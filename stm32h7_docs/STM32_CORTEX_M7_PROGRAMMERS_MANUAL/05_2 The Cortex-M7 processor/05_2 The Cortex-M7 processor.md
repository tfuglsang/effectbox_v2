# **2 The Cortex-M7 processor**

## **2.1 Programmers model**

This section describes the Cortex®-M7 programmers model. In addition to the individual core register descriptions, it contains information about the processor modes and privilege levels for software execution and stacks.

## **2.1.1 Processor mode and privilege levels for software execution**

The processor *modes* are:

**Thread mode** Executes application software. The processor enters Thread mode

when it comes out of reset.

**Handler mode** Handles exceptions. The processor returns to Thread mode when it has

finished all exception processing.

The *privilege levels* for software execution are:

**Unprivileged** The software:

- Has limited access to system registers using the MSR and MRS instructions, and cannot use the CPS instruction to mask interrupts.
- Cannot access the system timer, NVIC, or system control block.
- Might have restricted access to memory or peripherals.

*Unprivileged software* executes at the unprivileged level.

**Privileged** The software can use all the instructions and has access to all resources.

*Privileged software* executes at the privileged level.

In Thread mode, the CONTROL register controls whether software execution is privileged or unprivileged, see *CONTROL register on page 27*. In Handler mode, software execution is always privileged.

Only privileged software can write to the CONTROL register to change the privilege level for software execution in Thread mode. Unprivileged software can use the SVC instruction to make a *supervisor call* to transfer control to privileged software.

## **2.1.2 Stacks**

The processor uses a full descending stack. This means the stack pointer holds the address of the last stacked item in memory. When the processor pushes a new item onto the stack, it decrements the stack pointer and then writes the item to the new memory location. The processor implements two stacks, the *main stack* and the *process stack*, with a pointer for each held in independent registers, see *Stack pointer on page 21*.

In Thread mode, the CONTROL register controls whether the processor uses the main stack or the process stack, see *CONTROL register on page 27*. In Handler mode, the processor always uses the main stack. The options for processor operations are:

![](_page_0_Picture_26.jpeg)

PM0253 Rev 5 19/254

**About this document PM0253**

### **Integrated instruction and data caches**

The instruction and data caches provide fast access to frequently accessed data and instructions, providing support for increased average performance when using system based memory.

#### **System timer**

The system timer, SysTick, is a 24-bit count-down timer. Use this as a *Real Time Operating System* (RTOS) tick timer or as a simple counter.

#### **Memory Protection Unit**

The *Memory Protection Unit* (MPU) improves system reliability by defining the memory attributes for different memory regions. It provides up to 8 different regions, and an optional predefined background region.

#### **Floating-point unit**

The FPU provides IEEE754-compliant operations on 32-bit single-precision and 64-bit double-precision floating-point values.

18/254 PM0253 Rev 5