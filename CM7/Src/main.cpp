/**
 * @file main.cpp
 * @brief Application entry point and main loop
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * This is the main entry point for the STM32H747I-DISCO audio application.
 * Mode-specific code is in separate files:
 * - audio_effects_mode.cpp: Audio effects pipeline and menu
 * - pitch_detection_mode.cpp: YIN pitch detection and display
 * - stm32_init.cpp: Hardware initialization functions
 */

#include <string>
#include <cstring>
#include <cstdio>
#include <atomic>
#include <array>
#include <cstdint>
#include <cmath>

#include "app_common.h"
#include "audio_pipeline.h"

// ============================================================================
// Global Objects
// ============================================================================

// DMA-accessible buffer in D2 SRAM
__attribute__((section(".ram_d2_data"))) alignas(32) 
std::array<int16_t, Audio::TOTAL_SAMPLES> audio_buffer;

// Global audio pipeline
AudioPipeline audio_pipeline;

// Current application mode
AppMode current_mode = AppMode::INITIAL_MENU;

// Joystick state
namespace Joystick {
    std::atomic<JoyEvent> last_event{JoyEvent::NONE};
    std::atomic<bool> event_triggered{false};
}

// ============================================================================
// Initial Menu System
// ============================================================================

namespace InitialMenu {
    constexpr uint32_t MENU_START_Y = 200;
    constexpr uint32_t MENU_ITEM_HEIGHT = 50;
    constexpr uint32_t MENU_ITEM_WIDTH = 400;
    constexpr uint32_t NUM_ITEMS = 2;
    
    const char* menu_items[NUM_ITEMS] = {
        "Audio Effects",
        "Pitch Detection"
    };
    
    uint32_t selected_index = 0;
    
    void draw_menu_item(uint32_t index) {
        uint32_t screen_width = 0;
        BSP_LCD_GetXSize(0, &screen_width);
        
        const uint32_t item_x = (screen_width - MENU_ITEM_WIDTH) / 2;
        const uint32_t item_y = MENU_START_Y + (index * (MENU_ITEM_HEIGHT + 10));
        const bool is_selected = (index == selected_index);
        
        // Draw item background
        const uint32_t bg_color = is_selected ? UTIL_LCD_COLOR_LIGHTBLUE : UTIL_LCD_COLOR_WHITE;
        const uint32_t border_color = is_selected ? UTIL_LCD_COLOR_BLUE : UTIL_LCD_COLOR_DARKGRAY;
        
        // Draw border
        BSP_LCD_FillRect(0, item_x - 2, item_y - 2, MENU_ITEM_WIDTH + 4, MENU_ITEM_HEIGHT + 4, border_color);
        // Draw background
        BSP_LCD_FillRect(0, item_x, item_y, MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT, bg_color);
        
        // Draw text centered in the item
        UTIL_LCD_SetBackColor(bg_color);
        UTIL_LCD_SetTextColor(is_selected ? UTIL_LCD_COLOR_DARKBLUE : UTIL_LCD_COLOR_BLACK);
        UTIL_LCD_SetFont(&Font24);
        
        const uint32_t text_y = item_y + (MENU_ITEM_HEIGHT - 24) / 2;
        UTIL_LCD_DisplayStringAt(0, text_y, 
            reinterpret_cast<uint8_t*>(const_cast<char*>(menu_items[index])), CENTER_MODE);
    }
    
    void draw() {
        UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);
        
        // Draw title
        UTIL_LCD_SetFont(&Font24);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
        UTIL_LCD_DisplayStringAt(0, 80, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Start menu")), CENTER_MODE);
        
        UTIL_LCD_SetFont(&Font16);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        UTIL_LCD_DisplayStringAt(0, 120, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Select Mode")), CENTER_MODE);
        
        // Draw clock rates (CM7 = SYSCLK, CM4 = HCLK)
        char clock_str[64];
        const uint32_t cm7_mhz = HAL_RCC_GetSysClockFreq() / 1000000U;
        const uint32_t cm4_mhz = HAL_RCC_GetHCLKFreq() / 1000000U;
        snprintf(clock_str, sizeof(clock_str), "CM7: %lu MHz  |  CM4: %lu MHz", cm7_mhz, cm4_mhz);
        
        UTIL_LCD_SetFont(&Font16);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_GRAY);
        UTIL_LCD_DisplayStringAt(0, 155, 
            reinterpret_cast<uint8_t*>(clock_str), CENTER_MODE);
        
        // Draw menu items
        for (uint32_t i = 0; i < NUM_ITEMS; i++) {
            draw_menu_item(i);
        }
        
        // Draw help text
        UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        UTIL_LCD_DisplayStringAt(0, 400, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("UP/DOWN: Select   SEL: Confirm")), CENTER_MODE);
    }
    
    void move_selection(int delta) {
        uint32_t old_index = selected_index;
        
        if (delta < 0 && selected_index == 0) {
            selected_index = NUM_ITEMS - 1;
        } else if (delta > 0 && selected_index == NUM_ITEMS - 1) {
            selected_index = 0;
        } else {
            selected_index = static_cast<uint32_t>(static_cast<int>(selected_index) + delta);
        }
        
        draw_menu_item(old_index);
        draw_menu_item(selected_index);
    }
    
    AppMode confirm_selection() {
        if (selected_index == 0) {
            return AppMode::AUDIO_EFFECTS;
        } else {
            return AppMode::PITCH_DETECTION;
        }
    }
}

// ============================================================================
// Audio Processing
// ============================================================================

// Process audio through the pipeline
void process_audio_block(int16_t* samples, uint32_t num_samples) {
    audio_pipeline.process(samples, num_samples);
}

static void cache_invalidate_half_buffer(uint32_t offset) {
    constexpr uint32_t half_size = Audio::TOTAL_SAMPLES / 2 * sizeof(int16_t);
    SCB_InvalidateDCache_by_Addr(
        reinterpret_cast<uint32_t*>(audio_buffer.data() + offset),
        half_size
    );
}

static void cache_clean_half_buffer(uint32_t offset) {
    constexpr uint32_t half_size = Audio::TOTAL_SAMPLES / 2 * sizeof(int16_t);
    SCB_CleanDCache_by_Addr(
        reinterpret_cast<uint32_t*>(audio_buffer.data() + offset),
        half_size
    );
}

extern "C" void BSP_AUDIO_IN_HalfTransfer_CallBack(uint32_t Instance) {
    if (Instance == 0) {
        cache_invalidate_half_buffer(0);
        constexpr uint32_t half_samples = Audio::TOTAL_SAMPLES / 2;
        process_audio_block(audio_buffer.data(), half_samples);
        cache_clean_half_buffer(0);
    }
}

extern "C" void BSP_AUDIO_IN_TransferComplete_CallBack(uint32_t Instance) {
    if (Instance == 0) {
        constexpr uint32_t half_offset = Audio::TOTAL_SAMPLES / 2;
        cache_invalidate_half_buffer(half_offset);
        constexpr uint32_t half_samples = Audio::TOTAL_SAMPLES / 2;
        process_audio_block(audio_buffer.data() + half_offset, half_samples);
        cache_clean_half_buffer(half_offset);
    }
}

// ============================================================================
// Joystick Handling
// ============================================================================

extern "C" void BSP_JOY_Callback(JOY_TypeDef JOY, uint32_t JoyPin) {
    static uint32_t last_tick = 0;
    const uint32_t current_tick = HAL_GetTick();
    
    if (current_tick - last_tick > Joystick::DEBOUNCE_MS) {
        Joystick::event_triggered = true;
        last_tick = current_tick;
        
        switch (JoyPin) {
            case JOY_UP: Joystick::last_event = JoyEvent::UP; break;
            case JOY_DOWN: Joystick::last_event = JoyEvent::DOWN; break;
            case JOY_LEFT: Joystick::last_event = JoyEvent::LEFT; break;
            case JOY_RIGHT: Joystick::last_event = JoyEvent::RIGHT; break;
            case JOY_SEL: Joystick::last_event = JoyEvent::SEL; break;
            default: Joystick::last_event = JoyEvent::NONE; break;
        }
    }
}

void handle_joystick_event(JoyEvent event) {
    switch (current_mode) {
        case AppMode::INITIAL_MENU:
            if (event == JoyEvent::UP) {
                InitialMenu::move_selection(-1);
            } else if (event == JoyEvent::DOWN) {
                InitialMenu::move_selection(1);
            } else if (event == JoyEvent::SEL) {
                current_mode = InitialMenu::confirm_selection();
                if (current_mode == AppMode::AUDIO_EFFECTS) {
                    setup_audio_effects_mode();
                } else if (current_mode == AppMode::PITCH_DETECTION) {
                    setup_pitch_detection_mode();
                }
            }
            break;
            
        case AppMode::AUDIO_EFFECTS:
            if (event == JoyEvent::SEL) {
                EffectsMenu::toggle_selected();
                BSP_LED_Toggle(LED1);
            } else if (event == JoyEvent::UP) {
                EffectsMenu::move_selection(-1);
            } else if (event == JoyEvent::DOWN) {
                EffectsMenu::move_selection(1);
            } else if (event == JoyEvent::LEFT) {
                EffectsMenu::adjust_selected_parameter(-1);
            } else if (event == JoyEvent::RIGHT) {
                EffectsMenu::adjust_selected_parameter(1);
            }
            break;
            
        case AppMode::PITCH_DETECTION:
            // Pitch detection mode has no joystick interaction for now
            break;
    }
}

// ============================================================================
// Application Entry Point
// ============================================================================

int main() {
#if defined(DUAL_CORE_BOOT_SYNC_SEQUENCE)
    stm32_wait_for_dual_core_ready(RCC_FLAG_D2CKRDY);
#endif

    stm32_mpu_config();
    stm32_cpu_cache_enable();
    HAL_Init();
    stm32_system_clock_config();

#if defined(DUAL_CORE_BOOT_SYNC_SEQUENCE)
    stm32_sync_dual_core_boot();
#endif

    BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_EXTI);
    stm32_init_leds();

    const auto display_size = stm32_init_display();
    (void)display_size;
    
    if (stm32_start_audio_passthrough() != BSP_ERROR_NONE) {
        Error_Handler();
    }
    
    // Initialize profiling
    AudioPipeline::init_profiling();
    audio_pipeline.set_profiling_enabled(true);
    
    // Initialize joystick
    BSP_JOY_Init(JOY1, JOY_MODE_EXTI, JOY_ALL);
    BSP_AUDIO_IN_SetVolume(0, Audio::INITIAL_IN_VOLUME);
    
    // Show initial menu
    current_mode = AppMode::INITIAL_MENU;
    InitialMenu::draw();

    uint32_t last_stats_update = HAL_GetTick();
    uint32_t last_pitch_update = HAL_GetTick();
    
    while (true) {
        // Handle joystick events
        if (Joystick::event_triggered) {
            const JoyEvent event = Joystick::last_event;
            handle_joystick_event(event);
            Joystick::event_triggered = false;
        }
        
        const uint32_t current_tick = HAL_GetTick();
        
        // Mode-specific periodic updates
        switch (current_mode) {
            case AppMode::AUDIO_EFFECTS:
                // Update CPU utilization stats every 1 second
                if (current_tick - last_stats_update >= Profiling::UPDATE_INTERVAL_MS) {
                    EffectsMenu::update_cpu_stats();
                    last_stats_update = current_tick;
                }
                break;
                
            case AppMode::PITCH_DETECTION:
                // Update pitch display every 100ms
                if (current_tick - last_pitch_update >= PitchDisplay::UPDATE_INTERVAL_MS) {
                    PitchDisplay::update_display();
                    last_pitch_update = current_tick;
                }
                break;
                
            case AppMode::INITIAL_MENU:
            default:
                break;
        }
    }
}

// ============================================================================
// Error Handler
// ============================================================================

void Error_Handler() {
    __disable_irq();
    while (true);
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line) {
    // Add debug info if needed
}
#endif
