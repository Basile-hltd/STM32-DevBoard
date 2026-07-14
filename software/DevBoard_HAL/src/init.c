#include "STM32_DevBoard.h"

void STM32_DevBoard_HAL_Init(void){

    //========== Flash init ==========

    FLASH_ACR |= 0x00000001;        // xxxxxxxx xxxxxxxx xxxxxxxx xxxxxxx1
    while ((FLASH_ACR & 0x00000001) == 0);

    //========== Clock init ==========

    RCC &= ~0x00003800;             // xxxxxxxx xxxxxxxx xx000xxx xxxxxxxx

    //========== RGB_Led init ==========

    RCC_IOPENR |=  0x0000002F;      // xxxxxxxx xxxxxxxx xxxxxxxx xx1x1111 

    GPIOF_MODER &=  ~0x000000CF;    // xxxxxxxx xxxxxxxx xxxxxxxx 00xx0000 
    GPIOF_MODER |=  0x00000045;     // xxxxxxxx xxxxxxxx xxxxxxxx 01xx0101
    
    GPIOF_OTYPER |= 0x0000000B;     // xxxxxxxx xxxxxxxx xxxxxxxx xxxx1011

    //========== END RGB_Led init ========== 
}