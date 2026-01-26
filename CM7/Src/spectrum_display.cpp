/**
 * @file spectrum_display.cpp
 * @brief Spectrum analyzer display rendering implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#include <cstdio>
#include <cmath>
#include "app_common.h"
#include "spectrum_analyzer.h"
#include "lcd_utils.h"

// External spectrum analyzer instance (created in spectrum_analyzer_mode.cpp)
extern SpectrumAnalyzer* g_spectrum_analyzer;

namespace SpectrumDisplay {

namespace {
    // Spectrum area layout
    constexpr uint32_t SPECTRUM_Y = 80;
    constexpr uint32_t SPECTRUM_HEIGHT = 320;
    constexpr uint32_t SPECTRUM_X = 50;
    constexpr uint32_t SPECTRUM_WIDTH = 700;
    
    // CPU display position
    constexpr uint32_t CPU_DISPLAY_X = 650;
    constexpr uint32_t CPU_DISPLAY_Y = 20;
    
    // Cached CPU value to avoid unnecessary redraws
    uint32_t last_cpu_percent_ = 0xFFFFFFFF;
    
    // Cached FFT size to detect changes
    uint32_t last_fft_size_ = 0;
    
    // dB range constants
    constexpr float MIN_DB = -80.0f;
    constexpr float MAX_DB = 0.0f;
    constexpr float DB_RANGE = MAX_DB - MIN_DB;
    
    // Color thresholds (in dB)
    constexpr float RED_THRESHOLD = -20.0f;
    constexpr float YELLOW_THRESHOLD = -50.0f;
    
    // Bar rendering
    constexpr uint32_t BAR_WIDTH = 2;
    constexpr uint32_t BAR_GAP = 1;
    constexpr uint32_t TOTAL_BAR_WIDTH = BAR_WIDTH + BAR_GAP;
    
    /**
     * @brief Get bar color based on magnitude in dB
     */
    uint32_t get_magnitude_color(float db) {
        if (db >= RED_THRESHOLD) {
            return UTIL_LCD_COLOR_RED;
        } else if (db >= YELLOW_THRESHOLD) {
            return UTIL_LCD_COLOR_YELLOW;
        } else {
            return UTIL_LCD_COLOR_GREEN;
        }
    }
    
    /**
     * @brief Convert dB value to bar height in pixels
     */
    uint32_t db_to_height(float db) {
        float normalized = (db - MIN_DB) / DB_RANGE;
        normalized = std::clamp(normalized, 0.0f, 1.0f);
        return static_cast<uint32_t>(normalized * SPECTRUM_HEIGHT);
    }
    
    /**
     * @brief Draw frequency axis labels
     */
    void draw_frequency_labels() {
        UTIL_LCD_SetFont(&Font12);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        
        const uint32_t label_y = SPECTRUM_Y + SPECTRUM_HEIGHT + 5;
        
        // Frequency labels at logarithmic positions
        struct FreqLabel {
            float freq;
            const char* text;
        };
        
        const FreqLabel labels[] = {
            {50.0f, "50"},
            {100.0f, "100"},
            {200.0f, "200"},
            {500.0f, "500"},
            {1000.0f, "1k"},
            {2000.0f, "2k"},
            {5000.0f, "5k"},
            {10000.0f, "10k"},
            {20000.0f, "20k"}
        };
        
        const float log_min = log10f(50.0f);
        const float log_max = log10f(20000.0f);
        const float log_range = log_max - log_min;
        
        for (const auto& label : labels) {
            float log_freq = log10f(label.freq);
            float normalized = (log_freq - log_min) / log_range;
            uint32_t x = SPECTRUM_X + static_cast<uint32_t>(normalized * SPECTRUM_WIDTH);
            
            UTIL_LCD_DisplayStringAt(x - 10, label_y, 
                reinterpret_cast<uint8_t*>(const_cast<char*>(label.text)), LEFT_MODE);
        }
        
        // Hz label
        UTIL_LCD_DisplayStringAt(SPECTRUM_X + SPECTRUM_WIDTH + 10, label_y,
            reinterpret_cast<uint8_t*>(const_cast<char*>("Hz")), LEFT_MODE);
    }
    
    /**
     * @brief Draw magnitude axis labels
     */
    void draw_magnitude_labels() {
        UTIL_LCD_SetFont(&Font12);
        UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
        UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
        
        const char* labels[] = {"0", "-20", "-40", "-60", "-80"};
        const float db_values[] = {0.0f, -20.0f, -40.0f, -60.0f, -80.0f};
        
        for (int i = 0; i < 5; ++i) {
            uint32_t height = db_to_height(db_values[i]);
            uint32_t y = SPECTRUM_Y + SPECTRUM_HEIGHT - height - 6;
            
            UTIL_LCD_DisplayStringAt(5, y,
                reinterpret_cast<uint8_t*>(const_cast<char*>(labels[i])), LEFT_MODE);
        }
        
        // dB label
        UTIL_LCD_DisplayStringAt(5, SPECTRUM_Y - 20,
            reinterpret_cast<uint8_t*>(const_cast<char*>("dB")), LEFT_MODE);
    }
    
    /**
     * @brief Draw grid lines
     */
    void draw_grid() {
        // Horizontal grid lines at dB intervals
        const float db_lines[] = {-20.0f, -40.0f, -60.0f};
        
        for (float db : db_lines) {
            uint32_t height = db_to_height(db);
            uint32_t y = SPECTRUM_Y + SPECTRUM_HEIGHT - height;
            
            // Draw dotted line (white on black background)
            for (uint32_t x = SPECTRUM_X; x < SPECTRUM_X + SPECTRUM_WIDTH; x += 8) {
                BSP_LCD_FillRect(0, x, y, 4, 1, UTIL_LCD_COLOR_WHITE);
            }
        }
    }
    
} // anonymous namespace

void update_cpu_display() {
    if (g_spectrum_analyzer == nullptr) return;
    
    // Finalize the CPU utilization calculation for this measurement period
    g_spectrum_analyzer->finalize_utilization(Profiling::CPU_FREQ_HZ, 
                                               Profiling::UPDATE_INTERVAL_MS);
    
    uint32_t cpu_percent = static_cast<uint32_t>(g_spectrum_analyzer->get_cpu_utilization() + 0.5f);
    
    // Only redraw if changed
    if (cpu_percent == last_cpu_percent_) return;
    last_cpu_percent_ = cpu_percent;
    
    // Clear previous text
    BSP_LCD_FillRect(0, CPU_DISPLAY_X, CPU_DISPLAY_Y, 140, 25, UTIL_LCD_COLOR_WHITE);
    
    // Choose color based on utilization
    uint32_t color;
    if (cpu_percent >= 90) {
        color = UTIL_LCD_COLOR_RED;
    } else if (cpu_percent >= 70) {
        color = UTIL_LCD_COLOR_ORANGE;
    } else {
        color = UTIL_LCD_COLOR_DARKGREEN;
    }
    
    char cpu_str[32];
    snprintf(cpu_str, sizeof(cpu_str), "CPU: %lu%%", cpu_percent);
    
    UTIL_LCD_SetFont(&Font16);
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetTextColor(color);
    UTIL_LCD_DisplayStringAt(CPU_DISPLAY_X, CPU_DISPLAY_Y,
        reinterpret_cast<uint8_t*>(cpu_str), LEFT_MODE);
}

void update_fft_size_display() {
    if (g_spectrum_analyzer == nullptr) return;
    
    uint32_t fft_size = g_spectrum_analyzer->get_fft_size();
    
    // Only redraw if changed
    if (fft_size == last_fft_size_) return;
    last_fft_size_ = fft_size;
    
    // Clear subtitle area
    BSP_LCD_FillRect(0, 0, 48, 800, 22, UTIL_LCD_COLOR_WHITE);
    
    // Draw updated subtitle with FFT size
    char subtitle[64];
    snprintf(subtitle, sizeof(subtitle), "Real-time FFT (%lu points)  [LEFT/RIGHT to change]", fft_size);
    
    UTIL_LCD_SetFont(&Font16);
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
    UTIL_LCD_DisplayStringAt(0, 50,
        reinterpret_cast<uint8_t*>(subtitle), CENTER_MODE);
}

void draw_initial() {
    // Reset cached values
    last_cpu_percent_ = 0xFFFFFFFF;
    last_fft_size_ = 0;
    
    UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);
    
    // Draw title
    UTIL_LCD_SetFont(&Font24);
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
    UTIL_LCD_DisplayStringAt(0, 20,
        reinterpret_cast<uint8_t*>(const_cast<char*>("Spectrum Analyzer")), CENTER_MODE);
    
    // Draw spectrum area background (black)
    BSP_LCD_FillRect(0, SPECTRUM_X, SPECTRUM_Y, SPECTRUM_WIDTH, SPECTRUM_HEIGHT, 
                     UTIL_LCD_COLOR_BLACK);
    
    // Draw border
    UTIL_LCD_DrawRect(SPECTRUM_X - 1, SPECTRUM_Y - 1, 
                      SPECTRUM_WIDTH + 2, SPECTRUM_HEIGHT + 2, UTIL_LCD_COLOR_DARKGRAY);
    
    // Draw axis labels
    draw_frequency_labels();
    draw_magnitude_labels();
    
    // Draw grid
    draw_grid();
    
    // Draw help text
    UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKGRAY);
    UTIL_LCD_DisplayStringAt(0, 450,
        reinterpret_cast<uint8_t*>(const_cast<char*>("Audio input is displayed as frequency spectrum")), CENTER_MODE);
    
    // Draw initial FFT size and CPU utilization
    update_fft_size_display();
    update_cpu_display();
}

void update_display() {
    if (g_spectrum_analyzer == nullptr) return;
    if (!g_spectrum_analyzer->has_new_data()) return;
    
    const auto& magnitudes = g_spectrum_analyzer->get_display_magnitudes();
    g_spectrum_analyzer->clear_new_data_flag();
    
    // Calculate how many display bars we can fit
    const uint32_t num_bars = SPECTRUM_WIDTH / TOTAL_BAR_WIDTH;
    const uint32_t samples_per_bar = SpectrumAnalyzer::DISPLAY_WIDTH / num_bars;
    
    // Draw each bar without clearing first - draw bar + background in one pass
    // This eliminates flickering by avoiding the clear-then-draw pattern
    for (uint32_t bar = 0; bar < num_bars; ++bar) {
        // Find max magnitude for this bar
        float max_db = MIN_DB;
        uint32_t start_idx = bar * samples_per_bar;
        uint32_t end_idx = start_idx + samples_per_bar;
        
        for (uint32_t i = start_idx; i < end_idx && i < magnitudes.size(); ++i) {
            if (magnitudes[i] > max_db) {
                max_db = magnitudes[i];
            }
        }
        
        // Calculate bar dimensions
        uint32_t bar_height = db_to_height(max_db);
        if (bar_height < 1) bar_height = 1;  // Minimum 1 pixel
        
        uint32_t bar_x = SPECTRUM_X + bar * TOTAL_BAR_WIDTH;
        uint32_t bar_bottom = SPECTRUM_Y + SPECTRUM_HEIGHT;
        uint32_t bar_top = bar_bottom - bar_height;
        
        // Get color based on magnitude
        uint32_t color = get_magnitude_color(max_db);
        
        // Draw background (black) above the bar - from spectrum top to bar top
        uint32_t bg_height = bar_top - SPECTRUM_Y;
        if (bg_height > 0) {
            BSP_LCD_FillRect(0, bar_x, SPECTRUM_Y, BAR_WIDTH, bg_height, UTIL_LCD_COLOR_BLACK);
        }
        
        // Draw the bar from bar_top to bottom
        BSP_LCD_FillRect(0, bar_x, bar_top, BAR_WIDTH, bar_height, color);
    }
    
    // Redraw grid lines on top (they may have been overwritten)
    draw_grid();
}

} // namespace SpectrumDisplay
