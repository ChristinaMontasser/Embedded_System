/*
 * APP.c
 *
 *  Created on: May 28, 2021
 *      Author: Compu Store
 */
#include "Macros.h"
#include "Types.h"
#include "DIO_Interface.h"
#include "EEPROM_Interface.h"

void main(void)
{
	u8 data=0;
	DIO_vdSetPortDirection(PortA, PORT_OUTPUT);
	EEPROM_write(10, 100);
	EEPROM_read(&data, 100);
	DIO_vdSetPortValue(PortA, data);
	while(1);
}
