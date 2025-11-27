#include "stm32f446xx_helper.h"
#include "stm32f446xx_map.h"
#include "stm32f446xx_regs.h"

int main(void) {

  // 1️⃣ Enable clocks
  RCC_EnableGPIO('A');
  RCC_EnableTIM(2);

  // 2️⃣ Configure PA5 as alternate function (AF1)
  GPIO_PinMode(GPIOA, 5, 2);
  GPIO_AFMode(GPIOA, 5, 1);

  // 3️⃣ Configure TIM2
  GPTIMA_Direction(TIM2, 0, 1);
  TIM2->PSC = 0;             // No prescaler
  TIM2->ARR = 1000;          // Period

  // 4️⃣ Configure PWM mode on channel 1
  GPTIMA_OutputMode(TIM2, 1, 6);

  // 5️⃣ Enable channel output

  // 6️⃣ Set duty cycle
  GPTIMA_DutyCycle(TIM2, 1, 500);

  // 7️⃣ Force update and start timer
  GPTIMA_ResetCounter(TIM2);
  GPTIMA_EnableStart(TIM2, 1);


  while(1) {

  }
return 0;
}

