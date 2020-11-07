/*
 * Quad_Robot.c
 *
 * Created: 2020/02/06 13:17:52
 *  Author: ohs80177
 */ 

#include "Quad_Robot.h"
#include "time.h"

SCHR flg = 1;
/* -------------------------------------------------------------------------- */
/* 関数名		：Quad_your_legs											  */
/* 機能概要		：脚を初期位置に移動させる									  */
/* 引数			：UCHR	cNam	　:		1>左前足　２＞左後ろ足				  */
/*										3>右後ろ脚　4>右前足				  */
/* 引数			：UCHR*	deg			:	選択した脚の角度配列				  */
/* 戻り値		：SCHR			 ：											  */
/* 作成日		：2020/01/19	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
SCHR Quad_your_legs(UCHR cNam,UCHR*	deg )
{
	SCHR cnt = 0;
	/*　引数チェック　*/
	if(cNam > 0)
	{
		return -1;
	}
	if(deg  == NULL)
	{
		return -1;
	}
	
	cNam--;
	
	/*  cNamの脚を各関節deg度回転　*/
	for(cnt = 0;cnt < 3;cnt++)
	{
		SERVO_OUT(cnt+(4*cNam),deg[0]);
	}
	
	
	return 0;
}


/* -------------------------------------------------------------------------- */
/* 関数名		：Quad_init_pos												  */
/* 機能概要		：脚を初期位置に移動させる									  */
/* 戻り値		：SCHR			 ：											  */
/* 作成日		：2020/01/19	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */


void Quad_init_pos(){
	flg = 1;
	Pac_init(0x80,60);
	
	/*
	//左まえ
	Pac_pwm_out(0,90);
	Pac_pwm_out(1,90);
	wait_1ms(500);
	Pac_pwm_out(2,90);
	
	//左後ろ
	Pac_pwm_out(4+0,90);
	wait_1ms(500);
	Pac_pwm_out(4+1,90);
	Pac_pwm_out(4+2,90);
	wait_1ms(500);
	
	//右後ろ
	Pac_pwm_out(8+0,90);
	Pac_pwm_out(8+1,90);
	wait_1ms(500);
	Pac_pwm_out(8+2,90);
	
	//右前
	Pac_pwm_out(12+0,90);
	wait_1ms(500);
	Pac_pwm_out(12+1,90);
	Pac_pwm_out(12+2,90);
	wait_1ms(2000);
	
	*/
	//while(1){};
	//*****************
	/*
	Pac_pwm_out(0,40);
	Pac_pwm_out(1,40);
	wait_1ms(500);
	Pac_pwm_out(2,130);

	Pac_pwm_out(4+0,40);
	wait_1ms(500);
	Pac_pwm_out(4+1,40);
	Pac_pwm_out(4+2,40);
	wait_1ms(500);
	
	Pac_pwm_out(8+0,40);
	Pac_pwm_out(8+1,40);
	wait_1ms(500);
	Pac_pwm_out(8+2,90);
	
	Pac_pwm_out(12+0,40);
	wait_1ms(500);
	Pac_pwm_out(12+1,40);
	Pac_pwm_out(12+2,90);
	wait_1ms(500);
	
	*/
	
	SERVO_OUT(0,5);
	SERVO_OUT(1,120);
	SERVO_OUT(2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(4+0,5);
	SERVO_OUT(4+1,120);
	SERVO_OUT(4+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(8+0,5);
	SERVO_OUT(8+1,120);
	SERVO_OUT(8+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(12+0,5);
	SERVO_OUT(12+1,120);
	SERVO_OUT(12+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	//**************
	
	SERVO_OUT(0,20);
	SERVO_OUT(1,60);
	SERVO_OUT(2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	SERVO_OUT(4+0,20);
	SERVO_OUT(4+1,60);
	SERVO_OUT(4+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(8+0,20);
	SERVO_OUT(8+1,60);
	SERVO_OUT(8+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(12+0,20);
	SERVO_OUT(12+1,60);
	SERVO_OUT(12+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	//*********************
	
	SERVO_OUT(0,40);
	SERVO_OUT(1,40);
	SERVO_OUT(2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	SERVO_OUT(4+0,40);
	SERVO_OUT(4+1,40);
	SERVO_OUT(4+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(8+0,40);
	SERVO_OUT(8+1,40);
	SERVO_OUT(8+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	SERVO_OUT(12+0,40);
	SERVO_OUT(12+1,40);
	SERVO_OUT(12+2,90);
	wait_1ms(QUAD_ROBOT_WEI_);
	
	//************************
	SERVO_OUT(0,40);
	SERVO_OUT(1,40);
	SERVO_OUT(2,130);
	wait_1ms(QUAD_ROBOT_WEI_);
	SERVO_OUT(4+0,40);
	SERVO_OUT(4+1,40);
	SERVO_OUT(4+2,40);
	wait_1ms(QUAD_ROBOT_WEI_);
	

}


void Quad_adv()
{
	
	if(flg)
	{
		
		
		/*
		//初期位置に移動
		Pac_pwm_out(0,40);
		Pac_pwm_out(1,40);
		Pac_pwm_out(2,130);

		Pac_pwm_out(4+0,40);
		Pac_pwm_out(4+1,40);
		Pac_pwm_out(4+2,40);
		
		Pac_pwm_out(8+0,40);
		Pac_pwm_out(8+1,40);
		Pac_pwm_out(8+2,90);
		
		Pac_pwm_out(12+0,40);
		Pac_pwm_out(12+1,40);
		Pac_pwm_out(12+2,90);
		wait_1ms(500);
		*/
		//**************
		
		SERVO_OUT(0,40);
		SERVO_OUT(1,120);
		SERVO_OUT(2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//****************
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		
	
		//******************
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,90);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,90);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,40);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//**************
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,120);
		SERVO_OUT(8+2,120);
		wait_1ms(QUAD_ROBOT_WEI_);
		//**************
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,120);
		wait_1ms(QUAD_ROBOT_WEI_);
		flg = 0;
		
	}
	else
	{
		//******************************************

		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,120);
		SERVO_OUT(12+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*************
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//***************
		
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,130);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,130);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,90);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,90);
		wait_1ms(QUAD_ROBOT_WEI_);
		// **************
		
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,120);
		SERVO_OUT(4+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		flg = 1;
	}
}


void Quad_back()
{
	
	if(flg)
	{
		
		//**************
		
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,120);
		SERVO_OUT(4+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//****************
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		
	
		//******************
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,90);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,90);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,130);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,120);
		wait_1ms(QUAD_ROBOT_WEI_);
		//**************
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,120);
		SERVO_OUT(12+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//**************
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		flg = 0;
		
	}
	else
	{
		//******************************************

		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,120);
		SERVO_OUT(8+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*************
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//***************
		
		SERVO_OUT(0,50);
		SERVO_OUT(1,40);
		SERVO_OUT(2,40);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,40);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,90);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,90);
		wait_1ms(QUAD_ROBOT_WEI_);
		// **************
		
		SERVO_OUT(0,40);
		SERVO_OUT(1,120);
		SERVO_OUT(2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		flg = 1;
	}
}

SCHR Quad_Left_rotation()
{

	if(flg)
	{
		//左後ろ
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,120);
		SERVO_OUT(4+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*********************
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		//右前
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,120);
		SERVO_OUT(8+2,170);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,170);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*********************
		
		
		
		//左まえ
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,90);
		
		//左後ろ
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,90);

		
		//右後ろ
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,130);
		
		//右前
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,40);
		flg = 0;
	}
	else
	{
		//右前
		SERVO_OUT(12+0,40-10);
		SERVO_OUT(12+1,120);
		SERVO_OUT(12+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*********************
		SERVO_OUT(12+0,40-10);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,130);
		wait_1ms(QUAD_ROBOT_WEI_);
		//左前
		SERVO_OUT(0+0,40);
		SERVO_OUT(0+1,120);
		SERVO_OUT(0+2,170);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		SERVO_OUT(0+0,40);
		SERVO_OUT(0+1,40);
		SERVO_OUT(0+2,170);
		wait_1ms(QUAD_ROBOT_WEI_);
		//*********************
		
		
		

	//**************************
	
	SERVO_OUT(0,40);
	SERVO_OUT(1,40);
	SERVO_OUT(2,130);

	SERVO_OUT(4+0,40);
	SERVO_OUT(4+1,40);
	SERVO_OUT(4+2,40);
	
	SERVO_OUT(8+0,40);
	SERVO_OUT(8+1,40);
	SERVO_OUT(8+2,90);
	
	SERVO_OUT(12+0,40);
	SERVO_OUT(12+1,40);
	SERVO_OUT(12+2,90);
	
		flg = 1;
	}
	
	wait_1ms(QUAD_ROBOT_WEI_);
		return 0;
	
}

SCHR Quad_Right_rotation()
{
	
	if(flg)
	{
		//左前足
		SERVO_OUT(0,40);
		SERVO_OUT(1,120);
		SERVO_OUT(2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		//左前足
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,120);
		SERVO_OUT(12+2,10);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,10);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		//***********
		
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,90);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,90);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,120);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		//**************
	
		flg = 0;
		
	}
	else
	{
		//左後ろ足
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,120);
		SERVO_OUT(8+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,40);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		//右後ろ足
		
		//左後ろ足
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,120);
		SERVO_OUT(4+2,20);
		wait_1ms(QUAD_ROBOT_WEI_);
		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,20);
		wait_1ms(QUAD_ROBOT_WEI_);
		
		
		//************
		
		SERVO_OUT(0,40);
		SERVO_OUT(1,40);
		SERVO_OUT(2,130);

		SERVO_OUT(4+0,40);
		SERVO_OUT(4+1,40);
		SERVO_OUT(4+2,40);
		
		SERVO_OUT(8+0,40);
		SERVO_OUT(8+1,40);
		SERVO_OUT(8+2,90);
		
		SERVO_OUT(12+0,40);
		SERVO_OUT(12+1,40);
		SERVO_OUT(12+2,90);
		wait_1ms(QUAD_ROBOT_WEI_);
		flg = 1;
	}
	
}

SCHR Quad_Greeting()
{
	int i = 0;
	if(flg)
	{
		//左前
		SERVO_OUT(0+0,20);
		SERVO_OUT(0+1,150);
		SERVO_OUT(0+2,40);
		wait_1ms(300);
		for(i = 0; i < 2 ;i++)
		{
			//左前
			SERVO_OUT(0+0,20);
			SERVO_OUT(0+1,150);
			SERVO_OUT(0+2,40);
			wait_1ms(200);
			//左前
			SERVO_OUT(0+0,90);
			SERVO_OUT(0+1,150);
			SERVO_OUT(0+2,40);
			wait_1ms(250);
			
			SERVO_OUT(0+0,90);
			SERVO_OUT(0+1,120);
			SERVO_OUT(0+2,40);
			wait_1ms(200);
			SERVO_OUT(0+0,20);
			SERVO_OUT(0+1,120);
			SERVO_OUT(0+2,40);
			wait_1ms(250);
		}
		wait_1ms(300);
			SERVO_OUT(0,40);
			SERVO_OUT(1,40);
			SERVO_OUT(2,130);

			SERVO_OUT(4+0,40);
			SERVO_OUT(4+1,40);
			SERVO_OUT(4+2,40);
			
			SERVO_OUT(8+0,40);
			SERVO_OUT(8+1,40);
			SERVO_OUT(8+2,90);
			
			SERVO_OUT(12+0,40);
			SERVO_OUT(12+1,40);
			SERVO_OUT(12+2,90);
			wait_1ms(250);
	}
	else
	{
		for(i = 0; i < 2 ;i++)
		{
			//右前
			SERVO_OUT(12+0,90);
			SERVO_OUT(12+1,150);
			SERVO_OUT(12+2,120);
			wait_1ms(500);
			
			SERVO_OUT(12+0,20);
			SERVO_OUT(12+1,120);
			SERVO_OUT(12+2,120);
			wait_1ms(500);
		}
		
				//左まえ
				SERVO_OUT(0,40);
				SERVO_OUT(1,40);
				SERVO_OUT(2,90);
				
				//左後ろ
				SERVO_OUT(4+0,40);
				SERVO_OUT(4+1,40);
				SERVO_OUT(4+2,90);

				
				//右後ろ
				SERVO_OUT(8+0,40);
				SERVO_OUT(8+1,40);
				SERVO_OUT(8+2,130);
				
				//右前
				SERVO_OUT(12+0,40);
				SERVO_OUT(12+1,40);
				SERVO_OUT(12+2,40);
	}
}