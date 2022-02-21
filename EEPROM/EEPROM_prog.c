/*
 * EEPROM_prog.c
 *
 *  Created on: May 28, 2021
 *      Author: Compu Store
 */

#ifndef EEPROM_PROG_C_
#define EEPROM_PROG_C_
#include "Macros.h"
#include "I2C_Interface.h"
#include "EEPROM_Interface.h"

void EEPROM_write(u8 Data, u16 address)
{
	u8 Address=0, ByteAddress=0 ;
	u16 ByteSelect=0;
	Send_vdStartCondition();
	Address = (Device_Select)|(DeviceEnable<<3)|(u8)((address>>7)&0x06);
	Address = Address>>1;
	Send_vdSlaveAddWrite(Address);
	ByteAddress = (u8)(address);
	Send_vdData(ByteAddress);
	Send_vdData(Data);
	Send_vdStopCondition();
}

void EEPROM_read(u8* Data, u16 address)
{
	u8 Address=0,ByteAddress=0 ;
	//u16 ByteSelect=0;
	Send_vdStartCondition();
	Address = (Device_Select)|(DeviceEnable<<3)|(u8)((address>>7)&0x06);
	Address = Address>>1;
	Send_vdSlaveAddWrite(Address);
	ByteAddress = (u8)(address);
	Send_vdData(ByteAddress);
	Send_vdRepStartCondition();
	Send_vdSlaveAddRead(Address);
	*Data= Read_u8Data();
	Send_vdStopCondition();
}

#endif /* EEPROM_PROG_C_ */
