/*
 * ADC_prog.c
 *
 *  Created on: Apr 17, 2021
 *      Author: Compu Store
 */
#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"
#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "GI_Interface.h"

void (*Ptr)(void);

void ADC_Init (u8 voltageSelection, u8 LRAdjust)
{
	//ADC Enable
	SET_BIT(ADCSRA_Reg,7);

	//Prescaler Configuration as 128
	SET_BIT(ADCSRA_Reg,2);
	SET_BIT(ADCSRA_Reg,1);
	SET_BIT(ADCSRA_Reg,0);

	switch(voltageSelection)
	{
		case internalVref:
			CLR_BIT(ADMUX_Reg,7);
			CLR_BIT(ADMUX_Reg,6);
			break;
		case externalCapacitor:
			CLR_BIT(ADMUX_Reg,7);
			SET_BIT(ADMUX_Reg,6);
			break;
		case Ex_internal:
			SET_BIT(ADMUX_Reg,7);
			SET_BIT(ADMUX_Reg,6);
			break;
	}
	switch(LRAdjust)
	{
	case rightAdjust:
		CLR_BIT(ADMUX_Reg,5);
		break;
	case leftAdjust:
		SET_BIT(ADMUX_Reg,5);
		break;
	}
}

void ADC_conversion (u8 channel, u8 conversionSelect)
{
	//We have to select channel before start conversion
	//there are ADC0-7 channel, it can be handled by macros
	//set and clear 3 bits
	// ADC Channel Selection
	//Switch 7 cases
	channel &= 0x07;
	ADMUX_Reg &= 0xE0;
	ADMUX_Reg |= channel;

	switch(conversionSelect)
	{
	case singleConversion:
		SET_BIT(ADCSRA_Reg,6);
		//wait for the conversion ?????
		while(!(ADCSRA_Reg & (1<<4)));
		//ADC Flag Clear
		SET_BIT(ADCSRA_Reg,4);
		break;
	case autoTrigring:
		SET_BIT(ADCSRA_Reg,5);
		SET_BIT(ADCSRA_Reg,3);
		GI_vdEnableGI();
		break;
	case autoTrigringFreeRunning:
		SET_BIT(ADCSRA_Reg,6);
		SET_BIT(ADCSRA_Reg,5);
		SET_BIT(ADCSRA_Reg,3);
		GI_vdEnableGI();
		break;
	}

}

u8 ADC_Read()
{
	return ADC;
}

void assignPtrCallBack(void (*PtrPassed)(void))
{
	Ptr=PtrPassed;
}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	(Ptr)();
}
