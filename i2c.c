

#include "i2c.h"



void i2c_M_init()
{
	
	TWBR = 0xFF;	//分周
	
	
	/* I2C開始条件送出 */
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);	
	
	/* 結果待ち */
	while( !( TWCR & (1<< TWINT) ) );	
	wait_10us_init();
	
	/* 送信許可確認 */
	if ((TWSR & 0xF8) != START)
	{
		return 0;
	} 	
	return 0;
}

void i2c_Adds_W(unsigned char adds)
{
	TWDR = adds ;					// あて先アドレス設定
	
	/* アドレス送信開始 */
	TWCR = ( 1<< TWINT )| ( 1<< TWEN ) ;
	
	/* あて先アドレス送信完了待ち */
	while(  ! ( TWCR & ( 1<< TWINT ) ) );	
	wait_10us(5);
	
	/* 正常送信チェック */
	while(  ( TWSR & 0xF8 ) != MT_SLA_ACK );	
	wait_10us(5);
	return;
}

void i2c_Data_W(unsigned char data)
{
	
	
	TWDR = data;		//送信データセット
	
	/* 送信開始 */
	TWCR = ( 1<< TWINT )| ( 1<< TWEN ) ;
	
	/* 完了待ち */
	while(  ! ( TWCR & ( 1<< TWINT ) ) );
	wait_10us(5);
	
	/* データ 正常送信チェック */
	while(  ( TWSR & 0xF8 ) != MT_DATA_ACK );
	wait_10us(5);
	return;

}
void i2c_1byte_W(unsigned char adds, unsigned char data)
{
	i2c_M_init();
	
	/* スレーブアドレス送信 */
	i2c_Adds_W(adds);
	
	/* データ出力 */
	i2c_Data_W(data);
	wait_10us(5);
	
	/* I2C停止条件送出　バスの開放 */
	TWCR = ( 1<< TWINT )| ( 1<< TWSTO )| ( 1<< TWEN ) ;	
	return;
}

i2c_2byte_W(unsigned char d_adds,unsigned char r_adds, unsigned char data)
{
	i2c_M_init();
	
	/* スレーブアドレス送信 */
	i2c_Adds_W(d_adds);
	
	/*** データ出力 ***/
	/* 1バイト目 */
	i2c_Data_W(r_adds);
	/* 2バイト目 */
	i2c_Data_W(data);
	
	
	TWCR = ( 1<< TWINT )| ( 1<< TWSTO )| ( 1<< TWEN ) ;	//I2C停止条件送出　バスの開放
	wait_10us(5);
	return;
}

/*
void led()
{
	
	
	PORTB = 0x20;
	wait_10us(50000);
	PORTB = 0x00;
	wait_10us(50000);
	
}
*/
