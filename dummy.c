#include "stm32f446xx.h"

int main(void) {
    int delay = 0;
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    RCC_EnableGPIO('C');  // Enable GPIOC clock
    GPIO_PinMode(GPIOA, 5, 1);  // Set PA5 as output
    GPIO_PinMode(GPIOC, 13, 0); // Set PC13 as input
    SYSCFG->EXTICR4 |= (1 << 5); // Map EXTI13 to PC13
    EXTI->IMR |= (1 << 13); // Unmask EXTI13
    EXTI->FTSR |= (1 << 13); // Trigger on falling edge
    NVIC->ISER[0] |= (1 << 13); // Enable EXTI13 interrupt

    SCB->ICSR |= (1 << 31); // Trigger a NMI exception

    while(1){
        for(delay = 0; delay < 100000; delay++);
        GPIO_SetPin(GPIOA, 5, false);
        for(delay = 0; delay < 100000; delay++);
        GPIO_SetPin(GPIOA, 5, true);
    }
}

void NMI_Handler(void) {
    // Handle NMI exception
    GPIO_SetPin(GPIOA, 5, true);
    int a = 2 + 2;
    while (1)
    {
        /* code */
    }
    

}