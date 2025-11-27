#include "stm32f446xx_helper.h"
#include "stm32f446xx_map.h"
#include "stm32f446xx_regs.h"


int main(){
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    RCC_EnableGPIO('C');  // Enable GPIOC clock
    GPIO_PinMode(GPIOA, 5, 1);  // Set PA5 as output
    GPIO_PinMode(GPIOC, 13, 0); // Set PC13 as input
    SYSCFG->EXTICR4 = (0b0010 << 4);
    EXTI->FTSR = (0b1 << 13);
    EXTI->IMR = (0b1 << 13);
}

void EXTI13_ISR(){
    GPIO_TogglePin(GPIOA, 5);
    EXTI->PR = (0b1 << 13);
}