/**
 * @file audio_effect.h
 * @brief Base class for audio effects with profiling support
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#ifndef AUDIO_EFFECT_H
#define AUDIO_EFFECT_H

#include <cstdint>
#include <string_view>

/**
 * @brief Base class for all audio effects
 * 
 * All audio effects must inherit from this class and implement
 * the process() method to modify audio samples.
 * 
 * IMPORTANT: All effects process MONO audio (single channel int16_t samples).
 * The AudioPipeline handles stereo-to-mono conversion at input and
 * mono-to-stereo conversion at output. Effects should process samples
 * in-place when possible.
 */
class AudioEffect {
public:
    explicit AudioEffect(std::string_view name) 
        : name_(name)
        , enabled_(true)
        , cycles_accumulated_(0)
        , call_count_(0)
        , cpu_utilization_percent_(0.0f) {}
    
    virtual ~AudioEffect() = default;
    
    // Non-copyable but movable
    AudioEffect(const AudioEffect&) = delete;
    AudioEffect& operator=(const AudioEffect&) = delete;
    AudioEffect(AudioEffect&&) noexcept = default;
    AudioEffect& operator=(AudioEffect&&) noexcept = default;
    
    /**
     * @brief Process MONO audio samples in-place
     * @param samples Pointer to MONO samples (single channel int16_t)
     * @param num_samples Number of mono samples to process
     */
    virtual void process(int16_t* samples, uint32_t num_samples) = 0;
    
    /**
     * @brief Reset the effect state (clear delay lines, etc.)
     */
    virtual void reset() {}
    
    /**
     * @brief Enable or disable the effect
     */
    virtual void set_enabled(bool enabled) { enabled_ = enabled; }
    bool is_enabled() const { return enabled_; }
    
    /**
     * @brief Get the effect name
     */
    std::string_view get_name() const { return name_; }
    
    // ========================================================================
    // CPU Profiling Interface
    // ========================================================================
    
    /**
     * @brief Add measured cycles from one process() call
     * @param cycles Number of CPU cycles consumed
     */
    void add_cycles(uint32_t cycles) {
        cycles_accumulated_ += cycles;
        call_count_++;
    }
    
    /**
     * @brief Calculate and store CPU utilization, then reset counters
     * @param cpu_freq_hz CPU frequency in Hz
     * @param measurement_period_ms Period over which cycles were accumulated (in ms)
     */
    void finalize_utilization(uint32_t cpu_freq_hz, uint32_t measurement_period_ms) {
        if (call_count_ > 0 && measurement_period_ms > 0) {
            // Total cycles available in the measurement period
            const float cycles_available = static_cast<float>(cpu_freq_hz) * 
                                           static_cast<float>(measurement_period_ms) / 1000.0f;
            
            // Calculate utilization percentage
            cpu_utilization_percent_ = (static_cast<float>(cycles_accumulated_) / cycles_available) * 100.0f;
        } else {
            cpu_utilization_percent_ = 0.0f;
        }
        
        // Reset accumulators for next period
        cycles_accumulated_ = 0;
        call_count_ = 0;
    }
    
    /**
     * @brief Get the last calculated CPU utilization
     * @return CPU utilization as percentage (0.0 - 100.0)
     */
    float get_cpu_utilization() const { return cpu_utilization_percent_; }
    
    // ========================================================================
    // Parameter Adjustment Interface (for effects with user-adjustable params)
    // ========================================================================
    
    /**
     * @brief Check if this effect has an adjustable parameter
     * @return true if parameter can be adjusted via adjust_parameter()
     */
    virtual bool has_parameter() const { return false; }
    
    /**
     * @brief Get the current parameter value as a percentage (0-100)
     * @return Parameter value in percent, or 0 if no parameter
     */
    virtual int get_parameter_percent() const { return 0; }
    
    /**
     * @brief Get a display string for the parameter (e.g., "50%")
     * @param buffer Output buffer for the string
     * @param buffer_size Size of the buffer
     */
    virtual void get_parameter_string(char* buffer, uint32_t buffer_size) const {
        if (buffer && buffer_size > 0) {
            buffer[0] = '\0';
        }
    }
    
    /**
     * @brief Adjust the parameter by a delta value
     * @param delta Positive to increase, negative to decrease
     */
    virtual void adjust_parameter(int delta) { (void)delta; }

protected:
    std::string_view name_;
    bool enabled_;
    
private:
    // CPU profiling data
    uint64_t cycles_accumulated_;
    uint32_t call_count_;
    float cpu_utilization_percent_;
};

#endif // AUDIO_EFFECT_H
