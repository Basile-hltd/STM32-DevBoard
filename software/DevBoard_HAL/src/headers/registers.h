#include <stdint.h>

#define RCC             (*(volatile uint32_t *)0x40021000UL)
#define RCC_IOPENR      (*(volatile uint32_t *)0x40021034UL)

#define GPIOF           (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_MODER     (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_OTYPER    (*(volatile uint32_t *)0x50001404UL)
#define GPIOF_PUPDR     (*(volatile uint32_t *)0x5000140CUL)
#define GPIOF_ODR       (*(volatile uint32_t *)0x50001414UL)