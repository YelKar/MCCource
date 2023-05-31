#include "Arduino.h"
#include "machine.h"
#include "PS2X_lib.h"
// motor
#define fd 6
#define bd 7

// ps2x
#define ps2_data A3
#define ps2_cmd A2
#define ps2_atn A1
#define ps2_clk A0
PS2X ps2x;

void setup() {
    Serial.begin(9600);
    Serial.setTimeout(10);
    pinMode(fd, OUTPUT);
    pinMode(bd, OUTPUT);
    int error = ps2x.config_gamepad(ps2_clk, ps2_cmd, ps2_atn, ps2_data, false, false);
    Serial.println(error);
    if(error == 0){
        Serial.println("Found Controller, configured successful");
        Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    // Serial.println("holding L1 or R1 will print out the analog stick values.");
    // Serial.println("Go to www.billporter.info for updates and to report bugs.");
   }
}
char out[32];
int a;

void loop() {
    bool success = ps2x.read_gamepad(false, 0);
    ps2x.reconfig_gamepad();

    if (success) {
        int r[] = {
            ps2x.Analog(PSS_LX), ps2x.Analog(PSS_LY),
            ps2x.Analog(PSS_RX), ps2x.Analog(PSS_RY),
        };
        a = map(r[1], 0, 255, -255, 255);
        sprintf(out, "lx=%d\tly=%d\trx=%d\try=%d", r[0], r[1], r[2], r[3]);
        Serial.println(out);
    }
    delay(10);
    Serial.println(a);
}
