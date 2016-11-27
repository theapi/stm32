/**
 *
 * Drive the 3 digit 7 segment LCD display LCD-S301C31TR at ~50Hz
 * http://uk.farnell.com/lumex/lcd-s301c31tr/lcd-3-digit-0-31-7-87mm-reflective/dp/1838930
 *
 */

#include "main.h"
#include "stm32l0xx_hal.h"
#include "system_clock.h"
#include "lcd.h"
#include "gpio.h"


int main(void) {

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_LCD_Init();

    int count = 0;
    while (1) {

        /* Display the count on the 3 digit lcd screen */
        LCD_display(&hlcd, count);
        HAL_Delay(1000);
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

        count++;
        if (count > 999) {
            count = 0;
        }

    }

}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
void Error_Handler(void) {
    /* User can add his own implementation to report the HAL error return state */
    while (1) {
    }
}

