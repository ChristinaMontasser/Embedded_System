/*
 * App.c
 *
 *  Created on: Apr 6, 2021
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
	DIO_vdSetPintDirection(PortB, PIN0, PIN_OUTPUT);
	DIO_vdSetPintDirection(PortB, PIN1, PIN_OUTPUT);

	while(1){
		DIO_vdSetPinValue(PortB, PIN0, PIN_High);
		_delay_ms(500);
		DIO_vdSetPinValue(PortB, PIN0, PIN_LOW);
		_delay_ms(500);
		/*DIO_vdSetPinValue(PortB, PIN1, PIN_High);
		_delay_ms(500);
		DIO_vdSetPinValue(PortB, PIN1, PIN_LOW);
		_delay_ms(500);*/
	}

}
