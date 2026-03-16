/* Contains weakly defined interrupt service routines (ISRs) for the STM32F446xx microcontroller.
   Users can override these defaults by providing their own implementations.
*/

#include "stm32f446xx_isr.h"
#include "stm32f446xx.h"

__attribute__((weak)) void NMI_ISR(void) {
    GPIO_SetPin(GPIOA, 5, true);
    while (1);
}

__attribute__((weak)) void HardFault_Handler(void) {
    while (1);
}

__attribute__((weak)) void MemManage_Handler(void) {
    while (1);
}

__attribute__((weak)) void BusFault_Handler(void) {
    while (1);
}

__attribute__((weak)) void UsageFault_Handler(void) {
    while (1);
}

__attribute__((weak)) void SVC_Handler(void) {
    while (1);
}

__attribute__((weak)) void DEBUG_ISR(void) {
    while (1);
}

__attribute__((weak)) void PENDSV_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI0_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI1_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI2_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI3_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI4_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI9_5_ISR(void) {
    while (1);
}

__attribute__((weak)) void TIM2_ISR(void) {
    while (1);
}

__attribute__((weak)) void EXTI15_10_ISR(void) {
    while (1);
}
