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
#include "DIO_interface.h"

int main(void)
{
	Std_ReturnType loc_StdRetTypeErrorStatus = E_OK;
	
        loc_StdRetTypeErrorStatus = MRCC_Init();
        loc_StdRetTypeErrorStatus = MRCC_StdReturnTypeEnablePeripheralClock(RCC_APB2_BUS,RCC_APB2_IOPAEN);
        loc_StdRetTypeErrorStatus = MDIO_Std_ReturnTypeSetPinDirection(DIO_PIN2,DIO_OUT_10MHZ_GPIO_PUSH_PULL);
	while(1);
	return 0;
}