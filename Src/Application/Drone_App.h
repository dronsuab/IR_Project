/*
 * Drone_App.h
 *
 *  Created on: Mar 9, 2018
 *      Author: FV4IYP0
 */

#ifndef DRONE_APP_H_
#define DRONE_APP_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "cmsis_os.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"
#include "common.h"
#include "GPIO.h"
#include "uart.h"
#include "interrupts.h"
#include <stdio.h>
#include "BridgeMode.h"


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void ToggleLed4(void *pvParameters);
void ToggleLed3(void *pvParameters);
void sendDataUART(void *pvParameters);
void receiveDataUART(void *pvParameters);
void systemInit(void);
void taskCreation(void);

//static void sendIRData(void *pvParameters);
//static void receiveIRData(void *pvParameters);



#endif /* DRONE_APP_H_ */
