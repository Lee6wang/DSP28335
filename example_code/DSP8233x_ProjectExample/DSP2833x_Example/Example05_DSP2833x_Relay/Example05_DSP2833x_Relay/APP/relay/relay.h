/*
 * relay.h
 *
 *  Created on: 2018-1-22
 *      Author: Administrator
 */

#ifndef RELAY_H_
#define RELAY_H_



#include "DSP2833x_Device.h"     // DSP2833x 头文件
#include "DSP2833x_Examples.h"   // DSP2833x 例子相关头文件


#define RELAY_ON			(GpioDataRegs.GPASET.bit.GPIO15=1)
#define RELAY_OFF			(GpioDataRegs.GPACLEAR.bit.GPIO15=1)


void Relay_Init(void);


#endif /* RELAY_H_ */
