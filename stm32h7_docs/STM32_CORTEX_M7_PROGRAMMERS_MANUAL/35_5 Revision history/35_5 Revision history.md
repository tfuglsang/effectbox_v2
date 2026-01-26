**PM0253 Revision history**

## **5 Revision history**

**Table 110. Document revision history**

| Date        | Revision | Changes                                                                                                                                                                                                                                                                           |
|-------------|----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 18-Dec-2015 | 1        | Initial release.                                                                                                                                                                                                                                                                  |
| 22-Apr-2016 | 2        | Updated Table 11: STM32F746xx/STM32F756xx Cortex®-M7<br>configuration title.<br>Added Table 12: STM32F76xxx/STM32F77xxx Cortex®-M7<br>configuration.<br>In Section 2.3.2: Memory system ordering of memory accesses<br>updated link to section 2.3.4: software ordering of memory |
|             |          | accesses.                                                                                                                                                                                                                                                                         |
| 02-Feb-2017 | 3        | Added Table 13: STM32F72xxx/STM32F73xxx Cortex®-M7<br>configuration.                                                                                                                                                                                                              |
| 14-Nov-2017 | 4        | Added STM32H7 Series in the whole document.<br>Added Table 14: STM32H7 Series Cortex®-M7 configuration.                                                                                                                                                                           |
| 15-Jun-2019 | 5        | Updated DREGION function description in Table 85: TYPE bit<br>assignments.<br>Added Section 4.7.7: Enabling and clearing FPU exception<br>interrupts.                                                                                                                             |

**Table 109. ABFSR bit assignments (continued)**

| Bits | Name | Function                              |
|------|------|---------------------------------------|
| [3]  | AXIM | Asynchronous fault on AXIM interface. |
| [2]  | AHBP | Asynchronous fault on AHBP interface. |
| [1]  | DTCM | Asynchronous fault on DTCM interface. |
| [0]  | ITCM | Asynchronous fault on ITCM interface  |

In the bus-fault handler, the software reads the BFSR, and if an asynchronous fault occurs, the ABFSR is read to determine which interfaces are affected. The ABFSR[4:0] fields remains valid until cleared by writing to the ABFSR with any value.

For more information about the BFSR, see *BusFault status register on page 207*.

![](_page_1_Picture_6.jpeg)