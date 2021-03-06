/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 01-08-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: RCC_private.h
 * 	BRIEF  	: The reset and clock control private file
 * 	DETAILS :   
 *********************************************************************************************************************/


/*Guard file*/
#ifndef  RCC_PRIVATE_H
#define  RCC_PRIVATE_H


/*********************************************************************************************************************
* GLOBAL MACROS
*********************************************************************************************************************/
#define RCC_HSI_DIV2			0x1
#define RCC_HSE_DIV2			0x2
#define RCC_HSE					0x3


/*PLL multiplication value*/
#define RCC_PLL_MUL_2              0
#define RCC_PLL_MUL_3              1
#define RCC_PLL_MUL_4             10
#define RCC_PLL_MUL_5             11
#define RCC_PLL_MUL_6            100
#define RCC_PLL_MUL_7            101
#define RCC_PLL_MUL_8            110
#define RCC_PLL_MUL_9            111
#define RCC_PLL_MUL_10          1000
#define RCC_PLL_MUL_11          1001
#define RCC_PLL_MUL_12          1010
#define RCC_PLL_MUL_13          1011
#define RCC_PLL_MUL_14          1100
#define RCC_PLL_MUL_15          1101
#define RCC_PLL_MUL_16          1110



/*ADC prescaler*/
#define RCC_ADC_CLK_DIV2		   0
#define RCC_ADC_CLK_DIV4		   1
#define RCC_ADC_CLK_DIV6		  10
#define RCC_ADC_CLK_DIV8		  11


/*APB2 prescaler*/
#define RCC_APB2_CLK_NOT_DIV	   0
#define RCC_APB2_CLK_DIV2        100
#define RCC_APB2_CLK_DIV4        101
#define RCC_APB2_CLK_DIV8        110
#define RCC_APB2_CLK_DIV16	     111

/*APB1 prescaler*/
#define RCC_APB1_CLK_NOT_DIV	   0
#define RCC_APB1_CLK_DIV2        100
#define RCC_APB1_CLK_DIV4        101
#define RCC_APB1_CLK_DIV8        110
#define RCC_APB1_CLK_DIV16	     111

/*AHB prescaler*/
#define RCC_AHB_CLK_NOT_DIV 	   0
#define RCC_AHB_CLK_DIV2    	1000
#define RCC_AHB_CLK_DIV4    	1001
#define RCC_AHB_CLK_DIV8    	1010
#define RCC_AHB_CLK_DIV16   	1011
#define RCC_AHB_CLK_DIV64   	1100
#define RCC_AHB_CLK_DIV128  	1101
#define RCC_AHB_CLK_DIV256  	1110
#define RCC_AHB_CLK_DIV512  	1111


/*********************************************************************************************************************
* BASE ADDRESSES
*********************************************************************************************************************/
#define RCC_BASE_ADDRESS						0x40021000																				/*  RCC base address	   */

/*********************************************************************************************************************
* REGISTER'S OFFSEST 
*********************************************************************************************************************/
#define RCC_CR_OFFSET							0x00																					/*  RCC_CR offset address  */
#define RCC_CFGR_OFFSET							0x04																					/*  RCC_CFGR offset address*/
#define RCC_CIR_OFFSET							0x08																					/*  RCC_CIR offset address */
#define RCC_APB2RSTR_OFFSET						0x0C																					/*  RCC_APB2RSTR offset    */
#define RCC_APB1RSTR_OFFSET						0x10																					/*  RCC_APB1RSTR offset    */
#define RCC_AHBENR_OFFSET						0x14																					/*  RCC_AHBENR offset      */
#define RCC_APB2ENR_OFFSET						0x18																					/*  RCC_APB2ENR offset     */
#define RCC_APB1ENR_OFFSET						0x1C																					/*  RCC_APB1ENR offset     */
#define RCC_BDCR_OFFSET							0x20																					/*  RCC_BDCR offset        */
#define RCC_CSR_OFFSET							0x24																					/*  RCC_CSR offset         */

/*********************************************************************************************************************
* BIT'S OFFSEST 
*********************************************************************************************************************/
#define RCC_SW_BIT_OFFSET						0x0
#define RCC_PLLON_BIT_OFFSET					0x18
#define RCC_CSSON_BIT_OFFSET					0x13
#define RCC_HSION_BIT_OFFSET					0x00
#define RCC_HSIRDY_BIT_OFFSET					0x01
#define RCC_HSEON_BIT_OFFSET					0x0F
#define RCC_HSERDY_BIT_OFFSET					0x11
#define RCC_PLLON_BIT_OFFSET					0x18
#define RCC_PLLRDY_BIT_OFFSET					0x19
#define RCC_SDIOEN_BIT_OFFSET					0xA
#define RCC_FSMCEN_BIT_OFFSET					0x8
#define RCC_CRCEN_BIT_OFFSET					0x6
#define RCC_FLITFEN_BIT_OFFSET					0x4
#define RCC_SRAMEN_BIT_OFFSET					0x2
#define RCC_DMA2EN_BIT_OFFSET					0x1
#define RCC_DMA1EN_BIT_OFFSET					0x0
#define RCC_TIM11EN_BIT_OFFSET					0x15
#define RCC_TIM10EN_BIT_OFFSET					0x14
#define RCC_TIM9EN_BIT_OFFSET					0x13
#define RCC_ADC3EN_BIT_OFFSET					0x0E
#define RCC_USART1EN_BIT_OFFSET					0x0D
#define RCC_TIM8EN_BIT_OFFSET					0x0
#define RCC_PLL_MUL_BIT_OFFSET					0x12



/*********************************************************************************************************************
* REGISTERS ADDRESSES 
*********************************************************************************************************************/
#define RCC_CR									(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_CR_OFFSET			)	)	)				/*  RCC_CR                 */
#define RCC_CFGR								(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_CFGR_OFFSET		) 	)	)				/*  RCC_CFGR               */
#define RCC_CIR									(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_CIR_OFFSET			) 	)	)			    /*  RCC_CIR                */
#define RCC_APB2RSTR							(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_APB2RSTR_OFFSET	) 	)	)				/*  RCC_APB2RSTR           */
#define RCC_APB1RSTR							(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_APB1RSTR_OFFSET	)	)	)				/*  RCC_APB1RSTR           */
#define RCC_AHBENR								(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_AHBENR_OFFSET		)	)	)				/*  RCC_AHBENR             */
#define RCC_APB2ENR								(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_APB2ENR_OFFSET		)	)	)				/*  RCC_APB2ENR            */
#define RCC_APB1ENR								(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_APB1ENR_OFFSET		)	)	)				/*  RCC_APB1ENR            */
#define RCC_BDCR								(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_BDCR_OFFSET		)	)	)				/*  RCC_BDCR               */
#define RCC_CSR									(*	( (volatile u32*)(RCC_BASE_ADDRESS + RCC_CSR_OFFSET			)	)	)				/*  RCC_CSR                */






#endif

