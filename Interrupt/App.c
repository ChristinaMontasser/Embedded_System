/*
 * App.c

 *
 *  Created on: Apr 6, 2021
 *      Author: Compu Store
 */


#include "Macros.h"
#include "EX_Interface.h"
#include "GI_Interface.h"
#include "DIO_Interface.h"



void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void main (void)
{
	DIO_vdSetPinDirection(PortA,PIN0,PIN_OUTPUT);
	//pull up resistor
	DIO_vdSetPinDirection(PortD,PIN2,PIN_INPUT);
	DIO_vdSetPinValue(PortD,PIN2,PIN_High);

	DIO_vdSetPinDirection(PortD,PIN1,PIN_INPUT);
	DIO_vdSetPinValue(PortD,PIN1,PIN_High);

	EX_vdConfigInterrupt(EX_INT0,EX_SENSE_FALLING_EDGE);

	EX_vdConfigInterrupt(EX_INT0,EX_SENSE_RAISING_EDGE);

	GI_vdEnableGI();
	while(1);
}

void __vector_1 (void)
{
	DIO_vdSetPinValue(PortA,PIN0,PIN_High);
}
void __vector_2 (void)
{
	DIO_vdSetPinValue(PortA,PIN0,PIN_LOW);
}

