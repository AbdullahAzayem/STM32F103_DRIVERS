/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 01-08-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: RCC_interface.h
 * 	BRIEF  	: The reset and clock control interface file
 * 	DETAILS :   
 *********************************************************************************************************************/



/*Guard file*/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/*clocks configuration*/
#define RCC_HSI			0x0
#define RCC_HSE			0x1
#define RCC_PLL			0x2

/*Bus id definitions*/
#define RCC_AHB_BUS	        0
#define RCC_APB2_BUS		1
#define RCC_APB1_BUS		2

/*Peripheral Id bit offset of AHB bus*/
#define RCC_AHB_DMA1EN			0x0
#define RCC_AHB_DMA2EN			0x1
#define RCC_AHB_SRAMEN			0x2
#define RCC_AHB_FLITFEN			0x4
#define RCC_AHB_CRCEN			0x6
#define RCC_AHB_FSMCEN			0x8
#define RCC_AHB_SDIOEN			0xA

/*Peripheral id offset of APB2 bus*/
#define RCC_APB2_AFIOEN			0x00
#define RCC_APB2_IOPAEN			0x02
#define RCC_APB2_IOPBEN			0x03
#define RCC_APB2_IOPCEN			0x04
#define RCC_APB2_IOPDEN			0x05
#define RCC_APB2_IOPEEN			0x06
#define RCC_APB2_IOPFEN			0x07
#define RCC_APB2_IOPGEN			0x08
#define RCC_APB2_ADC1EN			0x09
#define RCC_APB2_ADC2EN			0x0A
#define RCC_APB2_TIM1EN			0x0B
#define RCC_APB2_SPI1EN			0x0C
#define RCC_APB2_TIM8EN			0x0D
#define RCC_APB2_USART1EN		0x0E
#define RCC_APB2_ADC3EN			0x0F
#define RCC_APB2_TIM9EN			0x14
#define RCC_APB2_TIM10EN		0x15
#define RCC_APB2_TIM11EN		0x16

/*Peripheral id offset of APB1 bus*/
#define RCC_APB2_TIM2EN			0x00
#define RCC_APB2_TIM3EN			0x01
#define RCC_APB2_TIM4EN			0x02
#define RCC_APB2_TIM5EN			0x03
#define RCC_APB2_TIM6EN			0x04
#define RCC_APB2_TIM7EN			0x05
#define RCC_APB2_TIM12EN		0x06
#define RCC_APB2_TIM13EN		0x07
#define RCC_APB2_TIM14EN		0x08
#define RCC_APB2_WWDGEN			0x0B
#define RCC_APB2_SPI2EN			0x0E
#define RCC_APB2_SPI3EN			0x0F
#define RCC_APB2_USART2EN		0x11
#define RCC_APB2_USART3EN		0x12
#define RCC_APB2_UART4EN		0x13
#define RCC_APB2_UART5EN		0x14
#define RCC_APB2_I2C1EN			0x15
#define RCC_APB2_I2C2EN			0x16
#define RCC_APB2_USBEN			0x17
#define RCC_APB2_CANEN			0x19
#define RCC_APB2_BKPEN			0x1B
#define RCC_APB2_PWREN			0x1C
#define RCC_APB2_DACEN			0x1D






/*Bus limit*/
#define RCC_BUS_ID_LENGTH	3
#define RCC_PER_ID_LENGTH	31


/******************************************************************************
Syntax          :   Std_ReturnType MRCC_StdReturnTypeEnablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId) 
Description     :   Enable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	void
*******************************************************************************/
Std_ReturnType MRCC_StdReturnTypeEnablePeripheralClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);

/******************************************************************************
Syntax          :   Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId) 
Description     :   Enable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId);


/******************************************************************************
Syntax          :   Std_ReturnType RCC_Init(void); 
Description     :   RCC_Init
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	void
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType RCC_Init(void);

#endif



