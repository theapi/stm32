/**
  * LCD-S301C31TR 3 Digit 7 segment static lcd display.
  * http://uk.farnell.com/lumex/lcd-s301c31tr/lcd-3-digit-0-31-7-87mm-reflective/dp/1838930
  */

#ifndef __lcd_H
#define __lcd_H
#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32l0xx_hal.h"
#include "main.h"


extern LCD_HandleTypeDef hlcd;

extern void Error_Handler(void);

void MX_LCD_Init(void);
void LCD_display(LCD_HandleTypeDef *hlcd, uint16_t num);
uint32_t LCD_digit(uint8_t digit, uint8_t num);
uint32_t LCD_digit1(uint8_t num);
uint32_t LCD_digit2(uint8_t num);
uint32_t LCD_digit3(uint8_t num);


/*

           A
      ----------
      |         |
     F|         |B
      |         |
      -----G-----
      |         |
     E|         |C
      |         |  _
      ----------- |_|DP
           D

 */

/* Digit 1 */
#define LCD_SEG_E1  0b00000000000000000000000000100000 /* LCD_SEG5 */
#define LCD_SEG_D1  0b00000000000000000000000001000000 /* LCD_SEG6 */
#define LCD_SEG_C1  0b00000000000000000000000010000000 /* LCD_SEG7 */
#define LCD_SEG_DP1 0b00000000000000000000000100000000 /* LCD_SEG8 */
#define LCD_SEG_B1  0b00000000000000000000001000000000 /* LCD_SEG9 */
#define LCD_SEG_G1  0b00000000000000000000010000000000 /* LCD_SEG10 */
#define LCD_SEG_F1  0b00000000000000000000100000000000 /* LCD_SEG11 */
#define LCD_SEG_A1  0b00000000000000000001000000000000 /* LCD_SEG12 */
/* Digit 2 */
#define LCD_SEG_E2  0b00000000000000000010000000000000 /* LCD_SEG13 */
#define LCD_SEG_D2  0b00000000000000000100000000000000 /* LCD_SEG14 */
#define LCD_SEG_C2  0b00000000000000001000000000000000 /* LCD_SEG15 */
#define LCD_SEG_DP2 0b00000000000000010000000000000000 /* LCD_SEG16 */
#define LCD_SEG_B2  0b00000000000000100000000000000000 /* LCD_SEG17 */
#define LCD_SEG_G2  0b00000000000001000000000000000000 /* LCD_SEG18 */
#define LCD_SEG_F2  0b00000000000010000000000000000000 /* LCD_SEG19 */
#define LCD_SEG_A2  0b00000000000100000000000000000000 /* LCD_SEG20 */
/* Digit 3 */
#define LCD_SEG_E3  0b00000000001000000000000000000000 /* LCD_SEG21 */
#define LCD_SEG_D3  0b00000000010000000000000000000000 /* LCD_SEG22 */
#define LCD_SEG_C3  0b00000000100000000000000000000000 /* LCD_SEG23 */
#define LCD_SEG_B3  0b00000001000000000000000000000000 /* LCD_SEG24 */
#define LCD_SEG_G3  0b00000010000000000000000000000000 /* LCD_SEG25 */
#define LCD_SEG_F3  0b00000100000000000000000000000000 /* LCD_SEG26 */
#define LCD_SEG_A3  0b00001000000000000000000000000000 /* LCD_SEG27 */


#define LCD_DIGIT1_0  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_C1 | LCD_SEG_D1 | LCD_SEG_E1 | LCD_SEG_F1
#define LCD_DIGIT1_1  LCD_SEG_B1 | LCD_SEG_C1
#define LCD_DIGIT1_2  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_D1 | LCD_SEG_E1 | LCD_SEG_G1
#define LCD_DIGIT1_3  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_C1 | LCD_SEG_D1 | LCD_SEG_G1
#define LCD_DIGIT1_4  LCD_SEG_B1 | LCD_SEG_C1 | LCD_SEG_F1 | LCD_SEG_G1
#define LCD_DIGIT1_5  LCD_SEG_A1 | LCD_SEG_C1 | LCD_SEG_D1 | LCD_SEG_F1 | LCD_SEG_G1
#define LCD_DIGIT1_6  LCD_SEG_C1 | LCD_SEG_D1 | LCD_SEG_E1 | LCD_SEG_F1 | LCD_SEG_G1
#define LCD_DIGIT1_7  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_C1
#define LCD_DIGIT1_8  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_C1 | LCD_SEG_D1 | LCD_SEG_E1 | LCD_SEG_F1 | LCD_SEG_G1
#define LCD_DIGIT1_9  LCD_SEG_A1 | LCD_SEG_B1 | LCD_SEG_C1 | LCD_SEG_F1 | LCD_SEG_G1
#define LCD_DIGIT1_DOT   LCD_SEG_DP1
#define LCD_DIGIT1_BLANK 0b0

#define LCD_DIGIT2_0  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_C2 | LCD_SEG_D2 | LCD_SEG_E2 | LCD_SEG_F2
#define LCD_DIGIT2_1  LCD_SEG_B2 | LCD_SEG_C2
#define LCD_DIGIT2_2  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_D2 | LCD_SEG_E2 | LCD_SEG_G2
#define LCD_DIGIT2_3  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_C2 | LCD_SEG_D2 | LCD_SEG_G2
#define LCD_DIGIT2_4  LCD_SEG_B2 | LCD_SEG_C2 | LCD_SEG_F2 | LCD_SEG_G2
#define LCD_DIGIT2_5  LCD_SEG_A2 | LCD_SEG_C2 | LCD_SEG_D2 | LCD_SEG_F2 | LCD_SEG_G2
#define LCD_DIGIT2_6  LCD_SEG_C2 | LCD_SEG_D2 | LCD_SEG_E2 | LCD_SEG_F2 | LCD_SEG_G2
#define LCD_DIGIT2_7  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_C2
#define LCD_DIGIT2_8  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_C2 | LCD_SEG_D2 | LCD_SEG_E2 | LCD_SEG_F2 | LCD_SEG_G2
#define LCD_DIGIT2_9  LCD_SEG_A2 | LCD_SEG_B2 | LCD_SEG_C2 | LCD_SEG_F2 | LCD_SEG_G2
#define LCD_DIGIT2_DOT   LCD_SEG_DP2
#define LCD_DIGIT2_BLANK 0b0

#define LCD_DIGIT3_0  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_C3 | LCD_SEG_D3 | LCD_SEG_E3 | LCD_SEG_F3
#define LCD_DIGIT3_1  LCD_SEG_B3 | LCD_SEG_C3
#define LCD_DIGIT3_2  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_D3 | LCD_SEG_E3 | LCD_SEG_G3
#define LCD_DIGIT3_3  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_C3 | LCD_SEG_D3 | LCD_SEG_G3
#define LCD_DIGIT3_4  LCD_SEG_B3 | LCD_SEG_C3 | LCD_SEG_F3 | LCD_SEG_G3
#define LCD_DIGIT3_5  LCD_SEG_A3 | LCD_SEG_C3 | LCD_SEG_D3 | LCD_SEG_F3 | LCD_SEG_G3
#define LCD_DIGIT3_6  LCD_SEG_C3 | LCD_SEG_D3 | LCD_SEG_E3 | LCD_SEG_F3 | LCD_SEG_G3
#define LCD_DIGIT3_7  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_C3
#define LCD_DIGIT3_8  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_C3 | LCD_SEG_D3 | LCD_SEG_E3 | LCD_SEG_F3 | LCD_SEG_G3
#define LCD_DIGIT3_9  LCD_SEG_A3 | LCD_SEG_B3 | LCD_SEG_C3 | LCD_SEG_F3 | LCD_SEG_G3
#define LCD_DIGIT3_BLANK 0b0

#define LCD_CHAR_BLANK 0x20

#ifdef __cplusplus
}
#endif
#endif
