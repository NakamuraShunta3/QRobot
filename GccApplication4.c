/* -------------------------------------------------------------------------- 	*/
/* Qrobot */
/*  四足歩行ロボットをコントローラーを使い操作する。							*/
/* -------------------------------------------------------------------------- */
/* 番号					更新履歴			日付			氏名			  */
/* -------------------------------------------------------------------------- */
/* 000000	新規作成						2020/1/1		中村　俊太		  */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* include定義																  */
/* -------------------------------------------------------------------------- */

#include "i2c.h"
#include "PCA9685.h"
#include "Quad_Robot.h"
#include "I2c_Lcd.h"
#include "AD.h"
#include "Walk_mod.h"

//状態値
volatile unsigned long cnt;
extern volatile UCHR pad_dat[];
extern float Rs2 ;
extern float Ls2 ;

void init();
void check();

int main(){
	UCHR button1= 0;			//押されたボタンの情報1
	UCHR button2= 0;			//押されたボタンの情報2
	
	/* 通信・タイマ初期化 */
	init();
	
	/* 3秒待機　*/
	wait_1ms(3000);
	
	/* 各関節を初期位置に移動 */
	Quad_init_pos();
	wait_1ms(1000);
	
	while(1){
		button1 = 0;
		button2= 0;
		/*ゲームパッドデータの取得*/
		button1 = Pad_dat_Get_1();
		button2 = Pad_dat_Get_2();
	
		/* 自動歩行モードに移行するか？ */
		if(button1 == 254)
		{
			out_walk();
		}
	
		/* コントロールモード */
		Control_mode(button1,button2);
		Pad_dat_Get_1();
	
	}
	
}






void init(){
	
	wait_10us_init();
	USART_Init();
	Vs_rcv_init();
	sei();
}

void check(){
	
	char i= 0;
	char bcnt= 0;
	UCHR bcheck= 0;
	ULNG ck =0;
	float deg;
		
	while(1)
	{
		 Pad_dat_Get_1();
		wait_1ms(250);
		Pac_pwm_out(12+0,90);
		Pac_pwm_out(12+2,90);
		Pac_pwm_out(12+1,90);
		wait_1ms(250);
		Pac_pwm_out(12+0,40);
		Pac_pwm_out(12+2,40);
		Pac_pwm_out(12+1,40);
		Vs_rcv_get();
		for(i = 0; i < 6; i++)
		{
			usart_print("%d,",pad_dat[i]);
		}
		usart_print("\n");
	}
	
	/*
	while(1)
	{
		Vs_rcv_get();
		usart_print("%d\n",pad_dat[0]);
	}
	*/
	/*
	while(1){
		deg = Angle_to_wall();
		usart_print("%f,%f,",Rs2,Ls2);
		usart_print("%f\n",deg);
		wait_1ms(100);
	}
	*/
}
