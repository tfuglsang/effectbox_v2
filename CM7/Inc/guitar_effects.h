/**
 * @file guitar_effects.h
 * @brief Guitar effects collection: Distortion, Delay, Chorus, Flanger, Tremolo, Reverb
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * All effects process MONO audio (int16_t samples). The AudioPipeline handles
 * stereo-to-mono and mono-to-stereo conversion.
 * 
 * All effects are optimized for real-time processing on Cortex-M7 with hardware FPU.
 */

#ifndef GUITAR_EFFECTS_H
#define GUITAR_EFFECTS_H

#include "audio_effect.h"
#include "app_common.h"
#include "arm_math.h"
#include <cmath>
#include <cstring>
#include <cstdio>

// ============================================================================
// Distortion / Overdrive Effect
// ============================================================================

/**
 * @brief Distortion effect using soft clipping (tanh waveshaping)
 * 
 * Creates warm tube-like distortion by applying soft clipping.
 * The drive parameter controls the amount of distortion.
 */
class DistortionEffect : public AudioEffect {
public:
    static constexpr float MIN_DRIVE = 1.0f;
    static constexpr float MAX_DRIVE = 50.0f;
    static constexpr int PARAM_STEP = 2;

    explicit DistortionEffect(float drive = 10.0f)
        : AudioEffect("Distortion")
        , drive_(drive)
        , output_gain_(0.5f) {
        clamp_drive();
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        for (uint32_t i = 0; i < num_samples; i++) {
            // Convert to float (-1.0 to 1.0)
            float sample = static_cast<float>(samples[i]) / 32768.0f;
            
            // Apply drive (pre-gain)
            sample *= drive_;
            
            // Soft clipping using tanh approximation (faster than std::tanh)
            // tanh(x) ≈ x / (1 + |x| + 0.28*x^2) for small-medium x
            float abs_sample = (sample < 0) ? -sample : sample;
            float x2 = sample * sample;
            sample = sample / (1.0f + abs_sample + 0.28f * x2);
            
            // Apply output gain to compensate for clipping
            sample *= output_gain_;
            
            // Convert back to int16, with saturation
            float output = sample * 32767.0f;
            if (output > 32767.0f) output = 32767.0f;
            else if (output < -32768.0f) output = -32768.0f;
            
            samples[i] = static_cast<int16_t>(output);
        }
    }

    void reset() override {}

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        int drive_int = static_cast<int>(drive_);
        snprintf(buffer, size, "%d", drive_int);
    }
    
    void adjust_parameter(int direction) override {
        drive_ += direction * PARAM_STEP;
        clamp_drive();
    }

    void set_drive(float drive) {
        drive_ = drive;
        clamp_drive();
    }
    
    float get_drive() const { return drive_; }

private:
    void clamp_drive() {
        if (drive_ < MIN_DRIVE) drive_ = MIN_DRIVE;
        if (drive_ > MAX_DRIVE) drive_ = MAX_DRIVE;
    }

    float drive_;
    float output_gain_;
};

// ============================================================================
// Delay / Echo Effect
// ============================================================================

/**
 * @brief Simple delay (echo) effect - processes MONO audio
 * 
 * Creates a single-tap delay with feedback for echo/repeat effect.
 * Delay time is adjustable from 50ms to 250ms.
 */
class DelayEffect : public AudioEffect {
public:
    // At 48kHz mono, 250ms = 12000 samples (was 24000 for stereo)
    static constexpr uint32_t MAX_DELAY_SAMPLES = 12000;
    static constexpr uint32_t MIN_DELAY_MS = 50;
    static constexpr uint32_t MAX_DELAY_MS = 250;
    static constexpr int PARAM_STEP = 25;  // 25ms steps

    explicit DelayEffect(uint32_t delay_ms = 200, float feedback = 0.4f, float mix = 0.5f)
        : AudioEffect("Delay/Echo")
        , delay_ms_(delay_ms)
        , feedback_(feedback)
        , mix_(mix)
        , write_index_(0) {
        clamp_params();
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        // Calculate delay in mono samples
        const uint32_t delay_samples = static_cast<uint32_t>(
            static_cast<float>(delay_ms_) * Audio::SAMPLES_PER_MS);
        
        for (uint32_t i = 0; i < num_samples; i++) {
            // Read from delay buffer
            uint32_t read_index = (write_index_ + MAX_DELAY_SAMPLES - delay_samples) % MAX_DELAY_SAMPLES;
            float delayed = static_cast<float>(delay_buffer_[read_index]) / 32768.0f;
            
            // Get dry signal
            float dry = static_cast<float>(samples[i]) / 32768.0f;
            
            // Write to delay buffer (input + feedback)
            float to_delay = dry + delayed * feedback_;
            // Soft limit to prevent runaway feedback
            if (to_delay > 1.0f) to_delay = 1.0f;
            else if (to_delay < -1.0f) to_delay = -1.0f;
            delay_buffer_[write_index_] = static_cast<int16_t>(to_delay * 32767.0f);
            
            // Mix dry and wet
            float output = dry * (1.0f - mix_) + delayed * mix_;
            
            // Clamp and convert back
            if (output > 1.0f) output = 1.0f;
            else if (output < -1.0f) output = -1.0f;
            samples[i] = static_cast<int16_t>(output * 32767.0f);
            
            write_index_ = (write_index_ + 1) % MAX_DELAY_SAMPLES;
        }
    }

    void reset() override {
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
        write_index_ = 0;
    }

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        snprintf(buffer, size, "%lums", delay_ms_);
    }
    
    void adjust_parameter(int direction) override {
        int new_delay = static_cast<int>(delay_ms_) + direction * PARAM_STEP;
        if (new_delay < static_cast<int>(MIN_DELAY_MS)) new_delay = MIN_DELAY_MS;
        if (new_delay > static_cast<int>(MAX_DELAY_MS)) new_delay = MAX_DELAY_MS;
        delay_ms_ = static_cast<uint32_t>(new_delay);
    }

    void set_delay_ms(uint32_t ms) {
        delay_ms_ = ms;
        clamp_params();
    }
    
    void set_feedback(float fb) {
        feedback_ = fb;
        clamp_params();
    }
    
    void set_mix(float mix) {
        mix_ = mix;
        clamp_params();
    }

private:
    void clamp_params() {
        if (delay_ms_ < MIN_DELAY_MS) delay_ms_ = MIN_DELAY_MS;
        if (delay_ms_ > MAX_DELAY_MS) delay_ms_ = MAX_DELAY_MS;
        if (feedback_ < 0.0f) feedback_ = 0.0f;
        if (feedback_ > 0.9f) feedback_ = 0.9f;  // Limit to prevent infinite echo
        if (mix_ < 0.0f) mix_ = 0.0f;
        if (mix_ > 1.0f) mix_ = 1.0f;
    }

    uint32_t delay_ms_;
    float feedback_;
    float mix_;
    uint32_t write_index_;
    int16_t delay_buffer_[MAX_DELAY_SAMPLES];
};

// ============================================================================
// Chorus Effect
// ============================================================================

/**
 * @brief Chorus effect using modulated delay - processes MONO audio
 * 
 * Creates a rich, shimmering sound by mixing the dry signal with
 * a pitch-modulated delayed copy. Uses an LFO to modulate delay time.
 */
class ChorusEffect : public AudioEffect {
public:
    static constexpr uint32_t MAX_DELAY_SAMPLES = 2400;  // 50ms max at 48kHz mono
    static constexpr float MIN_RATE = 0.1f;   // Hz
    static constexpr float MAX_RATE = 5.0f;   // Hz
    static constexpr int PARAM_STEP = 1;      // 0.1Hz steps (displayed as x10)

    explicit ChorusEffect(float rate_hz = 1.5f, float depth = 0.5f, float mix = 0.5f)
        : AudioEffect("Chorus")
        , rate_hz_(rate_hz)
        , depth_(depth)
        , mix_(mix)
        , phase_(0.0f)
        , write_index_(0) {
        clamp_params();
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        // LFO phase increment per sample (mono)
        const float phase_inc = rate_hz_ / Audio::SAMPLE_RATE_F;
        
        // Base delay ~15ms, modulation depth ~10ms (in mono samples)
        const float base_delay = 15.0f * Audio::SAMPLES_PER_MS;
        const float mod_depth = depth_ * 10.0f * Audio::SAMPLES_PER_MS;

        for (uint32_t i = 0; i < num_samples; i++) {
            // Calculate modulated delay using sine LFO
            float lfo = arm_sin_f32(phase_ * 2.0f * PI);
            float delay = base_delay + lfo * mod_depth;
            
            // Ensure delay is within buffer bounds
            if (delay < 2.0f) delay = 2.0f;
            if (delay > MAX_DELAY_SAMPLES - 2) delay = MAX_DELAY_SAMPLES - 2;
            
            // Linear interpolation for smooth modulation
            uint32_t delay_int = static_cast<uint32_t>(delay);
            float frac = delay - static_cast<float>(delay_int);
            
            float dry = static_cast<float>(samples[i]) / 32768.0f;
            
            // Read delayed samples with interpolation
            uint32_t read_idx1 = (write_index_ + MAX_DELAY_SAMPLES - delay_int) % MAX_DELAY_SAMPLES;
            uint32_t read_idx2 = (read_idx1 + MAX_DELAY_SAMPLES - 1) % MAX_DELAY_SAMPLES;
            
            float s1 = static_cast<float>(delay_buffer_[read_idx1]) / 32768.0f;
            float s2 = static_cast<float>(delay_buffer_[read_idx2]) / 32768.0f;
            float delayed = s1 * (1.0f - frac) + s2 * frac;
            
            // Write to delay buffer
            delay_buffer_[write_index_] = samples[i];
            write_index_ = (write_index_ + 1) % MAX_DELAY_SAMPLES;
            
            // Mix dry and wet
            float output = dry * (1.0f - mix_) + delayed * mix_;
            
            if (output > 1.0f) output = 1.0f;
            else if (output < -1.0f) output = -1.0f;
            samples[i] = static_cast<int16_t>(output * 32767.0f);
            
            phase_ += phase_inc;
            if (phase_ >= 1.0f) phase_ -= 1.0f;
        }
    }

    void reset() override {
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
        write_index_ = 0;
        phase_ = 0.0f;
    }

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        int rate_x10 = static_cast<int>(rate_hz_ * 10.0f);
        snprintf(buffer, size, "%d.%dHz", rate_x10 / 10, rate_x10 % 10);
    }
    
    void adjust_parameter(int direction) override {
        rate_hz_ += direction * 0.1f;
        clamp_params();
    }

private:
    void clamp_params() {
        if (rate_hz_ < MIN_RATE) rate_hz_ = MIN_RATE;
        if (rate_hz_ > MAX_RATE) rate_hz_ = MAX_RATE;
        if (depth_ < 0.0f) depth_ = 0.0f;
        if (depth_ > 1.0f) depth_ = 1.0f;
        if (mix_ < 0.0f) mix_ = 0.0f;
        if (mix_ > 1.0f) mix_ = 1.0f;
    }

    float rate_hz_;
    float depth_;
    float mix_;
    float phase_;
    uint32_t write_index_;
    int16_t delay_buffer_[MAX_DELAY_SAMPLES];
};

// ============================================================================
// Flanger Effect
// ============================================================================

/**
 * @brief Flanger effect using very short modulated delay with feedback - processes MONO
 * 
 * Creates the classic "jet plane" swooshing sound using a very short
 * delay (1-10ms) modulated by a slow LFO, with feedback for resonance.
 */
class FlangerEffect : public AudioEffect {
public:
    static constexpr uint32_t MAX_DELAY_SAMPLES = 1200;  // 25ms max at 48kHz mono
    static constexpr float MIN_RATE = 0.05f;
    static constexpr float MAX_RATE = 2.0f;
    static constexpr int PARAM_STEP = 1;

    explicit FlangerEffect(float rate_hz = 0.3f, float depth = 0.7f, float feedback = 0.5f)
        : AudioEffect("Flanger")
        , rate_hz_(rate_hz)
        , depth_(depth)
        , feedback_(feedback)
        , phase_(0.0f)
        , write_index_(0) {
        clamp_params();
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        const float phase_inc = rate_hz_ / Audio::SAMPLE_RATE_F;
        
        // Very short delay for flanger: 1-7ms (in mono samples)
        const float base_delay = 1.0f * Audio::SAMPLES_PER_MS;
        const float mod_depth = depth_ * 6.0f * Audio::SAMPLES_PER_MS;

        for (uint32_t i = 0; i < num_samples; i++) {
            // Triangle LFO for flanger (more aggressive sweep than sine)
            float lfo = phase_ < 0.5f ? (4.0f * phase_ - 1.0f) : (3.0f - 4.0f * phase_);
            float delay = base_delay + (lfo + 1.0f) * 0.5f * mod_depth;
            
            if (delay < 2.0f) delay = 2.0f;
            if (delay > MAX_DELAY_SAMPLES - 2) delay = MAX_DELAY_SAMPLES - 2;
            
            uint32_t delay_int = static_cast<uint32_t>(delay);
            float frac = delay - static_cast<float>(delay_int);
            
            float dry = static_cast<float>(samples[i]) / 32768.0f;
            
            // Read with interpolation
            uint32_t read_idx1 = (write_index_ + MAX_DELAY_SAMPLES - delay_int) % MAX_DELAY_SAMPLES;
            uint32_t read_idx2 = (read_idx1 + MAX_DELAY_SAMPLES - 1) % MAX_DELAY_SAMPLES;
            
            float s1 = static_cast<float>(delay_buffer_[read_idx1]) / 32768.0f;
            float s2 = static_cast<float>(delay_buffer_[read_idx2]) / 32768.0f;
            float delayed = s1 * (1.0f - frac) + s2 * frac;
            
            // Write input + feedback to delay
            float to_delay = dry + delayed * feedback_;
            if (to_delay > 1.0f) to_delay = 1.0f;
            else if (to_delay < -1.0f) to_delay = -1.0f;
            delay_buffer_[write_index_] = static_cast<int16_t>(to_delay * 32767.0f);
            write_index_ = (write_index_ + 1) % MAX_DELAY_SAMPLES;
            
            // Mix: flanger typically uses 50/50 for comb filtering effect
            float output = dry * 0.5f + delayed * 0.5f;
            
            if (output > 1.0f) output = 1.0f;
            else if (output < -1.0f) output = -1.0f;
            samples[i] = static_cast<int16_t>(output * 32767.0f);
            
            phase_ += phase_inc;
            if (phase_ >= 1.0f) phase_ -= 1.0f;
        }
    }

    void reset() override {
        std::memset(delay_buffer_, 0, sizeof(delay_buffer_));
        write_index_ = 0;
        phase_ = 0.0f;
    }

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        int rate_x100 = static_cast<int>(rate_hz_ * 100.0f);
        snprintf(buffer, size, "%d.%02dHz", rate_x100 / 100, rate_x100 % 100);
    }
    
    void adjust_parameter(int direction) override {
        rate_hz_ += direction * 0.05f;
        clamp_params();
    }

private:
    void clamp_params() {
        if (rate_hz_ < MIN_RATE) rate_hz_ = MIN_RATE;
        if (rate_hz_ > MAX_RATE) rate_hz_ = MAX_RATE;
        if (depth_ < 0.0f) depth_ = 0.0f;
        if (depth_ > 1.0f) depth_ = 1.0f;
        if (feedback_ < 0.0f) feedback_ = 0.0f;
        if (feedback_ > 0.9f) feedback_ = 0.9f;
    }

    float rate_hz_;
    float depth_;
    float feedback_;
    float phase_;
    uint32_t write_index_;
    int16_t delay_buffer_[MAX_DELAY_SAMPLES];
};

// ============================================================================
// Tremolo Effect
// ============================================================================

/**
 * @brief Tremolo effect - amplitude modulation
 * 
 * Creates a pulsing volume effect by modulating the amplitude
 * with a low-frequency oscillator.
 */
class TremoloEffect : public AudioEffect {
public:
    static constexpr float MIN_RATE = 1.0f;
    static constexpr float MAX_RATE = 15.0f;
    static constexpr int PARAM_STEP = 1;

    explicit TremoloEffect(float rate_hz = 5.0f, float depth = 0.5f)
        : AudioEffect("Tremolo")
        , rate_hz_(rate_hz)
        , depth_(depth)
        , phase_(0.0f) {
        clamp_params();
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        const float phase_inc = rate_hz_ / Audio::SAMPLE_RATE_F;

        for (uint32_t i = 0; i < num_samples; i++) {
            // Sine LFO for smooth tremolo
            float lfo = arm_sin_f32(phase_ * 2.0f * PI);
            
            // Convert LFO (-1 to 1) to gain (1-depth to 1)
            float gain = 1.0f - depth_ * (1.0f - lfo) * 0.5f;
            
            // Apply gain
            float sample = static_cast<float>(samples[i]) * gain;
            
            // Clamp (shouldn't be needed for tremolo, but be safe)
            if (sample > 32767.0f) sample = 32767.0f;
            else if (sample < -32768.0f) sample = -32768.0f;
            
            samples[i] = static_cast<int16_t>(sample);
            
            phase_ += phase_inc;
            if (phase_ >= 1.0f) phase_ -= 1.0f;
        }
    }

    void reset() override {
        phase_ = 0.0f;
    }

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        int rate_int = static_cast<int>(rate_hz_);
        snprintf(buffer, size, "%dHz", rate_int);
    }
    
    void adjust_parameter(int direction) override {
        rate_hz_ += direction * PARAM_STEP;
        clamp_params();
    }

private:
    void clamp_params() {
        if (rate_hz_ < MIN_RATE) rate_hz_ = MIN_RATE;
        if (rate_hz_ > MAX_RATE) rate_hz_ = MAX_RATE;
        if (depth_ < 0.0f) depth_ = 0.0f;
        if (depth_ > 1.0f) depth_ = 1.0f;
    }

    float rate_hz_;
    float depth_;
    float phase_;
};

// ============================================================================
// Reverb Effect (Simple Schroeder Reverb)
// ============================================================================

/**
 * @brief Simple reverb using parallel comb filters and series allpass filters
 *        Processes MONO audio
 * 
 * Implements a basic Schroeder reverb algorithm for room ambience.
 * Uses 4 parallel comb filters feeding into 2 series allpass filters.
 */
class ReverbEffect : public AudioEffect {
public:
    static constexpr float MIN_DECAY = 0.1f;
    static constexpr float MAX_DECAY = 0.95f;
    static constexpr int PARAM_STEP = 5;  // 5% steps
    
    // Comb filter delay times (in samples at 48kHz) - prime numbers for diffusion
    // Reduced for memory efficiency
    static constexpr uint32_t COMB1_DELAY = 743;
    static constexpr uint32_t COMB2_DELAY = 809;
    static constexpr uint32_t COMB3_DELAY = 857;
    static constexpr uint32_t COMB4_DELAY = 929;
    
    // Allpass filter delays
    static constexpr uint32_t AP1_DELAY = 197;
    static constexpr uint32_t AP2_DELAY = 67;
    
    static constexpr uint32_t MAX_COMB_DELAY = 1000;
    static constexpr uint32_t MAX_AP_DELAY = 256;

    explicit ReverbEffect(float decay = 0.6f, float mix = 0.3f)
        : AudioEffect("Reverb")
        , decay_(decay)
        , mix_(mix) {
        clamp_params();
        reset();
    }

    void process(int16_t* samples, uint32_t num_samples) override {
        if (!enabled_) return;

        for (uint32_t i = 0; i < num_samples; i++) {
            // Input is already mono
            float input = static_cast<float>(samples[i]) / 32768.0f;
            
            // Parallel comb filters
            float comb_out = 0.0f;
            comb_out += process_comb(0, input, COMB1_DELAY);
            comb_out += process_comb(1, input, COMB2_DELAY);
            comb_out += process_comb(2, input, COMB3_DELAY);
            comb_out += process_comb(3, input, COMB4_DELAY);
            comb_out *= 0.25f;  // Average
            
            // Series allpass filters for diffusion
            float ap_out = process_allpass(0, comb_out, AP1_DELAY);
            ap_out = process_allpass(1, ap_out, AP2_DELAY);
            
            // Mix dry and wet
            float output = input * (1.0f - mix_) + ap_out * mix_;
            
            // Clamp
            if (output > 1.0f) output = 1.0f;
            else if (output < -1.0f) output = -1.0f;
            
            samples[i] = static_cast<int16_t>(output * 32767.0f);
        }
    }

    void reset() override {
        for (int i = 0; i < 4; i++) {
            std::memset(comb_buffer_[i], 0, sizeof(comb_buffer_[i]));
            comb_idx_[i] = 0;
        }
        for (int i = 0; i < 2; i++) {
            std::memset(ap_buffer_[i], 0, sizeof(ap_buffer_[i]));
            ap_idx_[i] = 0;
        }
    }

    // Parameter interface
    bool has_parameter() const override { return true; }
    
    void get_parameter_string(char* buffer, uint32_t size) const override {
        int decay_pct = static_cast<int>(decay_ * 100.0f);
        snprintf(buffer, size, "%d%%", decay_pct);
    }
    
    void adjust_parameter(int direction) override {
        decay_ += direction * 0.05f;
        clamp_params();
    }

    void set_decay(float decay) {
        decay_ = decay;
        clamp_params();
    }
    
    void set_mix(float mix) {
        mix_ = mix;
        clamp_params();
    }

private:
    void clamp_params() {
        if (decay_ < MIN_DECAY) decay_ = MIN_DECAY;
        if (decay_ > MAX_DECAY) decay_ = MAX_DECAY;
        if (mix_ < 0.0f) mix_ = 0.0f;
        if (mix_ > 1.0f) mix_ = 1.0f;
    }
    
    float process_comb(int idx, float input, uint32_t delay) {
        // Read delayed sample (convert from int16 to float)
        uint32_t read_idx = (comb_idx_[idx] + MAX_COMB_DELAY - delay) % MAX_COMB_DELAY;
        float delayed = static_cast<float>(comb_buffer_[idx][read_idx]) / 32768.0f;
        
        // Write new sample (input + feedback * delayed), convert to int16
        float to_write = input + decay_ * delayed;
        // Soft limit
        if (to_write > 1.0f) to_write = 1.0f;
        else if (to_write < -1.0f) to_write = -1.0f;
        comb_buffer_[idx][comb_idx_[idx]] = static_cast<int16_t>(to_write * 32767.0f);
        comb_idx_[idx] = (comb_idx_[idx] + 1) % MAX_COMB_DELAY;
        
        return delayed;
    }
    
    float process_allpass(int idx, float input, uint32_t delay) {
        // Read delayed sample (convert from int16 to float)
        uint32_t read_idx = (ap_idx_[idx] + MAX_AP_DELAY - delay) % MAX_AP_DELAY;
        float delayed = static_cast<float>(ap_buffer_[idx][read_idx]) / 32768.0f;
        
        // Allpass coefficient (typically 0.5-0.7)
        const float g = 0.5f;
        
        // Allpass: output = -g*input + delayed + g*output_delayed
        float output = -g * input + delayed;
        float to_write = input + g * delayed;
        // Soft limit
        if (to_write > 1.0f) to_write = 1.0f;
        else if (to_write < -1.0f) to_write = -1.0f;
        ap_buffer_[idx][ap_idx_[idx]] = static_cast<int16_t>(to_write * 32767.0f);
        ap_idx_[idx] = (ap_idx_[idx] + 1) % MAX_AP_DELAY;
        
        return output;
    }

    float decay_;
    float mix_;
    
    // Comb filter buffers and indices - use int16_t to save memory
    int16_t comb_buffer_[4][MAX_COMB_DELAY];
    uint32_t comb_idx_[4];
    
    // Allpass filter buffers and indices - use int16_t to save memory
    int16_t ap_buffer_[2][MAX_AP_DELAY];
    uint32_t ap_idx_[2];
};

#endif // GUITAR_EFFECTS_H
