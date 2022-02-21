/*
 * main.c
 *
 *  Created on: May 1, 2021
 *      Author: Compu Store
 */


#include "Types.h"
#include "Macros.h"
#include <avr/io.h>
#include "DIO_Interface.h"

void main(void)
{
	DIO_vdSetPintDirection(PortD, PIN4, PIN_OUTPUT);
	while(1)
	{
		//2.5--15%
		TCCR1A = 0x23;
		TCCR1B = 0x1B;
		OCR1BH=0;
		OCR1BL=249;
		OCR1AH=9;
		OCR1AL = 196;
	}
}
