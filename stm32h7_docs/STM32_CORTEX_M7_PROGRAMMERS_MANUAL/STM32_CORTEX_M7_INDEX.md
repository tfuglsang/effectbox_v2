# STM32 Cortex-M7 Programming Manual Index

**Document**: PM0253 - STM32 Cortex-M7 Programming Manual
**Purpose**: This index helps LLMs locate relevant documentation sections without loading the entire manual into context.

---

## How to Use This Index

1. Read this index file to identify which section(s) contain information about your topic
2. Load only the relevant markdown file(s) from the `STM32_CORTEX_M7_PROGRAMMERS_MANUAL` folder
3. Each section is in its own subfolder with a `.md` file containing the full content

---

## Chapter Summaries

### Section 1: Document Introduction

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `01_1 About this document/` | 1 | Document scope and purpose - covers STM32 Cortex-M7 processor programming | document overview |
| `02_1.1 Typographical conventions/` | 1.1 | Explains text formatting, conventions for bits, registers, and code examples | formatting, conventions |
| `03_1.2 List of abbreviations for registers/` | 1.2 | Register abbreviation definitions (RW, RO, WO, etc.) | abbreviations, register types |
| `04_1.3 About the Cortex®-M7 processor and core peripherals/` | 1.3 | Overview of M7 processor features: DSP, FPU, caches, bus interfaces, debug support | processor overview, features, FPU, DSP, cache, AXI, AMBA |

---

### Section 2: The Cortex-M7 Processor

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `05_2 The Cortex-M7 processor/` | 2 | Chapter introduction for processor architecture | processor architecture |
| `06_2.1 Programmers model/` | 2.1 | **Core registers (R0-R15, PSR, PRIMASK, FAULTMASK, BASEPRI, CONTROL)**, processor modes (Thread/Handler), privilege levels (Privileged/Unprivileged), stacks (MSP/PSP), data types | registers, modes, privilege, stack, MSP, PSP, APSR, IPSR, EPSR, Thread mode, Handler mode |
| `07_2.2 Cortex®-M7 configurations/` | 2.2 | Processor configuration options table - FPU variants, cache sizes, MPU regions | configuration, FPU options, cache size |
| `08_2.3 Memory model/` | 2.3 | **Memory map (4GB address space)**, memory types (Normal, Device, Strongly-ordered), memory attributes (Shareable, XN), memory barriers (DMB, DSB, ISB), exclusive access, endianness | memory map, memory types, barriers, DMB, DSB, ISB, shareable, exclusive access, little-endian |
| `09_2.4 Exception model/` | 2.4 | **Exception types, vector table, exception priorities**, NVIC operation, interrupt latency, exception entry/exit, tail-chaining | exceptions, interrupts, vector table, priority, NVIC, tail-chaining, preemption |
| `10_2.5 Fault handling/` | 2.5 | **Fault types (HardFault, MemManage, BusFault, UsageFault)**, fault escalation, lockup, fault status registers | faults, HardFault, MemManage, BusFault, UsageFault, lockup, CFSR |
| `11_2.6 Power management/` | 2.6 | Low-power modes (Sleep, Deep Sleep), WFI, WFE, sleep-on-exit, SLEEPDEEP bit | power management, sleep, WFI, WFE, low power |

---

### Section 3: The Cortex-M7 Instruction Set

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `12_3 The Cortex-M7 instruction set/` | 3 | Chapter introduction - Thumb instruction set overview | instruction set, Thumb |
| `13_3.1 Instruction set summary/` | 3.1 | **Complete instruction table** - all ARM Cortex-M7 instructions with syntax and descriptions | instruction table, instruction list, opcodes |
| `14_3.2 CMSIS functions/` | 3.2 | CMSIS intrinsic functions for accessing special instructions from C code | CMSIS, intrinsics, C functions |
| `15_3.3 About the instruction descriptions/` | 3.3 | How to read instruction documentation - operands, flags, syntax notation, condition codes | instruction format, condition codes, flags, operands |
| `16_3.4 Memory access instructions/` | 3.4 | **LDR, STR, LDM, STM, PUSH, POP, ADR** - load/store instructions, addressing modes | LDR, STR, load, store, PUSH, POP, addressing modes |
| `17_3.5 General data processing instructions/` | 3.5 | **ADD, SUB, AND, ORR, EOR, MOV, CMP, TST, LSL, LSR, ASR, ROR** - arithmetic, logic, shifts, comparisons | ADD, SUB, AND, OR, XOR, MOV, CMP, shift, rotate, arithmetic |
| `18_3.6 Multiply and divide instructions/` | 3.6 | **MUL, MLA, SMULL, UMULL, SDIV, UDIV** - 32/64-bit multiply, divide, multiply-accumulate, DSP multiply | MUL, DIV, multiply, divide, SMULL, UMULL, MLA, DSP |
| `19_3.7 Saturating instructions/` | 3.7 | **SSAT, USAT, QADD, QSUB** - saturating arithmetic for DSP applications | saturation, SSAT, USAT, QADD, QSUB, DSP, overflow |
| `20_3.8 Packing and unpacking instructions/` | 3.8 | **SXTB, SXTH, UXTB, UXTH, PKHBT** - sign/zero extension, pack halfwords | sign extend, zero extend, pack, SXTB, UXTB |
| `21_3.9 Bit field instructions/` | 3.9 | **BFC, BFI, SBFX, UBFX, RBIT, REV** - bit manipulation, bit field extract/insert, reverse | bit field, BFC, BFI, SBFX, UBFX, bit manipulation |
| `22_3.10 Branch and control instructions/` | 3.10 | **B, BL, BX, BLX, CBZ, CBNZ, IT, TBB, TBH** - branches, function calls, conditional execution | branch, BL, BX, function call, conditional, IT block, CBZ |
| `23_3.11 Floating-point instructions/` | 3.11 | **VADD, VSUB, VMUL, VDIV, VCMP, VCVT, VMOV, VLDR, VSTR** - FPU operations (single/double precision) | floating-point, FPU, VADD, VMUL, VCVT, float, double |
| `24_3.12 Miscellaneous instructions/` | 3.12 | **NOP, BKPT, WFI, WFE, SEV, DMB, DSB, ISB, MRS, MSR, CPSIE, CPSID** - system control, barriers, debug | NOP, WFI, WFE, barrier, MRS, MSR, CPSIE, CPSID, debug |

---

### Section 4: Cortex-M7 Core Peripherals

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `25_4 Cortex-M7 peripherals/` | 4 | Chapter introduction - core peripheral overview | peripherals |
| `26_4.1 About the Cortex-M7 peripherals/` | 4.1 | List of core peripherals: NVIC, SCB, SysTick, MPU, FPU with base addresses | peripheral addresses, PPB |
| `27_4.2 Nested Vectored Interrupt Controller/` | 4.2 | **NVIC registers (ISER, ICER, ISPR, ICPR, IABR, IPR, STIR)**, interrupt enable/disable, pending, priority, CMSIS functions | NVIC, interrupts, ISER, ICER, priority, CMSIS, IRQ |
| `28_4.3 System control block/` | 4.3 | **SCB registers (CPUID, ICSR, VTOR, AIRCR, SCR, CCR, SHPR, SHCSR, CFSR, HFSR, MMFAR, BFAR)** - system control, fault status, vector table relocation | SCB, CPUID, VTOR, AIRCR, fault registers, CFSR, HFSR |
| `29_4.4 System timer, SysTick/` | 4.4 | **SysTick registers (CSR, RVR, CVR, CALIB)** - system timer for RTOS tick, delay generation | SysTick, timer, RTOS, tick, delay |
| `30_4.5 Processor features/` | 4.5 | **Feature registers (CLIDR, CTR, CCSIDR, CSSELR)** - cache identification, cache geometry | cache ID, CLIDR, CTR, cache size |
| `31_4.6 Memory protection unit/` | 4.6 | **MPU registers (TYPE, CTRL, RNR, RBAR, RASR)** - memory regions, access permissions, memory attributes configuration | MPU, memory protection, regions, permissions, RBAR, RASR |
| `32_4.7 Floating-point unit/` | 4.7 | **FPU registers (CPACR, FPCCR, FPCAR, FPDSCR, FPSCR)** - FPU enable, lazy stacking, exception flags | FPU, CPACR, FPCCR, FPSCR, floating-point enable, lazy stacking |
| `33_4.8 Cache maintenance operations/` | 4.8 | **Cache registers (ICIALLU, DCIMVAC, DCCMVAC, DCCIMVAC)** - cache invalidate, clean, clean+invalidate by address/set/way | cache, invalidate, clean, ICIALLU, DCIMVAC, DMA coherency |
| `34_4.9 Access control/` | 4.9 | **Access control registers (ITCMCR, DTCMCR, AHBPCR, CACR, AHBSCR, ABFSR)** - TCM configuration, cache policy, AHB configuration | TCM, access control, ITCMCR, DTCMCR, AHB |

---

### Section 5: Revision History

| File | Section | Summary | Keywords |
|------|---------|---------|----------|
| `35_5 Revision history/` | 5 | Document revision history chapter | revision |
| `36_Table 110. Document revision history/` | Table 110 | Detailed revision history table | revision history |

---

## Quick Reference: Common Topics

### Register Access
- **Core registers (R0-R15, PSR, etc.)**: `06_2.1 Programmers model/`
- **NVIC registers**: `27_4.2 Nested Vectored Interrupt Controller/`
- **SCB registers**: `28_4.3 System control block/`
- **MPU registers**: `31_4.6 Memory protection unit/`
- **FPU registers**: `32_4.7 Floating-point unit/`
- **Cache registers**: `33_4.8 Cache maintenance operations/`

### Interrupt/Exception Handling
- **Exception model & priorities**: `09_2.4 Exception model/`
- **NVIC configuration**: `27_4.2 Nested Vectored Interrupt Controller/`
- **Fault handling**: `10_2.5 Fault handling/`
- **Vector table (VTOR)**: `28_4.3 System control block/`

### Memory Management
- **Memory map & types**: `08_2.3 Memory model/`
- **MPU configuration**: `31_4.6 Memory protection unit/`
- **Cache operations**: `33_4.8 Cache maintenance operations/`
- **Memory barriers**: `08_2.3 Memory model/` or `24_3.12 Miscellaneous instructions/`

### Low Power
- **Sleep modes**: `11_2.6 Power management/`
- **WFI/WFE instructions**: `24_3.12 Miscellaneous instructions/`

### Floating-Point
- **FPU instructions**: `23_3.11 Floating-point instructions/`
- **FPU configuration**: `32_4.7 Floating-point unit/`

### Assembly Programming
- **Instruction summary table**: `13_3.1 Instruction set summary/`
- **Instruction syntax**: `15_3.3 About the instruction descriptions/`
- **Specific instruction categories**: Sections 3.4-3.12

---

## Base Addresses (Quick Reference)

| Peripheral | Base Address | Documentation |
|------------|--------------|---------------|
| NVIC | 0xE000E100 | `27_4.2 Nested Vectored Interrupt Controller/` |
| SCB | 0xE000ED00 | `28_4.3 System control block/` |
| SysTick | 0xE000E010 | `29_4.4 System timer, SysTick/` |
| MPU | 0xE000ED90 | `31_4.6 Memory protection unit/` |
| FPU | 0xE000EF34 | `32_4.7 Floating-point unit/` |
| Cache Maintenance | 0xE000EF50 | `33_4.8 Cache maintenance operations/` |

---

*Generated from STM32 Cortex-M7 Programming Manual PM0253 Rev 5*
