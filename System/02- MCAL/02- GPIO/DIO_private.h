/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 02-08-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: DIO_private.h
 * 	BRIEF  	: The digital input output driver
 * 	DETAILS :   
 *********************************************************************************************************************/



/*Guard file*/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/**********************************************************************************************************************
* GLOBAL MACROS CONSTANT
**********************************************************************************************************************/


/**********************************************************************************************************************
* GPIOs PERIPHERALS BASE ADDRESSES
**********************************************************************************************************************/
#define DIO_PORTA_BASE_ADDRESS				0x40010800
#define DIO_PORTB_BASE_ADDRESS				0x40010C00
#define DIO_PORTC_BASE_ADDRESS				0x40011000

/**********************************************************************************************************************
* GPIOs REGISTERS OFFSETS
**********************************************************************************************************************/
#define DIO_CRL_OFFSET						0x00
#define DIO_CRH_OFFSET						0x04
#define DIO_IDR_OFFSET						0x08
#define DIO_ODR_OFFSET						0x0C
#define DIO_BSRR_OFFSET						0x10
#define DIO_BRR_OFFSET						0x14
#define DIO_LCKR_OFFSET						0x18
								

/**********************************************************************************************************************
* GPIOA REGISTERS ADDRESSES
**********************************************************************************************************************/
#define DIO_PORTA_CRL						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_CRL_OFFSET ) ) )
#define DIO_PORTA_CRH						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_CRH_OFFSET ) ) )
#define DIO_PORTA_IDR						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_IDR_OFFSET ) ) )
#define DIO_PORTA_ODR						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_ODR_OFFSET ) ) )
#define DIO_PORTA_BSRR						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_BSRR_OFFSET) ) )
#define DIO_PORTA_BRR						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_BRR_OFFSET ) ) )
#define DIO_PORTA_LCKR						( *( (volatile u32*) (DIO_PORTA_BASE_ADDRESS + DIO_LCKR_OFFSET) ) )

#define DIO_PORTB_CRL						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_CRL_OFFSET ) ) )
#define DIO_PORTB_CRH						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_CRH_OFFSET ) ) )
#define DIO_PORTB_IDR						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_IDR_OFFSET ) ) )
#define DIO_PORTB_ODR						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_ODR_OFFSET ) ) )
#define DIO_PORTB_BSRR						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_BSRR_OFFSET) ) )
#define DIO_PORTB_BRR						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_BRR_OFFSET ) ) )
#define DIO_PORTB_LCKR						( *( (volatile u32*) (DIO_PORTB_BASE_ADDRESS + DIO_LCKR_OFFSET) ) )

#define DIO_PORTC_CRL						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_CRL_OFFSET ) ) )
#define DIO_PORTC_CRH						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_CRH_OFFSET ) ) )
#define DIO_PORTC_IDR						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_IDR_OFFSET ) ) )
#define DIO_PORTC_ODR						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_ODR_OFFSET ) ) )
#define DIO_PORTC_BSRR						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_BSRR_OFFSET) ) )
#define DIO_PORTC_BRR						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_BRR_OFFSET ) ) )
#define DIO_PORTC_LCKR						( *( (volatile u32*) (DIO_PORTC_BASE_ADDRESS + DIO_LCKR_OFFSET) ) )




#endif

