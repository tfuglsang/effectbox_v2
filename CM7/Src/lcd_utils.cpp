/**
 * @file lcd_utils.cpp
 * @brief LCD drawing utilities implementation
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 */

#include "lcd_utils.h"
#include <cstring>

namespace LcdUtils {

void draw_text_fixed_width(uint32_t x, uint32_t y, const char* text, 
                           uint32_t width, uint32_t height,
                           uint32_t text_color, uint32_t bg_color,
                           Text_AlignModeTypdef align) {
    uint32_t screen_width = get_screen_width();
    
    // Calculate fill position based on alignment
    uint32_t fill_x;
    if (align == CENTER_MODE) {
        fill_x = (screen_width - width) / 2;
    } else if (align == RIGHT_MODE) {
        fill_x = screen_width - width - x;
    } else {
        fill_x = x;
    }
    
    // Fill background
    BSP_LCD_FillRect(0, fill_x, y, width, height, bg_color);
    
    // Draw text
    UTIL_LCD_SetTextColor(text_color);
    UTIL_LCD_SetBackColor(bg_color);
    UTIL_LCD_DisplayStringAt(x, y, 
        reinterpret_cast<uint8_t*>(const_cast<char*>(text)), align);
}

void draw_cell(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
               const char* text, uint32_t text_color, uint32_t bg_color,
               sFONT* font, uint32_t vertical_padding) {
    // Fill background
    BSP_LCD_FillRect(0, x, y, width, height, bg_color);
    
    // Set font and colors
    UTIL_LCD_SetFont(font);
    UTIL_LCD_SetTextColor(text_color);
    UTIL_LCD_SetBackColor(bg_color);
    
    // Draw text with padding
    UTIL_LCD_DisplayStringAt(x, y + vertical_padding, 
        reinterpret_cast<uint8_t*>(const_cast<char*>(text)), LEFT_MODE);
}

void draw_bar(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
              float fill_percent, uint32_t fill_color, uint32_t bg_color) {
    // Clamp percentage
    if (fill_percent < 0.0f) fill_percent = 0.0f;
    if (fill_percent > 1.0f) fill_percent = 1.0f;
    
    // Draw background
    BSP_LCD_FillRect(0, x, y, width, height, bg_color);
    
    // Draw filled portion
    if (fill_percent > 0.0f) {
        uint32_t fill_width = static_cast<uint32_t>(width * fill_percent);
        if (fill_width > width) fill_width = width;
        if (fill_width > 0) {
            BSP_LCD_FillRect(0, x, y, fill_width, height, fill_color);
        }
    }
}

uint32_t get_threshold_color(float percent, float green_max, float yellow_max) {
    if (percent >= yellow_max + 1.0f) {
        return UTIL_LCD_COLOR_RED;           // Critical (90%+)
    } else if (percent >= green_max + 1.0f) {
        return UTIL_LCD_COLOR_ORANGE;        // Warning (71-89%)
    } else {
        return UTIL_LCD_COLOR_DARKGREEN;     // Good (0-70%)
    }
}

} // namespace LcdUtils
