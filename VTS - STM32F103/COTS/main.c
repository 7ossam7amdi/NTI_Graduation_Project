

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "RCC_interface.h"
#include "DIO_interface.h"
#include "USART_interface.h"
#include "VTS_interface.h"
/*
void  _delay_ms(u32 ticks)
{
	u32 i;
	for( i = 0; i < (ticks * 500) ; i++)
	{
		asm("NOP");
	}
}
*/
int main(void)
{


	VTS_voidInit();

	u8 x;
	u8 data[]= "0";
	u8 lon[] = "30.0185944";
	u8 lat []= "31.7049176";

	u8 data2[]= "1";
	u8 lon2[] = "30.0186042";
	u8 lat2[]= "31.7050869";

	u8 data3[]= "2";
	u8 lon3[] = "30.0185894";
	u8 lat3[]= "31.7052421";

	u8 data4[]= "3";
	u8 lon4[] = "30.0185723";
	u8 lat4[]= "31.7054466";

	u8 data5[]= "4";
	u8 lon5[] = "30.0185653";
	u8 lat5[]= "31.7056726";

	u8 data6[]= "5";
	u8 lon6[] = "30.0185717";
	u8 lat6[]= "31.7059743";

	u8 data7[] = "6";
	u8 lon7[] = "30.0185627";
	u8 lat7[] = "31.7060582";

	u8 data8[] = "7";
	u8 lon8[] = "30.0185354";
	u8 lat8[] = "31.7061906";


	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);

	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data2);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon2);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat2);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data3);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon3);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat3);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data4);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon4);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat4);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data5);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon5);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat5);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);




	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data6);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon6);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat6);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data7);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon7);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat7);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);


	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);

	MUSART1_voidTransmit("AT+HTTPPARA=\"URL\",\"gpsnti-5dd6724ca02a.herokuapp.com/save?data=");
	MUSART1_voidTransmit(data8);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lon8);
	MUSART1_voidTransmit(",");
	MUSART1_voidTransmit(lat8);
	MUSART1_voidTransmit("\"\r\n");
	_delay_ms(1000);

	MUSART1_voidTransmit("AT+HTTPACTION=0\r\n");
	_delay_ms(2500);




	while(1)
	{


	}

	return 0;
}
