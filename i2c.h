/*
 * i2c.h
 *
 * Created: 2020/01/01 21:07:20
 *  Author: ohs80177
 */ 


#ifndef I2C_H_
#define I2C_H_

#define		START	0x08		//スタート状態値
#define		RECEIVE	0x60		//自分あての受信状態値

#define		MT_SLA_ACK	0x18	//アドレス:SLA_Wを正常送信チェック値
#define		MT_DATA_ACK	0x28	//データを正常送信チェック値

#define		_I2C_SEND_OK_　0		//送信失敗
#define		_I2C_SEND_NG_　-1		//送信失敗
#define		I2C_OPEN TWCR = ( 1<< TWINT )| ( 1<< TWSTO )| ( 1<< TWEN )	//I2C停止条件送出　バスの開放	

#include<avr/io.h>								/* IO関連ヘッダ				  */
#include<avr/interrupt.h>						/* 割り込み関連ヘッダ		  */
#include "system.h"
#include "time.h"

void i2c_M_init();
void i2c_Adds_W(unsigned char adds);
void i2c_Data_W(unsigned char data);
void i2c_1byte_W(unsigned char adds, unsigned char data);
void i2c_2byte_W(unsigned char d_adds,unsigned char r_adds, unsigned char data);
void i2c_Open();
void led();


#endif /* I2C_H_ */