/*
 * App.c
 *
 *  Created on: Apr 30, 2021
 *      Author: Compu Store
 */


#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "util\delay.h"

void main(void)
{
	DIO_vdSetPintDirection(PortA, PIN0,PIN_OUTPUT);
	while(1)
	{
		DIO_vdSetPinValue(PortA, PIN0,PIN_High);
		_delay_ms(1);
		DIO_vdSetPinValue(PortA, PIN0,PIN_LOW);
		_delay_ms(19);

	}

}
