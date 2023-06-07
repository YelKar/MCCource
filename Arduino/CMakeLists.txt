cmake_minimum_required(VERSION 3.25)
project(JoystickPS2)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        lib/PS2X_lib
        lib/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/avr/include/
        C:/Users/karam/AppData/Local/Arduino15/packages/esp8266/hardware/esp8266/3.1.2/libraries/ESP8266WiFi/src
        C:/Users/karam/AppData/Local/Arduino15/packages/arduino/hardware/avr/1.8.6/firmwares/wifishield/wifiHD/src
        C:/Users/karam/AppData/Local/Arduino15/packages/esp32/hardware/esp32/1.0.6/libraries/WiFi/src
)

add_executable(
        JoystickPS2 main.cpp
        Client Client/Client.ino
        JoystickPS2 JoystickPS2/JoystickPS2.ino
        WifiControl WifiControl/WifiControl.ino
)

add_custom_command(
        OUTPUT file.txt
        COMMAND arduino-cli core list
)