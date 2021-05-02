cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_air C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(air
        air.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(air pico_stdlib hardware_i2c)

pico_enable_stdio_usb(air 1)
pico_enable_stdio_uart(air 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(air)
