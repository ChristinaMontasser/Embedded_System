/*
 * App.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Abdelrhman Walaa
 */
#include "avr\delay.h"
#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
u8 getSize(u8* ptr);

#define F_CPU 8000000UL
int main (void)
{


		u8 string1 []="Lovely Chris";
		u8 string2 []="Happy birthday";


		DIO_vdSetPortDirection(LCD_U8_DATA_PORT,PORT_OUTPUT);
		DIO_vdSetPortDirection(LCD_U8_CTRL_PORT,PORT_OUTPUT);

		LCD_vdInitialization();
		//LCD_vdSendChar('A');

	  // LCD_vdWriteString(string1);
	   // LCD_vdWriteString(string2);
		//LCD_vdSendChar('r');
		/*for(u8 i=0; i<4; i++)
		{
			LCD_vdSendChar(' ');
			_delay_ms(1);
		}
		LCD_vdWriteString(string1);*/

	 //   LCD_vdSendChar('b');
	   // LCD_vdSendChar('a');
	/*	LCD_vdStringPostion (0,  5, string1 );
		LCD_vdClear();*/
		/*LCD_vdWriteString(string1);
		u8 shift = 15;	// Number of time shifts count=15
		while(1)
		{
			for(u8 i=0;i<shift;i++)
			{
				LCD_vdSendCmd(0x1c);// shift entire display right
				_delay_ms(300);
			}
			shift=30;// number of time shifts 30

			for(u8 i=0;i<30;i++)
			{
				LCD_vdSendCmd(0x18);// shift entire display left
				_delay_ms(300);
			}
		}*/

		/*int iter = (16-getSize(string1))+1;
		for(int i=0; i<iter; i++)
		{
			LCD_vdStringPostion(0, i, string1 );
			_delay_ms(500);
			LCD_vdClear();
			_delay_ms(200);*/
		// Shift

		 /*	int iter = (16-getSize(string1))+1;
		for(int i=1; i<=iter; i+=2)
		{
			LCD_vdStringPostion(0, i-1, string1 );
			_delay_ms(500);
			LCD_vdClear();
			_delay_ms(200);
			if (i>=iter-1)
				continue;
			LCD_vdStringPostion(1, i, string1);
			_delay_ms(500);
			LCD_vdClear();
			_delay_ms(200);
		}  //sinusoidal

		//task  lec
   u8 dots[] ={1, 0, 0, 0, 0, 0};
    LCD_vdSendDataoCGRAM(dots);
    LCD_vdGotoDDRAM(0, 2);
    LCD_vdSendChar(0);*/

		//LCD_vdWriteFloatNum(255.27);
/*		LCD_vdWriteNum(25);
		LCD_vdSendChar('/');
		LCD_vdWriteNum(8);*/
		//LCD_vdGotoDDRAM(0, 1);
		LCD_vdWriteString(string2);
/*
		_delay_ms(1000);
		LCD_vdReturnHome();
		_delay_ms(1000);
		LCD_vdClear();
*/


	return 0;
}

u8 getSize(u8* ptr)
{
	u8 i=0;
	sizeof(i);
	while(*ptr != '\0')
	{
		ptr++;
		i++;
	}
	return i;
}

