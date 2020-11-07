/*
 * time.h
 *
 * Created: 2020/01/02 19:46:11
 *  Author: ohs80177
 */ 


#ifndef TIME_H_
#define TIME_H_
#include<avr/io.h>								/* IO関連ヘッダ				  */
#include<avr/interrupt.h>						/* 割り込み関連ヘッダ		  */

void wait_10us(  unsigned long );
void wait_1ms(  unsigned long );
void i2c_M_init();



#endif /* TIME_H_ */