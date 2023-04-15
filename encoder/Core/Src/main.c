/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
//  RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
//  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//  GPIOA->CRH &= (~GPIO_CRH_CNF9_0);
//  GPIOA->CRH |= (GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9);
//  GPIOA->CRH &= (~GPIO_CRH_CNF10_0);
//  GPIOA->CRH |= GPIO_CRH_CNF10_1;
//  GPIOA->CRH &= (~(GPIO_CRH_MODE10));
//  GPIOA->BSRR |= GPIO_ODR_ODR10;
//  USART1->CR1 = USART_CR1_UE;
//  USART1->BRR = 7500;
  USART1->CR1 |= USART_CR1_TE | USART_CR1_RE ; // разрешаем приемник и передатчик

  USART2->CR1 |= USART_CR1_TE | USART_CR1_RE ; // разрешаем приемник и передатчик



  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  TIM1->CR1 |= 1;
  TIM2->CR1 |= 1;
  TIM3->CR1 |= 1;

  TIM1->DIER |= 1;
  TIM2->DIER |= 1;
  TIM3->DIER |= 1;

  uint32_t data = 2000000000;

  uint32_t data1 = 2000000000;
  uint32_t data2 = 2000000000;

  extern int8_t tim1;
  extern int8_t tim2;
  extern int8_t tim3;

  tim1 = 0;
  tim2 = 0;
  tim3 = 0;
//  int8_t tim3 = 0;

  uint16_t REVOLUTION = 65535;

//  TIM2->CR1 |= 1;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

	  uint8_t flag;
	   // отослать данное назад

	  while ((USART2->SR & USART_SR_RXNE) == 0) {} // Ждем пустого регистра
      	  	 flag = USART2->DR;
      switch (flag){
    	  case 0 :
    		  data = 2000000000 + (uint32_t)LL_TIM_GetCounter(TIM1) + REVOLUTION * tim1;
    		  break;
    	  case 1 :
    		  data = 2000000000 + (uint32_t)LL_TIM_GetCounter(TIM2) + REVOLUTION * tim2;
    	      break;
    	  case 2 :
			  data = 2000000000 + (uint32_t)LL_TIM_GetCounter(TIM3) + REVOLUTION * tim3;
			  break;
    	  case 22 :
			  data1 = 2000000000 + (uint32_t)LL_TIM_GetCounter(TIM1) + REVOLUTION * tim1;
			  data2 = 2000000000 + (uint32_t)LL_TIM_GetCounter(TIM2) + REVOLUTION * tim2;
			  break;
    	  case 10 :
			  TIM1->CNT = 32000;
			  tim1 = 0;
			  data = 0;
			  break;
		  case 11 :
			  TIM2->CNT = 32000;
			  tim2 = 0;
			  data = 0;
			  break;
		  case 12 :
			  TIM3->CNT = 32000;
			  data = 0;
			  break;

      }
      if (flag == 22){
    	  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
    	  	        USART2->DR = data1 & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data1>>8) & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data1>>16) & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data1>>24) & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = data2 & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data2>>8) & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data2>>16) & 0xFF;
		  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
				USART2->DR = (data2>>24) & 0xFF;
		  continue;

      }
      while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
      	  	  USART2->DR = flag;
	  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
	        USART2->DR = data & 0xFF;
	  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
	        USART2->DR = (data>>8) & 0xFF;
	  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
	        USART2->DR = (data>>16) & 0xFF;
	  while ((USART2->SR & USART_SR_TXE) == 0) {} // Ждем пустого регистра
	        USART2->DR = (data>>24) & 0xFF;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_2);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_2)
  {
  }
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE_DIV_2, LL_RCC_PLL_MUL_9);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_SetSystemCoreClock(72000000);

   /* Update the time base */
  if (HAL_InitTick (TICK_INT_PRIORITY) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
