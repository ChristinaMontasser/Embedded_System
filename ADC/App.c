/*
 * App.c
 *
 *  Created on: Apr 17, 2021
 *      Author: Compu Store
 */

#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "util\delay.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include "DIO_Interface.h"

void callBackTimerApp(void);

void main (void)
{
	assignPtrCallBack(callBackTimerApp);

	//u16 DigitalValue = 0;
	/*float AnalogValue = 0;
	f32 Temp=0;
	f32 LDR=0;*/
	DIO_vdSetPintDirection(PortA,PIN0,PIN_INPUT);

	LCD_vdInitialization();
	ADC_Init (externalCapacitor, rightAdjust);
	ADC_conversion (PIN0, singleConversion);
	while(1)
	{
		/*DigitalValue = ADC_Read(PIN0);
		//AnalogValue = (DigitalValue*2500)/1024;
		Temp=(DigitalValue*150)/600;
		if(Temp<20)
		{
			DIO_vdSetPinValue(PortB,PIN0,PIN_LOW);
			DIO_vdSetPinValue(PortB,PIN1,PIN_LOW);
			DIO_vdSetPinValue(PortB,PIN2,PIN_High);
		}
		else if(Temp >20 && Temp< 40)
		{
			DIO_vdSetPinValue(PortB,PIN0,PIN_LOW);
			DIO_vdSetPinValue(PortB,PIN1,PIN_High);
			DIO_vdSetPinValue(PortB,PIN2,PIN_LOW);
		}
		else if(Temp > 40)
		{
			DIO_vdSetPinValue(PortB,PIN0,PIN_High);
			DIO_vdSetPinValue(PortB,PIN1,PIN_LOW);
			DIO_vdSetPinValue(PortB,PIN2,PIN_LOW);
		}*/

		//DigitalValue = ADC_Read();
	/*	AnalogValue = (DigitalValue*5000)/1024;
		LDR = ((5000*5000)-(5000*AnalogValue))/AnalogValue;
		LDR/=1000;
		if(LDR<200)
		{
			DIO_vdSetPinValue(PortB,PIN0,PIN_LOW);

		}
		else if(LDR>500)
		{
			DIO_vdSetPinValue(PortB,PIN0,PIN_High);

		}*/
		ADC_conversion (PIN0, autoTrigringFreeRunning);
	}
}

void callBackTimerApp(void)
{
	u16 DigitalValue;
	DigitalValue = ADC_Read(PIN0);
	u8 AnalogValue = (DigitalValue*2500)/1024;
	LCD_vdWriteNum(AnalogValue);
}

