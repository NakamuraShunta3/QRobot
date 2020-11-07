/*
 * vs_rcv3.h
 *
 * Created: 2020/02/10 13:23:30
 *  Author: ohs80177
 */ 


#ifndef VS-RCV3_H_
#define VS-RCV3_H_

#include "system.h"
#include "time.h"
#include "_usart.h"

#define _VS_RCV_OK_		0
#define _VS_RCV_NG_		-1

void Vs_rcv_init(void);
UCHR Vs_rcv_transmit(UCHR tdata);
void Vs_rcv_input();

#endif /* VS-RCV3_H_ */