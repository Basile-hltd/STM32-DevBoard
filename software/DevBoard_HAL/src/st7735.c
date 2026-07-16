#include "STM32_DevBoard.h"

void st7735_dc_cmd(void){
    GPIOD_BSRR = (1U << 18);
}

void st7735_dc_data(void){
    GPIOD_BSRR = (1U << 2);
}

void st7735_rst_low(void){
    GPIOD_BSRR = (1U << 19);
}

void st7735_rst_high(void){
    GPIOD_BSRR = (1U << 3);
}

void st7735_hardware_reset(void){
    st7735_rst_low();
    Delay(20);
    st7735_rst_high();
    Delay(150);
}

void st7735_software_reset(void){
    st7735_spi_write_cmd(0x01);
    Delay(150);
}

void st7735_init(void) {
    
    st7735_hardware_reset();
    st7735_software_reset();

    st7735_spi_write_cmd(0x11);  // SLPOUT (sortie veille)
    Delay(150);

    st7735_spi_write_cmd(0x3A);  // COLMOD
    st7735_spi_write_data(0x05); // 16 bits/pixel (RGB565)
    Delay(10);

    st7735_spi_write_cmd(0x36);     // MADCTL (orientation)
    st7735_spi_write_data(0xA8);    // 1010 10xx

    st7735_spi_write_cmd(0x21);  // INVON

    st7735_spi_write_cmd(0x29);  // DISPON
    Delay(100);

    fill_screen_rgb565(0, 0, 0);
}
