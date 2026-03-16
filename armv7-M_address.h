#ifndef ARMV7M_ADDRESS_H
#define ARMV7M_ADDRESS_H
// Basic peripheral base addresses for ARMv7-M core (Cortex-M3/M4/M7)
//ICT
#define ICT_BASE      0xE000E000UL
//SysTick
#define SYSTICK_BASE  0xE000E010UL
//NVIC
#define NVIC_BASE     0xE000E100UL
//MPU
#define MPU_BASE      0xE000ED90UL
//SCB
#define SCB_BASE      0xE000ED00UL
//FPU
#define FPU_BASE      0xE000EF34UL
//Debug
#define DEBUG_BASE    0xE000EDF0UL
//SWTRIG
#define SWTRIG_BASE   0xE000EF00UL
//Cache and branch predictor
#define CACHE_BASE    0xE000EF50UL
//ImplementationDefined
#define IMP_BASE      0xE000EF90UL
//Microcontroller-specific ID space
#define MCUID_BASE    0xE000EFD0UL

#endif // ARMV7M_ADDRESS_H