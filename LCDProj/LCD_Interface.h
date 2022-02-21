/*
 * LCD_Interface.h
 *
 *  Created on: Apr 2, 2021
 *      Author: Abdelrhman Walaa
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#define LCD_U8_DATA_PORT PortA
#define LCD_U8_CTRL_PORT PortD

#define LCD_U8_RS_PIN PIN0
#define LCD_U8_RW_PIN PIN1
#define LCD_U8_EN_PIN PIN2


/*Configured bits:
 * 1- BIT4 DL: 0-> 4 bit    , 1-> 8 bit
 * 2- BIT3 N : 0-> 1 Line   , 1-> 2 Lines
 * 3- BIT2 F : 0-> 5*7 dots , 1-> 5*10 dots
 * */
#define LCD_U8_FUNC_SET 0b00111000

/*Configured bits:
 * 1- BIT2 D : 0-> Display OFF      , 1-> Display ON
 * 2- BIT1 C : 0-> Cursor OFF       , 1-> Cursor ON
 * 3- BIT0 B : 0-> Cursor Blink OFF , 1-> Cursor Blink ON
 * */
#define LCD_U8_DISP_ON_OFF_CTRL 0b00001111

/*Configured bits:
 * 1- BIT1 I/D : 0-> Decrement , 1-> Increment
 * 2- BIT0 SH  : 0-> Shift OFF , 1-> Shift ON
 */
#define LCD_U8_ENTRY_MDE 0b00000110

#define LCD_U8_DISP_CLEAR 0b00000001
#define LCD_U8_RETURN_HOME 0b00000010

#define CGRAM 0x40
#define DDRAM_ROW0 0x80
#define DDRAM_ROW1 0xC0

void LCD_vdSendCmd(u8 LOC_u8Command);
void LCD_vdSendChar(u8 LOC_u8Char);
void LCD_vdInitialization(void);
void LCD_vdWriteString(u8 *LOC_u8Ptr);
void LCD_vdStringPostion (u8 row, u8 pos, u8 *LOC_u8Ptr);/* Send string to LCD with xy position */
void LCD_vdClear();
void LCD_vdGotoDDRAM(u8 row, u8 pos);
void LCD_vdSendDataoCGRAM(u8*ptr);
void LCD_vdWriteNum(u32 num);
void LCD_vdWriteFloatNum(f32 num);
void LCD_vdReturnHome();
void LCD_u8BusyFlag();
#endif /* LCD_INTERFACE_H_ */
