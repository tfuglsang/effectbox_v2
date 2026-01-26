## **8 STM32H747I-DISCO I/O assignment**

**Table 22. STM32H747I-DISCO I/O assignment** 

| Pin | GPIO port | GPIO primary interface      |
|-----|-----------|-----------------------------|
| A1  | VSS       | -                           |
| A10 | PG9       | QSPI_BK2_IO2                |
| A11 | PD5       | PMOD#2- USART2_TX           |
| A12 | PD4       | PMOD#4- USART2_RTS          |
| A13 | PC10      | SDIO1_D2                    |
| A14 | PA15      | JTDI                        |
| A15 | PI1       | FMC_D25                     |
| A16 | PI0       | FMC_D24                     |
| A17 | VSS       | -                           |
| A2  | PI6       | FMC_D28                     |
| A3  | PI5       | FMC_NBL3                    |
| A4  | PI4       | FMC_NBL2                    |
| A5  | PB5       | ULPI_D7                     |
| A6  | VDDLDO    | -                           |
| A7  | VCAP      | -                           |
| A8  | PK5       | JOY_RIGHT                   |
| A9  | PG10      | DCMI_D2                     |
| B1  | VBAT      | -                           |
| B10 | PJ15      | Audio_INT                   |
| B11 | PD6       | PMOD#3- USART2_RX           |
| B12 | PD3       | PMOD#18_DFSDM_CKOUT/DCMI_D5 |
| B13 | PC11      | SDIO1_D3    DCMI_D4         |
| B14 | PA14      | JTCK-SWCLK                  |
| B15 | PI2       | FMC_D26                     |
| B16 | PH15      | FMC_D23                     |
| B17 | PH14      | FMC_D22                     |
| B2  | VSS       | -                           |
| B3  | PI7       | FMC_D29                     |
| B4  | PE1       | FMC_NBL1                    |
| B5  | PB6       | HDMI_CEC                    |
| B6  | VSS       | -                           |
| B7  | PB4       | NJTRST                      |

36/56 UM2411 Rev 7

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port      | GPIO primary interface         |
|-----|----------------|--------------------------------|
| B8  | PK4            | JOY_LEFT                       |
| B9  | PG11           | ETH_/TX_EN/TX_EN               |
| C1  | PC15-OSC32_OUT | OSC32_OUT                      |
| C10 | VSS            | -                              |
| C11 | PD7            | SPDIF_RX0                      |
| C12 | PC12           | SDIO1_CK                       |
| C13 | VSS            | -                              |
| C14 | PI3            | FMC_D27                        |
| C15 | PA13           | JTMS-SWDIO                     |
| C16 | VSS            | -                              |
| C17 | VDDLDO         | -                              |
| C2  | PC14-OSC32_IN  | OSC32_IN                       |
| C3  | PE2            | ETH_nINT    SAI4_CK1           |
| C4  | PE0            | FMC_NBL0                       |
| C5  | PB7            | DCMI_VSYNC                     |
| C6  | PB3            | JTDO/TRACESWO                  |
| C7  | PK6            | JOY_UP                         |
| C8  | PK3            | JOY_DOWN                       |
| C9  | PG12           | ETH_/TXD1/TXD1                 |
| D1  | PE5            | SAI1_SCK_A                     |
| D10 | PJ14           | DCMI_PWR_EN                    |
| D11 | PJ12           | BL_CTRL                        |
| D12 | PD2            | SDIO1_CMD                      |
| D13 | PD0            | FMC_D2                         |
| D14 | PA10           | VCP-USART1_RX                  |
| D15 | PA9            | VCP-USART1_TX                  |
| D16 | PH13           | FMC_D21                        |
| D17 | VCAP           | -                              |
| D2  | PE4            | SAI1_FS_A                      |
| D3  | PE3            | SAI1_SD_B                      |
| D4  | PB9            | PMOD#19_DFSDM-DATA7    DCMI_D7 |
| D5  | PB8            | PMOD#20_DFSDM-CK7    DCMI_D6   |
| D6  | PG15           | FMC_SDNCAS                     |
| D7  | PK7            | TOUCH_INT                      |
| D8  | PG14           | QSPI_BK2_IO3                   |

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port | GPIO primary interface      |
|-----|-----------|-----------------------------|
| D9  | PG13      | ETH_/TXD0/TXD0              |
| E1  | VLXSMPS   | -                           |
| E10 | PJ13      | PMOD#12_GPIO                |
| E11 | VDD       | -                           |
| E12 | PD1       | FMC_D3                      |
| E13 | PC8       | SDIO1_D0                    |
| E14 | PC9       | SDIO1_D1    DCMI_D3         |
| E15 | PA8       | CEC_CK    MCO1              |
| E16 | PA12      | PMOD#4-SPI2_SCK/2_CK        |
| E17 | PA11      | PMOD#1-SPI2_NSS/2_WS        |
| E2  | PI9       | FMC_D30                     |
| E3  | PC13      | TAMP_1/WKUP2                |
| E4  | PI8       | uSD_Detect                  |
| E5  | PE6       | SAI1_SD_A                   |
| E6  | VDD       | -                           |
| E7  | PDR_ON    | -                           |
| E8  | BOOT0     | -                           |
| E9  | VDD       | -                           |
| F1  | VDDSMPS   | -                           |
| F13 | PC7       | PMOD#17_DFSDM_DATA3/DCMI_D1 |
| F14 | PC6       | PMOD#11_INT/DCMI_D0         |
| F15 | PG8       | FMC_SDCLK                   |
| F16 | PG7       | SAI1_MCLK_A                 |
| F17 | VDD33USB  | -                           |
| F2  | VSSSMPS   | -                           |
| F3  | PI10      | FMC_D31                     |
| F4  | PI11      | ULPI_DIR                    |
| F5  | VDD       | -                           |
| G1  | PF2       | FMC_A2                      |
| G10 | VSS       | -                           |
| G11 | VSS       | -                           |
| G13 | VDD       | -                           |
| G14 | PG5       | FMC_BA1                     |
| G15 | PG6       | QSPI_BK1_NCS                |
| G16 | VSS       | -                           |

![](_page_2_Picture_4.jpeg)

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port     | GPIO primary interface       |
|-----|---------------|------------------------------|
| G17 | VDD50USB      | -                            |
| G2  | VFBSMPS       | -                            |
| G3  | PF1           | FMC_A1                       |
| G4  | PF0           | FMC_A0                       |
| G5  | VDD           | -                            |
| G7  | VSS           | -                            |
| G8  | VSS           | -                            |
| G9  | VSS           | -                            |
| H1  | PI12          | LED1                         |
| H10 | VSS           | -                            |
| H11 | VSS           | -                            |
| H13 | VDD           | -                            |
| H14 | PG4           | FMC_BA0                      |
| H15 | PG3           | DSI_Reset                    |
| H16 | PG2           | FMC_A12                      |
| H17 | PK2           | JOY_SEL                      |
| H2  | PI13          | LED2                         |
| H3  | PI14          | LED3                         |
| H4  | PF3           | FMC_A3                       |
| H5  | VDD           | -                            |
| H7  | VSS           | -                            |
| H8  | VSS           | -                            |
| H9  | VSS           | -                            |
| J1  | PH1 - OSC_OUT | OSC_OUT                      |
| J10 | VSS           | -                            |
| J11 | VSS           | -                            |
| J13 | VDD           | -                            |
| J14 | PK0           | ARD_D13-SPI5_SCK             |
| J15 | PK1           | ARD_D10-SPI5_NSS    TIM1_CH1 |
| J16 | VSS           | -                            |
| J17 | VSS           | -                            |
| J2  | PH0 - OSC_IN  | OSC_IN                       |
| J3  | VSS           | -                            |
| J4  | PF5           | FMC_A5                       |
| J5  | PF4           | FMC_A4                       |

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port | GPIO primary interface          |
|-----|-----------|---------------------------------|
| J7  | VSS       | -                               |
| J8  | VSS       | -                               |
| J9  | VSS       | -                               |
| K1  | NRST      | NRST                            |
| K10 | VSS       | -                               |
| K11 | VSS       | -                               |
| K13 | VDD       | -                               |
| K14 | PJ11      | ARD_D12-SPI5_MISO               |
| K15 | VSSDSI    | -                               |
| K16 | DSI_D1P   | -                               |
| K17 | DSI_D1N   | -                               |
| K2  | PF6       | QSPI_BK1_IO3                    |
| K3  | PF7       | QSPI_BK1_IO2                    |
| K4  | PF8       | PMOD#14_PWM    ARD_D3-TIM13_CH1 |
| K5  | VDD       | -                               |
| K7  | VSS       | -                               |
| K8  | VSS       | -                               |
| K9  | VSS       | -                               |
| L1  | VDDA      | -                               |
| L10 | VSS       | -                               |
| L11 | VSS       | -                               |
| L13 | VDD       | -                               |
| L14 | PJ10      | ARD_D11-SPI5_MOSI    TIM1_CH2N  |
| L15 | VSSDSI    | -                               |
| L16 | DSI_CKP   | -                               |
| L17 | DSI_CKN   | -                               |
| L2  | PC0       | ULPI_STP                        |
| L3  | PF10      | ARD_A1                          |
| L4  | PF9       | QSPI_BK1_IO1                    |
| L5  | VDD       | -                               |
| L7  | VSS       | -                               |
| L8  | VSS       | -                               |
| L9  | VSS       | -                               |
| M1  | VREF+     | -                               |
| M13 | VDD       | -                               |

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port | GPIO primary interface  |
|-----|-----------|-------------------------|
| M14 | PJ9       | ARD_D0-UART8_RX         |
| M15 | VSSDSI    | -                       |
| M16 | DSI_D0P   | -                       |
| M17 | DSI_D0N   | -                       |
| M2  | PC1       | ETH_MDC    SAI4_D1      |
| M3  | PC2       | PMOD#3-SPI2_MISO/2_SDI  |
| M4  | PC3       | PMOD#2-SPI2_MOSI/2_SDO  |
| M5  | VDD       | -                       |
| N1  | VREF-     | -                       |
| N10 | VDD       | -                       |
| N11 | VDD       | -                       |
| N12 | VDD       | -                       |
| N13 | PJ8       | ARD_D1-UART8_TX         |
| N14 | PJ7       | ARD_D6-TIM8_CH2N        |
| N15 | PJ6       | ARD_D9-TIM8_CH2         |
| N16 | VSS       | -                       |
| N17 | VCAPDSI   | -                       |
| N2  | PH2       | QSPI_BK2_IO0            |
| N3  | PA2       | ETH_MDIO                |
| N4  | PA1       | ETH_/RX_CLK/REF_CLK/CLK |
| N5  | PA0       | PMOD#1- USART2_CTS_NSS  |
| N6  | PJ0       | ARD_D7                  |
| N7  | VDD       | -                       |
| N8  | VDD       | -                       |
| N9  | PE10      | FMC_D7                  |
| P1  | VSSA      | -                       |
| P10 | PE11      | FMC_D8                  |
| P11 | PB10      | ULPI_D3                 |
| P12 | PB11      | ULPI_D4                 |
| P13 | PH10      | FMC_D18                 |
| P14 | PH11      | FMC_D19                 |
| P15 | PD15      | FMC_D1                  |
| P16 | PD14      | FMC_D0                  |
| P17 | VDDDSI    | -                       |
| P2  | PH3       | QSPI_BK2_IO1            |

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port | GPIO primary interface         |
|-----|-----------|--------------------------------|
| P3  | PH4       | ULPI_NXT                       |
| P4  | PH5       | FMC_SDNWE                      |
| P5  | PI15      | LED4                           |
| P6  | PJ1       | OTG_HS_OverCurrent             |
| P7  | PF13      | FMC_A7                         |
| P8  | PF14      | FMC_A8                         |
| P9  | PE9       | FMC_D6                         |
| R1  | PC2_C     | ARD_A4                         |
| R10 | PE12      | FMC_D9                         |
| R11 | PE15      | FMC_D12                        |
| R12 | PJ5       | ARD_D8                         |
| R13 | PH9       | FMC_D17                        |
| R14 | PH12      | FMC_D20                        |
| R15 | PD11      | QSPI_BK1_IO0                   |
| R16 | PD12      | PMOD#7/ARD_D15-I2C4_SCL        |
| R17 | PD13      | PMOD#10/ARD_D14-I2C4_SDA       |
| R2  | PC3_C     | ARD_A5                         |
| R3  | PA6       | ARD_D5-TIM3_CH1    DCMI_PIXCLK |
| R4  | VSS       | -                              |
| R5  | PA7       | ETH_/RX_DV/CRS_DV/SYNC         |
| R6  | PB2       | QSPI_CLK                       |
| R7  | PF12      | FMC_A6                         |
| R8  | VSS       | -                              |
| R9  | PF15      | FMC_A9                         |
| T1  | PA0_C     | ARD_A2                         |
| T10 | PE13      | FMC_D10                        |
| T11 | PH6       | FMC_SDNE1                      |
| T12 | VSS       | -                              |
| T13 | PH8       | FMC_D16                        |
| T14 | PB12      | ULPI_D5                        |
| T15 | PB15      | PMOD#8-SPI2_MOSI/2_SDO         |
| T16 | PD10      | FMC_D15                        |
| T17 | PD9       | FMC_D14                        |
| T2  | PA1_C     | ARD_A3                         |
| T3  | PA5       | ULPI_CK                        |

42/56 UM2411 Rev 7

**Table 22. STM32H747I-DISCO I/O assignment (continued)**

| Pin | GPIO port | GPIO primary interface                 |
|-----|-----------|----------------------------------------|
| T4  | PC4       | ETH_/RXD0/RXD0/RXD                     |
| T5  | PB1       | ULPI_D2                                |
| T6  | PJ2       | DSI_TE                                 |
| T7  | PF11      | FMC_SDNRAS                             |
| T8  | PG0       | FMC_A10                                |
| T9  | PE8       | FMC_D5                                 |
| U1  | VSS       | -                                      |
| U10 | PE14      | FMC_D11                                |
| U11 | VCAP1     | -                                      |
| U12 | VDDLDO    | -                                      |
| U13 | PH7       | FMC_SDCKE1                             |
| U14 | PB13      | ULPI_D6                                |
| U15 | PB14      | PMOD#9-SPI2_MISO/2_SDI                 |
| U16 | PD8       | FMC_D13                                |
| U17 | VSS       | -                                      |
| U2  | PA3       | ULPI_D0                                |
| U3  | PA4       | PMOD#13_ADC    ARD_A0   <br>DCMI_HSYNC |
| U4  | PC5       | ETH_/RXD1/RXD1                         |
| U5  | PB0       | ULPI_D1                                |
| U6  | PJ3       | ARD_D2                                 |
| U7  | PJ4       | ARD_D4                                 |
| U8  | PG1       | FMC_A11                                |
| U9  | PE7       | FMC_D4                                 |