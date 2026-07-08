/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32l1xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define TEMP_INT_Pin GPIO_PIN_0
#define TEMP_INT_GPIO_Port GPIOC
#define TEMP_EXT_Pin GPIO_PIN_2
#define TEMP_EXT_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_6
#define LCD_RS_GPIO_Port GPIOA
#define REL_2_CTRL_Pin GPIO_PIN_7
#define REL_2_CTRL_GPIO_Port GPIOA
#define DAC_CS_Pin GPIO_PIN_4
#define DAC_CS_GPIO_Port GPIOC
#define LCD_DB7_Pin GPIO_PIN_5
#define LCD_DB7_GPIO_Port GPIOC
#define V_ADC_CS_Pin GPIO_PIN_1
#define V_ADC_CS_GPIO_Port GPIOB
#define A_ADC_CS_Pin GPIO_PIN_2
#define A_ADC_CS_GPIO_Port GPIOB
#define LCD_DB6_Pin GPIO_PIN_6
#define LCD_DB6_GPIO_Port GPIOC
#define ENC_SW_Pin GPIO_PIN_7
#define ENC_SW_GPIO_Port GPIOC
#define ENC_SW_EXTI_IRQn EXTI9_5_IRQn
#define LCD_DB5_Pin GPIO_PIN_8
#define LCD_DB5_GPIO_Port GPIOC
#define LCD_DB4_Pin GPIO_PIN_9
#define LCD_DB4_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_8
#define SD_CS_GPIO_Port GPIOA
#define ENC_DT_Pin GPIO_PIN_11
#define ENC_DT_GPIO_Port GPIOA
#define ENC_CLK_Pin GPIO_PIN_12
#define ENC_CLK_GPIO_Port GPIOA
#define ENC_CLK_EXTI_IRQn EXTI15_10_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define FAN_CTRL_Pin GPIO_PIN_15
#define FAN_CTRL_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define REL_1_CTRL_Pin GPIO_PIN_6
#define REL_1_CTRL_GPIO_Port GPIOB
#define LCD_EN_Pin GPIO_PIN_8
#define LCD_EN_GPIO_Port GPIOB
#define LCD_RW_Pin GPIO_PIN_9
#define LCD_RW_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
