/*
 * EEPROM_Interface.h
 *
 *  Created on: May 28, 2021
 *      Author: Compu Store
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "Macros.h"
#include "Types.h"
#define Device_Select 0xA0
#define DeviceEnable 0

void EEPROM_write(u8 Data, u16 address);
void EEPROM_read(u8* Data, u16 address);

#endif /* EEPROM_INTERFACE_H_ */
