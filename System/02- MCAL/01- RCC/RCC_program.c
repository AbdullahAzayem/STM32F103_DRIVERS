/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 01-08-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: RCC_program.c
 * 	BRIEF  	: The reset and clock control peripheral
 * 	DETAILS :   
 *********************************************************************************************************************/



/*********************************************************************************************************************
* INCLUDES
*********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static const u32 glob_u32BusOffsetArr[RCC_BUS_ID_LENGTH] = 
{
	RCC_AHBENR_OFFSET   ,
	RCC_APB2ENR_OFFSET	,
	RCC_APB1ENR_OFFSET	
}

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
Syntax          :   Std_ReturnType MRCC_StdReturnTypeEnablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId) 
Description     :   Enable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	void
*******************************************************************************/
Std_ReturnType MRCC_StdReturnTypeEnablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId)
{
	/*Error sattus*/
	Std_ReturnType loc_StdReturnTypeErrorStatus = E_OK;
	
	/*Bus id*/
	u8 loc_u8BusOffset = 0;
	
	if( (RCC_PER_ID_LENGTH <= Copy_u8PeripheralId) && (RCC_BUS_ID_LENGTG <= Copy_u8BusId) )
	{
 		// /*Get bus offset*/
		// loc_u8BusOffset = glob_u32BusOffsetArr[Coyp_u8BusId];
		// /*Set the peripheral clock*/
		// GET_HW_REG(RCC_BASE_ADDRESS,local_u8BusOffset) |= ( (u32)1 << Copy_u8PeripheralId );
		
		switch(Coyp_u8BusId)
		{
			case RCC_AHB_BUS:
				SET_BIT(RCC_AHBENR,Copy_u8PeripheralId);
`					break;
			case RCC_APB1_BUS:
				SET_BIT(RCC_APBENR1,Copy_u8PeripheralId);
				break;
			case RCC_APB2_BUS:
				SET_BIT(RCC_APBENR2,Copy_u8PeripheralId);
				break;
			default:
				/*Set error status*/
				loc_StdReturnTypeErrorStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*Set error*/
		loc_StdReturnTypeErrorStatus = E_NOT_OK;
	}
	
	/*Return error status*/
	return loc_StdReturnTypeErrorStatus;
}

/******************************************************************************
Syntax          :   Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId) 
Description     :   Enable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId)
{
	/*Error sattus*/
	Std_ReturnType loc_StdReturnTypeErrorStatus = E_OK;
	
	if( (RCC_PER_ID_LENGTH <= Copy_u8PeripheralId) && (RCC_BUS_ID_LENGTG <= Copy_u8BusId) )
	{
		// /*Get bus offset*/
		// loc_u8BusOffset = glob_u32BusOffsetArr[Coyp_u8BusId];
		// /*Set the peripheral clock*/
		// GET_HW_REG(RCC_BASE_ADDRESS,local_u8BusOffset) &= ~( (u32)1 << Copy_u8PeripheralId );
		

		switch(Coyp_u8BusId)
		{
			case RCC_AHB:
				CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId);
`					break;
			case RCC_APB1:
				CLR_BIT(RCC_APBENR1,Copy_u8PeripheralId);
				break;
			case RCC_APB2:
				CLR_BIT(RCC_APBENR2,Copy_u8PeripheralId);
				break;
			default:
				/*Set error status*/
				loc_StdReturnTypeErrorStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*Set error*/
		loc_StdReturnTypeErrorStatus = E_NOT_OK;
	}
	
	/*Return error status*/
	return loc_StdReturnTypeErrorStatus;
}

/******************************************************************************
Syntax          :   Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Coyp_u8BusId,u8 Copy_u8PeripheralId) 
Description     :   Enable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType RCC_Init(void)
{
	/*Clock source selection*/
	#if   RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSI
		/*Clock selection*/
		RCC_CFGR = 0x00000000;
		/*Enable HSI*/
		RCC_CR = 0x00000081;
		/*Polling on HSI ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSIRDY_BIT_OFFSET));
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSE_CRYSTAL
		/*Clock selection*/
		RCC_CFGR = 0x00000001;
		/*Enable HSE_CYSTAL*/
		RCC_CR = 0x00010000; 
		/*Polling on HSE ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSERDY_BIT_OFFSET));
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSE_RC
		/*Clock selection*/
		RCC_CFGR = 0x00000001;
		/*Enable HSE_RC*/
		RCC_CR = 0x00050000; 
		/*Polling on HSE ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSERDY_BIT_OFFSET));		
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_PLL
		/*Clock selection*/
		RCC_CFGR = 0x00000002;
		/*Enable PLL*/
		RCC_CR = 0x01000000;	
		/*Polling on PLL ready*/
		while(1 == GET_BIT(RCC_CR,RCC_PLLRDY_BIT_OFFSET));		
	#else
		#error "Wrong configuration"
	#endif	
}

