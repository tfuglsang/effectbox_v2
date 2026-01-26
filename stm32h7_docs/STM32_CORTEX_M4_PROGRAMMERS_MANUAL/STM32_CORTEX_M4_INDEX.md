# STM32 Cortex-M4 Programming Manual Index

**Document**: PM0214 - STM32F3/F4/L4/L4+/G4 Series Cortex-M4 Programming Manual
**Purpose**: This index helps LLMs locate relevant documentation sections without loading the entire manual into context.

---

## How to Use This Index

1. Read this index file to identify which section(s) contain information about your topic
2. Load only the relevant markdown file(s) from the `STM32_CORTEX_M4_PROGRAMMERS_MANUAL` folder
3. Each section is in its own subfolder with a `.md` file containing the full content

---

## Chapter Summaries

### Section 1: Document Introduction

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `01_1 About this document/` | 1 | Document scope and purpose - covers STM32 Cortex-M4 processor programming for F3/F4/L4/L4+/G4 series | document overview |
| `02_1.1 Typographical conventions/` | 1.1 | Explains text formatting, conventions for bits, registers, and code examples | formatting, conventions |
| `03_1.2 List of abbreviations for registers/` | 1.2 | Register abbreviation definitions (RW, RO, WO, etc.) | abbreviations, register types |
| `04_1.3 About the STM32 Cortex-M4 processor and core peripherals/` | 1.3 | Overview of M4 processor features: DSP, FPU (single precision), bus interfaces, debug support | processor overview, features, FPU, DSP, AHB, APB |

---

### Section 2: The Cortex-M4 Processor

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `05_2 The Cortex-M4 processor/` | 2 | Chapter introduction for processor architecture | processor architecture |
| `06_2.1 Programmers model/` | 2.1 | **Core registers (R0-R15, PSR, PRIMASK, FAULTMASK, BASEPRI, CONTROL)**, processor modes (Thread/Handler), privilege levels (Privileged/Unprivileged), stacks (MSP/PSP), data types | registers, modes, privilege, stack, MSP, PSP, APSR, IPSR, EPSR, Thread mode, Handler mode |
| `07_2.2 Memory model/` | 2.2 | **Memory map (4GB address space)**, memory types (Normal, Device, Strongly-ordered), memory attributes (Shareable, XN), memory access behavior, bit-banding, memory barriers (DMB, DSB, ISB), exclusive access, endianness | memory map, memory types, barriers, DMB, DSB, ISB, bit-banding, shareable, exclusive access, little-endian |
| `08_2.3 Exception model/` | 2.3 | **Exception types, vector table, exception priorities**, NVIC operation, interrupt latency, exception entry/exit, tail-chaining | exceptions, interrupts, vector table, priority, NVIC, tail-chaining, preemption |
| `09_2.4 Fault handling/` | 2.4 | **Fault types (HardFault, MemManage, BusFault, UsageFault)**, fault escalation, lockup, fault status registers | faults, HardFault, MemManage, BusFault, UsageFault, lockup, CFSR |
| `10_2.5 Power management/` | 2.5 | Low-power modes (Sleep, Deep Sleep), WFI, WFE, sleep-on-exit, SLEEPDEEP bit, wakeup from sleep | power management, sleep, WFI, WFE, low power, wakeup |

---

### Section 3: The STM32 Cortex-M4 Instruction Set

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `11_3 The STM32 Cortex-M4 instruction set/` | 3 | Chapter introduction - Thumb-2 instruction set overview | instruction set, Thumb-2 |
| `12_3.1 Instruction set summary/` | 3.1 | **Complete instruction table** - all ARM Cortex-M4 instructions with syntax and descriptions | instruction table, instruction list, opcodes |
| `13_3.2 CMSIS intrinsic functions/` | 3.2 | CMSIS intrinsic functions for accessing special instructions from C code | CMSIS, intrinsics, C functions |
| `14_3.3 About the instruction descriptions/` | 3.3 | How to read instruction documentation - operands, flags, syntax notation, condition codes | instruction format, condition codes, flags, operands |
| `15_3.4 Memory access instructions/` | 3.4 | **LDR, STR, LDM, STM, PUSH, POP, ADR** - load/store instructions, addressing modes | LDR, STR, load, store, PUSH, POP, addressing modes |
| `16_3.5 General data processing instructions/` | 3.5 | **ADD, SUB, AND, ORR, EOR, MOV, CMP, TST, LSL, LSR, ASR, ROR** - arithmetic, logic, shifts, comparisons | ADD, SUB, AND, OR, XOR, MOV, CMP, shift, rotate, arithmetic |
| `17_3.6 Multiply and divide instructions/` | 3.6 | **MUL, MLA, SMULL, UMULL, SDIV, UDIV** - 32/64-bit multiply, divide, multiply-accumulate, DSP multiply | MUL, DIV, multiply, divide, SMULL, UMULL, MLA, DSP |
| `18_3.7 Saturating instructions/` | 3.7 | **SSAT, USAT, QADD, QSUB** - saturating arithmetic for DSP applications | saturation, SSAT, USAT, QADD, QSUB, DSP, overflow |
| `19_3.8 Packing and unpacking instructions/` | 3.8 | **SXTB, SXTH, UXTB, UXTH, PKHBT** - sign/zero extension, pack halfwords | sign extend, zero extend, pack, SXTB, UXTB |
| `20_3.9 Bitfield instructions/` | 3.9 | **BFC, BFI, SBFX, UBFX, RBIT, REV** - bit manipulation, bit field extract/insert, reverse | bit field, BFC, BFI, SBFX, UBFX, bit manipulation |
| `21_3.10 Floating-point instructions/` | 3.10 | **VADD, VSUB, VMUL, VDIV, VCMP, VCVT, VMOV, VLDR, VSTR** - FPU operations (single precision only on M4) | floating-point, FPU, VADD, VMUL, VCVT, float |
| `22_3.11 Miscellaneous instructions/` | 3.11 | **NOP, BKPT, WFI, WFE, SEV, DMB, DSB, ISB, MRS, MSR, CPSIE, CPSID** - system control, barriers, debug | NOP, WFI, WFE, barrier, MRS, MSR, CPSIE, CPSID, debug |

---

### Section 4: Core Peripherals

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `23_4 Core peripherals/` | 4 | Chapter introduction - core peripheral overview | peripherals |
| `24_4.1 About the STM32 Cortex-M4 core peripherals/` | 4.1 | List of core peripherals with address ranges: NVIC, SCB, SysTick, MPU, FPU | peripheral addresses, PPB |
| `25_4.2 Memory protection unit (MPU)/` | 4.2 | **MPU registers (TYPE, CTRL, RNR, RBAR, RASR)** - 8 memory regions, access permissions, memory attributes configuration | MPU, memory protection, regions, permissions, RBAR, RASR |
| `26_4.3 Nested vectored interrupt controller (NVIC)/` | 4.3 | **NVIC registers (ISER, ICER, ISPR, ICPR, IABR, IPR, STIR)**, interrupt enable/disable, pending, priority, CMSIS functions | NVIC, interrupts, ISER, ICER, priority, CMSIS, IRQ |
| `27_4.4 System control block (SCB)/` | 4.4 | **SCB registers (CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR, SHCSR, CFSR, HFSR, MMFAR, BFAR)** - system control, fault status, vector table relocation | SCB, CPUID, VTOR, AIRCR, fault registers, CFSR, HFSR |
| `28_4.5 SysTick timer (STK)/` | 4.5 | **SysTick registers (CTRL, LOAD, VAL, CALIB)** - system timer for RTOS tick, delay generation | SysTick, timer, RTOS, tick, delay, STK |
| `29_4.6 Floating point unit (FPU)/` | 4.6 | **FPU registers (CPACR, FPCCR, FPCAR, FPDSCR, FPSCR)** - FPU enable, lazy stacking, exception flags, single precision only | FPU, CPACR, FPCCR, FPSCR, floating-point enable, lazy stacking |

---

### Section 5: Revision History

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `30_5 Revision history/` | 5 | Document revision history | revision history |

---

## Quick Reference: Common Topics

### Register Access
- **Core registers (R0-R15, PSR, etc.)**: `06_2.1 Programmers model/`
- **NVIC registers**: `26_4.3 Nested vectored interrupt controller (NVIC)/`
- **SCB registers**: `27_4.4 System control block (SCB)/`
- **MPU registers**: `25_4.2 Memory protection unit (MPU)/`
- **FPU registers**: `29_4.6 Floating point unit (FPU)/`
- **SysTick registers**: `28_4.5 SysTick timer (STK)/`

### Interrupt/Exception Handling
- **Exception model & priorities**: `08_2.3 Exception model/`
- **NVIC configuration**: `26_4.3 Nested vectored interrupt controller (NVIC)/`
- **Fault handling**: `09_2.4 Fault handling/`
- **Vector table (VTOR)**: `27_4.4 System control block (SCB)/`

### Memory Management
- **Memory map & types**: `07_2.2 Memory model/`
- **Bit-banding**: `07_2.2 Memory model/`
- **MPU configuration**: `25_4.2 Memory protection unit (MPU)/`
- **Memory barriers**: `07_2.2 Memory model/` or `22_3.11 Miscellaneous instructions/`

### Low Power
- **Sleep modes**: `10_2.5 Power management/`
- **WFI/WFE instructions**: `22_3.11 Miscellaneous instructions/`

### Floating-Point
- **FPU instructions**: `21_3.10 Floating-point instructions/`
- **FPU configuration**: `29_4.6 Floating point unit (FPU)/`

### Assembly Programming
- **Instruction summary table**: `12_3.1 Instruction set summary/`
- **Instruction syntax**: `14_3.3 About the instruction descriptions/`
- **Specific instruction categories**: Sections 3.4-3.11

---

## Base Addresses (Quick Reference)

| Peripheral | Base Address | Documentation |
|------------|--------------|---------------|
| SysTick | 0xE000E010 | `28_4.5 SysTick timer (STK)/` |
| NVIC | 0xE000E100 | `26_4.3 Nested vectored interrupt controller (NVIC)/` |
| SCB | 0xE000ED00 | `27_4.4 System control block (SCB)/` |
| FPU (CPACR) | 0xE000ED88 | `29_4.6 Floating point unit (FPU)/` |
| MPU | 0xE000ED90 | `25_4.2 Memory protection unit (MPU)/` |
| NVIC (STIR) | 0xE000EF00 | `26_4.3 Nested vectored interrupt controller (NVIC)/` |
| FPU (other) | 0xE000EF30 | `29_4.6 Floating point unit (FPU)/` |

---

## Key Differences: Cortex-M4 vs Cortex-M7

| Feature | Cortex-M4 | Cortex-M7 |
|---------|-----------|-----------|
| FPU | Single precision only | Single & double precision |
| Caches | No | I-Cache & D-Cache |
| MPU Regions | 8 | 8 or 16 |
| DSP | Yes | Yes (enhanced) |
| Bit-banding | Yes | No |
| Pipeline | 3-stage | 6-stage superscalar |

---

*Generated from STM32 Cortex-M4 Programming Manual PM0214 Rev 10*
