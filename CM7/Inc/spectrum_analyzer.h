/**
 * @file spectrum_analyzer.h
 * @brief FFT-based spectrum analyzer effect with runtime-configurable FFT size
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Computes real-time frequency spectrum using CMSIS-DSP FFT functions.
 * Provides logarithmically-mapped magnitude data for display rendering.
 * FFT size can be changed at runtime between 128 and 4096.
 * 
 * Note: Large FFT buffers are placed in D2 SRAM (RAM_D2) to avoid
 * overflowing the main 128KB RAM.
 */

#ifndef SPECTRUM_ANALYZER_H
#define SPECTRUM_ANALYZER_H

#include <array>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include "audio_effect.h"
#include "arm_math.h"

// FFT buffers in D2 SRAM - declared here, defined in spectrum_analyzer_mode.cpp
// These are placed in .ram_d2_data section to use the 128KB D2 SRAM
namespace SpectrumBuffers {
    constexpr uint32_t MAX_FFT_SIZE = 4096;
    constexpr uint32_t MAX_NUM_BINS = MAX_FFT_SIZE / 2;
    constexpr uint32_t DISPLAY_WIDTH = 700;
    
    extern float input_buffer[MAX_FFT_SIZE];
    extern float windowed_buffer[MAX_FFT_SIZE];
    extern float window[MAX_FFT_SIZE];
    extern float fft_output[MAX_FFT_SIZE];
    extern float magnitude_bins[MAX_NUM_BINS];
}

class SpectrumAnalyzer : public AudioEffect {
public:
    // FFT size limits and options
    static constexpr uint32_t MAX_FFT_SIZE = SpectrumBuffers::MAX_FFT_SIZE;
    static constexpr uint32_t MIN_FFT_SIZE = 128;
    static constexpr uint32_t MAX_NUM_BINS = SpectrumBuffers::MAX_NUM_BINS;
    static constexpr uint32_t NUM_FFT_SIZES = 6;
    static constexpr uint32_t FFT_SIZES[NUM_FFT_SIZES] = {128, 256, 512, 1024, 2048, 4096};
    static constexpr uint32_t DEFAULT_FFT_SIZE_INDEX = 3;  // 1024
    
    // Display configuration - must match spectrum_display.cpp SPECTRUM_WIDTH
    static constexpr uint32_t DISPLAY_WIDTH = SpectrumBuffers::DISPLAY_WIDTH;
    static constexpr float MIN_FREQ = 50.0f;     // Hz
    static constexpr float MAX_FREQ = 20000.0f;  // Hz
    static constexpr float MIN_DB = -80.0f;
    static constexpr float MAX_DB = 0.0f;
    
    // Smoothing coefficients for attack/decay envelope
    // Attack: how fast bars rise to new peaks (higher = faster)
    // Decay: how fast bars fall when signal drops (lower = slower fall)
    static constexpr float ATTACK_COEFF = 0.6f;   // 60% new value on rise
    static constexpr float DECAY_COEFF = 0.08f;   // 8% toward new value on fall
    
    // Overlap configuration: 75% overlap means hop size = fft_size / 4
    // This gives 4x more FFT frames per second for smoother display
    static constexpr uint32_t OVERLAP_DIVISOR = 4;  // 75% overlap
    
    explicit SpectrumAnalyzer(float sample_rate, std::string_view name = "Spectrum")
        : AudioEffect(name)
        , sample_rate_(sample_rate)
        , fft_size_index_(DEFAULT_FFT_SIZE_INDEX)
        , fft_size_(FFT_SIZES[DEFAULT_FFT_SIZE_INDEX])
        , hop_size_(fft_size_ / OVERLAP_DIVISOR)
        , num_bins_(fft_size_ / 2)
        , input_index_(0)
        , buffer_filled_(false)
        , new_data_available_(false)
        , fft_size_changed_(false)
    {
        init_fft();
    }
    
    /**
     * @brief Process audio samples - accumulates for FFT with 75% overlap
     * 
     * Uses a sliding window approach:
     * 1. Initially fill the buffer completely (fft_size samples)
     * 2. After first FFT, shift buffer left by hop_size (fft_size/4)
     * 3. Add new samples to the end, compute FFT when hop_size new samples arrive
     * 
     * This gives 4x more FFT frames compared to non-overlapping windows.
     */
    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;
        
        for (uint32_t i = 0; i < num_samples; ++i) {
            // Convert to float and normalize to [-1.0, 1.0]
            float sample = static_cast<float>(samples[i]) / 32768.0f;
            
            if (!buffer_filled_) {
                // Initial fill: accumulate until we have fft_size samples
                SpectrumBuffers::input_buffer[input_index_++] = sample;
                
                if (input_index_ >= fft_size_) {
                    // Buffer is now full, compute first FFT
                    compute_fft();
                    compute_magnitudes();
                    map_to_display_bins();
                    new_data_available_ = true;
                    buffer_filled_ = true;
                    
                    // Shift buffer left by hop_size for overlap
                    shift_buffer();
                    input_index_ = fft_size_ - hop_size_;  // Continue filling from here
                }
            } else {
                // Overlap mode: add samples to end of buffer
                SpectrumBuffers::input_buffer[input_index_++] = sample;
                
                if (input_index_ >= fft_size_) {
                    // We have hop_size new samples, compute FFT
                    compute_fft();
                    compute_magnitudes();
                    map_to_display_bins();
                    new_data_available_ = true;
                    
                    // Shift buffer left by hop_size for next overlap
                    shift_buffer();
                    input_index_ = fft_size_ - hop_size_;
                }
            }
        }
    }
    
    /**
     * @brief Reset analyzer state
     */
    void reset() override {
        input_index_ = 0;
        buffer_filled_ = false;
        for (uint32_t i = 0; i < MAX_FFT_SIZE; ++i) {
            SpectrumBuffers::input_buffer[i] = 0.0f;
        }
        for (uint32_t i = 0; i < MAX_NUM_BINS; ++i) {
            SpectrumBuffers::magnitude_bins[i] = MIN_DB;
        }
        for (uint32_t i = 0; i < DISPLAY_WIDTH; ++i) {
            display_magnitudes_[i] = MIN_DB;
        }
        new_data_available_ = false;
    }
    
    /**
     * @brief Get the display-mapped magnitude array
     */
    const std::array<float, DISPLAY_WIDTH>& get_display_magnitudes() const {
        return display_magnitudes_;
    }
    
    /**
     * @brief Check if new FFT data is available
     */
    bool has_new_data() const { return new_data_available_; }
    
    /**
     * @brief Clear the new data flag after reading
     */
    void clear_new_data_flag() { new_data_available_ = false; }
    
    /**
     * @brief Get current FFT size
     */
    uint32_t get_fft_size() const { return fft_size_; }
    
    /**
     * @brief Cycle to next FFT size (larger)
     */
    void increase_fft_size() {
        if (fft_size_index_ < NUM_FFT_SIZES - 1) {
            fft_size_index_++;
            apply_fft_size_change();
        }
    }
    
    /**
     * @brief Cycle to previous FFT size (smaller)
     */
    void decrease_fft_size() {
        if (fft_size_index_ > 0) {
            fft_size_index_--;
            apply_fft_size_change();
        }
    }
    
    /**
     * @brief Check if FFT size was changed (for display update)
     */
    bool fft_size_changed() const { return fft_size_changed_; }
    
    /**
     * @brief Clear the FFT size changed flag
     */
    void clear_fft_size_changed_flag() { fft_size_changed_ = false; }

private:
    /**
     * @brief Initialize FFT instance and window for current size
     */
    void init_fft() {
        arm_rfft_fast_init_f32(&fft_instance_, fft_size_);
        hop_size_ = fft_size_ / OVERLAP_DIVISOR;
        
        // Pre-compute Hann window coefficients for current FFT size
        for (uint32_t i = 0; i < fft_size_; ++i) {
            SpectrumBuffers::window[i] = 0.5f * (1.0f - cosf(2.0f * 3.14159265f * i / (fft_size_ - 1)));
        }
        
        // Clear buffers
        reset();
    }
    
    /**
     * @brief Apply FFT size change
     */
    void apply_fft_size_change() {
        fft_size_ = FFT_SIZES[fft_size_index_];
        hop_size_ = fft_size_ / OVERLAP_DIVISOR;
        num_bins_ = fft_size_ / 2;
        fft_size_changed_ = true;
        init_fft();
    }
    
    /**
     * @brief Shift input buffer left by hop_size for overlap processing
     * 
     * Keeps the last (fft_size - hop_size) samples and makes room for
     * hop_size new samples at the end.
     */
    void shift_buffer() {
        const uint32_t keep_samples = fft_size_ - hop_size_;
        
        // Shift samples: move [hop_size..fft_size) to [0..keep_samples)
        for (uint32_t i = 0; i < keep_samples; ++i) {
            SpectrumBuffers::input_buffer[i] = SpectrumBuffers::input_buffer[i + hop_size_];
        }
    }
    
    /**
     * @brief Apply window and compute FFT
     */
    void compute_fft() {
        // Apply Hann window to reduce spectral leakage
        for (uint32_t i = 0; i < fft_size_; ++i) {
            SpectrumBuffers::windowed_buffer[i] = SpectrumBuffers::input_buffer[i] * SpectrumBuffers::window[i];
        }
        
        // Compute real FFT using CMSIS-DSP
        arm_rfft_fast_f32(&fft_instance_, SpectrumBuffers::windowed_buffer, SpectrumBuffers::fft_output, 0);
    }
    
    /**
     * @brief Calculate magnitude in dB for each frequency bin
     */
    void compute_magnitudes() {
        // Bin 0 (DC component) - purely real
        {
            float re = SpectrumBuffers::fft_output[0];
            float magnitude = fabsf(re) / static_cast<float>(fft_size_);
            float db = 20.0f * log10f(magnitude + 1e-10f);
            SpectrumBuffers::magnitude_bins[0] = std::clamp(db, MIN_DB, MAX_DB);
        }
        
        // Bins 1 to N/2-1 - complex values starting at index 2
        for (uint32_t i = 1; i < num_bins_; ++i) {
            float re = SpectrumBuffers::fft_output[2 * i];
            float im = SpectrumBuffers::fft_output[2 * i + 1];
            
            float magnitude = sqrtf(re * re + im * im);
            magnitude /= static_cast<float>(fft_size_);
            float db = 20.0f * log10f(magnitude + 1e-10f);
            SpectrumBuffers::magnitude_bins[i] = std::clamp(db, MIN_DB, MAX_DB);
        }
    }
    
    /**
     * @brief Map FFT bins to display X positions using logarithmic scaling
     * 
     * Uses attack/decay smoothing for a more pleasing visual display:
     * - Attack: Fast rise to new peaks
     * - Decay: Slow fall when signal drops
     */
    void map_to_display_bins() {
        const float log_min = log10f(MIN_FREQ);
        const float log_max = log10f(MAX_FREQ);
        const float log_range = log_max - log_min;
        const float bin_freq_resolution = sample_rate_ / static_cast<float>(fft_size_);
        
        // Temporary buffer for new raw magnitudes (before smoothing)
        // Initialize to MIN_DB so unmapped bins decay properly
        std::array<float, DISPLAY_WIDTH> new_magnitudes;
        for (uint32_t i = 0; i < DISPLAY_WIDTH; ++i) {
            new_magnitudes[i] = MIN_DB;
        }
        
        // Map FFT bins to display positions (take max if multiple bins map to same pixel)
        for (uint32_t bin = 1; bin < num_bins_; ++bin) {
            float freq = static_cast<float>(bin) * bin_freq_resolution;
            
            if (freq < MIN_FREQ || freq > MAX_FREQ) continue;
            
            float log_freq = log10f(freq);
            float normalized = (log_freq - log_min) / log_range;
            uint32_t x = static_cast<uint32_t>(normalized * static_cast<float>(DISPLAY_WIDTH - 1));
            
            if (x >= DISPLAY_WIDTH) x = DISPLAY_WIDTH - 1;
            
            if (SpectrumBuffers::magnitude_bins[bin] > new_magnitudes[x]) {
                new_magnitudes[x] = SpectrumBuffers::magnitude_bins[bin];
            }
        }
        
        // Apply attack/decay smoothing
        for (uint32_t i = 0; i < DISPLAY_WIDTH; ++i) {
            float new_val = new_magnitudes[i];
            float old_val = display_magnitudes_[i];
            
            if (new_val > old_val) {
                // Attack - fast rise to new peaks
                display_magnitudes_[i] = ATTACK_COEFF * new_val + (1.0f - ATTACK_COEFF) * old_val;
            } else {
                // Decay - slow fall when signal drops
                display_magnitudes_[i] = DECAY_COEFF * new_val + (1.0f - DECAY_COEFF) * old_val;
            }
        }
    }
    
    // CMSIS-DSP FFT instance
    arm_rfft_fast_instance_f32 fft_instance_;
    
    // Display magnitudes - small enough to keep in main RAM
    std::array<float, DISPLAY_WIDTH> display_magnitudes_;
    
    float sample_rate_;
    uint32_t fft_size_index_;
    uint32_t fft_size_;
    uint32_t hop_size_;      // fft_size / OVERLAP_DIVISOR for 75% overlap
    uint32_t num_bins_;
    uint32_t input_index_;
    bool buffer_filled_;     // True after initial buffer fill
    bool new_data_available_;
    bool fft_size_changed_;
};

#endif // SPECTRUM_ANALYZER_H
