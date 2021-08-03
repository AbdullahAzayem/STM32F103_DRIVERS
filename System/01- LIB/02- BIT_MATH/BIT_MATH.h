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
* GLOBAL MACTRO CONSTANT
*********************************************************************************************************************/
#define BASE_PER_ALIAS_ADDRESS				  0x42000000
#define BASE_PER_ADDRESS					  0x40000000

/*********************************************************************************************************************
* GLOBAL MACTRO FUNCTION
*********************************************************************************************************************/

#define SET_BIT(VAR , BITNUM) 			  	  VAR |= (  ( 1 << (BITNUM) ) )
#define CLR_BIT(VAR , BITNUM) 			  	  VAR &= ( ~( 1 << (BITNUM) ) )
#define TOG_BIT(VAR , BITNUM) 			  	  VAR ^= (    1 << (BITNUM)   )
#define GET_BIT(VAR , BITNUM) 			  	  ( ( VAR >> (BITNUM) ) & 1   )
#define GET_HW_REG(BASE_ADDRESS , OFFSET)	  (*((volatile u32*)(BASE_ADDRESS+(u32)OFFSET)))
#define SET_BIT_BANDING(REG,BITNUM,VAL)		  (* ( (volatile u32*)( BASE_PER_ALIAS_ADDRESS + ((REG-BASE_PER_ADDRESS)*0x000000020) +(BITNUM*0x00000004)	) )) = VAL
#define GET_BIT_BANDING(REG,BITNUM)		      (* ( (volatile u32*)( BASE_PER_ALIAS_ADDRESS + ((REG-BASE_PER_ADDRESS)*0x000000020) +(BITNUM*0x00000004)	) ))

#endif