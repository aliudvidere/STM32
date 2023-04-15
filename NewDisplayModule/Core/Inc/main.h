/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_CS_Pin GPIO_PIN_0
#define LED_CS_GPIO_Port GPIOA
#define LED_ON_Pin GPIO_PIN_1
#define LED_ON_GPIO_Port GPIOA
#define LED_RESET_Pin GPIO_PIN_2
#define LED_RESET_GPIO_Port GPIOA
#define Boozer_Pin GPIO_PIN_0
#define Boozer_GPIO_Port GPIOB
#define KBD_R1_Pin GPIO_PIN_2
#define KBD_R1_GPIO_Port GPIOB
#define KBD_R2_Pin GPIO_PIN_10
#define KBD_R2_GPIO_Port GPIOB
#define KBD_R3_Pin GPIO_PIN_11
#define KBD_R3_GPIO_Port GPIOB
#define KBD_C5_Pin GPIO_PIN_12
#define KBD_C5_GPIO_Port GPIOB
#define KBD_C4_Pin GPIO_PIN_13
#define KBD_C4_GPIO_Port GPIOB
#define KBD_C3_Pin GPIO_PIN_14
#define KBD_C3_GPIO_Port GPIOB
#define KBD_C2_Pin GPIO_PIN_15
#define KBD_C2_GPIO_Port GPIOB
#define KBD_C1_Pin GPIO_PIN_8
#define KBD_C1_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
