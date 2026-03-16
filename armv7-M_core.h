#include <stdint.h>
#include "armv7-M_address.h"
#ifndef ARMV7M_CORE_H
#define ARMV7M_CORE_H

//SCB
typedef struct
{
    volatile uint32_t CPUID; // CPUID Register
    volatile uint32_t ICSR; // Interrupt Control and State Register
    volatile uint32_t VTOR; // Vector Table Offset Register
    volatile uint32_t AIRCR; // Application Interrupt and Reset Control Register
    volatile uint32_t SCR; // System Control Register
    volatile uint32_t CCR; // Configuration Control Register
    volatile uint32_t SHPR1; // System Handler Priority Register 1
    volatile uint32_t SHPR2; // System Handler Priority Register 2
    volatile uint32_t SHPR3; // System Handler Priority Register 3
    volatile uint32_t SHCSR; // System Handler Control and State Register
    volatile uint32_t CFSR; // Configurable Fault Status Register
    volatile uint32_t HFSR; // HardFault Status Register
    volatile uint32_t DFSR; // Debug Fault Status Register
    volatile uint32_t MMFAR; // MemManage Fault Address Register
    volatile uint32_t BFAR; // Bus Fault Address Register
    volatile uint32_t AFSR; // Auxiliary Fault Status Register
    volatile uint32_t RESERVED[17];

    volatile uint32_t CPACR; // Coprocessor Access Control Register
} SCB_TypeDef;
#define SCB ((SCB_TypeDef *) SCB_BASE)

//FPU
typedef struct
{
    volatile uint32_t FPCCR;
    volatile uint32_t FPCAR;
    volatile uint32_t FPDSCR;
    volatile uint32_t MVFR0;
    volatile uint32_t MVFR1;
    volatile uint32_t MVFR2;
} FPU_TypeDef;
#define FPU ((FPU_TypeDef *) FPU_BASE)

//NVIC
typedef struct
{
    volatile uint32_t ISER[16]; // Interrupt Set Enable Register
    volatile uint32_t RESERVED0[16];
    volatile uint32_t ICER[16]; // Interrupt Clear Enable Register
    volatile uint32_t RESERVED1[16];
    volatile uint32_t ISPR[16]; // Interrupt Set Pending Register
    volatile uint32_t RESERVED2[16];
    volatile uint32_t ICPR[16]; // Interrupt Clear Pending Register
    volatile uint32_t RESERVED3[16];
    volatile uint32_t IABR[16]; // Interrupt Active Bit Register
    volatile uint32_t RESERVED5[16];
    volatile uint32_t IPR[124]; // Interrupt Priority Register

} NVIC_TypeDef;
#define NVIC ((NVIC_TypeDef *) NVIC_BASE)

#endif // ARMV7M_CORE_H