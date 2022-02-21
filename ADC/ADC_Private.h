/*
 * ADC_Private.h
 *
 *  Created on: Apr 17, 2021
 *      Author: Compu Store
 */

#include "Types.h"
#include "Macros.h"

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX_Reg 	*((volatile u8*)0x27) 	// ADC Multiplexer Register
#define ADCSRA_Reg 	*((volatile u8*)0x26) 	// ADC Control And Status Register
#define ADCH_Reg 	*((volatile u8*)0x25) 		// ADC High Register
#define ADC 	    *((volatile u16*)0x24) 		// ADC Low Register


#endif /* ADC_PRIVATE_H_ */
