#include "stm32f446xx_map.h"
#include "stm32f446xx_regs.h"


extern unsigned int _stack;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;
extern unsigned int _sidata;
extern int main(void);

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
        RCC->AHB1ENR |= (1 << 0);        // Enable clock for GPIOA
    GPIOA->MODER |= (1 << (2 * 5));  // Set PA5 as output
    GPIOA->ODR |= (1 << 5);           // Set PA5 high
    while (1);
    // to catch hardfaults
}

void isr_TIM2(void) {
    // Toggle PA5
    GPIOA->ODR ^= (1 << 5);
    // Clear the interrupt flag
    TIM2->SR &= ~(1 << 0); // Clear UIF flag
}

typedef void (*isr_t)(void);
#define IVT_SIZE 112U
__attribute__((used, section(".isr_vector")))
static const isr_t vector_table[IVT_SIZE] = {
    (isr_t)(&_stack),
    isr_reset,
    0,
    isr_hardfault,
    [44] = isr_TIM2,    //Todo: Add other ISRs here, 
    
};
