#pragma once

#include "main.h"

// PINS and PORTS config

// BLUE USR BUTTON
#define BLUE_BTN_PIN    GPIO_PIN_13
#define BLUE_BTN_PORT   GPIOC

// UART
#define UART_TX_PIN     GPIO_PIN_2
#define UART_RX_PIN     GPIO_PIN_3
#define UART_PIN_PORT   GPIOA

// LED ON BOARD
#define LED_BOARD_PIN   GPIO_PIN_5
#define LED_BOARD_PORT  GPIOA

// TEMPERATURE SENSORS
#define TEMP_INT_PIN    GPIO_PIN_0
#define TEMP_INT_PORT   GPIOC
#define TEMP_EXT_PIN    GPIO_PIN_2
#define TEMP_EXT_PORT   GPIOC

// LCD
#define LCD_EN_PIN      GPIO_PIN_8
#define LCD_EN_PORT     GPIOB
#define LCD_RS_PIN      GPIO_PIN_6
#define LCD_RS_PORT     GPIOA
#define LCD_RW_PIN      GPIO_PIN_9
#define LCD_RW_PORT     GPIOB
#define LCD_DB7_PIN     GPIO_PIN_5
#define LCD_DB7_PORT    GPIOC
#define LCD_DB6_PIN     GPIO_PIN_6
#define LCD_DB6_PORT    GPIOC
#define LCD_DB5_PIN     GPIO_PIN_8
#define LCD_DB5_PORT    GPIOC
#define LCD_DB4_PIN     GPIO_PIN_9
#define LCD_DB4_PORT    GPIOC

// SPI (i do not use from it, SPI connection is configured by HAL)

// SPI2 used for DAC and DAC
#define SPI2_SCK_PIN    GPIO_PIN_13
#define SPI2_MISO_PIN   GPIO_PIN_14
#define SPI2_MOSI_PIN   GPIO_PIN_15
#define SPI2_PORT       GPIOB
// SPI3 used for SD Card
#define SPI3_SCK_PIN    GPIO_PIN_10
#define SPI3_MISO_PIN   GPIO_PIN_11
#define SPI3_MOSI_PIN   GPIO_PIN_12
#define SPI3_PORT       GPIOC

// CS for SPI
#define DAC_CS_PIN      GPIO_PIN_4
#define DAC_CS_PORT     GPIOC
#define V_ADC_CS_PIN    GPIO_PIN_1
#define V_ADC_CS_PORT   GPIOB
#define A_ADC_CS_PIN    GPIO_PIN_2
#define A_ADC_CS_PORT   GPIOB
#define SD_CS_PIN       GPIO_PIN_8
#define SD_CS_PORT      GPIOA

// ENCODER
#define ENC_SW_PIN      GPIO_PIN_7
#define ENC_SW_PORT     GPIOC
#define ENC_DT_PIN      GPIO_PIN_11
#define ENC_DT_PORT     GPIOA
#define ENC_CLK_PIN     GPIO_PIN_12
#define ENC_CLK_PORT    GPIOA

// FAN
#define FAN_CTRL_PIN    GPIO_PIN_15
#define FAN_CTRL_PORT   GPIOA

// RELAYS
#define REL_1_CTRL_PIN  GPIO_PIN_6
#define REL_1_CTRL_PORT GPIOB
#define REL_2_CTRL_PIN  GPIO_PIN_7
#define REL_2_CTRL_PORT GPIOA
