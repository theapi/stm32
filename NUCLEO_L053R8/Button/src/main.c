/**
 * Button controlling the LED
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

/* A memory structure that starts at GPIOA_BASE ((uint32_t)0x40000000U + 0x10000000U) */
typedef struct
{
    __IO uint32_t MODER;        /*!< GPIO port mode register,                     Address offset: 0x00 */
    __IO uint32_t OTYPER;       /*!< GPIO port output type register,              Address offset: 0x04 */
    __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,             Address offset: 0x08 */
    __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C */
    __IO uint32_t IDR;          /*!< GPIO port input data register,               Address offset: 0x10 */
    __IO uint32_t ODR;          /*!< GPIO port output data register,              Address offset: 0x14 */
    __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,        Address offset: 0x18 */
    __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,       Address offset: 0x1C */
    __IO uint32_t AFR[2];       /*!< GPIO alternate function register,            Address offset: 0x20-0x24 */
    __IO uint32_t BRR;          /*!< GPIO bit reset register,                     Address offset: 0x28 */
}FOO_TypeDef;
#define FOO               ((FOO_TypeDef *) GPIOA_BASE)


/**
 * Initialise the on board LED: PORT A, PIN 5
 */
void
led_init ()
{
  // Enable GPIOA
  RCC->IOPENR |= RCC_IOPENR_IOPAEN;
  // Pin 5 output mode: 01
  // - first set as: 00
  GPIOA->MODER &= ~(GPIO_MODER_MODE5);
  // - then set: 01
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  // Output type Push/Pull
  GPIOA->OTYPER &= ~(GPIO_OTYPER_OT_5);
  // Pin speed - low speed: 00 (inverse of 11)
  GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEED5);
  // No pull up nor pull down
  GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);
}

/**
 * Initialise the on board USER button: PORT C, PIN 13
 */
void
button_init ()
{
  // Enable GPIOC
  RCC->IOPENR |= RCC_IOPENR_IOPCEN;
  // Input mode: 00
  GPIOC->MODER &= ~(GPIO_MODER_MODE13);
  // Hard wired as a pull up.
}

int
main (void)
{



  // Configure the on board LED.
  led_init ();

  // Configure the on board button.
  button_init ();

  FOO->BSRR |= GPIO_BSRR_BS_5;
  //GPIOA->BSRR |= GPIO_BSRR_BS_5;

  while (1)
    {



      // Read the button.
      if (GPIOC->IDR && GPIO_IDR_ID13_Msk)
	{
	  // Turn on the led
	  GPIOA->BSRR |= GPIO_BSRR_BS_5;

	}
      else
	{
	  // Pressed
	  // Turn off the led
	  GPIOA->BRR |= GPIO_BRR_BR_5;

	}

    }
}
