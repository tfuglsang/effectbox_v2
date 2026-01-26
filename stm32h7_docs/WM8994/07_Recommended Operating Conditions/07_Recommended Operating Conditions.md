
## **RECOMMENDED OPERATING CONDITIONS**

| PARAMETER                   | SYMBOL                                                    | MIN  | TYP | MAX | UNIT |
|-----------------------------|-----------------------------------------------------------|------|-----|-----|------|
| Digital supply range (Core) | DCVDD                                                     | 0.95 | 1.0 | 2.0 | V    |
| See notes 7, 8              |                                                           |      |     |     |      |
| Digital supply range (I/O)  | DBVDD                                                     | 1.62 | 1.8 | 3.6 | V    |
| Analogue supply 1 range     | AVDD1                                                     | 2.4  | 3.0 | 3.3 | V    |
| See notes 3, 4, 5, 6        |                                                           |      |     |     |      |
| Analogue supply 2 range     | AVDD2                                                     | 1.71 | 1.8 | 2.0 | V    |
| Charge Pump supply range    | CPVDD                                                     | 1.71 | 1.8 | 2.0 | V    |
| Speaker supply range        | SPKVDD1, SPKVDD2                                          | 2.7  | 5.0 | 5.5 | V    |
| LDO1 supply range           | LDO1VDD                                                   | 2.7  | 5.0 | 5.5 | V    |
| LDO2 supply range           | LDO2VDD                                                   | 1.71 | 1.8 | 2.0 | V    |
| Ground                      | DGND, AGND, CPGND,<br>SPKGND1, SPKGND2,<br>REFGND, HP2GND |      | 0   |     | V    |
| Power supply rise time      | All supplies                                              | 1    |     |     | s   |
| See notes 9, 10, 11         |                                                           |      |     |     |      |
| Operating temperature range | TA                                                        | -40  |     | 85  | °C   |

## **Notes**

- 1. Analogue, digital and speaker grounds must always be within 0.3V of AGND.
- 2. There is no power sequencing requirement; the supplies may be enabled in any order.
- 3. AVDD1 must be less than or equal to SPKVDD1 and SPKVDD2.
- 4. An internal LDO (powered by LDO1VDD) can be used to provide the AVDD1 supply.
- 5. When AVDD1 is supplied externally (not from LDO1), the LDO1VDD voltage must be greater than or equal to AVDD1
- 6. The WM8994 can operate with AVDD1 tied to 0V; power consumption may be reduced, but the analogue audio functions will not be supported.
- 7. An internal LDO (powered by LDO2VDD) can be used to provide the DCVDD supply.
- 8. When DCVDD is supplied externally (not from LDO2), the LDO2VDD voltage must be greater than or equal to DCVDD
- 9. DCVDD and AVDD1 minimum rise times do not apply when these domains are powered using the internal LDOs.
- 10. The specified minimum power supply rise times assume a minimum decoupling capacitance of 100nF per pin. However, Cirrus Logic strongly advises that the recommended decoupling capacitors are present on the PCB and that appropriate layout guidelines are observed (see "Applications Information" section).
- 11. The specified minimum power supply rise times also assume a maximum PCB inductance of 10nH between decoupling capacitor and pin.

**12 Rev 4.6**