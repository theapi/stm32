/**
 * DL1178 lcd screen found in generic large screen kitchen timers like this:
 * https://www.amazon.co.uk/Mudder-Magnetic-Digital-Kitchen-Display/dp/B016EHCJFG
 * Datasheet is in the docs folder.
 *
 * 3V, 1/4 Duty, 1/2 Bias
 *
 *

           A
      ----------
      |         |
     F|         |B
      |         |
      -----G-----
      |         |
     E|         |C
      |         |    _   _
      -----------   |_| |_|COLON (colon is AM PM)
           D


 *
 */

#ifndef __lcd_dl1178_H
#define __lcd_dl1178_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32l0xx_hal.h"
#include "main.h"

 /* NB these are numbered as they are in the lcd datasheet */
#define LCD_SEG_1 0b00000000000000000000000000000001
#define LCD_SEG_2 0b00000000000000000000000000000010
#define LCD_SEG_3 0b00000000000000000000000000000100
#define LCD_SEG_4 0b00000000000000000000000000001000
#define LCD_SEG_5 0b00000000000000000000000000010000
#define LCD_SEG_6 0b00000000000000000000000000100000
#define LCD_SEG_7 0b00000000000000000000000001000000
#define LCD_SEG_8 0b00000000000000000000000010000000



void LCD_display(LCD_HandleTypeDef *hlcd, uint8_t minutes, uint8_t seconds, uint8_t ampm);

#ifdef __cplusplus
}
#endif
#endif /*__lcd_dl1178_H */

