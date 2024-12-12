/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define en_1_Pin GPIO_PIN_1
#define en_1_GPIO_Port GPIOA
#define en_2_Pin GPIO_PIN_2
#define en_2_GPIO_Port GPIOA
#define en_3_Pin GPIO_PIN_3
#define en_3_GPIO_Port GPIOA
#define en_4_Pin GPIO_PIN_4
#define en_4_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOA
#define re_1_Pin GPIO_PIN_6
#define re_1_GPIO_Port GPIOA
#define ye_1_Pin GPIO_PIN_7
#define ye_1_GPIO_Port GPIOA
#define l1_Pin GPIO_PIN_0
#define l1_GPIO_Port GPIOB
#define l2_Pin GPIO_PIN_1
#define l2_GPIO_Port GPIOB
#define l3_Pin GPIO_PIN_2
#define l3_GPIO_Port GPIOB
#define gr_1_Pin GPIO_PIN_8
#define gr_1_GPIO_Port GPIOA
#define re_2_Pin GPIO_PIN_9
#define re_2_GPIO_Port GPIOA
#define ye_2_Pin GPIO_PIN_10
#define ye_2_GPIO_Port GPIOA
#define gr_2_Pin GPIO_PIN_11
#define gr_2_GPIO_Port GPIOA
#define button_1_Pin GPIO_PIN_12
#define button_1_GPIO_Port GPIOA
#define button_2_Pin GPIO_PIN_13
#define button_2_GPIO_Port GPIOA
#define button_3_Pin GPIO_PIN_14
#define button_3_GPIO_Port GPIOA
#define l4_Pin GPIO_PIN_3
#define l4_GPIO_Port GPIOB
#define l5_Pin GPIO_PIN_4
#define l5_GPIO_Port GPIOB
#define l6_Pin GPIO_PIN_5
#define l6_GPIO_Port GPIOB
#define l7_Pin GPIO_PIN_6
#define l7_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
