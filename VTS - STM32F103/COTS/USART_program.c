/**
 *
 * @file USART_program.c
 * @author Avelabs - Group A
 * @brief This is the file that implements the USART driver in MCAL
 * @version 1.00
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

static u8 UART_TimeoutRecieveFlag=0;

/**
 * @brief This function is used to initialize the UART with Baud rate 9600 and enable the transmitter & receiver
 */
void MUSART1_voidInit(void)
{
	/*	baud rate = 9600		*/
	USART1 -> BRR = UART_BAUDRATE_9600;

	SET_BIT((USART1-> CR[0]), TE);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), RE);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), UE);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
}

/**
 * @brief 				This function is used to transmit a string through UART
 * @param Copy_pu8arr	Pointer to the string we want to send
 */
void MUSART1_voidTransmit(u8 * Copy_pu8arr)
{
	u8 i = 0;
	//Loop until we reach the termination (null) char
	while(Copy_pu8arr[i] != '\0'){
		USART1 -> DR = Copy_pu8arr[i];
		while((GET_BIT((USART1 -> SR), TC)) == 0);
		i++;
	}
	
}

/**
 * @brief			This function is used to transmit a character through UART
 * @return			Return the received character from the UART data register
 */
u8 MUSART1_u8Receive(void)
{
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((USART1 -> SR), RXNE)) == 0);	//Check for the received flag
	Loc_u8ReceivedData = USART1 -> DR;				//Get data from data register and store it in the local variable
	return Loc_u8ReceivedData;
}






















