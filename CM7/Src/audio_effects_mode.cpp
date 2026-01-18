/**
 * @file audio_effects_mode.cpp
 * @brief Audio Effects mode implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Contains the EffectsMenu namespace and audio effects mode setup.
 */

#include <string>
#include <cstring>
#include <cstdio>

#include "app_common.h"
#include "gain_effect.h"
#include "biquad_filter_effect.h"
#include "codec_volume_effect.h"
#include "cpu_burn_effect.h"
#include "guitar_effects.h"
#include "lcd_utils.h"

// ============================================================================
// Audio Effects (defined here, used by this mode)
// ============================================================================

// Codec volume controls (hardware gain adjustment) - at start of chain
static CodecInVolume codec_in_volume(Audio::INITIAL_IN_VOLUME);   // Initial volume 50%
static CodecOutVolume codec_out_volume(Audio::INITIAL_OUT_VOLUME); // Initial volume 100%

// Guitar effects chain
static DistortionEffect distortion_effect(10.0f);   // Distortion/overdrive
static ChorusEffect chorus_effect(1.5f, 0.5f, 0.4f); // Chorus for shimmer
static FlangerEffect flanger_effect(0.3f, 0.7f, 0.5f); // Flanger sweep
static TremoloEffect tremolo_effect(5.0f, 0.5f);    // Amplitude modulation
static DelayEffect delay_effect(250, 0.4f, 0.4f);   // Echo/delay
static ReverbEffect reverb_effect(0.6f, 0.3f);      // Room reverb

// Output gain
static GainEffect gain_effect(0.8f);  // Output level control

// CPU burn effect for profiling testing (starts disabled)
static CpuBurnEffect cpu_burn_effect(100, "CPU Burn (debug)");

// ============================================================================
// Effects Menu System - Table Layout
// ============================================================================

namespace EffectsMenu {
    // Table layout constants - maximized for 800x480 display with 12 effects
    // Screen height: 480px, Width: 800px
    constexpr uint32_t TABLE_START_Y = 30;      // Y position where table starts (after title)
    constexpr uint32_t TABLE_MARGIN_X = 10;     // Left margin
    constexpr uint32_t ROW_HEIGHT = 32;         // Height of each row (for Font16)
    constexpr uint32_t HEADER_HEIGHT = 28;      // Height of header row
    
    // Column positions (X coordinates) - spread across 780px width
    constexpr uint32_t COL_ENABLED_X = TABLE_MARGIN_X + 5;
    constexpr uint32_t COL_NAME_X = TABLE_MARGIN_X + 80;
    constexpr uint32_t COL_PARAM_X = TABLE_MARGIN_X + 450;
    constexpr uint32_t COL_CPU_X = TABLE_MARGIN_X + 620;
    constexpr uint32_t TABLE_WIDTH = 780;
    
    // Column widths for selective redraw
    constexpr uint32_t COL_ENABLED_WIDTH = 70;
    constexpr uint32_t COL_PARAM_WIDTH = 160;
    constexpr uint32_t COL_CPU_WIDTH = 100;
    
    // Colors
    constexpr uint32_t COLOR_HEADER_BG = UTIL_LCD_COLOR_DARKBLUE;
    constexpr uint32_t COLOR_HEADER_TEXT = UTIL_LCD_COLOR_WHITE;
    constexpr uint32_t COLOR_ROW_NORMAL = UTIL_LCD_COLOR_WHITE;
    constexpr uint32_t COLOR_ROW_SELECTED = UTIL_LCD_COLOR_LIGHTBLUE;
    constexpr uint32_t COLOR_TEXT_NORMAL = UTIL_LCD_COLOR_BLACK;
    constexpr uint32_t COLOR_TEXT_SELECTED = UTIL_LCD_COLOR_DARKBLUE;
    constexpr uint32_t COLOR_BORDER = UTIL_LCD_COLOR_DARKGRAY;
    constexpr uint32_t COLOR_ENABLED = UTIL_LCD_COLOR_DARKGREEN;
    constexpr uint32_t COLOR_DISABLED = UTIL_LCD_COLOR_RED;
    
    // Pipeline reference - set via init()
    AudioPipeline* pipeline_ = nullptr;
    uint32_t selected_index = 0;
    
    // Cached values for each row to minimize redraws
    struct RowCache {
        bool enabled = false;
        char param[12] = "";
        uint32_t cpu_pct = 0;
        bool is_selected = false;
        bool initialized = false;
    };
    static constexpr uint32_t MAX_CACHED_ROWS = 16;
    RowCache row_cache_[MAX_CACHED_ROWS];
    
    // Cached total CPU for flicker-free update
    static uint32_t last_total_cpu_ = 0xFFFFFFFF;
    
    // Forward declarations
    void draw_total_cpu();
    
    // Helper functions to access pipeline
    uint32_t get_num_effects() {
        return pipeline_ ? pipeline_->get_effect_count() : 0;
    }
    
    AudioEffect* get_effect(uint32_t index) {
        return pipeline_ ? pipeline_->get_effect(index) : nullptr;
    }
    
    void init(AudioPipeline* pipeline) {
        pipeline_ = pipeline;
        selected_index = 0;
        // Clear cache
        for (uint32_t i = 0; i < MAX_CACHED_ROWS; i++) {
            row_cache_[i].initialized = false;
        }
    }
    
    void draw_table_header() {
        const uint32_t header_y = TABLE_START_Y;
        
        // Draw header background
        BSP_LCD_FillRect(0, TABLE_MARGIN_X, header_y, 
                        TABLE_WIDTH, HEADER_HEIGHT, COLOR_HEADER_BG);
        
        // Draw header text with larger font
        UTIL_LCD_SetFont(&Font16);
        UTIL_LCD_SetTextColor(COLOR_HEADER_TEXT);
        UTIL_LCD_SetBackColor(COLOR_HEADER_BG);
        
        UTIL_LCD_DisplayStringAt(COL_ENABLED_X, header_y + 6, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("ON")), LEFT_MODE);
        UTIL_LCD_DisplayStringAt(COL_NAME_X, header_y + 6, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Effect Name")), LEFT_MODE);
        UTIL_LCD_DisplayStringAt(COL_PARAM_X, header_y + 6, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Parameter")), LEFT_MODE);
        UTIL_LCD_DisplayStringAt(COL_CPU_X, header_y + 6, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("CPU %")), LEFT_MODE);
    }
    
    /**
     * @brief Draw a single cell with background fill to prevent flicker
     *        Uses LcdUtils::draw_cell for consistent rendering
     */
    void draw_cell(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
                   const char* text, uint32_t text_color, uint32_t bg_color) {
        LcdUtils::draw_cell(x, y, width, height, text, text_color, bg_color, &Font16, 8);
    }
    
    void draw_table_row(uint32_t index) {
        const uint32_t num_effects = get_num_effects();
        if (index >= num_effects || index >= MAX_CACHED_ROWS) return;
        
        AudioEffect* effect = get_effect(index);
        if (effect == nullptr) return;
        
        const uint32_t row_y = TABLE_START_Y + HEADER_HEIGHT + (index * ROW_HEIGHT);
        const bool is_selected = (index == selected_index);
        const bool is_enabled = effect->is_enabled();
        
        // Get current values
        char param_buffer[12] = "-";
        if (effect->has_parameter()) {
            effect->get_parameter_string(param_buffer, sizeof(param_buffer));
        }
        uint32_t cpu_rounded = static_cast<uint32_t>(effect->get_cpu_utilization() + 0.5f);
        
        RowCache& cache = row_cache_[index];
        
        // Check what needs updating
        bool selection_changed = !cache.initialized || (cache.is_selected != is_selected);
        bool enabled_changed = !cache.initialized || (cache.enabled != is_enabled);
        bool param_changed = !cache.initialized || (strcmp(cache.param, param_buffer) != 0);
        bool cpu_changed = !cache.initialized || (cache.cpu_pct != cpu_rounded);
        
        // Choose colors based on selection
        const uint32_t bg_color = is_selected ? COLOR_ROW_SELECTED : COLOR_ROW_NORMAL;
        const uint32_t text_color = is_selected ? COLOR_TEXT_SELECTED : COLOR_TEXT_NORMAL;
        
        // If selection changed, redraw entire row background
        if (selection_changed) {
            BSP_LCD_FillRect(0, TABLE_MARGIN_X, row_y, TABLE_WIDTH, ROW_HEIGHT, bg_color);
            
            // Draw selection indicator (left border highlight)
            if (is_selected) {
                BSP_LCD_FillRect(0, TABLE_MARGIN_X, row_y, 4, ROW_HEIGHT, UTIL_LCD_COLOR_BLUE);
            }
            
            // Draw bottom border
            BSP_LCD_FillRect(0, TABLE_MARGIN_X, row_y + ROW_HEIGHT - 1, 
                            TABLE_WIDTH, 1, COLOR_BORDER);
            
            // Force redraw all cells
            enabled_changed = true;
            param_changed = true;
            cpu_changed = true;
            
            // Redraw name (doesn't change but needs redraw on selection change)
            char name_buffer[20];
            snprintf(name_buffer, sizeof(name_buffer), "%-16s", 
                     std::string(effect->get_name()).c_str());
            UTIL_LCD_SetFont(&Font16);
            UTIL_LCD_SetBackColor(bg_color);
            UTIL_LCD_SetTextColor(text_color);
            UTIL_LCD_DisplayStringAt(COL_NAME_X, row_y + 8, 
                reinterpret_cast<uint8_t*>(name_buffer), LEFT_MODE);
        }
        
        // Column 1: Enabled status
        if (enabled_changed) {
            if (is_enabled) {
                draw_cell(COL_ENABLED_X, row_y, COL_ENABLED_WIDTH, ROW_HEIGHT - 1,
                         "ON", COLOR_ENABLED, bg_color);
            } else {
                draw_cell(COL_ENABLED_X, row_y, COL_ENABLED_WIDTH, ROW_HEIGHT - 1,
                         "OFF", COLOR_DISABLED, bg_color);
            }
        }
        
        // Column 3: Parameter value
        if (param_changed) {
            draw_cell(COL_PARAM_X, row_y, COL_PARAM_WIDTH, ROW_HEIGHT - 1,
                     param_buffer, text_color, bg_color);
        }
        
        // Column 4: CPU utilization
        if (cpu_changed) {
            char cpu_buffer[12];
            snprintf(cpu_buffer, sizeof(cpu_buffer), "%3lu%%", cpu_rounded);
            draw_cell(COL_CPU_X, row_y, COL_CPU_WIDTH, ROW_HEIGHT - 1,
                     cpu_buffer, text_color, bg_color);
        }
        
        // Update cache
        cache.enabled = is_enabled;
        strncpy(cache.param, param_buffer, sizeof(cache.param) - 1);
        cache.cpu_pct = cpu_rounded;
        cache.is_selected = is_selected;
        cache.initialized = true;
    }
    
    void clear_table_area() {
        const uint32_t num_effects = get_num_effects();
        const uint32_t total_height = HEADER_HEIGHT + (num_effects * ROW_HEIGHT) + 40;
        BSP_LCD_FillRect(0, TABLE_MARGIN_X - 5, TABLE_START_Y - 35, 
                        TABLE_WIDTH + 10, total_height + 40, UTIL_LCD_COLOR_WHITE);
    }
    
    void draw_full_menu() {
        const uint32_t num_effects = get_num_effects();
        
        // Clear cache to force full redraw
        for (uint32_t i = 0; i < MAX_CACHED_ROWS; i++) {
            row_cache_[i].initialized = false;
        }
        
        // Draw title with large font
        UTIL_LCD_SetFont(&Font20);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_DisplayStringAt(TABLE_MARGIN_X, 5, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Audio Effects Pipeline")), LEFT_MODE);
        
        // Draw table border (outer frame)
        const uint32_t table_height = HEADER_HEIGHT + (num_effects * ROW_HEIGHT);
        BSP_LCD_FillRect(0, TABLE_MARGIN_X - 1, TABLE_START_Y - 1, 
                        TABLE_WIDTH + 2, table_height + 2, COLOR_BORDER);
        
        // Draw header
        draw_table_header();
        
        // Draw all rows
        for (uint32_t i = 0; i < num_effects; i++) {
            draw_table_row(i);
        }
        
        // Draw help text and CPU below table
        const uint32_t footer_y = TABLE_START_Y + HEADER_HEIGHT + (num_effects * ROW_HEIGHT) + 5;
        UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_DisplayStringAt(TABLE_MARGIN_X, footer_y, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("UP/DN: Select   SEL: Toggle ON/OFF   LEFT/RIGHT: Adjust Parameter")), LEFT_MODE);
        
        // Draw total CPU utilization (will be updated by update_cpu_stats)
        last_total_cpu_ = 0xFFFFFFFF;  // Force redraw
        draw_total_cpu();
    }
    
    /**
     * @brief Draw total CPU utilization with color coding
     *        Uses LcdUtils::get_threshold_color for consistent color thresholds
     */
    void draw_total_cpu() {
        const uint32_t num_effects = get_num_effects();
        
        // Calculate total CPU utilization
        float total_cpu = 0.0f;
        for (uint32_t i = 0; i < num_effects; i++) {
            AudioEffect* effect = get_effect(i);
            if (effect && effect->is_enabled()) {
                total_cpu += effect->get_cpu_utilization();
            }
        }
        
        uint32_t total_cpu_int = static_cast<uint32_t>(total_cpu + 0.5f);
        
        // Only redraw if changed
        if (total_cpu_int == last_total_cpu_) return;
        last_total_cpu_ = total_cpu_int;
        
        // Position below help text
        const uint32_t cpu_y = TABLE_START_Y + HEADER_HEIGHT + (num_effects * ROW_HEIGHT) + 22;
        
        // Clear the area first
        LcdUtils::clear_area(TABLE_MARGIN_X, cpu_y, 350, 20);
        
        // Choose color based on utilization level using shared threshold function
        uint32_t cpu_color = LcdUtils::get_threshold_color(
            static_cast<float>(total_cpu_int), 70.0f, 90.0f);
        
        // Format and display with Font16 for visibility
        char cpu_str[32];
        snprintf(cpu_str, sizeof(cpu_str), "Total CPU Utilization: %lu%%", total_cpu_int);
        
        UTIL_LCD_SetFont(&Font16);
        UTIL_LCD_SetTextColor(cpu_color);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_DisplayStringAt(TABLE_MARGIN_X, cpu_y, 
            reinterpret_cast<uint8_t*>(cpu_str), LEFT_MODE);
    }
    
    void move_selection(int delta) {
        uint32_t old_index = selected_index;
        const uint32_t num_effects = get_num_effects();
        
        if (delta < 0 && selected_index == 0) {
            selected_index = num_effects - 1;
        } else if (delta > 0 && selected_index == num_effects - 1) {
            selected_index = 0;
        } else {
            selected_index = static_cast<uint32_t>(static_cast<int>(selected_index) + delta);
        }
        
        // Redraw affected rows
        draw_table_row(old_index);
        draw_table_row(selected_index);
    }
    
    void toggle_selected() {
        AudioEffect* effect = get_effect(selected_index);
        if (effect) {
            effect->set_enabled(!effect->is_enabled());
            draw_table_row(selected_index);
        }
    }
    
    void adjust_selected_parameter(int delta) {
        AudioEffect* effect = get_effect(selected_index);
        if (effect && effect->has_parameter()) {
            effect->adjust_parameter(delta);
            draw_table_row(selected_index);
        }
    }
    
    void update_cpu_stats() {
        const uint32_t num_effects = get_num_effects();
        
        // Finalize utilization for all effects
        for (uint32_t i = 0; i < num_effects; i++) {
            AudioEffect* effect = get_effect(i);
            if (effect) {
                effect->finalize_utilization(Profiling::CPU_FREQ_HZ, 
                                             Profiling::UPDATE_INTERVAL_MS);
            }
        }
        
        // Redraw all rows to show updated CPU %
        for (uint32_t i = 0; i < num_effects; i++) {
            draw_table_row(i);
        }
        
        // Update total CPU display
        draw_total_cpu();
    }
}

// ============================================================================
// Audio Effects Mode Setup
// ============================================================================

void setup_audio_effects_mode() {
    // Initialize codec volume controls if not already done
    codec_in_volume.init();
    codec_out_volume.init();
    
    // Clear pipeline and add audio effects in signal flow order
    audio_pipeline.clear();
    
    // === Input Stage ===
    audio_pipeline.add_effect(&codec_in_volume);    // Hardware input gain
    
    // === Guitar Effects Chain ===
    audio_pipeline.add_effect(&distortion_effect);  // Distortion/overdrive (disabled by default)
    audio_pipeline.add_effect(&chorus_effect);      // Chorus (disabled by default)
    audio_pipeline.add_effect(&flanger_effect);     // Flanger (disabled by default)
    audio_pipeline.add_effect(&tremolo_effect);     // Tremolo (disabled by default)
    audio_pipeline.add_effect(&delay_effect);       // Delay/echo (disabled by default)
    audio_pipeline.add_effect(&reverb_effect);      // Reverb (disabled by default)
    
    // === Output Stage ===
    audio_pipeline.add_effect(&gain_effect);        // Output level
    audio_pipeline.add_effect(&codec_out_volume);   // Hardware output gain
    
    // === Utilities ===
    audio_pipeline.add_effect(&cpu_burn_effect);    // CPU stress test (disabled)
    
    // Set initial states - guitar effects start disabled
    distortion_effect.set_enabled(false);
    chorus_effect.set_enabled(false);
    flanger_effect.set_enabled(false);
    tremolo_effect.set_enabled(false);
    delay_effect.set_enabled(false);
    reverb_effect.set_enabled(false);
    cpu_burn_effect.set_enabled(false);
    
    // Initialize and draw effects menu
    EffectsMenu::init(&audio_pipeline);
    UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);
    EffectsMenu::draw_full_menu();
}
