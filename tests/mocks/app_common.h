/**
 * @file app_common.h
 * @brief Mock app_common.h for host-side testing
 * 
 * Provides only the Audio namespace constants needed by DSP code,
 * without pulling in STM32 HAL dependencies.
 */

#ifndef APP_COMMON_H
#define APP_COMMON_H

#include <cstdint>

// ============================================================================
// Audio Configuration Constants (mirrors CM7/Inc/app_common.h)
// ============================================================================
namespace Audio {
    // Core sample rate - single source of truth for the entire audio system
    constexpr uint32_t SAMPLE_RATE = 48000U;
    constexpr float SAMPLE_RATE_F = 48000.0f;
    
    // Buffer configuration
    constexpr uint32_t SAMPLES_PER_CHANNEL = 512U;
    constexpr uint32_t NUM_CHANNELS = 2U;
    constexpr uint32_t NUM_BUFFERS = 2U;
    constexpr uint32_t TOTAL_SAMPLES = SAMPLES_PER_CHANNEL * NUM_CHANNELS * NUM_BUFFERS;
    
    // Codec volume defaults
    constexpr uint32_t INITIAL_OUT_VOLUME = 100U;
    constexpr uint32_t INITIAL_IN_VOLUME = 50U;
    
    // Audio format
    constexpr uint32_t BITS_PER_SAMPLE = 16U;
    
    // Derived constants useful for DSP calculations
    constexpr float SAMPLES_PER_MS = SAMPLE_RATE_F / 1000.0f;  // 48 samples/ms at 48kHz
}

// CPU profiling constants
namespace Profiling {
    constexpr uint32_t CPU_FREQ_HZ = 400000000U;  // 400 MHz
    constexpr uint32_t UPDATE_INTERVAL_MS = 1000U;
}

#endif // APP_COMMON_H
