# **2 The Cortex-M4 processor**

## **2.1 Programmers model**

This section describes the Cortex-M4 programmer's model. In addition to the individual core register descriptions, it contains information about the processor modes and privilege levels for software execution and stacks.

#### **2.1.1 Processor mode and privilege levels for software execution**

The processor *modes* are:

**Thread mode**: Used to execute application software.

The processor enters Thread mode when it comes out of reset. The CONTROL register controls whether software execution is privileged or unprivileged, see *CONTROL register on page 25*.

**Handler mode**: Used to handle exceptions.

The processor returns to Thread mode when it has finished exception processing.

Software execution is always privileged.

The *privilege levels* for software execution are:

**Unprivileged**: *Unprivileged software* executes at the unprivileged level and:

- Has limited access to the MSR and MRS instructions, and cannot use the CPS instruction.
- Cannot access the system timer, NVIC, or system control block.
- Might have restricted access to memory or peripherals.
- Must use the SVC instruction to make a *supervisor call* to transfer control to privileged software.

**Privileged:** *Privileged software* executes at the privileged level and can use all the instructions and has access to all resources.

> Can write to the CONTROL register to change the privilege level for software execution.

### **2.1.2 Stacks**

The processor uses a full descending stack. This means the stack pointer indicates the last stacked item on the stack memory. When the processor pushes a new item onto the stack, it decrements the stack pointer and then writes the item to the new memory location. The processor implements two stacks, the *main stack* and the *process stack*, with independent copies of the stack pointer, see *Stack pointer on page 19*.

In Thread mode, the CONTROL register controls whether the processor uses the main stack or the process stack, see *CONTROL register on page 25*. In Handler mode, the processor always uses the main stack. The options for processor operations are:

![](_page_0_Picture_24.jpeg)

PM0214 Rev 10 17/262

**About this document PM0214**

#### **1.3.4 Cortex-M4 core peripherals**

The peripherals are:

#### **Nested vectored interrupt controller**

The *nested vectored interrupt controller* (NVIC) is an embedded interrupt controller that supports low latency interrupt processing.

#### **System control block**

The *system control block* (SCB) is the programmer's model interface to the processor. It provides system implementation information and system control, including configuration, control, and reporting of system exceptions.

#### **System timer**

The system timer (SysTick) is a 24-bit count-down timer. Use this as a Real Time Operating System (RTOS) tick timer or as a simple counter.

#### **Memory protection unit**

The *Memory protection unit* (MPU) improves system reliability by defining the memory attributes for different memory regions. It provides up to eight different regions, and an optional predefined background region.

#### **Floating-point unit**

The *Floating-point unit* (FPU) provides IEEE754-compliant operations on singleprecision, 32-bit, floating-point values.

16/262 PM0214 Rev 10