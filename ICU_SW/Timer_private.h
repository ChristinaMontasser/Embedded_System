/*
 * Timer_private.h
 *
 *  Created on: Apr 23, 2021
 *      Author: Compu Store
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCCR0_Register *((volatile u8*) 0x53)
#define TCNT0_Register *((volatile u8*) 0x52)
#define OCR0_Register *((volatile u8*) 0x5C)
#define TIMSK_Register *((volatile u8*) 0x59)
#define TIFR_Register *((volatile u8*) 0x58)

#define OC0 PIN3
#define T1 PIN1
#endif /* TIMER_PRIVATE_H_ */
