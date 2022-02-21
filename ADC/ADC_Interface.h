/*
 * ADC_Interface.h
 *
 *  Created on: Apr 17, 2021
 *      Author: Compu Store
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

//ADMUCX bit 6 7
void assignPtrCallBack(void (*PtrPassed)(void));

void ADC_conversion (u8 channel, u8 conversionSelect);
void ADC_Init (u8 voltageSelection, u8 LRAdjust);
u8 ADC_Read();

#define internalVref 0  //0 0
#define externalCapacitor 1 // 0 1
#define Ex_internal 2  //1 1

#define rightAdjust 0 //0 in bit5 in ADMUCX
#define leftAdjust 1 //1 in bit5 in ADMUCX

#define singleConversion 0 //Bit 6 -->1
#define autoTrigring  1 //Bit5 Bit3 --> 1 +Global interrupt
#define autoTrigringFreeRunning 2 //Bit5 Bit3 --> 1 +Global interrupt + Bit 6 -->1

#define ADC0_channel 0
#define ADC1_channel 1
#define ADC2_channel 2
#define ADC3_channel 3
#define ADC4_channel 4
#define ADC5_channel 5
#define ADC6_channel 6
#define ADC7_channel 7
#endif /* ADC_INTERFACE_H_ */
