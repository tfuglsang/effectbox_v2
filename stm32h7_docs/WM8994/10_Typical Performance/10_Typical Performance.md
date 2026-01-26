
# **TYPICAL PERFORMANCE**

## **TYPICAL POWER CONSUMPTION**

| OPERATING MODE                                                    | TEST CONDITIONS                                                           | SPKVDD<br>(Note 3) | LDO1VDD                  | AVDD2           | CPVDD           | DBVDD           | LDO2VDD                  | TOTAL  |
|-------------------------------------------------------------------|---------------------------------------------------------------------------|--------------------|--------------------------|-----------------|-----------------|-----------------|--------------------------|--------|
| Off (Battery Leakage only)                                        |                                                                           |                    |                          |                 |                 |                 |                          |        |
| LDO1 disabled,<br>LDO2 disabled                                   |                                                                           | 4.2V<br>1.1A      | 4.2V<br>0.4A            | 0.0V<br>5.5A   | 0.0V<br>5A     | 0.0V<br>9.3A   | 0.0V<br>0.2A            | 0.01mW |
| Standby                                                           |                                                                           |                    |                          |                 |                 |                 |                          |        |
| LDO1 disabled,<br>LDO2 enabled                                    | All supplies present,<br>No clocks,<br>Default register settings          | 4.2V<br>1.8A      | 4.2V<br>1A              | 1.8V<br>60A    | 1.8V<br>5A     | 1.8V<br>20A    | 1.8V<br>42A             | 0.2mW  |
| Standby                                                           |                                                                           |                    |                          |                 |                 |                 |                          |        |
| LDO1 enabled,<br>LDO2 enabled                                     | All supplies present,<br>No clocks,<br>Default register settings          | 4.2V<br>1.8A      | 4.2V<br>89A             | 1.8V<br>65A    | 1.8V<br>5A     | 1.8V<br>30A    | 1.8V<br>42A             | 0.6mW  |
|                                                                   | Music playback to Headphone (32ohm load)                                  |                    |                          |                 |                 |                 |                          |        |
| AIF1 to DAC to<br>HPOUT1 (stereo)                                 | fs=44.1kHz,<br>Clocking rate=256fs,<br>24-bit I2S, Slave mode             | 4.2V<br>0.0mA      | 4.2V<br>2.05mA           | 1.8V<br>0.32mA  | 1.8V<br>0.48mA  | 1.8V<br>0.04mA  | 1.8V<br>1.09mA           | 12.1mW |
| AIF1 to DAC to<br>HPOUT1 (stereo)<br>LDOs disabled,<br>See Note 5 | fs=44.1kHz,<br>Clocking rate=128fs,<br>24-bit I2S, Slave mode,<br>Class W | 3.6V<br>0.0mA      | AVDD1=<br>2.4V<br>1.43mA | 1.8V<br>0.21mA  | 1.8V<br>0.21mA  | 1.8V<br>0.01mA  | DCVDD=<br>1.0V<br>0.94mA | 5.34mW |
|                                                                   | Music playback to Class D speaker output (8ohm, 22H load)                |                    |                          |                 |                 |                 |                          |        |
| AIF1 to DAC to<br>SPKOUT (stereo)                                 | fs=44.1kHz,<br>Clocking rate=256fs,<br>24-bit I2S, Slave mode,            | 4.2V<br>1.65mA     | 4.2V<br>2.36mA           | 1.8V<br>1.24mA  | 1.8V<br>0.01mA  | 1.8V<br>0.04mA  | 1.8V<br>1.09mA           | 21.1mW |
|                                                                   | +7.5dB Class D boost                                                      |                    |                          |                 |                 |                 |                          |        |
| AIF1 to DAC to<br>SPKOUT (Left)                                   | fs=44.1kHz,<br>Clocking rate=256fs,<br>24-bit I2S, Slave mode,            | 4.2V<br>0.74mA     | 4.2V<br>2.34mA           | 1.8V<br>0.79mA  | 1.8V<br>0.01mA  | 1.8V<br>0.04mA  | 1.8V<br>1.09mA           | 16.4mW |
|                                                                   | +0.0dB Class D boost                                                      |                    |                          |                 |                 |                 |                          |        |
|                                                                   | AIF1 to AIF3 Mono Digital Bypass (eg. Bluetooth video call)               |                    |                          |                 |                 |                 |                          |        |
| AIF1(L) to AIF3(L),<br>AIF3(L) to AIF1(L)                         | fs=8kHz,<br>Clocking rate=256fs,<br>24-bit I2S, Slave mode                | 4.2V<br>0.0mA      | 4.2V<br>0.09mA           | 1.8V<br>0.07mA  | 1.8V<br>0.01mA  | 1.8V<br>0.08mA  | 1.8V<br>0.33mA           | 1.2mW  |
|                                                                   | AIF2 to AIF3 Mono Digital Bypass (eg. Bluetooth voice call)               |                    |                          |                 |                 |                 |                          |        |
| AIF2(L) to AIF3(L),<br>AIF3(L) to AIF2(L)                         | fs=8kHz,<br>Clocking rate=256fs,<br>24-bit I2S, Slave mode                | 4.2V<br>0.002mA    | 4.2V<br>0.089mA          | 1.8V<br>0.065mA | 1.8V<br>0.003mA | 1.8V<br>0.039mA | 1.8V<br>0.272mA          | 1.1mW  |

#### **Notes:**

- 1. AVDD1 = 3.0V, generated by LDO1
- 2. DCVDD = 1.0V, generated by LDO2
- 3. SPKVDD = SPKVDD1 = SPKVDD2.
- 4. ISPKVDD = ISPKVDD1 + ISPKVDD2.
- 5. Power consumption for music playback with LDOs disabled requires an external supply for AVDD1 and DCVDD

**Rev 4.6 31**


### **TYPICAL SIGNAL LATENCY**

| OPERATING MODE                                                                             |                                 | LATENCY                         |                |       |  |
|--------------------------------------------------------------------------------------------|---------------------------------|---------------------------------|----------------|-------|--|
|                                                                                            | AIF1                            | AIF2                            | DIGITAL CORE   |       |  |
| AIF2 to DAC Stereo Path                                                                    |                                 |                                 |                |       |  |
| AIF2 EQ enabled,<br>AIF2 3D enabled,                                                       | fs=8kHz,<br>Clock rate = 256fs  | fs=8kHz,<br>Clock rate = 1536fs | SYSCLK=AIF1CLK | 1.4ms |  |
| AIF2 DRC enabled,<br>SRC enabled                                                           | fs=48kHz,<br>Clock rate = 256fs | fs=8kHz,<br>Clock rate = 1536fs | SYSCLK=AIF1CLK | 1.3ms |  |
|                                                                                            | fs=8kHz,<br>Clock rate = 256fs  | fs=8kHz,<br>Clock rate = 256fs  | SYSCLK=AIF1CLK | 1.7ms |  |
|                                                                                            | fs=48kHz,<br>Clock rate = 256fs | fs=8kHz,<br>Clock rate = 256fs  | SYSCLK=AIF1CLK | 1.4ms |  |
| ADC to AIF2 Stereo Path                                                                    |                                 |                                 |                |       |  |
| Digital Sidetone HPF enabled,<br>AIF2 DRC enabled,                                         | fs=8kHz,<br>Clock rate = 256fs  | fs=8kHz,<br>Clock rate = 256fs  | SYSCLK=AIF1CLK | 2.2ms |  |
| AIF2 HPF enabled,<br>SRC enabled                                                           | fs=48kHz,<br>Clock rate = 256fs | fs=8kHz,<br>Clock rate = 256fs  | SYSCLK=AIF1CLK | 1.2ms |  |
| Digital Sidetone HPF disabled,<br>AIF2 DRC disabled,<br>AIF2 HPF disabled,<br>SRC disabled |                                 | fs=8kHz,<br>Clock rate = 1536fs | SYSCLK=AIF2CLK | 1.3ms |  |
| Digital Sidetone HPF disabled,<br>AIF2 DRC disabled,<br>AIF2 HPF disabled,<br>SRC enabled  | fs=48kHz,<br>Clock rate = 256fs | fs=8kHz,<br>Clock rate = 1536fs | SYSCLK=AIF1CLK | 1.1ms |  |

#### **Notes:**

- 1. These figures are relevant to typical voice call modes, assuming AIF2 is connected to the baseband processor
- 2. The SRC (Sample Rate Converter) is enabled automatically whenever required

**32 Rev 4.6**


### SPEAKER DRIVER PERFORMANCE

Typical speaker driver THD+N performance is shown below for Class D and Class AB modes. Curves are shown for typical SPKVDD supply voltage, gain and load conditions.

![](_page_2_Figure_4.jpeg)

Rev 4.6 33