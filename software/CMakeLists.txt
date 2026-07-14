cmake_minimum_required(VERSION 3.10)
project(STM32_DevBoard)

find_program(OBJCOPY arm-none-eabi-objcopy REQUIRED)
find_program(DFU_UTIL dfu-util REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(MCU_FLAGS "-mcpu=cortex-m0plus -mthumb -mfloat-abi=soft")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MCU_FLAGS} -Wall -ffunction-sections -fdata-sections -nostdlib")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${CMAKE_CURRENT_SOURCE_DIR}/stm32c0.ld ${MCU_FLAGS} -nostartfiles -Wl,--gc-sections")

add_subdirectory(DevBoard_HAL)
add_subdirectory(Blinky)