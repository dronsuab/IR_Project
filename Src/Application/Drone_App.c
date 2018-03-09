/*
 * Drone_App.c
 *
 *  Created on: Mar 9, 2018
 *      Author: FV4IYP0
 */

#include "Drone_App.h"

/* Private variables ---------------------------------------------------------*/
char SerialTXBuffer[50];
char SerialRXBuffer[50];
char IrDATXBuffer[50];
char IrDARXBuffer[50];

tBool UART_TO_IRDA_CP;
tBool IRDA_TO_UART_CP;
tBool pushed = FALSE;


xQueueHandle pbq;


void systemInit(void)
{
	  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	  HAL_Init();


	  /* Configure the system clock */
	  SystemClock_Config();


	  /* Initialize all configured peripherals */

	  GPIOInit();
	  uartInit();
	  uartStart();
	  interruptsInit();
	  interruptsStart();
}

void taskCreation(void)
{

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
			//IRDA_TO_UART_CP = FALSE;
			pushed = !pushed;
			if (pushed)
				GPIOWrite(GPIO_LED_3, GPIO_HIGH);
			else
				GPIOWrite(GPIO_LED_3, GPIO_LOW);
			vTaskDelay(1600 / portTICK_RATE_MS);
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
