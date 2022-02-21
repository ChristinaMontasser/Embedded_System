/*
 * I2C_Private.h
 *
 *  Created on: May 27, 2021
 *      Author: Compu Store
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

//Bit rate register, select division factor use Set Byte
#define TWBR_Reg *((volatile u8*)0x20)
//Control register-->Interrupt flag, enable ack, start condition, stop condition, collision flag, Enable, Interrupt enable
#define TWCR_Reg *((volatile u8*)0x56)
#define TWSR_Reg *((volatile u8*)0x21)
//Data Register
#define TWDR_Reg *((volatile u8*)0x23)
//Address register of slave
#define TWAR_Reg *((volatile u8*)0x22)

#endif /* I2C_PRIVATE_H_ */
