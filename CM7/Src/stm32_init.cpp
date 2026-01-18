/**
 * @file stm32_init.cpp
 * @brief STM32 hardware initialization functions
 * @author Thomas Fuglsang <tfuglsang@gmail.com>
 * 
 * Contains all low-level hardware initialization code:
 * - System clock configuration
 * - MPU configuration
 * - CPU cache enable
 * - UART initialization
 * - LCD/Display initialization
 * - LED initialization
 * - Audio passthrough setup
 */

#include "app_common.h"

extern "C" {
#include "main.h"
}

// ============================================================================
// UART Configuration
// ============================================================================

UART_HandleTypeDef huart1;

void stm32_uart_init() {
    constexpr uint32_t BAUD_RATE = 115200U;
    
    RCC_PeriphCLKInitTypeDef clock_init{
        .PeriphClockSelection = RCC_PERIPHCLK_USART1,
        .Usart16ClockSelection = RCC_USART16CLKSOURCE_D2PCLK2
    };
    HAL_RCCEx_PeriphCLKConfig(&clock_init);

    huart1 = UART_HandleTypeDef{
        .Instance = USART1,
        .Init = UART_InitTypeDef{
            .BaudRate = BAUD_RATE,
            .WordLength = UART_WORDLENGTH_8B,
            .StopBits = UART_STOPBITS_1,
            .Parity = UART_PARITY_NONE,
            .Mode = UART_MODE_TX_RX,
            .HwFlowCtl = UART_HWCONTROL_NONE,
            .OverSampling = UART_OVERSAMPLING_16,
            .OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE,
            .ClockPrescaler = UART_PRESCALER_DIV1
        },
        .AdvancedInit = UART_AdvFeatureInitTypeDef{
            .AdvFeatureInit = UART_ADVFEATURE_NO_INIT
        }
    };
    
    HAL_UART_Init(&huart1);
    HAL_UARTEx_SetTxFifoThreshold(&huart1, UART_TXFIFO_THRESHOLD_1_8);
    HAL_UARTEx_SetRxFifoThreshold(&huart1, UART_RXFIFO_THRESHOLD_1_8);
    HAL_UARTEx_DisableFifoMode(&huart1);
}

// ============================================================================
// Display and Hardware Initialization
// ============================================================================

namespace Display {
    constexpr uint32_t DISPLAY_INSTANCE = 0U;
    constexpr uint32_t TITLE_Y = 10U;
    constexpr const char* TITLE_TEXT = "Audio Effects";
}

DisplaySize stm32_init_display() {
    BSP_LCD_Init(Display::DISPLAY_INSTANCE, LCD_ORIENTATION_LANDSCAPE);
    BSP_LCD_DisplayOn(Display::DISPLAY_INSTANCE);
    UTIL_LCD_SetFuncDriver(&LCD_Driver);
    
    DisplaySize size{};
    BSP_LCD_GetXSize(Display::DISPLAY_INSTANCE, &size.width);
    BSP_LCD_GetYSize(Display::DISPLAY_INSTANCE, &size.height);
    
    UTIL_LCD_Clear(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_WHITE);
    UTIL_LCD_SetFont(&UTIL_LCD_DEFAULT_FONT);
    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_DARKBLUE);
    UTIL_LCD_DisplayStringAt(0, Display::TITLE_Y, 
        reinterpret_cast<uint8_t*>(const_cast<char*>(Display::TITLE_TEXT)), 
        CENTER_MODE);
    return size;
}

void stm32_init_leds() {
    BSP_LED_Init(LED1);
    BSP_LED_Init(LED2);
    BSP_LED_Init(LED3);
    BSP_LED_Init(LED4);
}

// ============================================================================
// Audio Subsystem
// ============================================================================

uint32_t stm32_start_audio_passthrough() {
    constexpr BSP_AUDIO_Init_t OUT_CONFIG{
        .Device = AUDIO_OUT_DEVICE_HEADPHONE,
        .SampleRate = Audio::SAMPLE_RATE,
        .BitsPerSample = Audio::BITS_PER_SAMPLE,
        .ChannelsNbr = Audio::NUM_CHANNELS,
        .Volume = Audio::INITIAL_OUT_VOLUME
    };

    if (BSP_AUDIO_OUT_Init(0, const_cast<BSP_AUDIO_Init_t*>(&OUT_CONFIG)) != BSP_ERROR_NONE) {
        return BSP_ERROR_PERIPH_FAILURE;
    }

    BSP_AUDIO_Init_t IN_CONFIG = OUT_CONFIG;
    IN_CONFIG.Device = AUDIO_IN_DEVICE_ANALOG_MIC;
    
    if (BSP_AUDIO_IN_Init(0, &IN_CONFIG) != BSP_ERROR_NONE) {
        return BSP_ERROR_PERIPH_FAILURE;
    }

    constexpr uint32_t buffer_size_bytes = Audio::TOTAL_SAMPLES * sizeof(int16_t);
    BSP_AUDIO_IN_Record(0, reinterpret_cast<uint8_t*>(audio_buffer.data()), buffer_size_bytes);
    const uint32_t ret = BSP_AUDIO_OUT_Play(0, reinterpret_cast<uint8_t*>(audio_buffer.data()), buffer_size_bytes);
    
    BSP_AUDIO_OUT_SetVolume(0, Audio::INITIAL_OUT_VOLUME);
    return ret;
}

// ============================================================================
// System Clock Configuration
// ============================================================================

void stm32_system_clock_config() {
    RCC_ClkInitTypeDef RCC_ClkInitStruct;
    RCC_OscInitTypeDef RCC_OscInitStruct;

    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
    while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY));

    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
    RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = 5;
    RCC_OscInitStruct.PLL.PLLN = 160;
    RCC_OscInitStruct.PLL.PLLFRACN = 0;
    RCC_OscInitStruct.PLL.PLLP = 2;
    RCC_OscInitStruct.PLL.PLLR = 2;
    RCC_OscInitStruct.PLL.PLLQ = 4;
    RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
    RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
    HAL_RCC_OscConfig(&RCC_OscInitStruct);

    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
    RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

    __HAL_RCC_CSI_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    HAL_EnableCompensationCell();
}

// ============================================================================
// MPU Configuration
// ============================================================================

void stm32_mpu_config() {
    HAL_MPU_Disable();

    // Configure Region 0: Disable access to all memory by default
    MPU_Region_InitTypeDef mpu_init = {};
    mpu_init.Enable = MPU_REGION_ENABLE;
    mpu_init.BaseAddress = 0x00;
    mpu_init.Size = MPU_REGION_SIZE_4GB;
    mpu_init.AccessPermission = MPU_REGION_NO_ACCESS;
    mpu_init.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
    mpu_init.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
    mpu_init.IsShareable = MPU_ACCESS_SHAREABLE;
    mpu_init.Number = MPU_REGION_NUMBER0;
    mpu_init.TypeExtField = MPU_TEX_LEVEL0;
    mpu_init.SubRegionDisable = 0x87;
    mpu_init.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
    HAL_MPU_ConfigRegion(&mpu_init);

    // Configure Region 1: SDRAM
    mpu_init.BaseAddress = SDRAM_DEVICE_ADDR;
    mpu_init.Size = MPU_REGION_SIZE_32MB;
    mpu_init.AccessPermission = MPU_REGION_FULL_ACCESS;
    mpu_init.Number = MPU_REGION_NUMBER1;
    mpu_init.IsCacheable = MPU_ACCESS_CACHEABLE;
    mpu_init.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
    mpu_init.SubRegionDisable = 0x00;
    mpu_init.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
    HAL_MPU_ConfigRegion(&mpu_init);

    // Configure Region 2: External memory
    mpu_init.BaseAddress = 0x90000000;
    mpu_init.Size = MPU_REGION_SIZE_128MB;
    mpu_init.Number = MPU_REGION_NUMBER2;
    mpu_init.IsCacheable = MPU_ACCESS_CACHEABLE;
    mpu_init.SubRegionDisable = 0x0;
    HAL_MPU_ConfigRegion(&mpu_init);

    HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

// ============================================================================
// CPU Cache Enable
// ============================================================================

void stm32_cpu_cache_enable() {
    SCB_EnableICache();
    SCB_EnableDCache();
}

// ============================================================================
// Dual Core Boot Synchronization
// ============================================================================

#if defined(DUAL_CORE_BOOT_SYNC_SEQUENCE)
constexpr int32_t BOOT_TIMEOUT = 0xFFFF;

void stm32_wait_for_dual_core_ready(uint32_t flag) {
    int32_t timeout = BOOT_TIMEOUT;
    while ((__HAL_RCC_GET_FLAG(flag) == RESET) && (timeout-- > 0));
    if (timeout < 0) Error_Handler();
}

void stm32_sync_dual_core_boot() {
    stm32_wait_for_dual_core_ready(RCC_FLAG_D2CKRDY);
    __HAL_RCC_HSEM_CLK_ENABLE();
    HAL_HSEM_FastTake(HSEM_ID_0);
    HAL_HSEM_Release(HSEM_ID_0, 0);
    stm32_wait_for_dual_core_ready(RCC_FLAG_D2CKRDY);
}
#endif
