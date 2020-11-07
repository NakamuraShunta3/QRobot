/*
 * Quad_Robot.h
 *
 * Created: 2020/02/06 13:16:14
 *  Author: ohs80177
 */ 


#ifndef QUAD_ROBOT_H_
#define QUAD_ROBOT_H_
#include "system.h"
#include "PCA9685.h"
#include "time.h"

#define QUAD_ROBOT_OK_			0					//正常終了
#define QUAD_ROBOT_NG_			-1					//異常終了
#define QUAD_ROBOT_WEI_			250
#define SERVO_OUT(adds,degr) if(Pac_pwm_out(adds,degr) == _PCA_NG_){return QUAD_ROBOT_NG_;}

SCHR Quad_your_legs(UCHR cNam,UCHR*	deg );
void Quad_init_pos();
void Quad_adv();
void Quad_back();
SCHR Quad_Left_rotation();
SCHR Quad_Right_rotation();
SCHR Quad_Greeting();




#endif /* QUAD_ROBOT_H_ */