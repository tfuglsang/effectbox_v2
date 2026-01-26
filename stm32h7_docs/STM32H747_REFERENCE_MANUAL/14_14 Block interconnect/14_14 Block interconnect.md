## **14 Block interconnect**

#### **14.1 Peripheral interconnect**

#### **14.1.1 Introduction**

Several peripherals have direct connections between them.

This enables autonomous communication and synchronization between peripherals, thus saving CPU resources and power consumption.

These hardware connections remove software latency, allow the design of a predictable system and result in a reduction of the number of pins and GPIOs.

#### <span id="page-0-0"></span>**14.1.2 Connection overview**

There are several types of connections.

• Asynchronous connections (A)

The source output signal is sampled by the destination clock, leading to introduction of a possible jitter in the latency between the source output event and the destination event detection

• Synchronous connections (S)

Both source and destination are synchronous (they run on the same clock), and the latency from the source to the destination is deterministic. No jitter is introduced.

• Immediate connections (I)

Either the source or the destination is an analog signal.

• Break/fault connection for TIM/HRTIM outputs (B)

The source output signal disables the timer outputs through a pure combinational logic path, without any latency.

**Table 100. Peripherals interconnect matrix (D2 domain) (1) (2)**

|           |      |                       |      |      |      |      |       |        |     |      |     |      |           |       |       | Destination |        |       |      |      |          |      |        |        |           |        |       |       |
|-----------|------|-----------------------|------|------|------|------|-------|--------|-----|------|-----|------|-----------|-------|-------|-------------|--------|-------|------|------|----------|------|--------|--------|-----------|--------|-------|-------|
|           |      |                       |      |      |      |      |       |        |     |      |     |      | D2 domain |       |       |             |        |       |      |      |          |      |        |        | D3 domain |        |       |       |
|           |      | Source                | APB1 |      |      |      |       |        |     | APB2 |     |      |           |       | AHB1  |             | AHB4   | APB4  |      |      |          |      |        |        |           |        |       |       |
|           |      |                       | TIM2 | TIM3 | TIM4 | TIM5 | TIM12 | LPTIM1 | DAC | CRS  | CAN | TIM1 | TIM8      | TIM15 | TIM16 | TIM17       | DFSDM1 | HRTIM | ADC1 | ADC2 | ETHERNET | ADC3 | LPTIM2 | LPTIM3 | LPTIM4    | LPTIM5 | COMP1 | COMP2 |
|           |      | TIM2                  | -    | S    | S    | -    | -     | -      | S   | -    | A   | S    | S         | S     | -     | -           | -      | S     | S    | S    | A        | S    | -      | -      | -         | -      | I     | I     |
|           |      | TIM3                  | S    | -    | S    | S    | -     | -      | -   | -    | A   | S    |           | S     | -     | -           | S      | S     | S    | S    | A        | S    | -      | -      | -         | -      | I     | I     |
|           |      | TIM4                  | S    | S    | -    | S    | S     | -      | S   | -    | -   | S    | S         | S     | -     | -           | S      | -     | S    | S    | -        | S    | -      | -      | -         | -      | -     | -     |
|           |      | TIM5                  | -    | -    | -    | -    | S     | -      | S   | -    | -   |      | S         |       | -     | -           | -      | -     | -    | -    | -        | S    | -      | -      | -         | -      | -     | -     |
|           |      | TIM6                  | -    | -    | -    | -    |       |        | S   | -    | -   | -    | -         | -     | -     | -           | S      | S     | S    | S    | -        | S    | -      | -      | -         | -      | -     | -     |
|           |      | TIM7                  | -    | -    | -    | -    |       |        | S   | -    | -   | -    | -         | -     | -     | -           | S      | S     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           | APB1 | TIM13                 | -    | -    | -    | -    | S     |        |     | -    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | TIM14                 | -    | -    | -    | -    | S     |        |     | -    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | LPTIM1                | -    | -    | -    | -    | -     | -      | A   | -    | -   | -    | -         | -     | -     | -           | A      | A     | A    | A    |          | A    | -      | -      | -         | -      | -     | -     |
|           |      | SPDIFRX               | -    | -    | -    | -    | -     | -      |     | -    | -   | -    | -         | -     | -     | S           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | OPAMP                 | -    | -    | -    | -    | -     | -      |     | -    | -   | -    | -         | -     | -     | -           | -      | A     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | CAN                   | -    | -    | -    | A    | -     | -      |     | -    | -   | -    | -         | -     | -     | -           | -      | A     | -    | -    | A        | -    | -      | -      | -         | -      | -     | -     |
|           |      | TIM1                  | S    | S    | S    | S    | -     | -      | S   | -    | -   | -    | S         | S     | -     | -           | S      | S     | S    | S    | -        | S    | -      | -      | -         | -      | I     | I     |
|           |      | TIM8                  | S    | -    | S    | S    | -     | -      | S   | -    | -   | -    | -         | -     | -     | -           | S      |       | S    | S    | -        | S    | -      | -      | -         | -      | I     | I     |
| D2 domain |      | TIM15                 | -    | S    | -    | -    | -     | -      | S   | -    | -   | S    | -         | -     | -     | -           |        | S     | S    | S    | -        | S    | -      | -      | -         | -      | I     | I     |
|           |      | TIM16                 | -    | -    | -    | -    | -     | -      | -   | -    | -   | -    | -         | S     | -     | -           | S      | S     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           | APB2 | TIM17                 | -    | -    | -    | -    | -     | -      | -   | -    | -   | -    | -         | S     | -     | -           |        | S     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | SAI1                  | A    | -    | -    | -    | -     | -      | -   | -    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | A      | -         | -      | -     | -     |
|           |      | SAI2                  | -    | -    | -    | A    | -     | -      | -   | -    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | -      | A         | -      | -     | -     |
|           |      | DFSDM1                | -    | -    | -    | -    | -     | -      | -   | -    | -   | B    | B         | B     | B     | B           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | HRTIM                 | -    | -    | -    | -    | -     | -      | A   | -    | A   | -    | -         | -     | -     | -           | S      | -     | A    | A    | A        | A    | -      | -      | -         | -      | -     | -     |
|           |      | ADC1                  | -    | -    | -    | -    | -     | -      | -   | -    | -   | A    | -         | -     | -     | -           | -      | A     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | ADC2                  | -    | -    | -    | -    | -     | -      | -   | -    | -   | -    | A         | -     | -     | -           | -      | A     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | ETH                   | A    | A    | -    | -    | -     | -      | -   | -    | A   | -    | -         | -     | -     | -           | -      |       | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           | AHB1 | USB1<br>(OTG_H<br>S1) | A    |      |      | A    | -     | -      |     | A    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |
|           |      | USB2<br>(OTG_<br>HS2) | A    |      |      | A    | -     | -      |     | A    | -   | -    | -         | -     | -     | -           | -      | -     | -    | -    | -        | -    | -      | -      | -         | -      | -     | -     |

- 1. Letters in the table correspond to the type of connection described in *[Section 14.1.2: Connection overview](#page-0-0)*
- 2. The "-" symbol in a gray cell means no interconnect.

**Table 101. Peripherals interconnect matrix (D3 domain) (1) (2)**

|           |      |        |      |           |      |      |       |        |     |     |     |      |           |       | Destination |       |        |           |      |      |          |              |        |        |        |        |
|-----------|------|--------|------|-----------|------|------|-------|--------|-----|-----|-----|------|-----------|-------|-------------|-------|--------|-----------|------|------|----------|--------------|--------|--------|--------|--------|
|           |      |        |      | D2 domain |      |      |       |        |     |     |     |      |           |       |             |       |        | D3 domain |      |      |          |              |        |        |        |        |
|           |      | Source |      | APB1      |      |      |       |        |     |     |     |      | APB2      |       |             |       |        |           | AHB1 |      |          | AHB4<br>APB4 |        |        |        |        |
|           |      |        | TIM2 | TIM3      | TIM4 | TIM5 | TIM12 | LPTIM1 | DAC | CRS | CAN | TIM1 | TIM8      | TIM15 | TIM16       | TIM17 | DFSDM1 | HRTIM     | ADC1 | ADC2 | ETHERNET | ADC3         | LPTIM2 | LPTIM3 | LPTIM4 | LPTIM5 |
|           |      | EXTI   | -    | -         | -    | -    | -     | -      | A   | -   | -   | -    | -         | -     | -           | -     | A      | -         | A    | A    | -        | -            | -      | -      | -      | -      |
|           |      | LPTIM2 | -    | -         | -    | -    | -     | -      | A   | -   | -   | -    | -         | -     | -           | -     | A      | A         | A    | A    | -        | A            | -      | A      | A      | A      |
|           |      | LPTIM3 | -    | -         | -    | -    | -     | -      | -   | -   | -   | -    | -         | -     | -           | -     | A      | -         | A    | A    | -        | A            | -      | -      | A      | A      |
|           |      | LPTIM4 | -    | -         | -    | -    | -     | -      | -   | -   | -   | -    | -         | -     | -           | -     | -      | -         | -    | -    | -        | -            | -      | A      | -      | A      |
|           | APB4 | LPTIM5 | -    | -         | -    | -    | -     | -      | -   | -   | -   | -    | -         | -     | -           | -     | -      | -         | -    | -    | -        | -            | -      | A      | A      | -      |
| D3 Domain |      | COMP1  | A    | A         | -    | -    | -     | A      | -   | -   | -   |      | A/B A/B B |       | B           | B     |        | A/B       | -    | -    | -        | -            | A      | -      | -      | -      |
|           |      | COMP2  | A    | A         | -    | -    | -     | A      | -   | -   | -   |      | A/B A/B B |       | B           | B     |        | A/B       | -    | -    | -        | -            | A      | -      | -      | -      |
|           |      | SAI4   | -    | -         | -    | -    | -     | -      | -   | -   | -   | -    | -         | -     | -           | -     | -      | -         | -    | -    | -        | -            | -      | A      | -      | A      |
|           |      | RTC    | -    | -         | -    | -    | -     | A      | -   | -   | -   | -    | -         | -     | A           | -     | -      | -         | -    | -    | -        | -            | A      | -      | -      | -      |
|           |      | ADC3   | -    | -         | -    | -    | -     | -      | -   | -   | -   | A    | A         | -     | -           | -     | -      | -         | -    | -    | -        | -            | -      | -      | -      | -      |
|           | AHB4 | RCC    | A    | -         | -    | -    | -     | -      | -   | A   | -   | -    | -         | A     | A           | A     | -      | -         | -    | -    | -        | -            | -      | -      | -      | -      |

<sup>1.</sup> Letters in the table correspond to the type of connection described in *[Section 14.1.2: Connection overview](#page-0-0)*.

<sup>2.</sup> The "-" symbol in a gray cell means no interconnect.

Table 102. Peripherals interconnect matrix details<sup>(1)</sup>

|        |         | Source                           |                        |        | Destination | า         |           | _    | Comment |  |  |
|--------|---------|----------------------------------|------------------------|--------|-------------|-----------|-----------|------|---------|--|--|
| Domain | Bus     | Peripheral                       | Signal                 | Signal | Peripheral  | Bus       | Domain    | Туре | Comment |  |  |
|        | APB2    | TIM1                             | TRGO                   | ITR0   |             |           |           | S    | -       |  |  |
|        | APBZ    | TIM8                             | TRGO                   | ITR1   |             |           |           | S    | -       |  |  |
|        | APB1    | TIM3                             | TRGO                   | ITR2   |             |           |           | S    | -       |  |  |
| D2     | APDI    | TIM4                             | TRGO                   | ITR3   |             |           |           | S    | -       |  |  |
|        |         | ETH                              | PPS                    | ITR4   |             |           |           | S    | -       |  |  |
|        | AHB1    | USB1                             | SOF                    | ITR5   |             |           |           | S    | -       |  |  |
|        |         | USB2                             | SOF                    | ITR6   |             |           |           | S    | -       |  |  |
|        |         | COMP1                            | comp1_out              | ETR1   | TIM2        | APB1      | D2        | I    | -       |  |  |
| D3     | APB4    | COMP2                            | comp2_out              | ETR2   | 111112      | , (I D I  | <i>D2</i> | I    | -       |  |  |
|        |         | RCC                              | lse_ck                 | ETR3   |             |           |           | Α    | -       |  |  |
| DO     | ADDO    | SAI1                             | SAI1_FS_A              | ETR4   |             |           |           | Α    | -       |  |  |
| D2     | APB2    | SAI1                             | SAI1 SAI1_FS_B ETR5    |        |             |           |           | Α    | -       |  |  |
|        |         | COMP1                            | comp1_out              | TI4_1  |             |           |           | 1    | -       |  |  |
| D3     | APB4    | COMP2                            | comp2_out              | TI4_2  |             |           |           | 1    | -       |  |  |
| D3     | AI D4   | COMP1 or<br>COMP2 <sup>(2)</sup> | comp1_out or comp2_out | TI4_3  |             |           |           | I    | -       |  |  |
|        | APB2    | TIM1                             | TRGO                   | ITR0   |             |           |           | S    | -       |  |  |
|        | APB1    | TIM2                             | TRGO                   | ITR1   |             |           |           | S    | -       |  |  |
| D2     | APB2    | TIM15                            | TRGO                   | ITR2   |             |           |           | S    | -       |  |  |
|        | APB1    | TIM4                             | TRGO                   | ITR3   |             |           |           | S    | -       |  |  |
|        | AHB1    | ETH                              | PPS                    | ITR4   | TIM3        | APB1      | D2        | S    | -       |  |  |
|        |         | COMP1                            | comp1_out              | ETR1   | 1 11110     | , ,, ,,,, | <i>52</i> | I    | -       |  |  |
|        |         | COMP1                            | comp1_out              | TI1_1  |             |           |           | I    | -       |  |  |
| D3     | APB4    | COMP2                            | comp2_out              | TI1_2  |             |           |           | I    | -       |  |  |
|        |         | COMP1 or<br>COMP2 <sup>(2)</sup> |                        | TI1_3  |             |           |           | I    | -       |  |  |
|        | APB2    | TIM1                             | TRGO                   | ITR0   |             |           |           | S    | -       |  |  |
| Do     | A D D 4 | TIM2                             | TRGO                   | ITR1   | TINAA       | APB1      | Do        | S    | -       |  |  |
| D2     | APB1    | TIM3                             | TRGO                   | ITR2   | TIM4        |           | D2        | S    | -       |  |  |
|        | APB2    | TIM8                             | TRGO                   | ITR3   |             |           |           | S    | -       |  |  |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |      | Source     |           |           | Destination | n    |        | -    | 0       |
|--------|------|------------|-----------|-----------|-------------|------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal    | Signal    | Peripheral  | Bus  | Domain | Type | Comment |
|        | APB2 | TIM1       | TRGO      | ITR0      |             |      |        | S    | -       |
|        | AFDZ | TIM8       | TRGO      | ITR1      |             |      |        | S    | -       |
|        |      | TIM3       | TRGO      | ITR2      |             |      |        | S    | -       |
|        | APB1 | TIM4       | TRGO      | ITR3      |             | APB1 |        | S    | -       |
|        |      | CAN        | SOC       | ITR6      | 1           |      |        | S    | -       |
| D2     | AHB1 | USB1       | SOF       | ITR7      | TIM5        |      | D2     | S    | -       |
|        | АПВІ | USB2       | SOF       | ITR8      |             |      |        | S    | -       |
|        | APB2 | SAI2       | SAI2_FS_A | ETR1      | -           |      |        | Α    | -       |
|        | AFDZ | SAI2       | SAI2_FS_B | ETR2      |             |      |        | Α    | -       |
|        | APB1 | CAN        | TMP       | TI1_1     |             |      |        | Α    | -       |
|        | APDI | CAN        | RTP       | TI1_2     |             |      |        | Α    | -       |
|        |      | TIM4       | TRGO      | ITR0      |             |      |        | S    | -       |
|        | APB1 | TIM5       | TRGO      | ITR1      | TIM12       | APB1 | D2     | S    | -       |
| D2     | APDI | TIM13      | OC1       | ITR2      | 1110112     | APDI | DZ     | S    | -       |
| D2     |      | TIM14      | OC1       | ITR3      | 1           |      |        | S    | -       |
|        | AHB1 | USB1       | SOF       | crs_sync2 | CRS         | APB1 | D2     | Α    | -       |
|        | АПВІ | USB2       | SOF       | crs_sync3 | CRS         | APB1 | D2     | Α    | -       |
| D3     | AHB4 | RCC        | lse_ck    | crs_sync1 | CRS         | APB1 | D2     | Α    | -       |

**Table 102. Peripherals interconnect matrix details(1) (continued)**

|        |      | Source     |                   |        | Destination |      |        | Type |         |
|--------|------|------------|-------------------|--------|-------------|------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal            | Signal | Peripheral  | Bus  | Domain |      | Comment |
|        | APB2 | TIM15      | TRGO              | ITR0   |             |      |        | S    | -       |
| D2     |      | TIM2       | TRGO              | ITR1   |             |      |        | S    | -       |
|        | APB1 | TIM3       | TRGO              | ITR2   |             |      |        | S    | -       |
|        |      | TIM4       | TRGO              | ITR3   |             |      |        | S    | -       |
|        |      | COMP1      | comp1_out         | ETR1   |             |      |        | I    | -       |
| D3     | APB4 | COMP2      | comp2_out         | ETR2   |             |      |        | I    | -       |
|        |      | ADC1       | adc1_awd1         | ETR3   |             |      |        | A    | -       |
| D2     | AHB1 | ADC1       | adc1_awd2         | ETR4   |             |      |        | A    | -       |
|        |      | ADC1       | adc1_awd3         | ETR5   | TIM1        |      |        | A    | -       |
|        |      | ADC3       | adc3_awd1         | ETR6   |             |      |        | A    | -       |
|        | AHB4 | ADC3       | adc3_awd2         | ETR7   |             | APB2 | D2     | A    | -       |
|        |      | ADC3       | adc3_awd3         | ETR8   |             |      |        | A    | -       |
| D3     |      | COMP1      | comp1_out         | TI1_1  |             |      |        | I    | -       |
|        | APB4 | COMP1      | comp1_out         | BRK_1  |             |      |        | B    | -       |
|        |      | COMP2      | comp2_out         | BRK_2  |             |      |        | B    | -       |
| D2     | APB2 | DFSDM1     | dfsdm1_<br>break0 | BRK_3  |             |      |        | B    | -       |
|        |      | COMP1      | comp1_out         | BRK2_1 |             |      |        | B    | -       |
| D3     | APB4 | COMP2      | comp2_out         | BRK2_2 |             |      |        | B    | -       |
| D2     | APB2 | DFSDM1     | dfsdm1_<br>break1 | BRK2_3 |             |      |        | B    | -       |

**Table 102. Peripherals interconnect matrix details(1) (continued)**

|        |      | Source                      |                   |        | Destination |      |        |      |         |
|--------|------|-----------------------------|-------------------|--------|-------------|------|--------|------|---------|
| Domain | Bus  | Peripheral                  | Signal            | Signal | Peripheral  | Bus  | Domain | Type | Comment |
|        | APB2 | TIM1                        | TRGO<br>ITR0      |        |             |      | S      | -    |         |
|        |      | TIM2                        | TRGO              | ITR1   |             |      |        | S    | -       |
| D2     | APB1 | TIM4                        | TRGO              | ITR2   |             |      |        | S    | -       |
|        |      | TIM5                        | TRGO              | ITR3   |             |      |        | S    | -       |
|        |      | COMP1                       | comp1_out         | ETR1   |             |      |        | I    | -       |
| D3     | APB4 | COMP2                       | comp2_out         | ETR2   |             |      |        | I    | -       |
|        |      | ADC2                        | adc2_awd1         | ETR3   | TIM8        |      |        | A    | -       |
| D2     | AHB1 | ADC2                        | adc2_awd2         | ETR4   |             |      |        | A    | -       |
|        |      | ADC2                        | adc2_awd3         | ETR5   |             |      |        | A    | -       |
|        |      | ADC3                        | adc3_awd1         | ETR6   |             |      |        | A    | -       |
|        | AHB4 | ADC3                        | adc3_awd2         | ETR7   |             | APB2 | D2     | A    | -       |
|        |      | ADC3                        | adc3_awd3         | ETR8   |             |      |        | A    | -       |
| D3     |      | COMP2                       | comp2_out         | TI1_1  |             |      |        | I    | -       |
|        | APB4 | COMP1                       | comp1_out         | BRK_1  |             |      |        | B    | -       |
|        |      | COMP2                       | comp2_out         | BRK_2  |             |      |        | B    | -       |
| D2     | APB2 | dfsdm1_<br>DFSDM1<br>break2 |                   | BRK_3  |             |      |        | B    | -       |
|        |      | COMP1                       | comp1_out         | BRK2_1 |             |      |        | B    | -       |
| D3     | APB4 | COMP2                       | comp2_out         | BRK2_2 |             |      |        | B    | -       |
| D2     | APB2 | DFSDM1                      | dfsdm1_<br>break3 | BRK2_3 |             |      |        | B    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

| Source Destination |         |            |                        |        |            |      |        |      |         |
|--------------------|---------|------------|------------------------|--------|------------|------|--------|------|---------|
| Domain             | Bus     | Peripheral | Signal                 | Signal | Peripheral | Bus  | Domain | Туре | Comment |
|                    | APB2    | TIM1       | TRGO                   | ITR0   |            |      |        | S    | -       |
|                    | APB1    | TIM3       | TRGO                   | ITR1   |            |      |        | S    | -       |
|                    | A DDO   | TIM16      | OC1                    | ITR2   |            |      |        | S    | -       |
| D2                 | APB2    | TIM17      | OC1                    | ITR3   |            |      |        | S    | -       |
|                    |         | TIM2       | CH1                    | TI1_1  |            |      |        | Α    | -       |
|                    | APB1    | TIM3       | CH1                    | TI1_2  |            |      |        | Α    | -       |
|                    |         | TIM4       | CH1                    | TI1_3  |            |      |        | Α    | -       |
|                    |         | RCC        | lse_ck                 | TI1_4  |            |      |        | Α    | -       |
| D3                 | AHB4    | RCC        | csi_ck                 | TI1_5  | TIM15      | APB2 | D2     | Α    | -       |
|                    |         | RCC        | MCO2                   | TI1_6  |            |      |        | Α    | -       |
|                    | APB1    | TIM2       | CH2                    | TI2_1  |            |      |        | Α    | -       |
| D2                 |         | TIM3       | CH2                    | TI2_2  |            |      |        | Α    | -       |
|                    |         | TIM4       | CH2                    | TI2_3  |            |      |        | Α    | -       |
| D3                 | APB4    | COMP1      | comp1_out              | BRK_1  |            |      |        | В    | -       |
|                    |         | COMP2      | comp2_out              | BRK_2  |            |      |        | В    | -       |
| D2                 | APB2    | DFSDM1     | dfsdm_<br>break0       | BRK_3  |            |      |        | В    | -       |
|                    | AHB4    | RCC        | lsi_ck                 | TI1_1  |            | APB2 | D2     | Α    | -       |
|                    |         | RCC        | lse_ck                 | TI1_2  |            |      |        | Α    | -       |
| D3                 | APB4    | RTC        | WKUP_IT                | TI1_3  |            |      |        | Α    | -       |
|                    |         | COMP1      | comp1_out              | BRK_1  | TIM16      |      |        | В    | -       |
|                    |         | COMP2      | comp2_out              | BRK_2  |            |      |        | В    | -       |
| D2                 | APB2    | DFSDM1     | dfsdm_<br>break1       | BRK_3  |            |      |        | В    | -       |
| D2                 | APB1    | SPDIFRX    | spdifrx_frame_<br>sync | TI1_1  |            |      |        | Α    | -       |
|                    | A LID 4 | RCC        | HSE_1MHZ               | TI1_2  |            |      |        | Α    | -       |
| Da                 | AHB4    | RCC        | MCO1                   | TI1_3  | TINAAT     | ٨٥٥٥ | Do     | Α    | -       |
| D3                 | A D D 4 | COMP1      | comp1_out              | BRK_1  | TIM17      | APB2 | D2     | В    | -       |
|                    | APB4    | COMP2      | comp2_out              | BRK_2  |            |      |        | В    | -       |
| D2                 | APB2    | DFSDM1     | dfsdm_<br>break2       | BRK_3  |            |      |        | В    | -       |

621/3556

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |             | Source     |            | Destination      |            |        |        |      |         |   |
|--------|-------------|------------|------------|------------------|------------|--------|--------|------|---------|---|
| Domain | Bus         | Peripheral | Signal     | Signal           | Peripheral | Bus    | Domain | Type | Comment |   |
| D3     | APB4        | COMP1      | comp1_out  | hrtim_evt11      |            |        |        |      | В       | - |
| D2     | APB2        | TIM1       | TRGO       | hrtim_evt12      |            | Ì      |        | В    | -       |   |
| D2     | AHB1        | ADC1       | adc1_awd1  | hrtim_evt13      |            |        |        | В    | -       |   |
| D3     | APB4        | COMP2      | OUT        | hrtim_evt21      |            |        |        | В    | -       |   |
|        | APB2        | TIM2       | TRGO       | hrtim_evt22      |            |        |        | В    | -       |   |
|        | AHB1        | ADC1       | adc1_awd2  | hrtim_evt23      |            |        |        | В    | -       |   |
|        | NC          | NC         | NC         | hrtim_evt31      |            |        |        | В    | -       |   |
|        | APB2        | TIM3       | TRGO       | hrtim_evt32      |            |        |        | В    | -       |   |
|        | AHB1        | ADC1       | adc1_awd3  | hrtim_evt33      |            |        |        | В    | -       |   |
| D2     | APB1        | OPAMP1     | opamp1_out | hrtim_evt41      |            |        |        | В    | -       |   |
|        | APBI        | TIM7       | TRGO       | hrtim_evt42      |            |        |        | В    | -       |   |
|        | AHB1        | ADC2       | adc2_awd1  | hrtim_evt43      |            |        |        | В    | -       |   |
|        | NC          | NC         | NC         | hrtim_evt51      |            |        |        | В    | -       |   |
|        | APB1        | LPTIM1     | lptim1_out | hrtim_evt52      |            |        |        | В    | -       |   |
|        | AHB1        | ADC2       | adc2_awd2  | hrtim_evt53      |            |        |        | В    | -       |   |
| D3     | APB4        | COMP1      | comp1_out  | hrtim_evt61      | LIDTIM     | 4 DD 0 | D2     | I    | -       |   |
| DO     | APB1        | TIM6       | TRGO       | hrtim_evt62      | HRTIM      | APB2   | D2     | S    | -       |   |
| D2     | AHB1        | ADC2       | adc2_awd3  | hrtim_evt63      |            |        |        |      | Α       | - |
| D3     | APB4        | COMP2      | comp2_out  | hrtim_evt71      |            |        |        | I    | -       |   |
|        | APB1        | TIM7       | TRGO       | hrtim_evt72      |            |        |        | S    | -       |   |
|        | NO          | NC         | NO         | hrtim_evt73      |            |        |        | -    | -       |   |
|        | NC          |            | NC         | hrtim_evt81      |            |        |        | -    | -       |   |
|        | APB1        | TIM6       | TRGO       | hrtim_evt82      |            |        |        | S    | -       |   |
| D2     | <b>ADD4</b> | CAN        | TTCAN_TMP  | hrtim_evt83      |            |        |        | Α    | -       |   |
|        | APB1        | OPAMP1     | opamp1_out | hrtim_evt91      |            |        |        | I    | -       |   |
|        | APB2        | TIM15      | TRGO       | hrtim_evt92      |            |        |        | S    | -       |   |
|        | APB1        | CAN        | TTCAN_RTP  | hrtim_evt93      |            |        |        | Α    | -       |   |
|        | NC          | NC         | NC         | hrtim_<br>evt101 |            |        |        |      | -       |   |
| D3     | APB4        | LPTIM2     | lptim2_out | hrtim_<br>evt102 |            |        |        | Α    | -       |   |
| D2     | APB1        | CAN        | TTCAN_SOC  | hrtim_<br>evt103 |            |        |        | Α    | -       |   |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

| Source Destination |      |            |                     |                     |            |      |        |      |         |
|--------------------|------|------------|---------------------|---------------------|------------|------|--------|------|---------|
| Domain             | Bus  | Peripheral | Signal              | Signal              | Peripheral | Bus  | Domain | Type | Comment |
| D3                 | APB4 | COMP1      | comp1_out           | hrtim_in_<br>flt1   |            |      |        | В    | -       |
| D3                 | AFD4 | COMP2      | comp2_out           | hrtim_in_<br>flt2   |            |      |        | В    | -       |
|                    | APB2 | TIM16      | ОС                  | hrtim_upd_en1       |            |      |        | S    | -       |
|                    | AFDZ | TIM17      | ОС                  | hrtim_upd_en2       |            |      |        | S    | -       |
|                    |      | TIM6       | TRGO                | hrtim_upd_en3       |            |      |        | S    | -       |
|                    | APB1 | TIM7       | TRGO                | hrtim_bm<br>_trg    | HRTIM      | APB2 | D2     | S    | -       |
| D2                 | APB2 | TIM16      | OC                  | hrtim_bm<br>_ck1    |            |      |        | S    | -       |
|                    |      | TIM17      | OC                  | hrtim_bm<br>_ck2    |            |      |        | S    | -       |
|                    | APB1 | TIM7       | TRGO                | hrtim_bm<br>_ck3    |            |      |        | S    | -       |
|                    |      | RTC        | rtc_alarm_a_<br>evt | lptim1_ext_<br>trg0 |            |      |        | Α    | -       |
|                    |      | RTC        | rtc_alarm_b_<br>evt | lptim1_ext_<br>trg1 |            |      |        | Α    | -       |
|                    |      | RTC        | rtc_tamp1_evt       | lptim1_ext_<br>trg2 |            |      |        | Α    | -       |
|                    |      | RTC        | rtc_tamp2_evt       | Iptim1_ext_<br>trg3 |            |      |        | Α    | -       |
| D3                 | APB4 | RTC        | rtc_tamp3_evt       | lptim1_ext_<br>trg4 |            | APB1 | D2     | Α    | -       |
|                    |      | COMP1      | comp1_out           | lptim1_ext_<br>trg5 |            |      |        | I    | -       |
|                    |      | COMP2      | comp2_out           | lptim1_ext_<br>trg6 |            |      |        | I    | -       |
|                    |      | COMP1      | comp1_out           | lptim1_in1_mu<br>x1 |            |      |        | -    | -       |
|                    |      | COMP2      | comp2_out           | lptim1_in2_mu<br>x2 |            |      |        | I    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |      | Source                | •                      | Destination         |            |        |        |      |                             |
|--------|------|-----------------------|------------------------|---------------------|------------|--------|--------|------|-----------------------------|
| Domain | Bus  | Peripheral            | Signal                 | Signal              | Peripheral | Bus    | Domain | Type | Comment                     |
|        |      | RTC                   | rtc_alarm_a_<br>evt    | Iptim2_ext_trg<br>0 |            |        |        | Α    | -                           |
|        |      | RTC                   | rtc_alarm_b_<br>evt    | Iptim2_ext_trg<br>1 |            |        |        | Α    | -                           |
|        |      | RTC                   |                        | Iptim2_ext_trg<br>2 |            |        |        | Α    | -                           |
|        |      | RTC                   | rtc_tamp2_evt          | Iptim2_ext_trg<br>3 |            |        |        | Α    | -                           |
|        |      | RTC                   | rtc_tamp3_evt          | Iptim2_ext_trg<br>4 |            | APB4   |        | Α    | -                           |
| D3     | APB4 | COMP1                 | comp1_out              | Iptim2_ext_trg<br>5 | LPTIM2     |        | D3     | I    | -                           |
|        |      | COMP2                 | comp2_out              | Iptim2_ext_trg<br>6 |            |        |        | I    | -                           |
|        |      | COMP1                 | comp1_out              | lptim2_in1_mu<br>x1 |            |        |        | I    | -                           |
|        |      | COMP2                 | comp2_out              | lptim2_in1_mu<br>x2 |            |        |        | I    | -                           |
|        |      | COMP1 or<br>COMP2 (2) | comp1_out or comp2_out | lptim2_in1_mu<br>x3 |            |        |        | I    | -                           |
|        |      | COMP2                 | comp2_out              | lptim2_in2_mu<br>x1 |            |        |        | I    | -                           |
|        |      | LPTIM2                | lptim2_out             | lptim3_ext_<br>trg0 | - LPTIM3   | A DD 4 |        | S    | If same kernel clock source |
| Da     | APB4 | NC                    | NC                     | lptim3_ext_<br>trg1 |            |        |        | -    | -                           |
| D3     |      | LPTIM4                | lptim4_out             | lptim3_ext_<br>trg2 |            |        |        | S    | If same kernel clock source |
|        |      | LPTIM5                | lptim5_out             | Iptim3_ext_<br>trg3 |            |        | D3     | S    | If same kernel clock source |
|        |      | SAI1                  | SAI1_FS_A              | lptim3_ext_<br>trg4 |            | APB4   | טט     | Α    | -                           |
| Da     | APB2 | SAI1                  | SAI1_FS_B              | Iptim3_ext_<br>trg5 |            |        |        | Α    | -                           |
| D2     |      | SAI4                  | SAI4_FS_A              | Iptim3_in1_<br>mux1 |            |        |        | Α    | -                           |
|        |      | SAI4                  | SAI4_FS_B              | lptim3_in1_<br>mux2 |            |        |        | Α    | -                           |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |      | Source     |            | Destination         |            |      |            |      | Comment                     |  |
|--------|------|------------|------------|---------------------|------------|------|------------|------|-----------------------------|--|
| Domain | Bus  | Peripheral | Signal     | Signal              | Peripheral | Bus  | Domain     | Type | Comment                     |  |
|        |      | LPTIM2     | lptim2_out | lptim4_ext_trg<br>0 |            | APB4 |            | S    | If same kernel clock source |  |
| D3     | APB4 | LPTIM3     | lptim3_out | lptim4_ext_trg<br>1 |            |      |            | S    | If same kernel clock source |  |
| D3     | AFD4 | NC         | NC         | lptim4_ext_trg<br>2 | LPTIM4     |      | D3         |      | -                           |  |
|        |      | LPTIM5     | lptim5_out | lptim4_ext_trg<br>3 | LF I IIVI4 |      | <i>D</i> 3 | S    | If same kernel clock source |  |
| D2     | APB2 | SAI2       | SAI2_FS_A  | lptim4_ext_trg<br>4 |            |      |            | Α    | -                           |  |
| D2     |      | SAI2       | SAI2_FS_B  | lptim4_ext_trg<br>5 |            |      |            | Α    | -                           |  |
|        |      | LPTIM2     | lptim2_out | lptim5_ext_trg<br>0 | LPTIM5     |      |            | S    | If same kernel clock source |  |
|        |      | LPTIM3     | lptim3_out | lptim5_ext_trg<br>1 |            |      | D3         | S    | If same kernel clock source |  |
| D3     | APB4 | LPTIM4     | lptim4_out | lptim5_ext_trg<br>2 |            | APB4 |            | S    | If same kernel clock source |  |
|        |      | SAI4       | SAI4_FS_A  | lptim5_ext_trg<br>3 |            |      |            | Α    | -                           |  |
|        |      | SAI4       | SAI4_FS_B  | lptim5_ext_trg<br>4 |            |      |            | Α    | -                           |  |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

| Source |      |            |                | Destination         |                               |      |        |      | Comment |
|--------|------|------------|----------------|---------------------|-------------------------------|------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal         | Signal              | Peripheral                    | Bus  | Domain | Type | Comment |
|        | APB2 | TIM1       | TRGO           | dac_ch1/2_trg<br>0  |                               |      |        | S    | -       |
|        |      | TIM2       | TRGO           | dac_ch1/2_trg<br>1  |                               |      |        | S    | -       |
|        |      | TIM4       | TRGO           | dac_ch1/2_trg<br>02 |                               |      |        | S    | -       |
|        | APB1 | TIM5       | TRGO           | dac_ch1/2_trg<br>3  | DAC<br>channel<br>1/channel 2 |      |        | S    | -       |
|        |      | TIM6       | TRGO           | dac_ch1/2_trg<br>4  |                               |      |        | S    | -       |
| D2     |      | TIM7       | TRGO           | dac_ch1/2_trg<br>5  |                               |      |        | S    | -       |
| DZ     | APB2 | TIM8       | TRGO           | dac_ch1/2_trg<br>6  |                               | APB1 | D2     | S    | -       |
|        |      | TIM15      | TRGO           | dac_ch1/2_trg<br>7  |                               |      |        | S    | -       |
|        |      | HRTIM1     | hrtim_dac_trg1 | dac_ch1/2_trg<br>8  |                               |      |        | S    | -       |
|        |      |            | hrtim_dac_trg2 | dac_ch1/2_trg<br>9  |                               |      |        | S    | -       |
|        | APB1 | LPTIM1     | lptim1_out     | dac_ch1/2_trg<br>10 |                               |      |        | S    | -       |
|        |      | LPTIM2     | lptim2_out     | dac_ch1/2_trg<br>11 |                               |      |        | S    | -       |
| D3     | APB4 | SYSCFG     | EXTI9          | dac_ch1/2_trg<br>12 |                               |      |        | S    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |        | Source     |                | Destination  |                |      |        |      | Comment |
|--------|--------|------------|----------------|--------------|----------------|------|--------|------|---------|
| Domain | Bus    | Peripheral | Signal         | Signal       | Peripheral     | Bus  | Domain | Туре | Comment |
|        |        | TIM1       | TRGO           | TRG0         |                |      |        | S    | -       |
|        | APB2   | TIM1       | TRGO2          | TRG1         |                |      |        | S    | -       |
|        | AFDZ   | TIM8       | TRGO           | TRG2         |                |      |        | S    | -       |
|        |        | TIM8       | TRGO2          | TRG3         |                |      |        | S    | -       |
|        | APB1   | TIM3       | TRGO           | TRG4         |                |      |        | S    | -       |
| D2     | AFDI   | TIM4       | TRGO           | TRG5         |                |      |        | S    | -       |
|        | APB2   | TIM16      | OC1            | TRG6         | DFSDM1         |      |        | S    | -       |
|        | APB1   | TIM6       | TRGO           | TRG7         |                | APB2 | D2     | S    | -       |
|        |        | TIM7       | TRGO           | TRG8         |                |      |        | S    | -       |
|        | APB2   | HRTIM1     | hrtim_adc_trg1 | TRG9         |                |      |        | S    | -       |
|        |        | HRTIM1     | hrtim_adc_trg3 | TRG10        |                |      |        | S    | -       |
| D3     | APB4   | SYSCFG     | EXTI11         | TRG24        |                |      |        | Α    | -       |
| D3     | APB4   | SYSCFG     | EXTI15         | TRG25        |                |      |        | Α    | -       |
| D2     | APB1   | LPTIM1     | lptim1_out     | TRG26        |                |      |        | Α    | -       |
| D3     | A DD 4 | LPTIM2     | lptim2_out     | TRG27        |                |      |        | Α    | -       |
| D3     | APB4   | LPTIM3     | lptim3_out     | TRG28        |                |      |        | Α    | -       |
|        |        | TIM1       | CC1            | adc_ext_trg0 |                |      |        | S    | -       |
|        | APB2   | TIM1       | CC2            | adc_ext_trg1 |                |      |        | S    | -       |
| D2     |        | TIM1       | CC3            | adc_ext_trg2 |                |      |        | S    | -       |
| D2     |        | TIM2       | CC2            | adc_ext_trg3 | ADC1<br>/ ADC2 | AHB1 | D2     | S    | -       |
|        | APB1   | TIM3       | TRGO           | adc_ext_trg4 | / ADOZ         |      |        | S    | -       |
|        |        | TIM4       | CC4            | adc_ext_trg5 |                |      |        | S    | -       |
| D3     | APB4   | SYSCFG     | EXTI11         | adc_ext_trg6 |                |      |        | Α    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |        | Source     |                |               | Destination   | _     |        |      |         |
|--------|--------|------------|----------------|---------------|---------------|-------|--------|------|---------|
| Domain | Bus    | Peripheral | Signal         | Signal        | Peripheral    | Bus   | Domain | Type | Comment |
|        |        | TIM8       | TRGO           | adc_ext_trg7  |               |       |        | S    | -       |
|        | APB2   | TIM8       | TRGO2          | adc_ext_trg8  |               |       |        | S    | -       |
|        | AFDZ   | TIM1       | TRGO           | adc_ext_trg9  |               |       |        | S    | -       |
|        |        | TIM1       | TRGO2          | adc_ext_trg10 |               |       |        | S    | -       |
|        |        | TIM2       | TRGO           | adc_ext_trg11 |               | ALID4 |        | S    | -       |
| D2     | APB1   | TIM4       | TRGO           | adc_ext_trg12 | ADC1<br>/ADC2 |       | Da     | S    | -       |
| D2     |        | TIM6       | TRGO           | adc_ext_trg13 |               |       |        | S    | -       |
|        | APB2   | TIM15      | TRGO           | adc_ext_trg14 |               | AHB1  | D2     | S    | -       |
|        | APB1   | TIM3       | CC4            | adc_ext_trg15 |               |       |        | S    | -       |
|        | APB2   | HRTIM1     | hrtim_adc_trg1 | adc_ext_trg16 |               |       |        | Α    | -       |
|        |        | HRTIM1     | hrtim_adc_trg3 | adc_ext_trg17 |               |       |        | Α    | -       |
|        |        | LPTIM1     | lptim1_out     | adc_ext_trg18 |               |       |        | Α    | -       |
| D3     | A DD 4 | LPTIM2     | lptim2_out     | adc_ext_trg19 |               |       |        | Α    | -       |
| D3     | APB4   | LPTIM3     | lptim3_out     | adc_ext_trg20 |               |       |        | Α    | -       |
|        | A DDO  | TIM1       | TRGO           | adc_jext_trg0 |               |       |        | S    | -       |
|        | APB2   | TIM1       | CC4            | adc_jext_trg1 | ADC1          |       |        | S    | -       |
| Da     |        | TIM2       | TRGO           | adc_jext_trg2 |               | ALID4 | Da     | S    | -       |
| D2     | A DD4  | TIM2       | CC1            | adc_jext_trg3 | / ADC2        | AHB1  | D2     | S    | -       |
|        | APB1   | TIM3       | CC4            | adc_jext_trg4 |               |       |        | S    | -       |
|        |        | TIM4       | TRGO           | adc_jext_trg5 |               |       |        | S    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |      | Source     |                | Destination    |                |      |        |      | 0       |
|--------|------|------------|----------------|----------------|----------------|------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal         | Signal         | Peripheral     | Bus  | Domain | Type | Comment |
| D3     | APB4 | SYSCFG     | EXTI15         | adc_jext_trg6  |                |      |        | Α    | -       |
|        |      | TIM8       | CC4            | adc_jext_trg7  |                | AHB1 |        | S    | -       |
|        | APB2 | TIM1       | TRGO2          | adc_jext_trg8  |                |      |        | S    | -       |
|        | AFBZ | TIM8       | TRGO           | adc_jext_trg9  | ADC1<br>/ ADC2 |      |        | S    | -       |
|        |      | TIM8       | TRGO2          | adc_jext_trg10 |                |      |        | S    | -       |
|        | APB1 | TIM3       | CC3            | adc_jext_trg11 |                |      |        | S    | -       |
| D2     |      | TIM3       | TRGO           | adc_jext_trg12 |                |      |        | S    | -       |
| D2     |      | TIM3       | CC1            | adc_jext_trg13 |                |      | D2     | S    | -       |
|        |      | TIM6       | TRGO           | adc_jext_trg14 |                |      |        | S    | -       |
|        |      | TIM15      | TRGO           | adc_jext_trg15 |                |      |        | S    | -       |
|        |      | HRTIM1     | hrtim_adc_trg2 | adc_jext_trg16 |                |      |        | Α    | -       |
|        |      | HRTIM1     | hrtim_adc_trg4 | adc_jext_trg17 |                |      |        | Α    | -       |
|        | APB1 | LPTIM1     | lptim1_out     | adc_jext_trg18 |                |      |        | Α    | -       |
| Da     | ADD4 | LPTIM2     | lptim2_out     | adc_jext_trg19 |                |      |        | Α    | -       |
| D3     | APB4 | LPTIM3     | lptim2_out     | adc_jext_trg20 |                |      |        | Α    | -       |

**Table 102. Peripherals interconnect matrix details(1) (continued)**

|        |      | Source     |                              | Destination   |            |      |        |      |         |
|--------|------|------------|------------------------------|---------------|------------|------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal                       | Signal        | Peripheral | Bus  | Domain | Type | Comment |
|        |      | TIM1       | CC1                          | adc_ext_trg0  |            |      |        | S    | -       |
|        | APB2 | TIM1       | CC2                          | adc_ext_trg1  |            |      |        | S    | -       |
| D2     |      | TIM1       | CC3                          | adc_ext_trg2  |            |      |        | S    | -       |
|        |      | TIM2       | CC2                          | adc_ext_trg3  |            |      |        | S    | -       |
|        | APB1 | TIM3       | TRGO                         | adc_ext_trg4  |            | AHB4 |        | S    | -       |
|        |      | TIM4       | CC4                          | adc_ext_trg5  |            |      |        | S    | -       |
| D3     | APB4 | SYSCFG     | EXTI11                       | adc_ext_trg6  |            |      |        | A    | -       |
|        | APB2 | TIM8       | TRGO                         | adc_ext_trg7  | ADC3       |      | D3     | S    | -       |
|        |      | TIM8       | TRGO2                        | adc_ext_trg8  |            |      |        | S    | -       |
|        |      | TIM1       | TRGO                         | adc_ext_trg9  |            |      |        | S    | -       |
|        |      | TIM1       | TRGO2                        | adc_ext_trg10 |            |      |        | S    | -       |
|        | APB1 | TIM2       | TRGO                         | adc_ext_trg11 |            |      |        | S    | -       |
|        |      | TIM4       | TRGO                         | adc_ext_trg12 |            |      |        | S    | -       |
| D2     |      | TIM6       | TRGO                         | adc_ext_trg13 |            |      |        | S    | -       |
|        | APB2 | TIM15      | TRGO                         | adc_ext_trg14 |            |      |        | S    | -       |
|        | APB1 | TIM3       | CC4                          | adc_ext_trg15 |            |      |        | S    | -       |
|        |      | HRTIM1     | hrtim_adc_trg1 adc_ext_trg16 |               |            |      |        | A    | -       |
|        | APB2 | HRTIM1     | hrtim_adc_trg3 adc_ext_trg17 |               |            |      |        | A    | -       |
|        |      | LPTIM1     | lptim1_out                   | adc_ext_trg18 |            |      |        | A    | -       |
|        |      | LPTIM2     | lptim2_out                   | adc_ext_trg19 |            |      |        | A    | -       |
| D3     | APB4 | LPTIM3     | lptim3_out                   | adc_ext_trg20 |            |      |        | A    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |        | Source     |                    | Destination    |            |        |        |      |         |
|--------|--------|------------|--------------------|----------------|------------|--------|--------|------|---------|
| Domain | Bus    | Peripheral | Signal             | Signal         | Peripheral | Bus    | Domain | Type | Comment |
|        | APB2   | TIM1       | TRGO               | adc_jext_trg0  |            |        |        | SI   | -       |
|        | AFBZ   | TIM1       | CC4                | adc_jext_trg1  |            |        |        | S    | -       |
| D2     |        | TIM2       | TRGO               | adc_jext_trg2  |            |        |        | S    | -       |
| DZ     | APB1   | TIM2       | CC1                | adc_jext_trg3  |            |        |        | S    | -       |
|        | AFDI   | TIM3       | CC4                | adc_jext_trg4  |            |        |        | S    | -       |
|        |        | TIM4       | TRGO               | adc_jext_trg5  |            |        |        | S    | -       |
| D3     | APB4   | SYSCFG     | EXTI15             | adc_jext_trg6  |            |        |        | Α    | -       |
|        |        | TIM8       | CC4                | adc_jext_trg7  |            | АНВ4   |        | S    | -       |
|        | ۵ ما م | TIM1       | TRGO2              | adc_jext_trg8  |            |        |        | S    | -       |
|        | APB2   | TIM8       | TRGO               | adc_jext_trg9  | ADC3       |        |        | S    | -       |
|        |        | TIM8       | TRGO2              | adc_jext_trg10 |            |        | D3     | S    | -       |
|        | APB1   | TIM3       | CC3                | adc_jext_trg11 |            |        |        | S    | -       |
|        |        | TIM3       | TRGO               | adc_jext_trg12 |            |        |        | S    | -       |
| D2     |        | TIM3       | CC1                | adc_jext_trg13 |            |        |        | S    | -       |
|        |        | TIM6       | TRGO               | adc_jext_trg14 |            |        |        | S    | -       |
|        | APB2   | TIM15      | TRGO               | adc_jext_trg15 |            |        |        | S    | -       |
|        |        | HRTIM1     | hrtim_adc_<br>trg2 | adc_jext_trg16 |            |        |        | Α    | -       |
|        |        | HRTIM1     | hrtim_adc_<br>trg4 | adc_jext_trg17 |            |        |        | Α    | -       |
|        | APB1   | LPTIM1     | OUT                | adc_jext_trg18 |            |        |        | Α    | -       |
| D3     | APB4   | LPTIM2     | OUT                | adc_jext_trg19 |            |        |        | Α    | -       |
| DS     | AFD4   | LPTIM3     | OUT                | adc_jext_trg20 |            |        |        | Α    | -       |
|        | ADDO   | TIM1       | OC5                | comp_blk1      |            |        |        | Ι    | -       |
|        | APB2   | TIM1       | OC3                | comp_blk2      |            |        |        | I    | -       |
| D2     | V DD4  | TIM3       | OC3                | comp_blk3      | COMP1      | A DD 4 | Da     | I    | -       |
| D2     | APB1   | TIM3       | OC4                | comp_blk4      | / COMP2    | APB4   | D3     | ı    | -       |
|        | A DDO  | TIM8       | OC5                | comp_blk5      |            |        |        | I    | -       |
|        | APB2   | TIM15      | OC1                | comp_blk6      |            |        |        | Ι    | -       |

Table 102. Peripherals interconnect matrix details<sup>(1)</sup> (continued)

|        |      | Source     |                    | Destination |              |            |        |      | 0       |
|--------|------|------------|--------------------|-------------|--------------|------------|--------|------|---------|
| Domain | Bus  | Peripheral | Signal             | Signal      | Peripheral   | Bus        | Domain | Type | Comment |
|        | APB1 | TIM2       | TRGO               | SWT0        | - FDCAN APB1 |            |        | Α    | -       |
|        | AFDI | TIM3       | TRGO               | SWT1        |              |            |        | Α    | -       |
|        | AHB1 | ETH        | PPS                | SWT2        |              |            |        | Α    | -       |
|        | APB2 | HRTIM1     | hrtim_dac_<br>trg1 | SWT3        |              | FDCAN APB1 | D2     | Α    | -       |
|        | APB1 | TIM2       | TRGO               | EVT0        |              |            |        | Α    | -       |
|        |      | TIM3       | TRGO               | EVT1        |              |            |        | Α    | -       |
| D2     | AHB1 | ETH        | PPS                | EVT2        |              |            |        | Α    | -       |
|        | APB2 | HRTIM1     | hrtim_dac_<br>trg1 | EVT3        |              |            |        | Α    | -       |
|        | APB1 | TIM2       | TRGO               | PTP0        |              |            |        | Α    | -       |
|        | AFDI | TIM3       | TRGO               | PTP1        | ETH          |            |        | Α    | -       |
|        | APB2 | HRTIM1     | hrtim_dac_<br>trg2 | PTP2        |              | AHB1       | D2     | Α    | -       |
|        | APB1 | CAN        | TMP                | PTP3        |              |            |        | Α    | -       |

<sup>1.</sup> Letters in the table correspond to the type of connection described in Section 14.1.2: Connection overview.

<span id="page-18-0"></span><sup>2.</sup> comp1\_out and comp2\_out are connected to the inputs of an OR gate. The output of this OR gate is connected to the The lptim2\_in1\_mux3 input.

### **14.2 Wakeup from low power modes**

The Extended interrupt and event controller module (EXTI) allows to wake up the system from Stop mode and/or a CPU from CStop mode. Wakeup events are coming from peripherals.

These events are handled by the EXTI either as Configurable events (**C**), or as Direct events (**D**). See *[Type](#page-20-0)* column in *[Table 103](#page-20-1)*. Refer to *Section 21: Extended interrupt and event controller (EXTI)* for further details.

Three types of peripheral output signals are connected to the EXTI input events:

- The wake up signals. These signals can be generated by the peripheral without any bus interface clock, they are referred to as xxx\_wkup in *[Table 103](#page-20-1)*. Some peripherals do not have this capability.
- The interrupt signals. These signals can be generated only if the peripheral bus interface clock is running. These interrupt signals are generally directly connected to the NVIC of CPU. They are referred to as xxx\_it.
- The signals, i.e. the pulses generated by the peripheral. Once a peripheral has generated a signal, no action (flag clearing) is required at peripheral level.

Each EXTI input event has a different wakeup capability or possible target (see *[Target](#page-20-2)* column in *[Table 103](#page-20-1)*):

- CPU1 wakeup (**CPU1**): the input event can be enabled to wake up the CPU1
- CPU2 wakeup (**CPU2**): the input event can be enabled to wake up the CPU2
- CPU1 and CPU2 wakeups (**CPU**): the input event can be enabled to wake up the CPU1 only, the CPU2 only, or both CPU1 and CPU2
- CPU1, CPU2 and D3 domain wakeup for autonomous Run mode (**ANY**): the input event can be enabled to wake up the CPU1 only, the CPU2 only, both CPU1 and CPU2, or the D3 domain only for an autonomous Run mode phase.

RM0399 Rev 4 633/3556

<span id="page-20-2"></span><span id="page-20-0"></span>Table 103. EXTI wakeup inputs<sup>(1)</sup>

<span id="page-20-1"></span>

| Source |        |            |                     | Dest   | _          |      |        |         |
|--------|--------|------------|---------------------|--------|------------|------|--------|---------|
| Domain | Bus    | Peripheral | Signal              | Signal | Peripheral | Type | Target | Comment |
|        |        |            | exti0_wkup          | WKUP0  |            |      |        | -       |
|        |        |            | exti1_wkup          | WKUP1  |            |      |        | -       |
|        |        |            | exti2_wkup          | WKUP2  |            |      |        | -       |
|        |        |            | exti3_wkup          | WKUP3  |            |      |        | -       |
|        |        |            | exti4_wkup          | WKUP4  |            |      |        | -       |
|        |        |            | exti5_wkup          | WKUP5  |            |      |        | -       |
|        |        |            | exti6_wkup          | WKUP6  |            |      |        | -       |
| Do     | V DD 4 | evecto     | exti7_wkup          | WKUP7  |            |      | ANY    | -       |
| D3     | APB4   | SYSCFG     | exti8_wkup          | WKUP8  |            | С    | ANY    | -       |
|        |        |            | exti9_wkup          | WKUP9  |            |      |        | -       |
|        |        |            | exti10_wkup         | WKUP10 |            |      |        | -       |
|        |        |            | exti11_wkup         | WKUP11 |            |      |        | -       |
|        |        |            | exti12_wkup         | WKUP12 |            |      |        | -       |
|        |        |            | exti13_wkup         | WKUP13 |            |      |        | -       |
|        |        |            | exti14_wkup         | WKUP14 | EXTI       |      |        | -       |
|        |        |            | exti15_wkup         | WKUP15 | LXII       |      |        | -       |
| D3     | AHB4   | PWR        | pvd_avd_wkup        | WKUP16 |            | С    | CPU    | -       |
| D3     | APB4   | RTC        | ALARMS              | WKUP17 |            | D    | CPU    | -       |
| D3     | APB4   | RTC        | TAMPER<br>TIMESTAMP | WKUP18 |            | O    | CPU    | -       |
| D3     | AHB4   | RCC        | CSS_LSE             |        |            |      |        | -       |
| D3     | APB4   | RTC        | WKUP                | WKUP19 |            | С    | ANY    | -       |
| D3     | APB4   | COMP1      | comp1_out           | WKUP20 |            | С    | ANY    | -       |
| D3     | APB4   | COMP2      | comp2_out           | WKUP21 |            | С    | ANY    | -       |
| D2     | APB1   | I2C1       |                     |        |            | С    | CPU    | -       |
| D2     | APB1   | I2C2       | i2c2_wkup           | WKUP23 |            | D    | CPU    | -       |
| D2     | APB1   | I2C3       | i2c3_wkup           | WKUP24 |            | D    | CPU    | -       |
| D2     | APB1   | I2C4       | i2c4_wkup           | WKUP25 |            | D    | ANY    | -       |
| D2     | APB2   | USART1     | usart1_wkup         | WKUP26 |            | D    | CPU    | -       |
| D2     | APB1   | USART2     | usart2_wkup         | WKUP27 |            | D    | CPU    | -       |

**Table 103. EXTI wakeup inputs(1) (continued)**

| Source |      |            |                | Destination          |      |      |        |         |  |
|--------|------|------------|----------------|----------------------|------|------|--------|---------|--|
| Domain | Bus  | Peripheral | Signal         | Signal<br>Peripheral |      | Type | Target | Comment |  |
| D2     | APB1 | USART3     | usart3_wkup    | WKUP28               |      | D    | CPU    | -       |  |
| D2     | APB2 | USART6     | usart6_wkup    | WKUP29               |      | D    | CPU    | -       |  |
| D2     | APB1 | UART4      | uart4_wkup     | WKUP30               |      | D    | CPU    | -       |  |
| D2     | APB1 | UART5      | uart5_wkup     | WKUP31               |      | D    | CPU    | -       |  |
| D2     | APB1 | UART7      | uart7_wkup     | WKUP32               |      | D    | CPU    | -       |  |
| D2     | APB1 | UART8      | uart8_wkup     | WKUP33               |      | D    | CPU    | -       |  |
| D3     | APB4 | LPUART     | lpuart_rx_wkup | WKUP34               |      | D    | ANY    | -       |  |
| D3     | APB4 | LPUART     | lpuart_tx_wkup | WKUP35               |      | D    | ANY    | -       |  |
| D2     | APB2 | SPI1       | spi1_wkup      | WKUP36               |      | D    | CPU    | -       |  |
| D2     | APB1 | SPI2       | spi2_wkup      | WKUP37               |      | D    | CPU    | -       |  |
| D2     | APB1 | SPI3       | spi3_wkup      | WKUP38               |      | D    | CPU    | -       |  |
| D2     | APB2 | SPI4       | spi4_wkup      | WKUP39               |      | D    | CPU    | -       |  |
| D2     | APB2 | SPI5       | spi5_wkup      | WKUP40               |      | D    | CPU    | -       |  |
| D3     | APB4 | SPI6       | spi6_wkup      | WKUP41               | EXTI | D    | ANY    | -       |  |
| D2     | APB1 | MDIOS      | mdios_wkup     | WKUP42               |      | D    | CPU    | -       |  |
| D2     | AHB1 | USB1       | usb1_wkup      | WKUP43               |      | D    | CPU    | -       |  |
| D2     | AHB1 | USB2       | usb2_wkup      | WKUP44               |      | D    | CPU    | -       |  |
| -      | -    | NC         | NC             | WKUP45               |      | -    | -      | -       |  |
| D1     | APB3 | DSI        | dsi_it         | WKUP46               |      | D    | CPU    | (1)     |  |
| D2     | APB1 | LPTIM1     | lptim1_wkup    | WKUP47               |      | D    | CPU    | -       |  |
| D3     | APB4 | LPTIM2     | lptim2_wkup    | WKUP48               |      | D    | ANY    | -       |  |
| D3     | APB4 | LPTIM2     | lptim2_out     | WKUP49               |      | C    | ANY    | (2)     |  |
| D3     | APB4 | LPTIM3     | lptim3_wkup    | WKUP50               |      | D    | ANY    | -       |  |
| D3     | APB4 | LPTIM3     | lptim3_out     | WKUP51               |      | C    | ANY    | (2)     |  |
| D3     | APB4 | LPTIM4     | lptim4_wkup    | WKUP52               |      | D    | ANY    | -       |  |
| D3     | APB4 | LPTIM5     | lptim5_wkup    | WKUP53               |      | D    | ANY    | -       |  |
| D2     | APB1 | SWPMI      | swpmi_wkup     | WKUP54               |      | D    | CPU    | -       |  |

Table 103. EXTI wakeup inputs<sup>(1)</sup> (continued)

|        |       | Source     | Dest               | <b>T.</b> | T          | 0    |        |         |  |  |  |  |             |        |  |   |     |
|--------|-------|------------|--------------------|-----------|------------|------|--------|---------|--|--|--|--|-------------|--------|--|---|-----|
| Domain | Bus   | Peripheral | Signal             | Signal    | Peripheral | Type | Target | Comment |  |  |  |  |             |        |  |   |     |
|        |       |            | pwr_wkup1_wkup     | WKUP55    |            |      |        | -       |  |  |  |  |             |        |  |   |     |
|        |       |            | pwr_wkup2_wkup     | WKUP56    |            |      |        | -       |  |  |  |  |             |        |  |   |     |
| Da     | ALID4 |            | pwr_wkup3_wkup     | WKUP57    |            | _    | CDLI   | -       |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | PWR        | pwr_wkup4_wkup     | WKUP58    |            | D    | CPU    | -       |  |  |  |  |             |        |  |   |     |
|        |       |            | pwr_wkup5_wkup     | WKUP59    |            |      |        | -       |  |  |  |  |             |        |  |   |     |
|        |       |            | pwr_wkup6_wkup     | WKUP60    |            |      |        | -       |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | RCC        | rcc_it             | WKUP61    |            | D    | CPU    | -       |  |  |  |  |             |        |  |   |     |
| D3     | APB4  | I2C4       | i2c4_ev_it         | WKUP62    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| טט     | AFD4  | I2C4       | i2c4_err_it        | WKUP63    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | APB4  | LPUART1    | lpuart1_it         | WKUP64    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | APB4  | SPI6       | spi6_it            | WKUP64    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
|        |       |            | bdma_ch0_it        | WKUP66    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
|        |       |            | bdma_ch1_it        | WKUP67    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
|        | AHB4  | BDMA       | bdma_ch2_it        | WKUP68    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| Da     |       |            | bdma_ch3_it        | WKUP69    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     |       |            | bdma_ch4_it WKUP70 |           | D          | CPU  | (1)    |         |  |  |  |  |             |        |  |   |     |
|        |       |            | bdma_ch5_it        | WKUP71    | EXTI       | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
|        |       |            |                    |           |            |      |        |         |  |  |  |  | bdma_ch6_it | WKUP72 |  | D | CPU |
|        |       |            | bdma_ch7_it        | WKUP73    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | DMAMUX2    | dmamux2_it         | WKUP74    |            |      | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | ADC3       | adc3_it            | WKUP75    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | APB4  | SAI4       | sai4_gbl_it        | WKUP76    |            | D    | CPU    | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | HSEM       | hsem_int0_it       | WKUP77    |            | D    | CPU1   | (1)     |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | HSEM       | hsem_int1_it       | WKUP78    |            | D    | CPU2   | (1)     |  |  |  |  |             |        |  |   |     |
| -      | -     | CPU2       | cpu2_sev_it        | WKUP79    |            | D    | CPU2   | (2)     |  |  |  |  |             |        |  |   |     |
| -      | -     | CPU1       | cpu1_sev_it        | WKUP80    |            | D    | CPU1   | (2)     |  |  |  |  |             |        |  |   |     |
| -      | -     | NC         | NC                 | WKUP81    |            | -    | -      | -       |  |  |  |  |             |        |  |   |     |
| D1     | APB3  | WWDG1      | wwdg1_out_rst      | WKUP82    |            | С    | CPU1   | (1)     |  |  |  |  |             |        |  |   |     |
| -      | -     | NC         | NC                 | WKUP83    |            | -    | -      | -       |  |  |  |  |             |        |  |   |     |
| D1     | APB1  | WWDG2      | wwdg2_out_rst      | WKUP84    |            | С    | CPU2   | (1)     |  |  |  |  |             |        |  |   |     |
| D1     | APB1  | CEC        | cec_wkup           | WKUP85    |            | С    | CPU    | -       |  |  |  |  |             |        |  |   |     |
| D2     | AHB1  | ETH        | eth                | WKUP86    |            | С    | CPU    | -       |  |  |  |  |             |        |  |   |     |
| D3     | AHB4  | RCC        | hse_css_rcc_wkup   | WKUP87    |            | D    | CPU    | -       |  |  |  |  |             |        |  |   |     |

<span id="page-23-0"></span>1. The source peripheral needs its bus clock in order to generate the event. This is either PCLK4 or HCLK4 in D3 domain, PCLK3 in D1 domain.

<span id="page-23-1"></span>2. The source peripheral signal is not connected to the NVIC.

The Extended Interrupt and Event Controller (EXTI) module event inputs able to wake up the D3 domain for autonomous Run mode have a pending request logic that can be cleared by 4 different input sources (*Table 104*). Refer to *Section 21: Extended interrupt and event controller (EXTI)* for further details.

Table 104. EXTI pending requests clear inputs

<span id="page-23-2"></span>

|        |      | Source      |                                      | D                  | Comment    |      |        |   |
|--------|------|-------------|--------------------------------------|--------------------|------------|------|--------|---|
| Domain | Bus  | Peripheral  | Signal                               | Signal             | Peripheral | Bus  | Domain |   |
|        | AHB4 | 34 DMAMUX2  | dmamux2_evt6                         | d3_pendclear_in[0] |            |      |        | - |
| D3     | АПБ4 | DIVIAIVIUAZ | dmamux2_evt7 d3_pendclear_in[1] EXTI | APB4               | D3         | -    |        |   |
|        | APB4 | LPTIM4      | lptim4_out                           | d3_pendclear_in[2] |            | AFD4 | DЗ     | - |
|        | APB4 | LPTIM5      | lptim5_out                           | d3_pendclear_in[3] |            |      |        | - |

#### **14.3 DMA**

In D1 domain, the MDMA allows the memory to transfer data. It can be triggered by software or by hardware, according to the connections described in *[Section 14.3.1](#page-25-0)*.

DMA Multiplexer in D2 domain (DMAMUX1) allows to map any peripheral DMA request to any stream of the DMA1 or the DMA2. In addition to this, The DMAMUX provides two other functionalities:

- It's possible to synchronize a peripheral DMA request with a timer, with an external pin or with a DMA transfer complete of another stream.
- DMA requests can be generated on a stream by the DMAMUX1 itself. This event can be triggered by a timer, by an external pin event, or by a DMA transfer complete of another stream. The number of DMA requests generated is configurable.

The connections on DMAMUX1 and DMA1/DMA2 are described in *Section 18: DMA request multiplexer (DMAMUX)*, *Section 16: Direct memory access controller (DMA)* and *Section 17: Basic direct memory access controller (BDMA)*.

DMA Multiplexer in D3 domain (DMAMUX2) has the same functionality of DMAMUX1, it is connected to the basic DMA (BDMA).

The connections on DMAMUX2 and BDMA are described in *[Section 14.3.3: DMAMUX2,](#page-32-0)  [BDMA \(D3 domain\)](#page-32-0)*. Refer to *[Section 14.3.3: DMAMUX2, BDMA \(D3 domain\)](#page-32-0)* and *Section 17: Basic direct memory access controller (BDMA)* for more details.

# <span id="page-25-0"></span>14.3.1 MDMA (D1 domain)

Table 105. MDMA

|        |      | Source     |            |            | Destination | Commont |        |                                      |
|--------|------|------------|------------|------------|-------------|---------|--------|--------------------------------------|
| Domain | Bus  | Peripheral | Signal     | Signal     | Peripheral  | Bus     | Domain | Comment                              |
|        |      |            | dma1_tcif0 | mdma_str0  |             |         |        | DMA1 stream 0 transfer complete      |
|        |      |            | dma1_tcif1 | mdma_str1  |             |         |        | DMA1 stream 1 transfer complete      |
|        |      |            | dma1_tcif2 | mdma_str2  |             |         |        | DMA1 stream 2 transfer complete      |
| D2     | AHB1 | DMA1       | dma1_tcif3 | mdma_str3  |             |         |        | DMA1 stream 3 transfer complete      |
| D2     | AUDI | DIVIAT     | dma1_tcif4 | mdma_str4  |             |         |        | DMA1 stream 4 transfer complete      |
|        |      |            | dma1_tcif5 | mdma_str5  |             |         |        | DMA1 stream 5 transfer complete flag |
|        |      |            | dma1_tcif6 | mdma_str6  |             |         |        | DMA1 stream 6 transfer complete      |
|        |      |            | dma1_tcif7 | mdma_str7  |             |         |        | DMA1 stream 7 transfer complete      |
|        |      |            | dma2_tcif0 | mdma_str8  | MDMA        | AXI     | D1     | DMA2 stream 0 transfer complete      |
|        |      |            | dma2_tcif1 | mdma_str9  |             |         |        | DMA2 stream 1 transfer complete      |
|        |      |            | dma2_tcif2 | mdma_str10 |             |         |        | DMA2 stream 2 transfer complete      |
| D2     | AHB1 | DMA2       | dma2_tcif3 | mdma_str11 |             |         |        | DMA2 stream 3 transfer complete      |
| DΖ     | АПВІ | DIVIAZ     | dma2_tcif4 | mdma_str12 |             |         |        | DMA2 stream 4 transfer complete      |
|        |      |            | dma2_tcif5 | mdma_str13 |             |         |        | DMA2 stream 5 transfer complete      |
|        |      |            | dma2_tcif6 | mdma_str14 |             |         |        | DMA2 stream 6 transfer complete      |
|        |      |            | dma2_tcif7 | mdma_str15 |             |         |        | DMA2 stream 7 transfer complete      |
| D1     | APB3 | LTDC       | ltdc_li_it | mdma_str16 |             |         |        | LTDC line interrupt                  |

#### Table 105. MDMA (continued)

|        |      | Source     |                        |            | Destination | 0   |        |                                   |
|--------|------|------------|------------------------|------------|-------------|-----|--------|-----------------------------------|
| Domain | Bus  | Peripheral | Signal                 | Signal     | Peripheral  | Bus | Domain | Comment                           |
|        |      |            | jpeg_ift_trg           | mdma_str17 |             |     |        | JPEG input FIFO threshold         |
|        |      |            | jpeg_ifnt_trg          | mdma_str18 |             |     |        | JPEG input FIFO not full          |
| D1     | AHB3 | JPEG       | jpeg_oft_trg           | mdma_str19 |             |     |        | JPEG output FIFO<br>threshold     |
|        |      |            | jpeg_ofne_trg          | mdma_str20 |             |     |        | JPEG output FIFO not empty        |
|        |      |            | jpeg_oec_trg           | mdma_str21 |             |     |        | JPEG end of conversion            |
|        |      |            | quadspi_ft_trg         | mdma_str22 |             |     |        | QUADSPI FIFO threshold            |
| D1     | AHB3 | QUADSPI    | quadspi_tc_trg         | mdma_str23 |             |     |        | QUADSPI transfer complete         |
|        |      |            | dma2d_clut_trg         | mdma_str24 |             |     |        | DMA2D CLUT transfer complete      |
| D1     | AHB3 | DMA2D      | dma2d_tc_trg           | mdma_str25 | MDMA        | AXI | D1     | DMA2D transfer complete           |
|        |      |            | dma2d_tw_trg           | mdma_str26 |             |     |        | DMA2D transfer<br>watermark       |
| D1     | APB3 | DSI        | dsi_te_trg             | mdma_str27 |             |     |        | Tearing effect                    |
| וט     | ALDS | וטט        | dsi_eor_trg            | mdma_str28 |             |     |        | End of refresh                    |
|        |      |            | sdmmc1_<br>buffend_trg | mdma_str30 |             |     |        | SDMMC1 internal DMA<br>buffer end |
| D1     | AHB3 | SDMMC1     | sdmmc1_<br>cmdend_trg  | mdma_str31 |             |     |        | SDMMC1 command end                |
|        |      |            | sdmmc1_<br>dataend_trg | mdma_str29 |             |     |        | End of data                       |

#### **14.3.2 DMAMUX1, DMA1 and DMA2 (D2 domain)**

**Table 106. DMAMUX1, DMA1 and DMA2 connections(1)**

| Source |      |            |                     | Destination      |                  |                  |        |         |             |                  |  |  |
|--------|------|------------|---------------------|------------------|------------------|------------------|--------|---------|-------------|------------------|--|--|
| Domain | Bus  | Peripheral | Signal              | Signal           | Peripheral       | Bus              | Domain | Comment |             |                  |  |  |
|        |      |            |                     |                  |                  | dmamux1_req_in1  |        |         |             |                  |  |  |
|        |      |            |                     | dmamux1_req_in2  |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | dmamux1_req_in3  |                  |                  |        |         |             |                  |  |  |
|        |      |            | dmamux1 internal    | dmamux1_req_in4  |                  |                  |        |         |             |                  |  |  |
| D3     | AHB4 |            | (Request generator) | NC               |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | NC               |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | NC               |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | NC               |                  |                  |        |         |             |                  |  |  |
| D2     | AHB1 | ADC1       | adc1_dma            | dmamux1_req_in9  |                  |                  |        |         |             |                  |  |  |
| D2     | AHB1 | ADC2       | adc2_dma            | dmamux1_req_in10 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim1_ch1_dma        | dmamux1_req_in11 |                  |                  |        |         |             |                  |  |  |
|        | APB2 |            |                     |                  | tim1_ch2_dma     | dmamux1_req_in12 |        |         |             |                  |  |  |
|        |      |            |                     | tim1_ch3_dma     | dmamux1_req_in13 |                  |        |         |             |                  |  |  |
| D2     |      | TIM1       | tim1_ch4_dma        | dmamux1_req_in14 |                  |                  | D2     |         |             |                  |  |  |
|        |      |            | tim1_up_dma         | dmamux1_req_in15 |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | tim1_trig_dma    | dmamux1_req_in16 | DMAMUX1          | AHB1   |         | Requests    |                  |  |  |
|        |      |            | tim1_com_dma        | dmamux1_req_in17 |                  |                  |        |         |             |                  |  |  |
|        |      | TIM2       | tim2_ch1_dma        | dmamux1_req_in18 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim2_ch2_dma        | dmamux1_req_in19 |                  |                  |        |         |             |                  |  |  |
| D2     | APB1 |            | tim2_ch3_dma        | dmamux1_req_in20 |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     | tim2_ch4_dma     | dmamux1_req_in21 |                  |        |         |             |                  |  |  |
|        |      |            |                     |                  |                  |                  |        |         | tim2_up_dma | dmamux1_req_in22 |  |  |
|        |      |            | tim3_ch1_dma        | dmamux1_req_in23 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim3_ch2_dma        | dmamux1_req_in24 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim3_ch3_dma        | dmamux1_req_in25 |                  |                  |        |         |             |                  |  |  |
| D2     | APB1 | TIM3       | tim3_ch4_dma        | dmamux1_req_in26 |                  |                  |        |         |             |                  |  |  |
|        |      |            |                     |                  | tim3_up_dma      | dmamux1_req_in27 |        |         |             |                  |  |  |
|        |      |            | tim3_trig_dma       | dmamux1_req_in28 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim4_ch1_dma        | dmamux1_req_in29 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim4_ch2_dma        | dmamux1_req_in30 |                  |                  |        |         |             |                  |  |  |
| D2     | APB1 | TIM4       | tim4_ch3_dma        | dmamux1_req_in31 |                  |                  |        |         |             |                  |  |  |
|        |      |            | tim4_up_dma         | dmamux1_req_in32 |                  |                  |        |         |             |                  |  |  |

**Table 106. DMAMUX1, DMA1 and DMA2 connections(1) (continued)**

|        |      | Source     |               | Destination      |                  |      |        |          |  |
|--------|------|------------|---------------|------------------|------------------|------|--------|----------|--|
| Domain | Bus  | Peripheral | Signal        | Signal           | Peripheral       | Bus  | Domain | Comment  |  |
|        |      |            | i2c1_rx_dma   | dmamux1_req_in33 |                  |      |        |          |  |
| D2     | APB1 | I2C1       | i2c1_tx_dma   | dmamux1_req_in34 |                  |      |        |          |  |
|        |      |            | i2c2_rx_dma   | dmamux1_req_in35 |                  |      |        |          |  |
| D2     | APB1 | I2C2       | i2c2_tx_dma   | dmamux1_req_in36 |                  |      |        |          |  |
|        |      |            | spi1_rx_dma   | dmamux1_req_in37 |                  |      |        |          |  |
| D2     | APB2 | SPI1       | spi1_tx_dma   | dmamux1_req_in38 |                  |      |        |          |  |
| D2     | APB1 | SPI2       | spi2_rx_dma   | dmamux1_req_in39 |                  |      |        |          |  |
|        |      |            | spi2_tx_dma   | dmamux1_req_in40 |                  |      |        |          |  |
|        |      |            | usart1_rx_dma | dmamux1_req_in41 |                  |      |        |          |  |
| D2     | APB2 | USART1     | usart1_tx_dma | dmamux1_req_in42 |                  |      |        |          |  |
|        |      |            | usart2_rx_dma | dmamux1_req_in43 |                  |      |        |          |  |
| D2     | APB1 |            | USART2        | usart2_tx_dma    | dmamux1_req_in44 |      |        |          |  |
|        |      |            | usart3_rx_dma | dmamux1_req_in45 |                  |      |        |          |  |
| D2     | APB1 | USART3     | usart3_tx_dma | dmamux1_req_in46 | DMAMUX1          |      |        | Requests |  |
|        | APB2 | TIM8       | tim8_ch1_dma  | dmamux1_req_in47 |                  |      |        |          |  |
|        |      |            | tim8_ch2_dma  | dmamux1_req_in48 |                  |      |        |          |  |
|        |      |            | tim8_ch3_dma  | dmamux1_req_in49 |                  | AHB1 | D2     |          |  |
| D2     |      |            | tim8_ch4_dma  | dmamux1_req_in50 |                  |      |        |          |  |
|        |      |            | tim8_up_dma   | dmamux1_req_in51 |                  |      |        |          |  |
|        |      |            | tim8_trig_dma | dmamux1_req_in52 |                  |      |        |          |  |
|        |      |            | tim8_com_dma  | dmamux1_req_in53 |                  |      |        |          |  |
| -      | -    | NC         | NC            | NC               |                  |      |        |          |  |
|        |      |            | tim5_ch1_dma  | dmamux1_req_in55 |                  |      |        |          |  |
|        |      |            | tim5_ch2_dma  | dmamux1_req_in56 |                  |      |        |          |  |
|        |      |            | tim5_ch3_dma  | dmamux1_req_in57 |                  |      |        |          |  |
| D1     | APB1 | TIM3       | tim5_ch4_dma  | dmamux1_req_in58 |                  |      |        |          |  |
|        |      |            | tim5_up_dma   | dmamux1_req_in59 |                  |      |        |          |  |
|        |      |            | tim5_trig_dma | dmamux1_req_in60 |                  |      |        |          |  |
|        |      |            | spi3_rx_dma   | dmamux1_req_in61 |                  |      |        |          |  |
| D2     | APB1 | SPI3       | spi3_tx_dma   | dmamux1_req_in62 |                  |      |        |          |  |
|        |      |            | uart4_rx_dma  | dmamux1_req_in63 |                  |      |        |          |  |
| D1     | APB1 | UART4      | uart4_tx_dma  | dmamux1_req_in64 |                  |      |        |          |  |

**Table 106. DMAMUX1, DMA1 and DMA2 connections(1) (continued)**

|        |      | Source     |                | Destination      |                  |      |        |          |  |
|--------|------|------------|----------------|------------------|------------------|------|--------|----------|--|
| Domain | Bus  | Peripheral | Signal         | Signal           | Peripheral       | Bus  | Domain | Comment  |  |
|        |      |            | uart5_rx_dma   | dmamux1_req_in65 |                  |      |        |          |  |
| D1     | APB1 | UART5      | uart5_tx_dma   | dmamux1_req_in66 |                  |      |        |          |  |
| D2     | APB1 | DAC1       | dac_ch1_dma    | dmamux1_req_in67 |                  |      |        |          |  |
| D2     | APB1 | DAC2       | dac_ch2_dma    | dmamux1_req_in68 |                  |      |        |          |  |
| D2     | APB1 | TIM6       | tim6_up_dma    | dmamux1_req_in69 |                  |      |        |          |  |
| D2     | APB1 | TIM7       | tim7_up_dma    | dmamux1_req_in70 |                  |      |        |          |  |
|        |      |            | usart6_rx_dma  | dmamux1_req_in71 |                  |      |        |          |  |
| D2     | APB2 | USART6     | usart6_tx_dma  | dmamux1_req_in72 |                  |      |        |          |  |
|        |      |            | i2c3_rx_dma    | dmamux1_req_in73 |                  |      |        |          |  |
| D2     | APB1 | I2C3       | i2c3_tx_dma    | dmamux1_req_in74 |                  |      |        |          |  |
| D2     | AHB2 | DCMI       | dcmi_dma       | dmamux1_req_in75 |                  |      |        |          |  |
|        |      |            | cryp_in_dma    | dmamux1_req_in76 |                  |      |        |          |  |
| D2     | AHB2 | CRYP       | cryp_out_dma   | dmamux1_req_in77 |                  |      |        |          |  |
| D2     | AHB2 | HASH       | hash_in_dma    | dmamux1_req_in78 |                  |      |        |          |  |
|        | APB1 |            | uart7_rx_dma   | dmamux1_req_in79 |                  |      |        |          |  |
| D2     |      | UART7      | uart7_tx_dma   | dmamux1_req_in80 | DMAMUX1          | AHB1 | D2     | Requests |  |
|        |      |            | uart8_rx_dma   | dmamux1_req_in81 |                  |      |        |          |  |
| D2     | APB1 | UART8      | uart8_tx_dma   | dmamux1_req_in82 |                  |      |        |          |  |
|        | APB2 |            | spi4_rx_dma    | dmamux1_req_in83 |                  |      |        |          |  |
| D2     |      | SPI4       | spi4_tx_dma    | dmamux1_req_in84 |                  |      |        |          |  |
|        |      |            | spi5_rx_dma    | dmamux1_req_in85 |                  |      |        |          |  |
| D2     | APB2 | SPI5       | spi5_tx_dma    | dmamux1_req_in86 |                  |      |        |          |  |
|        |      |            | sai1_a_dma     | dmamux1_req_in87 |                  |      |        |          |  |
| D2     | APB2 | SAI1       | sai1_b_dma     | dmamux1_req_in88 |                  |      |        |          |  |
|        |      |            | sai2_a_dma     | dmamux1_req_in89 |                  |      |        |          |  |
| D2     | APB2 | SAI2       | sai2_b_dma     | dmamux1_req_in90 |                  |      |        |          |  |
|        |      |            | swpmi_rx_dma   | dmamux1_req_in91 |                  |      |        |          |  |
| D2     | APB1 | SWPMI      | swpmi_tx_dma   | dmamux1_req_in92 |                  |      |        |          |  |
|        |      |            | spdifrx_dt_dma | dmamux1_req_in93 |                  |      |        |          |  |
| D2     |      | APB1       | SPDIFRX        | spdifrx_cs_dma   | dmamux1_req_in94 |      |        |          |  |

**Table 106. DMAMUX1, DMA1 and DMA2 connections(1) (continued)**

|        |      | Source       |                | Destination       |            |      |          |            |
|--------|------|--------------|----------------|-------------------|------------|------|----------|------------|
| Domain | Bus  | Peripheral   | Signal         | Signal            | Peripheral | Bus  | Domain   | Comment    |
|        |      |              | hrtim_dma1     | dmamux1_req_in95  |            |      |          |            |
|        |      |              | hrtim_dma2     | dmamux1_req_in96  |            |      |          |            |
| D2     | APB2 | HRTIM1       | hrtim_dma3     | dmamux1_req_in97  |            |      |          |            |
|        |      |              | hrtim_dma4     | dmamux1_req_in98  |            |      |          |            |
|        |      |              | hrtim_dma5     | dmamux1_req_in99  |            |      | D2<br>D2 |            |
|        |      |              | hrtim_dma6     | dmamux1_req_in100 |            |      |          |            |
|        |      |              | dfsdm1_dma0    | dmamux1_req_in101 |            |      |          |            |
| D2     | APB2 | DFSDM1       | dfsdm1_dma1    | dmamux1_req_in102 |            |      |          |            |
|        |      |              | dfsdm1_dma2    | dmamux1_req_in103 |            |      |          |            |
|        |      |              | dfsdm1_dma3    | dmamux1_req_in104 |            |      |          |            |
|        |      | TIM15        | tim15_ch1_dma  | dmamux1_req_in105 | DMAMUX1    | AHB1 |          | Requests   |
|        | APB2 |              | tim15_up_dma   | dmamux1_req_in106 |            |      |          |            |
| D2     |      |              | tim15_trig_dma | dmamux1_req_in107 |            |      |          |            |
|        |      |              | tim15_com_dma  | dmamux1_req_in108 |            |      |          |            |
| D2     | APB2 | TIM16        | tim16_ch1_dma  | dmamux1_req_in109 |            |      |          |            |
|        |      |              | tim16_up_dma   | dmamux1_req_in110 |            |      |          |            |
|        |      | TIM17        | tim17_ch1_mda  | dmamux1_req_in111 |            |      |          |            |
| D2     | APB2 |              | tim17_up_dma   | dmamux1_req_in112 |            |      |          |            |
|        |      |              | sai3_a_dma     | dmamux1_req_in113 |            |      |          |            |
| D2     | APB2 | SAI3         | sai3_b_dma     | dmamux1_req_in114 |            |      |          |            |
| D3     | AHB4 | ADC3         | adc3_dma       | dmamux1_req_in115 |            |      |          |            |
|        |      |              | dmamux1_evt0   | dmamux1_gen0      |            |      |          |            |
| D2     |      | AHB1 DMAMUX1 | dmamux1_evt1   | dmamux1_gen1      |            |      |          |            |
|        |      |              | dmamux1_evt2   | dmamux1_gen2      |            |      |          |            |
| D2     | APB1 | LPTIM1       | lptim1_out     | dmamux1_gen3      | DMAMUX1    |      |          | Request    |
| D2     | APB1 | LPTIM2       | lptim2_out     | dmamux1_gen4      |            | AHB1 |          | generation |
| D2     | APB1 | LPTIM3       | lptim3_out     | dmamux1_gen5      |            |      |          |            |
| D3     | APB4 | EXTI         | exti_exti0_it  | dmamux1_gen6      |            |      |          |            |
| D2     | APB1 | TIM12        | tim12_trgo     | dmamux1_gen7      |            |      |          |            |

**Table 106. DMAMUX1, DMA1 and DMA2 connections(1) (continued)**

| Source |      |              |                   | Destination  |            |      |          |                                        |
|--------|------|--------------|-------------------|--------------|------------|------|----------|----------------------------------------|
| Domain | Bus  | Peripheral   | Signal            | Signal       | Peripheral | Bus  | Domain   |                                        |
| D2     |      |              | dmamux1_evt0      | dmamux1_trg0 |            |      |          | Comment<br>Triggers<br>Requests<br>out |
|        |      | AHB1 DMAMUX1 | dmamux1_evt1      | dmamux1_trg1 |            |      | D2<br>D2 |                                        |
|        |      |              | dmamux1_evt2      | dmamux1_trg2 |            |      |          |                                        |
| D2     | APB1 | LPTIM1       | lptim1_out        | dmamux1_trg3 | DMAMUX1    | AHB1 |          |                                        |
| D2     | APB1 | LPTIM2       | lptim2_out        | dmamux1_trg4 |            |      |          |                                        |
| D2     | APB1 | LPTIM3       | lptim3_out        | dmamux1_trg5 |            |      |          |                                        |
| D3     | APB4 | EXTI         | exti_exti0_it     | dmamux1_trg6 |            |      |          |                                        |
| D2     | APB1 | TIM12        | tim12_trgo        | dmamux1_trg7 |            |      |          |                                        |
|        |      |              | dmamux1_req_out0  | dma1_str0    | DMA1       |      |          |                                        |
|        |      |              | dmamux1_req_out1  | dma1_str1    |            |      |          |                                        |
|        |      |              | dmamux1_req_out2  | dma1_str2    |            |      |          |                                        |
|        |      |              | dmamux1_req_out3  | dma1_str3    |            |      |          |                                        |
|        |      |              | dmamux1_req_out4  | dma1_str4    |            | AHB1 |          |                                        |
|        |      |              | dmamux1_req_out5  | dma1_str5    |            |      |          |                                        |
|        |      |              | dmamux1_req_out6  | dma1_str6    |            |      |          |                                        |
|        |      |              | dmamux1_req_out7  | dma1_str7    |            |      |          |                                        |
| D2     |      | AHB1 DMAMUX1 | dmamux1_req_out8  | dma2_str0    |            |      |          |                                        |
|        |      |              | dmamux1_req_out9  | dma2_str1    |            |      |          |                                        |
|        |      |              | dmamux1_req_out10 | dma2_str2    |            |      |          |                                        |
|        |      |              | dmamux1_req_out11 | dma2_str3    | DMA2       |      |          |                                        |
|        |      |              | dmamux1_req_out12 | dma2_str4    |            | AHB1 | D2       |                                        |
|        |      |              | dmamux1_req_out13 | dma2_str5    |            |      |          |                                        |
|        |      |              | dmamux1_req_out14 | dma2_str6    |            |      |          |                                        |
|        |      |              | dmamux1_req_out15 | dma2_str7    |            |      |          |                                        |

<sup>1.</sup> The "-" symbol in grayed cells means no interconnect.

#### <span id="page-32-0"></span>**14.3.3 DMAMUX2, BDMA (D3 domain)**

**Table 107. DMAMUX2 and BDMA connections** 

|        |      | Source     |                     | Destination      |                  |     |        |          |  |
|--------|------|------------|---------------------|------------------|------------------|-----|--------|----------|--|
| Domain | Bus  | Peripheral | Signal              | Signal           | Peripheral       | Bus | Domain | Comment  |  |
|        |      |            |                     | dmamux2_req_in1  |                  |     |        |          |  |
|        |      |            |                     | dmamux2_req_in2  |                  |     |        |          |  |
|        |      |            |                     | dmamux2_req_in3  |                  |     |        |          |  |
|        |      |            | dmamux2 internal    | dmamux2_req_in4  |                  |     |        |          |  |
| D3     | AHB4 |            | (Request generator) | NC               |                  |     |        |          |  |
|        |      |            |                     | NC               |                  |     |        |          |  |
|        |      |            |                     | NC               |                  |     |        |          |  |
|        |      |            |                     | NC               |                  |     |        |          |  |
|        | APB4 | LPUART     | dma_rx_lpuart       | dmamux2_req_in9  | DMAMUX2 AHB4     |     | D3     | Requests |  |
| D3     |      |            | dma_tx_lpuart       | dmamux2_req_in10 |                  |     |        |          |  |
|        | APB4 |            |                     | dma_rx_spi6      | dmamux2_req_in11 |     |        |          |  |
| D3     |      | SPI6       | dma_tx_spi6         | dmamux2_req_in12 |                  |     |        |          |  |
|        | APB1 |            | dma_rx_i2c4         | dmamux2_req_in13 |                  |     |        |          |  |
| D2     |      |            | I2C4                | dma_tx_i2c4      | dmamux2_req_in14 |     |        |          |  |
|        |      |            |                     | dma_a_sai4       | dmamux2_req_in15 |     |        |          |  |
| D3     | APB4 | SAI4       | dma_b_sai4          | dmamux2_req_in16 |                  |     |        |          |  |
| D3     | APB4 | ADC3       | dma_adc3            | dmamux2_req_in17 |                  |     |        |          |  |

**Table 107. DMAMUX2 and BDMA connections (continued)**

| Source |      |              |                   | Destination   |              |     |        |                       |
|--------|------|--------------|-------------------|---------------|--------------|-----|--------|-----------------------|
| Domain | Bus  | Peripheral   | Signal            | Signal        | Peripheral   | Bus | Domain | Comment               |
| D3     |      | AHB4 DMAMUX2 | dmamux2_evt0      | dmamux2_gen0  | DMAMUX2 AHB4 |     | D3     | Request<br>generation |
|        |      |              | dmamux2_evt1      | dmamux2_gen1  |              |     |        |                       |
|        |      |              | dmamux2_evt2      | dmamux2_gen2  |              |     |        |                       |
|        |      |              | dmamux2_evt3      | dmamux2_gen3  |              |     |        |                       |
|        |      |              | dmamux2_evt4      | dmamux2_gen4  |              |     |        |                       |
|        |      |              | dmamux2_evt5      | dmamux2_gen5  |              |     |        |                       |
|        |      |              | dmamux2_evt6      | dmamux2_gen6  |              |     |        |                       |
|        |      | EXTI         | exti_lpuart_rx_it | dmamux2_gen7  |              |     |        |                       |
|        | APB4 |              | exti_lpuart_tx_it | dmamux2_gen8  |              |     |        |                       |
|        |      |              | exti_lptim2_wkup  | dmamux2_gen9  |              |     |        |                       |
|        |      |              | exti_lptim2_out   | dmamux2_gen10 |              |     |        |                       |
|        |      |              | exti_lptim3_wkup  | dmamux2_gen11 |              |     |        |                       |
|        |      |              | exti_lptim3_out   | dmamux2_gen12 |              |     |        |                       |
| D3     |      |              | exti_lptim4_wkup  | dmamux2_gen13 |              |     |        |                       |
|        |      |              | exti_lptim5_wkup  | dmamux2_gen14 |              |     |        |                       |
|        |      |              | exti_i2c4_wkup    | dmamux2_gen15 |              |     |        |                       |
|        |      |              | exti_spi6_wkup    | dmamux2_gen16 |              |     |        |                       |
|        |      |              | exti_comp1_out    | dmamux2_gen17 |              |     |        |                       |
|        |      |              | exti_comp2_out    | dmamux2_gen18 |              |     |        |                       |
|        |      |              | exti_rtc_wkup     | dmamux2_gen19 |              |     |        |                       |
|        |      |              | exti_syscfg_exti0 | dmamux2_gen20 |              |     |        |                       |
|        |      |              | exti_syscfg_exti2 | dmamux2_gen21 |              |     |        |                       |
| D3     | APB4 | I2C4         | it_evt_i2c4       | dmamux2_gen22 |              |     |        |                       |
| D3     | APB4 | SPI6         | it_spi6           | dmamux2_gen23 |              |     |        |                       |
|        | APB4 | LPUART       | it_tx_lpuart1     | dmamux2_gen24 |              |     |        |                       |
| D3     |      |              | it_rx_lpuart1     | dmamux2_gen25 |              |     |        |                       |
| D3     | AHB4 | ADC3         | it_adc3           | dmamux2_gen26 |              |     |        |                       |
|        |      |              | out_awd1_adc3     | dmamux2_gen27 |              |     |        |                       |
| D3     | AHB4 | BDMA         | it_ch0_bdma       | dmamux2_gen28 |              |     |        |                       |
|        |      |              | it_ch1_bdma       | dmamux2_gen29 |              |     |        |                       |

**Table 107. DMAMUX2 and BDMA connections (continued)**

| Source |      |              |                      | Destination   |              |      |        |              |
|--------|------|--------------|----------------------|---------------|--------------|------|--------|--------------|
| Domain | Bus  | Peripheral   | Signal               | Signal        | Peripheral   | Bus  | Domain | Comment      |
| D3     |      | AHB4 DMAMUX2 | dmamux2_evt0         | dmamux2_trg0  | DMAMUX2 AHB4 |      | D3     | Triggers     |
|        |      |              | dmamux2_evt1         | dmamux2_trg1  |              |      |        |              |
|        |      |              | dmamux2_evt2         | dmamux2_trg2  |              |      |        |              |
|        |      |              | dmamux2_evt3         | dmamux2_trg3  |              |      |        |              |
|        |      |              | dmamux2_evt4         | dmamux2_trg4  |              |      |        |              |
|        |      |              | dmamux2_evt5         | dmamux2_trg5  |              |      |        |              |
|        | APB4 | EXTI         | it_exti_tx_lpuart1   | dmamux2_trg6  |              |      |        |              |
|        |      |              | it_exti_rx_lpuart1   | dmamux2_trg7  |              |      |        |              |
|        |      |              | it_exti_out_lptim2   | dmamux2_trg8  |              |      |        |              |
|        |      |              | it_exti_out_lptim3   | dmamux2_trg9  |              |      |        |              |
|        |      |              | it_exti_wkup_i2c4    | dmamux2_trg10 |              |      |        |              |
| D3     |      |              | it_exti_wkup_spi6    | dmamux2_trg11 |              |      |        |              |
|        |      |              | it_exti_out_comp1    | dmamux2_trg12 |              |      |        |              |
|        |      |              | it_exti_wkup_rtc     | dmamux2_trg13 |              |      |        |              |
|        |      |              | it_exti_exti0_syscfg | dmamux2_trg14 |              |      |        |              |
|        |      |              | it_exti_exti2_syscfg | dmamux2_trg15 |              |      |        |              |
| D3     |      | AHB4 DMAMUX2 | dmamux1_req_out0     | bdma_ch0      | BDMA         | AHB4 | D3     | Requests out |
|        |      |              | dmamux1_req_out1     | bdma_ch1      |              |      |        |              |
|        |      |              | dmamux1_req_out2     | bdma_ch2      |              |      |        |              |
|        |      |              | dmamux1_req_out3     | bdma_ch3      |              |      |        |              |
|        |      |              | dmamux1_req_out4     | bdma_ch4      |              |      |        |              |
|        |      |              | dmamux1_req_out5     | bdma_ch5      |              |      |        |              |
|        |      |              | dmamux1_req_out6     | bdma_ch6      |              |      |        |              |
|        |      |              | dmamux1_req_out7     | bdma_ch7      |              |      |        |              |