/**
 * @file app_common.h
 * @brief Common application definitions and declarations
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Contains shared constants, types, and function declarations used
 * across all application modes (audio effects and pitch detection).
 */

#ifndef APP_COMMON_H
#define APP_COMMON_H

#include <cstdint>
#include <array>
#include <atomic>
#include <string>

extern "C" {
#include "main.h"
}

#include "stm32h747i_discovery.h"
#include "stm32h747i_discovery_lcd.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32_lcd.h"
#include "stm32h747i_discovery_audio.h"

#include "audio_effect.h"
#include "audio_pipeline.h"

// ============================================================================
// Audio Configuration Constants
// ============================================================================
// NOTE: When changing these values, also update tests/mocks/app_common.h
// to keep host-side unit tests in sync with the target configuration.
namespace Audio {
    // Core sample rate - single source of truth for the entire audio system
    // Used by: codec (WM8994), SAI, DMA, audio pipeline, and all DSP effects
    constexpr uint32_t SAMPLE_RATE = AUDIO_FREQUENCY_48K;
    constexpr float SAMPLE_RATE_F = static_cast<float>(SAMPLE_RATE);
    
    // Buffer configuration
    constexpr uint32_t SAMPLES_PER_CHANNEL = 512U;
    constexpr uint32_t NUM_CHANNELS = 2U;
    constexpr uint32_t NUM_BUFFERS = 2U;
    constexpr uint32_t TOTAL_SAMPLES = SAMPLES_PER_CHANNEL * NUM_CHANNELS * NUM_BUFFERS;
    
    // Codec volume defaults
    constexpr uint32_t INITIAL_OUT_VOLUME = 100U;
    constexpr uint32_t INITIAL_IN_VOLUME = 50U;
    
    // Audio format
    constexpr uint32_t BITS_PER_SAMPLE = AUDIO_RESOLUTION_16B;
    
    // Derived constants useful for DSP calculations
    constexpr float SAMPLES_PER_MS = SAMPLE_RATE_F / 1000.0f;  // 48 samples/ms at 48kHz
}

// CPU profiling constants
namespace Profiling {
    constexpr uint32_t CPU_FREQ_HZ = 400000000U;  // 400 MHz
    constexpr uint32_t UPDATE_INTERVAL_MS = 1000U;  // Update stats every 1 second
}

// ============================================================================
// Application Mode
// ============================================================================

enum class AppMode : uint8_t {
    INITIAL_MENU,
    AUDIO_EFFECTS,
    PITCH_DETECTION
};

// ============================================================================
// Joystick Events
// ============================================================================

enum class JoyEvent : uint8_t { NONE, UP, DOWN, LEFT, RIGHT, SEL };

namespace Joystick {
    constexpr uint32_t DEBOUNCE_MS = 150U;
    extern std::atomic<JoyEvent> last_event;
    extern std::atomic<bool> event_triggered;
}

// ============================================================================
// Global Objects (defined in main.cpp)
// ============================================================================

// Audio pipeline
extern AudioPipeline audio_pipeline;

// DMA-accessible buffer in D2 SRAM
extern std::array<int16_t, Audio::TOTAL_SAMPLES> audio_buffer;

// Current application mode
extern AppMode current_mode;

// ============================================================================
// STM32 Initialization Functions (defined in stm32_init.cpp)
// ============================================================================

struct DisplaySize {
    uint32_t width;
    uint32_t height;
};

void stm32_mpu_config();
void stm32_cpu_cache_enable();
void stm32_system_clock_config();
void stm32_uart_init();
DisplaySize stm32_init_display();
void stm32_init_leds();
uint32_t stm32_start_audio_passthrough();

#if defined(DUAL_CORE_BOOT_SYNC_SEQUENCE)
void stm32_wait_for_dual_core_ready(uint32_t flag);
void stm32_sync_dual_core_boot();
#endif

// ============================================================================
// Audio Effects Mode (defined in audio_effects_mode.cpp)
// ============================================================================

namespace EffectsMenu {
    void init(AudioPipeline* pipeline);
    void draw_full_menu();
    void move_selection(int delta);
    void toggle_selected();
    void adjust_selected_parameter(int delta);
    void update_cpu_stats();
}

void setup_audio_effects_mode();

// ============================================================================
// Pitch Detection Mode (defined in pitch_detection_mode.cpp)
// ============================================================================

namespace PitchDisplay {
    constexpr uint32_t UPDATE_INTERVAL_MS = 100;  // Update every 100ms
    void draw_initial();
    void update_display();
}

void setup_pitch_detection_mode();

// ============================================================================
// Initial Menu (defined in main.cpp)
// ============================================================================

namespace InitialMenu {
    void draw();
    void move_selection(int delta);
    AppMode confirm_selection();
}

#endif // APP_COMMON_H
