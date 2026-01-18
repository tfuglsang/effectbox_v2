/**
 * @file dsp_utils.cpp
 * @brief Audio DSP utilities implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#include "dsp_utils.h"

namespace DSP {

// Low-pass FIR filter coefficients (81 taps, cutoff ~2kHz at 48kHz)
// Generated using Python scipy.signal.firwin
static constexpr float32_t LOWPASS_COEFFS[81] = {
    -0.00097f, -0.00121f, -0.00128f, -0.00111f, 0.00012f, 0.00254f, 0.00604f,
     0.01052f,  0.01599f,  0.02209f,  0.02861f,  0.03549f,  0.04247f,  0.04949f,
     0.05637f,  0.06298f,  0.06920f,  0.07486f,  0.07988f,  0.08413f,  0.08752f,
     0.09002f,  0.09154f,  0.09206f,  0.09154f,  0.09002f,  0.08752f,  0.08413f,
     0.07988f,  0.07486f,  0.06920f,  0.06298f,  0.05637f,  0.04949f,  0.04247f,
     0.03549f,  0.02861f,  0.02209f,  0.01599f,  0.01052f,  0.00604f,  0.00254f,
     0.00012f, -0.00111f, -0.00128f, -0.00121f, -0.00097f,  0.00000f,  0.00138f,
     0.00320f,  0.00548f,  0.00827f,  0.01159f,  0.01550f,  0.02004f,  0.02526f,
     0.03122f,  0.03798f,  0.04560f,  0.05414f,  0.06371f,  0.07440f,  0.08629f,
     0.09946f,  0.11407f,  0.13030f,  0.14849f,  0.16906f,  0.19258f,  0.21978f,
     0.25158f,  0.28916f,  0.33393f,  0.38778f,  0.45296f,  0.53236f
};

constexpr uint32_t LOWPASS_NUM_TAPS = 81U;

AudioAnalyzer::AudioAnalyzer() {
    arm_rfft_fast_init_f32(&fft_instance, FFT_SIZE);
    arm_fir_init_f32(&filter_instance, LOWPASS_NUM_TAPS,
                    const_cast<float32_t*>(LOWPASS_COEFFS), filter_state, FFT_SIZE);
}

void AudioAnalyzer::compute_spectrum(const float32_t* input, uint32_t num_samples,
                                    float32_t* output) {
    uint32_t copy_size = (num_samples < FFT_SIZE) ? num_samples : FFT_SIZE;
    arm_copy_f32(input, fft_input, copy_size);
    
    if (copy_size < FFT_SIZE) {
        arm_fill_f32(0.0f, fft_input + copy_size, FFT_SIZE - copy_size);
    }
    
    arm_rfft_fast_f32(&fft_instance, fft_input, fft_output, 0);
    arm_cmplx_mag_f32(fft_output, output, FFT_HALF);
}

uint32_t AudioAnalyzer::find_peak_bin(const float32_t* spectrum) {
    uint32_t peak_index = 0;
    float32_t peak_value = 0.0f;
    arm_max_f32(spectrum, FFT_HALF, &peak_value, &peak_index);
    return peak_index;
}

void AudioAnalyzer::apply_lowpass_filter(const float32_t* input, float32_t* output,
                                        uint32_t num_samples) {
    uint32_t remaining = num_samples;
    uint32_t offset = 0;
    
    while (remaining > 0) {
        uint32_t block_size = (remaining < FFT_SIZE) ? remaining : FFT_SIZE;
        arm_fir_f32(&filter_instance, input + offset, output + offset, block_size);
        remaining -= block_size;
        offset += block_size;
    }
}

} // namespace DSP
