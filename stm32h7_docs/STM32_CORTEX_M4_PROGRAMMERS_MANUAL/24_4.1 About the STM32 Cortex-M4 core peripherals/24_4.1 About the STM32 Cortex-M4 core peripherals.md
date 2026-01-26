**PM0214 Core peripherals**

# **4 Core peripherals**

### **4.1 About the STM32 Cortex-M4 core peripherals**

The address map of the *Private peripheral bus* (PPB) is:

**Table 37. STM32 core peripheral register regions** 

| Address               | Core peripheral                                   | Description          |
|-----------------------|---------------------------------------------------|----------------------|
| 0xE000E010-0xE000E01F | System timer                                      | Table 55 on page 251 |
| 0xE000E100-0xE000E4EF | Nested vectored interrupt<br>controller           | Table 49 on page 219 |
| 0xE000ED00-0xE000ED3F | System control block                              | Table 53 on page 244 |
| 0xE000ED88-0xE000ED8B | Floating point unit<br>coprocessor access control | Table 56 on page 252 |
| 0xE000ED90-0xE000EDB8 | Memory protection unit                            | Table 44 on page 206 |
| 0xE000EF00-0xE000EF03 | Nested vectored interrupt<br>controller           | Table 49 on page 219 |
| 0xE000EF30-0xE000EF44 | Floating point unit                               | Table 56 on page 252 |

In register descriptions,

- Register type is described as follows:
  - RW: Read and write.
  - RO: Read-only.
  - WO: Write-only.
- *Required privilege* gives the privilege level required to access the register, as follows:
  - Privileged: Only privileged software can access the register.
  - Unprivileged**:** Both unprivileged and privileged software can access the register.

## **4.2 Memory protection unit (MPU)**

This section describes the Memory protection unit (MPU) which is implemented in some STM32 microcontrollers. Refer to the corresponding device datasheet to see if the MPU is present in the STM32 type you are using.

The MPU divides the memory map into a number of regions, and defines the location, size, access permissions, and memory attributes of each region. It supports:

- Independent attribute settings for each region
- Overlapping regions
- Export of memory attributes to the system.

The memory attributes affect the behavior of memory accesses to the region. The Cortex-M4 MPU defines:

- Eight separate memory regions, 0-7
- A background region.

![](_page_0_Picture_23.jpeg)

PM0214 Rev 10 193/262

### **3.11.12 WFI**

Wait for Interrupt.

#### **Syntax**

WFI{*cond*}

#### Where:

• *'cond'* is an optional condition code, see *Conditional execution on page 65*.

#### **Operation**

WFI is a hint instruction that suspends execution until one of the following events occurs:

- An exception
- A Debug Entry request, regardless of whether Debug is enabled.

#### **Condition flags**

This instruction does not change the flags.

#### **Examples**

WFI ; Wait for interrupt

192/262 PM0214 Rev 10