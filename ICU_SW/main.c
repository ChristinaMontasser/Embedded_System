/*
 * main.c
 *
 *  Created on: May 1, 2021
 *      Author: Compu Store
 */


#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "Timer_interface.h"
#include "EX_Interface.h"
#include "Timer1_interface.h"

void __vector_1 (void) __attribute__((signal));
void callBackTimerApp(void);

void main(void)
{
	assignPtrCallBack(callBackTimerApp);
	//Timer1 conf
	intial();

	//Timer0 conf
	intiNormal(Normal_Mode, Prescaler8, 0);

	//Interrupt
	GI_vdEnableGI();
	EX_vdConfigInterrupt(EX_INT0 , EX_SENSE_RAISING_EDGE);

}

void callBackTimerApp(void)
{
	volatile static u8 counter=0;
	counter++;

}
void __vector_1 (void)
{
	volatile static u8 edge= EX_SENSE_RAISING_EDGE;
	volatile static Ton=0, Toff=0;
	if(edge==EX_SENSE_RAISING_EDGE && Ton!=0)
	{
		Toff = TCNT0_Register*ticTime*counter - Ton;
		edge = EX_SENSE_FALLING_EDGE;
		EX_vdConfigInterrupt(EX_INT0 , EX_SENSE_FALLING_EDGE);
	}
	else if(edge == EX_SENSE_FALLING_EDGE)
	{
		//assume tick time = 1us
		Ton= TCNT0_Register*ticTime*counter;
		EX_vdConfigInterrupt(EX_INT0 , EX_SENSE_RAISING_EDGE);

	}
	else{
		TimerOverFlowInterrupt();
		edge = EX_SENSE_FALLING_EDGE;
		EX_vdConfigInterrupt(EX_INT0 , EX_SENSE_FALLING_EDGE);
	}
}
