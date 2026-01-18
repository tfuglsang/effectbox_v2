/**
 * @file dsp_utils.h
 * @brief Audio DSP utilities using CMSIS-DSP library
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Provides signal processing functions for real-time audio analysis
 * optimized for Cortex-M7.
 */

#ifndef DSP_UTILS_H
#define DSP_UTILS_H

#include <cstdint>
#include "arm_math.h"

namespace DSP {

/// FFT Configuration
constexpr uint32_t FFT_SIZE = 512U;
constexpr uint32_t FFT_HALF = FFT_SIZE / 2U;

/**
 * @brief Audio analyzer using FFT
 * 
 * Performs real-time frequency domain analysis of audio signals.
 */
class AudioAnalyzer {
public:
    AudioAnalyzer();
    
    /**
     * @brief Compute FFT magnitude spectrum
     * @param input Audio samples (real values)
     * @param num_samples Number of input samples
     * @param output Magnitude spectrum (half complex)
     */
    void compute_spectrum(const float32_t* input, uint32_t num_samples, 
                         float32_t* output);
    
    /**
     * @brief Compute peak frequency from magnitude spectrum
     * @param spectrum Magnitude spectrum (half complex)
     * @return Peak frequency bin index
     */
    uint32_t find_peak_bin(const float32_t* spectrum);
    
    /**
     * @brief Simple low-pass FIR filter
     * @param input Input audio buffer
     * @param output Output filtered audio
     * @param num_samples Number of samples to process
     */
    void apply_lowpass_filter(const float32_t* input, float32_t* output, 
                             uint32_t num_samples);
    
private:
    arm_rfft_fast_instance_f32 fft_instance;
    arm_fir_instance_f32 filter_instance;
    float32_t fft_input[FFT_SIZE];
    float32_t fft_output[FFT_SIZE];
    float32_t filter_state[FFT_SIZE + 64U];
};

/**
 * @brief Convert magnitude spectrum bin to frequency (Hz)
 * @param bin Bin index
 * @param sample_rate Sample rate in Hz
 * @return Frequency in Hz
 */
inline float32_t bin_to_frequency(uint32_t bin, uint32_t sample_rate) {
    return (static_cast<float32_t>(bin) * static_cast<float32_t>(sample_rate)) / 
           static_cast<float32_t>(FFT_SIZE);
}

} // namespace DSP

#endif // DSP_UTILS_H
