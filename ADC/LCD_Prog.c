/*
 * LCD_Prog.c
 *
 *  Created on: Apr 2, 2021
 *      Author: Abdelrhman Walaa
 */
#include "avr\delay.h"
#include "Types.h"
#include "DIO_Interface.h"
#include "LCD_Interface.h"

#define F_CPU 8000000UL

void LCD_vdSendCmd(u8 LOC_u8Command)
{
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_LOW); //command
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN,PIN_LOW); //write
	DIO_vdSetPortValue(LCD_U8_DATA_PORT,LOC_u8Command); //Put on data port
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_High); //Enable pin
	_delay_ms(1); //Delay
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_LOW); //Disable pin
	_delay_ms(1);
}


void LCD_vdInitialization(void)
{

	_delay_ms(50);
	LCD_vdSendCmd(LCD_U8_FUNC_SET);
	_delay_ms(10);
	LCD_vdSendCmd(LCD_U8_DISP_ON_OFF_CTRL);
	_delay_ms(10);
	LCD_vdSendCmd(LCD_U8_DISP_CLEAR);
	_delay_ms(10);
	LCD_vdSendCmd(LCD_U8_ENTRY_MDE);
	_delay_ms(10);
}

void LCD_vdSendChar(u8 LOC_u8Char)
{
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_High);
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN,PIN_LOW);
	DIO_vdSetPortValue(LCD_U8_DATA_PORT, LOC_u8Char);
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_High);
	_delay_ms(1);
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_LOW);
	_delay_ms(1);
}


void LCD_vdWriteString(u8 *LOC_u8Ptr)
{
	while(*LOC_u8Ptr != '\0')
	{
		LCD_vdSendChar(*LOC_u8Ptr);
		LOC_u8Ptr++;
	}
}

void LCD_vdStringPostion (u8 row, u8 pos, u8 *LOC_u8Ptr)
{
	if (row == 0)
		LCD_vdSendCmd((pos & 0x0F)|0x80);	/* Command of first row and required position<16 */
	else if (row == 1 && pos<16)
		LCD_vdSendCmd((pos & 0x0F)|0xC0);	/* Command of first row and required position<16 */
	LCD_vdWriteString(LOC_u8Ptr);
}

void LCD_vdClear()
{
	LCD_vdSendCmd (0x01);		/* clear display */
}

void LCD_vdSendDataoCGRAM(u8* ptr)
{
	LCD_vdSendCmd(CGRAM);
	for(u8 x=0; x<6; x++)
	{
		LCD_vdSendChar(*ptr);
		ptr++;
	}
}

void LCD_vdGotoDDRAM(u8 row, u8 pos)
{

	if (row == 0 && pos<16)
		LCD_vdSendCmd((pos & 0x0F)|DDRAM_ROW0);
	else if (row == 1 && pos<16)
		LCD_vdSendCmd((pos & 0x0F)|DDRAM_ROW1);
}

/*void LCD_vdWriteNum(u32 num)
{
	u32 reverse=0;
	u8 reminder;
	while(num !=0)
			{
				reminder = num%10;
				reverse = reverse*10+reminder;
				num/=10;
			}
			while(reverse !=0)
			{
				reminder = reverse%10;
				LCD_vdSendChar(reminder+'0');
				reverse/=10;
			}
}*/
void LCD_vdWriteNum(u32 num)
{
	u32 reverse=0;
	u8 reminder=0;
	if(num>=10)
	{
		while(num !=0)
		{
			reminder = num%10;
			reverse = reverse*10+reminder;
			num/=10;
		}
		while(reverse !=0)
		{
			reminder = reverse%10;
			LCD_vdSendChar(reminder+'0');
			reverse/=10;
		}
	}
	else
	{
		LCD_vdSendChar(num+'0');
	}
}

void LCD_vdWriteFloatNum(f32 num)
{
	u16 floatNum=0, number=0, it=0;
	if(num == (u32)num)
	{
		LCD_vdWriteNum(num);
	}
	else
	{
		while(num != (u32)num)
		{
			number= num*10;
			it++;
		}
		LCD_vdWriteNum(num);
		LCD_vdSendChar(',');
		floatNum=number-(((u32)num)*it*10);
		LCD_vdWriteNum(floatNum);

	}
}

void LCD_vdReturnHome()
{
	LCD_vdSendCmd (LCD_U8_RETURN_HOME);

}

void LCD_u8BusyFlag()
{
	DIO_vdSetPintDirection(LCD_U8_DATA_PORT,PIN7, PIN_INPUT);
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RS_PIN,PIN_LOW); //command
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_RW_PIN, PIN_High); //Read
	DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_High);
	DIO_vdSetPortDirection(PortB, PORT_OUTPUT);
	while(DIO_u8GetPinValue(LCD_U8_DATA_PORT,PIN7)==1)
	{
		DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_LOW);
		DIO_vdSetPinValue(LCD_U8_CTRL_PORT,LCD_U8_EN_PIN,PIN_High);
		DIO_vdSetPinValue(PortB, PIN0 ,PIN_High);
		//_delay_ms(1000);
	}
	DIO_vdSetPinValue(PortB, PIN0 ,PIN_LOW);
	//return returned;
}
