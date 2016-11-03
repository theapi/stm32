/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

void SystemClock_Config(void);
void Error_Handler(void);

int main(void) {
	//HAL_Init();
	//SystemClock_Config();

	// Output the clock to PA8
	//HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);
	//HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_HSI, RCC_MCODIV_1);



	/* Deconstructing HAL_RCC_MCOConfig */
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	GPIO_InitStruct.Pin = GPIO_PIN_8;
	GPIO_InitStruct.Alternate = GPIO_AF0_MCO;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	MODIFY_REG(RCC->CFGR, (RCC_CFGR_MCOSEL | RCC_CFGR_MCO_PRE),
			((RCC_MCO1SOURCE_SYSCLK | RCC_MCODIV_1 )));


	while (1) {

	}
}

/**
 * System Clock Configuration
 */
void SystemClock_Config(void) {

}

/**
 * This function is executed in case of error occurrence.
 */
void Error_Handler(void) {
	while (1) {
	}
}

