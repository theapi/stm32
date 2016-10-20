/**
 * Using the HAL library
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

GPIO_InitTypeDef GPIO_InitStructure;
int main(void) {

	HAL_Init();
	BSP_LED_Init(LED2);

	// Initialise the button (PC13)
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStructure.Pin = GPIO_PIN_13;
	GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
	GPIO_InitStructure.Pull = GPIO_NOPULL; // External pull up
	GPIO_InitStructure.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

	while (1) {
		if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)) {
			BSP_LED_Toggle(LED2);
			//HAL_Delay(500);
		}
	}

}
