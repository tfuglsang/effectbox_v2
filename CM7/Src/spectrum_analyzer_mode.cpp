/**
 * @file spectrum_analyzer_mode.cpp
 * @brief Spectrum Analyzer mode implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Contains the setup function for spectrum analyzer mode.
 * Also defines the large FFT buffers in D2 SRAM to avoid RAM overflow.
 */

#include "app_common.h"
#include "spectrum_analyzer.h"
#include "spectrum_display.h"

// ============================================================================
// FFT Buffers in D2 SRAM
// ============================================================================
// These buffers are placed in the D2 domain SRAM (128KB at 0x30000000)
// to avoid overflowing the main 128KB RAM. Total size: ~82KB
// 4 buffers * 4096 floats * 4 bytes = 65536 bytes
// 1 buffer * 2048 floats * 4 bytes = 8192 bytes
// Total: ~74KB

namespace SpectrumBuffers {
    __attribute__((section(".ram_d2_data"))) alignas(32)
    float input_buffer[MAX_FFT_SIZE];
    
    __attribute__((section(".ram_d2_data"))) alignas(32)
    float windowed_buffer[MAX_FFT_SIZE];
    
    __attribute__((section(".ram_d2_data"))) alignas(32)
    float window[MAX_FFT_SIZE];
    
    __attribute__((section(".ram_d2_data"))) alignas(32)
    float fft_output[MAX_FFT_SIZE];
    
    __attribute__((section(".ram_d2_data"))) alignas(32)
    float magnitude_bins[MAX_NUM_BINS];
}

// ============================================================================
// Spectrum Analyzer Instance
// ============================================================================

// Global spectrum analyzer instance
SpectrumAnalyzer* g_spectrum_analyzer = nullptr;

// Static instance to avoid dynamic allocation
static SpectrumAnalyzer spectrum_analyzer_instance(Audio::SAMPLE_RATE_F, "Spectrum");

void setup_spectrum_analyzer_mode() {
    // Clear pipeline and add spectrum analyzer
    audio_pipeline.clear();
    
    // Reset and enable the analyzer
    spectrum_analyzer_instance.reset();
    spectrum_analyzer_instance.set_enabled(true);
    
    // Add to pipeline
    audio_pipeline.add_effect(&spectrum_analyzer_instance);
    
    // Set global pointer for display access
    g_spectrum_analyzer = &spectrum_analyzer_instance;
    
    // Draw initial display
    SpectrumDisplay::draw_initial();
}
