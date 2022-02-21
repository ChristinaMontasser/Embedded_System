/*
 * Ex_private.h
 *
 *  Created on: Apr 10, 2021
 *      Author: Compu Store
 */

#ifndef EX_PRIVATE_H_
#define EX_PRIVATE_H_

#define MCUCR_REGISTER  *((volatile u8*) 0x55)
#define GICR_REGISTER  *((volatile u8*) 0x5B)
#define GIFR_REGISTER  *((volatile u8*) 0x5A)
#define MCUCSR_REGISTER *((volatile u8 *)0x54)

#endif /* EX_PRIVATE_H_ */
