/*
 * Ex_prog.c
 *
 *  Created on: Apr 10, 2021
 *      Author: Compu Store
 */
#include "EX_Interface.h"
#include "Ex_private.h"
#include "Macros.h"
#include "DIO_Interface.h"
void EX_vdDisable(u8 CopyInterrupt)
{
	if(CopyInterrupt <= EX_INT2)
	{
		switch (CopyInterrupt)
		{
		case EX_INT0:
			CLR_BIT(GICR_REGISTER,6);
			break;
		case EX_INT1:
			CLR_BIT(GICR_REGISTER,7);
			break;
		case EX_INT2:
			CLR_BIT(GICR_REGISTER,5);
			break;
		default:
			break;
		}
	}
}

void EX_vdConfigInterrupt(u8 CopyInterrupt , u8 CopyControlSense)
{
	if(CopyInterrupt <= EX_INT2 && CopyControlSense <= EX_SENSE_LOGIACL_CHANGE)
	{
		switch (CopyInterrupt)
		{
			case EX_INT0:
				SET_BIT(GICR_REGISTER,6);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						CLR_BIT(MCUCR_REGISTER,0);
						SET_BIT(MCUCR_REGISTER,1);
						break;
					case EX_SENSE_RAISING_EDGE:
						SET_BIT(MCUCR_REGISTER,0);
						SET_BIT(MCUCR_REGISTER,1);
						break;
					case EX_SENSE_LOW_LEVEL:
						CLR_BIT(MCUCR_REGISTER,0);
						CLR_BIT(MCUCR_REGISTER,1);
						break;
					case EX_SENSE_LOGIACL_CHANGE:
						SET_BIT(MCUCR_REGISTER,0);
						CLR_BIT(MCUCR_REGISTER,1);
						break;
				}
				break;
			case EX_INT1:
				SET_BIT(GICR_REGISTER,7);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						CLR_BIT(MCUCR_REGISTER,2);
						SET_BIT(MCUCR_REGISTER,3);
						break;
					case EX_SENSE_RAISING_EDGE:
						SET_BIT(MCUCR_REGISTER,2);
						SET_BIT(MCUCR_REGISTER,3);
						break;
					case EX_SENSE_LOW_LEVEL:
						CLR_BIT(MCUCR_REGISTER,2);
						CLR_BIT(MCUCR_REGISTER,3);
						break;
					case EX_SENSE_LOGIACL_CHANGE:
						SET_BIT(MCUCR_REGISTER,2);
						CLR_BIT(MCUCR_REGISTER,3);
						break;
				}
				break;
			case EX_INT2:
				SET_BIT(GICR_REGISTER,5);
				switch (CopyControlSense)
				{
					case EX_SENSE_FALLING_EDGE:
						CLR_BIT(MCUCSR_REGISTER,6);
						break;
					case EX_SENSE_RAISING_EDGE:
						SET_BIT(MCUCSR_REGISTER,6);
						break;
				}
				break;
		}
	}

}
