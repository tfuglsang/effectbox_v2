/**
 * @file codec_volume_effect.h
 * @brief WM8994 codec hardware volume control effects
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#ifndef CODEC_VOLUME_EFFECT_H
#define CODEC_VOLUME_EFFECT_H

#include "audio_effect.h"
#include <cstdio>

// Forward declaration - these are defined in stm32h747i_discovery_audio.h
extern "C" {
    int32_t BSP_AUDIO_OUT_SetVolume(uint32_t Instance, uint32_t Volume);
    int32_t BSP_AUDIO_IN_SetVolume(uint32_t Instance, uint32_t Volume);
}

/**
 * @brief Codec Output Volume Control
 * 
 * Controls the WM8994 codec's output (headphone) volume via BSP_AUDIO_OUT_SetVolume.
 * This is a "control" effect - it doesn't process audio samples, but adjusts
 * the codec's hardware gain setting.
 */
class CodecOutVolume : public AudioEffect {
public:
    static constexpr uint32_t INSTANCE = 0;
    static constexpr int MIN_VOLUME = 0;
    static constexpr int MAX_VOLUME = 100;
    static constexpr int VOLUME_STEP = 10;
    static constexpr int DEFAULT_VOLUME = 50;

    /**
     * @brief Construct codec output volume control
     * @param initial_volume Initial volume (0-100), default is 50
     */
    explicit CodecOutVolume(int initial_volume = DEFAULT_VOLUME)
        : AudioEffect("Codec Output Volume")
        , volume_(clamp_volume(initial_volume)) {
    }
    
    /**
     * @brief Initialize the codec output volume
     * Must be called after BSP_AUDIO_OUT_Init()
     */
    void init() {
        apply_volume();
    }
    
    /**
     * @brief No sample processing - this is a control-only effect
     */
    void process(int16_t* samples, uint32_t num_samples) override {
        (void)samples;
        (void)num_samples;
        // No sample processing - volume is controlled at codec level
    }
    
    void reset() override {
        // Re-apply the current volume setting
        apply_volume();
    }

    void set_enabled(bool enabled) override {
         enabled_ = true; // Always enabled to allow volume control
    }
    
    /**
     * @brief Set the output volume
     * @param volume Volume level 0-100
     */
    void set_volume(int volume) {
        volume_ = clamp_volume(volume);
        apply_volume();
    }
    
    int get_volume() const { return volume_; }
    
    // ========================================================================
    // Parameter Interface Implementation
    // ========================================================================
    
    bool has_parameter() const override { return true; }
    
    int get_parameter_percent() const override {
        return volume_;
    }
    
    void get_parameter_string(char* buffer, uint32_t buffer_size) const override {
        if (buffer && buffer_size >= 8) {
            snprintf(buffer, buffer_size, "%3d%%", volume_);
        }
    }
    
    void adjust_parameter(int delta) override {
        int new_volume = volume_ + (delta * VOLUME_STEP);
        set_volume(new_volume);
    }

private:
    int volume_;
    
    static int clamp_volume(int v) {
        if (v < MIN_VOLUME) return MIN_VOLUME;
        if (v > MAX_VOLUME) return MAX_VOLUME;
        return v;
    }
    
    void apply_volume() {
        if (enabled_) {
            BSP_AUDIO_OUT_SetVolume(INSTANCE, static_cast<uint32_t>(volume_));
        }
    }
};


/**
 * @brief Codec Input Volume Control
 * 
 * Controls the WM8994 codec's input (microphone) volume via BSP_AUDIO_IN_SetVolume.
 * This is a "control" effect - it doesn't process audio samples, but adjusts
 * the codec's hardware gain setting.
 */
class CodecInVolume : public AudioEffect {
public:
    static constexpr uint32_t INSTANCE = 0;
    static constexpr int MIN_VOLUME = 0;
    static constexpr int MAX_VOLUME = 100;
    static constexpr int VOLUME_STEP = 10;
    static constexpr int DEFAULT_VOLUME = 50;

    /**
     * @brief Construct codec input volume control
     * @param initial_volume Initial volume (0-100), default is 50
     */
    explicit CodecInVolume(int initial_volume = DEFAULT_VOLUME)
        : AudioEffect("Codec Input Volume")
        , volume_(clamp_volume(initial_volume)) {
    }
    
    /**
     * @brief Initialize the codec input volume
     * Must be called after BSP_AUDIO_IN_Init()
     */
    void init() {
        apply_volume();
    }
    
    /**
     * @brief No sample processing - this is a control-only effect
     */
    void process(int16_t* samples, uint32_t num_samples) override {
        (void)samples;
        (void)num_samples;
        // No sample processing - volume is controlled at codec level
    }
    
    void reset() override {
        // Re-apply the current volume setting
        apply_volume();
    }

    void set_enabled(bool enabled) override {
         enabled_ = true; // Always enabled to allow volume control
    }
    
    /**
     * @brief Set the input volume
     * @param volume Volume level 0-100
     */
    void set_volume(int volume) {
        volume_ = clamp_volume(volume);
        apply_volume();
    }
    
    int get_volume() const { return volume_; }
    
    // ========================================================================
    // Parameter Interface Implementation
    // ========================================================================
    
    bool has_parameter() const override { return true; }
    
    int get_parameter_percent() const override {
        return volume_;
    }
    
    void get_parameter_string(char* buffer, uint32_t buffer_size) const override {
        if (buffer && buffer_size >= 8) {
            snprintf(buffer, buffer_size, "%3d%%", volume_);
        }
    }
    
    void adjust_parameter(int delta) override {
        int new_volume = volume_ + (delta * VOLUME_STEP);
        set_volume(new_volume);
    }

private:
    int volume_;
    
    static int clamp_volume(int v) {
        if (v < MIN_VOLUME) return MIN_VOLUME;
        if (v > MAX_VOLUME) return MAX_VOLUME;
        return v;
    }
    
    void apply_volume() {
        if (enabled_) {
            BSP_AUDIO_IN_SetVolume(INSTANCE, static_cast<uint32_t>(volume_));
        }
    }
};

#endif // CODEC_VOLUME_EFFECT_H
