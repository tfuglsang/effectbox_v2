/**
 * @file gain_effect.h
 * @brief Digital gain/volume effect using CMSIS-DSP
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#ifndef GAIN_EFFECT_H
#define GAIN_EFFECT_H

#include "audio_effect.h"
#include "arm_math.h"
#include <cstdio>

/**
 * @brief Simple gain/volume effect
 * 
 * Applies a gain multiplier to all audio samples.
 * Gain of 1.0 = unity (no change)
 * Gain > 1.0 = amplification
 * Gain < 1.0 = attenuation
 */
class GainEffect : public AudioEffect {
public:
    // Gain range: 0% to 100% (maps to 0.0 to 1.0 linear gain)
    static constexpr float32_t MIN_GAIN = 0.0f;
    static constexpr float32_t MAX_GAIN = 1.0f;
    static constexpr int PARAM_STEP = 5;  // 5% per adjustment step

    /**
     * @brief Construct a gain effect
     * @param gain Initial gain value (0.0 to 1.0)
     */
    explicit GainEffect(float32_t gain = 1.0f) 
        : AudioEffect("Digital Gain Filter"), gain_(gain) {
        // Clamp initial gain to valid range
        if (gain_ < MIN_GAIN) gain_ = MIN_GAIN;
        if (gain_ > MAX_GAIN) gain_ = MAX_GAIN;
    }
    
    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_ || gain_ == 1.0f) {
            return; // No processing needed
        }
        
        // Convert gain to Q15 format for efficient integer processing
        // Q15 range: -32768 to 32767, where 32767 = ~1.0
        const q15_t gain_q15 = static_cast<q15_t>(gain_ * 32767.0f);
        
        // Use CMSIS-DSP for optimized scaling
        arm_scale_q15(reinterpret_cast<q15_t*>(samples), 
                      gain_q15, 
                      0,  // No shift
                      reinterpret_cast<q15_t*>(samples), 
                      num_samples);
    }
    
    void reset() override {
        // Gain effect is stateless, nothing to reset
    }
    
    /**
     * @brief Set the gain value
     * @param gain New gain value (clamped to MIN_GAIN - MAX_GAIN)
     */
    void set_gain(float32_t gain) {
        gain_ = (gain < MIN_GAIN) ? MIN_GAIN : ((gain > MAX_GAIN) ? MAX_GAIN : gain);
    }
    
    float32_t get_gain() const { return gain_; }
    
    /**
     * @brief Convert gain to decibels
     */
    float32_t get_gain_db() const {
        if (gain_ <= 0.0f) return -100.0f;
        return 20.0f * log10f(gain_);
    }
    
    /**
     * @brief Set gain from decibels
     * @param db Gain in decibels (-60 to 0 dB range)
     */
    void set_gain_db(float32_t db) {
        set_gain(powf(10.0f, db / 20.0f));
    }
    
    // ========================================================================
    // Parameter Interface Implementation
    // ========================================================================
    
    bool has_parameter() const override { return true; }
    
    int get_parameter_percent() const override {
        return static_cast<int>(gain_ * 100.0f);
    }
    
    void get_parameter_string(char* buffer, uint32_t buffer_size) const override {
        if (buffer && buffer_size >= 8) {
            snprintf(buffer, buffer_size, "%3d%%", get_parameter_percent());
        }
    }
    
    void adjust_parameter(int delta) override {
        // delta is in percent steps
        int current_pct = get_parameter_percent();
        int new_pct = current_pct + (delta * PARAM_STEP);
        
        // Clamp to 0-100%
        if (new_pct < 0) new_pct = 0;
        if (new_pct > 100) new_pct = 100;
        
        gain_ = static_cast<float32_t>(new_pct) / 100.0f;
    }

private:
    float32_t gain_;
};

#endif // GAIN_EFFECT_H
