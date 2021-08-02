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
};

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
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MRCC_StdReturnTypeEnablePeripheralClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{
	/*Error sattus*/
	Std_ReturnType loc_StdReturnTypeErrorStatus = E_OK;
	
	/*Bus id*/
	u8 loc_u8BusOffset = 0;
	
	if( (RCC_PER_ID_LENGTH >= Copy_u8PeripheralId) && (RCC_BUS_ID_LENGTH >= Copy_u8BusId) )
	{
		/*		METHOD-01		*/
 		// /*Get bus offset*/
		// loc_u8BusOffset = glob_u32BusOffsetArr[Coyp_u8BusId];
		// /*Set the peripheral clock*/
		// GET_HW_REG(RCC_BASE_ADDRESS,local_u8BusOffset) |= ( (u32)1 << Copy_u8PeripheralId );

		/*		METHOD-02		*/
		// /*Set using bit banding*/
		// SET_BIT_BANDING((RCC_BASE_ADDRESS+local_u8BusOffset), Copy_u8PeripheralId,HIGH);
		
		/*		METHOD-03		*/		
		switch(Copy_u8BusId)
		{
			case RCC_AHB_BUS:
				/*Set using read modify write*/
				SET_BIT(RCC_AHBENR,Copy_u8PeripheralId);
				break;
			case RCC_APB1_BUS:
				/*Set using read modify write*/
				SET_BIT(RCC_APB1ENR,Copy_u8PeripheralId);
				break;
			case RCC_APB2_BUS:
				/*Set using read modify write*/
				SET_BIT(RCC_APB2ENR,Copy_u8PeripheralId);
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
Description     :   Disable the peripheral clock
Sync\Async      : 	Async
Reentrancy      : 	Reentrant and Entrant
Parameters (in) : 	u8 Coyp_u8BusId,u8 Copy_u8PeripheralId
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MRCC_Std_ReturnTypeDisablePeripheralClock(u8 Copy_u8BusId,u8 Copy_u8PeripheralId)
{
	/*Error sattus*/
	Std_ReturnType loc_StdReturnTypeErrorStatus = E_OK;
	
	if( (RCC_PER_ID_LENGTH <= Copy_u8PeripheralId) && (RCC_BUS_ID_LENGTH <= Copy_u8BusId) )
	{
		/*			METHOD-01			*/
		// /*Get bus offset*/
		// loc_u8BusOffset = glob_u32BusOffsetArr[Coyp_u8BusId];
		// /*Set the peripheral clock*/
		// GET_HW_REG(RCC_BASE_ADDRESS,local_u8BusOffset) &= ~( (u32)1 << Copy_u8PeripheralId );

		/*			METHOD-02			*/
		// /*Clear using bit banding*/
		// SET_BIT_BANDING((RCC_BASE_ADDRESS+local_u8BusOffset), Copy_u8PeripheralId, LOW);				

		/*			METHOD-03			*/		
		switch(Copy_u8BusId)
		{
			case RCC_AHB_BUS:
				/*Clear using read modify write*/
				CLR_BIT(RCC_AHBENR,Copy_u8PeripheralId);				
					break;
			case RCC_APB1_BUS:
				/*Clear using read modify write*/
				CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralId);		
				break;
			case RCC_APB2_BUS:
				/*Clear using read modify write*/
				CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralId);
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
Syntax          :   Std_ReturnType RCC_Init(void)
Description     :   RCC_Init
Sync\Async      : 	Async
Reentrancy      : 	Reentrancy
Parameters (in) : 	void
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MRCC_Init(void)
{		
	RCC_CR   = 0x00000000;
	RCC_CFGR = 0x00000000;
	
	/*Clock source selection*/
	#if   RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSI
		/* METHOD-01 Clock selection
		/*Clock selection*/
		RCC_CFGR = 0x00000000;
		/* METHOD-02 Clock selection by bit banding
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 0 , LOW);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 1 , LOW);
		*/
		
		/*METHOD-01 HSI Enable*/
		/*Enable HSI*/
		RCC_CR = 0x00000081;
		
		/* METHOD-02 Enable HSI by bit banding
		RCC_CR = 0x00000000;
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 0 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 4 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 7 , HIGH);
		*/
		
		/*Polling on HSI ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSIRDY_BIT_OFFSET));
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSE_CRYSTAL

		/*METHOD-01 Clock selection*/
		/*Clock selection*/
		RCC_CFGR = 0x00000001;

		/* METHOD-02 Clock selection by bit banding
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 0 , HIGH );
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 1 , LOW  );
		*/

		/*METHOD-01 HSE_CYSTAL Enable*/
		/*Enable HSE_CYSTAL*/
		RCC_CR = 0x00090000; 
		
		/* METHOD-02 Enable HSE Crystal by bit banding
		RCC_CR = 0x00000000;
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 16 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 19 , HIGH);
		*/
		
		/*Polling on HSE ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSERDY_BIT_OFFSET));
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_HSE_RC
		/*METHOD-01 Clock selection*/
		/*Clock selection*/
		RCC_CFGR = 0x00000001;

		/* METHOD-02 Clock selection by bit banding
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 0 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 1 , LOW );
		*/
		
		/* METHOD-02 Enable HSE RC by bit banding
		/*Enable HSE_RC*/
		RCC_CR = 0x000D0000; 

		/* METHOD-02 Enable HSE RC by bit banding
		RCC_CR = 0x00000000;
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 16 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 18 , HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 19 , HIGH);
		*/

		/*Polling on HSE ready*/
		while(1 == GET_BIT(RCC_CR,RCC_HSERDY_BIT_OFFSET));		
	#elif RCC_SYSTEM_CLOCK_SOURCE  == 	RCC_PLL
	
		/*Set the mul of PLL*/ 
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 18 , GET_DIGIT_VAL(RCC_PLL_MUL_VAL,0) );
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 19 , GET_DIGIT_VAL(RCC_PLL_MUL_VAL,1) );
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 20 , GET_DIGIT_VAL(RCC_PLL_MUL_VAL,2) );
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 21 , GET_DIGIT_VAL(RCC_PLL_MUL_VAL,3) );

	
		#if RCC_PLL_CLOCK_SOURCE == RCC_HSI_DIV2
			SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 16 ,LOW);				
		#elif RCC_PLL_CLOCK_SOURCE == RCC_HSE_DIV2
			SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 17 ,HIGH);
		#elif RCC_PLL_CLOCK_SOURCE == RCC_HSE
			SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 16 ,HIGH);
		#else	
			#error ("Wrong Configuration")
		#endif
		
		/* METHOD-01 Clock selection*/
		/*Clock selection*/
		RCC_CFGR = 0x00000002;

		/* METHOD-02 Clock selection by bit banding
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 0, LOW  );
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 1, HIGH );
		*/
		
		/*METHOD-01 Enable PLL*/
		/*Enable PLL*/
		RCC_CR = 0x01000000;

		/* METHOD-02 Enable PLL by bit banding
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 16 ,HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 18 ,HIGH);
		SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CR_OFFSET), 19 ,HIGH);
		*/
		
		/*Polling on PLL ready*/
		while(1 == GET_BIT(RCC_CR,RCC_PLLRDY_BIT_OFFSET));		
	#else
		#error "Wrong configuration"
	#endif	
	
	/*ADC prescaler*/
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 14 , GET_DIGIT_VAL(RCC_ADC_PRESCALER,0) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 15 , GET_DIGIT_VAL(RCC_ADC_PRESCALER,1) );
	
	/*APB2 prescaler*/
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 11 , GET_DIGIT_VAL(RCC_APB2_PRESCALER,0) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 12 , GET_DIGIT_VAL(RCC_APB2_PRESCALER,1) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 13 , GET_DIGIT_VAL(RCC_APB2_PRESCALER,2) );
	
	/*APB1 prescaler*/
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 8  , GET_DIGIT_VAL(RCC_APB2_PRESCALER,0) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 9  , GET_DIGIT_VAL(RCC_APB2_PRESCALER,1) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 10 , GET_DIGIT_VAL(RCC_APB2_PRESCALER,2) );
	
	/*AHB prescaler*/
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 4  , GET_DIGIT_VAL(RCC_AHB_PRESCALER,0) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 5  , GET_DIGIT_VAL(RCC_AHB_PRESCALER,1) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 6  , GET_DIGIT_VAL(RCC_AHB_PRESCALER,2) );
	SET_BIT_BANDING( (RCC_BASE_ADDRESS+RCC_CFGR_OFFSET), 7  , GET_DIGIT_VAL(RCC_AHB_PRESCALER,3) );			
}


