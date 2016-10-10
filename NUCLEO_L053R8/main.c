/**
 * Hello world
 */

#include "stm32l0xx.h"
#include "stm32l0xx_nucleo.h"

int
main (void)
{
  // Enable GPIOA clock
  RCC->IOPENR |= RCC_IOPENR_IOPAEN;
  // Pin 5 output mode: 01
  // - first set as: 00
  GPIOA->MODER &= ~(GPIO_MODER_MODE5);
  // - then set: 01
  GPIOA->MODER |= GPIO_MODER_MODE5_1;
  // Output type Push/Pull
  GPIOA->OTYPER |= GPIO_OTYPER_OT_5;
  // Pin speed - low speed: 00 (inverse of 11)
  GPIOA->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEED5);
  // No pull up nor pull down
  GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5);

  while (1)
    {

    }
}
