#ifndef STM32F446XX_HELPER_H
#define STM32F446XX_HELPER_H

#include "stm32f446xx_map.h"
#include <stdint.h>
#include <stdbool.h>

/*
Just like everything else that may be published:
!!WARNING!! this is a fun experiment and learning environment, use at own your risk!!
this is a helper library for the STM32F446 microcontroller
it MAY or MAY NOT be comprehensive and fully correct
*/

// UART
void USART_SendString(USART_TypeDef *USARTx, char str[], uint16_t length);
void USART_SendValue(USART_TypeDef *USARTx, int value, int max_magnitude);

// GPIO
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber, bool Pin);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint32_t PinNumber);
void GPIO_PinMode(GPIO_TypeDef *GPIOx, uint32_t PinNumber, uint8_t Mode);
bool GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t PinNumber);
void GPIO_AFMode(GPIO_TypeDef *GPIOx, uint32_t PinNumber, uint8_t AF);

// RCC
void RCC_EnableGPIO(char port);
void RCC_EnableTIM(int tim);
void RCC_EnableUSART(int usart);

// General purpose timer group A (GPTIMA)
void GPTIMA_SetPrescaler(GPTIMA_TypeDef *TIMx, uint32_t Prescaler);
void GPTIMA_ARBuffer(GPTIMA_TypeDef *TIMx, bool Enable);
void GPTIMA_DutyCycle(GPTIMA_TypeDef *TIMx, uint8_t channel, uint32_t DutyCycle);
void GPTIMA_ResetCounter(GPTIMA_TypeDef *TIMx);
void GPTIMA_Direction(GPTIMA_TypeDef *TIMx, uint8_t Mode, uint8_t Direction);
void GPTIMA_OutputMode(GPTIMA_TypeDef *TIMx, uint8_t channel, uint8_t Mode);

// General purpose timer group B (GPTIMB)
void GPTIMB_SetPrescaler(GPTIMB_TypeDef *TIMx, uint32_t Prescaler);
void GPTIMB_ARBuffer(GPTIMB_TypeDef *TIMx, bool Enable);

// Advanced timer (ATIM)
void ATIM_SetAutoReload(ATIM_TypeDef *TIMx, uint32_t AutoReload);
void ATIM_ARBuffer(ATIM_TypeDef *TIMx, bool Enable);

// Basic timer (BTIM)
void BTIM_SetPrescaler(BTIM_TypeDef *TIMx, uint32_t Prescaler);
void BTIM_ARBuffer(BTIM_TypeDef *TIMx, bool Enable);

// Timer counter enable function (works for multiple timers)
void TIM_EnableCounter(uint8_t tim);

// USART
void USART_SetBaud(USART_TypeDef *USARTx, uint32_t BaudRate, uint32_t PCLK);
void USART_Enable(USART_TypeDef *USARTx, bool Enable);
void USART_EnableTX(USART_TypeDef *USARTx, bool Enable);
void USART_EnableRX(USART_TypeDef *USARTx, bool Enable);
void USART_WaitSendByte(USART_TypeDef *USARTx, uint8_t Data);
void USART_SendByte(USART_TypeDef *USARTx, uint8_t Data);

#endif // STM32F446XX_HELPER_H