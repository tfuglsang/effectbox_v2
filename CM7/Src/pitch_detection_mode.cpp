/**
 * @file pitch_detection_mode.cpp
 * @brief Pitch Detection mode implementation - Guitar Tuner
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Contains the PitchDisplay namespace and pitch detection mode setup.
 * Optimized for guitar tuning in standard tuning (E A D G B E).
 */

#include <cstring>
#include <cstdio>
#include <cmath>

#include "app_common.h"
#include "yin_pitch_detector.h"
#include "lcd_utils.h"
#include "guitar_tuning.h"

// ============================================================================
// Pitch Detector (used by this mode)
// ============================================================================

static YinPitchDetector pitch_detector(static_cast<float>(Audio::SAMPLE_RATE), 0.15f, "YIN Pitch");

// ============================================================================
// Pitch Detection Display - Guitar Tuner
// ============================================================================

namespace PitchDisplay {
    // Cache previous values to avoid unnecessary redraws
    static float last_pitch_ = -1.0f;
    static float last_confidence_ = -1.0f;
    static float last_cents_ = -999.0f;
    static char last_freq_str_[32] = "";
    static char last_note_str_[32] = "";
    static int last_tuning_direction_ = 0;  // -1 = flat, 0 = in tune, 1 = sharp
    
    /**
     * @brief Draw the tuning indicator (shows if pitch is flat, sharp, or in tune)
     */
    static void draw_tuning_indicator(float cents) {
        using namespace GuitarTuning;
        
        const uint32_t screen_width = LcdUtils::get_screen_width();
        
        constexpr uint32_t indicator_y = 300;
        constexpr uint32_t indicator_height = 50;
        constexpr uint32_t bar_width = 400;
        const uint32_t bar_x = (screen_width - bar_width) / 2;
        const uint32_t center_x = screen_width / 2;
        
        // Clear the indicator area
        LcdUtils::clear_area(bar_x, indicator_y, bar_width, indicator_height);
        
        // Determine tuning state using guitar_tuning module
        int direction = get_tuning_direction(cents);
        
        // Draw the tuning bar background
        constexpr uint32_t bar_height = 20;
        const uint32_t bar_y = indicator_y + 15;
        BSP_LCD_FillRect(0, bar_x, bar_y, bar_width, bar_height, UTIL_LCD_COLOR_LIGHTGRAY);
        
        // Draw center marker (green zone for "in tune")
        constexpr uint32_t green_zone_width = 20;
        BSP_LCD_FillRect(0, center_x - green_zone_width/2, bar_y, 
                        green_zone_width, bar_height, UTIL_LCD_COLOR_DARKGREEN);
        
        // Draw the pitch indicator needle
        // Map cents (-50 to +50) to pixel position
        float clamped_cents = cents;
        if (clamped_cents < -50.0f) clamped_cents = -50.0f;
        if (clamped_cents > 50.0f) clamped_cents = 50.0f;
        
        int32_t needle_offset = static_cast<int32_t>((clamped_cents / 50.0f) * (bar_width / 2 - 10));
        uint32_t needle_x = center_x + needle_offset - 3;
        
        // Choose needle color based on how in-tune it is
        float abs_cents = (cents < 0) ? -cents : cents;
        uint32_t needle_color;
        if (abs_cents <= IN_TUNE_THRESHOLD) {
            needle_color = UTIL_LCD_COLOR_DARKGREEN;  // In tune
        } else if (abs_cents <= CLOSE_THRESHOLD) {
            needle_color = UTIL_LCD_COLOR_YELLOW;     // Close
        } else {
            needle_color = UTIL_LCD_COLOR_RED;        // Out of tune
        }
        
        // Draw needle (vertical bar)
        BSP_LCD_FillRect(0, needle_x, bar_y - 5, 6, bar_height + 10, needle_color);
        
        // Draw arrows and text indicating direction
        UTIL_LCD_SetFont(&Font24);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        
        if (direction == -1) {
            // Flat - need to tune UP
            UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
            UTIL_LCD_DisplayStringAt(bar_x - 50, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>("<<")), LEFT_MODE);
            UTIL_LCD_DisplayStringAt(bar_x + bar_width + 10, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(" ")), LEFT_MODE);
        } else if (direction == 1) {
            // Sharp - need to tune DOWN
            UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
            UTIL_LCD_DisplayStringAt(bar_x - 50, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(" ")), LEFT_MODE);
            UTIL_LCD_DisplayStringAt(bar_x + bar_width + 10, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(">>")), LEFT_MODE);
        } else {
            // In tune!
            UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGREEN);
            UTIL_LCD_DisplayStringAt(bar_x - 50, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(" ")), LEFT_MODE);
            UTIL_LCD_DisplayStringAt(bar_x + bar_width + 10, indicator_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(" ")), LEFT_MODE);
        }
        
        // Show cents deviation
        char cents_str[16];
        int cents_int = static_cast<int>(cents);
        snprintf(cents_str, sizeof(cents_str), "%+d cents", cents_int);
        UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
        LcdUtils::draw_text_fixed_width(0, bar_y + bar_height + 5, cents_str, 150, 20, 
                             UTIL_LCD_COLOR_BLACK, UTIL_LCD_COLOR_WHITE, CENTER_MODE);
        
        last_tuning_direction_ = direction;
    }
    
    void draw_initial() {
        // Reset cached values
        last_pitch_ = -1.0f;
        last_confidence_ = -1.0f;
        last_cents_ = -999.0f;
        last_freq_str_[0] = '\0';
        last_note_str_[0] = '\0';
        last_tuning_direction_ = 0;
        
        UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);
        
        // Draw title
        UTIL_LCD_SetFont(&Font24);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
        UTIL_LCD_DisplayStringAt(0, 20, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Guitar Tuner")), CENTER_MODE);
        
        // Draw guitar string reference
        UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        UTIL_LCD_DisplayStringAt(0, 55, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Standard: E2 A2 D3 G3 B3 E4")), CENTER_MODE);
        
        // Draw labels
        UTIL_LCD_SetFont(&Font16);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        UTIL_LCD_DisplayStringAt(0, 90, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Detected:")), CENTER_MODE);
        
        // Draw confidence label
        UTIL_LCD_DisplayStringAt(0, 380, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Signal:")), CENTER_MODE);
        
        // Draw help text at bottom
        UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
        UTIL_LCD_DisplayStringAt(0, 460, 
            reinterpret_cast<uint8_t*>(const_cast<char*>("Play a string - arrows show tuning direction")), CENTER_MODE);
        
        // Draw initial values
        update_display();
    }
    
    void update_display() {
        using namespace GuitarTuning;
        
        float pitch = pitch_detector.get_pitch();
        float confidence = pitch_detector.get_probability();
        
        // Build frequency and note strings
        char freq_buffer[32];
        char note_buffer[32];
        float cents = 0.0f;
        
        if (pitch > 0.0f) {
            int pitch_int = static_cast<int>(pitch);
            int pitch_frac = static_cast<int>((pitch - pitch_int) * 10.0f);
            snprintf(freq_buffer, sizeof(freq_buffer), "%d.%d Hz", pitch_int, pitch_frac);
            cents = freq_to_note_string(pitch, note_buffer, sizeof(note_buffer), false);
        } else {
            snprintf(freq_buffer, sizeof(freq_buffer), "--- Hz");
            snprintf(note_buffer, sizeof(note_buffer), "---");
        }
        
        // Only redraw note if changed
        if (strcmp(note_buffer, last_note_str_) != 0) {
            UTIL_LCD_SetFont(&Font24);
            uint32_t text_color = (pitch > 0.0f) ? UTIL_LCD_COLOR_DARKBLUE : UTIL_LCD_COLOR_DARKGRAY;
            // Large note display
            LcdUtils::draw_text_fixed_width(0, 130, note_buffer, 200, 40, text_color, UTIL_LCD_COLOR_WHITE, CENTER_MODE);
            strncpy(last_note_str_, note_buffer, sizeof(last_note_str_) - 1);
        }
        
        // Only redraw frequency if changed
        if (strcmp(freq_buffer, last_freq_str_) != 0) {
            UTIL_LCD_SetFont(&Font16);
            uint32_t text_color = (pitch > 0.0f) ? UTIL_LCD_COLOR_DARKGREEN : UTIL_LCD_COLOR_DARKGRAY;
            LcdUtils::draw_text_fixed_width(0, 180, freq_buffer, 200, 25, text_color, UTIL_LCD_COLOR_WHITE, CENTER_MODE);
            strncpy(last_freq_str_, freq_buffer, sizeof(last_freq_str_) - 1);
        }
        
        // Find which guitar string this might be
        if (pitch > 0.0f) {
            int string_idx = find_closest_string(pitch);
            if (string_idx >= 0) {
                // Show target string info
                char target_str[32];
                snprintf(target_str, sizeof(target_str), "Target: %s (%.1f Hz)", 
                        STANDARD_TUNING[string_idx].name, 
                        STANDARD_TUNING[string_idx].frequency);
                UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
                LcdUtils::draw_text_fixed_width(0, 220, target_str, 300, 20, 
                                     UTIL_LCD_COLOR_DARKGRAY, UTIL_LCD_COLOR_WHITE, CENTER_MODE);
                
                // Calculate cents relative to target guitar string
                cents = calculate_cents(pitch, STANDARD_TUNING[string_idx].frequency);
            }
        } else {
            // Clear target info when no pitch
            LcdUtils::draw_text_fixed_width(0, 220, " ", 300, 20, 
                                 UTIL_LCD_COLOR_WHITE, UTIL_LCD_COLOR_WHITE, CENTER_MODE);
        }
        
        // Update tuning indicator if cents changed significantly
        float cents_diff = (cents > last_cents_) ? (cents - last_cents_) : (last_cents_ - cents);
        if (pitch > 0.0f && (cents_diff > 1.0f || last_cents_ < -900.0f)) {
            draw_tuning_indicator(cents);
            last_cents_ = cents;
        } else if (pitch <= 0.0f && last_pitch_ > 0.0f) {
            // Clear tuning indicator when pitch lost
            const uint32_t screen_width = LcdUtils::get_screen_width();
            LcdUtils::clear_area(0, 250, screen_width, 120);
            last_cents_ = -999.0f;
        }
        
        // Only redraw confidence bar if changed significantly (>2% difference)
        float conf_diff = (confidence > last_confidence_) ? 
                          (confidence - last_confidence_) : (last_confidence_ - confidence);
        if (conf_diff > 0.02f || last_confidence_ < 0.0f) {
            const uint32_t screen_width = LcdUtils::get_screen_width();
            constexpr uint32_t bar_width = 300;
            constexpr uint32_t bar_height = 20;
            const uint32_t bar_x = (screen_width - bar_width) / 2;
            constexpr uint32_t bar_y = 410;
            
            // Use threshold color based on confidence level (inverted - high is good)
            uint32_t color;
            if (confidence > 0.7f) {
                color = UTIL_LCD_COLOR_DARKGREEN;
            } else if (confidence > 0.4f) {
                color = UTIL_LCD_COLOR_YELLOW;
            } else {
                color = UTIL_LCD_COLOR_RED;
            }
            
            LcdUtils::draw_bar(bar_x, bar_y, bar_width, bar_height, 
                              confidence, color, UTIL_LCD_COLOR_LIGHTGRAY);
            
            last_confidence_ = confidence;
        }
        
        last_pitch_ = pitch;
    }
}

// ============================================================================
// Pitch Detection Mode Setup
// ============================================================================

void setup_pitch_detection_mode() {
    // Clear pipeline and add pitch detector
    // The pitch detector is a pass-through analyzer (doesn't modify audio)
    // Audio from microphone will pass through to headphones
    audio_pipeline.clear();
    audio_pipeline.add_effect(&pitch_detector);
    
    pitch_detector.set_enabled(true);
    
    // Draw pitch detection UI
    PitchDisplay::draw_initial();
}
