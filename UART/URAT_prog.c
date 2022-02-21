/*
 * URAT_prog.c

 *
 *  Created on: May 8, 2021
 *      Author: Compu Store
 */

#include "Types.h"
#include "URAT_private.h"
#include "URAT_Interface.h"
#include "Macros.h"

void URAT_vdInit(void)
{
	//Tran Enb
	SET_BIT(UCSRB_Reg, 3);
	//Rec Enb
	SET_BIT(UCSRB_Reg, 4);
	//Char size
	CLR_BIT(UCSRB_Reg, 2);
	SET_BYTE(UCSRC_Reg, 0b10000110);
	SET_BYTE(UBRRL_Reg, 51);
}

u8 URAT_u8Rec(void)
{

	while((GET_BIT(UCSRA_Reg,7))!=1);
	SET_BIT(UCSRA_Reg,7);
	return UDR_Reg;
}

void URAT__vdTran(u8 dataTran)
{
	while((GET_BIT(UCSRA_Reg,5))!=1);
	SET_BYTE(UDR_Reg, dataTran);
}



ISR(Recevire)
{
	x = UDR;
}

ISR(data register empty)
{
	UDR = x;
}
