/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 31-07-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: RCC_config.h
 * 	BRIEF  	: The reset and clock control configuration file
 * 	DETAILS :   
 *********************************************************************************************************************/

/*Guard file*/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* System clock Options
	1- RCC_HSI
	2- RCC_HSE_CRYSTAL
	3- RCC_HSE_RC
	4- RCC_PLL
*/
#define RCC_SYSTEM_CLOCK_SOURCE		RCC_HSI	
/*PLL clock source
* 	1- RCC_HSI_DIV2
*	2- RCC_HSE_DIV2
*	3- RCC_HSE
*/
/*Condition: PLL is selected as a source clock*/
#if RCC_SYSTEM_CLOCK_SOURCE == RCC_PLL
#define RCC_PLL_CLOCK_SOURCE 		RCC_HSE_DIV2
#endif

#endif


