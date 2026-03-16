/*
This is to clean up and organize my setup/prototyping of the ISR's
*/
//I will try to keep this in order of where these are in the ISR vector

//The idea here is that I can make these prototype into real functions 
//in the later projects, do note that these will (from what I understand)
//take up space in the bin but it should be a few bytes at most, if need be 
//delete unused ISR's

 //note: the index of an interupt vector is the address/4
#pragma ONCE

//start of stack
//reset handler
//NMI
void NMI_ISR(void);
//hard fault handler
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DEBUG_ISR(void);
void PENDSV_ISR(void);
void EXTI0_ISR(void); //22
void EXTI1_ISR(void); //23
void EXTI2_ISR(void); //24
void EXTI3_ISR(void); //25
void EXTI4_ISR(void); //26
void EXTI9_5_ISR(void); //39
void TIM2_ISR(void); //44
void EXTI15_10_ISR(void); //56
