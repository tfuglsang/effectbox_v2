/**
 * @file stm32h7xx.h
 * @brief Mock STM32H7 HAL types for host-side testing
 */

#ifndef STM32H7XX_MOCK_H
#define STM32H7XX_MOCK_H

#include <cstdint>

// Mock DWT (Data Watchpoint and Trace) for cycle counting
typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t CYCCNT;
} DWT_Type;

// Mock CoreDebug
typedef struct {
    volatile uint32_t DEMCR;
} CoreDebug_Type;

// Global mock instances
inline DWT_Type DWT_Instance = {0, 0};
inline CoreDebug_Type CoreDebug_Instance = {0};

#define DWT (&DWT_Instance)
#define CoreDebug (&CoreDebug_Instance)

// DWT control register bits
#define DWT_CTRL_CYCCNTENA_Msk (1UL << 0)

// CoreDebug DEMCR bits
#define CoreDebug_DEMCR_TRCENA_Msk (1UL << 24)

// Mock BSP audio functions
extern "C" {
    inline int32_t BSP_AUDIO_OUT_SetVolume(uint32_t Instance, uint32_t Volume) {
        (void)Instance;
        (void)Volume;
        return 0;  // Success
    }
    
    inline int32_t BSP_AUDIO_IN_SetVolume(uint32_t Instance, uint32_t Volume) {
        (void)Instance;
        (void)Volume;
        return 0;  // Success
    }
}

#endif // STM32H7XX_MOCK_H
