#include "stm32f446xx_helper.h"
int main(void)
{
    // 1. Enable clocks
    RCC->AHB1ENR |= (1 << 0);    // GPIOA
    RCC->APB1ENR |= (1 << 17);   // USART2

    // 2. Set PA2 to AF7 (USART2_TX)
    GPIOA->MODER &= ~(3 << (2*2));   // clear mode
    GPIOA->MODER |=  (2 << (2*2));   // AF mode
    GPIOA->AFRL &= ~(0xF << (4*2));
    GPIOA->AFRL |=  (7 << (4*2));  // AF7

    // 3. Configure USART2 baud = 9600, assuming 16 MHz PCLK1
    USART2->BRR = 0x0683;  // 0x683 = 1667 decimal → 16 MHz / 1667 ≈ 9600

    // 4. Enable TX and USART
    USART2->CR1 = (1 << 3) | (1 << 13); // TE + UE

    // 5. Send forever
    while (1) {
        while (!(USART2->SR & (1 << 7))); // wait TXE
        USART2->DR = 0b10101010; // send 'B'
    }
}
