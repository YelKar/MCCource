#include "Arduino.h"
#include "machine.h"
#include "PS2X_lib.h"
// motor
#define flf 5
#define flb 6
#define frf 7
#define frb 8
#define blf 9
#define blb 10
#define brf 11
#define brb 12

// ps2x
#define ps2_data A3
#define ps2_cmd A2
#define ps2_atn A1
#define ps2_clk A0
PS2X ps2x;

void setup() {
    Serial.begin(9600);
    Serial.setTimeout(10);
    for (int i = 5; i <= 12; i++) {
        pinMode(i, OUTPUT);
    }
    int error = ps2x.config_gamepad(ps2_clk, ps2_cmd, ps2_atn, ps2_data, false, false);
    Serial.println(error);
    if(error == 0){
        Serial.println("Found Controller, configured successful");
        Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    // Serial.println("holding L1 or R1 will print out the analog stick values.");
    // Serial.println("Go to www.billporter.info for updates and to report bugs.");
   }
}
int a;

// Колеса
ctrl::Motor
    FdLt(flf, flb),
    FdRt(frf, frb),
    BdLt(blf, blb),
    BdRt(brf, brb);

ctrl::Machine machine(&FdLt, &FdRt, &BdLt, &BdRt);


void loop() {
    bool success = ps2x.read_gamepad(false, 0);
    ps2x.reconfig_gamepad();

    if (success) {
        int lx = ps2x.Analog(PSS_LX),
            ly = ps2x.Analog(PSS_LY),
            rx = ps2x.Analog(PSS_RX),
            ry = ps2x.Analog(PSS_RY);
        int *r[] = {&lx, &ly, &rx, &ry};
        for (int* m : r) {
            *m = map(*m, 0, 255, -255, 255);
        }
        machine.rotate(lx);
        machine.x(rx);
        machine.y(ry);
    }
    delay(10);
    Serial.println(a);
}
