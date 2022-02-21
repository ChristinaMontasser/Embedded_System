/*
 * EX_Interface.h
 *
 *  Created on: Apr 10, 2021
 *      Author: Compu Store
 */

#ifndef EX_INTERFACE_H_
#define EX_INTERFACE_H_

#define EX_INT0 0
#define EX_INT1 1
#define EX_INT2 2

#define EX_SENSE_FALLING_EDGE   0
#define EX_SENSE_RAISING_EDGE   1
#define EX_SENSE_LOW_LEVEL      2
#define EX_SENSE_LOGIACL_CHANGE 3

void EX_vdDisable(u8 CopyInterrupt);
void EX_vdConfigInterrupt(u8 CopyInterrupt , u8 CopyControlSense);


#endif /* EX_INTERFACE_H_ */
