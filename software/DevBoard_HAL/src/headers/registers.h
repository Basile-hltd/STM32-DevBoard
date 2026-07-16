#include <stdint.h>

#define FLASH_ACR       (*(volatile uint32_t *)0x40022000UL)

#define RCC_CR          (*(volatile uint32_t *)0x40021000UL)
#define RCC_IOPENR      (*(volatile uint32_t *)0x40021034UL)
#define RCC_APBENR1     (*(volatile uint32_t *)0x4002103CUL)
#define RCC_APBENR2     (*(volatile uint32_t *)0x40021040UL)

#define GPIOA_MODER     (*(volatile uint32_t *)0x50000000UL)
#define GPIOA_OSPEEDR   (*(volatile uint32_t *)0x50000008UL)
#define GPIOA_AFRL      (*(volatile uint32_t *)0x50000020UL)

#define GPIOD_MODER     (*(volatile uint32_t *)0x50000C00UL)
#define GPIOD_OTYPER    (*(volatile uint32_t *)0x50000C04UL)
#define GPIOD_OSPEEDR   (*(volatile uint32_t *)0x50000C08UL)
#define GPIOD_ODR       (*(volatile uint32_t *)0x50000C14UL)
#define GPIOD_BSRR      (*(volatile uint32_t *)0x50000C18UL)

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

#define SPI1_CR1        (*(volatile uint32_t *)0x40013000UL)
#define SPI1_CR2        (*(volatile uint32_t *)0x40013004UL)
#define SPI1_SR         (*(volatile uint32_t *)0x40013008UL)
#define SPI1_DR         (*(volatile uint32_t *)0x4001300CUL)
#define SPI1_CRCPR      (*(volatile uint32_t *)0x40013010UL)
#define SPI1_RXCRPR     (*(volatile uint32_t *)0x40013014UL)
#define SPI1_TXCRCR     (*(volatile uint32_t *)0x40013018UL)
#define SPI1_I2SCFGR    (*(volatile uint32_t *)0x4001301CUL)
#define SPI1_I2SPR      (*(volatile uint32_t *)0x40013020UL)