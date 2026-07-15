#include <stdint.h>

#define FLASH_ACR       (*(volatile uint32_t *)0x40022000UL)

#define RCC_CR          (*(volatile uint32_t *)0x40021000UL)
#define RCC_IOPENR      (*(volatile uint32_t *)0x40021034UL)
#define RCC_APBENR1     (*(volatile uint32_t *)0x4002103CUL)

#define GPIOF           (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_MODER     (*(volatile uint32_t *)0x50001400UL)
#define GPIOF_OTYPER    (*(volatile uint32_t *)0x50001404UL)
#define GPIOF_PUPDR     (*(volatile uint32_t *)0x5000140CUL)
#define GPIOF_ODR       (*(volatile uint32_t *)0x50001414UL)

#define TIM2_CR1        (*(volatile uint32_t *)0x40000000UL)
#define TIM2_DIER       (*(volatile uint32_t *)0x4000000CUL)
#define TIM2_SR         (*(volatile uint32_t *)0x40000010UL)
#define TIM2_EGR        (*(volatile uint32_t *)0x40000014UL)
#define TIM2_CNT        (*(volatile uint32_t *)0x40000024UL)
#define TIM2_PSC        (*(volatile uint32_t *)0x40000028UL)
#define TIM2_ARR        (*(volatile uint32_t *)0x4000002CUL)