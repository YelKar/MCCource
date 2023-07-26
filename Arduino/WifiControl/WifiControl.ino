#include "ArduinoJson.h"
#include "machine.h"
#include "Server.h"

/*
Объявляем макросы для моторов
|| Номер пина отвечающего за движение вперед
|| Номер ШИМ-канала для движения вперед
|| Номер пина отвечающего за движение вперед
*/

// Левый передний
#define flfd  23
#define flpwm 0
#define flbd  22

// Левый задний
#define blfd  19
#define blpwm 1
#define blbd  18

// Правый задний
#define frfd  0
#define frpwm 2
#define frbd  4

// Правый передний
#define brfd  16
#define brpwm 3
#define brbd  17


#define pwmFreq 1000

char* ssid = "MGTS_GPON_FE9E";
char* pwd = "xCRQTeuF";

void setup() {
    Serial.begin(9600);
    
    // Настраиваем ШИМ-каналы
    ledcSetup(flpwm, pwmFreq, 8);
    ledcSetup(blpwm, pwmFreq, 8);
    ledcSetup(frpwm, pwmFreq, 8);
    ledcSetup(brpwm, pwmFreq, 8);

    // Настраиваем режимы пинов и подключаем ШИМ-каналы к пинам отвечающим за движение вперед
    ledcAttachPin(flfd, flpwm);
    pinMode(flbd, OUTPUT);

    ledcAttachPin(blfd, blpwm);
    pinMode(blbd, OUTPUT);

    ledcAttachPin(frfd, frpwm);
    pinMode(frbd, OUTPUT);

    ledcAttachPin(brfd, brpwm);
    pinMode(brbd, OUTPUT);
    
    pinMode(LED_BUILTIN, OUTPUT);

    digitalWrite(LED_BUILTIN, LOW);
    
    Serial.println((String) ssid + " " + pwd);
    setupWifi(ssid, pwd);

    // При подключении к WiFi, включаем встроенный пин
    digitalWrite(LED_BUILTIN, HIGH);
}

ctrl::Motor fl(flpwm, flbd);
ctrl::Motor bl(blpwm, blbd);
ctrl::Motor fr(frpwm, frbd);
ctrl::Motor br(brpwm, brbd);

ctrl::Machine m(&fl, &fr, &bl, &br);

int a[] = {150, 0, -150, 0};
int c = 0;

String json;

void loop() {
    Serial.println("GET:");
    Serial.print(json = get());
    if (json) {
        Serial.println("JSON:");
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, json);
        Serial.print("JSON deserialized\n\n");
        Serial.println(c++);
        int rx = doc["rightX"];
        int ry = doc["rightY"];
        int lx = doc["leftX"];
        m.y(ry);
        m.x(rx);
        m.rotate(lx);
        m.update();
        Serial.println("END\n\n\n");
    }
}
