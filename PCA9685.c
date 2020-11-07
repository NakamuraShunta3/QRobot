/*
 * PCA9685.c
 *
 * Created: 2020/01/02 20:16:58
 *  Author: ohs80177
 */ 
#include "PCA9685.h"

UCHR pca_adds;


/* -------------------------------------------------------------------------- */
/* 関数名		：Pac_pwm_pott												  */
/* 機能名		：pwm出力レジスタ取得										  */
/* 機能概要		：pwm出力レジスタ取得します。								  */
/* 引数			：UCHR pot		 ：pwm出力ポート番号						  */
/* 戻り値		：SCHR			 ：pwm出力レジスタ番号						  */
/* 作成日		：2020/01/19	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
SCHR Pac_pwm_pot(UCHR pot)
{
	return 0x06 + 4 * pot;
}

UCHR Angle_correction(UCHR adds, UCHR freq)
{
	SLNG box = freq;
	
	switch(adds)
	{
		case 2:
		box = freq + 25;
		break;
	
		break;
		
		case 4:
		box = freq - 10;
		break;
		
		case 4 + 2:
		box = freq +10;
		break;
	
		break;
		
		case 8 + 1:
		box = freq - 7;
		break;
		
		case 8 + 2:
		box = freq + 10;
		break;
		case 12:
		box = freq +10;
		break;
		case 12 + 1:
		box = freq - 10;
		break;
		
		case 12 + 2:
		box = freq + 0;
		break;
	}
		if(box > 180)
		{
			box = 180;
		}
		else
		if(box < 0)
		{
			box = 0;
		}
	
		
		
		
		return (UCHR)box;
	
}

/* -------------------------------------------------------------------------- */
/* 関数名		：Pac_init													  */
/* 機能名		：PCA9685初期設定											  */
/* 機能概要		：PCA9685を初期設定します。									  */
/* 引数			：UCHR adds		 ：	PCA9685アドレス							  */
/*				：UCHR freq		 ：	pwm出力周波数							  */
/* 戻り値		：SCHR			 ：											  */
/* 作成日		：2020/01/19	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
SCHR Pac_init(UCHR adds,UCHR freq )
{
	if( 100 < freq )
	{
		return _PCA_NG_;
	}
	float freq2 = 25000000/4096/freq;
	pca_adds = adds;
	
	
	/* sleepを設定 */
	i2c_M_init();
	i2c_Adds_W(adds);
	i2c_Data_W(_PCA_MODE1_);
	i2c_Data_W(_PCA_SLEEP_ON_);
	I2C_OPEN;
	
	/* pwm周波数設定 */
	i2c_M_init();
	i2c_Adds_W(adds);
	i2c_Data_W(_PCA_PRESCALE_);
	i2c_Data_W(((UCHR)freq2) - 1);
	I2C_OPEN;
	
	/* sleepを停止 */
	i2c_M_init();
	i2c_Adds_W(adds);
	i2c_Data_W(_PCA_MODE1_);
	i2c_Data_W(_PCA_SLEEP_OFF_);
	I2C_OPEN;
	
	return _PCA_OK_;
}

/* -------------------------------------------------------------------------- */
/* 関数名		：Pac_pwm_out												  */
/* 機能名		：PCA9685pwm出力											  */
/* 機能概要		：PCA9685の指定のポートにｐｗｍ出力します。					  */
/* 引数			：UCHR pot		 ：	pwm出力ポート							  */
/*				：float deg 	 ：	回転角度								  */
/* 戻り値		：SCHR			 ：											  */
/* 作成日		：2020/01/19	中村　俊太		新規作成					  */
/* -------------------------------------------------------------------------- */
SCHR Pac_pwm_out(UCHR pot, float deg)
{
	if(16 < pot || 180 <= deg || 1 > deg)
	{
		return _PCA_NG_;
	}
	deg = Angle_correction(pot,deg);
	USHT PwmOff = ((float)(deg/180)*(_PCA_SERVO_MAX_ - _PCA_SERVO_MIN_)) + _PCA_SERVO_MIN_;
	UCHR PwmOff_L = PwmOff >> 8;
	UCHR PwmOff_H = (PwmOff << 8)>>8;
	ULNG i;
	UCHR* box = &PwmOff;
	
	i2c_M_init();
	i2c_Adds_W(pca_adds);
	
	
	PwmOff_L = PwmOff >> 8;
	PwmOff_H = (PwmOff << 8)>>8;
	
	
	i2c_Data_W(Pac_pwm_pot(pot));
	
	
	
	/*pwmON*/
	i2c_Data_W(0x00);
	i2c_Data_W(0x00);
	
	/*pwmOFF*/
	i2c_Data_W(PwmOff_H);
	i2c_Data_W(PwmOff_L);
	wait_10us(5);
	I2C_OPEN;
	return _PCA_OK_;
	
}

