cmake_minimum_required(VERSION 3.25)
project(MCCourse)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        lib/PS2X_lib
        lib/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/
)

add_executable(
        MCCourse main.cpp
)

add_custom_command(
        OUTPUT file.txt
        COMMAND arduino-cli core list
)