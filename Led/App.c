/*
 * App.c
 *
 *  Created on: Mar 29, 2021
 *      Author: Compu Store
 */

#include "define.h"
#include "type.h"
#include "DIO_interface.h"
#include "DIO_Registers.h"
#include "SegmentBit.h"

int main()
{
	//Application1
	/*u8 arr[10]={zero, one, two, three, four, five, six, seven, eight, nine};
	//Set Port direction
	DIO_vdSetPortDirection(PortA, PORT_OUTPUT);
	DIO_vdSetPortDirection(PortC, PORT_OUTPUT);
	while(1)
	{
	    //Set PORT value
		DIO_vdSetPortValue(PortC , PORT_INPUT);
		for(u8 u=0; u<=9; u++)
		{
			for(u8 i=0; i<=9; i++)
			{
				//Set PORT value units
				DIO_vdSetPortValue(PortA ,arr[i]);
				if(u!=0 && i==0)
				{
					//Set PORT value tens
					DIO_vdSetPortValue(PortC ,arr[u]);
					//Delay
					for (s32 d = 1; d <= 70000; d++){}
				}
				else
				{
					//Delay
					for (s32 d = 1; d <= 70000; d++){}
				}

			}

		}
	}
	*/


	//Application2
	//SetPORT Direction
	DIO_vdSetPortDirection(PortA, PORT_INPUT);
	//Set pin value
	DIO_vdSetPinValue(PortA , PIN0 , PIN_High);
	//Set Pin direction
	DIO_vdSetPintDirection(PortD, PIN1, PIN_OUTPUT);
	while(1)
	{
		//Get pin
		if(DIO_u8GetPinValue(PortA , PIN0)==0)
		{
			//Set Pin Value
			DIO_vdSetPinValue(PortD ,PIN1, PIN_High);
			//delay
			for (s32 d = 1; d <= 70000; d++){}

		}
		else if(DIO_u8GetPinValue(PortA , PIN0)==1)
		{
		  //Set Port value
			DIO_vdSetPortValue(PortD , PORT_LOW);
		}
	}

return 0;
}
