/**
 *
 * @file GSM_program.c
 * @author Avelabs - Group A
 * @brief This file that implements the GSM driver in HAL
 * @version 1.00
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "GSM_prv.h"
#include "GSM_interface.h"

/**
 * @brief This function is used to delay depend on the target
 * @param Copy_u32ticks	Ticks you want to be delayed
 */

void _delay_ms(u32 Copy_u32ticks)
{
	u32 i;
	for( i = 0; i < (Copy_u32ticks * 500) ; i++)
	{
		asm("NOP");
	}
}

/**
 * @brief	This function in used to initialize the GSM Module by sending the AT-COMMANDS needed to start the connection with the server
 */

void GSM_voidInit(void)
{
	MUSART1_voidTransmit("AT\r\n");                               	//Check Command
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+SAPBR=3,1,\"Contype\",\"GPRS\"\r\n");	//Set connection to the GPRS
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+CSTT=\"internet.vodafone.net\"\r\n");	//Connect to the web through vodafone carrier
	_delay_ms(5000);


	MUSART1_voidTransmit("AT+SAPBR=1,1\r\n");                     	//Enable the GPRS
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPINIT\r\n");                      	//Initialize the HTTP protocol
	_delay_ms(3000);


	MUSART1_voidTransmit("AT+HTTPPARA=\"CID\",1\r\n");            	//Setting HTTP parer profile
	_delay_ms(3000);
}

/**
 * @brief 				This Function only used to send the data to the server through the GSM Module
 * @param Copy_pu8Data
 * @param Copy_pu8Lon	The longitude of the point we want to send to the server
 * @param Copy_pu8Lat	The latitude of the point we want to send to the server
 */

void GSM_voidSendToServer(u8 * Copy_pu8Data, u8 * Copy_pu8Lon, u8 * Copy_pu8Lat)
{
	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");			//Connect to our database server
	MUSART1_voidTransmit(Copy_pu8Data);																	//Send the point number
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(Copy_pu8Lon);																	//Send the longitude string
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(Copy_pu8Lat);																	//Send the latitude string
	MUSART1_voidTransmit("\"\r\n");
	while((GSM_voidGetAck()) != 'K');

	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");														//Take action to send it to the server
	_delay_ms(2500);
}

u8 GSM_voidGetAck(void)
{
	u8 Local_u8Val;
	u8 Local_u8Buffer[30];
	u8 Local_u8Index =0;
	while (1)
	{
		Local_u8Val= MUSART1_u8Receive() ;
		Local_u8Buffer[Local_u8Index]= Local_u8Val ;
		if ((Local_u8Buffer[Local_u8Index]== 'K')||(Local_u8Buffer[Local_u8Index]== 'R'))
			return Local_u8Buffer[Local_u8Index];
		else
			Local_u8Index ++;
		if (Local_u8Index >29)
			return 'R';
	}
}

