**About this document PM0253**

## **1 About this document**

This document provides information required for application and system-level software development. It does not provide information on debug components, features, or operation.

STM32F7 Series and STM32H7 Series 32-bit MCUs are based on Arm®(a) Cortex®-M processors.

This material is for microcontroller software and hardware engineers, including those who have no experience of Arm products.

## **1.1 Typographical conventions**

The typographical conventions used in this document are:

*italic* Highlights important notes, introduces special terminology, denotes

internal cross-references, and citations.

**bold** Highlights interface elements, such as menu names. Denotes signal

names. Also used for terms in descriptive lists, where appropriate.

monospace Denotes text that the user can enter at the keyboard, such as com-

mands, file and program names, and source code.

monospace Denotes a permitted abbreviation for a command or option. core can

enter the underlined text instead of the full command or option name.

*monospace italic* Denotes arguments to monospace text where the argument is to be

replaced by a specific value.

*monospace bold* Denotes language keywords when used outside example code.

< and > Enclose replaceable terms for assembler syntax where they appear in

code or code fragments. For example: LDRSB<cond> <Rt>, [<Rn>, #<offset>]

## **1.2 List of abbreviations for registers**

The following abbreviations are used in register descriptions:

read/write (rw) Software can read and write to these bits.

read-only (r) Software can only read these bits. write-only (w) Software can only write to this bit.

Reading the bit returns the reset value.

read/clear (rc\_w) Software can read as well as clear this bit by writing any value.

14/254 PM0253 Rev 5

![](_page_0_Picture_29.jpeg)

a. Arm is a registered trademark of Arm Limited (or its subsidiaries) in the US and/or elsewhere.

**PM0253 List of figures**

| Figure 49. | MPU_CTRL bit assignments 223        |  |
|------------|-------------------------------------|--|
| Figure 50. | MPU_RNR bit assignments 225         |  |
| Figure 51. | MPU_RBAR bit assignments: 225       |  |
| Figure 52. | MPU_RASR bit assignments 227        |  |
| Figure 53. | Example of disabling subregion 232  |  |
| Figure 54. | CPACR bit assignments 233           |  |
| Figure 55. | FPCCR bit assignments 234           |  |
| Figure 56. | FPCAR bit assignments 236           |  |
| Figure 57. | FPSCR bit assignments 236           |  |
| Figure 58. | FPDSCR bit assignments 237          |  |
| Figure 59. | Cache operation bit assignments 241 |  |
| Figure 60. | ITCMR and DTCMR bit assignments 246 |  |
| Figure 61. | AHBPCR bit assignments 248          |  |
| Figure 62. | CACR bit assignments 249            |  |
| Figure 63. | AHBSCR bit assignments 250          |  |
| Figure 64. | ABFSR bit assignments 251           |  |
|            |                                     |  |

![](_page_1_Picture_2.jpeg)

PM0253 Rev 5 13/254