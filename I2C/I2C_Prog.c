/*
 * I2C_Prog.c
 *
 *  Created on: May 27, 2021
 *      Author: Compu Store
 */
#include "Macros.h"
#include "Types.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

#define F_CPU 8000000UL
//It's up to 400KH
#define F_SCL 200000UL
#define TWBRValue ((((F_CPU / F_SCL) / Prescaler1) - 16 ) / 2)
//12
void init_vdMaster()
{
	//Select division factor
	CLR_BIT(TWSR_Reg, TWPS0);
	CLR_BIT(TWSR_Reg, TWPS1);
	//Bit rate
	SET_BYTE(TWBR_Reg, TWBRValue);
	SET_BIT(TWCR_Reg, EnableAck_TWEA);
	SET_BIT(TWAR_Reg, GeneralCall);
	//Enable
	SET_BIT(TWCR_Reg, Enable_TWEN);

}

void Send_vdStartCondition()
{
	//Start Condition //Must be cleared after transmitted
	SET_BIT(TWCR_Reg, Start_TWSTA);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
	//

}

void Send_vdStopCondition()
{
	SET_BIT(TWCR_Reg, Stop_TWSTO);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
}

void Send_vdSlaveAddWrite(u8 Slave_address)
{
	CLR_BIT(TWCR_Reg, Start_TWSTA);
	//Send address on data register
	Slave_address = Slave_address<<1;
	SET_BYTE(TWDR_Reg, Slave_address);
	CLR_Bit(TWDR_Reg, 0);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
	//CheckAck
	/*//Send data
	SET_BYTE(TWDR_Reg, Data);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);*/
}

void Send_u8SlaveAddRead(u8 Slave_address)
{
	CLR_BIT(TWCR_Reg, Start_TWSTA);
	//Send address on data register
	SET_BYTE(TWDR_Reg, Slave_address<<1);
	SET_BIT(TWDR_Reg, 0);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
	//Read data
}

void Send_vdRepStartCondition()
{
	SET_BIT(TWCR_Reg, Start_TWSTA);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
}

void Send_vdData(u8 Data)
{
	//Send data
	SET_BYTE(TWDR_Reg, Data);
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
}
u8 Read_u8Data()
{
	SET_BIT(TWCR_Reg, IntFlag_TWINT);
	while((GET_BIT(TWCR_Reg, IntFlag_TWINT))!=1);
	return TWDR_Reg;
}

void init_vdSlave(u8 MyAddress)
{
	SET_BIT(TWCR_Reg, EnableAck_TWEA);
	//Enable
	SET_BIT(TWCR_Reg, Enable_TWEN);
	//Shift address left by 1
	TWAR_Reg &=(MyAddress<<1);
	SET_BIT(TWAR_Reg, GeneralCall);
}

//Slave sends ack when reading data its address from data bus --> Set "EnableAck_TWEA"
//Master must Check Ack before sending data
//Stop function must clear that ack bit

