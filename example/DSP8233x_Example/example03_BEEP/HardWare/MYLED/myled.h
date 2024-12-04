/*
 * myled.h
 *
 *  Created on: 12/2/2024
 *      Author: Lee
 */

#ifndef HARDWARE_MYLED_MYLED_H_
#define HARDWARE_MYLED_MYLED_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define LED_ON 		(GpioDataRegs.GPCCLEAR.bit.GPIO68=1)
#define LED_OFF		(GpioDataRegs.GPCSET.bit.GPIO68=1;)
#define LED_TOGGLE	(GpioDataRegs.GPCTOGGLE.bit.GPIO68=1)

void LED_Init(void);

#endif /* HARDWARE_MYLED_MYLED_H_ */
