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
#include "util\delay.h"
#include "DIO_Interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "GI_Interface.h"

void callBackTimerApp(void);
int main()
{
	assignPtrCallBack(callBackTimerApp);
	DIO_vdSetPintDirection(PortA, PIN0, PIN_OUTPUT);
	intiNormal();
	GI_vdEnableGI();
	while(1);
	return 0;
}

void callBackTimerApp(void)
{
	volatile static u8 counter=0;
	counter++;
	if(counter==31)
	{
		SET_BYTE(TCNT0_Register,123);
		DIO_vdTogPinValue(PortA, PIN0);
		counter=0;
	}
}
