
## **TABLE OF CONTENTS**

<span id="page-0-0"></span>

| DESCRIPTION                                 | 1    |
|---------------------------------------------|------|
| FEATURES                                    | 1    |
| APPLICATIONS                                | 1    |
| TABLE OF CONTENTS                           |      |
| BLOCK DIAGRAM                               |      |
| PIN CONFIGURATION                           |      |
|                                             |      |
| ORDERING INFORMATION                        |      |
| PIN DESCRIPTION                             |      |
| ABSOLUTE MAXIMUM RATINGS                    |      |
| RECOMMENDED OPERATING CONDITIONS            | . 12 |
| THERMAL PERFORMANCE                         | . 13 |
| ELECTRICAL CHARACTERISTICS                  |      |
| INPUT SIGNAL LEVEL                          |      |
| INPUT PIN RESISTANCE                        |      |
| PROGRAMMABLE GAINS                          |      |
| OUTPUT DRIVER CHARACTERISTICS               | . 18 |
| ADC INPUT PATH PERFORMANCE                  | 10   |
| DAC OUTPUT PATH PERFORMANCE                 |      |
| BYPASS PATH PERFORMANCE                     |      |
| MULTI-PATH CROSSTALK                        |      |
| DIGITAL INPUT / OUTPUT                      |      |
| DIGITAL FILTER CHARACTERISTICS              |      |
| MICROPHONE BIAS CHARACTERISTICS             |      |
| MISCELLANEOUS CHARACTERISTICS               |      |
| TERMINOLOGY                                 |      |
| TYPICAL PERFORMANCE                         |      |
| TYPICAL POWER CONSUMPTION                   |      |
| TYPICAL SIGNAL LATENCY                      |      |
| SPEAKER DRIVER PERFORMANCE                  |      |
| SIGNAL TIMING REQUIREMENTS                  |      |
| SYSTEM CLOCKS & FREQUENCY LOCKED LOOP (FLL) |      |
| AUDIO INTERFACE TIMING                      |      |
| DIGITAL MICROPHONE (DMIC) INTERFACE TIMING  |      |
| DIGITAL MICROPHONE (DMIC) INTERFACE TIMING  |      |
| DIGITAL AUDIO INTERFACE - SLAVE MODE        |      |
| DIGITAL AUDIO INTERFACE - TDM MODE          |      |
| CONTROL INTERFACE TIMING                    |      |
| 2-WIRE (I2C) CONTROL MODE                   |      |
| 3-WIRE (SPI) CONTROL MODE                   |      |
| 4-WIRE (SPI) CONTROL MODE                   |      |
| DEVICE DESCRIPTION                          |      |
| INTRODUCTION                                |      |
| ANALOGUE INPUT SIGNAL PATH                  |      |
| MICROPHONE INPUTS                           |      |
| MICROPHONE BIAS CONTROL                     |      |
| MICROPHONE CURRENT DETECT                   |      |
| LINE AND VOICE CODEC INPUTS                 |      |
| INPUT PGA ENABLE                            |      |
| INPUT PGA CONFIGURATION                     | 48   |
|                                             |      |


| INPUT PGA VOLUME CONTROL                                                             | 50  |
|--------------------------------------------------------------------------------------|-----|
| INPUT MIXER ENABLE                                                                   |     |
| INPUT MIXER CONFIGURATION AND VOLUME CONTROL                                         |     |
| DIGITAL MICROPHONE INTERFACE                                                         |     |
| DIGITAL PULL-UP AND PULL-DOWN                                                        |     |
| ANALOGUE TO DIGITAL CONVERTER (ADC)                                                  |     |
| ADC CLOCKING CONTROL                                                                 |     |
| DIGITAL CORE ARCHITECTURE                                                            |     |
| DIGITAL MIXING                                                                       |     |
| AUDIO INTERFACE 1 (AIF1) OUTPUT MIXING                                               |     |
| DIGITAL SIDETONE MIXING                                                              |     |
| DIGITAL SIDETONE VOLUME AND FILTER CONTROL                                           |     |
| DAC OUTPUT DIGITAL MIXING                                                            |     |
| AUDIO INTERFACE 2 (AIF2) DIGITAL MIXING                                              |     |
| ULTRASONIC (4FS) AIF OUTPUT MODE                                                     |     |
| DYNAMIC RANGE CONTROL (DRC)                                                          |     |
| DRC COMPRESSION / EXPANSION / LIMITING                                               |     |
| GAIN LIMITS                                                                          |     |
| DYNAMIC CHARACTERISTICS                                                              | 75  |
| ANTI-CLIP CONTROL                                                                    |     |
| QUICK RELEASE CONTROL                                                                | 76  |
| SIGNAL ACTIVITY DETECT                                                               | 76  |
| DRC REGISTER CONTROLS                                                                |     |
| RETUNE MOBILE PARAMETRIC EQUALIZER (EQ)                                              |     |
| DEFAULT MODE (5-BAND PARAMETRIC EQ)                                                  |     |
| RETUNE MOBILE MODE                                                                   |     |
| EQ FILTER CHARACTERISTICS                                                            |     |
| 3D STEREO EXPANSION                                                                  |     |
| DIGITAL VOLUME AND FILTER CONTROL                                                    |     |
| AIF1 - OUTPUT PATH VOLUME CONTROL                                                    |     |
| AIF1 - OUTPUT PATH HIGH PASS FILTER                                                  |     |
| AIF1 - INPUT PATH VOLUME CONTROL                                                     |     |
| AIF1 - INPUT PATH SOFT MUTE CONTROL                                                  |     |
| AIF1 - INPUT PATH MONO MIX AND DE-EMPHASIS FILTER                                    |     |
| AIF2 - OUTPUT PATH VOLUME CONTROL                                                    |     |
| AIF2 - OUTPUT PATH HIGH PASS FILTER                                                  |     |
| AIF2 - INPUT PATH COLT MUTE CONTROL                                                  |     |
| AIF2 - INPUT PATH SOFT MUTE CONTROLAIF2 - INPUT PATH MONO MIX AND DE-EMPHASIS FILTER |     |
| DIGITAL TO ANALOGUE CONVERTER (DAC)                                                  |     |
| DAC CLOCKING CONTROL                                                                 |     |
| DAC CLOCKING CONTROL                                                                 |     |
| DAC SOFT MUTE AND SOFT UN-MUTE                                                       |     |
| ANALOGUE OUTPUT SIGNAL PATH                                                          |     |
| OUTPUT SIGNAL PATHS ENABLE                                                           |     |
| HEADPHONE SIGNAL PATHS ENABLE                                                        |     |
| OUTPUT MIXER CONTROL                                                                 |     |
| SPEAKER MIXER CONTROL                                                                |     |
| OUTPUT SIGNAL PATH VOLUME CONTROL                                                    |     |
| SPEAKER BOOST MIXER                                                                  |     |
| EARPIECE DRIVER MIXER                                                                |     |
| LINE OUTPUT MIXERS                                                                   |     |
| CHARGE PUMP                                                                          |     |
| DC SERVO                                                                             | 136 |
| DC SERVO ENABLE AND START-UP                                                         |     |
|                                                                                      |     |


| DC SERVO ACTIVE MODES                                 | 138 |
|-------------------------------------------------------|-----|
| GPIO / INTERRUPT OUTPUTS FROM DC SERVO                |     |
| ANALOGUE OUTPUTS                                      |     |
| SPEAKER OUTPUT CONFIGURATIONS                         | 140 |
| HEADPHONE OUTPUT CONFIGURATIONS                       |     |
| EARPIECE DRIVER OUTPUT CONFIGURATIONS                 |     |
| LINE OUTPUT CONFIGURATIONS                            |     |
| GENERAL PURPOSE INPUT/OUTPUT                          |     |
| GPIO CONTROL                                          | 148 |
| GPIO FUNCTION SELECT                                  |     |
| BUTTON DETECT (GPIO INPUT)                            |     |
| LOGIC '1' AND LOGIC '0' OUTPUT (GPIO OUTPUT)          |     |
| SDOUT (4-WIRE SPI CONTROL INTERFACE DATA)             |     |
| INTERRUPT (IRQ) STATUS OUTPUT                         |     |
| OVER-TEMPERATURE DETECTION                            |     |
| ACCESSORY DETECTION (MICBIAS CURRENT DETECTION)       |     |
| FREQUENCY LOCKED LOOP (FLL) LOCK STATUS OUTPUT        |     |
| SAMPLE RATE CONVERTER (SRC) LOCK STATUS OUTPUT        |     |
| DYNAMIC RANGE CONTROL (DRC) SIGNAL ACTIVITY DETECTION |     |
| CONTROL WRITE SEQUENCER STATUS DETECTION              |     |
| DIGITAL CORE FIFO ERROR STATUS DETECTION              |     |
| OPCLK CLOCK OUTPUT                                    |     |
| FLL CLOCK OUTPUT                                      | 158 |
| INTERRUPTS                                            | 159 |
| DIGITAL AUDIO INTERFACE                               | 166 |
| MASTER AND SLAVE MODE OPERATION                       | 167 |
| OPERATION WITH TDM                                    | 167 |
| AUDIO DATA FORMATS (NORMAL MODE)                      | 168 |
| AUDIO DATA FORMATS (TDM MODE)                         | 171 |
| DIGITAL AUDIO INTERFACE CONTROL                       | 173 |
| AIF1 - MASTER / SLAVE AND TRI-STATE CONTROL           | 173 |
| AIF1 - SIGNAL PATH ENABLE                             | 174 |
| AIF1 - BCLK AND LRCLK CONTROL                         | 174 |
| AIF1 - DIGITAL AUDIO DATA CONTROL                     | 177 |
| AIF1 - MONO MODE                                      | 178 |
| AIF1 - COMPANDING                                     | 179 |
| AIF1 - LOOPBACK                                       | 180 |
| AIF2 - MASTER / SLAVE AND TRI-STATE CONTROL           | 181 |
| AIF2 - SIGNAL PATH ENABLE                             | 182 |
| AIF2 - BCLK AND LRCLK CONTROL                         | 182 |
| AIF2 - DIGITAL AUDIO DATA CONTROL                     | 185 |
| AIF2 - MONO MODE                                      | 186 |
| AIF2 - COMPANDING                                     | 187 |
| AIF2 - LOOPBACK                                       | 187 |
| AUDIO INTERFACE AIF3 CONFIGURATION                    | 188 |
| DIGITAL PULL-UP AND PULL-DOWN                         |     |
| CLOCKING AND SAMPLE RATES                             | 191 |
| AIF1CLK ENABLE                                        | 192 |
| AIF1 CLOCKING CONFIGURATION                           | 193 |
| AIF2CLK ENABLE                                        | 195 |
| AIF2 CLOCKING CONFIGURATION                           | 195 |
| MISCELLANEOUS CLOCK CONTROLS                          | 197 |
| BCLK AND LRCLK CONTROL                                | 200 |
| CONTROL INTERFACE CLOCKING                            | 201 |
| FREQUENCY LOCKED LOOP (FLL)                           | 201 |

## **WM8994**


| FREE-RUNNING FLL CLOCK                                                                 | 206 |
|----------------------------------------------------------------------------------------|-----|
| GPIO OUTPUTS FROM FLL                                                                  | 207 |
| EXAMPLE FLL CALCULATION                                                                |     |
| EXAMPLE FLL SETTINGS                                                                   | 208 |
| SAMPLE RATE CONVERSION                                                                 | 209 |
| SAMPLE RATE CONVERTER 1 (SRC1)                                                         | 209 |
| SAMPLE RATE CONVERTER 2 (SRC2)                                                         | 209 |
| SAMPLE RATE CONVERTER RESTRICTIONS                                                     | 209 |
| SAMPLE RATE CONVERTER CONFIGURATION ERROR INDICATION                                   |     |
| CONTROL INTERFACE                                                                      |     |
| SELECTION OF CONTROL INTERFACE MODE                                                    | 212 |
| 2-WIRE (I2C) CONTROL MODE                                                              | 213 |
| 3-WIRE (SPI) CONTROL MODE                                                              | 216 |
| 4-WIRE (SPI) CONTROL MODE                                                              |     |
| CONTROL WRITE SEQUENCER                                                                | 218 |
| INITIATING A SEQUENCE                                                                  | 218 |
| PROGRAMMING A SEQUENCE                                                                 | 219 |
| DEFAULT SEQUENCES                                                                      |     |
| LDO REGULATORS                                                                         |     |
| POP SUPPRESSION CONTROL                                                                | 231 |
| DISABLED LINE OUTPUT CONTROL                                                           | 231 |
| LINE OUTPUT DISCHARGE CONTROL                                                          |     |
| VMID REFERENCE DISCHARGE CONTROL                                                       | 232 |
| INPUT VMID CLAMPS                                                                      | 232 |
| REFERENCE VOLTAGES AND MASTER BIAS                                                     |     |
| POWER MANAGEMENT                                                                       |     |
| THERMAL SHUTDOWN                                                                       | 241 |
| POWER ON RESET                                                                         |     |
| QUICK START-UP AND SHUTDOWN                                                            | 244 |
| SOFTWARE RESET AND DEVICE ID                                                           |     |
| REGISTER MAP                                                                           |     |
| REGISTER BITS BY ADDRESS                                                               |     |
| APPLICATIONS INFORMATION                                                               |     |
| RECOMMENDED EXTERNAL COMPONENTS                                                        |     |
|                                                                                        |     |
| AUDIO INPUT PATHS                                                                      |     |
| HEADPHONE OUTPUT PATH                                                                  |     |
| EARPIECE DRIVER OUTPUT PATH                                                            |     |
| LINE OUTPUT PATHS                                                                      |     |
| POWER SUPPLY DECOUPLING                                                                |     |
| CHARGE PUMP COMPONENTS                                                                 |     |
| MICROPHONE BIAS CIRCUIT                                                                |     |
| CLASS D SPEAKER CONNECTIONS                                                            |     |
| RECOMMENDED EXTERNAL COMPONENTS DIAGRAMDIGITAL AUDIO INTERFACE CLOCKING CONFIGURATIONS |     |
|                                                                                        |     |
| PCB LAYOUT CONSIDERATIONS                                                              |     |
| CLASS D LOUDSPEAKER CONNECTION                                                         |     |
| PACKAGE DIMENSIONS                                                                     |     |
| MPORTANT NOTICE                                                                        |     |
| REVISION HISTORY                                                                       | 363 |