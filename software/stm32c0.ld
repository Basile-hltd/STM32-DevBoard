MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 32K
    SRAM  (rwx) : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
    .vectors : { *(.vectors) } > FLASH
    .text    : { *(.text*)   } > FLASH
    .rodata  : { *(.rodata*) } > FLASH
    .data    : { *(.data*)   } > SRAM AT > FLASH
    .bss     : { *(.bss*)    } > SRAM
}