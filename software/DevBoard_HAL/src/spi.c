#include "STM32_DevBoard.h"

void st7735_cs_low(void){
    GPIOD_BSRR = (1U << 16);
}

void st7735_cs_high(void){
    GPIOD_BSRR = (1U << 0);
}

uint8_t spi1_transfer(uint8_t data) {

    while (!(SPI1_SR & (1U << 1)));   // attendre TXE
    *(volatile uint8_t *)&SPI1_DR = data;

    while (!(SPI1_SR & (1U << 0)));   // attendre RXNE
    uint8_t rx = *(volatile uint8_t *)&SPI1_DR;

    return rx;

}

void st7735_spi_write_cmd(uint8_t cmd) {
    st7735_dc_cmd();
    st7735_cs_low();
    spi1_transfer(cmd);
    st7735_cs_high();
}

void st7735_spi_write_data(uint8_t data) {
    st7735_dc_data();
    st7735_cs_low();
    spi1_transfer(data);
    st7735_cs_high();
}
