/*
 * beep.c
 *
 *  Created on: 12/3/2024
 *      Author: Lee
 */

#include "beep.h"

void BEEP_Init(void)
{
	EALLOW;
	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;//开启GPIO时钟
	//端口配置
	GpioCtrlRegs.GPAMUX1.bit.GPIO6=0;
	GpioCtrlRegs.GPADIR.bit.GPIO6=1;
	GpioCtrlRegs.GPAPUD.bit.GPIO6=0;

	EDIS;

	GpioDataRegs.GPACLEAR.bit.GPIO6=1;

}
