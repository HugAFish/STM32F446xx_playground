#include "stm32f446xx_helper.h"

int main(void) {
    int delay;
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    RCC_EnableGPIO('C');  // Enable GPIOC clock
    GPIO_PinMode(GPIOA, 5, 1);  // Set PA5 as output
    GPIO_PinMode(GPIOC, 13, 0); // Set PC13 as input
    
    GPIO_SetPin(GPIOA, 5, true);  // Set PA5 high;
    for (int i = 0; i < 1000000; i++) {
      delay++;
    }
    GPIO_SetPin(GPIOA, 5, false);  // Set PA5 low
    while(1) {
      if (GPIO_ReadPin(GPIOC, 13)) {  // If PC13 is high
        GPIO_SetPin(GPIOA, 5, true);  // Set PA5 high
    }
    else {
      GPIO_SetPin(GPIOA, 5, false);  // Set PA5 low
    }
  }
  return 0;
}