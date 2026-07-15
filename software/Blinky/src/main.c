#include "STM32_DevBoard.h"

int main(){
    
    STM32_DevBoard_HAL_Init();

    RGB_Off();

    rgb_led_color color = BLACK;

    Delay(500);

    while(1){
        color = (color + 1) % RGB_LED_COLOR_COUNT;
        RGB_SetColor(color);

        Delay(500);

        RGB_Off();
        
        Delay(500);
    }

}

