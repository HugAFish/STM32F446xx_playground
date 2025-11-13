#include "stm32f446xx_helper.h"
/*
Just like everything else that may be published:
!!WARNING!! this is a fun experiment and learning environment, use at own your risk!!
this is a helper library for the STM32F446 microcontroller
it MAY or MAY NOT be comprehensive and fully correct
*/
/*
High level abstraction functions for peripherals
*/

//UART
/*
Sends a string over USART
takes a pointer to the first character of the string and the length of the string
*/
void USART_SendString(USART_TypeDef *USARTx, char str[], uint16_t length) {
  for (uint16_t i = 0; i < length; i++) {
    while (!(USARTx->SR & (1 << 7))); // wait TXE
    USARTx->DR = str[i];
  }
  }

/*
Takes a value and sends it over USART as a string
max_magnitude is the maximum amount of digits the value can have
for example, if the value is between -999 and 999, max_magnitude is 3
if the value is between -9999 and 9999, max_magnitude is 4

*/
void USART_SendValue(USART_TypeDef *USARTx, int value, int max_magnitude) {// this can be scaled up but that would take forever to prosses on these chips
    const int MAGNITUDE[] = {1, 10, 100, 1000, 10000, 100000}; //short cut for powers of ten
  if (max_magnitude < 0 || max_magnitude > 5) {
    return; // out of range
  }
  if (value == 0) {
    USART_WaitSendByte(USARTx, '0');
    return;
  }
    if (value < 0) {
    USART_WaitSendByte(USARTx, '-');
    value = -value;
  }
  for (int i = max_magnitude; i >= 0; i--) {
    int divisor = 1;
    for (int j = 0; j < i; j++) {
      divisor *= 10;
    }
    int digit = (value / divisor);
    USART_WaitSendByte(USARTx, '0' + digit);
    value -= digit * divisor;
  }
}






/*
Low level abstraction functions for peripherals
*/
/*GPIO
GPIO is split into ports A to H
there is no unique GPIO struct as each port has the same register layout
the GPIOx pointer is used to point to the specific port
as of now, alternative functions dont have proper abstraction
*/

// Set or reset the pin via a buffered set/reset register
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber, bool Pin) {
  if (Pin) {
    GPIOx->BSRR |= (1 << PinNumber);
  } else {
    GPIOx->BSRR |= (1 << (PinNumber + 16));
  }
}

// Toggle the pin state via the output data register (no buffering)
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
  GPIOx->ODR ^= (1 << PinNumber);
}

/*
Set the pin mode
Mode: 0 = Input, 1 = Output, 2 = Alternate function, 3 = Analog
*/
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

// Read the pin state via the input data register, return true if high, false if low
bool GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber) {
  return (GPIOx->IDR & (1 << PinNumber)) != 0;
}

/*
Set the pin alternate function mode
Reffer to the datasheet for the alternate function mapping as these are pin specific
*/
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

//Enable the clock for the specified GPIO port
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

//Enable the clock for the specified timer
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

//Enable the clock for the specified USART
void RCC_EnableUSART(int usart) {
  switch (usart) {
    case 1:
      RCC->APB2ENR |= (1 << 4);
      break;
    case 2:
      RCC->APB1ENR |= (1 << 17);
      break;
    case 3:
      RCC->APB1ENR |= (1 << 18);
      break;
    case 4:
      RCC->APB1ENR |= (1 << 19);
      break;
    case 5:
      RCC->APB1ENR |= (1 << 20);
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

//Set the prescaler value for  a general purpose timer of group A
void GPTIMA_SetPrescaler(GPTIMA_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}

//Set the prescaler value for  a general purpose timer of group B
void GPTIMB_SetPrescaler(GPTIMB_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}

//Set the auto-reload value for an advanced timer
void ATIM_SetAutoReload(ATIM_TypeDef *TIMx, uint32_t AutoReload) {
  TIMx->ARR = AutoReload; //Not all timers are 32 bit, some are 16 bit
}

//Set the prescaler value for a basic timer
void BTIM_SetPrescaler(BTIM_TypeDef *TIMx, uint32_t Prescaler) {
  TIMx->PSC = Prescaler;
}

/*
Enable or disable the auto-reload register buffer of a general purpose timer of group A
*/
void GPTIMA_ARBuffer(GPTIMA_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}

/*
Enable or disable the auto-reload register buffer of a general purpose timer of group B
*/
void GPTIMB_ARBuffer(GPTIMB_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}

//Enable or disable the auto-reload register buffer of an advanced timer
void ATIM_ARBuffer(ATIM_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}

//Enable or disable the auto-reload register buffer of a basic timer
void BTIM_ARBuffer(BTIM_TypeDef *TIMx, bool Enable) {
  if (Enable) {
    TIMx->CR1 |= (1 << 7); // ARPE = 1
  } else {
    TIMx->CR1 &= ~(1 << 7); // ARPE = 0
  }
}

//Enable the counter for the specified timer
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

//The duty cycle is not a percentage but a value between 0 and the auto-reload value\
//Some timers are 16 bit so the max value is 65535
//Some timers are 32 bit so the max value is 4294967295
void GPTIMA_DutyCycle(GPTIMA_TypeDef *TIMx, uint8_t channel, uint32_t DutyCycle) {
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

/*
Reset the timer peripheral by generating an update event
This function must be called after the the timer is setup to properly work
*/
void GPTIMA_ResetCounter(GPTIMA_TypeDef *TIMx) {
  TIMx->EGR |= 1;
}

/*
Mode: 0 = edge-aligned, 1 = center-aligned 1, 2 = center-aligned 2, 3 = center-aligned 3
Direction: 1 = upcounter, 2 = downcounter

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
void GPTIMA_Direction(GPTIMA_TypeDef *TIMx, uint8_t Mode, uint8_t Direction) {
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
void GPTIMA_OutputMode(GPTIMA_TypeDef *TIMx, uint8_t channel, uint8_t Mode) {

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

//USART
//if you are reading this befor a proper realease, this section will get many updated for debugging
/*
Just because all functions are called USART does not mean they all have the ability be synchronous
USART5 and UART4 are not synchronous capable
*/
/*
Set the baud rate for the specified USART peripheral
PCLK is the peripheral clock frequency in Hz
BaudRate is the desired baud rate
USARTDIV = PCLK / (16 * BaudRate)
Mantissa = Integer part of USARTDIV
Fraction = (USARTDIV - Mantissa) * 16
*/
void USART_SetBaud(USART_TypeDef *USARTx, uint32_t BaudRate, uint32_t PCLK) {
  float usartdiv = (float)PCLK / (16 * BaudRate);
  uint32_t mantissa = (uint32_t)usartdiv;
  uint32_t fraction = (uint32_t)((usartdiv - mantissa) * 16);
  USARTx->BRR = (mantissa << 4) | (fraction & 0xF);
}  

/*
Enable or disable the USART peripheral
*/
void USART_Enable(USART_TypeDef *USARTx, bool Enable) {
  if (Enable) {
    USARTx->CR1 |= (1 << 13); // UE = 1
  } else {
    USARTx->CR1 &= ~(1 << 13); // UE = 0
  }
}

/*
Enable or disable the USART transmitter
*/
void USART_EnableTX(USART_TypeDef *USARTx, bool Enable) {
  if (Enable) {
    USARTx->CR1 |= (1 << 3); // TE = 1
  } else {
    USARTx->CR1 &= ~(1 << 3); // TE = 0
  }
}

/*
Enable or disable the USART receiver
*/
void USART_EnableRX(USART_TypeDef *USARTx, bool Enable) {
  if (Enable) {
    USARTx->CR1 |= (1 << 2); // RE = 1
  } else {
    USARTx->CR1 &= ~(1 << 2); // RE = 0
  }
}

/*
Send a byte of data over USART
Waits until the transmit data register is empty before sending the data
*/
void USART_WaitSendByte(USART_TypeDef *USARTx, uint8_t Data) {
  while (!(USARTx->SR & (1 << 7))); // Wait until TXE (Transmit data register empty) is set
  USARTx->DR = Data; // Send data
}


/*
Send a byte of data over USART
Does not wait until the transmit data register is empty before sending the data
*/
void USART_SendByte(USART_TypeDef *USARTx, uint8_t Data) {
  USARTx->DR = Data; // Send data
}

