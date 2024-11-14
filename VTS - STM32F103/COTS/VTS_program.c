/**
 *
 * @file VTS_program.c
 * @author Avelabs - Group A
 * @brief This is the file that implements the Application
 * @version 1.00
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "GSM_interface.h"

/**
 * @brief This Function implemented to initialize the whole system (RCC,GPIO,UART&GSM)
 */
void VTS_voidInit(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2, 14);		/* Enable USART1 Clock */

	/* Setting A9:TX pin as Output alternate function push pull w max speed 50 MHz */
	MGPIO_VidSetPinDirection(GPIOA,PIN9,OUTPUT_SPEED_50MHZ_AFPP);

	/* Setting A10:RX pin as input floating */
	MGPIO_VidSetPinDirection(GPIOA,PIN10,INPUT_FLOATING);

	MUSART1_voidInit();

	GSM_voidInit();
}
