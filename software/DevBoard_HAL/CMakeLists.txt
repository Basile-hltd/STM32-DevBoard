add_library(STM32_DevBoard_HAL STATIC
    src/startup.c    
    src/init.c    
    src/rgb_led.c
)

target_include_directories(STM32_DevBoard_HAL PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/headers
)