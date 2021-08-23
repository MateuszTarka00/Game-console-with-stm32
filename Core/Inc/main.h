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
#define Right_Pin GPIO_PIN_0
#define Right_GPIO_Port GPIOC
#define Right_EXTI_IRQn EXTI0_IRQn
#define Up_Pin GPIO_PIN_1
#define Up_GPIO_Port GPIOC
#define Up_EXTI_IRQn EXTI1_IRQn
#define Left_Pin GPIO_PIN_2
#define Left_GPIO_Port GPIOC
#define Left_EXTI_IRQn EXTI2_TSC_IRQn
#define Down_Pin GPIO_PIN_3
#define Down_GPIO_Port GPIOC
#define Down_EXTI_IRQn EXTI3_IRQn
#define DC_Pin GPIO_PIN_4
#define DC_GPIO_Port GPIOA
#define CE_Pin GPIO_PIN_5
#define CE_GPIO_Port GPIOA
#define RESET_Pin GPIO_PIN_6
#define RESET_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
