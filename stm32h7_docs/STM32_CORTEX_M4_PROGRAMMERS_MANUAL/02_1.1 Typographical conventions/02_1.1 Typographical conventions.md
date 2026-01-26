**About this document PM0214**

## **1 About this document**

This document provides the information required for application and system-level software development. It does not provide information on debug components, features, or operation.

This material is for microcontroller software and hardware engineers, including those who have no experience of Arm products.

This document applies to Arm®(a)-based devices.

![](_page_0_Picture_5.jpeg)

## **1.1 Typographical conventions**

The typographical conventions used in this document are:

*italic* Highlights important notes, introduces special terminology, denotes

internal cross-references, and citations.

< and > Enclose replaceable terms for assembler syntax where they appear in

code or code fragments. For example: LDRSB<cond> <Rt>, [<Rn>, #<offset>]

bold Highlights interface elements, such as menu names. Denotes signal

names. Also used for terms in descriptive lists, where appropriate.

monospace Denotes text that you can enter at the keyboard, such as commands,

file and program names, and source code.

monospace Denotes a permitted abbreviation for a command or option. You can

enter the underlined text instead of the full command or option name.

*monospace italic* Denotes arguments to monospace text where the argument is to be

replaced by a specific value.

**monospace bold** Denotes language keywords when used outside example code.

## **1.2 List of abbreviations for registers**

The following abbreviations are used in register descriptions:

read/write (rw) Software can read and write to these bits.

read-only (r) Software can only read these bits. write-only (w) Software can only write to this bit.

Reading the bit returns the reset value.

12/262 PM0214 Rev 10

a. Arm is a registered trademark of Arm Limited (or its subsidiaries) in the US and/or elsewhere.

**PM0214 List of figures**

## **List of figures**

| STM32 Cortex-M4 implementation 13 |                                                                                                                                                                                                                                                                                                                  |
|-----------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
| Vector table 40                   |                                                                                                                                                                                                                                                                                                                  |
| Cortex-M4 stack frame layout 43   |                                                                                                                                                                                                                                                                                                                  |
| ASR #3 62                         |                                                                                                                                                                                                                                                                                                                  |
| LSR #3 63                         |                                                                                                                                                                                                                                                                                                                  |
| LSL #3 63                         |                                                                                                                                                                                                                                                                                                                  |
| ROR #3 64                         |                                                                                                                                                                                                                                                                                                                  |
| RRX #3 64                         |                                                                                                                                                                                                                                                                                                                  |
| Subregion example 198             |                                                                                                                                                                                                                                                                                                                  |
|                                   |                                                                                                                                                                                                                                                                                                                  |
| CFSR subregisters 237             |                                                                                                                                                                                                                                                                                                                  |
|                                   | Processor core registers 18<br>APSR, IPSR and EPSR bit assignment 20<br>PSR bit assignment 20<br>PRIMASK bit assignment 24<br>FAULTMASK bit assignment 24<br>BASEPRI bit assignment 25<br>Memory map 28<br>Bit-band mapping 33<br>Little-endian example 34<br>Mapping of IP[N] fields in NVIC_IPRx registers 215 |

![](_page_1_Picture_3.jpeg)

PM0214 Rev 10 11/262