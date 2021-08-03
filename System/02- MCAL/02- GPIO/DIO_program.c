/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 02-08-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: DIO_program.c
 * 	BRIEF  	: The digital input output program file
 * 	DETAILS :   
 *********************************************************************************************************************/


/*********************************************************************************************************************
* INCLUDES
**********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*********************************************************************************************************************
* GLOBAL DATA
**********************************************************************************************************************/
static const u32 glob_u32DioPortBaseAddress[DIO_MAX_PORT_NO] = 
{
	DIO_PORTA_BASE_ADDRESS,
	DIO_PORTB_BASE_ADDRESS,
	DIO_PORTC_BASE_ADDRESS
};

/*********************************************************************************************************************
* GLOBAL FUNCTIONS DIFINITIONS
**********************************************************************************************************************/

/******************************************************************************
Syntax          :   Std_ReturnType MDIO_Std_ReturnTypeSetPinDirection(u8 Coyp_u8PinNo,u8 Copy_u8PinMode) 
Description     :   Set pin direction
Sync\Async      : 	Async
Reentrancy      : 	
Parameters (in) : 	u8 Coyp_u8PinNo,u8 Copy_u8PinMode
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MDIO_Std_ReturnTypeSetPinDirection(u8 Coyp_u8PinNo,u8 Copy_u8PinMode)
{
	/*Error status*/
	Std_ReturnType loc_u8ErrorStatus = E_OK;
	
	/*Port number*/
	u8 loc_u8PortNo = 0;
	
	/*Pin number*/
	u8 loc_u8PinNo = 0;
	
	/*Pin access*/
	u8 loc_u8PinConfigOffset = 0;
	
	/*Base address*/
	u32 loc_u32BaseAddress = 0;
	
	/*Mode offset*/
	u8 loc_u8PinModeOffset = 0;
	
	/*Check error*/
	if(DIO_MAX_CHANNEL_NO >= Coyp_u8PinNo)
	{
		/*Calculate pin number*/
		loc_u8PinNo = Coyp_u8PinNo % 0xF;
		/*Calculate port number*/
		loc_u8PortNo = Coyp_u8PinNo / 0xF;
		/*Calculate pin configuration offset*/
		loc_u8PinConfigOffset = (loc_u8PinNo/8)*4;
		/*Calculate pin number*/
		loc_u8PinModeOffset = (Coyp_u8PinNo % 0x8)*4;		
		/*Calculate base address*/
		loc_u32BaseAddress = glob_u32DioPortBaseAddress[loc_u8PortNo];
		
		
		// /* METHOD-01  Set mode configuration */
		// GET_HW_REG(loc_u32BaseAddress,loc_u8PinConfigOffset) |= (u32)0xF			   << loc_u8PinModeOffset;
		// GET_HW_REG(loc_u32BaseAddress,loc_u8PinConfigOffset) |= (u32)Copy_u8PinMode << loc_u8PinModeOffset;

		// /* METHOD-02  Set mode configuration using bit banding*/
		// SET_BIT_BANDING( (loc_u32BaseAddress+loc_u8PinConfigOffset) , (loc_u8PinModeOffset+0) ,( Copy_u8PinMode   %2) );
		// SET_BIT_BANDING( (loc_u32BaseAddress+loc_u8PinConfigOffset) , (loc_u8PinModeOffset+1) ,((Copy_u8PinMode/2)%2) );
		// SET_BIT_BANDING( (loc_u32BaseAddress+loc_u8PinConfigOffset) , (loc_u8PinModeOffset+2) ,((Copy_u8PinMode/4)%2) );
		// SET_BIT_BANDING( (loc_u32BaseAddress+loc_u8PinConfigOffset) , (loc_u8PinModeOffset+3) ,((Copy_u8PinMode/8)%2) );

		/* METHOD-03  Set mode configuration normally*/
		switch(loc_u8PortNo)
		{
			case DIO_PORTA:
				if(loc_u8PinNo <= 7)
				{
					DIO_PORTA_CRL &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTA_CRL |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );
					
				}
				else if(loc_u8PinNo <= 15)
				{
					loc_u8PinNo %= 8; 
					DIO_PORTA_CRH &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTA_CRH |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );					
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTB:
				if(loc_u8PinNo <= 7)
				{
					DIO_PORTB_CRL &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTB_CRL |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );
					
				}
				else if(loc_u8PinNo <= 15)
				{
					loc_u8PinNo %= 8; 
					DIO_PORTB_CRH &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTB_CRH |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );					
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTC:
				if(loc_u8PinNo <= 7)
				{
					DIO_PORTC_CRL &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTC_CRL |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );
					
				}
				else if(loc_u8PinNo <= 15)
				{
					loc_u8PinNo %= 8; 
					DIO_PORTC_CRH &= ~((u32)0xF            << (loc_u8PinNo*4) );
					DIO_PORTC_CRH |=  ((u32)Copy_u8PinMode << (loc_u8PinNo*4) );					
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			default:
					loc_u8ErrorStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*Set error status*/
		loc_u8ErrorStatus = E_NOT_OK;
	}
	
	/*Return error status*/
	return loc_u8ErrorStatus;
}





/******************************************************************************
Syntax          :   Std_ReturnType MDIO_Std_ReturnTypeSetPinVal(u8 Coyp_u8PinNo,u8 Copy_u8PinVal) 
Description     :   Set pin value
Sync\Async      : 	Async
Reentrancy      : 	
Parameters (in) : 	u8 Coyp_u8PinNo,u8 Copy_u8PinVal
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MDIO_Std_ReturnTypeSetPinVal(u8 Coyp_u8PinNo,u8 Copy_u8PinVal)
{
	/*Error status*/
	Std_ReturnType loc_u8ErrorStatus = E_OK;
	
	/*Port number*/
	u8 loc_u8PortNo = 0;
	
	/*Pin number*/
	u8 loc_u8PinNo = 0;
	
	/*Base address*/
	u32 loc_u32BaseAddress = 0;
	
	
	/*Check error*/
	if(DIO_MAX_CHANNEL_NO >= Coyp_u8PinNo)
	{
		/*Calculate pin number*/
		loc_u8PinNo = Coyp_u8PinNo % 0xF;
		/*Calculate port number*/
		loc_u8PortNo = Coyp_u8PinNo / 0xF;

		/*Calculate base address*/
		loc_u32BaseAddress = glob_u32DioPortBaseAddress[loc_u8PortNo];
		
		
		// /* METHOD-01  Set mode configuration */
		// GET_HW_REG(loc_u32BaseAddress,DIO_ODR_OFFSET) &= (u32)Copy_u8PinVal << loc_u8PinNo;

		// /* METHOD-02  Set mode configuration using bit banding*/
		// SET_BIT_BANDING( (loc_u32BaseAddress+DIO_ODR_OFFSET) , loc_u8PinNo , Copy_u8PinVal);

		/* METHOD-03  Set mode configuration normally*/
		switch(loc_u8PortNo)
		{
			case DIO_PORTA:
				if(loc_u8PinVal == DIO_HIGH)
				{
					SET_BIT(DIO_PORTA_ODR,loc_u8PinNo);
				}
				else if(loc_u8PinVal == DIO_LOW)
				{
					CLR_BIT(DIO_PORTA_ODR,loc_u8PinNo);
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTB:
				if(loc_u8PinVal == DIO_HIGH)
				{
					SET_BIT(DIO_PORTB_ODR,loc_u8PinNo);
				}
				else if(loc_u8PinVal == DIO_LOW)
				{
					SET_BIT(DIO_PORTB_ODR,loc_u8PinNo);					
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			case DIO_PORTC:
				if(loc_u8PinVal == DIO_HIGH)
				{
					SET_BIT(DIO_PORTC_ODR,loc_u8PinNo);					
				}
				else if(loc_u8PinVal == DIO_LOW)
				{
					SET_BIT(DIO_PORTC_ODR,loc_u8PinNo);
				}
				else
				{
					loc_u8ErrorStatus = E_NOT_OK;
				}
				break;
			default:
					loc_u8ErrorStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*Set error status*/
		loc_u8ErrorStatus = E_NOT_OK;
	}
	
	/*Return error status*/
	return loc_u8ErrorStatus;	
}



/******************************************************************************
Syntax          :   Std_ReturnType MDIO_Std_ReturnTypeGetPinVal(u8 Coyp_u8PinNo,u8* Ptr_u8PinVal) 
Description     :   Get pin value
Sync\Async      : 	Async
Reentrancy      : 	
Parameters (in) : 	u8 Coyp_u8PinNo,u8* Ptr_u8PinVal
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MDIO_Std_ReturnTypeGetPinVal(u8 Coyp_u8PinNo,u8* Ptr_u8PinVal)
{
	/*Error status*/
	Std_ReturnType loc_u8ErrorStatus = E_OK;
	
	/*Port number*/
	u8 loc_u8PortNo = 0;
	
	/*Pin number*/
	u8 loc_u8PinNo = 0;
	
	/*Base address*/
	u32 loc_u32BaseAddress = 0;
	
	
	/*Check error*/
	if( (DIO_MAX_CHANNEL_NO >= Coyp_u8PinNo) && (Ptr_u8PinVal != NULLPOINTER) )
	{
		/*Calculate pin number*/
		loc_u8PinNo = Coyp_u8PinNo % 0xF;
		/*Calculate port number*/
		loc_u8PortNo = Coyp_u8PinNo / 0xF;

		/*Calculate base address*/
		loc_u32BaseAddress = glob_u32DioPortBaseAddress[loc_u8PortNo];
		
		
		// /* METHOD-01  Set mode configuration */
		//(*Ptr_u8PinVal) = (u32)GET_HW_REG(loc_u32BaseAddress,DIO_IDR_OFFSET) >> loc_u8PinNo;

		// /* METHOD-02  Set mode configuration using bit banding*/
		//(*Ptr_u8PinVal) =  GET_BIT_BANDING( (loc_u32BaseAddress+DIO_IDR_OFFSET) , loc_u8PinNo);

		/* METHOD-03  Set mode configuration normally*/
		switch(loc_u8PortNo)
		{
			case DIO_PORTA:
				(*Ptr_u8PinVal) = GET_BIT(DIO_PORTA_IDR,loc_u8PinNo);
				break;
			case DIO_PORTB:
				(*Ptr_u8PinVal) = GET_BIT(DIO_PORTB_IDR,loc_u8PinNo);
				break;
			case DIO_PORTC:
				(*Ptr_u8PinVal) = GET_BIT(DIO_PORTC_IDR,loc_u8PinNo);			
				break;
			default:
					loc_u8ErrorStatus = E_NOT_OK;
				break;
		}
	}
	else
	{
		/*Set error status*/
		loc_u8ErrorStatus = E_NOT_OK;
	}
	
	/*Return error status*/
	return loc_u8ErrorStatus;	
}
