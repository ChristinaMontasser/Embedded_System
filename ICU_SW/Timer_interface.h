/*
 * Timer_interface.h
 *
 *  Created on: Apr 23, 2021
 *      Author: Compu Store
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void intiNormal(u8 ModeofOperation, u8 ClockSelect, u8 desiredTime);
void CompareOutPutModeToggle();
void TimerOverFlowInterrupt();
void TimerCompareInterrupt();
void TM_vdintiNormalNonPeriodicEve(void);
u8 TimeOverflow(u8 ClockSelect ,u8 desiredTime);
u8 TimeCases(u8 desiredTime,u8 TimeOverFlow,  u8 TimeTick  );
void assignPtrCallBack(void (*PtrPassed)(void));
//Inverted and non inverted function
#define Normal_Mode 0
#define CTC_Mode    1
#define PMW_Mode    2
#define PMW_FAST 3

#define PMW_Inverted 0
#define PMW_NonInverted 1

#define Prescaler8    0
#define Prescaler64   1
#define Prescaler256  2
#define Prescaler1024 3
#define F_CPU 8000000UL



#endif /* TIMER_INTERFACE_H_ */
