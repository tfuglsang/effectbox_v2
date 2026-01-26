
| PIN NO | NAME     | POWER DOMAIN | GROUND DOMAIN |
|--------|----------|--------------|---------------|
| F3     | SDA      | DBVDD        | DGND          |
| A3     | SPKMODE  | DBVDD        | DGND          |
| B1     | SPKOUTLN | SPKVDD1      | SPKGND1       |
| A2     | SPKOUTLP | SPKVDD1      | SPKGND1       |
| C3     | SPKOUTRN | SPKVDD2      | SPKGND2       |
| B3     | SPKOUTRP | SPKVDD2      | SPKGND2       |

## **ABSOLUTE MAXIMUM RATINGS**

Absolute Maximum Ratings are stress ratings only. Permanent damage to the device may be caused by continuously operating at or beyond these limits. Device functional operating limits and guaranteed performance specifications are given under Electrical Characteristics at the test conditions specified.

![](_page_0_Picture_5.jpeg)

ESD Sensitive Device. This device is manufactured on a CMOS process. It is therefore generically susceptible to damage from excessive static voltages. Proper ESD precautions must be taken during handling and storage of this device.

Cirrus Logic tests its package types according to IPC/JEDEC J-STD-020B for Moisture Sensitivity to determine acceptable storage conditions prior to surface mount assembly. These levels are:

MSL1 = unlimited floor life at <30C / 85% Relative Humidity. Not normally stored in moisture barrier bag.

MSL2 = out of bag storage for 1 year at <30C / 60% Relative Humidity. Supplied in moisture barrier bag.

MSL3 = out of bag storage for 168 hours at <30C / 60% Relative Humidity. Supplied in moisture barrier bag.

The Moisture Sensitivity Level for each package type is specified in Ordering Information.

| CONDITION                                              | MIN         | MAX          |
|--------------------------------------------------------|-------------|--------------|
| Supply voltages (AVDD1, DBVDD)                         | -0.3V       | +4.5V        |
| Supply voltages (AVDD2, DCVDD, LDO2VDD)                | -0.3V       | +2.5V        |
| Supply voltages (CPVDD)                                | -0.3V       | +2.2V        |
| Supply voltages (SPKVDD1, SPKVDD2, LDO1VDD)            | -0.3V       | +7.0V        |
| Voltage range digital inputs (DBVDD domain)            | AGND - 0.3V | DBVDD + 0.3V |
| Voltage range digital inputs (DMICDATn)                | AGND - 0.3V | AVDD1 + 0.3V |
| Voltage range analogue inputs (AVDD1 domain)           | AGND - 0.3V | AVDD1 + 0.3V |
| Voltage range analogue inputs (LINEOUTFB)              | AGND - 0.3V | AVDD1 + 0.3V |
| Voltage range analogue inputs (HPOUT1FB)               | AGND - 0.3V | AGND + 0.3V  |
| Ground (DGND, CPGND, SPKGND1, SPKGND2, REFGND, HP2GND) | AGND - 0.3V | AGND + 0.3V  |
| Operating temperature range, TA                        | -40ºC       | +85ºC        |
| Junction temperature, TJMAX                            | -40ºC       | +150ºC       |
| Storage temperature after soldering                    | -65ºC       | +150ºC       |

**Rev 4.6 11**