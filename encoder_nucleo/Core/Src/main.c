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
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "st7789.h"
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
char* parser(uint16_t);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
//uint16_t* im =

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

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  uint16_t number;
  extern uint8_t flag_change;
  number = 0;
  flag_change = 0;
  ST7789_Init(130, 131);
  ST7789_MemAccessModeSet(3, 0, 0, 1);
  ST7789_InversionMode(0);
  ST7789_SetBL(100);
//  uint16_t orange = RGB565(255, 102, 0);
//  uint16_t brown = RGB565(128, 64, 48);
//  uint16_t pink = RGB565(252, 15, 192);
//  ST7789_FillScreen(BLACK);
//  HAL_Delay(500);
////  ST7789_DrawCircleFilled(20, 30, 10, GREEN);
//  ST7789_String(21, 60, "reSET", BLACK, orange);
//  ST7789_DrawRectangleFilled(10, 30+7, 40, 40+7, brown);
//  ST7789_DrawRectangleFilled(10, 20+7, 40, 30+7, YELLOW);
//  ST7789_DrawRectangleFilled(10, 10+7, 40, 20+7, pink);
//  ST7789_DrawCircleFilled(25, 10, 5, RED);
//  char str_numb [10];
//  snprintf(str_numb, sizeof(str_numb), "%i", number);
//  ST7789_String(56, 100, str_numb, BLACK, WHITE);
uint16_t *im = {119, 103, 103, 109, 145, 143, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 139, 132, 126, 125, 124, 136, 139, 138, 140, 140, 140, 144, 140, 138, 138, 138, 137, 138, 138, 138, 136, 139, 135, 112, 255, 255, 254, 255, 255, 255, 255,
		55, 33, 32, 33, 63, 81, 77, 77, 76, 77, 77, 77, 77, 77, 76, 77, 77, 78, 77, 77, 84, 85, 80, 59, 61, 62, 66, 68, 82, 85, 82, 84, 87, 87, 87, 87, 87, 87, 87, 84, 78, 74, 46, 255, 255, 255, 255, 255, 255, 255,
		60, 38, 35, 28, 35, 81, 79, 79, 83, 81, 81, 81, 81, 80, 81, 81, 81, 81, 81, 80, 87, 81, 84, 81, 81, 60, 50, 55, 57, 64, 85, 81, 75, 75, 75, 77, 77, 75, 75, 75, 82, 72, 43, 255, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 34, 40, 68, 77, 81, 86, 86, 86, 84, 81, 81, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 79, 76, 78, 63, 62, 61, 61, 63, 75, 75, 82, 85, 80, 80, 80, 66, 84, 255, 254, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 31, 37, 39, 59, 60, 66, 79, 83, 84, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 80, 81, 81, 81, 84, 81, 79, 79, 59, 51, 57, 63, 64, 77, 89, 80, 80, 87, 70, 66, 255, 255, 254, 255, 255, 255, 255, 255,
		48, 28, 30, 33, 32, 29, 42, 46, 51, 64, 71, 83, 81, 79, 81, 81, 81, 80, 81, 81, 81, 81, 81, 81, 81, 83, 84, 85, 84, 86, 86, 79, 78, 61, 53, 57, 65, 80, 80, 77, 72, 72, 255, 255, 255, 255, 255, 255, 255, 255,
		76, 30, 31, 32, 32, 34, 57, 77, 77, 64, 51, 66, 63, 61, 76, 81, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 80, 81, 81, 81, 81, 81, 79, 65, 55, 80, 80, 82, 71, 62, 255, 255, 255, 255, 254, 255, 255, 255,
		101, 43, 33, 32, 32, 26, 42, 75, 83, 86, 80, 59, 54, 53, 67, 73, 81, 81, 81, 81, 81, 81, 80, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 86, 77, 80, 80, 82, 71, 62, 255, 255, 255, 255, 255, 255, 255, 255,
		90, 50, 34, 28, 32, 31, 38, 63, 70, 78, 85, 82, 80, 82, 58, 56, 72, 65, 69, 79, 84, 81, 81, 79, 79, 79, 81, 81, 81, 81, 81, 81, 81, 81, 81, 81, 80, 80, 80, 80, 72, 73, 255, 255, 255, 255, 255, 255, 255, 255,
		97, 69, 37, 29, 32, 36, 30, 43, 72, 81, 85, 80, 80, 80, 80, 74, 62, 56, 59, 63, 66, 81, 85, 79, 83, 83, 81, 81, 81, 81, 81, 79, 81, 81, 85, 80, 82, 81, 80, 77, 94, 56, 255, 255, 255, 255, 255, 255, 255, 255,
		103, 79, 55, 34, 30, 33, 33, 37, 57, 71, 81, 81, 80, 80, 82, 85, 81, 75, 84, 50, 55, 68, 68, 65, 79, 81, 81, 81, 79, 81, 81, 81, 80, 81, 85, 80, 82, 80, 80, 72, 58, 197, 255, 255, 255, 255, 255, 255, 255, 255,
		108, 88, 78, 38, 30, 32, 32, 32, 38, 77, 87, 76, 77, 80, 81, 77, 77, 74, 94, 86, 71, 60, 53, 55, 64, 62, 76, 79, 77, 84, 86, 79, 81, 81, 84, 75, 82, 80, 80, 80, 62, 255, 254, 255, 255, 255, 255, 255, 255, 255,
		96, 75, 74, 55, 33, 34, 32, 32, 35, 74, 85, 79, 82, 82, 72, 74, 88, 88, 82, 82, 82, 81, 80, 74, 57, 53, 64, 66, 66, 81, 80, 81, 81, 81, 79, 78, 82, 80, 80, 79, 60, 255, 255, 254, 254, 255, 255, 255, 255, 255,
		100, 79, 81, 79, 36, 32, 32, 32, 35, 67, 81, 81, 84, 81, 80, 73, 81, 79, 80, 81, 76, 85, 89, 86, 80, 72, 60, 57, 55, 66, 73, 81, 81, 81, 81, 84, 84, 80, 80, 80, 59, 255, 255, 255, 255, 255, 255, 254, 255, 255,
		90, 78, 81, 82, 58, 36, 27, 36, 33, 38, 81, 84, 81, 79, 81, 85, 88, 78, 81, 91, 84, 74, 85, 85, 82, 82, 80, 77, 71, 57, 54, 71, 65, 69, 83, 87, 93, 75, 75, 77, 54, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		48, 63, 84, 72, 73, 42, 33, 31, 34, 38, 58, 61, 69, 88, 88, 83, 74, 86, 85, 87, 79, 76, 84, 80, 80, 80, 79, 79, 81, 81, 74, 55, 49, 51, 58, 61, 80, 94, 85, 76, 56, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		52, 35, 64, 68, 68, 52, 34, 28, 26, 31, 38, 49, 52, 72, 61, 75, 92, 89, 81, 75, 74, 79, 87, 75, 78, 74, 80, 80, 80, 80, 79, 72, 88, 79, 58, 57, 63, 65, 73, 79, 61, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		54, 32, 33, 53, 62, 67, 39, 27, 27, 34, 45, 67, 74, 60, 54, 66, 68, 77, 79, 81, 77, 78, 81, 76, 81, 76, 81, 87, 84, 80, 87, 82, 80, 80, 82, 70, 55, 56, 75, 74, 232, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		54, 32, 38, 74, 84, 71, 51, 32, 29, 32, 38, 61, 84, 83, 70, 55, 47, 47, 67, 73, 83, 84, 81, 77, 81, 85, 85, 79, 77, 75, 79, 80, 80, 80, 84, 87, 93, 86, 76, 79, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 60, 88, 78, 67, 37, 34, 34, 30, 35, 69, 85, 82, 80, 77, 72, 62, 50, 63, 62, 64, 78, 85, 85, 81, 76, 74, 79, 77, 83, 80, 80, 81, 81, 78, 86, 76, 70, 255, 255, 255, 255, 255, 255, 255, 254, 255, 255,
		54, 32, 28, 42, 77, 78, 76, 56, 36, 32, 32, 38, 64, 82, 81, 82, 91, 83, 85, 81, 52, 51, 53, 65, 66, 65, 72, 79, 83, 84, 84, 81, 89, 82, 80, 80, 80, 81, 76, 70, 255, 255, 255, 254, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 46, 73, 84, 84, 79, 36, 32, 32, 30, 40, 79, 84, 76, 81, 91, 91, 88, 83, 83, 77, 51, 49, 48, 66, 69, 84, 89, 89, 77, 76, 80, 77, 80, 80, 81, 76, 70, 255, 255, 255, 255, 255, 255, 254, 255, 255, 255,
		54, 32, 32, 32, 40, 60, 81, 86, 52, 36, 32, 34, 34, 69, 80, 81, 83, 78, 78, 75, 77, 80, 80, 80, 82, 75, 56, 49, 61, 66, 65, 84, 77, 90, 80, 82, 80, 77, 76, 70, 255, 255, 255, 254, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 32, 32, 34, 74, 81, 72, 39, 31, 31, 23, 38, 76, 83, 81, 88, 84, 81, 84, 84, 82, 71, 80, 82, 75, 69, 55, 55, 51, 68, 65, 82, 78, 94, 77, 77, 74, 65, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		54, 32, 32, 32, 32, 37, 71, 85, 68, 39, 31, 32, 26, 35, 52, 66, 74, 72, 81, 81, 85, 85, 84, 73, 81, 80, 85, 87, 80, 86, 75, 50, 53, 69, 66, 84, 78, 74, 82, 199, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		57, 31, 31, 32, 32, 32, 37, 64, 53, 49, 31, 32, 25, 35, 62, 55, 54, 55, 68, 69, 81, 81, 81, 79, 84, 76, 75, 81, 78, 85, 81, 74, 77, 54, 59, 80, 81, 71, 105, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		70, 36, 33, 32, 32, 32, 33, 42, 75, 75, 52, 35, 32, 32, 37, 77, 88, 74, 60, 49, 67, 67, 68, 79, 79, 79, 81, 83, 76, 81, 86, 90, 85, 78, 79, 80, 80, 77, 89, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		80, 37, 33, 32, 32, 35, 33, 35, 60, 80, 74, 41, 32, 32, 34, 61, 80, 86, 85, 68, 53, 51, 54, 68, 68, 65, 76, 80, 79, 79, 85, 81, 84, 85, 80, 80, 80, 77, 88, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		78, 52, 33, 31, 37, 34, 33, 32, 38, 73, 79, 53, 35, 32, 28, 35, 72, 81, 84, 71, 80, 80, 74, 49, 52, 52, 65, 69, 81, 81, 85, 81, 77, 76, 77, 80, 79, 77, 88, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		103, 82, 50, 32, 28, 28, 32, 32, 32, 70, 85, 62, 35, 32, 31, 33, 75, 81, 85, 79, 78, 80, 86, 78, 80, 76, 58, 53, 72, 72, 69, 79, 74, 84, 80, 80, 80, 77, 89, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		107, 91, 72, 55, 23, 35, 32, 32, 32, 38, 65, 54, 47, 32, 31, 32, 60, 67, 68, 81, 80, 74, 81, 83, 82, 80, 82, 73, 57, 54, 55, 67, 62, 70, 80, 79, 80, 77, 88, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		101, 83, 79, 74, 32, 32, 28, 36, 28, 21, 42, 75, 63, 35, 33, 32, 32, 56, 58, 65, 66, 79, 87, 82, 79, 76, 80, 83, 81, 81, 77, 58, 52, 66, 64, 77, 80, 71, 199, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		97, 87, 81, 63, 38, 31, 31, 30, 26, 23, 41, 71, 69, 51, 35, 32, 32, 57, 67, 55, 52, 70, 68, 65, 76, 84, 81, 82, 82, 81, 77, 77, 69, 54, 56, 77, 72, 58, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		102, 70, 67, 54, 63, 54, 39, 26, 32, 33, 38, 57, 86, 80, 37, 32, 32, 43, 72, 78, 68, 59, 53, 51, 63, 65, 67, 81, 76, 76, 77, 81, 78, 75, 75, 83, 75, 30, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		89, 55, 60, 76, 81, 74, 52, 28, 27, 32, 32, 35, 73, 88, 53, 38, 30, 39, 68, 89, 80, 81, 77, 68, 54, 49, 47, 67, 71, 84, 81, 80, 82, 81, 82, 82, 77, 59, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		55, 54, 63, 64, 64, 64, 59, 43, 33, 32, 32, 28, 36, 56, 54, 39, 32, 30, 43, 57, 64, 64, 66, 71, 62, 61, 55, 33, 36, 62, 64, 62, 64, 64, 65, 65, 63, 40, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		61, 35, 31, 35, 35, 34, 37, 32, 30, 32, 32, 39, 27, 28, 31, 30, 30, 36, 32, 28, 35, 35, 35, 32, 36, 36, 31, 28, 30, 39, 35, 32, 35, 35, 35, 35, 35, 50, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		48, 30, 33, 28, 28, 28, 30, 30, 33, 32, 28, 32, 32, 32, 33, 28, 26, 32, 32, 32, 31, 36, 38, 35, 36, 39, 35, 36, 32, 30, 28, 32, 30, 26, 36, 39, 38, 43, 254, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		60, 50, 52, 54, 56, 55, 54, 54, 54, 40, 33, 32, 32, 32, 39, 50, 35, 32, 31, 33, 50, 29, 23, 27, 26, 44, 54, 56, 54, 56, 56, 52, 36, 32, 37, 39, 41, 223, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		69, 68, 70, 77, 78, 79, 79, 72, 68, 45, 40, 34, 32, 32, 42, 65, 42, 32, 32, 35, 68, 56, 56, 50, 49, 66, 70, 71, 77, 78, 77, 68, 41, 36, 57, 63, 65, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		86, 44, 34, 68, 81, 70, 66, 46, 43, 45, 45, 29, 33, 31, 28, 32, 32, 32, 32, 32, 35, 76, 78, 82, 73, 43, 42, 53, 72, 77, 68, 34, 28, 44, 72, 77, 52, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		74, 41, 37, 39, 67, 55, 50, 72, 87, 84, 72, 55, 37, 33, 32, 32, 32, 32, 32, 32, 34, 64, 85, 81, 78, 83, 81, 70, 53, 38, 34, 32, 35, 63, 74, 80, 54, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		87, 61, 39, 33, 37, 65, 67, 80, 79, 78, 79, 79, 39, 38, 32, 32, 32, 32, 32, 32, 32, 30, 68, 71, 69, 88, 82, 78, 63, 37, 38, 46, 41, 47, 72, 80, 54, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		183, 71, 68, 53, 31, 30, 33, 64, 79, 79, 66, 62, 32, 36, 35, 32, 32, 32, 32, 32, 28, 29, 54, 54, 63, 62, 63, 59, 41, 27, 56, 84, 82, 75, 74, 80, 54, 255, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 166, 79, 81, 53, 31, 32, 40, 66, 65, 46, 45, 52, 52, 35, 32, 32, 32, 32, 32, 28, 34, 69, 77, 58, 46, 33, 28, 30, 35, 80, 86, 86, 78, 74, 80, 54, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		254, 255, 148, 70, 62, 51, 38, 33, 40, 42, 63, 72, 81, 75, 51, 35, 32, 32, 32, 32, 28, 28, 46, 78, 80, 64, 32, 29, 45, 53, 71, 63, 79, 81, 75, 82, 161, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 255, 200, 172, 66, 54, 50, 35, 32, 44, 66, 78, 82, 77, 43, 29, 32, 32, 34, 49, 38, 42, 77, 71, 39, 38, 59, 77, 69, 57, 51, 69, 67, 67, 90, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		255, 255, 254, 255, 255, 163, 74, 84, 38, 30, 30, 39, 62, 85, 81, 56, 37, 32, 31, 38, 73, 39, 40, 60, 39, 36, 52, 87, 90, 76, 76, 68, 55, 55, 66, 95, 255, 254, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		254, 254, 255, 255, 254, 255, 124, 76, 74, 51, 43, 25, 27, 73, 76, 81, 43, 32, 32, 38, 68, 48, 38, 32, 35, 50, 68, 73, 84, 84, 80, 79, 74, 82, 78, 66, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
		254, 255, 255, 255, 255, 255, 255, 182, 65, 90, 79, 49, 40, 35, 40, 62, 29, 32, 32, 32, 38, 60, 38, 33, 39, 72, 80, 85, 91, 88, 85, 75, 81, 74, 78, 72, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254		};
uint16_t num = 0;
  for (int i =0; i<50;i++){
	  for (int j = 0; j < 50; j++){
		  ST7789_DrawPixel(i, j, RGB565(0,0,im[num]));
		  num++;
	  }
  }
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	  if (flag_change == 1){
//		  number++;
//		  snprintf(str_numb, sizeof(str_numb), "%i", number);
//		  if(number < 10)
//			  ST7789_String(56, 100, str_numb, BLACK, WHITE);
//		  else if (number < 100)
//			  ST7789_String(47, 100, str_numb, BLACK, WHITE);
//		  else
//			  ST7789_String(39, 100, str_numb, BLACK, WHITE);
//		  flag_change = 0;
//		  if (number == 15){
//			  ST7789_FillScreen(BLACK);
//			  ST7789_String(30, 0, "Very", BLACK, WHITE);
//			  ST7789_String(13, 50, "Simple", BLACK, WHITE);
//			  ST7789_String(30, 100, "Task", BLACK, WHITE);
//		  }
//		  if (number == 16){
//			  ST7789_FillScreen(BLACK);
//			  ST7789_String(21, 60, "reSET", BLACK, orange);
//			  ST7789_DrawRectangleFilled(10, 30+7, 40, 40+7, brown);
//			  ST7789_DrawRectangleFilled(10, 20+7, 40, 30+7, YELLOW);
//			  ST7789_DrawRectangleFilled(10, 10+7, 40, 20+7, pink);
//			  ST7789_DrawCircleFilled(25, 10, 5, RED);
//			  ST7789_String(47, 100, str_numb, BLACK, WHITE);
//		  }
//	  }

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
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_0)
  {
  }
  LL_RCC_HSI_Enable();

   /* Wait till HSI is ready */
  while(LL_RCC_HSI_IsReady() != 1)
  {

  }
  LL_RCC_HSI_SetCalibTrimming(16);
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSI);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSI)
  {

  }
  LL_SetSystemCoreClock(8000000);

   /* Update the time base */
  if (HAL_InitTick (TICK_INT_PRIORITY) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
char* parser(uint16_t number){
	char str_numb [3];
	snprintf(str_numb, sizeof(str_numb), "%d", number);
	return str_numb;
}
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