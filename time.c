/*
 * time.c
 *
 * Created: 2020/01/02 19:46:31
 *  Author: ohs80177
 */ 
#include "time.h"

extern volatile unsigned long cnt;

void wait_10us( unsigned long time ){
	cnt = 0;
	TCNT1H = 0x00;
	TCNT1L = 0x00;
	while(time > cnt)
	{
		
	}
	return;
}

void wait_1ms(  unsigned long time)
{
	int i = 0;
	for(i = 0;i < time; i++)
	{
		wait_10us(100);
	}
	return;
}

void wait_10us_init()
{
	TCCR1A = 0x00;
	TCCR1B = 0x09;
	OCR1AH = 0x00;
	OCR1AL = 0xA0;  // 10usごとに割り込み
	TIMSK1  = 0x02;
	return;
}

/* -------------------------------------------------------------------------- */
/* タイマ1割り込み															  */
/* タイマ1の割り込みが発生するとこの関数が呼び出されます					  */
/* 一定時間ごとに呼ばれ、LED,PWM,フラグ制御などを行います					  */
/* -------------------------------------------------------------------------- */
/* 関数名		：ISR														  */
/* 機能名		：タイマ1割り込み処理										  */
/* 機能概要		：タイマ1の割り込みが発生するとこの関数が呼び出されます。	  */
/* 				：一定時間ごとに呼ばれ、LED,PWM,フラグ制御などを行います。	  */
/* 引数名		：SIG_OVERFLOW1		:タイマ1割り込みフラグ（固定）			  */
/* 戻り値		：VOID		:なし	:なし									  */
/* 作成日		：2012/11/21		桝井　隆治		新規作成				  */
/* -------------------------------------------------------------------------- */

ISR( TIMER1_COMPA_vect )
{
	cnt++ ;
}