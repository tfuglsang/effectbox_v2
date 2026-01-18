/**
 * @file biquad_filter_effect.h
 * @brief Biquad filter effect using CMSIS-DSP
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#pragma once

#include "audio_effect.h"
#include "arm_math.h"
#include <cmath>

/**
 * @brief Biquad filter effect using CMSIS-DSP
 * 
 * Implements IIR biquad filter sections for lowpass/highpass filtering.
 * Uses floating-point for accurate coefficient representation on Cortex-M7 FPU.
 * Handles stereo audio by processing left and right channels separately.
 */
class BiquadFilterEffect : public AudioEffect {
public:
    enum class FilterType {
        LOWPASS,
        HIGHPASS
    };

    /**
     * @brief Construct a biquad filter effect
     * @param type Filter type (lowpass or highpass)
     * @param cutoff_hz Cutoff frequency in Hz
     * @param sample_rate Sample rate in Hz
     * @param q Q factor (default 0.707 for Butterworth response)
     * @param custom_name Optional custom name (if empty, uses default based on type)
     */
    BiquadFilterEffect(FilterType type, float32_t cutoff_hz, 
                       float32_t sample_rate, float32_t q = 0.7071f,
                       std::string_view custom_name = "")
        : AudioEffect(custom_name.empty() ? 
                      (type == FilterType::LOWPASS ? "LPF" : "HPF") : custom_name)
        , filter_type_(type)
        , cutoff_hz_(cutoff_hz)
        , sample_rate_(sample_rate)
        , q_factor_(q) {
        design_filter();
        init_filter();
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_ || num_samples == 0) {
            return;
        }
        
        // Audio is interleaved stereo: L0, R0, L1, R1, ...
        const uint32_t frames = num_samples / 2;  // Number of stereo frames
        const uint32_t process_frames = (frames > BUFFER_SIZE) ? BUFFER_SIZE : frames;
        
        // Deinterleave and convert to float
        for (uint32_t i = 0; i < process_frames; i++) {
            // Convert Q15 to float (-1.0 to +1.0 range)
            work_buffer_left_[i] = static_cast<float32_t>(samples[i * 2]) / 32768.0f;
            work_buffer_right_[i] = static_cast<float32_t>(samples[i * 2 + 1]) / 32768.0f;
        }
        
        // Process left channel with floating-point biquad
        arm_biquad_cascade_df1_f32(&filter_instance_left_, 
                                   work_buffer_left_, 
                                   work_buffer_left_, 
                                   process_frames);
        
        // Process right channel
        arm_biquad_cascade_df1_f32(&filter_instance_right_, 
                                   work_buffer_right_, 
                                   work_buffer_right_, 
                                   process_frames);
        
        // Reinterleave and convert back to Q15
        for (uint32_t i = 0; i < process_frames; i++) {
            // Clamp and convert float to Q15
            float32_t left = work_buffer_left_[i];
            float32_t right = work_buffer_right_[i];
            
            // Soft clipping to prevent harsh distortion
            if (left > 1.0f) left = 1.0f;
            else if (left < -1.0f) left = -1.0f;
            if (right > 1.0f) right = 1.0f;
            else if (right < -1.0f) right = -1.0f;
            
            samples[i * 2] = static_cast<int16_t>(left * 32767.0f);
            samples[i * 2 + 1] = static_cast<int16_t>(right * 32767.0f);
        }
    }

    void reset() override {
        // Clear filter state for both channels
        for (auto& s : state_left_) {
            s = 0.0f;
        }
        for (auto& s : state_right_) {
            s = 0.0f;
        }
        init_filter();
    }

    // Getters
    float32_t get_cutoff() const { return cutoff_hz_; }
    FilterType get_type() const { return filter_type_; }

    /**
     * @brief Update the cutoff frequency
     * @param cutoff_hz New cutoff frequency in Hz
     */
    void set_cutoff(float32_t cutoff_hz) {
        cutoff_hz_ = cutoff_hz;
        design_filter();
        init_filter();
    }

private:
    static constexpr uint32_t NUM_STAGES = 1;  // Single biquad stage (2nd order)
    static constexpr uint32_t BUFFER_SIZE = 512; // Max frames per channel
    
    FilterType filter_type_;
    float32_t cutoff_hz_;
    float32_t sample_rate_;
    float32_t q_factor_;
    
    // Coefficients in float format: {b0, b1, b2, a1, a2} per stage
    // Note: CMSIS-DSP f32 biquad uses negated a1, a2 internally
    float32_t coefficients_[5 * NUM_STAGES];
    
    // Working buffers for deinterleaved processing (per-instance)
    float32_t work_buffer_left_[BUFFER_SIZE];
    float32_t work_buffer_right_[BUFFER_SIZE];
    
    // Separate state buffers for left and right channels
    // 4 values per stage per channel for df1
    float32_t state_left_[4 * NUM_STAGES] = {0};
    float32_t state_right_[4 * NUM_STAGES] = {0};
    
    // Separate filter instances for stereo
    arm_biquad_casd_df1_inst_f32 filter_instance_left_;
    arm_biquad_casd_df1_inst_f32 filter_instance_right_;

    void design_filter() {
        // Pre-warp the cutoff frequency for bilinear transform
        const float32_t omega = 2.0f * PI * cutoff_hz_ / sample_rate_;
        const float32_t sin_omega = arm_sin_f32(omega);
        const float32_t cos_omega = arm_cos_f32(omega);
        const float32_t alpha = sin_omega / (2.0f * q_factor_);
        
        float32_t b0, b1, b2, a0, a1, a2;
        
        if (filter_type_ == FilterType::LOWPASS) {
            // Lowpass filter coefficients
            b0 = (1.0f - cos_omega) / 2.0f;
            b1 = 1.0f - cos_omega;
            b2 = (1.0f - cos_omega) / 2.0f;
            a0 = 1.0f + alpha;
            a1 = -2.0f * cos_omega;
            a2 = 1.0f - alpha;
        } else {
            // Highpass filter coefficients
            b0 = (1.0f + cos_omega) / 2.0f;
            b1 = -(1.0f + cos_omega);
            b2 = (1.0f + cos_omega) / 2.0f;
            a0 = 1.0f + alpha;
            a1 = -2.0f * cos_omega;
            a2 = 1.0f - alpha;
        }
        
        // Normalize by a0
        const float32_t norm = 1.0f / a0;
        
        // CMSIS-DSP df1 f32 format: {b0, b1, b2, a1, a2}
        // Note: a1 and a2 are stored with opposite sign in CMSIS-DSP
        coefficients_[0] = b0 * norm;
        coefficients_[1] = b1 * norm;
        coefficients_[2] = b2 * norm;
        coefficients_[3] = -a1 * norm;  // Negated for CMSIS-DSP
        coefficients_[4] = -a2 * norm;  // Negated for CMSIS-DSP
    }

    void init_filter() {
        // Initialize left channel filter
        arm_biquad_cascade_df1_init_f32(&filter_instance_left_,
                                        NUM_STAGES,
                                        coefficients_,
                                        state_left_);
        
        // Initialize right channel filter (same coefficients, different state)
        arm_biquad_cascade_df1_init_f32(&filter_instance_right_,
                                        NUM_STAGES,
                                        coefficients_,
                                        state_right_);
    }
};

// Convenience type aliases
using LowpassFilterEffect = BiquadFilterEffect;
using HighpassFilterEffect = BiquadFilterEffect;
