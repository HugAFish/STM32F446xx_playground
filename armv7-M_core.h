#include <cstdint>
#ifndef ARMV7M_CORE_H
#define ARMV7M_CORE_H

//System control space
typedef struct 
{
    volatile uint32_t CPUID;
    volatile uint32_t ICSR;
    volatile uint32_t VTOR;
    volatile uint32_t AIRCR;
    volatile uint32_t SCR;
    volatile uint32_t CCR;
    volatile uint32_t SHPR1;
    volatile uint32_t SHPR2;
    volatile uint32_t SHPR3;
    volatile uint32_t SHCSR;
    volatile uint32_t CFSR;
    volatile uint32_t HFSR;
    volatile uint32_t DFSR;
    volatile uint32_t MMFAR;
    volatile uint32_t BFAR;
    volatile uint32_t AFSR;
    volatile uint32_t CPACR;
} SYSCON_TypeDef;
#define SYSCON ((SYSCON_TypeDef *) SYSCON_BASE);
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
#define FPU ((FPU_TypeDef *) FPU_BASE);
#endif // ARMV7M_CORE_H