/*
 * AD.c
 *
 * Created: 2020/02/16 0:05:42
 *  Author: ohs80177
 */ 
#include "AD.h"

float Rs2 = 0;
float Ls2 = 0;

ULNG AD_conversion(UCHR pin)
{
	/* ピンの範囲チェック */
	DDRC  = 0x00;								/* Ａ／Ｄ設定				 */
	PORTC = 0x00;	
	DIDR0 = 0xFF;
	if(7 < pin)
	{
		return 1;
	}
	ULNG ulAD  = 0;				/* ＡＤ変換値				 */
	ADMUX = 0x00;								/* レジスタ初期化			 */
	ADMUX = ADMUX | 0x40;						/* 基準電圧の設定			 */
	ADMUX = ADMUX & 0xDF;						/* 右揃え					 */
	ADMUX = ADMUX & 0xF0;						/* チャンネルＡ初期化		 */
	ADMUX = ADMUX | pin;						//
	
	/* Ａ／Ｄ変換許可（ＡＤＣＳＲＡの８ｂｉｔ目を１）----------------------- */
	ADCSRA = ADCSRA | 0x80;					/* Ａ／Ｄ変換許可			 */
	ADCSRA = ADCSRA | 0x02;					// 分周１２８
	/* Ａ／Ｄ変換実行 */
	ADCSRA = ADCSRA | 0x40;					/* Ａ／Ｄ変換開始			 */
	while(( ADCSRA & 0x10 ) == 0x00 );		/* Ａ／Ｄ変換完了待ち		 */
	ADCSRA = ADCSRA | 0x10;					/* Ａ／Ｄ変換解除			 */

	/* Ａ／Ｄ変換値を取得(１０ｂｉｔ分取得)									*/
	ulAD = ADC;								/* Ａ／Ｄ変換値を取得			*/
	return ulAD;
}

float Angle_to_wall()
{
	Rs2 = 0;
	Ls2 = 0;
	float Rs = 0;
	float Ls = 0;

	int i = 0;

		for(i = 0; i< 50; i++){
	/*入力電圧測定*/
			Rs = VCC * ((float)AD_conversion(0)) / 1024.0;
			Ls = VCC *((float)AD_conversion(1)) / 1024.0;
	
			/*距離変換*/
			Rs = 26.549*pow(Rs,-1.2091); 
			Ls = 26.549*pow(Ls,-1.2091);

			Rs2=Rs2+Rs;
			Ls2=Ls2+Ls;
		}
		
		
		Rs2/=50.0;
		Ls2/=50.0;

return degree(Rs2,Ls2);
	
}

float degree(float Rs,float Ls)
{
	float tei = 0;
	float deg = 0;
	if(Rs >= Ls)
	{
		tei = Rs - Ls;
		deg = atan2(8,tei);
		deg = deg * (180.0 / PI);
		deg = 180 - deg;
	}
	else
	{
		tei = Ls - Rs;
		deg = atan2(8,tei);
		deg = deg * (180.0 / PI);
	}

		
	
	

	return deg;
	
}