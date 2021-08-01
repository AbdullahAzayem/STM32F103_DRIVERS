/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 31-07-2021
 *  MCU 	: STM32
 *  LAYERED : APP
 *  VERSION	: V01
 * 	FILE   	: main.c
 * 	BRIEF  	: The main of all system
 * 	DETAILS :   
 *********************************************************************************************************************/
/*********************************************************************************************************************
* INCLUDES
**********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_config.h"

void main(void)
{
	Std_ReturnType loc_StdRetTypeErrorStatus = E_OK;
	
        loc_StdRetTypeErrorStatus = RCC_Init();
        loc_StdRetTypeErrorStatus = MRCC_StdReturnTypeEnablePeripheralClock(RCC_APB2_BUS,RCC_APB2_TIM1EN);
        
	while(1);
}