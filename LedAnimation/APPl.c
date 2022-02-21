/*
 * APPl.c
 *
 *  Created on: Mar 31, 2021
 *      Author: Compu Store
 */

#include "avr/io.h"
#include "Macros.h"
#include "Types.h"
#include "DIO_Interface.h"
#include "Pattern.h"

int main (void)
{
	/*u8 SequnceArr[3]= {FirstSeq, SecondSeq, ThirdSeq};
	DIO_vdSetPortDirection(PortA , PORT_INPUT);
	DIO_vdSetPortValue(PortA , 255);
	//DIO_vdSetPinValue(PortA , PIN0 , PIN_High);
	//Set Port D as an output
	DIO_vdSetPortDirection(PortD , PORT_OUTPUT);
	//Set port value
	while(1)
	{
		if(DIO_u8GetPinValue(PortA , PIN0)==0)
		{
			for (u8 x = 1; x<3 ; x++)
			{
				DIO_vdSetPortValue(PortD , SequnceArr[x] );
				for (s32 d = 1; d <= 70000; d++){}
				//DIO_vdSetPinValue(PortD ,PIN1, PIN_High);
				//delay
			}
		}
		else if(DIO_u8GetPinValue(PortA , PIN0)==1)
		{
		  //Set Port value
			DIO_vdSetPortValue(PortD , PORT_LOW);
		}

	}



	// for (s32 d = 1; d <= 70000; d++){}

	//Set Port A as an input
	//DIO_vdSetPortDirection(PortA , PORT_INPUT);*/

	//Test
	//DIO_vdSetPortDirection(PortD, PORT_OUTPUT);
	while(1)
	{
		DDRD = 255;
		PORTD = 0b11110100;
		for (s32 d = 1; d <= 70000; d++){}
	}

	//DIO_vdSetPortValue(PortD ,PORT_HIGH);
	/*DIO_vdSetPinValue(PortD , PIN0 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN1 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN4 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN5 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN7 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN2 , PIN_High);
	DIO_vdSetPinValue(PortD , PIN3,  PIN_High);*/

return 0;
}
