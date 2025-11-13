#include "stm32f446xx_helper.h"
int main(void)
{
    char alph[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char name[5] = "James";
    // 1. Enable clocks
    RCC_EnableGPIO('A');  // Enable GPIOA clock
    RCC_EnableUSART(2); // Enable USART2 clock
    RCC_EnableGPIO('C');  // Enable GPIOC clock

    // 2. Set PA2 to AF7 (USART2_TX)
    GPIO_PinMode(GPIOA, 2, 2);  // Set PA2 to Alternate Function mode
    GPIO_AFMode(GPIOA, 2, 7);  // Set PA2 to AF7
    GPIO_PinMode(GPIOC, 13, 0); // Set PC13 to input mode

    // 3. Configure USART2 baud = 9600, assuming 16 MHz PCLK1
    USART_SetBaud(USART2, 9600, 16000000);

    // 4. Enable TX and USART
    USART_EnableTX(USART2, true);
    USART_Enable(USART2, true);

    // 5. Send forever
    while (1) {
        for (int i = 0; i < 26; i++) {
            USART_WaitSendByte(USART2, alph[i]);
        }
        USART_WaitSendByte(USART2, '\n');
        while(GPIO_ReadPin(GPIOC, 13)); // Wait until button is pressed
        for (int i = 0; i < 5; i++) {
            USART_WaitSendByte(USART2, name[i]);
        }
        USART_WaitSendByte(USART2, '\n');
        while(!GPIO_ReadPin(GPIOC, 13)); // Wait until button is released
        USART_SendValue(USART2, 1234, 4); // Send the value 1234
        USART_WaitSendByte(USART2, '\n');
    }
}
