/**
 * @file cpu_burn_effect.h
 * @brief CPU burn effect for profiling and testing
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#pragma once

#include "audio_effect.h"
#include <cstdint>

/**
 * @brief A dummy AudioEffect that burns CPU cycles for profiling testing.
 * 
 * This effect intentionally wastes CPU cycles by performing meaningless
 * calculations to verify the CPU utilization measurement mechanism.
 * The burn intensity is controlled as a percentage (0-100%), where 100%
 * corresponds to MAX_ITERATIONS (50) iterations per sample.
 */
class CpuBurnEffect : public AudioEffect {
public:
    static constexpr uint32_t MAX_ITERATIONS = 100;  // 100% burn rate
    
    /**
     * @brief Construct a CPU burn effect
     * @param burn_percent Burn intensity as percentage (0-100)
     * @param name Display name for the effect
     */
    explicit CpuBurnEffect(uint32_t burn_percent = 100, const char* name = "CPU Burn")
        : AudioEffect(name)
        , burn_percent_(burn_percent > 100 ? 100 : burn_percent)
        , dummy_accumulator_(0.0f)
    {}

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;
        
        // Convert percentage to iterations
        const uint32_t iterations = (burn_percent_ * MAX_ITERATIONS) / 100;
        if (iterations == 0) return;
        
        // Burn CPU cycles by doing meaningless floating-point operations
        // The volatile prevents the compiler from optimizing away the work
        volatile float accumulator = dummy_accumulator_;
        
        for (uint32_t i = 0; i < num_samples; i++) {
            // Do wasteful work for each sample
            for (uint32_t j = 0; j < iterations; j++) {
                // Mix of operations to prevent optimization
                accumulator += static_cast<float>(samples[i]) * 0.00001f;
                accumulator *= 0.999999f;
                accumulator += 0.000001f;
            }
        }
        
        // Store back to prevent complete optimization
        dummy_accumulator_ = accumulator;
    }

    // Parameter interface to adjust burn intensity
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        snprintf(buffer, size, "%lu%%", burn_percent_);
    }
    
    void adjust_parameter(int delta) override {
        // Adjust in steps of 5%
        int32_t new_val = static_cast<int32_t>(burn_percent_) + (delta * 5);
        if (new_val < 0) new_val = 0;
        if (new_val > 100) new_val = 100;
        burn_percent_ = static_cast<uint32_t>(new_val);
    }

    // Getter/setter for burn percentage
    uint32_t get_burn_percent() const { return burn_percent_; }
    void set_burn_percent(uint32_t percent) { 
        burn_percent_ = percent > 100 ? 100 : percent; 
    }

private:
    uint32_t burn_percent_;
    volatile float dummy_accumulator_;  // volatile to prevent optimization
};
