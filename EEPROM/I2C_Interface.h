/*
 * I2C_Interface.h
 *
 *  Created on: May 27, 2021
 *      Author: Compu Store
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include "Macros.h"
#include "Types.h"
//TWCR Bits
#define Enable_TWEN    2
#define Enable_IntTWEI 0
#define WriteCol_TWWC  3
#define Stop_TWSTO     4
#define Start_TWSTA    5
#define EnableAck_TWEA 6
#define IntFlag_TWINT  7

#define GeneralCall 0
//TWSR
//Job status TWSR 7->3
#define Prescaler1 1
#define Prescaler4 4
#define Prescaler16 16
#define Prescaler64 64

#define TWPS0  0
#define TWPS1  1

//TWAR
#define TWGCE 0

void init_vdMaster();
void Send_vdStartCondition();
void Send_vdStopCondition();
void Send_vdSlaveAddWrite(u8 Slave_address);
void Send_u8SlaveAddRead(u8 Slave_address);
void Send_vdRepStartCondition();
void Send_vdData(u8 Data);
u8 Read_u8Data();
void init_vdSlave(u8 MyAddress);

#endif /* I2C_INTERFACE_H_ */
