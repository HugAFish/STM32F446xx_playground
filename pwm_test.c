#include "stm32f446xx_helper.h"
volatile uint32_t duty = 0;
volatile uint8_t feq = 1000;
int main(void) {

RCC_EnableGPIO('A');  // Enable GPIOA clock
GPTIMA_EnableCounter(TIM2); // Enable TIM2 clock
GPTIMA_CounterBuffer(TIM2, true); // Enable counter buffer
GPTIMA_ARBufferCmd(TIM2, true); // Enable auto-reload buffer
GPIO_PinMode(GPIOA, 5, 2);  // Set PA5 as output
GPIOA->AFRL |=  (0x1 << (5 * 4)); // Set AF1 for PA5
GPTIMA_SetPrescaler(TIM2, 1); // Set prescaler to 4 (16MHz/5 = 3.2MHz)
GPTIMA_SetAutoReload(TIM2, feq); // Set auto-reload to 999 (84MHz/1000 = 84kHz)
GPTIMA_OutputMode(TIM2, 1, 6); // Set channel 1 to PWM mode 1
TIM2->DIER |= (1 << 1); // Enable interrupt for channel 1
GPTIMA_ResetCounter(TIM2);
GPTIMA_DutyCycle(TIM2, 1, duty); // Set duty cycle to 0% (0/999)


while(1) {

}
return 0;
}

void isr_TIM2(void) {
  if (TIM2->SR & (1 << 1)) { // Check if interrupt is from channel 1
    TIM2->SR &= ~(1 << 1); // Clear interrupt flag
    
  }
}
