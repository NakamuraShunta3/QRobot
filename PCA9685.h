/*
 * PCA9685.h
 *
 * Created: 2020/01/02 20:17:12
 *  Author: ohs80177
 */ 


#ifndef PCA9685_H_
#define PCA9685_H_

#include "i2c.h"
#include "system.h"


#define _PCA_OK_			0					//正常終了
#define _PCA_NG_			-1					//異常終了
#define _PCA_MODE1_			0x00				//PCA9685_MODE1レジスタ
#define	_PCA_PRESCALE_		0xFE				//pwm設定レジスタ
#define	_PCA_SLEEP_ON_		0x31				//スリープモードON
#define	_PCA_SLEEP_OFF_		0x21				//スリープモードOFF
#define _PCA_SERVO_MIN_			150
#define _PCA_SERVO_MAX_			600

UCHR Angle_correction(UCHR adds, UCHR freq);
SCHR Pac_pwm_pot(UCHR);
SCHR Pac_init(UCHR, UCHR);
SCHR Pac_pwm_out(UCHR,float);





#endif /* PCA9685_H_ */