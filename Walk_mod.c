/*
 * Walk_mod.c
 *
 * Created: 2020/02/17 13:32:13
 *  Author: ohs80177
 */ 
#include "AD.h"
#include "Walk_mod.h"
extern volatile UCHR pad_dat[];
extern float Rs2 ;
extern float Ls2 ;
UCHR Pad_dat_Get_1()
{
	UCHR bcheck = 0;
	Vs_rcv_get();
	bcheck = pad_dat[0];
	//usart_print("%d,",bcheck);
	/* 誤動作防止 */
	/*
	if(pad_dat[0] != 255)
	{
		bcheck = pad_dat[0];
		
		wait_1ms(5);
		Vs_rcv_get();
		if(pad_dat[0] != bcheck)
		{
			bcheck = 0;
		}
		
		usart_print("%d\n");
	}
	else
	{
		bcheck = 0;
	}
	*/
	return bcheck;
}

UCHR Pad_dat_Get_2()
{
	UCHR bcheck = 0;
	//Vs_rcv_get();
	bcheck = pad_dat[1];
	
	return bcheck;
}
void Control_mode(UCHR bcheck ,UCHR bcheck2)
{
char i= 0;
char bcnt= 0;
ULNG ck =0;
float deg;

/*ボタン取得*/
usart_print("%d,%d,\n",(int)bcheck,pad_dat[0]);
//wait_1ms(100);
/* ボタン誤動作防止 */

/* 各歩行動作 */
if(bcheck == 239)
{
	Quad_adv();
}
else if(127== bcheck)
{
	
	Quad_Left_rotation();
}
else if(223 == bcheck)
{
	Quad_Right_rotation();
}
else if(191 == bcheck)
{
	Quad_back();
}else if(223 == bcheck2)
{
	Quad_Greeting();
}
//usart_print("%d,\n",pad_dat[0]);
wait_1ms(100);
	return;
}
void out_walk(){
	int i = 0;
	float deg;
	UCHR bot = 0;
	
	while(bot != 247)
	{
		/*0回避*/
		for(i = 0 ; i < 5
		; i ++){
		bot = Pad_dat_Get_1();

		}

		if(bot == 247)
		{
			
		}
		else
		{
			
		
			deg = Angle_to_wall();
			usart_print("%f.%f\n",Rs2,Ls2);
			
			
			if(Rs2 <=_WALL_DISTANCE_ ||  Ls2 <=_WALL_DISTANCE_ )
			{
				if(deg > 90){
					
					for(i = 0; i < 4;i++)
					{
						Quad_Left_rotation();
					}
				}
				else
				{
					for(i = 0; i < 4;i++)
					{
						Quad_Right_rotation();
					}
				}
			}
			else
			{
				Quad_adv();
			}
			
			wait_1ms(100);
			
			
			
		}
		
	}
}