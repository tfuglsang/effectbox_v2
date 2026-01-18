/**
 * @file lcd_utils.h
 * @brief LCD drawing utilities for flicker-free text and UI elements
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Provides common drawing functions used across different display modes.
 */

#ifndef LCD_UTILS_H
#define LCD_UTILS_H

#include <cstdint>

extern "C" {
#include "stm32h747i_discovery_lcd.h"
#include "stm32_lcd.h"
}

namespace LcdUtils {

/**
 * @brief Draw text with fixed-width background to prevent flicker
 * 
 * Fills a fixed-width rectangle with background color before drawing text,
 * ensuring previous text is completely erased without screen flicker.
 * 
 * @param x X position (used for non-centered text)
 * @param y Y position
 * @param text Text to display
 * @param width Width of background rectangle
 * @param height Height of background rectangle
 * @param text_color Text color
 * @param bg_color Background color
 * @param align Text alignment (LEFT_MODE, CENTER_MODE, RIGHT_MODE)
 */
void draw_text_fixed_width(uint32_t x, uint32_t y, const char* text, 
                           uint32_t width, uint32_t height,
                           uint32_t text_color, uint32_t bg_color,
                           Text_AlignModeTypdef align);

/**
 * @brief Draw a table cell with background fill
 * 
 * @param x X position of cell
 * @param y Y position of cell
 * @param width Cell width
 * @param height Cell height
 * @param text Text to display in cell
 * @param text_color Text color
 * @param bg_color Background color
 * @param font Font to use (default Font16)
 * @param vertical_padding Padding from top of cell to text
 */
void draw_cell(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
               const char* text, uint32_t text_color, uint32_t bg_color,
               sFONT* font = &Font16, uint32_t vertical_padding = 8);

/**
 * @brief Draw a horizontal progress/meter bar
 * 
 * @param x X position
 * @param y Y position
 * @param width Total bar width
 * @param height Bar height
 * @param fill_percent Fill percentage (0.0 to 1.0)
 * @param fill_color Color for filled portion
 * @param bg_color Color for unfilled portion
 */
void draw_bar(uint32_t x, uint32_t y, uint32_t width, uint32_t height,
              float fill_percent, uint32_t fill_color, uint32_t bg_color);

/**
 * @brief Get color based on percentage thresholds
 * 
 * Returns green for low values, yellow/orange for medium, red for high.
 * Useful for CPU utilization, signal strength, etc.
 * 
 * @param percent Current percentage value (0-100)
 * @param green_max Maximum percentage for green (default 70)
 * @param yellow_max Maximum percentage for yellow (default 89)
 * @return Appropriate color based on thresholds
 */
uint32_t get_threshold_color(float percent, 
                             float green_max = 70.0f,
                             float yellow_max = 89.0f);

/**
 * @brief Clear a rectangular area with specified color
 * 
 * @param x X position
 * @param y Y position
 * @param width Rectangle width
 * @param height Rectangle height
 * @param color Fill color
 */
inline void clear_area(uint32_t x, uint32_t y, uint32_t width, uint32_t height, 
                       uint32_t color = UTIL_LCD_COLOR_WHITE) {
    BSP_LCD_FillRect(0, x, y, width, height, color);
}

/**
 * @brief Get screen width
 */
inline uint32_t get_screen_width() {
    uint32_t width = 0;
    BSP_LCD_GetXSize(0, &width);
    return width;
}

/**
 * @brief Get screen height
 */
inline uint32_t get_screen_height() {
    uint32_t height = 0;
    BSP_LCD_GetYSize(0, &height);
    return height;
}

} // namespace LcdUtils

#endif // LCD_UTILS_H
