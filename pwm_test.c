#include "stm32f446xx_helper.h"

int main(void) {
RCC_EnableGPIO('A');  // Enable GPIOA clock
GPTIMA_EnableCounter(TIM2); // Enable TIM2 clock
TIM2->CR1 |= (1 << 7); // ARPE = 1
GPIO_PinMode(GPIOA, 5, 2);  // Set PA5 as output
GPIOA->AFRL &= ~(0xF << (5 * 4)); // Clear bits [23:20]
GPIOA->AFRL |=  (0x1 << (5 * 4)); // Set AF1 for PA5
GPTIMA_SetPrescaler(TIM2, 1); // Set prescaler to 4 (16MHz/5 = 3.2MHz)
GPTIMA_SetAutoReload(TIM2, 999); // Set auto-reload to 999 (84MHz/1000 = 84kHz)
TIM2->CCMR1 &= ~(0xFF << 0);      // Clear channel 1 settings
TIM2->CCMR1 |=  (6 << 4);         // OC1M = 110 = PWM mode 1
TIM2->CCMR1 |=  (1 << 3);         // OC1PE = 1
TIM2->CCER |= (1 << 0);   // CC1E = enable output
TIM2->CCER &= ~(1 << 1);  //


GPTIMA_ResetCounter(TIM2);
GPTIMA_DutyCycle(TIM2, 1, 499); // Set duty cycle to 50% (499/999)

while(1) {

}
return 0;
}
