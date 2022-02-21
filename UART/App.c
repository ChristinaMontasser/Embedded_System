/*
 * App.c

 *
 *  Created on: May 8, 2021
 *      Author: Compu Store
 */

#include "Types.h"
#include "URAT_Interface.h"
#include "DIO_Interface.h"
void main(void)
{
	u8 data;
	DIO_vdSetPortDirection(PortA,PORT_OUTPUT);
	URAT_vdInit();
	while(1)
	{
		data =URAT_u8Rec();
		data = data - 48;
		DIO_vdSetPortValue(PortA , data);
	}

}
