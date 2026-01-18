/**
 * @file audio_pipeline.h
 * @brief Audio processing pipeline with stereo-mono conversion
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#ifndef AUDIO_PIPELINE_H
#define AUDIO_PIPELINE_H

#include <array>
#include <cstdint>
#include <algorithm>
#include "audio_effect.h"

// DWT (Data Watchpoint and Trace) cycle counter access
// This is a hardware counter that counts CPU cycles with zero overhead
extern "C" {
#include "stm32h7xx.h"
}

/**
 * @brief Audio processing pipeline that chains multiple effects
 * 
 * The AudioPipeline manages a collection of AudioEffect objects and
 * processes audio through each effect in sequence.
 * 
 * Audio Flow:
 * [Stereo Interleaved Input] → [Deinterleave to Mono] → [Effects Chain] → [Interleave to Stereo Output]
 * 
 * All effects process MONO audio internally for efficiency. The pipeline
 * handles stereo-to-mono conversion at input and mono-to-stereo at output.
 * 
 * Includes CPU cycle profiling using the DWT hardware cycle counter.
 */
class AudioPipeline {
public:
    static constexpr uint32_t MAX_EFFECTS = 15;
    
    // Maximum mono samples we can process (stereo pairs / 2)
    // Input: 1024 stereo samples = 512 stereo pairs = 512 mono samples
    static constexpr uint32_t MAX_MONO_SAMPLES = 1024;
    
    AudioPipeline() : num_effects_(0), enabled_(true), profiling_enabled_(true) {
        effects_.fill(nullptr);
        mono_buffer_.fill(0);
    }
    
    /**
     * @brief Initialize the DWT cycle counter (call once at startup)
     */
    static void init_profiling() {
        // Enable DWT and ITM
        CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
        
        // Reset and enable the cycle counter
        DWT->CYCCNT = 0;
        DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
    }
    
    /**
     * @brief Add an effect to the end of the pipeline
     * @param effect Pointer to the effect (ownership NOT transferred)
     * @return true if added successfully, false if pipeline is full
     */
    bool add_effect(AudioEffect* effect) {
        if (effect == nullptr || num_effects_ >= MAX_EFFECTS) {
            return false;
        }
        effects_[num_effects_++] = effect;
        return true;
    }
    
    /**
     * @brief Remove an effect from the pipeline
     * @param effect Pointer to the effect to remove
     * @return true if removed, false if not found
     */
    bool remove_effect(AudioEffect* effect) {
        for (uint32_t i = 0; i < num_effects_; ++i) {
            if (effects_[i] == effect) {
                // Shift remaining effects down
                for (uint32_t j = i; j < num_effects_ - 1; ++j) {
                    effects_[j] = effects_[j + 1];
                }
                effects_[--num_effects_] = nullptr;
                return true;
            }
        }
        return false;
    }
    
    /**
     * @brief Remove all effects from the pipeline
     */
    void clear() {
        effects_.fill(nullptr);
        num_effects_ = 0;
    }
    
    /**
     * @brief Enable or disable CPU profiling
     */
    void set_profiling_enabled(bool enabled) { profiling_enabled_ = enabled; }
    bool is_profiling_enabled() const { return profiling_enabled_; }
    
    /**
     * @brief Process audio through all effects in the pipeline
     * 
     * Input: Stereo interleaved int16_t samples [L0, R0, L1, R1, ...]
     * Output: Same buffer with processed stereo interleaved samples
     * 
     * @param stereo_samples Pointer to stereo interleaved samples
     * @param num_stereo_samples Total number of int16_t values (2x stereo pairs)
     */
    void process(int16_t* stereo_samples, uint32_t num_stereo_samples) {
        if (!enabled_ || stereo_samples == nullptr || num_stereo_samples == 0) {
            return;
        }
        
        // Calculate number of mono samples (stereo pairs)
        const uint32_t num_mono_samples = num_stereo_samples / 2;
        if (num_mono_samples > MAX_MONO_SAMPLES) {
            return;  // Buffer too large
        }
        
        // Step 1: Deinterleave stereo to mono (average L+R channels)
        deinterleave_to_mono(stereo_samples, num_mono_samples);
        
        // Step 2: Process through all enabled effects (mono)
        for (uint32_t i = 0; i < num_effects_; ++i) {
            if (effects_[i] != nullptr && effects_[i]->is_enabled()) {
                if (profiling_enabled_) {
                    // Read cycle counter before processing
                    const uint32_t start_cycles = DWT->CYCCNT;
                    
                    effects_[i]->process(mono_buffer_.data(), num_mono_samples);
                    
                    // Read cycle counter after processing
                    const uint32_t end_cycles = DWT->CYCCNT;
                    
                    // Calculate cycles (handles wraparound correctly)
                    const uint32_t cycles_used = end_cycles - start_cycles;
                    effects_[i]->add_cycles(cycles_used);
                } else {
                    effects_[i]->process(mono_buffer_.data(), num_mono_samples);
                }
            }
        }
        
        // Step 3: Interleave mono back to stereo (duplicate to both channels)
        interleave_to_stereo(stereo_samples, num_mono_samples);
    }
    
    /**
     * @brief Reset all effects in the pipeline
     */
    void reset() {
        for (uint32_t i = 0; i < num_effects_; ++i) {
            if (effects_[i] != nullptr) {
                effects_[i]->reset();
            }
        }
        mono_buffer_.fill(0);
    }
    
    /**
     * @brief Enable or disable the entire pipeline
     */
    void set_enabled(bool enabled) { enabled_ = enabled; }
    bool is_enabled() const { return enabled_; }
    
    /**
     * @brief Get the number of effects in the pipeline
     */
    uint32_t get_effect_count() const { return num_effects_; }
    
    /**
     * @brief Get an effect by index
     * @param index Effect index (0-based)
     * @return Pointer to effect or nullptr if index is invalid
     */
    AudioEffect* get_effect(uint32_t index) {
        return (index < num_effects_) ? effects_[index] : nullptr;
    }

private:
    /**
     * @brief Convert stereo interleaved to mono by taking left channel
     * 
     * Note: We use left channel only instead of averaging because the
     * audio codec outputs dual-mono with one channel inverted.
     * 
     * Input:  stereo_samples[2*i] = Left, stereo_samples[2*i+1] = Right
     * Output: mono_buffer_[i] = Left channel
     */
    void deinterleave_to_mono(const int16_t* stereo_samples, uint32_t num_mono_samples) {
        for (uint32_t i = 0; i < num_mono_samples; ++i) {
            // Use left channel only (right channel may be inverted)
            mono_buffer_[i] = stereo_samples[2 * i];
        }
    }
    
    /**
     * @brief Convert mono back to stereo interleaved by duplicating to both channels
     * 
     * Input:  mono_buffer_[i]
     * Output: stereo_samples[2*i] = stereo_samples[2*i+1] = mono_buffer_[i]
     */
    void interleave_to_stereo(int16_t* stereo_samples, uint32_t num_mono_samples) {
        for (uint32_t i = 0; i < num_mono_samples; ++i) {
            int16_t mono_sample = mono_buffer_[i];
            stereo_samples[2 * i] = mono_sample;
            stereo_samples[2 * i + 1] = mono_sample;
        }
    }
    
    std::array<AudioEffect*, MAX_EFFECTS> effects_;
    uint32_t num_effects_;
    bool enabled_;
    bool profiling_enabled_;
    
    // Internal mono buffer for processing
    std::array<int16_t, MAX_MONO_SAMPLES> mono_buffer_;
};

#endif // AUDIO_PIPELINE_H
