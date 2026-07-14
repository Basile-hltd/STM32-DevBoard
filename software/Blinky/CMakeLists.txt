get_filename_component(APP_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

add_executable(${APP_NAME}.elf
    src/main.c    
)

target_link_libraries(${APP_NAME}.elf PRIVATE STM32_DevBoard_HAL)

set_target_properties(${APP_NAME}.elf PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/
)

add_custom_command(TARGET ${APP_NAME}.elf POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${APP_NAME}.elf> $<TARGET_FILE_DIR:${APP_NAME}.elf>/${APP_NAME}.bin
)

add_custom_target(flash_${APP_NAME}
    DEPENDS ${APP_NAME}.elf
    COMMAND dfu-util -d 0483:df11 -a 0 -D ${CMAKE_SOURCE_DIR}/bin/${APP_NAME}.bin -s 0x08000000:leave || exit 0
    COMMENT "Flash de ${APP_NAME} via dfu-util"
    USES_TERMINAL
)