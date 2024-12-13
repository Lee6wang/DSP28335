/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "leds.h"
#include "key.h"
#include "dc_motor.h"



/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
	int i=0;
	char key=0;

	InitSysCtrl();

	LED_Init();
	KEY_Init();
	DC_Motor_Init();

	while(1)
	{
		key=KEY_Scan(0);
		switch(key)
		{
			case KEY1_PRESS: DC_MOTOR_INA_SETH;DC_MOTOR_INB_SETL;break;
			case KEY2_PRESS: DC_MOTOR_INA_SETL;DC_MOTOR_INB_SETH;break;
			case KEY3_PRESS: DC_MOTOR_INA_SETL;DC_MOTOR_INB_SETL;break;
		}

		i++;
		if(i%2000==0)
		{
			LED1_TOGGLE;
		}
		DELAY_US(100);
	}
}

