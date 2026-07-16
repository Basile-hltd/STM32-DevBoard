#include "STM32_DevBoard.h"

void STM32_DevBoard_HAL_Init(void){

    //========== Flash init ==========

    FLASH_ACR |= 0x00000001;        // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1
    while ((FLASH_ACR & 0x00000001) == 0);

    //========== END Flash init ==========

    //========== Clock init ==========

    RCC_CR &= ~0x00003800;             // xxxxxxxx xxxxxxxx xx000xxx xxxxxxxx
    while ((RCC_CR & 0x00003800) >= 1);

    RCC_APBENR1 |= 0x00000001;      // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1
    while ((RCC_APBENR1 & 0x00000001) == 0);

    RCC_APBENR2 |= 0x00001000;      // xxxxxxxx xxxxxxxx xxx1xxxx xxxxxxxx
    while ((RCC_APBENR2 & 0x00001000) == 0);

    //========== END Clock init ==========

    //========== RGB_Led init ==========

    RCC_IOPENR |=  0x0000002F;      // xxxxxxxx xxxxxxxx xxxxxxxx xx1x1111 

    GPIOF_MODER &=  ~0x000000CF;    // xxxxxxxx xxxxxxxx xxxxxxxx 00xx0000 
    GPIOF_MODER |=  0x00000045;     // xxxxxxxx xxxxxxxx xxxxxxxx 01xx0101
    
    GPIOF_OTYPER |= 0x0000000B;     // xxxxxxxx xxxxxxxx xxxxxxxx xxxx1011

    //========== END RGB_Led init ==========
    
    //========== Delay init ==========

    TIM2_PSC = 48000 - 1;           // (PSC+1) = 48 → 48MHz/48000 = 1kHz → tick = 1ms
    TIM2_ARR = 0xFFFFFFFF;
    TIM2_CR1 |= 0x0084;             // xxxx0x00 10000100 

    TIM2_EGR |= 0x0001;
    TIM2_SR &= ~0x0001;

    TIM2_CR1 |= 0x0001;             // xxxxxxxx xxxxxxx1 

    TIM2_CNT = 0;

    //========== END Delay init ========== 

    //========== SPI1 init ==========

    GPIOA_MODER &= ~0x0000FC00;     //xxxxxxxx xxxxxxxx 101010xx xxxxxxxx
    GPIOA_MODER |= 0x0000A800;      //xxxxxxxx xxxxxxxx 101010xx xxxxxxxx

    GPIOA_OSPEEDR |= 0x0000FC00;    //xxxxxxxx xxxxxxxx 111111xx xxxxxxxx

    GPIOA_AFRL &= ~0xFFF00000;      //00000000 0000xxxx xxxxxxxx xxxxxxxx

    GPIOD_MODER &= ~0x000000F3;     //xxxxxxxx xxxxxxxx xxxxxxxx 1111xx01
    GPIOD_MODER |= 0x00000051;      //xxxxxxxx xxxxxxxx xxxxxxxx 0101xx01

    GPIOD_OSPEEDR |= 0x000000F3;    //xxxxxxxx xxxxxxxx xxxxxxxx 1111xx11

    GPIOD_ODR |= 0x0000000D;        //xxxxxxxx xxxxxxxx xxxxxxxx xxxx11X1

    SPI1_CR1 = 0x034C;              //00000011 0100 1100
    SPI1_CR2 &= ~0x7FFF;            //x0010111 00000000
    SPI1_CR2 |= 0x1700;             //x0010111 00000000 

    //========== END SPI1 init ========== 

    RGB_Off();
    st7735_init();
}