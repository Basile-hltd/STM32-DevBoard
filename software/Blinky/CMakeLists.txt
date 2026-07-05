add_executable(firmware.elf
    src/main.c    
)

target_link_libraries(firmware.elf PRIVATE STM32_DevBoard_HAL)

set_target_properties(firmware.elf PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/Blinky
)

add_custom_command(TARGET firmware.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:firmware.elf> $<TARGET_FILE_DIR:firmware.elf>/firmware.bin
)