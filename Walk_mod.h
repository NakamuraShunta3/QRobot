/*
 * Walk_mod.h
 *
 * Created: 2020/02/17 13:30:59
 *  Author: ohs80177
 */ 


#ifndef WALK_MOD_H_
#define WALK_MOD_H_

#define _WALL_DISTANCE_ 25.0

#include "i2c.h"
#include "PCA9685.h"
//#include "_spi.h"
#include "_usart.h"
#include "Quad_Robot.h"
#include "I2c_Lcd.h"
#include "AD.h"


UCHR Pad_dat_Get_1();
UCHR Pad_dat_Get_2();
void Control_mode(UCHR bcheck ,UCHR bcheck2);
void out_walk();


#endif /* WALK_MOD_H_ */