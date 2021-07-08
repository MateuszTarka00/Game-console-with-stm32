/*
 * lcd.h
 *
 *  Created on: 28 cze 2021
 *      Author: mateo
 */

#include "stm32f3xx_hal.h"

#ifndef INC_LCD_H_
#define INC_LCD_H_

void lcd_reset();
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t* data, int size);

#endif /* INC_LCD_H_ */
