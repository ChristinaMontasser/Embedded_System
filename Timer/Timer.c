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
#include "Timer_private.h"

void (*Ptr)(void);

void intiNormal()
{
	SET_BYTE(TCNT0_Register,123);
	//normal
	CLR_BIT(TCCR0_Register, 3);
	CLR_BIT(TCCR0_Register, 6);
	SET_BIT(TIMSK_Register, 0);
	SET_BIT(TCCR0_Register, 0);
	CLR_BIT(TCCR0_Register, 1);
	SET_BIT(TCCR0_Register, 2);

}
void assignPtrCallBack(void (*PtrPassed)(void))
{
	Ptr=PtrPassed;
}
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	(Ptr)();
}
