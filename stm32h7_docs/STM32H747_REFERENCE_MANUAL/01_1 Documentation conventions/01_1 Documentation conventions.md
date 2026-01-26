# **1 Documentation conventions**

### **1.1 General information**

The STM32H745/755 and STM32H747/757 devices embed an Arm®(a) Cortex®-M4 with FPU and an Arm® Cortex®-M7 with FPU core.

## **1.2 List of abbreviations for registers**

The following abbreviations(b) are used in register descriptions:

read/write (rw) Software can read and write to this bit.

read-only (r) Software can only read this bit.

write-only (w) Software can only write to this bit. Reading this bit returns the reset value.

read/clear write0 (rc\_w0) Software can read as well as clear this bit by writing 0. Writing 1 has no

effect on the bit value.

read/clear write1 (rc\_w1) Software can read as well as clear this bit by writing 1. Writing 0 has no

effect on the bit value.

read/clear write (rc\_w) Software can read as well as clear this bit by writing to the register. The

value written to this bit is not important.

read/clear by read (rc\_r) Software can read this bit. Reading this bit automatically clears it to 0.

Writing this bit has no effect on the bit value.

read/set by read (rs\_r) Software can read this bit. Reading this bit automatically sets it to 1.

Writing this bit has no effect on the bit value.

read/set (rs) Software can read as well as set this bit. Writing 0 has no effect on the bit

value.

read/write once (rwo) Software can only write once to this bit and can also read it at any time.

Only a reset can return the bit to its reset value.

toggle (t) The software can toggle this bit by writing 1. Writing 0 has no effect.

read-only write trigger (rt\_w1) Software can read this bit. Writing 1 triggers an event but has no effect on

the bit value.

Reserved (Res.) Reserved bit, must be kept at reset value.

106/3556 RM0399 Rev 4

a. Arm is a registered trademark of Arm Limited (or its subsidiaries) in the US and/or elsewhere.

b. This is an exhaustive list of all abbreviations applicable to STMicroelectronics microcontrollers, some of them may not be used in the current document.

### **1.3 Glossary**

This section gives a brief definition of acronyms and abbreviations used in this document:

- **Word**: data of 32-bit length.
- **Half-word**: data of 16-bit length.
- **Byte**: data of 8-bit length.
- **Double word**: data of 64-bit length.
- Flash word: data of 256-bit length
- **IAP (in-application programming)**: IAP is the ability to re-program the flash memory of a microcontroller while the user program is running.
- **ICP (in-circuit programming)**: ICP is the ability to program the flash memory of a microcontroller using the JTAG protocol, the SWD protocol or the bootloader while the device is mounted on the user application board.
- **Option bytes**: product configuration bits stored in the flash memory.
- **AHB**: advanced high-performance bus.
- **APB**: advanced peripheral bus.
- **AXI**: Advanced extensible interface protocol.
- **PCROP**: proprietary code readout protection.
- **RDP**: readout protection.

## **1.4 Availability of peripherals**

For availability of peripherals and their number across all sales types, refer to the particular device datasheet.

**Table 1. Availability of security features**

| Security feature                                                                    | STM32H755xI and<br>STM32H757xI | STM32H745xI/G and<br>STM32H747xI/G |
|-------------------------------------------------------------------------------------|--------------------------------|------------------------------------|
| Embedded flash memory (FLASH):<br>– Flash Secure-only area                          |                                |                                    |
| Security memory management:<br>– Secure access mode<br>– Root secure services (RSS) | Available                      | Not available                      |
| Cryptographic processor (CRYP)                                                      |                                |                                    |
| Hash processor (HASH)                                                               |                                |                                    |