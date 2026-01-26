
## **PIN DESCRIPTION**

A description of each pin on the WM8994 is provided below.

Note that a table detailing the associated power domain for every input and output pin is provided on the following page. Note that, where multiple pins share a common name, these pins should be tied together on the PCB.

| PIN NO                                     | NAME       | TYPE                                       | DESCRIPTION                                                   |  |
|--------------------------------------------|------------|--------------------------------------------|---------------------------------------------------------------|--|
| F2                                         | ADCDAT1    | Digital Output                             | Audio interface 1 ADC digital audio data                      |  |
| Digital Input / Output<br>G3<br>ADCLRCLK1/ |            | Audio interface 1 ADC left / right clock / |                                                               |  |
|                                            | GPIO1      |                                            | General Purpose pin GPIO 1/                                   |  |
|                                            |            |                                            | Control interface data output                                 |  |
| D6, E7,<br>E8                              | AGND       | Supply                                     | Analogue ground (Return path for AVDD1, AVDD2 and LDO1VDD)    |  |
| D9                                         | AVDD1      | Supply / Analogue<br>Output                | Analogue core supply / LDO1 Output                            |  |
| D8                                         | AVDD2      | Supply                                     | Bandgap reference, analogue class D and FLL supply            |  |
| G1                                         | BCLK1      | Digital Input / Output                     | Audio interface 1 bit clock                                   |  |
| A4                                         | CIFMODE    | Digital Input                              | Selects 2-wire or 3/4-wire control interface mode             |  |
| G8                                         | CPCA       | Analogue Output                            | Charge pump fly-back capacitor pin                            |  |
| H8                                         | CPCB       | Analogue Output                            | Charge pump fly-back capacitor pin                            |  |
| H9                                         | CPGND      | Supply                                     | Charge pump ground (Return path for CPVDD)                    |  |
| G9                                         | CPVDD      | Supply                                     | Charge pump supply                                            |  |
| H7                                         | CPVOUTN    | Analogue Output                            | Charge pump negative supply decoupling pin (HPOUT1L, HPOUT1R) |  |
| G7                                         | CPVOUTP    | Analogue Output                            | Charge pump positive supply decoupling pin (HPOUT1L, HPOUT1R) |  |
| G2                                         | CS¯¯ /ADDR | Digital Input                              | 3-/4-wire (SPI) chip select or 2-wire (I2C) address select    |  |
| E4                                         | DACDAT1    | Digital Input                              | Audio interface 1 DAC digital audio data                      |  |
| D2                                         | DBVDD      | Supply                                     | Digital buffer (I/O) supply                                   |  |
| F1                                         | DCVDD      | Supply / Analogue<br>Output                | Digital core supply / LDO2 output                             |  |
| E2                                         | DGND       | Supply                                     | Digital ground (Return path for DCVDD, DBVDD and LDO2VDD)     |  |
| C6                                         | DMICCLK    | Digital Output                             | Digital MIC clock output                                      |  |
| E1                                         | GPIO2/     | Digital Input                              | General Purpose pin GPI 2 /                                   |  |
|                                            | MCLK2      |                                            | Master clock 2                                                |  |
| H2                                         | GPIO3/     | Digital Input / Output                     | General Purpose pin GPIO 3 /                                  |  |
|                                            | BCLK2      |                                            | Audio interface 2 bit clock                                   |  |
| F4                                         | GPIO4/     | Digital Input / Output                     | General Purpose pin GPIO 4 /                                  |  |
|                                            | LRCLK2     |                                            | Audio interface 2 left / right clock                          |  |
| H3                                         | GPIO5/     | Digital Input / Output                     | General Purpose pin GPIO 5 /                                  |  |
|                                            | DACDAT2    |                                            | Audio interface 2 DAC digital audio data                      |  |
| G4                                         | GPIO6/     | Digital Input / Output                     | General Purpose pin GPIO 6 /                                  |  |
|                                            | ADCLRCLK2  |                                            | Audio interface 2 ADC left / right clock                      |  |
| E5                                         | GPIO7/     | Digital Input / Output                     | General Purpose pin GPIO 7 /                                  |  |
|                                            | ADCDAT2    |                                            | Audio interface 2 ADC digital audio data                      |  |
| H4                                         | GPIO8/     | Digital Input / Output                     | General Purpose pin GPIO 8 /                                  |  |
|                                            | DACDAT3    |                                            | Audio interface 3 DAC digital audio data                      |  |
| F5                                         | GPIO9/     | Digital Input / Output                     | General Purpose pin GPIO 9 /                                  |  |
|                                            | ADCDAT3    |                                            | Audio interface 3 ADC digital audio data                      |  |
| H5                                         | GPIO10/    | Digital Input / Output                     | General Purpose pin GPIO 10 /                                 |  |
|                                            | LRCLK3     |                                            | Audio interface 3 left / right clock                          |  |
| F6                                         | GPIO11/    | Digital Input / Output                     | General Purpose pin GPIO 11 /                                 |  |
|                                            | BCLK3      |                                            | Audio interface 3 bit clock                                   |  |
| F7                                         | HP2GND     | Supply                                     | Analogue ground                                               |  |
| G5                                         | HPOUT1FB   | Analogue Input                             | HPOUT1L and HPOUT1R ground loop noise rejection feedback      |  |
| H6                                         | HPOUT1L    | Analogue Output                            | Left headphone output                                         |  |

**8 Rev 4.6**


| PIN NO                        | NAME                                                                   | TYPE                       | DESCRIPTION                                                         |  |
|-------------------------------|------------------------------------------------------------------------|----------------------------|---------------------------------------------------------------------|--|
| G6                            | HPOUT1R                                                                | Analogue Output            | Right headphone output                                              |  |
| F9                            | HPOUT2N                                                                | Analogue Output            | Earpiece speaker inverted output                                    |  |
| F8                            | HPOUT2P                                                                | Analogue Output            | Earpiece speaker non-inverted output                                |  |
|                               | Analogue Input<br>Left channel single-ended MIC input /<br>D7<br>IN1LN |                            |                                                                     |  |
|                               |                                                                        |                            | Left channel negative differential MIC input                        |  |
| C8                            | IN1LP                                                                  | Analogue Input             | Left channel line input /                                           |  |
|                               |                                                                        |                            | Left channel positive differential MIC input                        |  |
| B7                            | IN1RN                                                                  | Analogue Input             | Right channel single-ended MIC input /                              |  |
|                               |                                                                        |                            | Right channel negative differential MIC input                       |  |
| C7<br>IN1RP<br>Analogue Input |                                                                        | Right channel line input / |                                                                     |  |
|                               |                                                                        |                            | Right channel positive differential MIC input                       |  |
| B9                            | IN2LN/                                                                 | Analogue Input /           | Left channel line input /                                           |  |
|                               | DMICDAT1                                                               | Digital Input              | Left channel negative differential MIC input /                      |  |
|                               |                                                                        |                            | Digital MIC data input 1                                            |  |
| B8                            | IN2LP/VRXN                                                             | Analogue Input             | Left channel line input /                                           |  |
|                               |                                                                        |                            | Left channel positive differential MIC input /                      |  |
|                               |                                                                        |                            | Mono differential negative input (RXVOICE -)                        |  |
| A9                            | IN2RN/                                                                 | Analogue Input /           | Right channel line input /                                          |  |
|                               | DMICDAT2                                                               | Digital Input              | Right channel negative differential MIC input /                     |  |
|                               |                                                                        |                            | Digital MIC data input 2                                            |  |
| A8                            | IN2RP/VRXP                                                             | Analogue Input             | Left channel line input /                                           |  |
|                               |                                                                        |                            | Left channel positive differential MIC input /                      |  |
|                               |                                                                        |                            | Mono differential positive input (RXVOICE +)                        |  |
| D4                            | LDO1ENA                                                                | Digital Input              | Enable pin for LDO1                                                 |  |
| E9                            | LDO1VDD                                                                | Supply                     | Supply for LDO1                                                     |  |
| D5                            | LDO2ENA                                                                | Digital Input              | Enable pin for LDO2                                                 |  |
| D1                            | LDO2VDD                                                                | Supply                     | Supply for LDO2                                                     |  |
| C5                            | LINEOUT1N                                                              | Analogue Output            | Negative mono line output / Positive left or right line output      |  |
| B5                            | LINEOUT1P                                                              | Analogue Output            | Positive mono line output / Positive left line output               |  |
| C4                            | LINEOUT2N                                                              | Analogue Output            | Negative mono line output / Positive left or right line output      |  |
| B4                            | LINEOUT2P                                                              | Analogue Output            | Positive mono line output / Positive left line output               |  |
| A6                            | LINEOUTFB                                                              | Analogue Input             | Line output ground loop noise rejection feedback                    |  |
| E3                            | LRCLK1                                                                 | Digital Input / Output     | Audio interface 1 left / right clock                                |  |
| D3                            | MCLK1                                                                  | Digital Input              | Master clock 1                                                      |  |
| A7                            | MICBIAS1                                                               | Analogue Output            | Microphone bias 1                                                   |  |
| B6                            | MICBIAS2                                                               | Analogue Output            | Microphone bias 2                                                   |  |
| A5                            | REFGND                                                                 | Supply                     | Analogue ground                                                     |  |
| H1                            | SCLK                                                                   | Digital Input              | Control interface clock input                                       |  |
| F3                            | SDA                                                                    | Digital Input / Output     | Control interface data input and output / 2-wire acknowledge output |  |
| A1                            | SPKGND1                                                                | Supply                     | Ground for speaker driver (Return path for SPKVDD1)                 |  |
| C1                            | SPKGND2                                                                | Supply                     | Ground for speaker driver (Return path for SPKVDD2)                 |  |
| A3                            | SPKMODE                                                                | Digital Input              | Mono / Stereo speaker mode select                                   |  |
| B1                            | SPKOUTLN                                                               | Analogue Output            | Left speaker negative output                                        |  |
| A2                            | SPKOUTLP                                                               | Analogue Output            | Left speaker positive output                                        |  |
| C3                            | SPKOUTRN                                                               | Analogue Output            | Right speaker negative output                                       |  |
| B3                            | SPKOUTRP                                                               | Analogue Output            | Right speaker positive output                                       |  |
| B2                            | SPKVDD1                                                                | Supply                     | Supply for speaker driver 1 (Left channel)                          |  |
| C2                            | SPKVDD2                                                                | Supply                     | Supply for speaker driver 2 (Right channel)                         |  |
| C9                            | VMIDC                                                                  | Analogue Output            | Midrail voltage decoupling capacitor                                |  |
| E6                            | VREFC                                                                  | Analogue Output            | Bandgap reference decoupling capacitor                              |  |

**Rev 4.6 9**


The following table identifies the power domain and ground reference associated with each of the input / output pins.

| PIN NO | NAME       | POWER DOMAIN        | GROUND DOMAIN |
|--------|------------|---------------------|---------------|
| F2     | ADCDAT1    | DBVDD               | DGND          |
| G3     | ADCLRCLK1/ | DBVDD               | DGND          |
|        | GPIO1      |                     |               |
| G1     | BCLK1      | DBVDD               | DGND          |
| G2     | CS¯¯ /ADDR | DBVDD               | DGND          |
| E4     | DACDAT1    | DBVDD               | DGND          |
| C6     | DMICCLK    | MICBIAS1            | AGND          |
| E1     | GPIO2/     | DBVDD               | DGND          |
|        | MCLK2      |                     |               |
| H2     | GPIO3/     | DBVDD               | DGND          |
|        | BCLK2      |                     |               |
| F4     | GPIO4/     | DBVDD               | DGND          |
|        | LRCLK2     |                     |               |
| H3     | GPIO5/     | DBVDD               | DGND          |
|        | DACDAT2    |                     |               |
| G4     | GPIO6/     | DBVDD               | DGND          |
|        | ADCLRCLK2  |                     |               |
| E5     | GPIO7/     | DBVDD               | DGND          |
|        | ADCDAT2    |                     |               |
| H4     | GPIO8/     | DBVDD               | DGND          |
|        | DACDAT3    |                     |               |
| F5     | GPIO9/     | DBVDD               | DGND          |
|        | ADCDAT3    |                     |               |
| H5     | GPIO10/    | DBVDD               | DGND          |
|        | LRCLK3     |                     |               |
| F6     | GPIO11/    | DBVDD               | DGND          |
|        | BCLK3      |                     |               |
| H6     | HPOUT1L    | CPVOUTP, CPVOUTN    | CPGND         |
| G6     | HPOUT1R    | CPVOUTP, CPVOUTN    | CPGND         |
| F9     | HPOUT2N    | CPVOUTP, CPVOUTN    | CPGND         |
| F8     | HPOUT2P    | CPVOUTP, CPVOUTN    | CPGND         |
| D7     | IN1LN      | AVDD1               | AGND          |
| C8     | IN1LP      | AVDD1               | AGND          |
| B7     | IN1RN      | AVDD1               | AGND          |
| C7     | IN1RP      | AVDD1               | AGND          |
| B9     | IN2LN/     | AVDD1 (IN2LN) or    | AGND          |
|        | DMICDAT1   | MICBIAS1 (DMICDAT1) |               |
| B8     | IN2LP/VRXN | AVDD1               | AGND          |
| A9     | IN2RN/     | AVDD1 (IN2RN) or    | AGND          |
|        | DMICDAT2   | MICBIAS1 (DMICDAT2) |               |
| A8     | IN2RP/VRXP | AVDD1               | AGND          |
| D4     | LDO1ENA    | DBVDD               | DGND          |
| D5     | LDO2ENA    | DBVDD               | DGND          |
| C5     | LINEOUT1N  | AVDD1               | AGND          |
| B5     | LINEOUT1P  | AVDD1               | AGND          |
| C4     | LINEOUT2N  | AVDD1               | AGND          |
| B4     | LINEOUT2P  | AVDD1               | AGND          |
| E3     | LRCLK1     | DBVDD               | DGND          |
| D3     | MCLK1      | DBVDD               | DGND          |
| H1     | SCLK       | DBVDD               | DGND          |

**10 Rev 4.6**