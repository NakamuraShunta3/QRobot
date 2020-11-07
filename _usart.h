/*
 * _usart.h
 *
 * Created: 2020/01/28 13:50:35
 *  Author: ohs80177
 */ 


#ifndef _USART_H_
#define _USART_H_

#include "system.h"
#include "time.h"

#define _USART_OK_ 0
#define	_USAR_NG_ -1


#define FOSC 16000000 /* MCUｸﾛｯｸ周波数 */
#define BAUD 9600 /* 目的USARTﾎﾞｰﾚｰﾄ速度 */
#define MYUBRR 25//FOSC/16/BAUD-1 /* 目的UBRRn値 */

void USART_Transmit(unsigned char data);

void USART_Init(void);

void usart_print(char* Message, ...);

#endif /* _USART_H_ */