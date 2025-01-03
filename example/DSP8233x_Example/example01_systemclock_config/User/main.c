/*
 * main.c
 *
 * Author:Lee
 * Created on:26/11/2024
 */

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，通过循环占用CPU，达到延时功能
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void delay(void)
{
    Uint16 		i;
	Uint32      j;
	for(i=0;i<32;i++)
		for (j = 0; j < 100000; j++);
}

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

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	InitSysCtrl();//系统时钟初始化，默认已开启F28335所有外设时钟

	LED_Init();

	while(1)
	{
		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//设置GPIO输出翻转信号
		delay();
	}

}
