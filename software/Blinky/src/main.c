#include "STM32_DevBoard.h"

int main(){
    
    STM32_DevBoard_HAL_Init();

    RGB_Off();
    
    Delay(2000);

    RGB_SetColor(RED);

    Delay(1000);

    RGB_SetColor(GREEN);

    Delay(1000);

    RGB_SetColor(BLUE);

    Delay(1000);

    RGB_Off();

    Delay(1000);

    rgb_led_color color = WHITE;

    while(1){
        RGB_SetColor(color);

        Delay(500);

        RGB_Off();

        Delay(500);

        color++;

        if (color >= RGB_LED_COLOR_COUNT-1){
            color = WHITE;
        }

    }

}

