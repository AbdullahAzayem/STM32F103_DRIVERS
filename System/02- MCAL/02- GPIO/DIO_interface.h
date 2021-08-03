/**********************************************************************************************************************
 *  AUTHOR 	: ABDULLAH AZAYEM
 *  DATE   	: 31-07-2021
 *  MCU 	: STM32
 *  LAYERED : MCAL
 *  VERSION	: V01
 * 	FILE   	: DIO_interface.h
 * 	BRIEF  	: The digital input output interface file
 * 	DETAILS :   
 *********************************************************************************************************************/


/*Guard file*/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/*********************************************************************************************************************
* PIN NUMBER CONFIGURATIONS
**********************************************************************************************************************/
#define DIO_PIN0                0
#define DIO_PIN1                1
#define DIO_PIN2                2
#define DIO_PIN3                3
#define DIO_PIN4                4
#define DIO_PIN5                5
#define DIO_PIN6                6
#define DIO_PIN7                7
#define DIO_PIN8                8
#define DIO_PIN9                9
#define DIO_PIN10               10
#define DIO_PIN11               11
#define DIO_PIN12               12
#define DIO_PIN13               13
#define DIO_PIN14               14
#define DIO_PIN15               15
#define DIO_PIN16               16
#define DIO_PIN17               17
#define DIO_PIN18               18
#define DIO_PIN19               19
#define DIO_PIN20               20
#define DIO_PIN21               21
#define DIO_PIN22               22
#define DIO_PIN23               23
#define DIO_PIN24               24
#define DIO_PIN25               25
#define DIO_PIN26               26
#define DIO_PIN27               27
#define DIO_PIN28               28
#define DIO_PIN29               29
#define DIO_PIN30               30
#define DIO_PIN31               31
#define DIO_PIN32               32
#define DIO_PIN33               33
#define DIO_PIN34               34
#define DIO_PIN35               35
#define DIO_PIN36				        36

/*********************************************************************************************************************
* PORT CONFIGURATIONS
**********************************************************************************************************************/
#define DIO_PORTA 			    0 
#define DIO_PORTB			    1
#define DIO_PORTC			    2

/*********************************************************************************************************************
* PIN DIRECTION CONFIGURATIONS
**********************************************************************************************************************/
#define DIO_IN_ANALOG_MODE                                      0x0
#define DIO_IN_FLOATING_MODE                                    0x4
#define DIO_IN_PULL_UP_DOWN_MODE                                0x8

#define DIO_OUT_10MHZ_GPIO_PUSH_PULL                            0x1
#define DIO_OUT_10MHZ_GPIO_OPEN_DRAIN                           0x5
#define DIO_OUT_10MHZ_AF_PUSH_PULL                              0x9
#define DIO_OUT_10MHZ_AF_OPEN_DRAIN                             0xD
#define DIO_OUT_2MHZ_GPIO_PUSH_PULL                             0x2
#define DIO_OUT_2MHZ_GPIO_OPEN_DRAIN                            0x6
#define DIO_OUT_2MHZ_AF_PUSH_PULL                               0xA
#define DIO_OUT_2MHZ_AF_OPEN_DRAIN                              0xE
#define DIO_OUT_50MHZ_GPIO_PUSH_PULL                            0x3
#define DIO_OUT_50MHZ_GPIO_OPEN_DRAIN                           0x7
#define DIO_OUT_50MHZ_AF_PUSH_PULL                              0xB
#define DIO_OUT_50MHZ_AF_OPEN_DRAIN															0xF
/*********************************************************************************************************************
* PIN VALUE CONFIGURATIONS
**********************************************************************************************************************/
#define DIO_HIGH												1
#define DIO_LOW													0





/*********************************************************************************************************************
* GLOBAL FUNCTIONS PROTOTYPES
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
Std_ReturnType MDIO_Std_ReturnTypeSetPinDirection(u8 Coyp_u8PinNo,u8 Copy_u8PinMode);

/******************************************************************************
Syntax          :   Std_ReturnType MDIO_Std_ReturnTypeSetPinVal(u8 Coyp_u8PinNo,u8 Copy_u8PinVal) 
Description     :   Set pin value
Sync\Async      : 	Async
Reentrancy      : 	
Parameters (in) : 	u8 Coyp_u8PinNo,u8 Copy_u8PinVal
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MDIO_Std_ReturnTypeSetPinVal(u8 Coyp_u8PinNo,u8 Copy_u8PinVal);

/******************************************************************************
Syntax          :   Std_ReturnType MDIO_Std_ReturnTypeGetPinVal(u8 Coyp_u8PinNo,u8* Ptr_u8PinVal) 
Description     :   Get pin value
Sync\Async      : 	Async
Reentrancy      : 	
Parameters (in) : 	u8 Coyp_u8PinNo,u8* Ptr_u8PinVal
Parameters (out):   void
Return value    : 	loc_StdReturnTypeErrorStatus
*******************************************************************************/
Std_ReturnType MDIO_Std_ReturnTypeGetPinVal(u8 Coyp_u8PinNo,u8* Ptr_u8PinVal);


#endif

