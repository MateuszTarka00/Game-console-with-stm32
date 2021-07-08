/*
 * lcd.c
 *
 *  Created on: 28 cze 2021
 *      Author: mateo
 */


#include "lcd.h"
#include "spi.h"
#include "gpio.h"
#include "font.h"

void lcd_reset()
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);
}

void lcd_cmd(uint8_t cmd)
{
	HAL_GPIO_WritePin(GPIOA, CE_Pin|DC_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi2, &cmd, 1, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(GPIOA, CE_Pin|DC_Pin, GPIO_PIN_SET);
}

void lcd_data(uint8_t* data, int size)
{
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(DC_GPIO_Port, DC_Pin, GPIO_PIN_SET);
	HAL_SPI_Transmit(&hspi2, (uint8_t*)data, size, HAL_MAX_DELAY);
	HAL_GPIO_WritePin(CE_GPIO_Port, CE_Pin, GPIO_PIN_SET);
}

void lcd_setup(void)
{
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, GPIO_PIN_SET);

	lcd_cmd(PCD8544_FUNCTION_SET | 1);
	lcd_cmd(PCD8544_H_BIAS | 4);
	lcd_cmd(PCD8544_H_VOP | 0x2f);
	lcd_cmd(PCD8544_FUNCTION_SET);
	lcd_cmd(PCD8544_DISP_NORMAL);
}



