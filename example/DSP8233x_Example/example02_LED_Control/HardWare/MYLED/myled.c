/*
 * myled.c
 *
 *  Created on: 12/2/2024
 *      Author: Lee
 */

#include "myled.h"

/*******************************************************************************
* 函 数 名         : LED_Init
* 函数功能		   : LED初始化函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void LED_Init(void)
{
	EALLOW;//关闭写保护

	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // 开启GPIO时钟

	//LED1端口配置
	GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//设置为通用GPIO功能
	GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//设置GPIO方向为输出
	GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//使能GPIO上拉电阻

	GpioDataRegs.GPCSET.bit.GPIO68=1;//设置GPIO输出高电平

	EDIS;//开启写保护
}



