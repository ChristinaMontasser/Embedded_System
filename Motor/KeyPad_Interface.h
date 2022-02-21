/*
 * Keypad_Interface.h
 *
 *  Created on: Apr 3, 2021
 *      Author: Abdelrhman Walaa
 */

#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#define KEYPAD_U8_PORT PortC

// Number of rows and columns connecting the 8 switches
#define ROWS 	4
#define COLUMNS 4

// 0b00001111 -> 0x0F : To set output (LSB) and input (MSB)
#define COLS_ROWS_DIRECTION 0x0F

// 0b11111111 -> 0xFF : To set high value (LSB) and to enable pull-up resistor (MSB)
#define COLS_ROWS_VALUE 0xFF

void Keypad_vdInitialization (void);
void Keypad_vdGetPressedKey (u8 *LOC_pu8ReturnedData);

#endif /* KEYPAD_INTERFACE_H_ */
