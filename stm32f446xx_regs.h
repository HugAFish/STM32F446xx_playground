#ifndef STM32F446XX_REGS_H
#define STM32F446XX_REGS_H
//WARNING!! I don't know what I am doing, use at own your risk!!
//this !!SHOULD!! be every peripheral register, I may be incorrect
//register base and end address are specific to the STM32F446 microcontroller
//some peripheral registers are used for multiple functions(i.e ADC is for ADC1-3 and SPI2-3 are also for I2S2-3)
//always refer to the reference manual for detailed information

#define DCMI_BASE               0x50050000UL 
#define DCMI_END_ADDRESS        0x500507FFUL
#define USB_OTG_FS_BASE         0x50000000UL
#define USB_OTG_FS_END_ADDRESS  0x5003FFFFUL
#define USB_OTG_HS_BASE         0x40040000UL
#define USB_OTG_HS_END_ADDRESS  0x4007FFFFUL
#define DMA2_BASE               0x40026400UL
#define DMA2_END_ADDRESS        0x400267FFUL
#define DMA1_BASE               0x40026000UL
#define DMA1_END_ADDRESS        0x400263FFUL
#define BKPSRAM_BASE            0x40024000UL
#define BKPSRAM_END_ADDRESS     0x40024FFFUL
#define FLASH_BASE              0x40023C00UL
#define FLASH_END_ADDRESS       0x40023FFFUL
#define RCC_BASE                0x40023800UL
#define RCC_END_ADDRESS         0x40023BFFUL
#define CRC_BASE                0x40023000UL
#define CRC_END_ADDRESS         0x400233FFUL
#define GPIOH_BASE              0x40021C00UL
#define GPIOH_END_ADDRESS       0x40021FFFUL
#define GPIOG_BASE              0x40021800UL
#define GPIOG_END_ADDRESS       0x40021BFFUL
#define GPIOF_BASE              0x40021400UL
#define GPIOF_END_ADDRESS       0x400217FFUL
#define GPIOE_BASE              0x40021000UL
#define GPIOE_END_ADDRESS       0x400213FFUL
#define GPIOD_BASE              0x40020C00UL
#define GPIOD_END_ADDRESS       0x40020FFFUL
#define GPIOC_BASE              0x40020800UL
#define GPIOC_END_ADDRESS       0x40020BFFUL
#define GPIOB_BASE              0x40020400UL
#define GPIOB_END_ADDRESS       0x400207FFUL
#define GPIOA_BASE              0x40020000UL
#define GPIOA_END_ADDRESS       0x400203FFUL
#define SAI2_BASE               0x40015C00UL
#define SAI2_END_ADDRESS        0x40015FFFUL
#define SAI1_BASE               0x40015800UL
#define SAI1_END_ADDRESS        0x40015BFFUL
#define TIM11_BASE              0x40014800UL
#define TIM11_END_ADDRESS       0x40014BFFUL
#define TIM10_BASE              0x40014400UL
#define TIM10_END_ADDRESS       0x400147FFUL
#define TIM9_BASE               0x40014000UL
#define TIM9_END_ADDRESS        0x400143FFUL
#define EXTI_BASE               0x40013C00UL
#define EXTI_END_ADDRESS        0x40013FFFUL
#define SYSCFG_BASE             0x40013800UL
#define SYSCFG_END_ADDRESS      0x40013BFFUL
#define SPI4_BASE               0x40013400UL
#define SPI4_END_ADDRESS        0x400137FFUL
#define SPI1_BASE               0x40013000UL
#define SPI1_END_ADDRESS        0x400133FFUL
#define SDMMC_BASE              0x40012C00UL
#define SDMMC_END_ADDRESS       0x40012FFFUL
#define ADC_BASE                0x40012000UL //this is for ADC1-3
#define ADC_END_ADDRESS         0x40012FFFUL
#define USART6_BASE             0x40011400UL
#define USART6_END_ADDRESS      0x400117FFUL
#define USART1_BASE             0x40011000UL
#define USART1_END_ADDRESS      0x400113FFUL
#define TIM8_BASE               0x40010400UL
#define TIM8_END_ADDRESS        0x400107FFUL
#define TIM1_BASE               0x40010000UL
#define TIM1_END_ADDRESS        0x400103FFUL
#define DAC_BASE                0x40007400UL
#define DAC_END_ADDRESS         0x400077FFUL
#define PWR_BASE                0x40007000UL
#define PWR_END_ADDRESS         0x400077FFUL
#define HDMI_CEC_BASE           0x40006C00UL
#define HDMI_CEC_END_ADDRESS    0x40006FFFUL
#define CAN2_BASE               0x40006800UL
#define CAN2_END_ADDRESS        0x40006BFFUL
#define CAN1_BASE               0x40006400UL
#define CAN1_END_ADDRESS        0x400067FFUL
#define I2C3_BASE               0x40005C00UL
#define I2C3_END_ADDRESS        0x40005FFFUL
#define I2C2_BASE               0x40005800UL
#define I2C2_END_ADDRESS        0x40005BFFUL
#define I2C1_BASE               0x40005400UL
#define I2C1_END_ADDRESS        0x400057FFUL
#define UART5_BASE              0x40005000UL
#define UART5_END_ADDRESS       0x400053FFUL
#define UART4_BASE              0x40004C00UL
#define UART4_END_ADDRESS       0x40004FFFUL
#define USART3_BASE             0x40004800UL
#define USART3_END_ADDRESS      0x40004BFFUL
#define USART2_BASE             0x40004400UL
#define USART2_END_ADDRESS      0x400047FFUL
#define SPDIF_RX_BASE           0x40004000UL
#define SPDIF_RX_END_ADDRESS    0x400043FFUL
#define SPI3_BASE               0x40003C00UL //can also be used for I2S3
#define SPI3_END_ADDRESS        0x40003FFFUL
#define SPI2_BASE               0x40003800UL //can also be used for I2S2
#define SPI2_END_ADDRESS        0x40003BFFUL
#define IWDG_BASE               0x40003000UL
#define IWDG_END_ADDRESS        0x400033FFUL
#define WWDG_BASE               0x40002C00UL
#define WWDG_END_ADDRESS        0x40002FFFUL
#define RTC_BKP_BASE            0x40002800UL
#define RTC_BKP_END_ADDRESS     0x40002BFFUL
#define TIM14_BASE              0x40002000UL
#define TIM14_END_ADDRESS       0x400023FFUL
#define TIM13_BASE              0x40001C00UL
#define TIM13_END_ADDRESS       0x40001FFFUL
#define TIM12_BASE              0x40001800UL
#define TIM12_END_ADDRESS       0x40001BFFUL
#define TIM7_BASE               0x40001400UL
#define TIM7_END_ADDRESS        0x400017FFUL
#define TIM6_BASE               0x40001000UL
#define TIM6_END_ADDRESS        0x400013FFUL
#define TIM5_BASE               0x40000C00UL
#define TIM5_END_ADDRESS        0x40000FFFUL
#define TIM4_BASE               0x40000800UL
#define TIM4_END_ADDRESS        0x40000BFFUL
#define TIM3_BASE               0x40000400UL
#define TIM3_END_ADDRESS        0x400007FFUL
#define TIM2_BASE               0x40000000UL
#define TIM2_END_ADDRESS        0x400003FFUL

//remember to read the reference manual for detailed information

#endif // STM32F446XX_REGS_H