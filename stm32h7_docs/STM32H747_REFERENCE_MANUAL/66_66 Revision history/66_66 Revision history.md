## **66 Revision history**

**Table 657. Document revision history** 

| Date        | Revision | Changes                                                                                                                                                                                                  |
|-------------|----------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 05-Jul-2018 | 1        | Initial release.                                                                                                                                                                                         |
|             |          | Added case of reset during half word write in Section : Error code correction (ECC).                                                                                                                     |
|             |          | Section 4: Embedded Flash memory (FLASH)                                                                                                                                                                 |
|             |          | Updated Figure 8: Embedded Flash memory usage.<br>Section : Adjusting programming timing constraints: added note related to                                                                              |
|             |          | WRHIGHFREQ modification during Flash memory programming/erasing.<br>Section : Adjusting programming parallelism: added note related to PSIZE1/2<br>modification during Flash memory programming/erasing. |
|             |          | Secure DTCM size (ST_RAM_SIZE):<br>Removed Secure DTCM size (ST_RAM_SIZE) from Section : Changing security<br>option bytes.                                                                              |
|             |          | Updated ST_RAM_SIZE description and added ST_RAM_SIZE to the values<br>programmed in the data protection option bytes in Section 4.4.6: Description of data<br>protection option bytes.                  |
|             | 2        | Section : Definitions of RDP global protection level: updated description of RDP<br>level 1 to 0 regression and RDP level 2.                                                                             |
| 04-Apr-2019 |          | Section : RDP protection transitions: user Flash memory can be partially or mass<br>erased when doing a level regression from RDP level 1 to 0.                                                          |
|             |          | Section 5: Secure internal Flash memory (SIFM) (former Secure memory<br>management section)                                                                                                              |
|             |          | Removed Section Flash protections.                                                                                                                                                                       |
|             |          | Updated Section 5.3.1: Associated features and Section 5.3.2: Boot state machine.                                                                                                                        |
|             |          | Added and added Note 2. below Figure 15: Flash memory areas and services in<br>Standard and Secure access modes.                                                                                         |
|             |          | Updated Figure 16: Bootloader state machine in Secure access mode.                                                                                                                                       |
|             |          | Updated Section 5.3.3: Secure access mode configuration.                                                                                                                                                 |
|             |          | Restructured Section 5.4: Root secure services (RSS):                                                                                                                                                    |
|             |          | Added Section 5.4.1: Secure area setting service and Section 5.4.2: Secure area<br>exiting service                                                                                                       |
|             |          | Renamed RSS services (removed RSS_ prefix).                                                                                                                                                              |
|             |          | Removed RSS_resetAndDestroyPCROPArea                                                                                                                                                                     |
|             |          | Updated Section 5.5.1: Access rules and Section 5.5.2: Setting secure user<br>memory areas. Remove sections Removing secure memory areas and Selecting<br>secure user software.                          |
|             |          | Updated Figure 17: Core access to Flash memory areas                                                                                                                                                     |

![](_page_0_Picture_4.jpeg)

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |
|-------------|---------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
| 04-Apr-2019 | 2 (continued) | Section 7: Power control (PWR)<br>Renamed SD converter into SMPS step-down converter in the whole section.<br>Added case of device startup with VCORE supplied in Bypass mode in Section<br>7.4.1: System supply startup.<br>Added VOS0 in Section 7.4.2: Core domain, Section 7.4.3: PWR external supply<br>and Section 7.6.2: Voltage scaling. Added Section : VOS0 activation/deactivation<br>sequence.<br>Updated Section 7.5.5: Battery voltage thresholds.<br>Updated Section 7.5.6: Temperature thresholds to indicate that the thresholds are<br>available only when the backup regulator is enabled.<br>Added note related to VOS0 activation in Section : Entering Stop mode and Section<br>: Entering Standby mode.<br>Section 9: Reset and Clock Control (RCC)<br>Updated Section : HSE oscillator, Section : LSE oscillator and Figure 52: HSE/LSE<br>clock source.<br>Changed maximum frequency to 480 MHz in Figure 55: Core and bus clock<br>generation.<br>Updated Table 60: Kernel clock distribution overview.<br>Updated DIVP1[6:0] in Section 9.7.12: RCC PLL1 dividers configuration register<br>(RCC_PLL1DIVR).<br>Renamed BKPSRAMAMEN into BKPRAMAMEN in Section 9.7.37: RCC D3<br>Autonomous mode register (RCC_D3AMR) register.<br>Added USB2OTGHSULPIEN in Section 9.7.40: RCC AHB1 clock register<br>(RCC_AHB1ENR), and USB2OTGHSULPILPEN in Section 9.7.49: RCC AHB1<br>Sleep clock register (RCC_AHB1LPENR).<br>Renamed HDMICECRST into CECRST in Section 9.7.32: RCC APB1 peripheral<br>reset register (RCC_APB1LRSTR), and HDMICECEN to CECEN in Section 7.7.45:<br>RCC APB1 Clock Register (RCC_APB1LENR).<br>Section 9: General-purpose I/Os (GPIO)<br>Updated Figure 82: Analog inputs connected to ADC inputs to specify that the<br>analog switch status depends on PxySO reset value in SYSCFG_PMCR.<br>MODER reset state changed to analog mode in Section 9.4.1: GPIO port mode<br>register (GPIOx_MODER) (x =A to C and E, H).<br>Section 13: System configuration controller (SYSCFG)<br>Added note related to CSI clock required for setting READY bit in SYSCFG<br>configuration register (SYSCFG_CFGR).<br>Added SYSCFG power control register (SYSCFG_PWRCR).<br>Section 17: Basic direct memory access controller (BDMA) |
|             |               | Updated Section : Channel state and disabling a channel.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                |

![](_page_1_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Table 657. Document revision history (continued) |               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
|--------------------------------------------------|---------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Date                                             | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
| 04-Apr-2019                                      | 2 (continued) | Section 12: DMA request multiplexer (DMAMUX)<br>Removed references to security and privileged/unprivileged access control in<br>Section 18.6.4: DMAMUX2 request line multiplexer interrupt channel status register<br>(DMAMUX2_CSR), Section 18.6.6: DMAMUX2 request line multiplexer interrupt<br>clear flag register (DMAMUX2_CFR) and Section 18.6.8: DMAMUX2 request<br>generator channel x configuration register (DMAMUX2_RGxCR).<br>Section 19: Chrom-Art Accelerator™ controller (DMA2D)<br>Replaced DMA2D_FGPFCR by DMA2D_FGPFCCR in Section : Memory-to |
|                                                  |               | memory with PFC, blending and fixed color FG.<br>Replaced DMA2D_BGPFCR by DMA2D_BGPFCCR in Section : Memory-to<br>memory with PFC, blending and fixed color BG.<br>Updated Section 19.6.9: DMA2D foreground color register (DMA2D_FGCOLR).<br>Added Section 19.6.21: DMA2D foreground CLUT (DMA2D_FGCLUT[y]) and<br>Section 19.6.22: DMA2D background CLUT (DMA2D_BGCLUT[y]).<br>Table 145: DMA2D register map and reset values:<br>Changed APLHA[7:0] to reserved for DMA2D_FGCOLR                                                                               |
|                                                  |               | Changed APLHA[7:0] to reserved for DMA2D_BGCOLR<br>Section 23: Flexible memory controller (FMC)<br>Replaced BCH8 by Hamming in Section 23.8.6: Computation of the error correction<br>code (ECC) in NAND Flash memory.<br>Updated Figure 115: Mode D write access waveforms.                                                                                                                                                                                                                                                                                      |
|                                                  |               | Section 25: Delay block (DLYB)<br>Updated Section 25.1: Introduction to specify that the DLYB output clock can be<br>used to clock the data received by Quad-SPI interface.                                                                                                                                                                                                                                                                                                                                                                                       |
|                                                  |               | Section 26: Analog-to-digital converters (ADC)<br>Renamed OVSR into OVR, OSR into OSVR[9:0] and AUTODLY into AUTDLY.<br>Added Section 26.3: ADC implementation.                                                                                                                                                                                                                                                                                                                                                                                                   |
|                                                  |               | For all ADC internal channels connected to VBAT, VSENSE, VREFINT, and DAC<br>internal channels, changed ADC channel name from ADCx_INPy/INMy to ADCx<br>VINP[y]/VINM[y].                                                                                                                                                                                                                                                                                                                                                                                          |
|                                                  |               | Updated Table 213: Offset computation versus data resolution, Section : 16-bit and<br>8-bit signed format management: RSHIFTx,SSATE and Table 217: Analog<br>watchdog 1,2,3 comparison.                                                                                                                                                                                                                                                                                                                                                                           |
|                                                  |               | Removed reference to ALIGN bit in the note related to data alignment in Section :<br>Single ADC operating modes support when oversampling.<br>Updated Section 26.6.4: ADC configuration register (ADC_CFGR) to change                                                                                                                                                                                                                                                                                                                                             |
|                                                  |               | RES[2:0] value corresponding to 8-bit format.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
|                                                  |               | Section 30: Operational amplifiers (OPAMP)<br>Removed references to OPAMODE in Section 30.6.1: OPAMP1 control/status<br>register (OPAMP1_CSR). Changed OPAMODE bitfield to reserved in Section<br>30.6.1: OPAMP1 control/status register (OPAMP1_CSR).                                                                                                                                                                                                                                                                                                            |

![](_page_2_Picture_3.jpeg)

3516/3556 RM0399 Rev 4

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                           |
|-------------|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 35: JPEG codec (JPEG)                                                                                                                                                                                                                     |
|             |               | Table 290: JPEG codec register map and reset values:                                                                                                                                                                                              |
|             |               | JPEG_CR: added HPDIE (bit 6)                                                                                                                                                                                                                      |
|             |               | Renamed JPEG_HWCFR1/2 into JPEG_HWCFGR1/2                                                                                                                                                                                                         |
|             |               | Section 33: LCD-TFT display controller (LTDC)                                                                                                                                                                                                     |
|             |               | Section 33.4.1: LTDC global configuration parameters / Synchronous timing<br>updated.                                                                                                                                                             |
|             |               | Section 19: True random number generator (RNG)                                                                                                                                                                                                    |
|             |               | Updated Section 19.2: RNG main features.                                                                                                                                                                                                          |
|             |               | Updated Section 19.4: RNG interrupts.                                                                                                                                                                                                             |
|             |               | Updated Section 19.6: RNG entropy source validation.                                                                                                                                                                                              |
| 04-Apr-2019 |               | Updated Table 97: RNG internal input/output signals.                                                                                                                                                                                              |
|             |               | Section 37: Cryptographic processor (CRYP)                                                                                                                                                                                                        |
|             | 2 (continued) | Section 37.6.21: CRYP context swap GCM-CCM registers<br>(CRYP_CSGCMCCMxR): renamed CRYP_CSGCMCCMxR[31:0] bitfield into<br>CSGCMCCMx[31:0] and updated bitfield description.                                                                       |
|             |               | Section 37.6.22: CRYP context swap GCM registers (CRYP_CSGCMxR): renamed<br>CRYP_CSGCMx[31:0] bitfield into CSGCMx[31:0] and updated bitfield description.                                                                                        |
|             |               | Table 308: CRYP register map and reset values:                                                                                                                                                                                                    |
|             |               | Added bitfield ranges for CRYP_K0LR/RR to CRYP_K3LR/RR.                                                                                                                                                                                           |
|             |               | Updated CRYP_IV0LR/RR to CRYP_IV1LR/RR.                                                                                                                                                                                                           |
|             |               | Renamed CRYP_KxLR bitfields into Kx.                                                                                                                                                                                                              |
|             |               | Section 38: Hash processor (HASH)                                                                                                                                                                                                                 |
|             |               | Changed CSRn into CSn for all HASH_CRSx registers in Table 313: HASH1<br>register map and reset values.                                                                                                                                           |
|             |               | Section 22: Advanced-control timers (TIM1)                                                                                                                                                                                                        |
|             |               | Replaced BKEx, BKPx by BKE, BK2E, BKP, BK2P.                                                                                                                                                                                                      |
|             |               | Updated Figure 134: Advanced-control timer block diagram.                                                                                                                                                                                         |
|             |               | Updated Figure 177: Break and Break2 circuitry overview.                                                                                                                                                                                          |
|             |               | Updated Figure 164: Output stage of capture/compare channel (channel 1, idem ch.<br>2 and 3), Figure 165: Output stage of capture/compare channel (channel 4) and<br>Figure 420: Output stage of capture/compare channel (channel 5, idem ch. 6). |
|             |               | Updated TIM1_CCMR1, TIM1_CCMR2, TIM1_CCMR3, TIM1_CCR2, TIM1_CCR4.                                                                                                                                                                                 |
|             |               | Added 00010 configuration for TS[4:0] in TIMx_SMCR register.                                                                                                                                                                                      |
|             |               | Table 347: TIM8 register map and reset values: extended DMAB bitfield to 32 bits<br>for TIM8_DMAR.                                                                                                                                                |

![](_page_3_Picture_3.jpeg)

RM0399 Rev 4 3517/3556

**Table 657. Document revision history (continued)**

| Table 657. Document revision history (continued) |               |                                                                                                                                                                                                                  |
|--------------------------------------------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Date                                             | Revision      | Changes                                                                                                                                                                                                          |
|                                                  |               | Section 23: General-purpose timer (TIM2)                                                                                                                                                                         |
|                                                  |               | Updated Figure 194: General-purpose timer block diagram.                                                                                                                                                         |
|                                                  |               | Updated Section 23.3.3: Clock selection.                                                                                                                                                                         |
|                                                  |               | Removed all information related to BDTR register and MOE and OSSSI bits.                                                                                                                                         |
|                                                  |               | Section 42: General-purpose timers (TIM12/TIM13/TIM14)                                                                                                                                                           |
|                                                  |               | Updated Figure 497: General-purpose timer block diagram (TIM12).                                                                                                                                                 |
|                                                  |               | Section 24: General-purpose timers (TIM16/TIM17)                                                                                                                                                                 |
|                                                  |               | Updated Figure 523: TIM15 block diagram.                                                                                                                                                                         |
|                                                  |               | Updated Figure 256: Capture/compare channel 1 main circuit? Figure 257: Output<br>stage of capture/compare channel (channel 1) and Figure 540: Output stage of<br>capture/compare channel (channel 2 for TIM15). |
|                                                  |               | Updated Section 24.3.11: Using the break function.                                                                                                                                                               |
|                                                  |               | Removed bit COMDE for TIM16/17.                                                                                                                                                                                  |
|                                                  |               | Table 156: TIM16/TIM17 register map and reset values: changed TISEL[3:0] into<br>TI1SEL[3:0] for TIM16_TISEL and TIM17_TISEL registers.                                                                          |
|                                                  |               | Section 29: Inter-integrated circuit (I2C) interface                                                                                                                                                             |
|                                                  |               | Updated Section 29.3: I2C implementation.                                                                                                                                                                        |
| 04-Apr-2019                                      | 2 (continued) | Updated Section 29.7.2: I2C control register 2 (I2C_CR2), Section 29.7.3: I2C own<br>address 1 register (I2C_OAR1), and Section 29.7.8: I2C interrupt clear register<br>(I2C_ICR).                               |
|                                                  |               | Section 25: Low-power timer (LPTIM)                                                                                                                                                                              |
|                                                  |               | Updated Section 25.4.8: Timeout function.                                                                                                                                                                        |
|                                                  |               | Updated WAVE bit description in Section 25.7.4: LPTIM configuration register                                                                                                                                     |
|                                                  |               | (LPTIM_CFGR).                                                                                                                                                                                                    |
|                                                  |               | Section 30: Universal synchronous/asynchronous receiver transmitter                                                                                                                                              |
|                                                  |               | (USART/UART)                                                                                                                                                                                                     |
|                                                  |               | Replaced DSI_NSS by DIS_NSS in USART_CR1.                                                                                                                                                                        |
|                                                  |               | Changed USART_TDR into USART_RDR in Figure 328: Reception using DMA.<br>Updated Section 30.5.4: USART FIFOs and thresholds.                                                                                      |
|                                                  |               | Updated RTO bitfield description in Section 30.7.7: USART receiver timeout register<br>(USART_RTOR).                                                                                                             |
|                                                  |               | Section 30.7.9: USART interrupt and status register [alternate] (USART_ISR):                                                                                                                                     |
|                                                  |               | Updated ABRF, IDLE bit descriptions                                                                                                                                                                              |
|                                                  |               |                                                                                                                                                                                                                  |
|                                                  |               | For FIFO disabled only: updated RXNE and ORE bit descriptions<br>Changed NFCF to NECF in Section 30.7.11: USART interrupt flag clear register                                                                    |
|                                                  |               | (USART_ICR).                                                                                                                                                                                                     |
|                                                  |               | Table 193: USART register map and reset values:                                                                                                                                                                  |
|                                                  |               | USART_CR1: bit 12 changed to M0, bit 7 changed to TXEIE/TXFNFIE, bit 5<br>changed to RXNEIE/RXFNEIE.                                                                                                             |
|                                                  |               | USART_ISR: changed TXE bit to TXE/TXFNF and RXNE into RXNE/RXFNE                                                                                                                                                 |
|                                                  |               | Corrected USART_ISR/TCGBT reset value for FIFO disabled.                                                                                                                                                         |

![](_page_4_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Date<br>04-Apr-2019 | Revision<br>2 (continued) | Changes<br>Section 31: Low-power universal asynchronous receiver transmitter<br>(LPUART)<br>Changed LPUART_TDR into LPUART_RDR in Figure 342: Reception using DMA.<br>Updated Section 30.5.4: USART FIFOs and thresholds.<br>Updated Section 31.5.1: LPUART control register 1 [alternate] (LPUART_CR1).<br>Corrected WUS bitfield length and changed RXFTCFG to TXFTCFG (bit 31 to 29) in<br>Section 31.5.4: LPUART control register 3 (LPUART_CR3).<br>Section 31.5.8: LPUART interrupt and status register [alternate] (LPUART_ISR):<br>Updated IDLE bit descriptions<br>FIFO enabled only: updated reset value<br>Changed NFCF to NECF in Section 31.5.9: LPUART interrupt flag clear register<br>(LPUART_ICR).<br>Table 199: LPUART register map and reset values<br>LPUART_CR1: bit 12 changed to M0, bit 5 changed to RXNEIE/RXFNEIE.<br>LPUART_ISR: changed TXE bit to TXE/TXFNF<br>Corrected LPUART_ISR reset value and bits 7 and 5 names.<br>Section 53: Serial peripheral interface (SPI)<br>Table 438: SPI register map and reset values:<br>SPI2S_SR: Changed bit 7 to CRCE.<br>SPI2S_I2SCFGR: added DATFMT (bit 14)<br>Section 57: Management data input/output (MDIOS)<br>In Table 459: MDIOS register map and reset values, for MDIOS_CR register,<br>changed bit 3 to EIE and added DPC (bit 7).<br>Section 58: Secure digital input/output MultiMediaCard interface (SDMMC)<br>Replaced HOLD by DHOLD in the whole document.<br>Updated Figure 746: SDMMC block diagram and Table 464: SDMMC pins.<br>Updated Figure 755: CLKMUX unit.<br>Updated Wait_S in Section : Data path and Table 474: Data path status flags and<br>clear bits.<br>Updated Section 58.5.3: General description.<br>Updated Section : Stream operation and CMD12. |
|---------------------|---------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                     |                           | Added Section 58.8: SDMMC interrupts.<br>Updated Section 58.9.10: SDMMC data counter register (SDMMC_DCNTR),<br>Section 58.9.11: SDMMC status register (SDMMC_STAR) and Section 58.9.15:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |

![](_page_5_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
|-------------|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 59: Controller area network with flexible data rate (FDCAN)                                                                                                                                                                                                                                                                                                                                                                                                                                           |
|             |               | Updated Section 59.4.7: FDCAN nominal bit timing and prescaler register<br>(FDCAN_NBTP), Section 59.4.12: FDCAN error counter register (FDCAN_ECR),<br>Section 59.4.15: FDCAN interrupt register (FDCAN_IR), Section 59.4.37: FDCAN<br>Tx buffer request pending register (FDCAN_TXBRP) and Section 59.4.64: FDCAN<br>TT trigger select register (FDCAN_TTTS).                                                                                                                                                |
|             |               | Updated Section Table 513.: FDCAN register map and reset values.                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|             |               | Updated FCCAN_CCU_CCFG in Section Table 514.: CCU register map and reset<br>values.                                                                                                                                                                                                                                                                                                                                                                                                                           |
|             |               | Section 61: Ethernet (ETH): media access control (MAC) with DMA controller                                                                                                                                                                                                                                                                                                                                                                                                                                    |
|             |               | Added Figure 833: Supported PHY interfaces.                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
|             |               | Removed reference to AV standard in Section 61.1: Ethernet introduction.                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| 04-Apr-2019 | 2 (continued) | Section 63: Debug infrastructure                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|             |               | Changed ETF RAM size to 4 Kbytes in Section 63.5.5: Embedded trace FIFO (ETF)<br>and Section : ETF RAM size register (ETF_RSZ).                                                                                                                                                                                                                                                                                                                                                                               |
|             |               | Added revision V and updated reset value in Section : DBGMCU identity code<br>register (DBGMCU_IDC).                                                                                                                                                                                                                                                                                                                                                                                                          |
|             |               | Renamed WDGLSD1/2 into DBG_IWDG1/2 in Section : DBGMCU APB4 peripheral<br>freeze register CPU1 (DBGMCU_APB4FZ1) and Section : DBGMCU APB4<br>peripheral freeze register CPU2 (DBGMCU_APB4FZ2)                                                                                                                                                                                                                                                                                                                 |
|             |               | Prefixed all bits names in Section : DBGMCU APB1L peripheral freeze register<br>CPU1 (DBGMCU_APB1LFZ1), Section : DBGMCU APB1L peripheral freeze<br>register CPU2 (DBGMCU_APB1LFZ2), Section : DBGMCU APB2 peripheral freeze<br>register CPU1 (DBGMCU_APB2FZ1), Section : DBGMCU APB2 peripheral freeze<br>register CPU2 (DBGMCU_APB2FZ2), Section : DBGMCU APB4 peripheral freeze<br>register CPU1 (DBGMCU_APB4FZ1) and Section : DBGMCU APB4 peripheral<br>freeze register CPU2 (DBGMCU_APB4FZ2) by 'DBG_'. |

3520/3556 RM0399 Rev 4

**Table 657. Document revision history (continued)**

|                     |               | Table 657. Document revision history (continued)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |
|---------------------|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                     |               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
| Date<br>27-Feb-2020 | Revision<br>3 | Changes<br>Updated Section : Error code correction (ECC) and Section : Embedded bootloader.<br>Section 3: RAM ECC monitoring (RAMECC)<br>Changed ECCEN bit of RAMECC_MxCR to reserved.<br>Table 12: RAMECC register map and reset values: updated RAMECC_MxCR,<br>RAMECC_MxSR. replaced by RAMECC_MxFAR at address offset 0x28+0x20*(x<br>1) and RAMECC_MxFDRLH replaced by RAMECC_MxFDRH.<br>Section 4: Embedded flash memory (FLASH)<br>Restricted Table 15 to STM32H745xI/747xI/755xI/757xI and added Table 15.<br>Added VOS0 range to Table 17.<br>Section 5: Secure memory management (SMM) (former Secure internal Flash<br>memory)<br>Updated exitSecureArea in Section 5.4.2: Secure area exiting service.<br>Section 7: Power control (PWR)<br>Moved LSI from backup to VDD domain in Figure 21: Power supply overview.<br>Added Figure 36: Switching VCORE from VOS1 to VOS0 in Section : VOS0<br>activation/deactivation sequence.<br>Updated list of GPIOs which use is restricted in Section 7.4.4: Backup domain.<br>Updated Section 7.4.8: DSI regulator.<br>Updated CStop mode exit in Section Table 42.: CStop mode.<br>Updated ACTVOSRDY bit definition in Section 7.8.2: PWR control status register 1<br>(PWR_CSR1).<br>Updated VOSRDY bit definition in Section 7.8.7: PWR D3 domain control register<br>(PWR_D3CR).<br>Section 8: Low-power D3 domain application example<br>Replaced LINUART1 by LPUART1.<br>Updated Figure 45: Timing diagram of SRAM4-to-LPUART1 transfer with BDMA<br>and D3 domain in Autonomous mode.<br>Updated section Section : EXTI programming.<br>Updated DMAMUX2_C0CR value for DMAMUX2 SYNC0 in Table 51: BDMA and<br>DMAMUX2 initialization sequence (DMAMUX2_INIT).<br>Renamed Table 52 into "LPUART1 start programming.<br>Section 9: Reset and Clock Control (RCC) |
|                     |               | Renamed adc_ker_ck into adc_ker_ck_inputs.<br>Added note on RTC/AWU and updated USB1ULPI and ADC1/2/3 maximum<br>allowed frequency for VOS0/1/2/3 in Table 66: Kernel clock distribution overview.<br>Updated introductory sentence of Section 9.4.2: System reset.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
|                     |               | Section 10: Clock recovery system (CRS)<br>Added Section 10.3: CRS implementation. Updated Section 10.8.1: CRS control<br>register (CRS_CR). Updated Table 93: CRS register map and reset values.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |

![](_page_7_Picture_3.jpeg)

RM0399 Rev 4 3521/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                        |
|-------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 12: General-purpose I/Os (GPIO)                                                                                                                                                                                                        |
|             |               | Changed to analog the mode in which most of the I/O ports are configured<br>during and just after reset.                                                                                                                                       |
|             |               | Section 16: Direct memory access controller (DMA)                                                                                                                                                                                              |
|             |               | Change Bit 20 to TRBUFF instead of reserved in Section 16.5.5: DMA stream x<br>configuration register (DMA_SxCR).                                                                                                                              |
|             |               | Section 21: Extended interrupt and event controller (EXTI)                                                                                                                                                                                     |
|             |               | Added note to event 80 in Table 152: EXTI Event input mapping.                                                                                                                                                                                 |
|             |               | Section 23: Flexible memory controller (FMC)                                                                                                                                                                                                   |
|             |               | Updated Section : General transaction rules to clarify the behavior of the FMC when<br>AXI transaction data size is different from the device data width and add the case of<br>unaligned addresses.                                           |
|             |               | Replaced FMC_CLK by fmc_ker_ck in the formulas of Section : WAIT management<br>in asynchronous accesses.                                                                                                                                       |
|             |               | Section 24: Quad-SPI interface (QUADSPI)                                                                                                                                                                                                       |
|             |               | Updated Section 24.3.4: QUADSPI signal interface protocol modes.                                                                                                                                                                               |
|             | 3 (continued) | Updated Section 24.3.11: QUADSPI configuration and Section 24.5.1: QUADSPI<br>control register (QUADSPI_CR) adding 'when setting QUADSPI interface in DDR<br>mode, the prescaler must be set with a division ratio of 2 or more' paragraph.    |
| 27-Feb-2020 |               | Updated FTHRES[4:0] bits description of Section 24.5.1: QUADSPI control register<br>(QUADSPI_CR) for IP_XACT compliance.                                                                                                                       |
|             |               | Added note in Section 24.5.6: QUADSPI communication configuration register<br>(QUADSPI_CCR). Updated Section 24.5.7: QUADSPI address register<br>(QUADSPI_AR). Changed FLEVEL[6:0] by FLEVEL[5:0] in Section 24.5.14:<br>QUADSPI register map. |
|             |               | Section 26: Analog-to-digital converters (ADC)                                                                                                                                                                                                 |
|             |               | Removed note related to connection to DFSDM limited to ADC1 and ADC2, and<br>added adc_sclk in Figure 141: ADC block diagram. Removed VREF+ and VREF<br>ranges and added adc_sclk in Table 209: ADC input/output pins.                         |
|             |               | Added reference to LDORDY bit in the whole section.                                                                                                                                                                                            |
|             |               | Updated Section 26.4.3: ADC clocks and renamed adc_ker_ck into<br>adc_ker_ck_inputs. Updated Section : BOOST control.                                                                                                                          |
|             |               | Replaced SMPPLUS control by Extended sample time option (SMPPLUS control)<br>and added LDO voltage regulator in Section 26.3: ADC implementation.                                                                                              |
|             |               | Updated Section 26.4.11: Channel selection (SQRx, JSQRx)                                                                                                                                                                                       |
|             |               | Removed RES[2:0] configuration in Table 217: Offset computation versus data<br>resolution and Table 221: Analog watchdog 1,2,3 comparison.                                                                                                     |
|             |               | Updated Section : ADC overrun (OVR, OVRMOD). Added case of FIFO overflow in<br>Section : Managing a sequence of conversion without using the DMA.                                                                                              |
|             |               | Updated Section : Single ADC operating modes support when oversampling to<br>remove the mention that the offset correction is not supported in oversampling<br>mode.                                                                           |

![](_page_8_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

|             |               | Table 657. Document revision history (continued)                                                                                                                                                                                                                                                                                                   |
|-------------|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                            |
|             | 3 (continued) | Section 26: Analog-to-digital converters (ADC)(continued)<br>Renamed VSENSEEN into TSEN, and replaced adc_hclk by adc_hclk in<br>CKMODE[1:0] bitfield definition of in Section 26.7.2: ADC x common control register<br>(ADCx_CCR) (x=1/2 or 3).                                                                                                   |
|             |               | Updated RES[2:0] bitfield in Section 26.6.4: ADC configuration register<br>(ADC_CFGR). Updated LSHIFT[3:0] corresponding to the "Shift left 14-bits"<br>configuration in Section 26.6.5: ADC configuration register 2 (ADC_CFGR2).                                                                                                                 |
|             |               | Reworded JEXTEN[1:0] to remove duplicate 00 configuration for JEXTEN[1:0] in<br>Section 26.6.16: ADC injected sequence register (ADC_JSQR) register. Updated<br>Section 26.6.26: ADC calibration factors register (ADC_CALFACT).                                                                                                                   |
|             |               | Removed ADC_CALCLKR register.                                                                                                                                                                                                                                                                                                                      |
|             |               | Section 27: Digital-to-analog converter (DAC)                                                                                                                                                                                                                                                                                                      |
|             |               | Replaced sample and hold clock (lsi_ck and lse_ck when available) by<br>dac_hold_ck.                                                                                                                                                                                                                                                               |
|             |               | Updated Section 27.3: DAC implementation and Figure 212: Dual-channel DAC<br>block diagram. Section 27.4.2: DAC pins and internal signals: added DAC<br>interconnection table, changed dac_chx_trg[0:15] into dac_chx_trg[1:15] (trigger 0<br>corresponds to the SW trigger) in block diagram and Table 230: DAC internal<br>input/output signals. |
|             |               | Updated Figure 215: Timing diagram for conversion with trigger disabled TEN = 0 to<br>make it independent from the bus (AHB or APB).                                                                                                                                                                                                               |
| 27-Feb-2020 |               | Removed Tables Trigger selection from Section 27.4.7: DAC trigger selection.                                                                                                                                                                                                                                                                       |
|             |               | Updated Section : Sample and hold mode to indicate that the lsi_ck/lse_ck (when<br>available) must not be stopped when Sample and hold mode enabled.                                                                                                                                                                                               |
|             |               | Updated supply voltages in Section 27.4.12: DAC channel buffer calibration.                                                                                                                                                                                                                                                                        |
|             |               | Updated CStop mode description for DAC1 in Section 27.5: DAC in low-power<br>modes.                                                                                                                                                                                                                                                                |
|             |               | Updated Section 27.6: DAC interrupts.                                                                                                                                                                                                                                                                                                              |
|             |               | Updated TSELx bitfield description in Section 27.7.1: DAC control register<br>(DAC_CR) register to add the correspondence between TSELx configurations and<br>dac_chx_trgy.                                                                                                                                                                        |
|             |               | Section 29: Comparator (COMP)                                                                                                                                                                                                                                                                                                                      |
|             |               | Removed condition on OR_CFG and changed OR bits to reserved in<br>Section 29.7.3: Comparator option register (COMP_OR).                                                                                                                                                                                                                            |
|             |               | Section 31: Digital filter for sigma delta modulators (DFSDM)<br>Updated Table 255: DFSDM break connection.                                                                                                                                                                                                                                        |
|             |               | Removed all "ADC1 and ADC2 only" notes and footnotes.                                                                                                                                                                                                                                                                                              |
|             |               | Updated Section 31.7: DFSDM channel y registers (y=07). Updated<br>Section 31.7.5: DFSDM channel y data input register (DFSDM_CHyDATINR).<br>Updated Section 31.8: DFSDM filter x module registers (x=03).                                                                                                                                         |

![](_page_9_Picture_3.jpeg)

RM0399 Rev 4 3523/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|-------------|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 35: JPEG codec (JPEG)<br>Updated Section 35.5.5: JPEG codec configuration register 4-7 (JPEG_CONFR4-<br>7). bit 1 and bit 0 description.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |
| 27-Feb-2020 | 3 (continued) | Section 36: True random number generator (RNG)<br>Updated Section 36.1: Introduction and Section 36.2: RNG main features.<br>Updated Section 36.3.3: Random number generation and Figure 295: RNG<br>initialization overview.<br>Updated note in Section 36.3.5: RNG operation.<br>Updated Section 36.5: RNG processing time and Section 36.6: RNG entropy<br>source validation.<br>Updated Section 36.7.3: RNG data register (RNG_DR).<br>Section 37: Cryptographic processor (CRYP)<br>Updated number of clock cycles for TDES in Section 37.2: CRYP main features.n<br>Removed flowcharts (Nonuser) in Section 37.4.5: CRYP procedure to perform a<br>cipher operation.<br>Updated Section 37.4.17: CRYP key registers.<br>Updated Table 312: Cryptographic processor configuration for memory-to<br>peripheral DMA transfers and Table 313: Cryptographic processor configuration for<br>peripheral-to-memory DMA transfers.<br>Section 37.5: CRYP interrupts: removed Figure CRYP interrupt mapping diagram<br>and updated Table 314: CRYP interrupt requests.<br>Section 37.6: CRYP processing time: updated Table 315: Processing latency for<br>ECB, CBC and CTR and Table 315: Processing latency for ECB, CBC and CTR.<br>Section 38: Hash processor (HASH)<br>Message size changed to 264-1 in Section 38.1: Introduction and Section 38.4.3:<br>About secure hash algorithms.<br>Added Section 38.3: HASH implementation.<br>Updated Figure 320: HASH block diagram.<br>Updated Figure 321: Message data swapping feature.<br>Updated Section 38.4.8: HASH suspend/resume operations.<br>Renamed HASH_HRx registers located at address offset 0x0C into Section : HASH<br>aliased digest register x (HASH_HRAx).<br>Updated ALGO description in Section 38.7.1: HASH control register (HASH_CR).<br>Specified value returned by reading Section 38.7.2: HASH data input register |
|             |               | (HASH_DIN).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |

![](_page_10_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

|             | Table 657. Document revision history (continued) |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |  |
|-------------|--------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--|
| Date        | Revision                                         | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           |  |
|             |                                                  | Section 40: Advanced-control timers (TIM1/TIM8)<br>Updated Figure 386: Advanced-control timer block diagram.<br>Updated Section 40.3.3: Repetition counter.<br>Updated Section 40.3.16: Using the break function.                                                                                                                                                                                                                                                                                                                                                                                                                                                 |  |
|             |                                                  | Updated Section 40.4.2: TIMx control register 2 (TIMx_CR2)(x = 1, 8). Aligned<br>TS[2:0] field in Section 40.4.3: TIMx slave mode control register (TIMx_SMCR)(x =<br>1, 8). Updated Section 40.4.5: TIMx status register (TIMx_SR)(x = 1, 8). Updated<br>Section 40.4.6: TIMx event generation register (TIMx_EGR)(x = 1, 8). Updated<br>Table 355: TIM1 register map and reset values, Table 356: TIM8 register map and<br>reset values.                                                                                                                                                                                                                        |  |
|             |                                                  | Updated Section 40.3.29: Debug mode.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |  |
|             |                                                  | Section 41: General-purpose timers (TIM2/TIM3/TIM4/TIM5)<br>Updated Section 41.4.12: TIMx counter [alternate] (TIMx_CNT)(x = 2 to 5).<br>Updated Table 360: TIM2/TIM3/TIM4/TIM5 register map and reset values.                                                                                                                                                                                                                                                                                                                                                                                                                                                    |  |
|             |                                                  |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |  |
|             |                                                  | Section 42: General-purpose timers (TIM12/TIM13/TIM14)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |  |
|             |                                                  | Updated Figure 496: General-purpose timer block diagram (TIM12).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |  |
|             |                                                  | Updated Figure 510: Capture/compare channel 1 main circuit.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |  |
|             | 3 (continued)                                    | Updated Figure 511: Output stage of capture/compare channel (channel 1).<br>Updated Section 42.4.1: TIM12 control register 1 (TIM12_CR1), Section 42.4.5:<br>TIM12 status register (TIM12_SR) and Section 42.5.5: TIMx capture/compare mode<br>register 1 (TIMx_CCMR1)(x = 13 to 14).                                                                                                                                                                                                                                                                                                                                                                             |  |
| 27-Feb-2020 |                                                  |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   |  |
|             |                                                  | Section 43: General-purpose timers (TIM15/TIM16/TIM17)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |  |
|             |                                                  | Updated Figure 522: TIM15 block diagram.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |  |
|             |                                                  | Updated Figure 537: Capture/compare channel 1 main circuit.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |  |
|             |                                                  | Updated: Section 43.5.2: TIM15 control register 2 (TIM15_CR2), Section 43.5.5:<br>TIM15 status register (TIM15_SR), Section 43.5.9: TIM15 capture/compare enable<br>register (TIM15_CCER), Section 43.6.2: TIMx control register 2 (TIMx_CR2)(x = 16<br>to 17), Section 43.6.4: TIMx status register (TIMx_SR)(x = 16 to 17), Section 43.6.7:<br>TIMx capture/compare mode register 1 [alternate] (TIMx_CCMR1)(x = 16 to 17)<br>and Section 43.6.8: TIMx capture/compare enable register (TIMx_CCER)(x = 16 to<br>17).Replaced DT[7:0] by DTG[7:0] in Table 368: TIM15 register map and reset<br>values and Table 370: TIM16/TIM17 register map and reset values. |  |
|             |                                                  | Section 45: Low-power timer (LPTIM)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |  |
|             |                                                  | Updated Section 45.4.5: Glitch filter.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |  |
|             |                                                  | Section 47: System window watchdog (WWDG)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |  |
|             |                                                  | Updated Section 47.5.1: WWDG control register (WWDG_CR).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |  |
|             |                                                  | Section 49: Real-time clock (RTC)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 |  |
|             |                                                  | Updated Figure 580: Detailed RTC block diagram and Figure 581: Tamper<br>detection. Updated Section 49.4: RTC low-power modes.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |  |
|             |                                                  | Updated Section 49.5: RTC interrupts.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |  |

![](_page_11_Picture_3.jpeg)

RM0399 Rev 4 3525/3556

**Table 657. Document revision history (continued)**

| Section 51: Universal synchronous/asynchronous receiver transmitter<br>(USART/UART)<br>Section 51.8.10: USART interrupt and status register [alternate] (USART_ISR):<br>– FIFO enabled: changed reset value to 0x0X80 00C0 in and Table 426: USART<br>register map and reset values.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |  |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--|
| – FIFO disabled: changed reset value to 0x0000 00C0 in Table 426: USART<br>register map and reset values<br>Changed reset value to 0x0000 0000 in Section 51.8.12: USART receive data<br>register (USART_RDR) and Section 51.8.13: USART transmit data register<br>(USART_TDR).<br>Updated Section 51.8: USART registers to indicate that USART and LPUART<br>registers are accessed by words.<br>Section 52: Low-power universal asynchronous receiver transmitter<br>(LPUART)<br>Added Section 51.4: USART implementation.<br>Section 52.7.7: LPUART interrupt and status register (LPUART_ISR):<br>– FIFO enabled: changed reset value to 0x0080 00C0 in Table 434: LPUART<br>register map and reset values.<br>– FIFO disabled: changed reset value to 0x0000 00C0 in Table 434: LPUART<br>register map and reset values.<br>Updated Section 52.7: LPUART registers to indicate that USART and LPUART<br>registers are accessed by words.<br>27-Feb-2020<br>3 (continued)<br>Section 54: Serial audio interface (SAI)<br>Figure 689: SAI functional block diagram: number of Dn and CKn lines made<br>generic, added note to indicate that all Dn and CKn might not be available on all SAI<br>instances.<br>Added Section 54.3: SAI implementation.<br>Updated Table 445: SAI input/output pins to indicate the number of Dn/CKn<br>available on each SAI instance.<br>Updated Figure 698: Start-up sequence.<br>Updated Section 54.6: SAI registers to indicate that SAI registers are accessed by<br>words.<br>Section 56: Single wire protocol master interface (SWPMI)<br>Updated Section 56: Single wire protocol master interface (SWPMI).<br>Section 59: Controller area network with flexible data rate (FDCAN)<br>Updated Section 59.1: Introduction and Section 59.2: FDCAN main features. Added<br>Section 59.3: FDCAN implementation.<br>Section 59.4.1: Operating modes: updated Section : Software initialization, Section :<br>CAN FD operation, and Section : Transceiver delay compensation.<br>Section 59.4.2: Message RAM: updated Acceptance filter, Figure 781: Standard<br>message ID filter path and Figure 782: Extended message ID filter path.<br>Updated Section 59.4.4: Bit timing and Section 59.4.5: Clock calibration on CAN.<br>Section 59.4.6: Application: updated Section : Software calibration, Section : Clock |  |

3526/3556 RM0399 Rev 4

![](_page_12_Picture_4.jpeg)

**Table 657. Document revision history (continued)**

| Date<br>Revision<br>Changes<br>Section 59: Controller area network with flexible data rate (FDCAN)<br>(continued)<br>Section 59.4.8: TTCAN configuration: updated Section : Timing of interface signals.<br>Updated Table 521: Standard message ID filter element field description, Table 523:<br>Extended message ID filter element field description, Table 525: Trigger memory<br>element description. Updated Table 525: Trigger memory element description and<br>Table 780: Extended message ID filter path.<br>Updated Section 59.5.6: FDCAN CC control register (FDCAN_CCCR),<br>Section 59.5.15: FDCAN interrupt register (FDCAN_IR), Section 59.5.18: FDCAN<br>interrupt line enable register (FDCAN_ILE), Section 59.5.21: FDCAN extended ID<br>filter configuration register (FDCAN_XIDFC), Section 59.5.31: FDCAN Rx FIFO 1<br>status register (FDCAN_RXF1S), Section 59.5.32: FDCAN Rx FIFO 1 acknowledge<br>register (FDCAN_RXF1A) and Section 59.7.2: Calibration configuration register<br>(FDCAN_CCU_CCFG). Updated Table 528: CCU register map and reset values.<br>Section 60: USB on-the-go high-speed (OTG_HS)<br>Updated Section 60.2: OTG_HS main features, Section 60.14.2: OTG interrupt<br>register (OTG_GOTGINT), Section 60.14.5: OTG reset register (OTG_GRSTCTL),<br>Section 60.14.6: OTG core interrupt register (OTG_GINTSTS), Section 60.14.18:<br>OTG host periodic transmit FIFO size register (OTG_HPTXFSIZ), Section 60.14.22:<br>OTG host frame interval register (OTG_HFIR), Section 60.14.33: OTG host channel<br>x transfer size register (OTG_HCTSIZx), Section 60.14.39: OTG device<br>configuration register (OTG_DCFG), Section 60.14.40: OTG device control register<br>27-Feb-2020<br>3 (continued)<br>(OTG_DCTL), Section 60.14.41: OTG device status register (OTG_DSTS),<br>Section 60.14.42: OTG device IN endpoint common interrupt mask register |  |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--|
|                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |  |
| (OTG_DIEPMSK), Section 60.14.43: OTG device OUT endpoint common interrupt<br>mask register (OTG_DOEPMSK),Section 60.14.54: OTG device IN endpoint x<br>control register (OTG_DIEPCTLx) and Section 60.14.61: OTG device OUT<br>endpoint x interrupt register (OTG_DOEPINTx).<br>Updated Section 60.10: OTG_HS Dynamic update of the OTG_HFIR register.<br>Updated Section 60.15.3: Device initialization.<br>Updated Section 60.15.5: Host programming model.<br>Section 61: Ethernet (ETH): media access control (MAC) with DMA controller<br>Replaced ptp_pps_o internal signal by eth_ptp_pps_out, and ptp_aux_ts_trig_i by<br>eth_ptp_trgx (where x = 0 to 3) and ptp_aux_trig_i[x] by eth_ptp_trgx.<br>Update ARPEN bit description in Section : Operating mode configuration register<br>(ETH_MACCR).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             |  |
| Reintroduced EIPG enumerated values in Section : Extended operating mode<br>configuration register (ETH_MACECR).<br>Removed sentence "This register is present only when the IEEE 1588 Timestamp<br>feature is selected without external timestamp input" from Section : System time<br>nanoseconds register (ETH_MACSTNR), and Section : System time nanoseconds                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |  |

![](_page_13_Picture_3.jpeg)

RM0399 Rev 4 3527/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
|-------------|---------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 27-Feb-2020 | 3 (continued) | Section 63: Debug infrastructure<br>Updated Figure 870: Block diagram of debug infrastructure, Figure 871: Power<br>domains of debug infrastructure and Figure 872: Clock domains of debug<br>infrastructure.<br>Updated Section : Clock domains.<br>Changed ID code for Instruction register = 1110 in Table 622: JTAG-DP data<br>registers.<br>Updated notes in Table 623: Debug port registers.<br>Modified Section : Debug port target identification register (DP_TARGETID) reset<br>value as well as bit descriptions.<br>Modified Section : Access port identification register (AP_IDR) reset value as well<br>as description of REVISION bitfield.<br>Updated Table 625: System ROM table 1.<br>Modified Section : SYSROM CoreSight peripheral identity register 0<br>(SYSROM_PIDR0), Section : SYSROM CoreSight peripheral identity register 1<br>(SYSROM_PIDR1) and Section : SYSROM CoreSight peripheral identity register 2<br>(SYSROM_PIDR2).<br>Added Table 626: System ROM table 2.<br>Modified Section : CTI CoreSight peripheral identity register 0 (CTI_PIDR0) and<br>Section : CTI CoreSight peripheral identity register 2 (CTI_PIDR2). Updated bitfield<br>description for Section : CTI application trigger set register (CTI_APPSET),<br>Section : CTI application trigger clear register (CTI_APPCLEAR), Section : CTI<br>application pulse register (CTI_APPPULSE), Section : CTI trigger IN x enable<br>register (CTI_INENx), Section : CTI trigger OUT x enable register (CTI_OUTENx)<br>and Section : CTI channel gate register (CTI_GATE).<br>Updated Section : ETF CoreSight peripheral identity register 2 (ETF_PIDR2) reset<br>value.<br>Modified Section : TPIU CoreSight peripheral identity register 2 (TPIU_PIDR2), and<br>Section : SWTF CoreSight peripheral identity register 2 (SWTF_PIDR2).<br>Changed DBGSTBY_D3 and DBGSTOP_D3 to reserved in Section : SWTF<br>CoreSight peripheral identity register 2 (SWTF_PIDR2).<br>Updated Table 641: Cortex-M7 processor ROM table and Table 656: Cortex-M4<br>ROM table. Updated Table 651: Cortex-M4 ROM table.<br>Updated Section : Processor ROM CoreSight peripheral identity register 0<br>(M7_CPUROM_PIDR0), Section : Processor ROM CoreSight peripheral identity<br>register 1 (M7_CPUROM_PIDR1) and Section : Processor ROM CoreSight<br>peripheral identity register 2 (M7_CPUROM_PIDR2).<br>Updated Section : DWT CoreSight peripheral identity register 0 (M7_DWT_PIDR0),<br>Section : DWT CoreSight peripheral identity register 1 (M7_DWT_PIDR1), Section :<br>DWT CoreSight peripheral identity register 2 (M7_DWT_PIDR2) reset value.<br>Updated Section : ITM CoreSight peripheral identity register 0 (M7_ITM_PIDR0),<br>Section : ITM CoreSight peripheral identity register 1 (M7_ITM_PIDR1), Section :<br>ITM CoreSight peripheral identity register 2 (M7_ITM_PIDR2).<br>Updated Table 648: Cortex-M7 ETM register map and reset values.<br>Updated Section : ITM CoreSight peripheral identity register 0 (M7_ITM_PIDR0),<br>Section : ITM CoreSight peripheral identity register 1 (M7_ITM_PIDR1) and<br>Section : ITM CoreSight peripheral identity register 2 (M7_ITM_PIDR2). |

![](_page_14_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Date             | Revision                 | Changes                                                                                                                                                                                                       |
|------------------|--------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                  |                          | Updated Section : Introduction. Added errata sheet in the list of reference<br>documents in Section : Related documents.                                                                                      |
|                  |                          | Section 2: Memory and bus architecture                                                                                                                                                                        |
|                  |                          | Updated Table 2: Bus-master-to-bus-slave interconnect.                                                                                                                                                        |
|                  |                          | Updated Figure 1: System architecture for STM32H745/55/47/57xx devices.                                                                                                                                       |
|                  |                          | Section 3: RAM ECC monitoring (RAMECC)                                                                                                                                                                        |
|                  |                          | Added note to Section 3.1: Introduction.                                                                                                                                                                      |
|                  |                          | Section 4: Embedded flash memory (FLASH)                                                                                                                                                                      |
|                  |                          | Removed bootloader extension from Figure 8: Embedded flash memory usage.                                                                                                                                      |
| 16-Jun-2023<br>4 |                          | Added option byte area (bank 1) in Table 14: Flash memory organization on<br>STM32H745xI/747xI/755xI/757xI devices.                                                                                           |
|                  |                          | Section : Erase operation overview: added note related to the case where data<br>cache is enabled after erase operations, removed the mention that Bank 2 can be<br>erased with ST secure firmware.           |
|                  | Updated FLASH registers: |                                                                                                                                                                                                               |
|                  |                          | – Modified number of wait states in description of LATENCY bits in FLASH access<br>control register (FLASH_ACR).                                                                                              |
|                  |                          | – Updated FLASH option status register (FLASH_OPTSR_CUR) and FLASH<br>option status register (FLASH_OPTSR_PRG).                                                                                               |
|                  |                          | – Added note providing non-secure Flash area start address in SEC_AREA_END1<br>of FLASH secure address for bank 1 (FLASH_SCAR_CUR1).                                                                          |
|                  |                          | – Added formula to FAIL_ECC_ADDR1/2 in FLASH ECC fail address for bank 1<br>(FLASH_ECC_FA1R) and FLASH ECC fail address for bank 2<br>(FLASH_ECC_FA2R), respectively.                                         |
|                  |                          | Section 5: Secure memory management (SMM)                                                                                                                                                                     |
|                  |                          | Added note below Figure 16: Bootloader state machine in Secure access mode.                                                                                                                                   |
|                  |                          | Section 5.4: Root secure services (RSS): added introduction and RSS API<br>addresses.                                                                                                                         |
|                  |                          | Section 5.5.2: Setting secure user memory areas: modified name of the service<br>used to initialize the option bytes.                                                                                         |
|                  |                          | Section 6: ART accelerator                                                                                                                                                                                    |
|                  |                          | Added note to PCACHEADDR[11:0] in ART accelerator - control register<br>(ART_CTR).                                                                                                                            |
|                  |                          | Section 7: Power control (PWR)                                                                                                                                                                                |
|                  |                          | Modified Section 7.4: Power supplies, Section : VCORE supplied in Bypass mode<br>(LDO and SMPS OFF) and Section 7.4.4: Backup domain.                                                                         |
|                  |                          |                                                                                                                                                                                                               |
|                  |                          | Updated Section 7.4.8: DSI regulator.                                                                                                                                                                         |
|                  |                          | Replaced WKUPn+1 with WKUPn, WKUPCn+1 with WKUPCn and WKUPFn+1<br>with WKUPFn in PWR wakeup clear register (PWR_WKUPCR), PWR wakeup flag<br>register (PWR_WKUPFR) and PWR wakeup enable and polarity register |
|                  |                          | (PWR_WKUPEPR).                                                                                                                                                                                                |

![](_page_15_Picture_3.jpeg)

RM0399 Rev 4 3529/3556

**Table 657. Document revision history (continued)**

| Section 8: Low-power D3 domain application example<br>Changed section title.<br>Section 9: Reset and Clock Control (RCC)<br>Updated Figure 48: RCC Block diagram and Figure 53: PLL block diagram.<br>Updated step 4 of PLL initialization phase.<br>Table 62: Kernel clock distribution overview: changed TIM[8:1][17:12] and ADC1,2,<br>3 maximum allowed frequencies.<br>Updated RCC registers:<br>– Updated DIVM3[5:0] in RCC PLLs clock source selection register<br>(RCC_PLLCKSELR) register to remove the indication that the value 000000<br>corresponds to the default value after reset.<br>– Updated maximum VCO frequency in PLLxVCOSEL of RCC PLL configuration<br>register (RCC_PLLCFGR), DIVNx[8:0] of RCC_PLLxDIVR registers,<br>FRACNx[12:0] of RCC_PLLxFRACR registers.<br>– Updated RCC PLL1 dividers configuration register (RCC_PLL1DIVR).<br>– Updated description of FRACN1[12:0] bits in RCC PLL1 fractional divider register<br>(RCC_PLL1FRACR).<br>– Added note to ARTRST bit description in RCC AHB1 peripheral reset<br>register(RCC_AHB1RSTR). |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| – Replaced VREF with VREFBUF in description of bit 15 in RCC APB4 peripheral<br>reset register (RCC_APB4RSTR) and RCC APB4 clock register<br>16-Jun-2023<br>4 (continued)<br>(RCC_APB4ENR).<br>– Updated RCC AHB1 clock register (RCC_AHB1ENR): modified position of<br>USB2OTGHSULPIEN bit (bit 28 instead of bit 18)<br>– Added note to USB2OTGHSULPILPEN in RCC AHB1 Sleep clock register<br>(RCC_AHB1LPENR).<br>Section 10: Clock recovery system (CRS)<br>Updated Section : FELIM value and CRS control register (CRS_CR).<br>Section 11: Hardware semaphore (HSEM)<br>Updated Section 11.1: Introduction.<br>Section 11.3: Functional description deeply reworked.<br>Updated HSEM registers: HSEM register semaphore x (HSEM_Rx), HSEM read<br>lock register semaphore x (HSEM_RLRx), HSEM interrupt enable register<br>(HSEM_CnIER), HSEM interrupt clear register (HSEM_CnICR), HSEM interrupt<br>status register (HSEM_CnISR) and HSEM interrupt status register<br>(HSEM_CnMISR).                                                                                |

![](_page_16_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
|-------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 13: System configuration controller (SYSCFG)<br>SYSCFG peripheral mode configuration register (SYSCFG_PMCR): updated reset<br>value, added note indicating that it depends on the package, modified<br>BOOSTVDDSEL bit description in (VDDA instead of VDD).<br>Added PI[x] pin in SYSCFG external interrupt configuration register 4<br>(SYSCFG_EXTICR4).<br>Added SYSCFG system register (SYSCFG_SR0).<br>Section 16: Direct memory access controller (DMA)<br>Updated number of DMA streams in Section 16.1: DMA introduction |
|             |               | Section 18: DMA request multiplexer (DMAMUX)<br>Updated caution note in Section 18.4.3: DMAMUX channels.                                                                                                                                                                                                                                                                                                                                                                                                                                 |
|             |               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| 16-Jun-2023 | 4 (continued) | Section 19: Chrom-ART Accelerator controller (DMA2D)<br>Updated Section 19.3.1: General description,Figure 93: DMA2D block diagram, and<br>Section 19.3.2: DMA2D internal signals.                                                                                                                                                                                                                                                                                                                                                       |
|             |               | Updated Section 19.3.9: DMA2D output FIFO, Section 19.3.12: DMA2D<br>transactions, and Section 19.3.13: DMA2D configuration.                                                                                                                                                                                                                                                                                                                                                                                                             |
|             |               | Updated DMA2D registers: DMA2D output color register (DMA2D_OCOLR),<br>DMA2D foreground CLUT (DMA2D_FGCLUTx) and DMA2D background CLUT<br>(DMA2D_BGCLUTx).                                                                                                                                                                                                                                                                                                                                                                               |
|             |               | Section 22: Cyclic redundancy check calculation unit (CRC)                                                                                                                                                                                                                                                                                                                                                                                                                                                                               |
|             |               | Added CRC register access granularity in Section 22.2: CRC main features and<br>Section 22.4: CRC registers.                                                                                                                                                                                                                                                                                                                                                                                                                             |
|             |               | Updated Figure 102: CRC calculation unit block diagram.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
|             |               | Added note in Section : Polynomial programmability to clarify what are even and<br>odd polynomials.                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|             |               | Section 23: Flexible memory controller (FMC)<br>Updated SRAM/NOR-flash chip-select control registers for bank x (FMC_BCRx)<br>reset value.                                                                                                                                                                                                                                                                                                                                                                                               |
|             |               | Section 24: Quad-SPI interface (QUADSPI)<br>Changed status polling mode to Automatic status-polling.<br>Updated Section : Triggering the start of a command.                                                                                                                                                                                                                                                                                                                                                                             |
|             |               | Section 25: Delay block (DLYB)<br>Updated Section 25.3.4: Delay line length configuration procedure and<br>Section 25.3.5: Output clock phase configuration procedure.                                                                                                                                                                                                                                                                                                                                                                   |

![](_page_17_Picture_3.jpeg)

RM0399 Rev 4 3531/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                      |
|-------------|---------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 26: Analog-to-digital converters (ADC)                                                                                                                                                                                                               |
|             |               | Added Section : Constraints between ADC clocks.                                                                                                                                                                                                              |
|             |               | Updated Section : I/O analog switch voltage booster.                                                                                                                                                                                                         |
|             |               | Updated Figure 175: Example of overrun (OVRMOD = 0), Figure 181: AUTDLY=1<br>in auto- injected mode (JAUTO=1), Figure 190: Regular and injected oversampling<br>modes used simultaneously, and Figure 191: Triggered regular oversampling with<br>injection. |
|             |               | Updated Section : DMA one shot mode (DMNGT=01) to change the DMA interrupt<br>name to transfer complete interrupt.                                                                                                                                           |
|             |               | Removed note on high shifting values in Section : Single ADC operating modes<br>support when oversampling.                                                                                                                                                   |
|             |               | Replaced ADCx_CCR by ADCx_CDR in Section : Regular simultaneous mode with<br>independent injected.                                                                                                                                                           |
|             |               | Updated temperature calculation formula in Section : Reading the temperature.                                                                                                                                                                                |
|             |               | Section 27: Digital-to-analog converter (DAC)                                                                                                                                                                                                                |
|             |               | Updated Section 27.2: DAC main features and changed OTRIMx[5:0] into                                                                                                                                                                                         |
|             |               | OTRIMx[4:0] in In Figure 212: Dual-channel DAC block diagram.                                                                                                                                                                                                |
|             |               | In TSEL1/2 of DAC control register (DAC_CR), changed internal trigger signal<br>names from dac_ch1_trigx/dac_ch2_trigx to dac_ch1_trgx/dac_ch2_trgx.                                                                                                         |
| 16-Jun-2023 | 4 (continued) | Section 28: Voltage reference buffer (VREFBUF)                                                                                                                                                                                                               |
|             |               | Updated Section 28.2: VREFBUF functional description.                                                                                                                                                                                                        |
|             |               | Updated VRS[2:0] of VREFBUF control and status register (VREFBUF_CSR).<br>Updated TRIM[5:0] of VREFBUF calibration control register (VREFBUF_CCR).                                                                                                           |
|             |               | Section 29: Comparator (COMP)                                                                                                                                                                                                                                |
|             |               | Comparator interrupt clear flag register (COMP_ICFR): changed CC2IF/CC1IF<br>access type to rc_w1 and updated address offset to 0x04.                                                                                                                        |
|             |               | Section 30: Operational amplifiers (OPAMP)                                                                                                                                                                                                                   |
|             |               | Updated rail-to-rail feature in Section 30.2: OPAMP main features.                                                                                                                                                                                           |
|             |               | Section 31: Digital filter for sigma delta modulators (DFSDM)                                                                                                                                                                                                |
|             |               | Removed indication of ID registers support in Section 31.3: DFSDM<br>implementation.                                                                                                                                                                         |
|             |               | Section 33: LCD-TFT display controller (LTDC)                                                                                                                                                                                                                |
|             |               | Updated:                                                                                                                                                                                                                                                     |
|             |               | – Figure 250: LTDC block diagram<br>– Section 33.3.2: LTDC pins and internal signals                                                                                                                                                                         |
|             |               | – Figure 252: Layer window programmable parameters                                                                                                                                                                                                           |
|             |               | – Example of synchronous timings configuration                                                                                                                                                                                                               |

3532/3556 RM0399 Rev 4

**Table 657. Document revision history (continued)**

![](_page_19_Picture_3.jpeg)

RM0399 Rev 4 3533/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                             |
|-------------|---------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 40: Advanced-control timers (TIM1/TIM8)                                                                                                                                                                                     |
|             | 4 (continued) | Updated Figure 409: Control circuit in normal mode, internal clock divided by 1,<br>Figure 413: Control circuit in external clock mode 2, Figure 415: Capture/compare<br>channel 1 main circuit.                                    |
|             |               | Updated Section 40.3.16: Using the break function, Section 40.3.18: Clearing the<br>OCxREF signal on an external event, and Section 40.3.22: Encoder interface mode.<br>Section 40.4: TIM1/TIM8 registers:                          |
|             |               | – Updated TIMx control register 1 (TIMx_CR1)(x = 1, 8) and TIMx control register 2<br>(TIMx_CR2)(x = 1, 8).                                                                                                                         |
|             |               | – Updated TIMx capture/compare mode register 1 [alternate] (TIMx_CCMR1)(x = 1,<br>8).                                                                                                                                               |
|             |               | – Updated Table 354: Output control bits for complementary OCx and OCxN<br>channels with break feature.                                                                                                                             |
|             |               | – Updated TIM1 alternate function option register 1 (TIM1_AF1), TIM1 Alternate<br>function register 2 (TIM1_AF2), TIM8 Alternate function option register 1<br>(TIM8_AF1) and TIM8 Alternate function option register 2 (TIM8_AF2). |
|             |               | Section 41: General-purpose timers (TIM2/TIM3/TIM4/TIM5)                                                                                                                                                                            |
| 16-Jun-2023 |               | Updated Figure 470: Control circuit in external clock mode 2, Figure 472:<br>Capture/Compare channel 1 main circuit, and Figure 473: Output stage of<br>Capture/Compare channel (channel 1).                                        |
|             |               | Updated Section 41.3.12: Clearing the OCxREF signal on an external event.                                                                                                                                                           |
|             |               | Update note below Figure 490: Master/slave connection example with 1 channel<br>only timers.                                                                                                                                        |
|             |               | Section 41.4: TIM2/TIM3/TIM4/TIM5 registers: updated TIMx control register 2<br>(TIMx_CR2)(x = 2 to 5), and TIMx capture/compare mode register 1 [alternate]<br>(TIMx_CCMR1) (x = 2 to 5).                                          |
|             |               | Section 42: General-purpose timers (TIM12/TIM13/TIM14)                                                                                                                                                                              |
|             |               | Updated Figure 497: General-purpose timer block diagram (TIM13/TIM14),<br>Figure 510: Capture/compare channel 1 main circuit, and Figure 511: Output stage<br>of capture/compare channel (channel 1).                               |
|             |               | Updated Section 42.3.6: PWM input mode (only for TIM12).                                                                                                                                                                            |
|             |               | Added Section 42.3.18: Using timer output as trigger for other timers<br>(TIM13/TIM14).                                                                                                                                             |
|             |               | Section 42.4: TIM12 registers: updated TIM12 control register 2 (TIM12_CR2),<br>TIM12 capture/compare mode register 1 [alternate] (TIM12_CCMR1), TIM12<br>capture/compare enable register (TIM12_CCER).                             |
|             |               | Section 42.5: TIM13/TIM14 registers: updated TIMx capture/compare mode register<br>1 (TIMx_CCMR1)(x = 13 to 14), TIMx capture/compare enable register<br>(TIMx_CCER)(x = 13 to 14)                                                  |

![](_page_20_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

|               | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            |
|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Revision      |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
|               | Section 43: General-purpose timers (TIM15/TIM16/TIM17)<br>Updated Figure 523: TIM16/TIM17 block diagram, Figure 537: Capture/compare<br>channel 1 main circuit, and Figure 538: Output stage of capture/compare channel<br>(channel 1).<br>Added Section 43.4.14: 6-step PWM generation<br>Added Section 43.4.23: Using timer output as trigger for other timers<br>(TIM16/TIM17).<br>Section 43.5: TIM15 registers:<br>– Updated TIM15 control register 2 (TIM15_CR2), TIM15 capture/compare mode |
|               | register 1 (TIM15_CCMR1).<br>– Added CC2DE bit in TIM15 DMA/interrupt enable register (TIM15_DIER).<br>– Updated TIM15 capture/compare mode register 1 [alternate] (TIM15_CCMR1) on                                                                                                                                                                                                                                                                                                                |
|               | page 1958.<br>– Updated Table 367: Output control bits for complementary OCx and OCxN<br>channels with break feature (TIM15)                                                                                                                                                                                                                                                                                                                                                                       |
|               | Section 43.6: TIM16/TIM17 registers:<br>– Updated TIMx capture/compare mode register 1 [alternate] (TIMx_CCMR1)(x =                                                                                                                                                                                                                                                                                                                                                                                |
|               | 16 to 17).                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         |
|               | – Updated Table 369: Output control bits for complementary OCx and OCxN<br>channels with break feature (TIM16/17)                                                                                                                                                                                                                                                                                                                                                                                  |
| 4 (continued) | Section 45: Low-power timer (LPTIM)<br>Updated Section 45.2: LPTIM main features, Section 45.4.4: LPTIM reset and<br>clocks.                                                                                                                                                                                                                                                                                                                                                                       |
|               | Added note to Section 45.4.7: Trigger multiplexer.<br>Updated Section 45.4.15: Encoder mode.<br>Updated CMPM bit description in LPTIM interrupt and status register (LPTIM_ISR).<br>Updated LPTIM configuration register (LPTIM_CFGR) and LPTIM interrupt clear<br>register (LPTIM_ICR).                                                                                                                                                                                                           |
|               | Section 47: System window watchdog (WWDG)                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
|               | Updated Section 47.3: WWDG functional description introduction, Section Figure<br>576.: Watchdog block diagram, and Section 47.3.4: Controlling the down-counter.<br>Updated Section 47.4: WWDG interrupts, and Section 47.5.2: WWDG configuration<br>register (WWDG_CFR).                                                                                                                                                                                                                         |
|               | Section 49: Real-time clock (RTC)<br>Updated Section : Alarm output, and Section 29.7.4: RTC initialization and status<br>register (RTC_ISR).                                                                                                                                                                                                                                                                                                                                                      |
|               | Section 50: Inter-integrated circuit (I2C) interface<br>Updated Section 50.4: I2C functional description introduction.                                                                                                                                                                                                                                                                                                                                                                             |
|               | Updated Section 50.4.3: I2C clock requirements and Section : I2C timings.<br>Updated I2C control register 2 (I2C_CR2), I2C timing register (I2C_TIMINGR), I2C<br>timeout register (I2C_TIMEOUTR), I2C interrupt and status register (I2C_ISR), I2C<br>interrupt clear register (I2C_ICR), I2C PEC register (I2C_PECR).                                                                                                                                                                             |
|               |                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |

![](_page_21_Picture_3.jpeg)

RM0399 Rev 4 3535/3556

**Table 657. Document revision history (continued)**

| Date<br>Revision                 |
|----------------------------------|
| 4<br>16-Jun-2023<br>(co.ntinued) |

3536/3556 RM0399 Rev 4

![](_page_22_Picture_4.jpeg)

**Table 657. Document revision history (continued)**

| Date<br>Revision<br>16-Jun-2023<br>4 (continued) |
|--------------------------------------------------|

![](_page_23_Picture_3.jpeg)

RM0399 Rev 4 3537/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                              |
|-------------|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|             |               | Section 59: Controller area network with flexible data rate (FDCAN)<br>Updated Section 59.4.6: Application. Modified Section Figure 777.: Transceiver<br>delay measurement.                                                                                                                                                                                                                                                                          |
|             |               | Updated FDCAN data bit timing and prescaler register (FDCAN_DBTP), and<br>FDCAN CC control register (FDCAN_CCCR).                                                                                                                                                                                                                                                                                                                                    |
|             |               | Added Section 59.5.47: FDCAN register map and Section 59.5: FDCAN registers.                                                                                                                                                                                                                                                                                                                                                                         |
|             |               | Section 60: USB on-the-go high-speed (OTG_HS)                                                                                                                                                                                                                                                                                                                                                                                                        |
|             |               | Updated Section 60.4.3: OTG_HS core, Section 60.4.4: Embedded full-speed OTG<br>PHY connected to OTG_HS.                                                                                                                                                                                                                                                                                                                                             |
|             |               | Added Section 60.4.5: OTG detections.                                                                                                                                                                                                                                                                                                                                                                                                                |
|             |               | Updated Section 60.4.6: High-speed OTG PHY connected to OTG_HS and<br>Section 60.5: OTG_HS dual role device (DRD).                                                                                                                                                                                                                                                                                                                                   |
|             |               | Added Figure 795: OTG_HS peripheral-only connection and Figure 796: OTG_HS<br>host-only connection.                                                                                                                                                                                                                                                                                                                                                  |
|             |               | Section 60.14: OTG_HS registers:                                                                                                                                                                                                                                                                                                                                                                                                                     |
|             |               | – Updated Table 540: TRDT values.<br>– Added ODDFRM bit in OTG host channel x characteristics register                                                                                                                                                                                                                                                                                                                                               |
|             |               | (OTG_HCCHARx).                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| 16-Jun-2023 | 4 (continued) | Section 61: Ethernet (ETH): media access control (MAC) with DMA controller<br>Updated Section 61.1: Ethernet introduction,Section 61.2: Ethernet main features,<br>Section 61.3: Ethernet pins and internal signals, Figure 824: Ethernet high-level<br>block diagram.                                                                                                                                                                               |
|             |               | Updated step 9 of DMA reception sequence in Section : DMA reception. Added<br>Section : Priority scheme for Tx DMA and Rx DMA.                                                                                                                                                                                                                                                                                                                       |
|             |               | Updated Section 61.5.1: Double VLAN processing, Section 61.5.2: Source address<br>and VLAN insertion, replacement, or deletion, Section 61.5.3: Packet filtering,<br>Section 61.5.4: IEEE 1588 timestamp support, Section 61.5.5: Checksum offload<br>engine, Section 61.5.6: TCP segmentation offload, Section 61.5.7: IPv4 ARP<br>offload, Section 61.5.8: Loopback, Section 61.5.9: Flow control and<br>Section 61.5.10: MAC management counters. |
|             |               | Updated Section : SMA functional overview, Section : MII management write<br>operations, Section : MII management read operation, and Section : Preamble<br>suppression.                                                                                                                                                                                                                                                                             |
|             |               | Updated Section 61.6.2: Media independent interface (MII) and Section 61.6.3:<br>Reduced media independent interface (RMII).                                                                                                                                                                                                                                                                                                                         |
|             |               | Updated Section 61.7: Ethernet low-power modes.                                                                                                                                                                                                                                                                                                                                                                                                      |
|             |               | Updated Section 61.9.1: DMA initialization, Section 61.9.3: MAC initialization,<br>Section 61.9.5: Stopping and starting transmission. Added Section 61.9.6:                                                                                                                                                                                                                                                                                         |
|             |               | Programming guidelines for switching to new descriptor list in RxDMA,                                                                                                                                                                                                                                                                                                                                                                                |
|             |               | Section 61.9.7: Programming guidelines for switching the AHB clock frequency, and<br>Section 61.9.10: Programming guidelines for PTP offload feature. Updated<br>Section 61.9.11: Programming guidelines for Energy Efficient Ethernet (EEE),                                                                                                                                                                                                        |
|             |               | Section 61.9.12: Programming guidelines for flexible pulse-per-second (PPS)<br>output, Section 61.9.13: Programming guidelines for TSO and Section 61.9.14:                                                                                                                                                                                                                                                                                          |
|             |               | Programming guidelines to perform VLAN filtering on the receive.                                                                                                                                                                                                                                                                                                                                                                                     |

![](_page_24_Picture_3.jpeg)

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      |
|-------------|---------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 16-Jun-2023 | 4 (continued) | Section 61: Ethernet (ETH): media access control (MAC) with DMA controller<br>(continued)<br>Section 61.10: Descriptors:<br>– Section 61.10.3: Transmit descriptor: updated TDES2 normal descriptor (read<br>format), TDES3 normal descriptor (read format), TDES3 normal descriptor (write<br>back format), TDES3 context descriptor (read format).<br>– Section 61.10.4: Receive descriptor: RDES0 normal descriptor (read format),<br>RDES0 normal descriptor (write-back format), RDES3 normal descriptor (read<br>format), RDES3 normal descriptor (write-back format).<br>Section 61.11.2: Ethernet DMA registers:<br>– DMA mode register (ETH_DMAMR): changed DA bit access type to rw.<br>– Updated System bus mode register (ETH_DMASBMR) reset value.<br>– Updated Channel transmit control register (ETH_DMACTXCR) and Channel<br>receive control register (ETH_DMACRXCR).<br>– Updated TDESLA and RDESLA bitfield descriptions of Channel Tx descriptor list<br>address register (ETH_DMACTXDLAR) and Channel Rx descriptor list address<br>register (ETH_DMACRXDLAR), respectively.<br>– Updated TDT and RDT bitfield descriptions in Channel Tx descriptor tail pointer<br>register (ETH_DMACTXDTPR) and Channel Rx descriptor tail pointer register<br>(ETH_DMACRXDTPR), respectively.<br>– Updated TDRL bitfield descriptions in Channel Tx descriptor ring length register<br>(ETH_DMACTXRLR). Updated Channel Rx descriptor ring length register<br>(ETH_DMACRXRLR).<br>– Channel interrupt enable register (ETH_DMACIER): removed<br>MMCIE/MMCRSIPIS and GPIIS/GPIIE from Figure 859: Generation of<br>ETH_DMAISR flags; updated AIE bit description.<br>– Added RWU bitfield in Channel Rx interrupt watchdog timer register<br>(ETH_DMACRXIWTR).<br>– Channel status register (ETH_DMACSR): changed bit 15:10, 8:6 and 2: 0 access<br>type to rc_w1; updated REB, TEB, AIS, CDE and TBU bit descriptions<br>– Channel missed frame count register (ETH_DMACMFCR): changed all bit access<br>type to rc_r.<br>Section 61.11.3: Ethernet MTL registers<br>– Operating mode Register (ETH_MTLOMR): updated CNTPRST and RAA and<br>DTXSTS bit descriptions.<br>– Updated Tx queue operating mode Register (ETH_MTLTXQOMR).<br>– Updated Tx queue underflow register (ETH_MTLTXQUR) bit access type.<br>– Updated Tx queue debug register (ETH_MTLTXQDR).<br>– Updated Rx queue operating mode register (ETH_MTLRXQOMR).<br>– Updated Rx queue missed packet and overflow counter register<br>(ETH_MTLRXQMPOCR) access type. |

![](_page_25_Picture_3.jpeg)

RM0399 Rev 4 3539/3556

**Table 657. Document revision history (continued)**

| Date        | Revision      | Changes                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
|-------------|---------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 16-Jun-2023 | 4 (continued) | Section 61: Ethernet (ETH): media access control (MAC) with DMA controller<br>(continued)<br>Section 61.11.4: Ethernet MAC and MMC registers<br>– Updated Operating mode configuration register (ETH_MACCR), Extended<br>operating mode configuration register (ETH_MACECR), Packet filtering control<br>register (ETH_MACPFR), and Watchdog timeout register (ETH_MACWTR).<br>– Updated Hash Table 0 register (ETH_MACHT0R) and Hash Table 1 register<br>(ETH_MACHT1R).<br>– Updated VLAN tag register (ETH_MACVTR), VLAN Hash table register<br>(ETH_MACVHTR), VLAN inclusion register (ETH_MACVIR) and VLAN inclusion<br>register (ETH_MACVIR).<br>– Updated Tx Queue flow control register (ETH_MACQTXFCR) and Rx flow control<br>register (ETH_MACRXFCR), Interrupt status register (ETH_MACISR), Rx Tx<br>status register (ETH_MACRXTXSR) and PMT control status register<br>(ETH_MACPCSR).<br>– Remote wakeup packet filter register (ETH_MACRWKPFR): moved Table:<br>Remote wakeup packet filter register to Section : Description of remote wakeup<br>packet mode<br>– Updated LPI control and status register (ETH_MACLCSR)<br>– Updated Version register (ETH_MACVR) reset value.<br>– Added HW feature 0 register (ETH_MACHWF0R), updated HW feature 1 register<br>(ETH_MACHWF1R), and HW feature 2 register (ETH_MACHWF2R).<br>– Updated MAC Address x high register (ETH_MACAxHR).<br>– Updated MMC Rx interrupt register (ETH_MMC_RX_INTERRUPT), MMC Tx<br>interrupt register (ETH_MMC_TX_INTERRUPT), MMC Rx interrupt mask register<br>(ETH_MMC_RX_INTERRUPT_MASK) and MMC Tx interrupt mask register<br>(ETH_MMC_TX_INTERRUPT_MASK).<br>– Updated L3 and L4 control 0 register (ETH_MACL3L4C0R) to Layer3 address 3<br>filter 1 register (ETH_MACL3A31R).<br>– Timestamp control Register (ETH_MACTSCR): moved Table Timestamp<br>snapshot dependency on register bits to Section : Clock types, updated TSUPDT<br>and TSINIT bit descriptions.<br>– Updated Subsecond increment register (ETH_MACSSIR), System time<br>nanoseconds register (ETH_MACSTNR), System time seconds update register<br>(ETH_MACSTSUR), System time nanoseconds update register<br>(ETH_MACSTNUR), Timestamp addend register (ETH_MACTSAR), and<br>Timestamp status register (ETH_MACTSSR).<br>– Modified Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) bit<br>access type.<br>– Updated Auxiliary control register (ETH_MACACR).<br>Section 63: Debug infrastructure<br>Replaced Cortex-M7 with Cortex-M4 in DBGMCU APB4 peripheral freeze register<br>CPU2 (DBGMCU_APB4FZ2). Updated bit 20 description in Section : DBGMCU<br>configuration register (DBGMCU_CR). Replaced PRESCALER - 1 with<br>PRESCALER +1 in the description of PRESCALER[12:0] bits (SWO current output<br>divisor register (SWO_CODR))<br>Section 64: Device electronic signature<br>Updated Section 64.1: Unique device ID register (96 bits); added Section 64.3: Line<br>identifier.<br>Added Section 65: Important security notice. |

3540/3556 RM0399 Rev 4

![](_page_26_Picture_4.jpeg)

**RM0399 Index**

## **Index**

| A                      | AXI_PERIPH_ID_3 119         |
|------------------------|-----------------------------|
| ADC_AWD2CR1062         | AXI_PERIPH_ID_4 117         |
| ADC_AWD3CR1063         | AXI_TARGx_FN_MOD 123        |
| ADC_CALFACT1066        | AXI_TARGx_FN_MOD_ISS_BM 121 |
| ADC_CALFACT21066       | AXI_TARGx_FN_MOD_LB 122     |
| ADC_CFGR1044           | AXI_TARGx_FN_MOD2 122       |
| ADC_CFGR21048          |                             |
| ADC_CR1039             | B                           |
|                        |                             |
| ADC_DIFSEL1065         | BDMA_CCRx 722               |
| ADC_DR1058             | BDMA_CM0ARx 727             |
| ADC_HTR11053           | BDMA_CM1ARx 728             |
| ADC_HTR21064           | BDMA_CNDTRx 726             |
| ADC_HTR31065           | BDMA_CPARx 726              |
| ADC_IER1037            | BDMA_IFCR 721               |
| ADC_ISR1034            | BDMA_ISR 718                |
| ADC_JDRy1062           |                             |
| ADC_JSQR1059           | C                           |
| ADC_LTR11052           |                             |
| ADC_LTR21063           | CEC_CFGR 3219               |
| ADC_LTR31064           | CEC_CR 3218                 |
| ADC_OFRy1061           | CEC_IER 3223                |
| ADC_PCSEL1052          | CEC_ISR 3221                |
| ADC_SMPR11050          | CEC_RXDR 3221               |
| ADC_SMPR21051          | CEC_TXDR 3221               |
| ADC_SQR11054           | COMP_CFGR1 1127             |
| ADC_SQR21055           | COMP_CFGR2 1129             |
| ADC_SQR31056           | COMP_ICFR 1126              |
| ADC_SQR41057           | COMP_OR 1127                |
| ADCx_CCR1069           | COMP_SR 1126                |
| ADCx_CDR1072           | CRC_CR 834                  |
| ADCx_CDR21072          | CRC_DR 833                  |
| ADCx_CSR1067           | CRC_IDR 833                 |
| AP_BASE3250            | CRC_INIT 835                |
| AP_CSW3249             | CRC_POL 835                 |
| AP_IDR3251             | CRS_CFGR 549                |
| ART_CTR266             | CRS_CR 548                  |
| AXI_COMP_ID_0119       | CRS_ICR 551                 |
| AXI_COMP_ID_1120       | CRS_ISR 550                 |
| AXI_COMP_ID_2120       | CRYP_CR 1463                |
| AXI_COMP_ID_3121       | CRYP_CSGCMCCMxR 1476        |
| AXI_INIx_FN_MOD125     | CRYP_CSGCMxR 1477           |
| AXI_INIx_FN_MOD_AHB124 | CRYP_DIN 1466               |
| AXI_INIx_FN_MOD2123    | CRYP_DMACR 1468             |
| AXI_INIx_READ_QOS124   | CRYP_DOUT 1467              |
| AXI_INIx_WRITE_QOS125  |                             |
| AXI_PERIPH_ID_0117     | CRYP_IMSCR 1468             |
| AXI_PERIPH_ID_1118     | CRYP_IV0LR 1474             |
| AXI_PERIPH_ID_2118     | CRYP_IV0RR 1475             |
|                        | CRYP_IV1LR 1475             |

![](_page_27_Picture_3.jpeg)

**Index RM0399**

| CRYP_IV1RR1476    | CTI_PIDR1 3286       |
|-------------------|----------------------|
| CRYP_K0LR1470     | CTI_PIDR2 3286       |
| CRYP_K0RR1471     | CTI_PIDR3 3287       |
| CRYP_K1LR1471     | CTI_PIDR4 3285       |
| CRYP_K1RR1472     | CTI_TRGISTS 3279     |
| CRYP_K2LR1472     | CTI_TRGOSTS 3279     |
| CRYP_K2RR1473     |                      |
| CRYP_K3LR1473     |                      |
| CRYP_K3RR1474     | D                    |
| CRYP_MISR1470     | DAC_CCR 1108         |
|                   | DAC_CR 1097          |
| CRYP_RISR1469     | DAC_DHR12L1 1101     |
| CRYP_SR1465       | DAC_DHR12L2 1103     |
| CSTF_AUTHSTAT3295 | DAC_DHR12LD 1104     |
| CSTF_CIDR03298    | DAC_DHR12R1 1101     |
| CSTF_CIDR13299    |                      |
| CSTF_CIDR23299    | DAC_DHR12R2 1102     |
| CSTF_CIDR33299    | DAC_DHR12RD 1104     |
| CSTF_CLAIMCLR3293 | DAC_DHR8R1 1102      |
| CSTF_CLAIMSET3293 | DAC_DHR8R2 1103      |
| CSTF_CTRL3291     | DAC_DHR8RD 1105      |
| CSTF_DEVID3295    | DAC_DOR1 1105        |
| CSTF_DEVTYPE3296  | DAC_DOR2 1106        |
| CSTF_LAR3294      | DAC_MCR 1108         |
| CSTF_LSR3294      | DAC_SHHR 1111        |
| CSTF_PIDR03296    | DAC_SHRR 1111        |
| CSTF_PIDR13297    | DAC_SHSR1 1110       |
| CSTF_PIDR23297    | DAC_SHSR2 1110       |
| CSTF_PIDR33298    | DAC_SR 1106          |
| CSTF_PIDR43296    | DAC_SWTRGR 1100      |
| CSTF_PRIORITY3292 | DBGMCU_APB1LFZ1 3367 |
| CTI_APPCLEAR3276  | DBGMCU_APB1LFZ2 3368 |
| CTI_APPPULSE3277  | DBGMCU_APB2FZ1 3370  |
| CTI_APPSET3276    | DBGMCU_APB2FZ2 3371  |
|                   | DBGMCU_APB3FZ1 3366  |
| CTI_AUTHSTAT3283  | DBGMCU_APB3FZ2 3367  |
| CTI_CHINSTS3280   | DBGMCU_APB4FZ1 3372  |
| CTI_CHOUTSTS3280  | DBGMCU_APB4FZ2 3373  |
| CTI_CIDR03287     |                      |
| CTI_CIDR13287     | DBGMCU_CR 3365       |
| CTI_CIDR23288     | DBGMCU_IDC 3364      |
| CTI_CIDR33288     | DCMI_CR 1222         |
| CTI_CLAIMCLR3282  | DCMI_CWSIZE 1230     |
| CTI_CLAIMSET3281  | DCMI_CWSTRT 1230     |
| CTI_CONTROL3275   | DCMI_DR 1231         |
| CTI_DEVID3284     | DCMI_ESCR 1228       |
| CTI_DEVTYPE3284   | DCMI_ESUR 1229       |
| CTI_GATE3281      | DCMI_ICR 1228        |
| CTI_INENx3277     | DCMI_IER 1226        |
| CTI_INTACK3275    | DCMI_MIS 1227        |
| CTI_LAR3282       | DCMI_RIS 1225        |
| CTI_LSR3283       | DCMI_SR 1224         |
| CTI_OUTENx3278    | DFSDM_CHyAWSCDR 1184 |
| CTI_PIDR03285     | DFSDM_CHyCFGR1 1181  |
|                   |                      |

**RM0399 Index**

| DFSDM_CHyCFGR21183    | DMAMUX_CxCR 744   |  |
|-----------------------|-------------------|--|
| DFSDM_CHyDATINR1185   | DMAMUX_RGCFR 750  |  |
| DFSDM_CHyWDATR1185    | DMAMUX1_CFR 747   |  |
| DFSDM_FLTxAWCFR1198   | DMAMUX1_CSR 746   |  |
| DFSDM_FLTxAWHTR1196   | DMAMUX1_CxCR 744  |  |
| DFSDM_FLTxAWLTR1196   | DMAMUX1_RGCFR 750 |  |
| DFSDM_FLTxAWSR1197    | DMAMUX1_RGSR 749  |  |
| DFSDM_FLTxCNVTIMR1199 | DMAMUX1_RGxCR 748 |  |
| DFSDM_FLTxCR11186     | DMAMUX2_CFR 747   |  |
| DFSDM_FLTxCR21189     | DMAMUX2_CSR 746   |  |
| DFSDM_FLTxEXMAX1198   | DMAMUX2_CxCR 745  |  |
| DFSDM_FLTxEXMIN1199   | DMAMUX2_RGCFR 751 |  |
| DFSDM_FLTxFCR1193     | DMAMUX2_RGSR 750  |  |
| DFSDM_FLTxICR1192     | DMAMUX2_RGxCR 748 |  |
| DFSDM_FLTxISR1190     | DP_ABORT 3239     |  |
| DFSDM_FLTxJCHGR1193   | DP_CTRL/STAT 3240 |  |
| DFSDM_FLTxJDATAR1194  | DP_DLCR 3242      |  |
| DFSDM_FLTxRDATAR1195  | DP_DLPIDR 3243    |  |
| DLYB_CFGR950          | DP_DPIDR 3238     |  |
| DLYB_CR950            | DP_RDBUFF 3245    |  |
| DMA_HIFCR697          | DP_RESEND 3244    |  |
| DMA_HISR696           | DP_SELECT 3244    |  |
| DMA_LIFCR697          | DP_TARGETID 3243  |  |
| DMA_LISR695           | DP_TARGETSEL 3246 |  |
| DMA_SxCR698           | DSI_CCR 1326      |  |
| DMA_SxFCR703          | DSI_CLCR 1343     |  |
| DMA_SxM0AR702         | DSI_CLTCR 1343    |  |
| DMA_SxM1AR702         | DSI_CMCR 1336     |  |
| DMA_SxNDTR701         | DSI_CR 1326       |  |
| DMA_SxPAR701          | DSI_DLTCR 1344    |  |
| DMA2D_AMTCR785        | DSI_FIR0 1354     |  |
| DMA2D_BGCLUTx786      | DSI_FIR1 1355     |  |
| DMA2D_BGCMAR779       | DSI_GHCR 1338     |  |
| DMA2D_BGCOLR778       | DSI_GPDR 1339     |  |
| DMA2D_BGMAR774        | DSI_GPSR 1339     |  |
| DMA2D_BGOR774         | DSI_GVCIDR 1330   |  |
| DMA2D_BGPFCCR777      | DSI_IER0 1350     |  |
| DMA2D_CR770           | DSI_IER1 1352     |  |
| DMA2D_FGCLUTx785      | DSI_ISR0 1347     |  |
| DMA2D_FGCMAR779       | DSI_ISR1 1349     |  |
| DMA2D_FGCOLR776       | DSI_LCCCR 1357    |  |
|                       |                   |  |
| DMA2D_FGMAR773        | DSI_LCCR 1336     |  |
| DMA2D_FGOR773         | DSI_LCOLCR 1327   |  |
| DMA2D_FGPFCCR775      | DSI_LCVCIDR 1357  |  |
| DMA2D_IFCR772         | DSI_LPCR 1328     |  |
| DMA2D_ISR771          | DSI_LPMCCR 1358   |  |
| DMA2D_LWR784          | DSI_LPMCR 1328    |  |
| DMA2D_NLR784          | DSI_LVCIDR 1327   |  |
| DMA2D_OCOLR 781-782   | DSI_MCR 1330      |  |
| DMA2D_OMAR783         | DSI_PCONFR 1345   |  |
| DMA2D_OOR783          | DSI_PCR 1329      |  |
| DMA2D_OPFCCR780       | DSI_PCTLR 1344    |  |

**Index RM0399**

| DSI_PSR1346      | ETF_CIDR2 3320      |
|------------------|---------------------|
| DSI_PTTCR1346    | ETF_CIDR3 3320      |
| DSI_PUCR1345     | ETF_CLAIMCLR 3314   |
| DSI_TCCR01340    | ETF_CLAIMSET 3314   |
| DSI_TCCR11341    | ETF_CTL 3307        |
| DSI_TCCR21341    | ETF_DEVID 3316      |
| DSI_TCCR31341    | ETF_DEVTYPE 3317    |
| DSI_TCCR41342    | ETF_FFCR 3311       |
| DSI_TCCR51342    | ETF_FFSR 3310       |
| DSI_VCCCR1360    | ETF_LAR 3315        |
| DSI_VCCR1332     | ETF_LBUFLVL 3309    |
| DSI_VHBPCCR1361  | ETF_LSR 3315        |
| DSI_VHBPCR1334   | ETF_MODE 3308       |
| DSI_VHSACCR1361  | ETF_PIDR0 3318      |
| DSI_VHSACR1333   | ETF_PIDR1 3318      |
|                  |                     |
| DSI_VLCCR1361    | ETF_PIDR2 3318      |
| DSI_VLCR1334     | ETF_PIDR3 3319      |
| DSI_VMCCR1358    | ETF_PIDR4 3317      |
| DSI_VMCR1330     | ETF_PSCR 3313       |
| DSI_VNPCCR1360   | ETF_RRD 3305        |
| DSI_VNPCR1333    | ETF_RRP 3306        |
| DSI_VPCCR1359    | ETF_RSZ 3304        |
| DSI_VPCR1332     | ETF_RWD 3308        |
| DSI_VR1326       | ETF_RWP 3306        |
| DSI_VSCR1356     | ETF_STS 3304        |
| DSI_VVACCR1363   | ETF_TRG 3307        |
| DSI_VVACR1335    | ETH_DMACCARXBR 3093 |
| DSI_VVBPCCR1362  | ETH_DMACCARXDR 3092 |
| DSI_VVBPCR1335   | ETH_DMACCATXBR 3093 |
| DSI_VVFPCCR1363  | ETH_DMACCATXDR 3092 |
| DSI_VVFPCR1335   | ETH_DMACCR 3078     |
| DSI_VVSACCR1362  | ETH_DMACIER 3087    |
| DSI_VVSACR1334   | ETH_DMACMFCR 3096   |
| DSI_WCFGR1364    | ETH_DMACRXCR 3081   |
| DSI_WCR1365      | ETH_DMACRXDLAR 3084 |
| DSI_WIER1365     | ETH_DMACRXDTPR 3086 |
| DSI_WIFCR1367    | ETH_DMACRXIWTR 3091 |
| DSI_WISR1366     | ETH_DMACRXRLR 3087  |
| DSI_WPCR01368    | ETH_DMACSR 3093     |
| DSI_WPCR11370    | ETH_DMACTXCR 3079   |
| DSI_WPCR21372    | ETH_DMACTXDLAR 3083 |
| DSI_WPCR31373    | ETH_DMACTXDTPR 3085 |
| DSI_WPCR41373    | ETH_DMACTXRLR 3086  |
| DSI_WRPCR1374    | ETH_DMADSR 3077     |
|                  | ETH_DMAISR 3077     |
|                  | ETH_DMAMR 3074      |
| E                |                     |
| ETF_AUTHSTAT3316 | ETH_DMASBMR 3076    |
| ETF_BUFWM3310    | ETH_MAC1USTCR 3140  |
| ETF_CBUFLVL3309  | ETH_MACA0HR 3153    |
|                  | ETH_MACACR 3185     |
| ETF_CIDR03319    | ETH_MACARPAR 3152   |
| ETF_CIDR13320    | ETH_MACATSNR 3186   |

**RM0399 Index**

| ETH_MACATSSR3186       | ETH_MACSTSR 3180                       |
|------------------------|----------------------------------------|
| ETH_MACAxHR3155        | ETH_MACSTSUR 3181                      |
| ETH_MACAxLR3154        | ETH_MACTSAR 3182                       |
| ETH_MACCR3112          | ETH_MACTSCR 3176                       |
| ETH_MACCSRSWCR3153     | ETH_MACTSEACR 3187                     |
| ETH_MACDR3141          | ETH_MACTSECNR 3188                     |
| ETH_MACECR3117         | ETH_MACTSIACR 3187                     |
| ETH_MACHT0R3121        | ETH_MACTSICNR 3188                     |
| ETH_MACHT1R3122        | ETH_MACTSSR 3183                       |
| ETH_MACHWF0R3142       | ETH_MACTXTSSNR 3184                    |
| ETH_MACHWF1R3144       | ETH_MACTXTSSSR 3185                    |
| ETH_MACHWF2R3147       | ETH_MACVHTR 3125                       |
| ETH_MACHWF3R3149       | ETH_MACVIR 3126                        |
| ETH_MACIER3133         | ETH_MACVR 3141                         |
| ETH_MACISR3131         | ETH_MACVTR 3123                        |
| ETH_MACIVIR3127        | ETH_MACWTR 3120                        |
| ETH_MACL3A00R3169      | ETH_MMC_CONTROL 3156                   |
| ETH_MACL3A01R3174      | ETH_MMC_RX_INTERRUPT 3157              |
| ETH_MACL3A10R3169      | ETH_MMC_RX_INTERRUPT_MASK 3160         |
| ETH_MACL3A11R3174      | ETH_MMC_TX_INTERRUPT 3158              |
| ETH_MACL3A20R3170      | ETH_MMC_TX_INTERRUPT_MASK 3161         |
| ETH_MACL3A21R3175      | ETH_MTLISR 3101                        |
| ETH_MACL3A30R3170      | ETH_MTLOMR 3100                        |
| ETH_MACL3A31R3175      | ETH_MTLQICSR 3104                      |
| ETH_MACL3L4C0R3166     | ETH_MTLRXQDR 3109                      |
| ETH_MACL3L4C1R3171     | ETH_MTLRXQMPOCR 3108                   |
| ETH_MACL4A0R3168       | ETH_MTLRXQOMR 3106                     |
| ETH_MACL4A1R3173       | ETH_MTLTXQDR 3103                      |
| ETH_MACLCSR3137        | ETH_MTLTXQOMR 3101                     |
| ETH_MACLETR3140        | ETH_MTLTXQUR 3102                      |
| ETH_MACLMIR3196        | ETH_RX_ALIGNMENT_ERROR_PACKETS         |
| ETH_MACLTCR3139        | 3163                                   |
| ETH_MACMDIOAR3150      | ETH_RX_CRC_ERROR_PACKETS 3163          |
| ETH_MACMDIODR3152      | ETH_RX_LPI_TRAN_CNTR 3165              |
| ETH_MACPCSR3135        | ETH_RX_LPI_USEC_CNTR 3165              |
| ETH_MACPFR3118         | ETH_RX_UNICAST_PACKETS_GOOD 3164       |
| ETH_MACPOCR3194        | ETH_TX_LPI_TRAN_CNTR 3165              |
| ETH_MACPPSCR3188, 3190 | ETH_TX_LPI_USEC_CNTR 3164              |
| ETH_MACPPSIR3192       | ETH_TX_MULTIPLE_COLLISION              |
| ETH_MACPPSTTNR3192     | GOOD_PACKETS 3162                      |
| ETH_MACPPSTTSR3191     | ETH_TX_PACKET_COUNT_GOOD 3163          |
|                        |                                        |
| ETH_MACPPSWR3193       | ETH_TX_SINGLE_COLLISION_GOOD_PACK      |
| ETH_MACQTXFCR3128      | ETS 3162                               |
| ETH_MACRWKPFR3137      | EXTI_EMR 822, 824                      |
| ETH_MACRXFCR3130       | EXTI_FTSR 812, 816, 819                |
| ETH_MACRXTXSR3134      | EXTI_IMR813-814, 817-818, 820-823, 825 |
| ETH_MACSPI0R3194       | EXTI_PR 823-824, 826                   |
| ETH_MACSPI1R3195       | EXTI_RTSR 812, 815, 819                |
| ETH_MACSPI2R3195       | EXTI_SWIER 813, 816, 820               |
| ETH_MACSSIR3178        |                                        |
| ETH_MACSTNR3180        |                                        |
| ETH_MACSTNUR3181       |                                        |

**Index RM0399**

| F                   | FDCAN_TTTMK 2724         |  |
|---------------------|--------------------------|--|
|                     | FDCAN_TTTS 2735          |  |
| FDCAN_CCCR2679      | FDCAN_TURCF 2721         |  |
| FDCAN_CCU_CCFG2737  | FDCAN_TURNA 2732         |  |
| FDCAN_CCU_CREL2737  | FDCAN_TXBAR 2708         |  |
| FDCAN_CCU_CSTAT2739 | FDCAN_TXBC 2705          |  |
| FDCAN_CCU_CWD2739   | FDCAN_TXBCF 2710         |  |
| FDCAN_CCU_IE2741    | FDCAN_TXBCIE 2711        |  |
| FDCAN_CCU_IR2740    | FDCAN_TXBCR 2709         |  |
| FDCAN_CREL2676      | FDCAN_TXBRP 2707         |  |
| FDCAN_DBTP2677      |                          |  |
| FDCAN_ECR2685       | FDCAN_TXBTIE 2710        |  |
| FDCAN_ENDN2676      | FDCAN_TXBTO 2709         |  |
| FDCAN_GFC2695       | FDCAN_TXEFA 2713         |  |
| FDCAN_HPMS2698      | FDCAN_TXEFC 2711         |  |
| FDCAN_IE2691        | FDCAN_TXEFS 2712         |  |
| FDCAN_ILE2694       | FDCAN_TXESC 2707         |  |
| FDCAN_ILS2693       | FDCAN_TXFQS 2706         |  |
| FDCAN_IR2688        | FDCAN_XIDAM 2697         |  |
| FDCAN_NBTP2681      | FDCAN_XIDFC 2696         |  |
|                     | FLASH_ACR 208            |  |
| FDCAN_NDAT12698     | FLASH_BOOT7_CURR 228-229 |  |
| FDCAN_NDAT22699     | FLASH_BOOT7_PRGR 229-230 |  |
| FDCAN_PSR2685       | FLASH_CCR1 217           |  |
| FDCAN_RWD2678       | FLASH_CCR2 241           |  |
| FDCAN_RXBC2701      | FLASH_CR1 209            |  |
| FDCAN_RXESC2704     | FLASH_CR2 234            |  |
| FDCAN_RXF0A2701     | FLASH_CRCCR1 230         |  |
| FDCAN_RXF0C2699     | FLASH_CRCCR2 246         |  |
| FDCAN_RXF0S2700     |                          |  |
| FDCAN_RXF1A2704     | FLASH_CRCDATAR 232       |  |
| FDCAN_RXF1C2702     | FLASH_CRCEADD1R 232      |  |
| FDCAN_RXF1S2703     | FLASH_CRCEADD2R 248      |  |
| FDCAN_SIDFC2696     | FLASH_CRCSADD1R 232      |  |
| FDCAN_TDCR2687      | FLASH_CRCSADD2R 247      |  |
| FDCAN_TEST2678      | FLASH_ECC_FA1R 233       |  |
| FDCAN_TOCC2683      | FLASH_ECC_FA2R 248       |  |
| FDCAN_TOCV2684      | FLASH_KEYR1 208          |  |
| FDCAN_TSCC2682      | FLASH_KEYR2 233          |  |
|                     | FLASH_OPTCCR 224         |  |
| FDCAN_TSCV2683      | FLASH_OPTCR 218          |  |
| FDCAN_TTCPT2734     | FLASH_OPTKEYR 209        |  |
| FDCAN_TTCSM2734     | FLASH_OPTSR_CUR 219      |  |
| FDCAN_TTCTC2733     | FLASH_OPTSR_PRG 222      |  |
| FDCAN_TTGTP2724     | FLASH_PRAR_CUR1 225      |  |
| FDCAN_TTIE2727      | FLASH_PRAR_CUR2 242      |  |
| FDCAN_TTILS2729     | FLASH_PRAR_PRG1 225      |  |
| FDCAN_TTIR2725      |                          |  |
| FDCAN_TTLGT2733     | FLASH_PRAR_PRG2 242      |  |
| FDCAN_TTMLM2720     | FLASH_SCAR_CUR1 226      |  |
| FDCAN_TTOCF2718     | FLASH_SCAR_CUR2 243      |  |
| FDCAN_TTOCN2722     | FLASH_SCAR_PRG1 227      |  |
| FDCAN_TTOST2730     | FLASH_SCAR_PRG2 244      |  |
| FDCAN_TTRMC2717     | FLASH_SR1 214            |  |
| FDCAN_TTTMC2717     | FLASH_SR2 238            |  |
|                     |                          |  |

**RM0399 Index**

| FLASH_WPSN_CUR1R227 | HRTIM_CMP1CxR 1612  |
|---------------------|---------------------|
| FLASH_WPSN_CUR2R245 | HRTIM_CMP1xR 1611   |
| FLASH_WPSN_PRG1R228 | HRTIM_CMP2xR 1612   |
| FLASH_WPSN_PRG2R245 | HRTIM_CMP3xR 1613   |
| FMC_BCRx878         | HRTIM_CMP4xR 1613   |
| FMC_BTRx882         | HRTIM_CNTxR 1610    |
| FMC_BWTRx885        | HRTIM_CPT1xCR 1629  |
| FMC_ECCR898         | HRTIM_CPT1xR 1614   |
| FMC_PATT896         | HRTIM_CPT2xCR 1630  |
| FMC_PCR893          | HRTIM_CPT2xR 1614   |
| FMC_PMEM895         | HRTIM_CR1 1637      |
| FMC_SDCMR913        | HRTIM_CR2 1639      |
| FMC_SDCRx910        | HRTIM_DTxR 1615     |
| FMC_SDRTR914        | HRTIM_EECR1 1651    |
| FMC_SDSR916         | HRTIM_EECR2 1653    |
| FMC_SDTRx911        | HRTIM_EECR3 1654    |
| FMC_SR894           | HRTIM_EEFxR1 1621   |
|                     | HRTIM_EEFxR2 1623   |
|                     | HRTIM_FLTINR1 1661  |
| G                   | HRTIM_FLTINR2 1663  |
| GPIOx_AFRH583       | HRTIM_FLTxR 1636    |
| GPIOx_AFRL582       | HRTIM_ICR 1641      |
| GPIOx_BSRR581       | HRTIM_IER 1642      |
| GPIOx_IDR580        | HRTIM_ISR 1640      |
| GPIOx_LCKR581       | HRTIM_MCMP1R 1597   |
| GPIOx_MODER578      | HRTIM_MCMP2R 1598   |
| GPIOx_ODR580        | HRTIM_MCMP3R 1598   |
| GPIOx_OSPEEDR579    | HRTIM_MCMP4R 1599   |
| GPIOx_OTYPER578     | HRTIM_MCNTR 1596    |
| GPIOx_PUPDR579      | HRTIM_MCR 1589      |
|                     | HRTIM_MDIER 1594    |
|                     | HRTIM_MICR 1593     |
| H                   | HRTIM_MISR 1592     |
| HASH_CR1493         | HRTIM_MPER 1596     |
| HASH_CSRx1500       | HRTIM_MREP 1597     |
| HASH_DIN1495        | HRTIM_ODISR 1644    |
| HASH_HRAx1497       | HRTIM_ODSR 1645     |
| HASH_HRx 1497-1498  | HRTIM_OENR 1643     |
| HASH_IMR1498        | HRTIM_OUTxR 1633    |
| HASH_SR1499         | HRTIM_PERxR 1610    |
| HASH_STR1496        | HRTIM_REPxR 1611    |
| HRTIM_ADC1R1655     | HRTIM_RSTAR 1624    |
| HRTIM_ADC2R1656     | HRTIM_RSTBR 1626    |
| HRTIM_ADC3R1657     | HRTIM_RSTCR 1626    |
| HRTIM_ADC4R1659     | HRTIM_RSTDR 1626    |
| HRTIM_BDMADR1667    | HRTIM_RSTER 1627    |
| HRTIM_BDMUPR1665    | HRTIM_RSTx1R 1619   |
| HRTIM_BDTxUPR1666   | HRTIM_RSTx2R 1620   |
| HRTIM_BMCMPR1650    | HRTIM_SETx1R 1617   |
| HRTIM_BMCR1646      | HRTIM_SETx2R 1619   |
| HRTIM_BMPER1650     | HRTIM_TIMxCR 1600   |
| HRTIM_BMTRGR1648    | HRTIM_TIMxDIER 1607 |
| HRTIM_CHPxR1627     |                     |
|                     |                     |

**Index RM0399**

| HRTIM_TIMxICR1606         | LPTIM_CFGR 2029       |  |
|---------------------------|-----------------------|--|
| HRTIM_TIMxISR1604         | LPTIM_CFGR2 2035      |  |
| HSEM_CnICR563             | LPTIM_CMP 2034        |  |
| HSEM_CnIER563             | LPTIM_CNT 2035        |  |
| HSEM_CnISR563             | LPTIM_CR 2032         |  |
| HSEM_CnMISR564            | LPTIM_ICR 2028        |  |
| HSEM_CR564                | LPTIM_IER 2028        |  |
| HSEM_KEYR565              | LPTIM_ISR 2027        |  |
| HSEM_RLRx562              | LPTIM3_CFGR2 2036     |  |
|                           |                       |  |
| HSEM_Rx561                | LPUART_BRR 2296       |  |
|                           | LPUART_CR1 2285, 2288 |  |
| I                         | LPUART_CR2 2291       |  |
|                           | LPUART_CR3 2293       |  |
| I2C_CR12155               | LPUART_ICR 2305       |  |
| I2C_CR22157               | LPUART_ISR 2297, 2302 |  |
| I2C_ICR2165               | LPUART_PRESC 2307     |  |
| I2C_ISR2163               | LPUART_RDR 2306       |  |
| I2C_OAR12159              | LPUART_RQR 2297       |  |
| I2C_OAR22160              | LPUART_TDR 2306       |  |
| I2C_PECR2166              | LTDC_AWCR 1246        |  |
| I2C_RXDR2167              | LTDC_BCCR 1249        |  |
| I2C_TIMEOUTR2162          | LTDC_BPCR 1245        |  |
| I2C_TIMINGR2161           | LTDC_CDSR 1253        |  |
| I2C_TXDR2167              | LTDC_CPSR 1252        |  |
| IWDG_KR2050               | LTDC_GCR 1247         |  |
| IWDG_PR2051               | LTDC_ICR 1251         |  |
| IWDG_RLR2052              | LTDC_IER 1250         |  |
| IWDG_SR2053               | LTDC_ISR 1251         |  |
| IWDG_WINR2054             | LTDC_LIPCR 1252       |  |
|                           | LTDC_LxBFCR 1258      |  |
|                           | LTDC_LxCACR 1257      |  |
| J                         | LTDC_LxCFBAR 1259     |  |
| JPEG_CFR1392              |                       |  |
| JPEG_CONFR01387           | LTDC_LxCFBLNR 1260    |  |
| JPEG_CONFR11387           | LTDC_LxCFBLR 1259     |  |
| JPEG_CONFR21388           | LTDC_LxCKCR 1256      |  |
| JPEG_CONFR31389           | LTDC_LxCLUTWR 1260    |  |
| JPEG_CONFRx1389           | LTDC_LxCR 1253        |  |
| JPEG_CR1390               | LTDC_LxDCCR 1257      |  |
| JPEG_DHTMEMx1397          | LTDC_LxPFCR 1256      |  |
|                           | LTDC_LxWHPCR 1254     |  |
| JPEG_DIR1393              | LTDC_LxWVPCR 1255     |  |
| JPEG_DOR1393              | LTDC_SRCR 1249        |  |
| JPEG_HUFFBASEx1395        | LTDC_SSCR 1245        |  |
| JPEG_HUFFENC_ACx_y1397    | LTDC_TWCR 1247        |  |
| JPEG_HUFFENC_DCx_y1398    |                       |  |
| JPEG_HUFFMINx_y 1394-1395 |                       |  |
| JPEG_HUFFSYMBx1396        | M                     |  |
| JPEG_QMEMx_y1394          | M4_DWT_CIDR0 3467     |  |
| JPEG_SR1391               | M4_DWT_CIDR1 3467     |  |
|                           | M4_DWT_CIDR2 3468     |  |
| L                         | M4_DWT_CIDR3 3468     |  |
|                           | M4_DWT_COMPx 3463     |  |
| LPTIM_ARR2034             |                       |  |
|                           |                       |  |

**RM0399 Index**

| M4_DWT_CPICNT3460    | M4_FPB_CTRL 3479       |
|----------------------|------------------------|
| M4_DWT_CTRL3458      | M4_FPB_PIDR0 3482      |
| M4_DWT_CYCCNT3460    | M4_FPB_PIDR1 3482      |
| M4_DWT_EXCCNT3461    | M4_FPB_PIDR2 3483      |
| M4_DWT_FOLDCNT3462   | M4_FPB_PIDR3 3483      |
| M4_DWT_FUNCTx3463    | M4_FPB_PIDR4 3481      |
| M4_DWT_LSUCNT3461    | M4_FPB_REMAP 3480      |
| M4_DWT_MASKx3463     | M4_ITM_CIDR0 3476      |
| M4_DWT_PCSR3462      | M4_ITM_CIDR1 3477      |
| M4_DWT_PIDR03465     | M4_ITM_CIDR2 3477      |
| M4_DWT_PIDR13465     | M4_ITM_CIDR3 3477      |
|                      |                        |
| M4_DWT_PIDR23466     | M4_ITM_PIDR0 3474      |
| M4_DWT_PIDR33466     | M4_ITM_PIDR1 3475      |
| M4_DWT_PIDR43465     | M4_ITM_PIDR2 3475      |
| M4_DWT_SLPCNT3461    | M4_ITM_PIDR3 3476      |
| M4_ETM_AUTHSTAT3501  | M4_ITM_PIDR4 3474      |
| M4_ETM_CCER3495      | M4_ITM_STIMx 3471      |
| M4_ETM_CCR3488       | M4_ITM_TCR 3473        |
| M4_ETM_CIDR03504     | M4_ITM_TER 3472        |
| M4_ETM_CIDR13504     | M4_ITM_TPR 3472        |
| M4_ETM_CIDR23505     | M4_ROM_CIDR0 3455      |
| M4_ETM_CIDR33505     | M4_ROM_CIDR1 3455      |
| M4_ETM_CLAIMCLR3499  | M4_ROM_CIDR2 3456      |
| M4_ETM_CLAIMSET3499  | M4_ROM_CIDR3 3456      |
| M4_ETM_CNTRLDVR13493 | M4_ROM_MEMTYPE 3452    |
| M4_ETM_CR3487        | M4_ROM_PIDR0 3453      |
| M4_ETM_DEVTYPE3501   | M4_ROM_PIDR1 3454      |
|                      |                        |
| M4_ETM_FFLR3493      | M4_ROM_PIDR2 3454      |
| M4_ETM_IDR3494       | M4_ROM_PIDR3 3455      |
| M4_ETM_IDR23498      | M4_ROM_PIDR4 3453      |
| M4_ETM_LAR3500       | M7_CPUROM_CIDR0 3380   |
| M4_ETM_LSR3500       | M7_CPUROM_CIDR1 3381   |
| M4_ETM_PDSR3498      | M7_CPUROM_CIDR2 3381   |
| M4_ETM_PIDR03502     | M7_CPUROM_CIDR3 3382   |
| M4_ETM_PIDR13502     | M7_CPUROM_MEMTYPE 3377 |
| M4_ETM_PIDR23503     | M7_CPUROM_PIDR0 3378   |
| M4_ETM_PIDR33503     | M7_CPUROM_PIDR1 3379   |
| M4_ETM_PIDR43502     | M7_CPUROM_PIDR2 3379   |
| M4_ETM_SCR3490       | M7_CPUROM_PIDR3 3380   |
| M4_ETM_SR3490        | M7_CPUROM_PIDR4 3378   |
| M4_ETM_SYNCFR3493    | M7_DWT_CIDR0 3398      |
| M4_ETM_TECR13492     | M7_DWT_CIDR1 3398      |
|                      |                        |
| M4_ETM_TEEVR3491     | M7_DWT_CIDR2 3398      |
| M4_ETM_TESSEICR3496  | M7_DWT_CIDR3 3399      |
| M4_ETM_TRACEIDR3497  | M7_DWT_COMPx 3393      |
| M4_ETM_TRIGGER3489   | M7_DWT_CPICNT 3391     |
| M4_ETM_TSEVR3496     | M7_DWT_CTRL 3389       |
| M4_FPB_CIDR03484     | M7_DWT_CYCCNT 3391     |
| M4_FPB_CIDR13484     | M7_DWT_EXCCNT 3392     |
| M4_FPB_CIDR23484     | M7_DWT_FOLDCNT 3393    |
| M4_FPB_CIDR33485     | M7_DWT_FUNCTx 3394     |
| M4_FPB_COMPx3481     | M7_DWT_LSUCNT 3392     |
|                      |                        |

**Index RM0399**

|  | M7_DWT_MASKx3394     | M7_ETM_STAT 3419       |  |
|--|----------------------|------------------------|--|
|  | M7_DWT_PCSR3393      | M7_ETM_SYNCP 3423      |  |
|  | M7_DWT_PIDR03396     | M7_ETM_TRACEID 3424    |  |
|  | M7_DWT_PIDR13396     | M7_ETM_TSCTL 3423      |  |
|  | M7_DWT_PIDR23397     | M7_ETM_VICTL 3425      |  |
|  | M7_DWT_PIDR33397     | M7_ETM_VIPCSSCTL 3426  |  |
|  | M7_DWT_PIDR43395     | M7_ETM_VISSCTL 3426    |  |
|  | M7_DWT_SLPCNT3392    | M7_FPB_CIDR0 3415      |  |
|  | M7_ETM_AUTHSTAT3440  | M7_FPB_CIDR1 3415      |  |
|  | M7_ETM_CCCTL3424     | M7_FPB_CIDR2 3416      |  |
|  | M7_ETM_CIDR03444     | M7_FPB_CIDR3 3416      |  |
|  | M7_ETM_CIDR13444     | M7_FPB_COMPx 3412      |  |
|  | M7_ETM_CIDR23445     | M7_FPB_CTRL 3410       |  |
|  | M7_ETM_CIDR33445     | M7_FPB_PIDR0 3413      |  |
|  |                      |                        |  |
|  | M7_ETM_CLAIMCLR3439  | M7_FPB_PIDR1 3413      |  |
|  | M7_ETM_CLAIMSET3438  | M7_FPB_PIDR2 3414      |  |
|  | M7_ETM_CNTRLDV3427   | M7_FPB_PIDR3 3414      |  |
|  | M7_ETM_CONFIG3420    | M7_FPB_PIDR4 3412      |  |
|  | M7_ETM_DEVARCH3441   | M7_FPB_REMAP 3411      |  |
|  | M7_ETM_DEVTYPE3441   | M7_ITM_CIDR0 3407      |  |
|  | M7_ETM_EVENTCTL03421 | M7_ITM_CIDR1 3408      |  |
|  | M7_ETM_EVENTCTL13421 | M7_ITM_CIDR2 3408      |  |
|  | M7_ETM_IDR03430      | M7_ITM_CIDR3 3409      |  |
|  | M7_ETM_IDR13431      | M7_ITM_PIDR0 3405      |  |
|  | M7_ETM_IDR103428     | M7_ITM_PIDR1 3406      |  |
|  | M7_ETM_IDR113428     | M7_ITM_PIDR2 3406      |  |
|  | M7_ETM_IDR123429     | M7_ITM_PIDR3 3407      |  |
|  | M7_ETM_IDR133429     | M7_ITM_PIDR4 3405      |  |
|  | M7_ETM_IDR23431      | M7_ITM_STIMx 3402      |  |
|  | M7_ETM_IDR33432      | M7_ITM_TCR 3403        |  |
|  | M7_ETM_IDR43433      | M7_ITM_TER 3402        |  |
|  | M7_ETM_IDR53433      | M7_ITM_TPR 3403        |  |
|  | M7_ETM_IDR83427      | M7_PPBROM_CIDR0 3386   |  |
|  | M7_ETM_IDR93428      | M7_PPBROM_CIDR1 3386   |  |
|  | M7_ETM_IMSPEC03429   | M7_PPBROM_CIDR2 3387   |  |
|  | M7_ETM_LAR3439       | M7_PPBROM_CIDR3 3387   |  |
|  | M7_ETM_LSR3440       | M7_PPBROM_MEMTYPE 3383 |  |
|  | M7_ETM_PDC3437       | M7_PPBROM_PIDR0 3384   |  |
|  | M7_ETM_PDS3438       | M7_PPBROM_PIDR1 3384   |  |
|  | M7_ETM_PIDR03442     | M7_PPBROM_PIDR2 3385   |  |
|  | M7_ETM_PIDR13443     | M7_PPBROM_PIDR3 3385   |  |
|  | M7_ETM_PIDR23443     | M7_PPBROM_PIDR4 3383   |  |
|  | M7_ETM_PIDR33444     | MDIOS_CLRFR 2528       |  |
|  | M7_ETM_PIDR43442     | MDIOS_CR 2524          |  |
|  | M7_ETM_PRGCTL3418    | MDIOS_CRDFR 2527       |  |
|  | M7_ETM_PROCSEL3419   | MDIOS_CWRFR 2526       |  |
|  | M7_ETM_RSCTL23434    | MDIOS_DINRx 2528       |  |
|  |                      |                        |  |
|  | M7_ETM_RSCTL33435    | MDIOS_DOUTRx 2529      |  |
|  | M7_ETM_SSCC03435     | MDIOS_RDFR 2526        |  |
|  | M7_ETM_SSCS03436     | MDIOS_SR 2527          |  |
|  | M7_ETM_SSPCIC03437   | MDIOS_WRFR 2525        |  |
|  | M7_ETM_STALLCTL3422  | MDMA_CxBNDTR 667       |  |

3550/3556 RM0399 Rev 4

![](_page_36_Picture_3.jpeg)

**RM0399 Index**

| MDMA_CxBRUR669      | OTG_GCCFG 2800           |
|---------------------|--------------------------|
| MDMA_CxCR661        | OTG_GINTMSK 2790         |
| MDMA_CxDAR669       | OTG_GINTSTS 2786         |
| MDMA_CxESR660       | OTG_GLPMCFG 2802         |
| MDMA_CxIFCR660      | OTG_GOTGCTL 2774         |
| MDMA_CxISR658       | OTG_GOTGINT 2777         |
| MDMA_CxLAR670       | OTG_GRSTCTL 2783         |
| MDMA_CxMAR672       | OTG_GRXFSIZ 2798         |
| MDMA_CxMDR672       | OTG_GRXSTSP 2796-2797    |
| MDMA_CxSAR668       | OTG_GRXSTSR 2794-2795    |
| MDMA_CxTBR671       | OTG_GUSBCFG 2780         |
| MDMA_CxTCR663       | OTG_HAINT 2811           |
| MDMA_GISR0658       | OTG_HAINTMSK 2811        |
|                     | OTG_HCCHARx 2815         |
|                     | OTG_HCDMABx 2824         |
| O                   | OTG_HCDMASGx 2823        |
| OPAMP_OR1146        | OTG_HCDMAx 2823          |
| OPAMP1_CSR1143      | OTG_HCFG 2807            |
| OPAMP1_HSOTR1146    | OTG_HCINTMSKx 2818       |
| OPAMP1_OTR1145      | OTG_HCINTx 2817          |
| OPAMP2_CSR1146      | OTG_HCSPLTx 2816         |
| OPAMP2_HSOTR1149    | OTG_HCTSIZSGx 2821       |
| OPAMP2_OTR1148      | OTG_HCTSIZx 2820         |
| OTG_CID2802         | OTG_HFIR 2808            |
| OTG_DAINT2832       | OTG_HFLBADDR 2812        |
| OTG_DAINTMSK2833    | OTG_HFNUM 2809           |
| OTG_DCFG2825        | OTG_HNPTXFSIZ 2798       |
| OTG_DCTL2827        | OTG_HNPTXSTS 2799        |
| OTG_DEACHINT2836    | OTG_HPRT 2812            |
| OTG_DEACHINTMSK2837 | OTG_HPTXFSIZ 2806        |
| OTG_DIEPCTLx2840    | OTG_HPTXSTS 2810         |
| OTG_DIEPDMAx2844    | OTG_HS_DIEPEACHMSK1 2837 |
| OTG_DIEPEMPMSK2836  | OTG_HS_DOEPEACHMSK1 2838 |
| OTG_DIEPINTx2842    | OTG_PCGCCTL 2855         |
| OTG_DIEPMSK2830     |                          |
| OTG_DIEPTSIZ02844   |                          |
| OTG_DIEPTSIZx2845   | P                        |
| OTG_DIEPTXF02798    | PWR_CSR 329, 336-337     |
| OTG_DIEPTXFx2806    |                          |
| OTG_DOEPCTL02846    |                          |
| OTG_DOEPCTLx2851    | Q                        |
| OTG_DOEPDMAx2851    | QUADSPI_ABR 943          |
| OTG_DOEPINTx2848    | QUADSPI_AR 942           |
| OTG_DOEPMSK2831     | QUADSPI_CCR 940          |
| OTG_DOEPTSIZ02850   | QUADSPI_CR 935           |
| OTG_DOEPTSIZx2854   | QUADSPI_DCR 937          |
| OTG_DSTS2829        | QUADSPI_DLR 940          |
| OTG_DTHRCTL2835     | QUADSPI_DR 943           |
| OTG_DTXFSTSx2845    | QUADSPI_FCR 939          |
| OTG_DVBUSDIS2834    | QUADSPI_LPTR 945         |
| OTG_DVBUSPULSE2834  | QUADSPI_PIR 945          |
| OTG_GAHBCFG2779     | QUADSPI_PSMAR 944        |
|                     | QUADSPI_PSMKR 944        |
|                     |                          |

**Index RM0399**

| QUADSPI_SR938           | RCC_D3CCIPR 449                          |  |
|-------------------------|------------------------------------------|--|
|                         | RCC_D3CFGR 428                           |  |
| R                       | RCC_GCR 477                              |  |
|                         | RCC_HSICFGR 419                          |  |
| RAMECC_IER149           | RCC_PLL1DIVR 434                         |  |
| RAMECC_MxCR150          | RCC_PLL1FRACR 436                        |  |
| RAMECC_MxFAR151         | RCC_PLL2DIVR 437                         |  |
| RAMECC_MxFDRH152        | RCC_PLL2FRACR 439                        |  |
| RAMECC_MxFDRL151        | RCC_PLL3DIVR 440                         |  |
| RAMECC_MxFECR152        | RCC_PLL3FRACR 442                        |  |
| RAMECC_MxSR150          | RCC_PLLCFGR 431                          |  |
| RCC_BDCR458             | RCC_PLLCKSELR 429                        |  |
| RCC_CFGR)422            | RCC_RSR 481                              |  |
| RCC_CICR456             | RNG_CR 1410                              |  |
| RCC_CIER452             | RNG_DR 1412                              |  |
| RCC_CIFR454             | RNG_SR 1411                              |  |
| RCC_CR415               | RTC_ALRMAR 2086                          |  |
| RCC_CRRCR420            | RTC_ALRMASSR 2097                        |  |
| RCC_CSICFGR421          | RTC_ALRMBR 2087                          |  |
| RCC_CSR460              | RTC_ALRMBSSR 2098                        |  |
| RCC_D1AHB1ENR484        | RTC_BKPxR 2099                           |  |
| RCC_D1AHB1LPENR508      | RTC_CALR 2093                            |  |
| RCC_D1AHB1RSTR461       | RTC_CR 2078                              |  |
| RCC_D1APB1ENR495        | RTC_DR 2076                              |  |
| RCC_D1APB1LPENR 517-518 | RTC_ISR 2081                             |  |
| RCC_D1APB1RSTR468       | RTC_OR 2099                              |  |
| RCC_D1CCIPR443          | RTC_PRER 2084                            |  |
| RCC_D1CFGR425           | RTC_SHIFTR 2089                          |  |
| RCC_D2AHB1ENR487        |                                          |  |
| RCC_D2AHB1LPENR510      | RTC_SSR 2088                             |  |
| RCC_D2AHB1RSTR463       | RTC_TAMPCR 2094                          |  |
| RCC_D2AHB2ENR489        | RTC_TR 325, 327-328, 331, 333, 335, 2075 |  |
| RCC_D2AHB2LPENR512      | RTC_TSDR 2091                            |  |
| RCC_D2AHB2RSTR465       | RTC_TSSSR 2092                           |  |
|                         | RTC_TSTR 2090                            |  |
| RCC_D2APB1HENR500       | RTC_WPR 2088                             |  |
| RCC_D2APB1HLPENR522     | RTC_WUTR 2085                            |  |
| RCC_D2APB1HRSTR472      |                                          |  |
| RCC_D2APB1LENR496       | S                                        |  |
| RCC_D2APB1LRSTR469      |                                          |  |
| RCC_D2APB2ENR502        | SAI_ACLRFR 2449                          |  |
| RCC_D2APB2LPENR524      | SAI_ACR1 2428                            |  |
| RCC_D2APB2RSTR473       | SAI_ACR2 2433                            |  |
| RCC_D2CCIP1R444         | SAI_ADR 2451                             |  |
| RCC_D2CCIP2R447         | SAI_AFRCR 2437                           |  |
| RCC_D2CFGR427           | SAI_AIM 2442                             |  |
| RCC_D3AHB1ENR492        | SAI_ASLOTR 2440                          |  |
| RCC_D3AHB1LPENR514      | SAI_ASR 2445                             |  |
| RCC_D3AHB1RSTR466       | SAI_BCLRFR 2450                          |  |
| RCC_D3AMR478            | SAI_BCR1 2430                            |  |
| RCC_D3APB1ENR505        | SAI_BCR2 2435                            |  |
| RCC_D3APB1LPENR527      | SAI_BDR 2452                             |  |
| RCC_D3APB1RSTR475       | SAI_BFRCR 2439                           |  |

**RM0399 Index**

| SAI_BIM2444          | SWO_CIDR2 3351     |
|----------------------|--------------------|
| SAI_BSLOTR2441       | SWO_CIDR3 3351     |
| SAI_BSR2447          | SWO_CLAIMCLR 3344  |
| SAI_GCR2427          | SWO_CLAIMSET 3343  |
| SAI_PDMCR2452        | SWO_CODR 3342      |
| SAI_PDMDLY2454       | SWO_DEVID 3346     |
| SDMMC_ACKTIMER2606   | SWO_DEVTYPE 3347   |
| SDMMC_ARGR2591       | SWO_FFSR 3343      |
| SDMMC_CLKCR2589      | SWO_LAR 3344       |
| SDMMC_CMDR2591       | SWO_LSR 3345       |
| SDMMC_DCNTR2597      | SWO_PIDR0 3348     |
| SDMMC_DCTRL2596      | SWO_PIDR1 3348     |
| SDMMC_DLENR2595      | SWO_PIDR2 3349     |
| SDMMC_DTIMER2594     | SWO_PIDR3 3349     |
| SDMMC_FIFORx2606     | SWO_PIDR4 3347     |
| SDMMC_ICR2601        | SWO_SPPR 3342      |
| SDMMC_IDMABASE0R2608 | SWPMI_BRR 2510     |
| SDMMC_IDMABASE1R2609 | SWPMI_CR 2509      |
| SDMMC_IDMABSIZER2608 | SWPMI_ICR 2512     |
| SDMMC_IDMACTRLR2607  | SWPMI_ISR 2511     |
| SDMMC_MASKR2603      | SWPMI_OR 2516      |
| SDMMC_POWER2588      | SWPMI_RDR 2515     |
| SDMMC_RESPCMDR2593   | SWPMI_RFL 2515     |
|                      |                    |
| SDMMC_RESPxR2594     | SWPMI_TDR 2515     |
| SDMMC_STAR2598       | SWTF_AUTHSTAT 3356 |
| SMPMI_IER2513        | SWTF_CIDR0 3360    |
| SPDIFRX_CR2480       | SWTF_CIDR1 3361    |
| SPDIFRX_CSR2488      | SWTF_CIDR2 3361    |
| SPDIFRX_DIR2488      | SWTF_CIDR3 3362    |
| SPDIFRX_FMT0_DR2486  | SWTF_CLAIMCLR 3355 |
| SPDIFRX_FMT1_DR2486  | SWTF_CLAIMSET 3354 |
| SPDIFRX_FMT2_DR2487  | SWTF_CTRL 3353     |
| SPDIFRX_IFCR2485     | SWTF_DEVID 3357    |
| SPDIFRX_IMR2482      | SWTF_DEVTYPE 3357  |
| SPDIFRX_SR2483       | SWTF_LAR 3355      |
| SPI_CFG12371         | SWTF_LSR 3356      |
| SPI_CFG22374         | SWTF_PIDR0 3358    |
| SPI_CR12369          | SWTF_PIDR1 3359    |
| SPI_CR22371          | SWTF_PIDR2 3359    |
| SPI_CRCPOLY2382      | SWTF_PIDR3 3360    |
| SPI_I2SCFGR2384      | SWTF_PIDR4 3358    |
| SPI_IER2376          | SWTF_PRIORITY 3354 |
| SPI_IFCR2380         | SYSCFG_CCCR 597    |
| SPI_RXCRC2383        | SYSCFG_CCCSR 596   |
| SPI_RXDR2381         | SYSCFG_CCVR 597    |
| SPI_SR2377           | SYSCFG_CFGR 593    |
| SPI_TXCRC2382        | SYSCFG_EXTICR1 589 |
| SPI_TXDR2381         | SYSCFG_EXTICR2 589 |
| SPI_UDRDR2384        | SYSCFG_EXTICR3 591 |
| SWO_AUTHSTAT3345     | SYSCFG_EXTICR4 592 |
| SWO_CIDR03350        | SYSCFG_PKGR 599    |
| SWO_CIDR13350        | SYSCFG_PMCR 586    |
|                      |                    |

**Index RM0399**

| SYSCFG_PWRCR598       | TIM15_AF1 1970                               |
|-----------------------|----------------------------------------------|
| SYSCFG_SR0598         | TIM15_ARR 1964                               |
| SYSCFG_UR0600         | TIM15_BDTR 1966                              |
| SYSCFG_UR1601         | TIM15_CCER 1961                              |
| SYSCFG_UR10605        | TIM15_CCMR1 1957-1958                        |
|                       |                                              |
| SYSCFG_UR11606        | TIM15_CCR1 1965                              |
| SYSCFG_UR12606        | TIM15_CCR2 1966                              |
| SYSCFG_UR13607        | TIM15_CNT 1964                               |
| SYSCFG_UR14608        | TIM15_CR1 1949                               |
| SYSCFG_UR15609        | TIM15_CR2 1950                               |
| SYSCFG_UR16610        | TIM15_DCR 1969                               |
| SYSCFG_UR17610        | TIM15_DIER 1953                              |
| SYSCFG_UR2601         | TIM15_DMAR 1969                              |
| SYSCFG_UR3602         | TIM15_EGR 1956                               |
| SYSCFG_UR4602         | TIM15_PSC 1964                               |
|                       |                                              |
| SYSCFG_UR5603         | TIM15_RCR 1965                               |
| SYSCFG_UR6603         | TIM15_SMCR 1952                              |
| SYSCFG_UR7604         | TIM15_SR 1954                                |
| SYSCFG_UR8604         | TIM15_TISEL 1971                             |
| SYSCFG_UR9605         | TIM16_AF1 1991                               |
| SYSROM_CIDR03257      | TIM16_TISEL 1992                             |
| SYSROM_CIDR13258      | TIM17_AF1 1993                               |
| SYSROM_CIDR23258      | TIM17_TISEL 1994                             |
| SYSROM_CIDR33259      | TIM2_AF1 1849                                |
| SYSROM_MEMTYPE3255    | TIM2_TISEL 1851                              |
| SYSROM_PIDR03256      | TIM3_AF1 1849                                |
|                       |                                              |
| SYSROM_PIDR13256      | TIM3_TISEL 1851                              |
| SYSROM_PIDR23256      | TIM4_AF1 1850                                |
| SYSROM_PIDR33257      | TIM4_TISEL 1852                              |
| SYSROM_PIDR43255      | TIM5_AF1 1850                                |
|                       | TIM5_TISEL 1853                              |
|                       | TIM8_AF1 1770                                |
| T                     | TIM8_AF2 1772                                |
| TIM1_AF11767          | TIM8_TISEL 1774                              |
| TIM1_AF21769          | TIMx_ARR1757, 1845, 1907, 1985, 2008         |
| TIM1_TISEL1774        | TIMx_BDTR 1760, 1987                         |
| TIM12_ARR1895         |                                              |
| TIM12_CCER1893        | TIMx_CCER1754, 1842, 1905, 1982              |
|                       | TIMx_CCMR1 1747-1748, 1836, 1838, 1902-      |
| TIM12_CCMR1 1889-1890 | 1903, 1979-1980                              |
| TIM12_CCR11895        | TIMx_CCMR21751-1752, 1840-1841               |
| TIM12_CCR21896        | TIMx_CCMR3 1765                              |
| TIM12_CNT1894         | TIMx_CCR11758, 1845, 1907, 1986              |
| TIM12_CR11883         | TIMx_CCR2 1759, 1846                         |
| TIM12_CR21884         | TIMx_CCR3 1759, 1846                         |
| TIM12_DIER1887        | TIMx_CCR4 1760, 1847                         |
| TIM12_EGR1888         | TIMx_CCR5 1766                               |
| TIM12_PSC1895         |                                              |
| TIM12_SMCR1885        | TIMx_CCR6 1767                               |
|                       | TIMx_CNT . 1757, 1843-1844, 1906, 1984, 2007 |
| TIM12_SR1887          | TIMx_CR11736, 1826, 1899, 1974, 2004         |
| TIM12_TISEL1896       | TIMx_CR21737, 1827, 1975, 2006               |
| TIM13_TISEL1908       | TIMx_DCR 1763, 1848, 1989                    |
| TIM14_TISEL1908       |                                              |
|                       | TIMx_DIER1742, 1832, 1900, 1976, 2006        |

**RM0399 Index**

| TIMx_DMAR 1764, 1848, 1990            | USART_CR2 2228       |
|---------------------------------------|----------------------|
|                                       |                      |
| TIMx_EGR 1746, 1834, 1901, 1978, 2007 | USART_CR3 2232       |
| TIMx_PSC 1757, 1844, 1907, 1985, 2008 | USART_GTPR 2237      |
| TIMx_RCR1758, 1986                    | USART_ICR 2251       |
| TIMx_SMCR1740, 1829                   | USART_ISR 2240, 2246 |
| TIMx_SR 1744, 1833, 1900, 1977, 2007  | USART_PRESC 2254     |
| TPIU_AUTHSTAT3333                     | USART_RDR 2253       |
| TPIU_CIDR03337                        | USART_RQR 2239       |
| TPIU_CIDR13338                        | USART_RTOR 2238      |
| TPIU_CIDR23338                        | USART_TDR 2253       |
| TPIU_CIDR33339                        |                      |
| TPIU_CLAIMCLR3331                     |                      |
|                                       | V                    |
| TPIU_CLAIMSET3331                     | VREFBUF_CCR 1116     |
| TPIU_CURPSIZE3324                     |                      |
| TPIU_CURTPM3327                       | VREFBUF_CSR 1115     |
| TPIU_DEVID3334                        |                      |
| TPIU_DEVTYPE3334                      | W                    |
| TPIU_FFCR3329                         |                      |
| TPIU_FFSR3328                         | WWDG_CFR 2045        |
| TPIU_FSCR3330                         | WWDG_CR 2045         |
| TPIU_LAR3332                          | WWDG_SR 2046         |
| TPIU_LSR3332                          |                      |
| TPIU_PIDR03335                        |                      |
|                                       |                      |
| TPIU_PIDR13336                        |                      |
| TPIU_PIDR23336                        |                      |
| TPIU_PIDR33337                        |                      |
| TPIU_PIDR43335                        |                      |
| TPIU_SUPPSIZE3324                     |                      |
| TPIU_SUPTPM3326                       |                      |
| TPIU_SUPTRGM3324                      |                      |
| TPIU_TPRCR3328                        |                      |
| TPIU_TRGCNT3325                       |                      |
| TPIU_TRGMULT3326                      |                      |
| TSG_CIDR03266                         |                      |
|                                       |                      |
| TSG_CIDR13267                         |                      |
| TSG_CIDR23267                         |                      |
| TSG_CIDR33268                         |                      |
| TSG_CNTCR3262                         |                      |
| TSG_CNTCVL3263                        |                      |
| TSG_CNTCVU3263                        |                      |
| TSG_CNTFID03264                       |                      |
| TSG_CNTSR3263                         |                      |
| TSG_PIDR03265                         |                      |
| TSG_PIDR13265                         |                      |
|                                       |                      |
| TSG_PIDR23265                         |                      |
| TSG_PIDR33266                         |                      |
| TSG_PIDR43264                         |                      |
|                                       |                      |
| U                                     |                      |
| USART_BRR2237                         |                      |
| USART_CR1 461, 2221, 2225             |                      |
|                                       |                      |

## **IMPORTANT NOTICE – READ CAREFULLY**

STMicroelectronics NV and its subsidiaries ("ST") reserve the right to make changes, corrections, enhancements, modifications, and improvements to ST products and/or to this document at any time without notice. Purchasers should obtain the latest relevant information on ST products before placing orders. ST products are sold pursuant to ST's terms and conditions of sale in place at the time of order acknowledgment.

Purchasers are solely responsible for the choice, selection, and use of ST products and ST assumes no liability for application assistance or the design of purchasers' products.

No license, express or implied, to any intellectual property right is granted by ST herein.

Resale of ST products with provisions different from the information set forth herein shall void any warranty granted by ST for such product.

ST and the ST logo are trademarks of ST. For additional information about ST trademarks, refer to *www.st.com/trademarks*. All other product or service names are the property of their respective owners.

Information in this document supersedes and replaces information previously supplied in any prior versions of this document.

© 2023 STMicroelectronics – All rights reserved

3556/3556 RM0399 Rev 4