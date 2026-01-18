#pragma once

#include "audio_effect.h"
#include "arm_math.h"
#include <cmath>

/**
 * @brief Fixed-point Biquad filter effect using CMSIS-DSP Q31 functions
 * 
 * Implements IIR biquad filter sections for lowpass/highpass filtering.
 * Uses Q31 fixed-point arithmetic for efficient processing without FPU.
 * Handles stereo audio by processing left and right channels separately.
 * 
 * Coefficients are computed in floating-point then converted to Q31 format
 * with appropriate scaling (postShift) to handle coefficients > 1.0.
 */
class BiquadFixedEffect : public AudioEffect {
public:
    enum class FilterType {
        LOWPASS,
        HIGHPASS
    };

    /**
     * @brief Construct a fixed-point biquad filter effect
     * @param type Filter type (lowpass or highpass)
     * @param cutoff_hz Cutoff frequency in Hz
     * @param sample_rate Sample rate in Hz
     * @param q Q factor (default 0.707 for Butterworth response)
     * @param custom_name Optional custom name
     */
    BiquadFixedEffect(FilterType type, float cutoff_hz, 
                      float sample_rate, float q = 0.7071f,
                      std::string_view custom_name = "")
        : AudioEffect(custom_name.empty() ? 
                      (type == FilterType::LOWPASS ? "LPF Q31" : "HPF Q31") : custom_name)
        , filter_type_(type)
        , cutoff_hz_(cutoff_hz)
        , sample_rate_(sample_rate)
        , q_factor_(q)
        , post_shift_(0) {
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
        
        // Deinterleave and convert int16 to Q31
        // int16 to Q31: shift left by 16 bits
        for (uint32_t i = 0; i < process_frames; i++) {
            work_buffer_left_[i] = static_cast<q31_t>(samples[i * 2]) << 16;
            work_buffer_right_[i] = static_cast<q31_t>(samples[i * 2 + 1]) << 16;
        }
        
        // Process left channel with Q31 biquad
        arm_biquad_cascade_df1_q31(&filter_instance_left_, 
                                   work_buffer_left_, 
                                   work_buffer_left_, 
                                   process_frames);
        
        // Process right channel
        arm_biquad_cascade_df1_q31(&filter_instance_right_, 
                                   work_buffer_right_, 
                                   work_buffer_right_, 
                                   process_frames);
        
        // Reinterleave and convert Q31 back to int16
        // Q31 to int16: shift right by 16 bits
        for (uint32_t i = 0; i < process_frames; i++) {
            samples[i * 2] = static_cast<int16_t>(work_buffer_left_[i] >> 16);
            samples[i * 2 + 1] = static_cast<int16_t>(work_buffer_right_[i] >> 16);
        }
    }

    void reset() override {
        // Clear filter state for both channels
        for (auto& s : state_left_) s = 0;
        for (auto& s : state_right_) s = 0;
        init_filter();
    }

    // Getters
    float get_cutoff() const { return cutoff_hz_; }
    FilterType get_type() const { return filter_type_; }

    void set_cutoff(float cutoff_hz) {
        cutoff_hz_ = cutoff_hz;
        design_filter();
        init_filter();
    }

private:
    static constexpr uint32_t NUM_STAGES = 1;     // Single biquad stage (2nd order)
    static constexpr uint32_t BUFFER_SIZE = 512;  // Max frames per channel
    
    FilterType filter_type_;
    float cutoff_hz_;
    float sample_rate_;
    float q_factor_;
    int8_t post_shift_;
    
    // Coefficients in Q31 format: {b0, b1, b2, a1, a2} per stage
    q31_t coefficients_[5 * NUM_STAGES];
    
    // Working buffers for deinterleaved processing (Q31)
    q31_t work_buffer_left_[BUFFER_SIZE];
    q31_t work_buffer_right_[BUFFER_SIZE];
    
    // Separate state buffers for left and right channels
    // 4 values per stage per channel for df1
    q31_t state_left_[4 * NUM_STAGES] = {0};
    q31_t state_right_[4 * NUM_STAGES] = {0};
    
    // Separate filter instances for stereo
    arm_biquad_casd_df1_inst_q31 filter_instance_left_;
    arm_biquad_casd_df1_inst_q31 filter_instance_right_;

    /**
     * @brief Design the filter and convert coefficients to Q31 format
     * 
     * Uses bilinear transform to compute biquad coefficients, then
     * scales them to Q31 format with appropriate postShift to handle
     * coefficients with magnitude > 1.0
     * 
     * CMSIS-DSP Q31 biquad uses the equation:
     *   y[n] = b0*x[n] + b1*x[n-1] + b2*x[n-2] + a1*y[n-1] + a2*y[n-2]
     * 
     * Standard IIR form has denominator (1 + a1*z^-1 + a2*z^-2), so we need
     * to NEGATE a1 and a2 for CMSIS-DSP format.
     */
    void design_filter() {
        // Compute coefficients in floating-point first
        const float omega = 2.0f * PI * cutoff_hz_ / sample_rate_;
        const float sin_omega = sinf(omega);
        const float cos_omega = cosf(omega);
        const float alpha = sin_omega / (2.0f * q_factor_);
        
        float b0, b1, b2, a0, a1, a2;
        
        if (filter_type_ == FilterType::LOWPASS) {
            b0 = (1.0f - cos_omega) / 2.0f;
            b1 = 1.0f - cos_omega;
            b2 = (1.0f - cos_omega) / 2.0f;
            a0 = 1.0f + alpha;
            a1 = -2.0f * cos_omega;
            a2 = 1.0f - alpha;
        } else {
            b0 = (1.0f + cos_omega) / 2.0f;
            b1 = -(1.0f + cos_omega);
            b2 = (1.0f + cos_omega) / 2.0f;
            a0 = 1.0f + alpha;
            a1 = -2.0f * cos_omega;
            a2 = 1.0f - alpha;
        }
        
        // Normalize by a0
        b0 /= a0;
        b1 /= a0;
        b2 /= a0;
        a1 /= a0;
        a2 /= a0;
        
        // CMSIS-DSP Q31 needs NEGATED feedback coefficients
        // (because it adds a1*y[n-1] instead of subtracting)
        a1 = -a1;
        a2 = -a2;
        
        // Find the maximum coefficient magnitude to determine scaling
        float max_coeff = fabsf(b0);
        if (fabsf(b1) > max_coeff) max_coeff = fabsf(b1);
        if (fabsf(b2) > max_coeff) max_coeff = fabsf(b2);
        if (fabsf(a1) > max_coeff) max_coeff = fabsf(a1);
        if (fabsf(a2) > max_coeff) max_coeff = fabsf(a2);
        
        // Calculate postShift: determines how many bits to shift the accumulator result
        // Coefficients are scaled down so they fit in Q31 [-1, 1) range
        // postShift then compensates by shifting the output back up
        post_shift_ = 0;
        float scale = 1.0f;
        while (max_coeff * scale >= 1.0f) {
            post_shift_++;
            scale *= 0.5f;
        }
        
        // Add extra headroom to prevent overflow (CMSIS recommends input scaled by 2 bits)
        // We'll add 1 more bit of headroom
        post_shift_++;
        scale *= 0.5f;
        
        // Convert to Q31 with scaling
        // Q31 range: [-2^31, 2^31-1] represents [-1.0, ~1.0)
        const double q31_scale = 2147483648.0 * static_cast<double>(scale);
        
        coefficients_[0] = static_cast<q31_t>(static_cast<double>(b0) * q31_scale);
        coefficients_[1] = static_cast<q31_t>(static_cast<double>(b1) * q31_scale);
        coefficients_[2] = static_cast<q31_t>(static_cast<double>(b2) * q31_scale);
        coefficients_[3] = static_cast<q31_t>(static_cast<double>(a1) * q31_scale);
        coefficients_[4] = static_cast<q31_t>(static_cast<double>(a2) * q31_scale);
    }

    void init_filter() {
        // Initialize left channel filter
        arm_biquad_cascade_df1_init_q31(&filter_instance_left_,
                                        NUM_STAGES,
                                        coefficients_,
                                        state_left_,
                                        post_shift_);
        
        // Initialize right channel filter (same coefficients, different state)
        arm_biquad_cascade_df1_init_q31(&filter_instance_right_,
                                        NUM_STAGES,
                                        coefficients_,
                                        state_right_,
                                        post_shift_);
    }
};
