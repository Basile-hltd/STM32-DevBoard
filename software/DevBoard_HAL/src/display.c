#include "STM32_DevBoard.h"

void set_x_bounding(uint16_t start, uint16_t end){
    st7735_spi_write_cmd(0x2A);

    st7735_spi_write_data(start >> 8);
    st7735_spi_write_data(start);
    st7735_spi_write_data(end >> 8);
    st7735_spi_write_data(end);
}

void set_y_bounding(uint16_t start, uint16_t end){
    st7735_spi_write_cmd(0x2B);

    st7735_spi_write_data(start >> 8);
    st7735_spi_write_data(start);
    st7735_spi_write_data(end >> 8);
    st7735_spi_write_data(end);
}

void fill_screen_rgb565(uint8_t red, uint8_t green, uint8_t blue){

    set_x_bounding(1, 1+ST7735_WIDTH-1);
    set_y_bounding(26, 26+ST7735_HEIGHT-1);

    st7735_spi_write_cmd(0x2C);
    st7735_dc_data();
    st7735_cs_low();
    for (unsigned char y = 0; y < ST7735_HEIGHT; y++){
        for (unsigned char x = 0; x < ST7735_WIDTH; x++){
            spi1_transfer(red << 3 | (green>>3)); 
            spi1_transfer(red << 5 | blue); 
        }
    }
    st7735_cs_high();

}

void draw_char(unsigned char x, unsigned char y, char c){
    
    const uint16_t* bitmap = NULL;

    if (c >= '0' && c <= '9'){
        bitmap = num_font[c-0x30]; 
    }
    else{
        return;
    }

    set_x_bounding(1+x*10, 1+x*10 + 9);
    set_y_bounding(26+y*10, 26+y*10 + 9);    

    st7735_spi_write_cmd(0x2C);
    st7735_dc_data();
    st7735_cs_low();
    for (unsigned char y = 0; y < 10; y++){
        for (unsigned char x = 0; x < 10; x++){
            if (bitmap[y] & (1 << (9 - x))){
                spi1_transfer(0xff);  
                spi1_transfer(0xff);
            }
            else{
                spi1_transfer(0x00);  
                spi1_transfer(0x00); 
            }
        }
    }
    st7735_cs_high();
}
