/*
 * I2c_Lcd.h
 *
 * Created: 2020/02/06 13:35:35
 *  Author: ohs80177
 */ 


#ifndef I2C_LCD_H_
#define I2C_LCD_H_

#include "i2c.h"
#include "system.h"

void lcd_putc(char Message);
void lcd_pfint(char* Message, ... );
void lcd_clear();
void lcd_init();



#endif /* I2C_LCD_H_ */