# WM8994 Audio Codec Index

**Document**: WM8994 Datasheet Rev 4.6 (Cirrus Logic)
**Purpose**: This index helps LLMs locate relevant documentation sections without loading the entire manual into context.

---

## How to Use This Index

1. Read this index file to identify which section(s) contain information about your topic
2. Load only the relevant markdown file(s) from the `WM8994` folder
3. Each section is in its own subfolder with a `.md` file containing the full content
4. Note: Chapter 03 (Pin Configuration) failed to convert - use the PDF directly if needed

---

## Device Overview

The WM8994 is a low-power, high-quality audio codec designed for portable applications like mobile phones. Key features:
- 4 stereo ADC channels (24-bit)
- 4 stereo DAC channels (24-bit)
- 3 independent digital audio interfaces (AIF1, AIF2, AIF3)
- Class D/AB speaker drivers (2W stereo or mono)
- Headphone, earpiece, and line outputs
- Dual FLL (Frequency Locked Loop) for flexible clocking
- I2C/SPI control interface
- Dynamic Range Control (DRC) and 5-band parametric EQ

---

## Chapter Summaries

| File | Chapter | Summary | Keywords |
|------|---------|---------|----------|
| `01_Table of Contents/` | TOC | Full table of contents with page numbers | contents, navigation |
| `02_Block Diagram/` | Block Diagram | High-level architecture showing signal paths | architecture, block diagram, signal flow |
| `04_Ordering Information/` | Ordering | Part numbers and package options | ordering, part number, package |
| `05_Pin Description/` | Pin Description | **Pin functions, names, and descriptions** for all 121 pins | pins, pinout, ball map, connections |
| `06_Absolute Maximum Ratings/` | Abs Max | Maximum voltage/current/temperature limits | maximum ratings, limits, ESD |
| `07_Recommended Operating Conditions/` | Operating | **Recommended voltage, temperature ranges** | voltage, temperature, operating conditions |
| `08_Thermal Performance/` | Thermal | Thermal resistance and power dissipation | thermal, heat, power dissipation |
| `09_Electrical Characteristics/` | Electrical | **ADC/DAC performance specs, gain ranges, SNR, THD** | SNR, THD, gain, performance, specifications |
| `10_Typical Performance/` | Performance | Graphs of typical power consumption, latency, speaker performance | power consumption, latency, graphs |
| `11_Signal Timing Requirements/` | Timing | **Clock timing, I2C/SPI timing, audio interface timing** | timing, clock, I2C, SPI, BCLK, LRCLK |
| `12_Device Description/` | **Main Technical Content** | **Complete functional description** - see detailed breakdown below | all technical topics |
| `13_Register Map/` | Registers | **Complete register definitions and bit fields** | registers, configuration, bits |
| `14_Applications Information/` | Applications | **Recommended circuits, PCB layout, external components** | schematic, circuit, layout, components |
| `15_Package Dimensions/` | Package | Physical package dimensions and drawings | package, dimensions, footprint |
| `16_Important Notice/` | Notice | Legal notices and disclaimers | legal, notice |
| `17_Revision History/` | Revision | Document revision history | revision, changes |

---

## Device Description (Chapter 12) - Detailed Breakdown

This is the main technical chapter (~200 pages). Key sections include:

### Analog Input Signal Path
| Topic | Keywords |
|-------|----------|
| Microphone Inputs | microphone, MIC, differential, single-ended, IN1L, IN1R, IN2L, IN2R |
| Microphone Bias (MICBIAS) | MICBIAS, bias voltage, MICB1, MICB2, accessory detect |
| Line Inputs | line input, IN1LP, IN1RP, IN2LP, IN2RP |
| Input PGA | PGA, gain, volume, input amplifier |
| Input Mixer | MIXINL, MIXINR, mixing |
| Digital Microphone Interface | DMIC, digital microphone, DMICDAT, DMICCLK |

### ADC (Analog-to-Digital Converter)
| Topic | Keywords |
|-------|----------|
| ADC Control | ADC, ADCL, ADCR, enable, clocking |
| High Pass Filter | HPF, DC offset, wind noise |

### Digital Core
| Topic | Keywords |
|-------|----------|
| Digital Mixing | mixing, routing, AIF1, AIF2, sidetone |
| Dynamic Range Control (DRC) | DRC, compression, limiting, AGC, anti-clip |
| Parametric EQ (ReTune Mobile) | EQ, equalizer, 5-band, filter coefficients |
| 3D Stereo Expansion | 3D, stereo widening |
| Volume Control | volume, gain, mute, soft mute |

### DAC (Digital-to-Analog Converter)
| Topic | Keywords |
|-------|----------|
| DAC Control | DAC, DACL, DACR, enable |
| DAC Soft Mute | mute, unmute, pop-free |

### Analog Output Signal Path
| Topic | Keywords |
|-------|----------|
| Output Mixers | MIXOUTL, MIXOUTR, output mixing |
| Speaker Drivers | speaker, SPKOUTL, SPKOUTR, Class D, Class AB, SPKMIX |
| Headphone Outputs | headphone, HPOUT1L, HPOUT1R, charge pump |
| Earpiece Driver | earpiece, HPOUT2, receiver |
| Line Outputs | LINEOUT, line output, differential |
| DC Servo | DC servo, offset correction, pop suppression |
| Charge Pump | charge pump, CP, negative voltage |

### GPIO and Interrupts
| Topic | Keywords |
|-------|----------|
| GPIO Control | GPIO, general purpose IO |
| Interrupts | IRQ, interrupt, status |
| Button/Accessory Detect | button, accessory, jack detect |

### Digital Audio Interface
| Topic | Keywords |
|-------|----------|
| AIF1 Configuration | AIF1, audio interface 1, master, slave |
| AIF2 Configuration | AIF2, audio interface 2, voice, baseband |
| AIF3 Configuration | AIF3, audio interface 3 |
| I2S/PCM/TDM Modes | I2S, PCM, TDM, DSP mode, data format |
| BCLK/LRCLK Control | BCLK, LRCLK, bit clock, frame clock |
| Companding | A-law, μ-law, companding |

### Clocking
| Topic | Keywords |
|-------|----------|
| System Clock (SYSCLK) | SYSCLK, system clock, MCLK |
| FLL (Frequency Locked Loop) | FLL, PLL, clock generation, frequency synthesis |
| Sample Rate Conversion | SRC, sample rate, resampling, asynchronous |
| AIF Clocking | AIF1CLK, AIF2CLK, clock source |

### Control Interface
| Topic | Keywords |
|-------|----------|
| I2C Control | I2C, 2-wire, control interface, address |
| SPI Control | SPI, 3-wire, 4-wire |
| Control Write Sequencer | sequencer, startup, shutdown, sequence |

### Power Management
| Topic | Keywords |
|-------|----------|
| LDO Regulators | LDO, regulator, power supply |
| Power Enable | enable, power management, bias |
| Pop Suppression | pop, click, startup, shutdown |
| Thermal Shutdown | thermal, overtemperature, protection |
| Software Reset | reset, device ID |

---

## Quick Reference: Common Tasks

### Audio Playback (DAC to Headphones)
1. `12_Device Description/` - DAC configuration, output mixer, headphone driver
2. `13_Register Map/` - Register settings
3. `14_Applications Information/` - Headphone circuit design

### Audio Recording (Microphone to ADC)
1. `12_Device Description/` - Microphone input, PGA, ADC configuration
2. `13_Register Map/` - Register settings
3. `14_Applications Information/` - Microphone circuit design

### Clock Configuration
1. `12_Device Description/` - FLL, SYSCLK, sample rates
2. `11_Signal Timing Requirements/` - Timing specifications
3. `13_Register Map/` - Clock register settings

### I2C/SPI Communication
1. `11_Signal Timing Requirements/` - I2C/SPI timing specs
2. `12_Device Description/` - Control interface section
3. `13_Register Map/` - All register addresses

### Speaker Output
1. `12_Device Description/` - Speaker mixer, Class D driver
2. `09_Electrical Characteristics/` - Speaker driver specs
3. `14_Applications Information/` - Speaker circuit design

### Hardware Design
1. `05_Pin Description/` - Pin assignments
2. `14_Applications Information/` - Recommended circuits, PCB layout
3. `15_Package Dimensions/` - Physical dimensions

---

## Register Quick Reference

Key register addresses (see `13_Register Map/` for complete details):

| Address | Name | Purpose |
|---------|------|---------|
| 0x0000 | Software Reset | Write to reset device, read for device ID |
| 0x0001 | Power Management 1 | MICBIAS, VMID, bias enables |
| 0x0002 | Power Management 2 | Input PGA enables |
| 0x0003 | Power Management 3 | MIXOUTL/R, SPKL/R enables |
| 0x0004 | Power Management 4 | AIF1/2 ADC/DAC enables |
| 0x0005 | Power Management 5 | AIF1/2 DAC enables |
| 0x0006 | Power Management 6 | AIF3 enables |
| 0x0200 | AIF1 Clocking 1 | AIF1CLK source and enable |
| 0x0208 | AIF2 Clocking 1 | AIF2CLK source and enable |
| 0x0210 | FLL1 Control 1 | FLL1 enable |
| 0x0220 | FLL2 Control 1 | FLL2 enable |
| 0x0300 | AIF1 Control 1 | AIF1 format, word length |
| 0x0310 | AIF2 Control 1 | AIF2 format, word length |

---

## STM32H747I-DISCO Board Notes

On the STM32H747I-DISCO board, the WM8994 is connected via:
- **I2C4** for control (address 0x34)
- **SAI2** for audio data (I2S mode)
- **MCLK** from SAI2 master clock output

Typical configuration for 48kHz audio:
- SYSCLK = 12.288 MHz (256 × 48kHz)
- BCLK = 3.072 MHz (64 × 48kHz)
- LRCLK = 48 kHz

---

*Generated from WM8994 Datasheet Rev 4.6 (Cirrus Logic)*
