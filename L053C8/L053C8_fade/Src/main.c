/**
 * Fade demo.
 *
 * Pins PA0, PA1, PA2, PA3
 * System clock: 2.097MHz
 * PWM frequency: 1024Hz
 * PWM steps 0 to 1023 ( 0 = off, 1023 = full on)
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32l0xx_hal.h"
#include "tim.h"
#include "gpio.h"
#include "system_clock.h"

int main(void) {

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock */
    SystemClock_Config();

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_TIM2_Init();

    /* Start the PWM */
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4);

    uint32_t fade1 = 0;
    uint8_t direction = 0;

    while (1) {
        if (direction == 0) {
            fade1++;
        } else {
            fade1--;
        }

        if (fade1 == 1023) {
            direction = 1;
        } else if (fade1 == 0) {
            direction = 0;
        }

        /* Fade PA0 & PA1 in opposite directions */
        TIM2->CCR1 = fade1;
        TIM2->CCR2 = 1023 - fade1;

        /* Same as above for PA2 & PA3 but through the HAL instance */
        htim2.Instance->CCR3 = fade1;
        htim2.Instance->CCR4 = 1023 - fade1;

        HAL_Delay(2);
    }

}

/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
void Error_Handler(void) {
    while (1) {
    }
}

