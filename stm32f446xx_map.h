#include "stm32f446xx_regs.h"
#include <stdint.h>
#ifndef STM32F446XX_MAP_H
//WARNING!! I don't know what I am doing, use at own your risk!!
//this may or may !!NOT!! be comprehensive, feel free to add if you get your hands on this
//this is a memory map specific for the STM32F446 microcontroller
//always refer to the reference manual for detailed information
//there is no safety built into the header


//DCMI
typedef struct {

} DCMI_TypeDef;
#define DCMI ((DCMI_TypeDef *) DCMI_BASE)

//USB_OTG_FS
typedef struct{

}USB_OTG_FS_TypeDef;
#define USB_OTG_FS ((USB_OTG_FS_TypeDef *) USB_OTG_FS_BASE)

//USB_OTG_HS
typedef struct {

} USB_OTG_HS_TypeDef;
#define USB_OTG_HS ((USB_OTG_HS_TypeDef *) USB_OTG_HS_BASE)

//EXTI
typedef struct {
    volatile uint32_t IMR; // Interrupt Mask Register 0x00
    volatile uint32_t EMR; // Event Mask Register 0x04
    volatile uint32_t RTSR; // Rising Trigger Selection Register 0x08
    volatile uint32_t FTSR; // Falling Trigger Selection Register 0x0C
    volatile uint32_t SWIER; // Software Interrupt Event Register 0x10
    volatile uint32_t PR; // Pending Register 0x14
} EXTI_TypeDef;
#define EXTI ((EXTI_TypeDef *) EXTI_BASE)

//DMA
typedef struct {
    volatile uint32_t LISR; // Low Interrupt Status Register 0x000
    volatile uint32_t HISR; // High Interrupt Status Register 0x004
    volatile uint32_t LIFCR; // Low Interrupt Flag Clear Register 0x008
    volatile uint32_t HIFCR; // High Interrupt Flag Clear Register 0x00C
    volatile uint32_t S0CR; // Stream 0 Control Register 0x010
    volatile uint32_t S0NDTR; // Stream 0 Number of Data Register 0x014
    volatile uint32_t S0PAR; // Stream 0 Peripheral Address Register 0x018
    volatile uint32_t S0M0AR; // Stream 0 Memory 0 Address Register 0x01C
    volatile uint32_t S0M1AR; // Stream 0 Memory 1 Address Register 0x020
    volatile uint32_t S0FCR; // Stream 0 FIFO Control Register 0x024
    volatile uint32_t S1CR; // Stream 1 Control Register 0x028
    volatile uint32_t S1NDTR; // Stream 1 Number of Data Register 0x02C
    volatile uint32_t S1PAR; // Stream 1 Peripheral Address Register 0x030
    volatile uint32_t S1M0AR; // Stream 1 Memory 0 Address Register 0x034
    volatile uint32_t S1M1FCR; // Stream 1 Memory 1 FIFO Control Register 0x038
    volatile uint32_t S1FCR; // Stream 1 FIFO Control Register 0x03C
    volatile uint32_t S2CR; // Stream 2 Control Register 0x040
    volatile uint32_t S2NDTR; // Stream 2 Number of Data Register 0x044
    volatile uint32_t S2PAR; // Stream 2 Peripheral Address Register 0x048
    volatile uint32_t S2M0AR; // Stream 2 Memory 0 Address Register 0x04C
    volatile uint32_t S2M1AR; // Stream 2 Memory 1 Address Register 0x050
    volatile uint32_t S2FCR; // Stream 2 FIFO Control Register 0x054
    volatile uint32_t S3CR; // Stream 3 Control Register 0x058
    volatile uint32_t S3NDTR; // Stream 3 Number of Data Register 0x05C
    volatile uint32_t S3PAR; // Stream 3 Peripheral Address Register 0x060
    volatile uint32_t S3M0AR; // Stream 3 Memory 0 Address Register 0x064
    volatile uint32_t S3M1AR; // Stream 3 Memory 1 Address Register 0x068
    volatile uint32_t S3FCR; // Stream 3 FIFO Control Register 0x06C
    volatile uint32_t S4CR; // Stream 4 Control Register 0x070
    volatile uint32_t S4NDTR; // Stream 4 Number of Data Register 0x074
    volatile uint32_t S4PAR; // Stream 4 Peripheral Address Register 0x078
    volatile uint32_t S4M0AR; // Stream 4 Memory 0 Address Register 0x07C
    volatile uint32_t S4M1AR; // Stream 4 Memory 1 Address Register 0x080
    volatile uint32_t S4FCR; // Stream 4 FIFO Control Register 0x084
    volatile uint32_t S5CR; // Stream 5 Control Register 0x088
    volatile uint32_t S5NDTR; // Stream 5 Number of Data Register 0x08C
    volatile uint32_t S5PAR; // Stream 5 Peripheral Address Register 0x090
    volatile uint32_t S5M0AR; // Stream 5 Memory 0 Address Register 0x094
    volatile uint32_t S5M1AR; // Stream 5 Memory 1 Address Register 0x098
    volatile uint32_t S5FCR; // Stream 5 FIFO Control Register 0x09C
    volatile uint32_t S6CR; // Stream 6 Control Register 0x0A0
    volatile uint32_t S6NDTR; // Stream 6 Number of Data Register 0x0A4
    volatile uint32_t S6PAR; // Stream 6 Peripheral Address Register 0x0A8
    volatile uint32_t S6M0AR; // Stream 6 Memory 0 Address Register 0x0AC
    volatile uint32_t S6M1AR; // Stream 6 Memory 1 Address Register 0x0B0
    volatile uint32_t S6FCR; // Stream 6 FIFO Control Register 0x0B4
    volatile uint32_t S7CR; // Stream 7 Control Register 0x0B8
    volatile uint32_t S7NDTR; // Stream 7 Number of Data Register 0x0BC
    volatile uint32_t S7PAR; // Stream 7 Peripheral Address Register 0x0C0
    volatile uint32_t S7M0AR; // Stream 7 Memory 0 Address Register 0x0C4
    volatile uint32_t S7M1AR; // Stream 7 Memory 1 Address Register 0x0C8
    volatile uint32_t S7FCR; // Stream 7 FIFO Control Register 0x0CC
} DMA_TypeDef;
#define DMA1 ((DMA_TypeDef *) DMA1_BASE)
#define DMA2 ((DMA_TypeDef *) DMA2_BASE)

//Backup SRAM
typedef struct {

} BKPSRAM_TypeDef;
#define BKPSRAM ((BKPSRAM_TypeDef *) BKPSRAM_BASE)

//FLASH
typedef struct {
    volatile uint32_t ACR; // Access Control Register 0x00
    volatile uint32_t KEYR; // Key Register 0x04
    volatile uint32_t OPTKEYR; // Option Key Register 0x08
    volatile uint32_t SR; // Status Register 0x0C
    volatile uint32_t CR; // Control Register 0x10
    volatile uint32_t OPTCR; // Option Control Register 0x14
} FLASH_TypeDef;
#define FLASH ((FLASH_TypeDef *) FLASH_BASE)

//RCC
typedef struct {
    volatile uint32_t CR; // Clock Control Register 0x00
    volatile uint32_t PLLCFGR; // PLL Configuration Register 0x04
    volatile uint32_t CFGR; // Clock Configuration Register 0x08
    volatile uint32_t CIR; // Clock Interrupt Register 0x0C
    volatile uint32_t AHB1RSTR; // AHB1 Peripheral Reset Register 0x10
    volatile uint32_t AHB2RSTR; // AHB2 Peripheral Reset Register 0x14
    volatile uint32_t AHB3RSTR; // AHB3 Peripheral Reset Register 0x18
    volatile const uint32_t RESERVED0; // Reserved 0x1C
    volatile uint32_t APB1RSTR; // APB1 Peripheral Reset Register 0x20
    volatile uint32_t APB2RSTR; // APB2 Peripheral Reset Register 0x24
    volatile const uint32_t RESERVED1; // Reserved 0x28
    volatile const uint32_t RESERVED2; // Reserved 0x2C
    volatile uint32_t AHB1ENR; // AHB1 Peripheral Clock Enable Register 0x30
    volatile uint32_t AHB2ENR; // AHB2 Peripheral Clock Enable Register 0x34
    volatile uint32_t AHB3ENR; // AHB3 Peripheral Clock Enable Register 0x38
    volatile const uint32_t RESERVED3; // Reserved 0x3C
    volatile uint32_t APB1ENR; // APB1 Peripheral Clock Enable Register 0x40
    volatile uint32_t APB2ENR; // APB2 Peripheral Clock Enable Register 0x44
    volatile const uint32_t RESERVED4; // Reserved 0x48
    volatile const uint32_t RESERVED5; // Reserved 0x4C
    volatile uint32_t AHB1LPENR; // AHB1 Peripheral Clock Enable in Low Power Mode Register 0x50
    volatile uint32_t AHB2LPENR; // AHB2 Peripheral Clock Enable in Low Power Mode Register 0x54
    volatile uint32_t AHB3LPENR; // AHB3 Peripheral Clock Enable in Low Power Mode Register 0x58
    volatile const uint32_t RESERVED6; // Reserved 0x5C
    volatile uint32_t APB1LPENR; // APB1 Peripheral Clock Enable in Low Power Mode Register 0x60
    volatile uint32_t APB2LPENR; // APB2 Peripheral Clock Enable in Low Power Mode Register 0x64
    volatile const uint32_t RESERVED7; // Reserved 0x68
    volatile const uint32_t RESERVED8; // Reserved 0x6C
    volatile uint32_t BDCR; // Backup Domain Control Register 0x70
    volatile uint32_t CSR; // Control/Status Register 0x74
    volatile const uint32_t RESERVED9; // Reserved 0x78
    volatile const uint32_t RESERVED10; // Reserved 0x7C
    volatile uint32_t SSCGR; // Spread Spectrum Clock Generation Register 0x80
    volatile uint32_t PLLI2SCFGR; // PLLI2S Configuration Register 0x84
    volatile uint32_t PLLSAICFGR; // PLLSAI Configuration Register 0x88
    volatile uint32_t DCKCFGR; // Dedicated Clocks Configuration Register 0x8C
    volatile uint32_t CKGATENR; // Clocks Gated Enable Register 0x90
    volatile uint32_t DCKCFGR2; // Dedicated Clocks Configuration Register 2 0x94
} RCC_TypeDef;
#define RCC ((RCC_TypeDef *) RCC_BASE)

//CRC
typedef struct {
    volatile uint32_t DR; // Data Register 0x00
    volatile uint32_t IDR; // Independent Data Register 0x04
    volatile uint32_t CR; // Control Register 0x08
} CRC_TypeDef;
#define CRC ((CRC_TypeDef *) CRC_BASE)

//GPIO
typedef struct {
    volatile uint32_t MODER; // Mode Register 0x00
    volatile uint32_t OTYPER; // Output Type Register 0x04
    volatile uint32_t OSPEEDR; // Output Speed Register 0x08
    volatile uint32_t PUPDR; // Pull-Up/Pull-Down Register 0x0C
    volatile uint32_t IDR; // Input Data Register 0x10
    volatile uint32_t ODR; // Output Data Register 0x14
    volatile uint32_t BSRR; // Bit Set/Reset Register 0x18
    volatile uint32_t LCKR; // Configuration Lock Register 0x1C
    volatile uint32_t AFRL; // Alternate Function Register 0x20
    volatile uint32_t AFRH; // Alternate Function Register 0x24
} GPIO_TypeDef;
#define GPIOA ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *) GPIOH_BASE)

//SAI
typedef struct {

} SAI_TypeDef;
#define SAI1 ((SAI_TypeDef *) SAI1_BASE)
#define SAI2 ((SAI_TypeDef *) SAI2_BASE)

//PWR
typedef struct {
    volatile uint32_t CR; // Control Register 0x00
    volatile uint32_t CSR; // Control/Status Register 0x04
} PWR_TypeDef;
#define PWR ((PWR_TypeDef *) PWR_BASE)

//SYSCFG
typedef struct {
    volatile uint32_t MEMRMP; // Memory Remap Register 0x00
    volatile uint32_t PMC; // Peripheral Mode Configuration Register 0x04
    volatile uint32_t EXTICR1; // External Interrupt Configuration Register 0x08
    volatile uint32_t EXTICR2; // External Interrupt Configuration Register 0x0C
    volatile uint32_t EXTICR3; // External Interrupt Configuration Register 0x10
    volatile uint32_t EXTICR4; // External Interrupt Configuration Register 0x14
    volatile uint32_t CMPCR; // Compensation Cell Control Register 0x18
    volatile uint32_t CFGR; // SYSCFG Configuration Register 0x1C
} SYSCFG_TypeDef;
#define SYSCFG ((SYSCFG_TypeDef *) SYSCFG_BASE)

//FMC
//probably going to be a work in progress for a long time
//go to page 320 on data sheet RM0390 provided in the README to understand the FMC registers
typedef struct {
    volatile uint32_t BCR1; // Bank Control Register 1 0x00
    volatile uint32_t BTR1; // Bank Timing Register 1 0x04
    volatile uint32_t BCR2; // Bank Control Register 2 0x08
    volatile uint32_t BTR2; // Bank Timing Register 2 0x0C
    volatile uint32_t BCR3; // Bank Control Register 3 0x10
    volatile uint32_t BTR3; // Bank Timing Register 3 0x14
    volatile uint32_t BCR4; // Bank Control Register 4 0x18
    volatile uint32_t BTR4; // Bank Timing Register 4 0x1C
    volatile const uint32_t RESERVED1[58]; // Reserved 0x20-0x100
    volatile uint32_t BETR1; // Bank Extended Timing Register 1 0x104
} FMC_TypeDef;
#define FMC ((FMC_TypeDef *) FMC_BASE)

//Advanced Timers (TIM1 and TIM8)
typedef struct {
    volatile uint32_t CR1; // Control Register 1 0x00
    volatile uint32_t CR2; // Control Register 2 0x04
    volatile uint32_t SMCR; // Slave Mode Control Register 0x08
    volatile uint32_t DIER; // DMA/Interrupt Enable Register 0x0C
    volatile uint32_t SR; // Status Register 0x10
    volatile uint32_t EGR; // Event Generation Register 0x14
    volatile uint32_t CCMR1; // Capture/Compare Mode Register 1 0x18
    volatile uint32_t CCMR2; // Capture/Compare Mode Register 2 0x1C
    volatile uint32_t CCER; // Capture/Compare Enable Register 0x20
    volatile uint32_t CNT; // Counter 0x24
    volatile uint32_t PSC; // Prescaler 0x28
    volatile uint32_t ARR; // Auto-Reload Register 0x2C
    volatile uint32_t RCR; // Repetition Counter Register 0x30
    volatile uint32_t CCR1; // Capture/Compare Register 1 0x34
    volatile uint32_t CCR2; // Capture/Compare Register 2 0x38
    volatile uint32_t CCR3; // Capture/Compare Register 3 0x3C
    volatile uint32_t CCR4; // Capture/Compare Register 4 0x40
    volatile uint32_t BDTR; // Break and Dead-Time Register 0x44
    volatile uint32_t DCR; // DMA Control Register 0x48
    volatile uint32_t DMAR; // DMA Address for Full Transfer 0x4C
} ATIM_TypeDef;
#define TIM1 ((ATIM_TypeDef *) TIM1_BASE)
#define TIM8 ((ATIM_TypeDef *) TIM8_BASE)

//General Purpose Timers (TIM2 to TIM5)
typedef struct {
    volatile uint32_t CR1; // Control Register 1 0x00
    volatile uint32_t CR2; // Control Register 2 0x04
    volatile uint32_t SMCR; // Slave Mode Control Register 0x08
    volatile uint32_t DIER; // DMA/Interrupt Enable Register 0x0C
    volatile uint32_t SR; // Status Register 0x10
    volatile uint32_t EGR; // Event Generation Register 0x14
    volatile uint32_t CCMR1; // Capture/Compare Mode Register 1 0x18
    volatile uint32_t CCMR2; // Capture/Compare Mode Register 2 0x1C
    volatile uint32_t CCER; // Capture/Compare Enable Register 0x20
    volatile uint32_t CNT; // Counter 0x24
    volatile uint32_t PSC; // Prescaler 0x28
    volatile uint32_t ARR; // Auto-Reload Register 0x2C
    volatile const uint32_t RESERVED1; // Reserved 0x30
    volatile uint32_t CCR1; // Capture/Compare Register 1 0x34
    volatile uint32_t CCR2; // Capture/Compare Register 2 0x38
    volatile uint32_t CCR3; // Capture/Compare Register 3 0x3C
    volatile uint32_t CCR4; // Capture/Compare Register 4 0x40
    volatile const uint32_t RESERVED2; // Reserved 0x44
    volatile uint32_t DCR; // DMA Control Register 0x48
    volatile uint32_t DMAR; // DMA Address for Full Transfer 0x4C
    volatile uint32_t OR; // Option Register 0x50(only for TIM2 and TIM5)
} GPTIMA_TypeDef;
#define TIM2 ((GPTIMA_TypeDef *) TIM2_BASE)
#define TIM3 ((GPTIMA_TypeDef *) TIM3_BASE)
#define TIM4 ((GPTIMA_TypeDef *) TIM4_BASE)
#define TIM5 ((GPTIMA_TypeDef *) TIM5_BASE)
//General Purpose Timers (TIM9 to TIM14)
typedef struct{
    volatile uint32_t CR1; // Control Register 1 0x00
    volatile uint32_t SMCR; // Slave Mode Control Register 0x08
    volatile uint32_t DIER; // DMA/Interrupt Enable Register 0x0C
    volatile uint32_t SR; // Status Register 0x10
    volatile uint32_t EGR; // Event Generation Register 0x14
    volatile uint32_t CCMR1; // Capture/Compare Mode Register 1 0
    volatile const uint32_t RESERVED1; // Reserved 0x1C
    volatile uint32_t CCER; // Capture/Compare Enable Register 0x20
    volatile uint32_t CNT; // Counter 0x24
    volatile uint32_t PSC; // Prescaler 0x28
    volatile uint32_t ARR; // Auto-Reload Register 0x2C
    volatile const uint32_t RESERVED2; // Reserved 0x30
    volatile uint32_t CCR1; // Capture/Compare Register 1 0x34
    volatile uint32_t CCR2; // Capture/Compare Register 2 0x38
    volatile const uint32_t RESERVED3; // Reserved 0x3C
    volatile const uint32_t RESERVED4; // Reserved 0x40
    volatile const uint32_t RESERVED5; // Reserved 0x44
    volatile const uint32_t RESERVED6; // Reserved 0x48
    volatile const uint32_t RESERVED7; // Reserved 0x4C
} GPTIMB_TypeDef;
#define TIM9 ((GPTIMB_TypeDef *) TIM9_BASE)
#define TIM10 ((GPTIMB_TypeDef *) TIM10_BASE)
#define TIM11 ((GPTIMB_TypeDef *) TIM11_BASE)
#define TIM12 ((GPTIMB_TypeDef *) TIM12_BASE)
#define TIM13 ((GPTIMB_TypeDef *) TIM13_BASE)
#define TIM14 ((GPTIMB_TypeDef *) TIM14_BASE)

//Basic Timers (TIM6 and TIM7)
typedef struct {
    volatile uint32_t CR1; // Control Register 1 0x00
    volatile uint32_t CR2; // Control Register 2 0x04
    volatile const uint32_t RESERVED1; // Reserved 0x08
    volatile uint32_t DIER; // DMA/Interrupt Enable Register 0x0C
    volatile uint32_t SR; // Status Register 0x10
    volatile uint32_t EGR; // Event Generation Register 0x14
    volatile const uint32_t RESERVED2; // Reserved 0x18
    volatile const uint32_t RESERVED3; // Reserved 0x1C
    volatile const uint32_t RESERVED4; // Reserved 0x20
    volatile uint32_t CNT; // Counter 0x24
    volatile uint32_t PSC; // Prescaler 0x28
    volatile uint32_t ARR; // Auto-Reload Register 0x2C
} BTIM_TypeDef;
#define TIM6 ((BTIM_TypeDef *) TIM6_BASE)
#define TIM7 ((BTIM_TypeDef *) TIM7_BASE)

//usart
typedef struct {
    volatile uint32_t SR; // Status Register 0x00
    volatile uint32_t DR; // Data Register 0x04
    volatile uint32_t BRR; // Baud Rate Register 0x08
    volatile uint32_t CR1; // Control Register 1 0x0C
    volatile uint32_t CR2; // Control Register 2 0x10
    volatile uint32_t CR3; // Control Register 3 0x14
    volatile uint32_t GTPR; // Guard Time and Prescaler Register 0x18
} USART_TypeDef;
#define USART1 ((USART_TypeDef *) USART1_BASE)
#define USART2 ((USART_TypeDef *) USART2_BASE)
#define USART3 ((USART_TypeDef *) USART3_BASE)
#define UART4 ((USART_TypeDef *) UART4_BASE)
#define UART5 ((USART_TypeDef *) UART5_BASE)
#define USART6 ((USART_TypeDef *) USART6_BASE)

#endif // STM32F446XX_MAP_H