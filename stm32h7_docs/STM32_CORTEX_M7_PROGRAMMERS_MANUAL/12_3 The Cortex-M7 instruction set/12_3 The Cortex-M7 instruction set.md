# **3 The Cortex-M7 instruction set**

# **3.1 Instruction set summary**

The processor implements Armv7-M instruction set and features provided by the Armv7E-M architecture profile. *[Table](#page-0-0) 23* lists the supported instructions.

#### In *[Table](#page-0-0) 23*:

- Angle brackets, <>, enclose alternative forms of the operand.
- Braces, {}, enclose optional operands.
- The Operands column is not exhaustive.
- Op2 is a flexible second operand that can be either a register or a constant.
- Most instructions can use an optional condition code suffix.

For more information on the instructions and operands, see the instruction descriptions.

**Table 23. Cortex®-M7 instructions** 

<span id="page-0-0"></span>

| Mnemonic  | Operands                | Brief description                 | Flags   | Page               |
|-----------|-------------------------|-----------------------------------|---------|--------------------|
| ADC, ADCS | {Rd,} Rn, Op2           | Add with Carry                    | N,Z,C,V | 3.5.1 on page 87   |
| ADD, ADDS | {Rd,} Rn, Op2           | Add                               | N,Z,C,V | 3.5.1 on page 87   |
| ADD, ADDW | {Rd,} Rn, #imm12        | Add                               | -       | 3.5.1 on page 87   |
| ADR       | Rd, label               | Load PC-relative Address          | -       | 3.4.1 on page 73   |
| AND, ANDS | {Rd,} Rn, Op2           | Logical AND                       | N,Z,C   | 3.5.2 on page 89   |
| ASR, ASRS | Rd, Rm, <rs #n></rs #n> | Arithmetic Shift Right            | N,Z,C   | 3.5.3 on page 90   |
| B         | label                   | Branch                            | -       | 3.10.1 on page 145 |
| BFC       | Rd, #lsb, #width        | Bit Field Clear                   | -       | 3.9.1 on page 142  |
| BFI       | Rd, Rn, #lsb, #width    | Bit Field Insert                  | -       | 3.9.1 on page 142  |
| BIC, BICS | {Rd,} Rn, Op2           | Bit Clear                         | N,Z,C   | 3.5.2 on page 89   |
| BKPT      | #imm                    | Breakpoint                        | -       | 3.12.1 on page 175 |
| BL        | label                   | Branch with Link                  | -       | 3.10.1 on page 145 |
| BLX       | Rm                      | Branch indirect with Link         | -       | 3.10.1 on page 145 |
| BX        | Rm                      | Branch indirect                   | -       | 3.10.1 on page 145 |
| CBNZ      | Rn, label               | Compare and Branch if Non<br>Zero | -       | 3.10.2 on page 147 |
| CBZ       | Rn, label               | Compare and Branch if<br>Zero     | -       | 3.10.2 on page 147 |
| CLREX     | -                       | Clear Exclusive                   | -       | 3.4.10 on page 84  |
| CLZ       | Rd, Rm                  | Count Leading Zeros               | -       | 3.5.4 on page 91   |
| CMN       | Rn, Op2                 | Compare Negative                  | N,Z,C,V | 3.5.5 on page 92   |
| CMP       | Rn, Op2                 | Compare                           | N,Z,C,V | 3.5.5 on page 92   |

52/254 PM0253 Rev 5

![](_page_0_Picture_15.jpeg)

### **2.6.2 Wakeup from sleep mode**

The conditions for the processor to wakeup depend on the mechanism that cause it to enter sleep mode.

#### **Wakeup from WFI or sleep-on-exit**

Normally, the processor wakes up only when it detects an exception with sufficient priority to cause exception entry. Some embedded systems might have to execute system restore tasks after the processor wakes up, and before it executes an interrupt handler. To achieve this set the PRIMASK bit to 1 and the FAULTMASK bit to 0. If an interrupt arrives that is enabled and has a higher priority than the current exception priority, the processor wakes up but does not execute the interrupt handler until the processor sets PRIMASK to zero. For more information about PRIMASK and FAULTMASK see *Exception mask registers on page 25*.

#### **Wakeup from WFE**

The processor wakes up if:

- It detects an exception with sufficient priority to cause exception entry.
- It detects an external event signal, see *[The external event input](#page-1-0)*.
- In a multiprocessor system, another processor in the system executes an SEV instruction.

In addition, if the SEVONPEND bit in the SCR is set to 1, any new pending interrupt triggers an event and wakes up the processor, even if the interrupt is disabled or has insufficient priority to cause exception entry. For more information about the SCR see *System control register on page 199*.

# <span id="page-1-0"></span>**2.6.3 The external event input**

The processor provides an external event input signal. Peripherals can drive this signal, either to wake the processor from WFE, or to set the internal WFE event register to one to indicate that the processor must not enter sleep mode on a later WFE instruction. See *Wait for event on page 50* for more information.

# **2.6.4 Power management programming hints**

ISO/IEC C cannot directly generate the WFI and WFE instructions. The CMSIS provides the following functions for these instructions:

```
void __WFE(void) // Wait for Event
void __WFI(void) // Wait for Interrupt
```

![](_page_1_Picture_17.jpeg)

PM0253 Rev 5 51/254