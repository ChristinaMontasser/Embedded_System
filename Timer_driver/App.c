/*

 * App.c
 *
 *  Created on: Apr 23, 2021
 *      Author: Compu Store
 */
#define F_CPU 8000000UL

#include "Types.h"
#include "Macros.h"
#include "DIO_Interface.h"
#include "DIO_Interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "GI_Interface.h"
void __vector_11 (void) __attribute__((signal));
int main()
{
	DIO_vdSetPintDirection(PortB, PIN3,PIN_OUTPUT);
	TM_vdintiNormalPeriodicEve(PWM_Mode, Prescaler1024, 100);
	PWM_vdCompareOut(PWM_NonInverted);
	//DIO_vdSetPintDirection(PortA, PIN0, PIN_OUTPUT);
	//DIO_vdSetPintDirection(PortA, PIN0, PIN_OUTPUT);
	//intiNormal(CTC_Mode, Prescaler1024);
/*	while(1){
		TM_vdintiNormalNonPeriodicEve();
	}*/
	return 0;
}

void __vector_11 (void)
{
	/*volatile static u8 counter=0;
	counter++;
	if(counter==31)
	{
		SET_BYTE(TCNT0_Register,123);
		DIO_vdTogPinValue(PortA, PIN0);
		counter=0;
	}*/
	//DIO_vdSetPinValue(PortA, PIN0,PIN_High);

}
