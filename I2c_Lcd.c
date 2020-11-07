/*
 * I2c_Lcd.c
 *
 * Created: 2020/02/06 13:36:09
 *  Author: ohs80177
 */ 

#include "I2c_Lcd.h"
void lcd_putc(char Message)
{
	if(Message == '\n')
	{
		i2c_2byte_W(0x7C,0x00,0xC0);
	}
	else
	{
		i2c_2byte_W(0x7C,0x40,Message);
	}
}
void lcd_pfint(char* Message, ... )
{
	int i = 0;
	SCHR    scStr[256];							/* 可変長文字列格納用		  */
	va_list args;								/* 可変長引数処理用			  */
	
	/* 可変長引数変換取得 --------------------------------------------------- */
	memset( &scStr[0], 0, sizeof( scStr ));
	
	va_start( args, Message );					/* 可変長引数処理開始		  */
	vsprintf( scStr, Message, args );			/* 可変長引数取得			  */
	va_end( args );								/* 可変長引数処理終了 		  */
	
	for(i = 0; scStr[i] != '\0'; i++)
	{
		if(scStr[i] == '\n')
		{
			i2c_2byte_W(0x7C,0x00,0xC0);
		}
		else
		{
			i2c_2byte_W(0x7C,0x40,scStr[i]);
		}
		
	}
	wait_1ms(4);
	return;
	
}

void lcd_clear()
{
	i2c_2byte_W(0x7C,0x00,0x01);
}
void lcd_init(){
	
	wait_1ms(40);
	i2c_2byte_W(0x7C,0x00,0x38);
	wait_10us(5);
	
	i2c_2byte_W(0x7C,0,0x39);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x14);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x70);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x56);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x6C);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x38);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x0C);
	wait_10us(5);
	i2c_2byte_W(0x7C,0,0x01);
	wait_1ms(4);
	
}

