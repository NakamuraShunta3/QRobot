/*
 * AD.h
 *
 * Created: 2020/02/16 0:06:08
 *  Author: ohs80177
 */ 


#ifndef AD_H_
#define AD_H_
#include "system.h"
#include "_usart.h"
#include <math.h>
#define PI 3.141592653589793
#define VCC 5.0
ULNG AD_conversion(UCHR pin);
float degree(float Rs,float Ls);
float Angle_to_wall();



#endif /* AD_H_ */