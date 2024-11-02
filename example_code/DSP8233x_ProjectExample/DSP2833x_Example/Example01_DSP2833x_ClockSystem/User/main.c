/*
 * main.c
 *
 *  Created on: 2018-3-21
 *  Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File


/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������ͨ��ѭ��ռ��CPU���ﵽ��ʱ����
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void delay(void)
{
    Uint16 		i;
	Uint32      j;
	for(i=0;i<32;i++)
		for (j = 0; j < 100000; j++);
}

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init(void)
{
	EALLOW;//�ر�д����

	SysCtrlRegs.PCLKCR3.bit.GPIOINENCLK = 1;    // ����GPIOʱ��

	//LED1�˿�����
	GpioCtrlRegs.GPCMUX1.bit.GPIO68=0;//����Ϊͨ��GPIO����
	GpioCtrlRegs.GPCDIR.bit.GPIO68=1;//����GPIO����Ϊ���
	GpioCtrlRegs.GPCPUD.bit.GPIO68=0;//ʹ��GPIO��������

	GpioDataRegs.GPCSET.bit.GPIO68=1;//����GPIO����ߵ�ƽ

	EDIS;//����д����
}

/*******************************************************************************
* �� �� ��         : main
* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void main()
{
	InitSysCtrl();//ϵͳʱ�ӳ�ʼ����Ĭ���ѿ���F28335��������ʱ��

	LED_Init();

	while(1)
	{
		GpioDataRegs.GPCTOGGLE.bit.GPIO68=1;//����GPIO�����ת�ź�
		delay();
	}

}
