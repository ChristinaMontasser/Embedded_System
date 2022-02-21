/*
 * APP.c
 *
 *  Created on: Apr 4, 2021
 *      Author: Compu Store
 */


#include "avr\delay.h"
#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "Keypad_Interface.h"

int main (void)
{
	u8 LOC_u8PressedValue = 'F';

	DIO_vdSetPortDirection(LCD_U8_DATA_PORT,PORT_OUTPUT);
	DIO_vdSetPortDirection(LCD_U8_CTRL_PORT,PORT_OUTPUT);

	Keypad_vdInitialization();
	LCD_vdInitialization();

	while(1)
	{
		Keypad_vdGetPressedKey(&LOC_u8PressedValue);
		if(LOC_u8PressedValue != 'F')
		{
			LCD_vdSendChar(LOC_u8PressedValue);
			LOC_u8PressedValue = 'F';
		}
	}
	return 0;

}
