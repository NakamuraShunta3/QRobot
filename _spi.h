/*
 * _spi.h
 *
 * Created: 2020/01/22 11:13:09
 *  Author: ohs80177
 */ 


#ifndef _SPI_H_
#define _SPI_H_

#include "system.h"
#include "time.h"


#define _SPI_OK_ 0
#define	_SPI_NG_ -1

void SPI_MasterInit(void);
UCHR SPI_MasterTransmit(UCHR cData);



#endif /* _SPI_H_ */