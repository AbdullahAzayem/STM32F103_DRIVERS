/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 31-07-2021
 *  MCU 	: STM32
 *  LAYERED : LIB
 *  VERSION	: V01
 * 	FILE   	: STD_TYPES.h
 * 	BRIEF  	: The standard types of all system
 * 	DETAILS :   
 *********************************************************************************************************************/


/*Guard file*/
#ifndef STD_TYPES_H
#define STD_TYPES_H


/*********************************************************************************************************************
* Standard types
*********************************************************************************************************************/
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long  int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long  int s32;
typedef unsigned long long int u64 ;
typedef signed long long int s64 ;
typedef float  f32;
typedef double f64;


/*********************************************************************************************************************
* Standard return types
*********************************************************************************************************************/
typedef u8 Std_ReturnType;
typedef ((void*) 0) NullPointer;

/*********************************************************************************************************************
* Error status
*********************************************************************************************************************/
#define E_OK 					0x0
#define E_NOT_OK 				0x1
#define E_NULL_POINTER			0x2


#endif