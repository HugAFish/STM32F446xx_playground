#include "stm32f446xx_map.h"
#include <stdint.h>
#include <stdbool.h>

/*
Just like everything else that may be published:
!!WARNING!! I don't know what I am doing, use at own your risk!!
this is a helper library for the STM32F446 microcontroller
it MAY or MAY NOT be comprehensive and fully correct
*/
/*
High level abstraction functions for peripherals
*/











/*
Low level abstraction functions for peripherals
*/
/*GPIO
GPIO is split into ports A to H
there is no unique GPIO struct as each port has the same register layout
the GPIOx pointer is used to point to the specific port
as of now, alternative functions dont have proper abstraction
*/
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber, bool Pin) {
  if (Pin) {
    GPIOx->BSRR |= (1 << PinNumber);
  } else {
    GPIOx->BSRR |= (1 << (PinNumber + 16));
  }
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
  GPIOx->ODR ^= (1 << PinNumber);
}

void GPIO_PinMode(GPIO_TypeDef *GPIOx, uint32_t PinNumber, uint8_t Mode) {
  GPIOx->MODER &= ~(3 << (PinNumber * 2));
  switch (Mode) {
    case 0:  // Input
      break;
    case 1:  // Output
      GPIOx->MODER |= (1 << (PinNumber * 2));
      break;
    case 2:  // Alternate function
      GPIOx->MODER |= (2 << (PinNumber * 2));
      break;
    case 3:  // Analog
      GPIOx->MODER |= (3 << (PinNumber * 2));
      break;
    default:
      break;
  }
}

bool GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
  return (GPIOx->IDR & (1 << PinNumber)) != 0;
}

void GPIO_AFMode(GPIO_TypeDef *GPIOx, uint32_t PinNumber, uint8_t AF) {
  if (PinNumber < 8) {
    GPIOx->AFRL &= ~(0xF << (PinNumber * 4));
    GPIOx->AFRL |= (AF << (PinNumber * 4));
  } else {
    GPIOx->AFRH &= ~(0xF << ((PinNumber - 8) * 4));
    GPIOx->AFRH |= (AF << ((PinNumber - 8) * 4));
  }
}

/*RCC
enable functions may be moved to their respective peripheral sections
*/
void RCC_EnableGPIO(char port) {
  switch (port) {
    case 'A':
      RCC->AHB1ENR |= (1 << 0);
      break;
    case 'B':
      RCC->AHB1ENR |= (1 << 1);
      break;
    case 'C':
      RCC->AHB1ENR |= (1 << 2);
      break;
    case 'D':
      RCC->AHB1ENR |= (1 << 3);
      break;
    case 'E':
      RCC->AHB1ENR |= (1 << 4);
      break;
    case 'F':
      RCC->AHB1ENR |= (1 << 5);
      break;
    default:
      break;
  }
}
void RCC_EnableTIM(int tim) {
  switch (tim) {
    case 1:
      RCC->APB2ENR |= (1 << 0);
      break;
    case 2:
      RCC->APB1ENR |= (1 << 0);
      break;
    case 3:
      RCC->APB1ENR |= (1 << 1);
      break;
    case 4:
      RCC->APB1ENR |= (1 << 2);
      break;
    case 5:
      RCC->APB1ENR |= (1 << 3);
      break;
    case 6:
      RCC->APB1ENR |= (1 << 4);
      break;
    case 7:
      RCC->APB1ENR |= (1 << 5);
      break;
    case 8:
      RCC->APB2ENR |= (1 << 1);
      break;
    case 9:
      RCC->APB2ENR |= (1 << 16);
      break;
    case 10:
      RCC->APB2ENR |= (1 << 17);
      break;
    case 11:
      RCC->APB2ENR |= (1 << 18);
      break;
    case 12:
      RCC->APB1ENR |= (1 << 6);
      break;
    case 13:
      RCC->APB1ENR |= (1 << 7);
      break;
    case 14:
      RCC->APB1ENR |= (1 << 8);
      break;
    default:
      break;
  }
}
/* universal timer functions 
this section is going to be seperated due to the timers having different register layouts
I have desided to call the advanced timers ATIM and the general purpose timers GPTIMA or GPTIMB and teh basic timers BTIM
Advanced Timers (ATIM) are TIM1 and TIM8
General Purpose Timers (GPTIMA) A are TIM2 to TIM5
General Purpose Timers (GPTIMB) B are TIM9 to TIM14
Basic Timers (BTIM) are TIM6 and TIM7
functions that are specific to a timer type will be in their own section
*/
void GPTIMA_SetPrescaler(GPTIMA_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}
void GPTIMB_SetPrescaler(GPTIMB_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}
void ATIM_SetAutoReload(ATIM_TypeDef *TIMx, uint32_t AutoReload) {
  TIMx->ARR = AutoReload; //Not all timers are 32 bit, some are 16 bit
}
void BTIM_SetPrescaler(BTIM_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}

void GPTIMA_ARBuffer(GPTIMA_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}
void GPTIMB_ARBuffer(GPTIMB_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}
void ATIM_ARBuffer(ATIM_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}
void BTIM_ARBuffer(BTIM_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}

void TIM_EnableCounter(uint8_t tim) {
  switch (tim) {
	case 1:
	  RCC->APB2ENR |= (1 << 0);
	  TIM1->CR1 |= 1;
	  break;
	case 2:
	  RCC->APB1ENR |= (1 << 0);
	  TIM2->CR1 |= 1;
	  break;
	case 3:
	  RCC->APB1ENR |= (1 << 1);
	  TIM3->CR1 |= 1;
	  break;
	case 4:
	  RCC->APB1ENR |= (1 << 2);
	  TIM4->CR1 |= 1;
	  break;
	case 5:
	  RCC->APB1ENR |= (1 << 3);
	  TIM5->CR1 |= 1;
	  break;
	case 6:
	  RCC->APB1ENR |= (1 << 4);
	  TIM6->CR1 |= 1;
	  break;
	case 7:
	  RCC->APB1ENR |= (1 << 5);
	  TIM7->CR1 |= 1;
	  break;
	case 8:
	  RCC->APB2ENR |= (1 << 1);
	  TIM8->CR1 |= 1;
	  break;
	case 9:
	  RCC->APB2ENR |= (1 << 16);
	  TIM9->CR1 |= 1;
	  break;
	case 10:
	  RCC->APB2ENR |= (1 << 17);
	  TIM10->CR1 |= 1;
	  break;
	case 11:
	  RCC->APB2ENR |= (1 << 18);
	  TIM11->CR1 |= 1;
	  break;
	case 12:
	  RCC->APB1ENR |= (1 << 6);
	  TIM12->CR1 |= 1;
	  break;
	case 13:
	  RCC->APB1ENR |= (1 << 7);
	  TIM13->CR1 |= 1;
	  break;
	case 14:
	  RCC->APB1ENR |= (1 << 8);
	  TIM14->CR1 |= 1;
	  break;
	default:
	  break;
  }
}
void GPTIMA_DutyCycle(GPTIMA_TypeDef *TIMx, uint8_t channel, uint32_t DutyCycle) {
  //The duty cycle is not a percentage but a value between 0 and the auto-reload value\
  //Some timers are 16 bit so the max value is 65535
  //Some timers are 32 bit so the max value is 4294967295
  switch (channel) {
    case 1:
      TIMx->CCR1 = DutyCycle;
      break;
    case 2:
      TIMx->CCR2 = DutyCycle;
      break;
    case 3:
      TIMx->CCR3 = DutyCycle;
      break;
    case 4:
      TIMx->CCR4 = DutyCycle;
      break;
    default:
      break;
  }
}
void GPTIMA_ResetCounter(GPTIMA_TypeDef *TIMx) {
  //This fucntion must be called after the the timer is setup to properly work
  TIMx->EGR |= 1;
}
void GPTIMA_Direction(GPTIMA_TypeDef *TIMx, uint8_t Mode, uint8_t Direction) {
  //Mode: 0 = edge-aligned, 1 = center-aligned 1, 2 = center-aligned 2, 3 = center-aligned 3
  //Direction: 1 = upcounter, 2 = downcounter
  /*
  The diffrent center-aligned modes are:
  1: Center-aligned mode 1. The counter counts up and down alternatively. Output compare
  interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
  only when the counter is counting down.
  2: Center-aligned mode 2. The counter counts up and down alternatively. Output compare
  interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
  only when the counter is counting up.
  3: Center-aligned mode 3. The counter counts up and down alternatively. Output compare
  interrupt flags of channels configured in output (CCxS=00 in TIMx_CCMRx register) are set
  both when the counter is counting up or down.
  */
  TIMx->CR1 &= ~(3 << 4); // Clear CMS bits
  TIMx->CR1 &= ~(1 << 3); // Clear DIR bit
  switch (Mode) {
    case 0: // Edge-aligned mode
      break;
    case 1: // Center-aligned mode 1
      TIMx->CR1 |= (1 << 5);
      break;
    case 2: // Center-aligned mode 2
      TIMx->CR1 |= (2 << 5);
      break;
    case 3: // Center-aligned mode 3
      TIMx->CR1 |= (3 << 5);
      break;
    default:
      break;
  }
  switch (Direction) {
    case 1: // Upcounter
      TIMx->CR1 &= ~(1 << 4);
      break;
    case 2: // Downcounter
      TIMx->CR1 |= (1 << 4);
      break;
    default:
      break;
}
}

void GPTIMA_OutputMode(GPTIMA_TypeDef *TIMx, uint8_t channel, uint8_t Mode) {
/*Sets the device channel as output and configures the output mode
Available modes:
0: Frozen - Use this mode to gerante a timing base without any output
1: Active level on match - Set the output to active level when the counter matches the capture/compare register
2: Inactive level on match - Set the output to inactive level when the counter matches the capture/compare register
3: Toggle - Toggle the output when the counter matches the capture/compare register
4: Force inactive level - Set the output to inactive level (OCxREF=0)
5: Force active level - Set the output to active level (OCxREF=1)
6: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1
else inactive. In downcounting, channel 1 is inactive (OC1REF=‘0) as long as
TIMx_CNT>TIMx_CCR1 else active (OC1REF=1).
7: PWM mode 2 - In upcounting, channel 1 is inactive as long as TIMx_CNT<TIMx_CCR1
else active. In downcounting, channel 1 is active (OC1REF=‘1) as long as
TIMx_CNT>TIMx_CCR1 else inactive (OC1REF=0).
*/

  switch (channel) {
    case 1:
      TIMx->CCMR1 &= ~(0x7 << 4); // Clears input output bits
      TIMx->CCMR1 |= (Mode << 4); //Sets output mode as described above
      TIMx->CCMR1 |= (0 << 0); // Set CC1S to output
      TIMx->CCER |= (1 << 0); // Enable output for channel 1
      break;
    case 2:
      TIMx->CCMR1 &= ~(0x7 << 12); // Clear OC2M bits
      TIMx->CCMR1 |= (Mode << 12);
      TIMx->CCMR1 |= (0 << 8); // Set CC2S to output
      TIMx->CCER |= (1 << 4); // Enable output for channel 2
      break;
    case 3:
      TIMx->CCMR2 &= ~(0x7 << 4); // Clear OC3M bits
      TIMx->CCMR2 |= (Mode << 4);
      TIMx->CCMR2 |= (0 << 0); // Set CC3S to output
      TIMx->CCER |= (1 << 8); // Enable output for channel 3
      break;
    case 4:
      TIMx->CCMR2 &= ~(0x7 << 12); // Clear OC4M bits
      TIMx->CCMR2 |= (Mode << 12);
      TIMx->CCMR2 |= (0 << 8); // Set CC4S to output
      TIMx->CCER |= (1 << 12); // Enable output for channel 4
      break;
    default:
      break;
  }
}
