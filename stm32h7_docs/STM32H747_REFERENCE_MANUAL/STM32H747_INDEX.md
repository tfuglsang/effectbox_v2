# STM32H747 Reference Manual Index

**Document**: RM0399 - STM32H745/747/755/757 Reference Manual
**Purpose**: This index helps LLMs locate relevant documentation sections without loading the entire manual into context.

---

## How to Use This Index

1. Read this index file to identify which section(s) contain information about your topic
2. Load only the relevant markdown file(s) from the `STM32H747_REFERENCE_MANUAL` folder
3. Each section is in its own subfolder with a `.md` file containing the full content

---

## Chapter Summaries by Category

### Document Information

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `01_1 Documentation conventions/` | 1 | Document conventions, terminology, register access types | conventions, terminology |
| `66_66 Revision history/` | 66 | Document revision history | revision history |
| `65_65 Important security notice/` | 65 | Security notice | security |
| `64_64 Device electronic signature/` | 64 | Unique device ID, flash size register | device ID, UID, flash size |

---

### Memory & Bus Architecture

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `02_2 Memory and bus architecture/` | 2 | **Memory map, bus matrix, system architecture**, AXI/AHB buses, D1/D2/D3 domains, boot configuration | memory map, bus matrix, AXI, AHB, domains, boot |
| `03_3 RAM ECC monitoring (RAMECC)/` | 3 | RAM ECC error detection and correction | ECC, RAM, error correction |
| `04_4 Embedded flash memory (FLASH)/` | 4 | **Flash organization, programming, protection, options bytes** | flash, program, erase, option bytes, write protection |
| `05_5 Secure memory management (SMM)/` | 5 | Secure access mode, firewall | secure memory, firewall, SMM |
| `06_6 ART accelerator/` | 6 | Adaptive real-time memory accelerator for flash | ART, accelerator, flash cache |

---

### Power & Clock Management

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `07_7 Power control (PWR)/` | 7 | **Power domains (D1/D2/D3), voltage scaling, low-power modes (Sleep, Stop, Standby)**, SMPS, LDO, wakeup | power, PWR, low power, sleep, stop, standby, SMPS, LDO, voltage scaling |
| `08_8 Low-power D3 domain application example/` | 8 | Example application for D3 domain low-power operation | low power, D3, application example |
| `09_9 Reset and Clock Control (RCC)/` | 9 | **Clock tree, PLLs (PLL1/2/3), HSE, HSI, LSE, LSI, clock sources, prescalers, peripheral clocks** | RCC, clock, PLL, HSE, HSI, LSE, LSI, prescaler, clock tree |
| `10_10 Clock recovery system (CRS)/` | 10 | Automatic HSI48 trimming using USB SOF or external signal | CRS, clock recovery, HSI48, USB sync |

---

### System & Interrupts

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `11_11 Hardware semaphore (HSEM)/` | 11 | **Inter-processor synchronization for dual-core (CM7/CM4)**, semaphore registers | HSEM, semaphore, dual-core, CM7, CM4, synchronization |
| `12_12 General-purpose IOs (GPIO)/` | 12 | **GPIO configuration, alternate functions, speed, pull-up/down** | GPIO, pins, alternate function, MODER, OSPEEDR, PUPDR |
| `13_13 System configuration controller (SYSCFG)/` | 13 | I/O compensation, boot configuration, memory remap | SYSCFG, I/O compensation, memory remap, boot |
| `14_14 Block interconnect/` | 14 | Pin multiplexing, alternate function mapping tables | alternate functions, pin mapping, AF tables |
| `20_20 Nested vectored interrupt controllers (NVIC1 and NVIC2)/` | 20 | **Dual-core NVIC configuration, interrupt vectors for CM7 and CM4** | NVIC, interrupts, vectors, CM7, CM4 |
| `21_21 Extended interrupt and event controller (EXTI)/` | 21 | **External interrupts, event generation, wakeup lines** | EXTI, external interrupt, wakeup, event |

---

### DMA Controllers

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `15_15 MDMA controller (MDMA)/` | 15 | **Master DMA for memory-to-memory and linked list transfers** | MDMA, master DMA, linked list |
| `16_16 Direct memory access controller (DMA)/` | 16 | **DMA1/DMA2 for peripheral transfers**, streams, FIFO, circular mode | DMA, DMA1, DMA2, streams, FIFO, circular |
| `17_17 Basic direct memory access controller (BDMA)/` | 17 | Basic DMA for D3 domain peripherals | BDMA, D3 domain |
| `18_18 DMA request multiplexer (DMAMUX)/` | 18 | **DMA request routing, synchronization, request generators** | DMAMUX, DMA requests, routing |
| `19_19 Chrom-ART Accelerator controller (DMA2D)/` | 19 | **2D graphics DMA for image blending, color conversion, fill** | DMA2D, Chrom-ART, graphics, blending, fill |

---

### Analog Peripherals

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `26_26 Analog-to-digital converters (ADC)/` | 26 | **ADC1/ADC2/ADC3 (16-bit), channels, sampling, DMA, injected/regular groups** | ADC, analog, sampling, conversion, channels |
| `27_27 Digital-to-analog converter (DAC)/` | 27 | **DAC1/DAC2 (12-bit), DMA, triggers, waveform generation** | DAC, analog output, waveform |
| `28_28 Voltage reference buffer (VREFBUF)/` | 28 | Internal voltage reference for ADC/DAC | VREFBUF, voltage reference |
| `29_29 Comparator (COMP)/` | 29 | **COMP1/COMP2 analog comparators** | COMP, comparator, analog |
| `30_30 Operational amplifiers (OPAMP)/` | 30 | **OPAMP1/OPAMP2 internal op-amps**, PGA mode, follower | OPAMP, op-amp, PGA, amplifier |
| `31_31 Digital filter for sigma delta modulators (DFSDM)/` | 31 | **DFSDM for external sigma-delta ADCs, digital microphones** | DFSDM, sigma-delta, digital microphone, filter |

---

### Display & Camera

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `32_32 Digital camera interface (DCMI)/` | 32 | **Parallel camera interface, JPEG capture** | DCMI, camera, image capture |
| `33_33 LCD-TFT display controller (LTDC)/` | 33 | **LCD controller, layers, blending, color keying** | LTDC, LCD, display, TFT, layers |
| `34_34 DSI Host (DSI)/` | 34 | **MIPI DSI display interface**, video/command modes | DSI, MIPI, display |
| `35_35 JPEG codec (JPEG)/` | 35 | **Hardware JPEG encoder/decoder** | JPEG, codec, image compression |

---

### Security & Cryptography

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `36_36 True random number generator (RNG)/` | 36 | **Hardware random number generator** | RNG, random, TRNG |
| `37_37 Cryptographic processor (CRYP)/` | 37 | **AES, DES, 3DES hardware encryption/decryption** | CRYP, AES, DES, encryption, cryptography |
| `38_38 Hash processor (HASH)/` | 38 | **SHA-1, SHA-224, SHA-256, MD5 hardware hash** | HASH, SHA, MD5, digest |

---

### Timers

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `39_39 High-resolution timer (HRTIM)/` | 39 | **High-resolution timer for power conversion, motor control** (184ps resolution) | HRTIM, high-resolution, PWM, motor control |
| `40_40 Advanced-control timers (TIM1TIM8)/` | 40 | **TIM1/TIM8 advanced timers**, complementary PWM, dead-time, break | TIM1, TIM8, advanced timer, PWM, dead-time, motor |
| `41_41 General-purpose timers (TIM2TIM3TIM4TIM5)/` | 41 | **TIM2-5 32/16-bit general purpose timers**, encoder interface | TIM2, TIM3, TIM4, TIM5, encoder, general purpose |
| `42_42 General-purpose timers (TIM12TIM13TIM14)/` | 42 | TIM12-14 general purpose timers | TIM12, TIM13, TIM14 |
| `43_43 General-purpose timers (TIM15TIM16TIM17)/` | 43 | TIM15-17 general purpose timers with break | TIM15, TIM16, TIM17 |
| `44_44 Basic timers (TIM6TIM7)/` | 44 | **TIM6/TIM7 basic timers**, DAC triggers | TIM6, TIM7, basic timer, DAC trigger |
| `45_45 Low-power timer (LPTIM)/` | 45 | **LPTIM1-5 low-power timers**, running in Stop mode | LPTIM, low-power timer, Stop mode |

---

### Watchdogs

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `46_46 Watchdog overview/` | 46 | Overview of watchdog timers | watchdog overview |
| `47_47 System window watchdog (WWDG)/` | 47 | **Window watchdog with early wakeup interrupt** | WWDG, window watchdog |
| `48_48 Independent watchdog (IWDG)/` | 48 | **Independent watchdog (LSI-based)** | IWDG, independent watchdog |

---

### Real-Time Clock

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `49_49 Real-time clock (RTC)/` | 49 | **RTC with calendar, alarms, wakeup timer, timestamp, tamper detection** | RTC, calendar, alarm, wakeup, timestamp, tamper |

---

### Communication Interfaces

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `50_50 Inter-integrated circuit (I2C) interface/` | 50 | **I2C1-4 master/slave, SMBus, PMBus**, 100kHz/400kHz/1MHz | I2C, SMBus, PMBus |
| `51_51 Universal synchronousasynchronous receiver transmitter (USARTUART)/` | 51 | **USART1-6, UART4/5/7/8**, RS-232, RS-485, LIN, IrDA, smartcard | USART, UART, RS-232, RS-485, serial |
| `52_52 Low-power universal asynchronous receiver transmitter (LPUART)/` | 52 | **LPUART1** for low-power operation in Stop mode | LPUART, low-power UART |
| `53_53 Serial peripheral interface (SPI)/` | 53 | **SPI1-6 master/slave**, I2S mode, full/half duplex | SPI, I2S, serial |
| `54_54 Serial audio interface (SAI)/` | 54 | **SAI1-4** for I2S, TDM, SPDIF audio | SAI, audio, I2S, TDM |
| `55_55 SPDIF receiver interface (SPDIFRX)/` | 55 | **S/PDIF audio receiver** | SPDIFRX, SPDIF, audio |
| `56_56 Single wire protocol master interface (SWPMI)/` | 56 | Single-wire protocol for SIM cards | SWPMI, single wire |
| `57_57 Management data inputoutput (MDIOS)/` | 57 | MDIO slave for Ethernet PHY management | MDIOS, MDIO, Ethernet management |

---

### External Memory & Storage

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `22_22 Cyclic redundancy check calculation unit (CRC)/` | 22 | **Hardware CRC calculation** (CRC-32, programmable polynomial) | CRC, checksum |
| `23_23 Flexible memory controller (FMC)/` | 23 | **External SRAM, SDRAM, NOR/NAND flash, PSRAM interface** | FMC, SDRAM, SRAM, NOR, NAND, external memory |
| `24_24 Quad-SPI interface (QUADSPI)/` | 24 | **Quad-SPI flash interface**, memory-mapped mode | QUADSPI, QSPI, flash, memory-mapped |
| `25_25 Delay block (DLYB)/` | 25 | Programmable delay for SDMMC/QUADSPI timing | DLYB, delay, timing |
| `58_58 Secure digital inputoutput MultiMediaCard interface (SDMMC)/` | 58 | **SDMMC1/2 for SD cards, eMMC** | SDMMC, SD card, eMMC, MMC |

---

### Connectivity

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `59_59 Controller area network with flexible data rate (FDCAN)/` | 59 | **FDCAN1/2 CAN FD controller** with message RAM | FDCAN, CAN, CAN FD, automotive |
| `60_60 USB on-the-go high-speed (OTG_HS)/` | 60 | **USB OTG HS with integrated PHY**, device/host/OTG modes | USB, OTG, high-speed, USB HS |
| `61_61 Ethernet (ETH) media access control (MAC) with DMA controller/` | 61 | **10/100 Mbps Ethernet MAC**, MII/RMII, IEEE 1588 PTP | Ethernet, ETH, MAC, MII, RMII, PTP |
| `62_62 HDMI-CEC controller (CEC)/` | 62 | **HDMI-CEC** consumer electronics control | CEC, HDMI |

---

### Debug

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `63_63 Debug infrastructure/` | 63 | **SWD, JTAG, ITM, ETM, debug registers**, CoreSight | debug, SWD, JTAG, ITM, ETM, CoreSight |

---

## Quick Reference: Common Topics

### Dual-Core Operation
- **Inter-core synchronization**: `11_11 Hardware semaphore (HSEM)/`
- **Dual NVIC**: `20_20 Nested vectored interrupt controllers (NVIC1 and NVIC2)/`
- **Memory domains (D1/D2/D3)**: `02_2 Memory and bus architecture/`
- **Power domains**: `07_7 Power control (PWR)/`

### Clock Configuration
- **Main clock tree**: `09_9 Reset and Clock Control (RCC)/`
- **PLLs (PLL1/2/3)**: `09_9 Reset and Clock Control (RCC)/`
- **USB clock sync**: `10_10 Clock recovery system (CRS)/`

### DMA Operations
- **Standard DMA**: `16_16 Direct memory access controller (DMA)/`
- **Master DMA (linked list)**: `15_15 MDMA controller (MDMA)/`
- **D3 domain DMA**: `17_17 Basic direct memory access controller (BDMA)/`
- **Request routing**: `18_18 DMA request multiplexer (DMAMUX)/`
- **Graphics DMA**: `19_19 Chrom-ART Accelerator controller (DMA2D)/`

### Analog
- **ADC**: `26_26 Analog-to-digital converters (ADC)/`
- **DAC**: `27_27 Digital-to-analog converter (DAC)/`
- **Comparators**: `29_29 Comparator (COMP)/`
- **Op-amps**: `30_30 Operational amplifiers (OPAMP)/`

### Communication Protocols
- **SPI**: `53_53 Serial peripheral interface (SPI)/`
- **I2C**: `50_50 Inter-integrated circuit (I2C) interface/`
- **UART/USART**: `51_51 Universal synchronousasynchronous receiver transmitter (USARTUART)/`
- **CAN FD**: `59_59 Controller area network with flexible data rate (FDCAN)/`
- **Ethernet**: `61_61 Ethernet (ETH) media access control (MAC) with DMA controller/`
- **USB**: `60_60 USB on-the-go high-speed (OTG_HS)/`

### Display
- **LCD/TFT**: `33_33 LCD-TFT display controller (LTDC)/`
- **MIPI DSI**: `34_34 DSI Host (DSI)/`
- **Graphics acceleration**: `19_19 Chrom-ART Accelerator controller (DMA2D)/`

### Timers
- **Advanced (PWM)**: `40_40 Advanced-control timers (TIM1TIM8)/`
- **General purpose**: `41_41 General-purpose timers (TIM2TIM3TIM4TIM5)/`
- **High-resolution**: `39_39 High-resolution timer (HRTIM)/`
- **Low-power**: `45_45 Low-power timer (LPTIM)/`

### Low Power
- **Power modes**: `07_7 Power control (PWR)/`
- **D3 domain example**: `08_8 Low-power D3 domain application example/`
- **LPTIM**: `45_45 Low-power timer (LPTIM)/`
- **LPUART**: `52_52 Low-power universal asynchronous receiver transmitter (LPUART)/`

### Security
- **Encryption (AES/DES)**: `37_37 Cryptographic processor (CRYP)/`
- **Hash (SHA/MD5)**: `38_38 Hash processor (HASH)/`
- **Random numbers**: `36_36 True random number generator (RNG)/`

---

## Memory Map Quick Reference

| Region | Address Range | Description |
|--------|---------------|-------------|
| ITCM RAM | 0x00000000 - 0x0000FFFF | 64KB Instruction TCM |
| DTCM RAM | 0x20000000 - 0x2001FFFF | 128KB Data TCM |
| AXI SRAM | 0x24000000 - 0x2407FFFF | 512KB AXI SRAM (D1) |
| SRAM1 | 0x30000000 - 0x3001FFFF | 128KB SRAM (D2) |
| SRAM2 | 0x30020000 - 0x3003FFFF | 128KB SRAM (D2) |
| SRAM3 | 0x30040000 - 0x30047FFF | 32KB SRAM (D2) |
| SRAM4 | 0x38000000 - 0x3800FFFF | 64KB SRAM (D3) |
| Backup SRAM | 0x38800000 - 0x38800FFF | 4KB Backup SRAM |
| Flash Bank 1 | 0x08000000 - 0x080FFFFF | 1MB Flash |
| Flash Bank 2 | 0x08100000 - 0x081FFFFF | 1MB Flash |
| Peripherals | 0x40000000 - 0x5FFFFFFF | APB/AHB peripherals |
| FMC/QSPI | 0x60000000 - 0x9FFFFFFF | External memory |
| Cortex-M7 PPB | 0xE0000000 - 0xE00FFFFF | Private peripheral bus |

---

*Generated from STM32H745/747/755/757 Reference Manual RM0399*
