/*
 * main.c
 *
 * Author:Lee
 * Created on:26/11/2024
 */

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "leds.h"
#include "relay.h"

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
