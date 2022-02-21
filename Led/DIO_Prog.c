/*
 * DIO_Prog.c

 *
 *  Created on: Mar 29, 2021
 *      Author: Compu Store
 */

#include "define.h"
#include "type.h"
#include "DIO_interface.h"
#include "DIO_Registers.h"
//Filename_typeFunctionality

//Set Port direction
void DIO_vdSetPortDirection(u8 PortID, u8 PortDirection)
{
	if(PortID >= 0 && PortID <= 3)
	{
		switch (PortID)
		{
			case PortA:
				DDRA_REGISTER= PortDirection;
				break;
			case PortB:
				DDRB_REGISTER= PortDirection;
				break;
			case PortC:
				DDRC_REGISTER= PortDirection;
				break;
			case PortD:
				DDRD_REGISTER= PortDirection;
				break;
		}
	}
	else
	{}
}

//Set PORT value
void DIO_vdSetPortValue(u8 PortID , u8 PortValue )
{
	if(PortID >= 0 && PortID <= 3)
	{
		if(PortValue == PORT_LOW)
		{
			switch(PortID)
			{
				case PortA:
					CLR_BYTE(PORTA_REGISTER);
					break;
				case PortB:
					CLR_BYTE(PORTB_REGISTER);
					break;
				case PortC:
					CLR_BYTE(PORTC_REGISTER);
					break;
				case PortD:
					CLR_BYTE(PORTD_REGISTER);
					break;
			}
		}
		else
		{
			switch(PortID)
			{
				case PortA:
					SET_BYTE(PORTA_REGISTER ,  PortValue);
					break;
				case PortB:
					SET_BYTE(PORTB_REGISTER , PortValue);
					break;
				case PortC:
					SET_BYTE(PORTC_REGISTER , PortValue);
					break;
				case PortD:
					SET_BYTE(PORTD_REGISTER , PortValue);
					break;
			}
		}
	}
	else
	{}
}

//Set pin direction
void DIO_vdSetPintDirection(u8 PortID, u8 PinID, u8 PinDirection)
{
	if((PortID >= 0 && PortID <= 3) && (PinID >= 0 && PinID <= 7))
	{
		if(PinDirection == PIN_OUTPUT)
		{
			switch(PortID)
			{
				case PortA:
					SET_BIT(DDRA_REGISTER , PinID);
					break;
				case PortB:
					SET_BIT(DDRB_REGISTER , PinID);
					break;
				case PortC:
					SET_BIT(DDRC_REGISTER , PinID);
					break;
				case PortD:
					SET_BIT(DDRD_REGISTER , PinID);
					break;
			}
		}
		else if(PinDirection == PIN_INPUT)
		{
			switch(PortID)
			{
				case PortA:
					CLR_BIT(DDRA_REGISTER , PinID);
					break;
				case PortB:
					CLR_BIT(DDRB_REGISTER , PinID);
					break;
				case PortC:
					CLR_BIT(DDRC_REGISTER , PinID);
					break;
				case PortD:
					CLR_BIT(DDRD_REGISTER , PinID);
					break;
			}
		}

	}
	else {}
}


//Set Pin value
void DIO_vdSetPinValue(u8 PortID , u8 PinID ,u8 PinValue )
{
	if((PortID >= 0 && PortID <= 3) && (PinID >= 0 && PinID <= 7))
	{
		if(PinValue==PIN_High)
		{
			switch(PortID)
			{
				case PortA:
					SET_BIT(PORTA_REGISTER , PinID);
					break;
				case PortB:
					SET_BIT(PORTB_REGISTER , PinID);
					break;
				case PortC:
					SET_BIT(PORTC_REGISTER , PinID);
					break;
				case PortD:
					SET_BIT(PORTD_REGISTER , PinID);
					break;
			}
		}
		else if(PinValue==PIN_LOW)
		{
			switch(PortID)
			{
				case PortA:
					CLR_BIT(PORTA_REGISTER , PinID);
					break;
				case PortB:
					CLR_BIT(PORTB_REGISTER , PinID);
					break;
				case PortC:
					CLR_BIT(PORTC_REGISTER , PinID);
					break;
				case PortD:
					CLR_BIT(PORTD_REGISTER , PinID);
					break;
			}
		}
		else
		{}
	}
	else {}
}

//Get PIN value
u8 DIO_u8GetPinValue(u8 PortID, u8 PinID)
{
	if((PortID >= 0 && PortID <= 3) && (PinID >= 0 && PinID <= 7))
	{
		switch(PortID)
		{
			case PortA:
				return GET_BIT(PINA_REGISTER , PinID);
			case PortB:
				return GET_BIT(PINB_REGISTER , PinID);
			case PortC:
				return GET_BIT(PINC_REGISTER , PinID);
			case PortD:
				return GET_BIT(PIND_REGISTER , PinID);
		}
	}
	else
	{}
	//return 0;
}

//Toggle port value
void DIO_vdTogPortValue(u8 PortID)
{
	if(PortID >= 0 && PortID <= 3)
	{
		switch(PortID)
		{
			case PortA:
				TOG_BYTE(PORTA_REGISTER);
				break;
			case PortB:
				TOG_BYTE(PORTB_REGISTER);
				break;
			case PortC:
				TOG_BYTE(PORTC_REGISTER);
				break;
			case PortD:
				TOG_BYTE(PORTD_REGISTER);
				break;
		}
	}
	else{}
}

//Toggle pin value
void DIO_vdTogPinValue(u8 PortID, u8 PinID)
{
	if(PortID >= 0 && PortID <= 3)
	{
		switch(PortID)
		{
			case PortA:
				TOG_BIT(PORTA_REGISTER, PinID);
				break;
			case PortB:
				TOG_BIT(PORTB_REGISTER, PinID);
				break;
			case PortC:
				TOG_BIT(PORTC_REGISTER, PinID);
				break;
			case PortD:
				TOG_BIT(PORTD_REGISTER, PinID);
				break;
		}
	}
	else{}
}
