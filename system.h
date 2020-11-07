/*
 * system.h
 *
 * Created: 2020/01/19 16:33:42
 *  Author: ohs80177
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_

/*	-----------------------------------------------------------------------	 */
/*	system.h																 */
/*	システムヘッダ															 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/05	桝井　隆治	 */
/*	-----------------------------------------------------------------------	 */

#include<avr/io.h>								/* IO関連ヘッダ				  */
#include<avr/interrupt.h>						/* 割り込み関連ヘッダ		  */
#include <stdarg.h>								/* 可変長引数制御用ヘッダ	  */
#include <stdio.h>

/*	-----------------------------------------------------------------------	 */
/*	typedef宣言																 */
/*	-----------------------------------------------------------------------	 */
typedef char			SCHR;					/*	char型					 */
typedef unsigned char	UCHR;					/*	unsigned char型			 */
typedef short			SSHT;					/*	short型					 */
typedef unsigned short	USHT;					/*	unsigned short型		 */
typedef long			SLNG;					/*	long型					 */
typedef unsigned long	ULNG;					/*	unsigned long型			 */
typedef int				SINT;					/*	int型					 */
typedef unsigned int	UINT;					/*	unsigned int型			 */
typedef	float			FLOT;					/*	float型					 */
typedef	double			DBLE;					/*	double型				 */



/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */





#endif /* SYSTEM_H_ */