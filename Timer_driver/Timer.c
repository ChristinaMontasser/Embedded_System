/*

 * Timer.c
 *
 *  Created on: Apr 23, 2021
 *      Author: Compu Store
/
 *
 */
#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "avr\delay.h"
#include "DIO_Interface.h"
#include "GI_Interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
//desired time in mic , Ton in PWM fast
//Duty cycle -percentage of ON = Ton -OCR+1- / 256 -T total- FastPWM
//Duty cycle = 2OCR+1/510
void TM_vdintiNormalPeriodicEve(u8 ModeofOperation, u8 ClockSelect, u8 desiredTime)
{
	u8 startTime;
	//WaveForm generator
	if(ModeofOperation<=2 )
	{
		switch(ModeofOperation)
		{
			case Normal_Mode:
				startTime=TimeOverflow(F_CPU/ClockSelect, desiredTime);
				SET_BYTE(TCNT0_Register, startTime);
				CLR_BIT(TCCR0_Register, 3);
				CLR_BIT(TCCR0_Register, 6);
				TimerOverFlowInterrupt();
				break;
			case CTC_Mode:
				SET_BIT(TCCR0_Register, 3);
				CLR_BIT(TCCR0_Register, 6);
				TimerCompareInterrupt();
				SET_BYTE(OCR0_Register, desiredTime);
				//?
				CompareOutPutModeToggle();
				break;
			case PWM_Mode:
				SET_BIT(TCCR0_Register, 6);
				CLR_BIT(TCCR0_Register, 3);
				//Deal with it as percentage
				SET_BYTE(OCR0_Register, TM_TimeOn(F_CPU/1024, desiredTime));
				break;
			case PWM_FAST:
				SET_BYTE(OCR0_Register, desiredTime);
				SET_BIT(TCCR0_Register, 6);
				SET_BIT(TCCR0_Register, 3);
				break;
		}
	}
	if(ClockSelect<=3)
	{
		switch(ClockSelect)
		{
			case Prescaler8:
				CLR_BIT(TCCR0_Register, 0);
				SET_BIT(TCCR0_Register, 1);
				CLR_BIT(TCCR0_Register, 2);
				break;
			case Prescaler64:
				SET_BIT(TCCR0_Register, 0);
				SET_BIT(TCCR0_Register, 1);
				CLR_BIT(TCCR0_Register, 2);
				break;
			case Prescaler256:
				CLR_BIT(TCCR0_Register, 0);
				CLR_BIT(TCCR0_Register, 1);
				SET_BIT(TCCR0_Register, 2);
				break;
			case Prescaler1024:
				SET_BIT(TCCR0_Register, 0);
				CLR_BIT(TCCR0_Register, 1);
				SET_BIT(TCCR0_Register, 2);
				break;
		}

	}
}

u8 TM_TimeOn(f32 F_timer ,u8 desiredTime)
{
	u8 total, Ton;
	total = 1/F_timer;
	Ton= (desiredTime/100)*total;
	return Ton;
}

void PWM_vdCompareOut(u8 mode)
{
	switch(mode)
	{
	    case PWM_Inverted:
	    	SET_BIT(TCCR0_Register, 4);
	    	SET_BIT(TCCR0_Register, 5);
	    	break;
	    case PWM_NonInverted:
	    	CLR_BIT(TCCR0_Register, 4);
	    	SET_BIT(TCCR0_Register, 5);
	    	break;
	}
}

void CompareOutPutModeToggle()
{
	//SET OutputCompare register page80
	DIO_vdSetPintDirection(PortB, OC0, PIN_OUTPUT);
	//ToggleMode
	SET_BIT(TCCR0_Register, 4);
	CLR_BIT(TCCR0_Register, 5);
}

void TimerOverFlowInterrupt()
{
	GI_vdEnableGI();
	SET_BIT(TIMSK_Register, 0);
}
void TimerCompareInterrupt()
{
	GI_vdEnableGI();
	SET_BIT(TIMSK_Register, 1);
}

u8 TimeOverflow(f32 F_Timer ,u8 desiredTime)
{
	f32 TimeTick, TimeOverFlow;
	TimeTick =1/F_Timer;
	TimeOverFlow = TimeTick*(2^8);
	if(TimeOverFlow==desiredTime)
		return 0;
	else
	{
		return TimeCases( desiredTime,TimeOverFlow, TimeTick );
	}
}
u8 TimeCases(u8 desiredTime, u8 TimeOverFlow, u8 TimeTick )
{
	u8 numOfTicks=0, preload=0;
	f32 numOfOver=0.0;
	if(desiredTime<TimeOverFlow)
	{
		numOfTicks= desiredTime/TimeTick;
		preload= 256- numOfTicks;
		return preload;
	}
	else
	{
		numOfOver= desiredTime/TimeOverFlow;
		if(numOfOver==(u8)numOfOver)
			return 0;
		else
		{
			numOfOver=numOfOver-(u8)numOfOver;
			numOfTicks=numOfOver*256;
			preload= 256- numOfTicks;
			return preload;
		}
	}
	return 0;
}





void TM_vdintiNormalNonPeriodicEve(void)
{
	SET_BYTE(TCNT0_Register,254);
	//Normal mode
	CLR_BIT(TCCR0_Register, 3);
	CLR_BIT(TCCR0_Register, 6);
	//falling edge
	CLR_BIT(TCCR0_Register, 0);
	SET_BIT(TCCR0_Register, 1);
	SET_BIT(TCCR0_Register, 2);
	//PullUp resistor on hardware pin --> Direction Input, PIN high
	DIO_vdSetPintDirection(PortB, T1, PIN_INPUT);
	DIO_vdSetPinValue(PortB, T1, PIN_High);
	while(DIO_u8GetPinValue(PortB, T1)!=0);
	TimerOverFlowInterrupt();
}
