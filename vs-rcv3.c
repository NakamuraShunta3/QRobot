/*
 * vs_rcv3.c
 *
 * Created: 2020/02/10 13:23:47
 *  Author: ohs80177
 */ 
#include "vs-rcv3.h"
 volatile UCHR pad_dat[6] = {0,0,0,0,0,0};
const ConEnt[] = {0x01,0x43,0x00,0x01,0x00,0x00,0x00,0x00,0x00};
/* -------------------------------------------------------------------------- */
/* 関数名		：Vs_rcv_init												  */
/* 機能概要		：Vs_rcvにspi通信するための初期化							  */
/* 引数			：void														  */
/* 戻り値		：void														  */
/* 作成日		：2020/02/10	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
void Vs_rcv_init(void)
{
	/* SPI通信条件設定 */
	SPCR = 0x00;
	SPCR = (1<<SPE) | (1<<DORD) | (1<<MSTR);
	SPCR |= (1<<CPOL) |(1<<SPR1)|(1<<SPR0)| _BV(CPHA);
	//SPE = SPI通信許可, DORD = データ順(LSB), MSTR = 主装置選択
	//CPOL = SCK極性選択, CPHA = SCK位相選択, SPR1,0=クロック選択(128分周)
	
	/* 通信ポート設定 */
	DDRB = 0b00101100;
	
	PORTB |= _BV(PB4);
}

/* -------------------------------------------------------------------------- */
/* 関数名		：Vs_rcv_transmit											  */
/* 機能概要		：Vs_rcvに1byteの送受信を行う								  */
/* 引数			：UCHR tdata		:	送信するデータ						  */
/* 戻り値		：UCHR				:	受信データ							  */
/* 作成日		：2020/02/10	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
UCHR Vs_rcv_transmit(UCHR tdata)
{
	/* 出力データセット */
	SPDR = tdata;
	
	/*	受信・送信待機 */
	while(!(SPSR & (1<<SPIF)));
	wait_10us(2);
	
	/* 受信データリターン */
	return SPDR;
}

/* -------------------------------------------------------------------------- */
/* 関数名		：Vs_rcv_transmit											  */
/* 機能概要		：Vs_rcvからボタンデータ取得する							  */
/* 戻り値		：UCHR				:	受信データ							  */
/* 作成日		：2020/02/10	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
SINT Vs_rcv_get()
{
	SCHR cnt = 0;		//ボタンカウント
	
	/*機器選択*/
	PORTB &= ~_BV(PB2);
	
	/* ボタンデータ取得用ヘッダ送信 */
	Vs_rcv_transmit(0x01);
	Vs_rcv_transmit(0x42);
	Vs_rcv_transmit(0x00);
	
	/* ボタンデータ取得 */
	for( cnt=0; cnt<6; cnt++)
	{
		pad_dat[cnt] = Vs_rcv_transmit(0x00);
		wait_10us(2);
	}
	
	/* エンター処理 */
	for( cnt=0; cnt<9; cnt++)
	{
		Vs_rcv_transmit((UCHR)ConEnt[cnt]);
		usart_print("%d,",(int)ConEnt[cnt]);
		wait_10us(2);
	}
	
	/* 機器選択解除 */
	PORTB |= _BV(PB2);
	
	
	wait_10us(2);
	return 0;
}