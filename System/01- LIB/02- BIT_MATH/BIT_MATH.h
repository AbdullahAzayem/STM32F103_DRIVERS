/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 31-07-2021
 *  MCU 	: STM32
 *  LAYERED : LIB
 *  VERSION	: V01
 * 	FILE   	: BIT_MATH.h
 * 	BRIEF  	: The standard bit math all system
 * 	DETAILS :   
 *********************************************************************************************************************/



/*Guard file*/
#ifndef BIT_MATH_H
#define BIT_MATH_H


/*********************************************************************************************************************
* Function macros
*********************************************************************************************************************/
#define SET_BIT(VAR , BITNUM) 			  	  VAR |= (  ( 1 << (BITNUM) ) )
#define CLR_BIT(VAR , BITNUM) 			  	  VAR &= ( ~( 1 << (BITNUM) ) )
#define TOG_BIT(VAR , BITNUM) 			  	  VAR ^= (    1 << (BITNUM)   )
#define GET_BIT(VAR , BITNUM) 			  	  ( ( VAR >> (BITNUM) ) & 1   )
#define GET_HW_REG(BASE_ADDRESS , OFFSET)	  (*((volatile u32*)(BASE_ADDRESS+OFFSET)))




#endif