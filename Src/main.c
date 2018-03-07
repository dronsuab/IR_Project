/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
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


/* Private variables ---------------------------------------------------------*/
char SerialTXBuffer[50];
char SerialRXBuffer[50];
char IrDATXBuffer[50];
char IrDARXBuffer[50];

tBool UART_TO_IRDA_CP;
tBool IRDA_TO_UART_CP;
tBool pushed = FALSE;

TIM_HandleTypeDef htim1;

xQueueHandle pbq;


/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_TIM1_Init(void);
static void ToggleLed4(void *pvParameters);
static void ToggleLed3(void *pvParameters);
static void sendDataUART(void *pvParameters);
static void receiveDataUART(void *pvParameters);
//static void sendIRData(void *pvParameters);
//static void receiveIRData(void *pvParameters);




int main(void)
{

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();


  /* Configure the system clock */
  SystemClock_Config();


  /* Initialize all configured peripherals */

  MX_TIM1_Init();
  GPIOInit();
  uartInit();
  uartStart();
  interruptsInit();
  interruptsStart();

  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */


  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */
  pbq = xQueueCreate(10, sizeof(int));


    /* Create tasks */
//    xTaskCreate(
//    	  ToggleLed4,                 /* Function pointer */
//  		  "ToggleLed4",                          /* Task name - for debugging only*/
//  		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
//  		  NULL,                     /* Pointer to tasks arguments (parameter) */
//  		  tskIDLE_PRIORITY + 2,           /* Task priority*/
//  		  NULL                              /* Task handle */
//    );
//
//    /* Create tasks */
//    xTaskCreate(
//    	  ToggleLed3,                 /* Function pointer */
//  		  "ToggleLed3",                          /* Task name - for debugging only*/
//  		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
//  		  NULL,                     /* Pointer to tasks arguments (parameter) */
//  		  tskIDLE_PRIORITY + 2,           /* Task priority*/
//  		  NULL                              /* Task handle */
//    );

    xTaskCreate(
    		sendDataUART,                 /* Function pointer */
  		  "sendDataUART",                          /* Task name - for debugging only*/
  		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
  		  NULL,                     /* Pointer to tasks arguments (parameter) */
  		  tskIDLE_PRIORITY + 5,           /* Task priority*/
  		  NULL                              /* Task handle */
    );

    xTaskCreate(
    		receiveDataUART,                 /* Function pointer */
   		  "receiveDataUART",                          /* Task name - for debugging only*/
   		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
   		  NULL,                     /* Pointer to tasks arguments (parameter) */
   		  tskIDLE_PRIORITY + 5,           /* Task priority*/
   		  NULL                              /* Task handle */
     );

//    xTaskCreate(
//    	  sendIRData,                 /* Function pointer */
//  		  "sendIRData",                          /* Task name - for debugging only*/
//  		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
//  		  NULL,                     /* Pointer to tasks arguments (parameter) */
//  		  tskIDLE_PRIORITY + 5,           /* Task priority*/
//  		  NULL                              /* Task handle */
//    );
//
//    xTaskCreate(
//    	  receiveIRData,                 /* Function pointer */
//   		  "receiveIRData",                          /* Task name - for debugging only*/
//   		  configMINIMAL_STACK_SIZE,         /* Stack depth in words */
//   		  NULL,                     /* Pointer to tasks arguments (parameter) */
//   		  tskIDLE_PRIORITY + 5,           /* Task priority*/
//   		  NULL                              /* Task handle */
//     );

    /* Start the RTOS Scheduler */
    vTaskStartScheduler();

    /* HALT */
    while(1);

}

void ToggleLed4(void *pvParameters){

  while (1) {
	GPIOWrite(GPIO_LED_4, GPIO_TOGGLE);
    vTaskDelay(1500 / portTICK_RATE_MS);
  }
}

void ToggleLed3(void *pvParameters){

  while (1) {
	GPIOWrite(GPIO_LED_3, GPIO_LOW);
    vTaskDelay(1600 / portTICK_RATE_MS);
  }
}

void sendDataUART(void *pvParameters){
	strcpy(SerialTXBuffer, "DISPARO,DronA/");
	while(1){
		if (GPIORead(USER_BUTTON_B1) == GPIO_HIGH)
		{
			uartWrite(UART_2, SerialTXBuffer);
			vTaskDelay(1600 / portTICK_RATE_MS);
			//IRDA_TO_UART_CP = FALSE;
			pushed = !pushed;
			if (pushed)
				GPIOWrite(GPIO_LED_3, GPIO_HIGH);
			else
				GPIOWrite(GPIO_LED_3, GPIO_LOW);
		}
	}
}

void receiveDataUART(void *pvParameters){
	while(1){
		if (uartRead(UART_2, SerialRXBuffer, '/') == HAL_OK)
		{

				UART_TO_IRDA_CP = enterBridgeMode(SerialRXBuffer, strlen(SerialRXBuffer), IrDATXBuffer, strlen(IrDATXBuffer));

		}
		vTaskDelay(1600 / portTICK_RATE_MS);
	}

}
//
//void sendIRData(void *pvParameters){
//
//	while(1){
//		if (IR_Ready)
//		{
//			memcpy (IRTXBuffer, SerialRXBuffer, strlen(SerialRXBuffer) + 1);
//			IR_Ready = FALSE;
//		}
//		vTaskDelay(1600 / portTICK_RATE_MS);
//	}
//}
//
//void receiveIRData(void *pvParameters){
//
//	while(1){
//		sprintf(IRRXBuffer, "0/1/2/3/4/");
//		Serial_Ready = TRUE;
//		vTaskDelay(1600 / portTICK_RATE_MS);
//	}
//
//}
/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 3, 0);
}


/* TIM1 init function */
static void MX_TIM1_Init(void)
{

  TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_SlaveConfigTypeDef sSlaveConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 0;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sSlaveConfig.SlaveMode = TIM_SLAVEMODE_DISABLE;
  sSlaveConfig.InputTrigger = TIM_TS_ITR0;
  if (HAL_TIM_SlaveConfigSynchronization(&htim1, &sSlaveConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* StartDefaultTask function */
void StartDefaultTask(void const * argument)
{

  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char * file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler_Debug */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
