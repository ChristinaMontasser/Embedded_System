/*
 * Timer_interface.h
 *
 *  Created on: Apr 23, 2021
 *      Author: Compu Store
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TM_vdintiNormalPeriodicEve(u8 ModeofOperation, u8 ClockSelect, u8 desiredTime);
void PWM_vdCompareOut(u8 mode);
void intiNormal(u8 ModeofOperation, u8 ClockSelect);
void CompareOutPutModeToggle();
void TimerOverFlowInterrupt();
void TimerCompareInterrupt();
void TM_vdintiNormalNonPeriodicEve(void);
u8 TimeOverflow(f32 F_Timer,u8 desiredTime);
u8 TimeCases(u8 desiredTime,u8 TimeOverFlow,  u8 TimeTick  );
u8 TM_TimeOn(f32 F_timer ,u8 desiredTime);
//Inverted and non inverted function
#define Normal_Mode 0
#define CTC_Mode    1
#define PWM_Mode    2
#define PWM_FAST 3

#define PWM_Inverted 0
#define PWM_NonInverted 1

#define Prescaler8    0
#define Prescaler64   1
#define Prescaler256  2
#define Prescaler1024 3
#define F_CPU 8000000UL



#endif /* TIMER_INTERFACE_H_ */
