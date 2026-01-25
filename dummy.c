#include "stm32f446xx_isr.h"
#include "stm32f446xx_helper.h"
#include "stm32f446xx_map.h"
#include "stm32f446xx_regs.h"

int main(void) {
    int delay = 0;
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    RCC_EnableGPIO('C');  // Enable GPIOC clock
    GPIO_PinMode(GPIOA, 5, 1);  // Set PA5 as output
    GPIO_PinMode(GPIOC, 13, 0); // Set PC13 as input



    while(1) {
        GPIO_SetPin(GPIOA, 5, true);  // Set PA5 low;
        for (int i = 0; i < 1000000; i++) {
        delay++;
        }
        GPIO_SetPin(GPIOA, 5, false);  // Set PA5 low;
        for (int i = 0; i < 1000000; i++) {
        delay++;
        }
    }
}