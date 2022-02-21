/*
 * ISP_prog.c
 *
 *  Created on: May 21, 2021
 *      Author: Compu Store
 */

#include "Macros.h"
#include "Types.h"
#include "SPI_Private.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "GI_Interface.h"
void (*Ptr)(void);

void SPI_init(void)
{
	SET_BIT(SPCR_Reg,Enable);
	SET_BIT(SPCR_Reg,LSB);
	//Prescaler
	/*CLR_BIT(SPCR_Reg,0);
	CLR_BIT(SPCR_Reg,1);*/
	//GI_vdEnableGI();
	//SET_BIT(SPCR_Reg, EnableInterrupt);
	CLR_BIT(SPCR_Reg,clockPolarity);
	SET_BIT(SPCR_Reg, clockPhase);

#if (SPI_mode==Master)
		SET_BIT(SPCR_Reg,selectMS);
#elif (SPI_mode==Slave)
		CLR_BIT(SPCR_Reg,selectMS);
#endif
}

u8 SPI_read()
{
	while((GET_BIT(SPSR_Reg,7))!=1);
	SET_BIT(SPSR_Reg,7);
	return SPDR_Reg;
}
void SPI_write(u8 data)
{
	SET_BYTE(SPDR_Reg, data);
}

void assignPtrCallBack(void (*PtrPassed)(void))
{
	Ptr=PtrPassed;
}
void __vector_12 (void) __attribute__((signal));
void __vector_12 (void)
{
	Ptr();
}
