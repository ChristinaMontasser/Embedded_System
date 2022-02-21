/*
 * Timer_1.c
 *
 *  Created on: May 7, 2021
 *      Author: Compu Store
 */

#include <avr/io.h>
#include "DIO_Interface.h"

void intial()
{
	TCCR1A = 0b10100011;
	TCCR1B = 0b00001001;
	OCR1AH=0b00000001;
	OCR1AL =0b11111111;
	DIO_vdSetPintDirection(PortD, PIN4, PIN_OUTPUT);

}
