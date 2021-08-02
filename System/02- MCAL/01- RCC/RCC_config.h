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


/*Options: 	
	 1- RCC_PLL_MUL_2
	 2- RCC_PLL_MUL_3
	 3- RCC_PLL_MUL_4
	 4- RCC_PLL_MUL_5
	 5- RCC_PLL_MUL_6
	 6- RCC_PLL_MUL_7
	 7- RCC_PLL_MUL_8
	 8- RCC_PLL_MUL_9
	 9- RCC_PLL_MUL_10
	10- RCC_PLL_MUL_11
	11- RCC_PLL_MUL_12
	12- RCC_PLL_MUL_13
	13- RCC_PLL_MUL_14
	14- RCC_PLL_MUL_15
	15- RCC_PLL_MUL_16
*/
#define RCC_PLL_MUL_VAL		RCC_PLL_MUL_2	


/*Options " RCC_ADC_PRESCALER " : 
	1- RCC_ADC_CLK_DIV2
	2- RCC_ADC_CLK_DIV4
	3- RCC_ADC_CLK_DIV6
	4- RCC_ADC_CLK_DIV8
*/
#define RCC_ADC_PRESCALER		RCC_ADC_CLK_DIV2

/*Options "RCC_APB2_PRESCALER" :
	1- RCC_APB2_CLK_NOT_DIV
	2- RCC_APB2_CLK_DIV2
	3- RCC_APB2_CLK_DIV4
	4- RCC_APB2_CLK_DIV8
	5- RCC_APB2_CLK_DIV16
*/
#define RCC_APB2_PRESCALER		RCC_APB2_CLK_NOT_DIV

/*Options "RCC_APB1_PRESCALER" :
	1- RCC_APB1_CLK_NOT_DIV
	2- RCC_APB1_CLK_DIV2
	3- RCC_APB1_CLK_DIV4
	4- RCC_APB1_CLK_DIV8
	5- RCC_APB1_CLK_DIV16
*/
#define RCC_APB1_PRESCALER		RCC_APB1_CLK_NOT_DIV


/*Options "RCC_AHB_PRESCALER" :
	1- RCC_AHB_CLK_NOT_DIV
	2- RCC_AHB_CLK_DIV2
	3- RCC_AHB_CLK_DIV4
	4- RCC_AHB_CLK_DIV8
	5- RCC_AHB_CLK_DIV16
	6- RCC_AHB_CLK_DIV64
	7- RCC_AHB_CLK_DIV128
	8- RCC_AHB_CLK_DIV256
	9- RCC_AHB_CLK_DIV512
*/
#define RCC_AHB_PRESCALER		RCC_AHB_CLK_NOT_DIV

#endif


