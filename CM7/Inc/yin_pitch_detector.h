/**
 * @file yin_pitch_detector.h
 * @brief YIN pitch detection algorithm for guitar tuner
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Implements the YIN algorithm for accurate pitch detection,
 * optimized with CMSIS-DSP and 6x downsampling for efficiency.
 */

#ifndef YIN_PITCH_DETECTOR_H
#define YIN_PITCH_DETECTOR_H

#include <array>
#include <cstdint>
#include <cmath>
#include <algorithm>
#include "audio_effect.h"
#include "app_common.h"
#include "arm_math.h"

/**
 * @brief YIN pitch detection algorithm - processes MONO audio
 * 
 * Key optimizations:
 * 1. 6x downsampling (48kHz -> 8kHz) reduces computation significantly
 * 2. CMSIS-DSP arm_dot_prod_f32 for fast cross-correlation
 * 3. Early exit once confident pitch is found
 * 
 * Buffer size determines minimum detectable frequency:
 * min_freq = sample_rate / (buffer_size / 2)
 * 
 * With 512 downsampled samples at 8kHz: min_freq = 8000 / 256 = 31.25Hz
 */
class YinPitchDetector : public AudioEffect {
public:
    // Configuration
    static constexpr float MIN_FREQUENCY = 50.0f;    // Hz (limited by buffer size)
    static constexpr float MAX_FREQUENCY = 1000.0f;  // Hz
    static constexpr float DEFAULT_THRESHOLD = 0.15f;
    
    // Aggressive downsampling: 48kHz -> 8kHz (6x) 
    // Nyquist = 4kHz, plenty for pitch up to 1000Hz
    static constexpr uint32_t DOWNSAMPLE_FACTOR = 6;
    static constexpr float ORIGINAL_SAMPLE_RATE = Audio::SAMPLE_RATE_F;
    static constexpr float DOWNSAMPLED_RATE = ORIGINAL_SAMPLE_RATE / DOWNSAMPLE_FACTOR;  // 8kHz
    
    // Buffer configuration after downsampling
    // For low frequencies at 8kHz: tau = 8000/50 = 160 samples needed
    // HALF_BUFFER_SIZE must be > 160, so use 256 (512 total)
    static constexpr uint32_t BUFFER_SIZE = 512U;
    static constexpr uint32_t HALF_BUFFER_SIZE = BUFFER_SIZE / 2;  // = 256
    
    // Input buffer collects original-rate MONO samples before downsampling
    static constexpr uint32_t INPUT_BUFFER_SIZE = BUFFER_SIZE * DOWNSAMPLE_FACTOR;  // 3072
    
    explicit YinPitchDetector(float sample_rate, 
                              float threshold = DEFAULT_THRESHOLD,
                              std::string_view name = "YIN Pitch")
        : AudioEffect(name)
        , sample_rate_(DOWNSAMPLED_RATE)  // Use downsampled rate for calculations
        , threshold_(threshold)
        , input_index_(0)
        , detected_pitch_(0.0f)
        , probability_(0.0f)
    {
        (void)sample_rate;  // Original rate is fixed at 48kHz
        input_buffer_.fill(0.0f);
        buffer_.fill(0.0f);
        yin_buffer_.fill(0.0f);
    }
    
    /**
     * @brief Process MONO audio samples
     * @param samples Pointer to MONO sample buffer (int16_t)
     * @param num_samples Number of mono samples
     */
    void process(int16_t* samples, uint32_t num_samples) override {
        if (!is_enabled()) return;
        
        // Accumulate mono samples into input buffer
        for (uint32_t i = 0; i < num_samples; i++) {
            input_buffer_[input_index_] = static_cast<float>(samples[i]);
            input_index_++;
            
            // When input buffer is full, downsample and run pitch detection
            if (input_index_ >= INPUT_BUFFER_SIZE) {
                // Downsample 6:1 with averaging (acts as low-pass filter)
                for (uint32_t j = 0; j < BUFFER_SIZE; ++j) {
                    uint32_t base = j * DOWNSAMPLE_FACTOR;
                    float sum = 0.0f;
                    for (uint32_t k = 0; k < DOWNSAMPLE_FACTOR; ++k) {
                        sum += input_buffer_[base + k];
                    }
                    buffer_[j] = sum * (1.0f / DOWNSAMPLE_FACTOR);
                }
                
                run_yin();
                input_index_ = 0;
            }
        }
    }
    
    void reset() override {
        input_buffer_.fill(0.0f);
        buffer_.fill(0.0f);
        yin_buffer_.fill(0.0f);
        input_index_ = 0;
        detected_pitch_ = 0.0f;
        probability_ = 0.0f;
    }
    
    // Pitch detection results
    float get_pitch() const { return detected_pitch_; }
    float get_probability() const { return probability_; }
    bool has_pitch() const { return detected_pitch_ > 0.0f; }
    
    // Parameter interface for menu
    bool has_parameter() const override { return true; }
    
    void adjust_parameter(int delta) override {
        threshold_ += delta * 0.01f;
        threshold_ = std::clamp(threshold_, 0.05f, 0.50f);
    }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        if (detected_pitch_ > 0.0f) {
            // Show detected pitch
            int pitch_int = static_cast<int>(detected_pitch_);
            snprintf(buffer, size, "%dHz", pitch_int);
        } else {
            // Show threshold when no pitch
            int thresh_pct = static_cast<int>(threshold_ * 100.0f);
            snprintf(buffer, size, "Th:%d%%", thresh_pct);
        }
    }

private:
    /**
     * @brief Run the complete YIN algorithm
     */
    void run_yin() {
        // Step 1: Difference function (optimized with CMSIS-DSP)
        difference();
        
        // Step 2: Cumulative mean normalized difference function
        cumulative_mean_normalized_difference();
        
        // Step 3: Absolute threshold
        int32_t tau_estimate = absolute_threshold();
        
        // Step 4: Parabolic interpolation and pitch calculation
        if (tau_estimate >= 0) {
            float better_tau = parabolic_interpolation(tau_estimate);
            detected_pitch_ = sample_rate_ / better_tau;
            
            // Validate frequency range
            if (detected_pitch_ < MIN_FREQUENCY || detected_pitch_ > MAX_FREQUENCY) {
                detected_pitch_ = 0.0f;
                probability_ = 0.0f;
            }
        } else {
            detected_pitch_ = 0.0f;
            probability_ = 0.0f;
        }
    }
    
    /**
     * @brief Step 1: Compute the difference function using CMSIS-DSP
     * 
     * Uses the identity: (a-b)² = a² + b² - 2ab
     * So: d(tau) = sum(x[j]²) + sum(x[j+tau]²) - 2*sum(x[j]*x[j+tau])
     * 
     * The cross-correlation term uses arm_dot_prod_f32 which is optimized
     * for Cortex-M7 and can process multiple floats per cycle.
     */
    void difference() {
        float* __restrict buf = buffer_.data();
        float* __restrict yin = yin_buffer_.data();
        
        // Precompute sum of squares for the first window (indices 0 to HALF_BUFFER_SIZE-1)
        float32_t sum_sq_first = 0.0f;
        arm_dot_prod_f32(buf, buf, HALF_BUFFER_SIZE, &sum_sq_first);
        
        yin[0] = 0.0f;
        
        // Compute running sum of squares for shifted windows incrementally
        float32_t sum_sq_shifted = sum_sq_first;
        
        for (uint32_t tau = 1; tau < HALF_BUFFER_SIZE; ++tau) {
            // Update sum_sq_shifted incrementally:
            // Remove buf[tau-1]² and add buf[HALF_BUFFER_SIZE + tau - 1]²
            float old_val = buf[tau - 1];
            float new_val = buf[HALF_BUFFER_SIZE + tau - 1];
            sum_sq_shifted = sum_sq_shifted - old_val * old_val + new_val * new_val;
            
            // Cross-correlation using CMSIS-DSP
            float32_t cross_corr = 0.0f;
            arm_dot_prod_f32(buf, buf + tau, HALF_BUFFER_SIZE, &cross_corr);
            
            // d(tau) = sum(x²) + sum(x_shifted²) - 2*correlation
            yin[tau] = sum_sq_first + sum_sq_shifted - 2.0f * cross_corr;
        }
    }
    
    /**
     * @brief Step 2: Cumulative mean normalized difference function
     * d'(tau) = d(tau) / ((1/tau) * sum_{j=1}^{tau} d(j))
     *         = d(tau) * tau / sum_{j=1}^{tau} d(j)
     */
    void cumulative_mean_normalized_difference() {
        yin_buffer_[0] = 1.0f;
        
        float running_sum = 0.0f;
        for (uint32_t tau = 1; tau < HALF_BUFFER_SIZE; ++tau) {
            running_sum += yin_buffer_[tau];
            if (running_sum > 0.0f) {
                yin_buffer_[tau] = yin_buffer_[tau] * static_cast<float>(tau) / running_sum;
            } else {
                yin_buffer_[tau] = 1.0f;
            }
        }
    }
    
    /**
     * @brief Step 3: Find the first tau below threshold, then find local minimum
     * @return Tau estimate, or -1 if no pitch found
     */
    int32_t absolute_threshold() {
        // Start from tau=2 to avoid edge effects
        for (uint32_t tau = 2; tau < HALF_BUFFER_SIZE; ++tau) {
            if (yin_buffer_[tau] < threshold_) {
                // Find the local minimum
                while (tau + 1 < HALF_BUFFER_SIZE && 
                       yin_buffer_[tau + 1] < yin_buffer_[tau]) {
                    ++tau;
                }
                probability_ = 1.0f - yin_buffer_[tau];
                return static_cast<int32_t>(tau);
            }
        }
        
        // No pitch found
        probability_ = 0.0f;
        return -1;
    }
    
    /**
     * @brief Step 4: Parabolic interpolation for sub-sample accuracy
     */
    float parabolic_interpolation(int32_t tau_estimate) const {
        int32_t x0 = tau_estimate - 1;
        int32_t x2 = tau_estimate + 1;
        
        // Handle edge cases
        if (x0 < 0) {
            x0 = tau_estimate;
        }
        if (x2 >= static_cast<int32_t>(HALF_BUFFER_SIZE)) {
            x2 = tau_estimate;
        }
        
        // Edge case: tau is at boundary
        if (x0 == tau_estimate) {
            return (yin_buffer_[tau_estimate] <= yin_buffer_[x2]) 
                   ? static_cast<float>(tau_estimate) 
                   : static_cast<float>(x2);
        }
        if (x2 == tau_estimate) {
            return (yin_buffer_[tau_estimate] <= yin_buffer_[x0]) 
                   ? static_cast<float>(tau_estimate) 
                   : static_cast<float>(x0);
        }
        
        // Standard parabolic interpolation
        float s0 = yin_buffer_[x0];
        float s1 = yin_buffer_[tau_estimate];
        float s2 = yin_buffer_[x2];
        
        float denominator = 2.0f * (2.0f * s1 - s2 - s0);
        if (std::fabs(denominator) < 1e-9f) {
            return static_cast<float>(tau_estimate);
        }
        
        float adjustment = (s2 - s0) / denominator;
        
        // Sanity check
        if (!std::isfinite(adjustment) || std::fabs(adjustment) > 1.0f) {
            return static_cast<float>(tau_estimate);
        }
        
        return static_cast<float>(tau_estimate) + adjustment;
    }
    
    // Configuration
    float sample_rate_;    // Downsampled rate (8kHz)
    float threshold_;
    
    // Input buffer (collects 48kHz samples before downsampling)
    std::array<float, INPUT_BUFFER_SIZE> input_buffer_;
    uint32_t input_index_;
    
    // Downsampled audio buffer (24kHz, used for analysis)
    std::array<float, BUFFER_SIZE> buffer_;
    
    // YIN working buffer (stores d'(tau) values)
    std::array<float, HALF_BUFFER_SIZE> yin_buffer_;
    
    // Results
    float detected_pitch_;
    float probability_;
};

#endif // YIN_PITCH_DETECTOR_H