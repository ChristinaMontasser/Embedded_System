/*
 * Keypad_program.c
 *
 *  Created on: Apr 3, 2021
 *      Author: Abdelrhman Walaa
 */
//#include <stdlib.h>
#include "avr/delay.h"
#include "Macros.h"
#include "Types.h"
#include "DIO_Interface.h"
#include "KeyPad_Interface.h"

u8 KEYPAD_u8KeysValues[ROWS][COLUMNS]=
{
		{'1','2','3','+'},
		{'4','5','6','-'},
		{'7','8','9','*'},
		{'0','=','/','%'}
};

void Keypad_vdInitialization (void)
{
	DIO_vdSetPortDirection(KEYPAD_U8_PORT, COLS_ROWS_DIRECTION);
	DIO_vdSetPortValue(KEYPAD_U8_PORT, COLS_ROWS_VALUE);
}

void Keypad_vdGetPressedKey (u8 *LOC_pu8ReturnedData)
{
	u8 LOC_u8RowsCounter , LOC_u8ColoumsCounter , LOC_u8StatusButton;

	DIO_vdSetPortValue(KEYPAD_U8_PORT, COLS_ROWS_VALUE);

	//if(LOC_pu8ReturnedData == NULL)

	for(LOC_u8RowsCounter = 0 ; LOC_u8RowsCounter <= 3 ; LOC_u8RowsCounter++)
	{
		DIO_vdSetPinValue(KEYPAD_U8_PORT,LOC_u8RowsCounter,PIN_LOW);

		for(LOC_u8ColoumsCounter = 0 ; LOC_u8ColoumsCounter <= 3 ; LOC_u8ColoumsCounter++)
		{
			LOC_u8StatusButton = DIO_u8GetPinValue(KEYPAD_U8_PORT, LOC_u8ColoumsCounter+4);

			if(LOC_u8StatusButton == PIN_LOW)
			{
				_delay_ms(20);
				LOC_u8StatusButton = DIO_u8GetPinValue(KEYPAD_U8_PORT, LOC_u8ColoumsCounter+4);

				while (LOC_u8StatusButton == PIN_LOW)
				{
					LOC_u8StatusButton = DIO_u8GetPinValue(KEYPAD_U8_PORT, LOC_u8ColoumsCounter+4);
				}

				*LOC_pu8ReturnedData = KEYPAD_u8KeysValues[LOC_u8RowsCounter][LOC_u8ColoumsCounter];
				return;
			}
		}
		DIO_vdSetPinValue(KEYPAD_U8_PORT, LOC_u8RowsCounter, PIN_High);
	}
}



