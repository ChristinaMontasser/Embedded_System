/*
 * DIO_Registers.h
 *
 *  Created on: Mar 29, 2021
 *      Author: Compu Store
 */

#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#define DDRA_REGISTER  *((volatile u8*) 0x3A)
#define PORTA_REGISTER *((volatile u8*) 0x3B)
#define PINA_REGISTER  *((volatile u8*) 0x39)

#define DDRB_REGISTER  *((volatile u8*) 0x37)
#define PORTB_REGISTER *((volatile u8*) 0x38)
#define PINB_REGISTER  *((volatile u8*) 0x36)

#define DDRC_REGISTER  *((volatile u8*) 0x34)
#define PORTC_REGISTER *((volatile u8*) 0x35)
#define PINC_REGISTER  *((volatile u8*) 0x33)

#define DDRD_REGISTER  *((volatile u8*) 0x31)
#define PORTD_REGISTER *((volatile u8*) 0x32)
#define PIND_REGISTER  *((volatile u8*) 0x30)


#endif /* DIO_REGISTERS_H_ */
