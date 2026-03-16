#include "stm32f446xx.h"

void main(void) {
    // Your main code here
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    GPIO_PinMode(GPIOA, 5, 1);  // Set PA5 as output
    GPIO_SetPin(GPIOA, 5, LOW);  // Set PA5 low
    while (1);
}

void NMI_ISR(void) {
    GPIO_SetPin(GPIOA, 5, HIGH);  // Set PA5 high
}