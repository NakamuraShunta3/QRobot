/*
 * usart.c
 *
 * Created: 2020/01/28 13:51:34
 *  Author: ohs80177
 */ 

#include "_usart.h"
void USART_Init(void)
{
	UBRR0H = (unsigned char)(MYUBRR>>8); /* ﾎﾞｰﾚｰﾄ設定(上位ﾊﾞｲﾄ) */
	UBRR0L = (unsigned char)MYUBRR; /* ﾎﾞｰﾚｰﾄ設定(下位ﾊﾞｲﾄ) */
	UCSR0B = (1<<USBS0)|(3<<UCSZ00); /* ﾌﾚｰﾑ形式設定(8ﾋﾞｯﾄ,2停止ﾋﾞｯﾄ) */
	UCSR0B = (1<<RXEN0)|(1<<TXEN0); /* 送受信許可 */
}


void USART_Transmit(unsigned char data)
{
	while ( !(UCSR0A & (1<<UDRE0)) ); /* 送信緩衝部空き待機 */
	UDR0 = data; /* ﾃﾞｰﾀ送信(送信開始) */
	
}

void usart_print(char* Message, ...)
{
	
	int i = 0;
	SCHR    scStr[256];							/* 可変長文字列格納用		  */
	va_list args;								/* 可変長引数処理用			  */
	
	/* 可変長引数変換取得 --------------------------------------------------- */
	memset( &scStr[0], 0, sizeof( scStr ));
	
	va_start( args, Message );					/* 可変長引数処理開始		  */
	vsprintf( scStr, Message, args );			/* 可変長引数取得			  */
	va_end( args );								/* 可変長引数処理終了 		  */
	
	for(i = 0; scStr[i] != '\0'; i++)
	{
		
		;
		if(scStr[i] == '\n')
		{
			USART_Transmit(0x0D);
			USART_Transmit(0x0A);
		}
		else
		{
			USART_Transmit(scStr[i]);
		}
		
	}
	wait_1ms(4);
	return;
	
}