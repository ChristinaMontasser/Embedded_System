/*
 * GI_prog.c
 *
 *  Created on: Apr 10, 2021
 *      Author: Compu Store
 */
#include "Types.h"
#include "Macros.h"
#include "GI_Interface.h"
#include "GI_Private.h"

void GI_vdEnableGI()
{
	SET_BIT(SREG_REGISTER, BIT_I);
}

void GI_vdDisEnableGI()
{
	 CLR_BIT(SREG_REGISTER, BIT_I);
}


