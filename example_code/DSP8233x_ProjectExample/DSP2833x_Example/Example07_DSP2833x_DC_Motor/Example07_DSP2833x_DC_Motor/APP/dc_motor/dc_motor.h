/*
 * dc_motor.h
 *
 *  Created on: 2018-1-23
 *      Author: Administrator
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "DSP2833x_Device.h"     // DSP2833x ͷ�ļ�
#include "DSP2833x_Examples.h"   // DSP2833x �������ͷ�ļ�


#define DC_MOTOR_INA_SETH			(GpioDataRegs.GPASET.bit.GPIO2=1)
#define DC_MOTOR_INA_SETL			(GpioDataRegs.GPACLEAR.bit.GPIO2=1)
#define DC_MOTOR_INB_SETH			(GpioDataRegs.GPASET.bit.GPIO3=1)
#define DC_MOTOR_INB_SETL			(GpioDataRegs.GPACLEAR.bit.GPIO3=1)

#define DC_MOTOR_INC_SETH			(GpioDataRegs.GPASET.bit.GPIO4=1)
#define DC_MOTOR_INC_SETL			(GpioDataRegs.GPACLEAR.bit.GPIO4=1)
#define DC_MOTOR_IND_SETH			(GpioDataRegs.GPASET.bit.GPIO5=1)
#define DC_MOTOR_IND_SETL			(GpioDataRegs.GPACLEAR.bit.GPIO5=1)

void DC_Motor_Init(void);

#endif /* DC_MOTOR_H_ */
