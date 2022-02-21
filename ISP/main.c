/*

 * main.c
 *
 *  Created on: May 21, 2021
 *      Author: Compu Store
 */
#include "Macros.h"
#include "Types.h"
#include "DIO_Interface.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_Private.h"
#define F_CPU 8000000UL
void callBackTimerApp(void);
void main(void)
{
	u8 read;
	assignPtrCallBack(callBackTimerApp);
	SPI_init();
	DIO_vdSetPortDirection(PortA, PORT_OUTPUT);
#if (SPI_mode==Master)
	DIO_vdSetPintDirection(PortB, PIN4, PIN_INPUT );
	DIO_vdSetPintDirection(PortB, PIN5, PIN_OUTPUT);
	DIO_vdSetPintDirection(PortB, PIN6,  PIN_INPUT);
	DIO_vdSetPintDirection(PortB, PIN7, PIN_OUTPUT);
	DIO_vdSetPinValue(PortB, PIN4, PIN_High);
#elif (SPI_mode==Slave)
	DIO_vdSetPintDirection(PortB, PIN4,  PIN_INPUT);
	DIO_vdSetPintDirection(PortB, PIN5, PIN_INPUT);
	DIO_vdSetPintDirection(PortB, PIN6, PIN_OUTPUT );
	DIO_vdSetPintDirection(PortB, PIN7, PIN_INPUT);
	while(1)
	{
		read= SPI_read();
		DIO_vdSetPortValue(PortA, read);

	}
#endif
}

void callBackTimerApp(void)
{
	DIO_vdSetPortValue(PortA , SPDR_Reg);
}

