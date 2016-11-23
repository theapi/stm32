/**
 * File Name : LCD.c
 */

#include "lcd.h"
#include "gpio.h"

LCD_HandleTypeDef hlcd;

void LCD_display(LCD_HandleTypeDef *hlcd, uint16_t num) {
    /* @todo implement double dabble as it is much more efficient */
    uint8_t hundreds = LCD_CHAR_BLANK;
    uint8_t tens = LCD_CHAR_BLANK;
    uint8_t singles = num % 10;

    if (num > 10) {
        tens = (num / 10) % 10;
        if (num > 100) {
            hundreds = (num / 100) % 10;
        }
    }

    LCD->RAM[LCD_RAM_REGISTER0] = LCD_digit(hlcd, 1, hundreds)
            | LCD_digit(hlcd, 2, tens) | LCD_digit(hlcd, 3, singles);
    HAL_LCD_UpdateDisplayRequest(hlcd);
}

uint32_t LCD_digit(LCD_HandleTypeDef *hlcd, uint8_t digit, uint8_t num) {
    uint32_t data;
    switch (digit) {
    case 1:
        data = LCD_digit1(hlcd, num);
        break;
    case 2:
        data = LCD_digit2(hlcd, num);
        break;
    case 3:
        data = LCD_digit3(hlcd, num);
        break;
    default:
        data = LCD_DIGIT1_BLANK;
    }

    return data;
}

uint32_t LCD_digit1(LCD_HandleTypeDef *hlcd, uint8_t num) {
    uint32_t data;
    switch (num) {
    case 0:
        data = LCD_DIGIT1_0;
        break;
    case 1:
        data = LCD_DIGIT1_1;
        break;
    case 2:
        data = LCD_DIGIT1_2;
        break;
    case 3:
        data = LCD_DIGIT1_3;
        break;
    case 4:
        data = LCD_DIGIT1_4;
        break;
    case 5:
        data = LCD_DIGIT1_5;
        break;
    case 6:
        data = LCD_DIGIT1_6;
        break;
    case 7:
        data = LCD_DIGIT1_7;
        break;
    case 8:
        data = LCD_DIGIT1_8;
        break;
    case 9:
        data = LCD_DIGIT1_9;
        break;
    default:
        data = LCD_DIGIT1_BLANK;
    }

    return data;
}

uint32_t LCD_digit2(LCD_HandleTypeDef *hlcd, uint8_t num) {
    uint32_t data;
    switch (num) {
    case 0:
        data = LCD_DIGIT2_0;
        break;
    case 1:
        data = LCD_DIGIT2_1;
        break;
    case 2:
        data = LCD_DIGIT2_2;
        break;
    case 3:
        data = LCD_DIGIT2_3;
        break;
    case 4:
        data = LCD_DIGIT2_4;
        break;
    case 5:
        data = LCD_DIGIT2_5;
        break;
    case 6:
        data = LCD_DIGIT2_6;
        break;
    case 7:
        data = LCD_DIGIT2_7;
        break;
    case 8:
        data = LCD_DIGIT2_8;
        break;
    case 9:
        data = LCD_DIGIT2_9;
        break;
    default:
        data = LCD_DIGIT2_BLANK;
    }

    return data;
}

uint32_t LCD_digit3(LCD_HandleTypeDef *hlcd, uint8_t num) {
    uint32_t data;
    switch (num) {
    case 0:
        data = LCD_DIGIT3_0;
        break;
    case 1:
        data = LCD_DIGIT3_1;
        break;
    case 2:
        data = LCD_DIGIT3_2;
        break;
    case 3:
        data = LCD_DIGIT3_3;
        break;
    case 4:
        data = LCD_DIGIT3_4;
        break;
    case 5:
        data = LCD_DIGIT3_5;
        break;
    case 6:
        data = LCD_DIGIT3_6;
        break;
    case 7:
        data = LCD_DIGIT3_7;
        break;
    case 8:
        data = LCD_DIGIT3_8;
        break;
    case 9:
        data = LCD_DIGIT3_9;
        break;
    default:
        data = LCD_DIGIT3_BLANK;
    }

    return data;
}

/* LCD init function */
void MX_LCD_Init(void) {

    hlcd.Instance = LCD;
    hlcd.Init.Prescaler = LCD_PRESCALER_16;
    hlcd.Init.Divider = LCD_DIVIDER_25;
    hlcd.Init.Duty = LCD_DUTY_STATIC;
    hlcd.Init.Bias = LCD_BIAS_1_4;
    hlcd.Init.VoltageSource = LCD_VOLTAGESOURCE_INTERNAL;
    hlcd.Init.Contrast = LCD_CONTRASTLEVEL_5;
    hlcd.Init.DeadTime = LCD_DEADTIME_0;
    hlcd.Init.PulseOnDuration = LCD_PULSEONDURATION_0;
    hlcd.Init.HighDrive = LCD_HIGHDRIVE_0;
    hlcd.Init.BlinkMode = LCD_BLINKMODE_OFF;
    hlcd.Init.BlinkFrequency = LCD_BLINKFREQUENCY_DIV8;
    hlcd.Init.MuxSegment = LCD_MUXSEGMENT_DISABLE;
    if (HAL_LCD_Init(&hlcd) != HAL_OK) {
        Error_Handler();
    }

}

void HAL_LCD_MspInit(LCD_HandleTypeDef* lcdHandle) {

    GPIO_InitTypeDef GPIO_InitStruct;
    if (lcdHandle->Instance == LCD) {

        /* Peripheral clock enable */
        __HAL_RCC_LCD_CLK_ENABLE();

        /**LCD GPIO Configuration
         PC0     ------> LCD_SEG18
         PC1     ------> LCD_SEG19
         PC2     ------> LCD_SEG20
         PC3     ------> LCD_SEG21
         PC4     ------> LCD_SEG22
         PC5     ------> LCD_SEG23
         PB0     ------> LCD_SEG5
         PB1     ------> LCD_SEG6
         PB10     ------> LCD_SEG10
         PB11     ------> LCD_SEG11
         PB12     ------> LCD_SEG12
         PB13     ------> LCD_SEG13
         PB14     ------> LCD_SEG14
         PB15     ------> LCD_SEG15
         PC6     ------> LCD_SEG24
         PC7     ------> LCD_SEG25
         PC8     ------> LCD_SEG26
         PC9     ------> LCD_SEG27
         PA8     ------> LCD_COM0
         PA15     ------> LCD_SEG17
         PB3     ------> LCD_SEG7
         PB4     ------> LCD_SEG8
         PB5     ------> LCD_SEG9
         PB8     ------> LCD_SEG16
         */
        GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3
                | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8
                | GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_LCD;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_10
                | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14
                | GPIO_PIN_15 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5
                | GPIO_PIN_8;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_LCD;
        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_8 | GPIO_PIN_15;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
        GPIO_InitStruct.Alternate = GPIO_AF1_LCD;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    }
}

void HAL_LCD_MspDeInit(LCD_HandleTypeDef* lcdHandle) {

    if (lcdHandle->Instance == LCD) {

        /* Peripheral clock disable */
        __HAL_RCC_LCD_CLK_DISABLE();

        /**LCD GPIO Configuration
         PC0     ------> LCD_SEG18
         PC1     ------> LCD_SEG19
         PC2     ------> LCD_SEG20
         PC3     ------> LCD_SEG21
         PC4     ------> LCD_SEG22
         PC5     ------> LCD_SEG23
         PB0     ------> LCD_SEG5
         PB1     ------> LCD_SEG6
         PB10     ------> LCD_SEG10
         PB11     ------> LCD_SEG11
         PB12     ------> LCD_SEG12
         PB13     ------> LCD_SEG13
         PB14     ------> LCD_SEG14
         PB15     ------> LCD_SEG15
         PC6     ------> LCD_SEG24
         PC7     ------> LCD_SEG25
         PC8     ------> LCD_SEG26
         PC9     ------> LCD_SEG27
         PA8     ------> LCD_COM0
         PA15     ------> LCD_SEG17
         PB3     ------> LCD_SEG7
         PB4     ------> LCD_SEG8
         PB5     ------> LCD_SEG9
         PB8     ------> LCD_SEG16
         */
        HAL_GPIO_DeInit(GPIOC,
                GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4
                        | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8
                        | GPIO_PIN_9);

        HAL_GPIO_DeInit(GPIOB,
                GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_10 | GPIO_PIN_11
                        | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15
                        | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_8);

        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_8 | GPIO_PIN_15);

    }

}

