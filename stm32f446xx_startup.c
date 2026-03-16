#include "stm32f446xx.h"

extern unsigned int _stack;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;
extern unsigned int _sidata;
extern int main(void);
extern void NMI_ISR(void);
extern void EXTI0_ISR(void);
extern void EXTI1_ISR(void);
extern void EXTI2_ISR(void);
extern void EXTI3_ISR(void);
extern void EXTI4_ISR(void);
extern void EXTI9_5_ISR(void);
extern void TIM2_ISR(void);
extern void EXTI15_10_ISR(void);

void bss_cleanup(void){
    unsigned int *p = &_sbss;
    while (p < &_ebss) {
        *p++ = 0;
    }
}

void data_init(void){
    unsigned int *src = &_sidata;
    unsigned int *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }
}

void isr_reset(void){
    bss_cleanup();
    data_init();
    main();

    // to catch returns from main
    while(1);
}

void isr_hardfault(void) {
    int delay = 0;
    RCC->AHB1ENR |= (1 << 0);        // Enable clock for GPIOA
    GPIOA->MODER |= (1 << (2 * 5));  // Set PA5 as output
    GPIOA->ODR |= (1 << 5);           // Set PA5 high
    while (1);
}

typedef void (*isr_t)(void);
#define IVT_SIZE 112U
__attribute__((used, section(".isr_vector")))
static const isr_t vector_table[IVT_SIZE] = {
    (isr_t)(&_stack),
    isr_reset,
    NMI_ISR,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0, 0, 0, 0,
    SVC_Handler,
    DEBUG_ISR,
    0,
    PENDSV_ISR,
    [22] = EXTI0_ISR,   //Todo: Enable EXTI0 to the nucleo user button to test
    [23] = EXTI1_ISR,
    [24] = EXTI2_ISR,
    [25] = EXTI3_ISR,
    [26] = EXTI4_ISR,
    [39] = EXTI9_5_ISR,
    [56] = EXTI15_10_ISR, //The ARMv7-M cpu supports just under 500 interrupts so why does st not use them
    [44] = TIM2_ISR,    //Todo: Add other ISRs here
};
