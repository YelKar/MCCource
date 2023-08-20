#include "machine.h"
#include "utils.h"
#include "JSON.h"

#include "WiFi.h"
#include "HTTPClient.h"

#include "NewPing.h"


#define flfd  4
#define flpwm 0
#define flbd  16

// Левый задний
#define blfd  0
#define blpwm 1
#define blbd  15

// Правый задний
#define frfd  27
#define frpwm 2
#define frbd  14

// Правый передний
#define brfd  12
#define brpwm 3
#define brbd  13


#define pwmFreq 1000


#define FdSonarTrigger 5
#define FdSonarEcho    17

#define BdSonarTrigger 19
#define BdSonarEcho    18

#define maxDist 400

const char ssid[] = "Xiaomi";
const char pwd[]  = "NetCamYCC365PlusT887";

const String url = "http://192.168.1.146:5000/state";


NewPing ForwardSonar(FdSonarTrigger, FdSonarEcho, maxDist);
NewPing BackwardSonar(BdSonarTrigger, BdSonarEcho, maxDist);

void setup() {
    // Подключаем последовательный порт
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

    // Подключаемся к WiFi
    WiFi.begin(ssid, pwd);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected!\n\rCurrent IP: ");
    Serial.println(WiFi.localIP());

    // При подключении к WiFi, включаем встроенный пин
    digitalWrite(LED_BUILTIN, HIGH);
}

ctrl::Motor fl(flpwm, flbd);
ctrl::Motor bl(blpwm, blbd);
ctrl::Motor fr(frpwm, frbd);
ctrl::Motor br(brpwm, brbd);

ctrl::Machine m(&fl, &fr, &bl, &br);

void loop() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        http.begin(url);
        int respCode = http.GET();

        if (respCode > 0) {
            String response = http.getString();
            auto state = utils::deserializeStatus(response);
            m.x(utils::map(state.x));
            m.y(utils::map(-state.y));
            m.rotate(state.turn);
            m.update();
            Serial.println(response);
        }
        http.end();

        http.begin(url);
        char httpRequestData[128];
        DynamicJsonDocument requestJson(128);
        requestJson["FS"] = ForwardSonar.ping_cm();
        requestJson["BS"] = BackwardSonar.ping_cm();

        requestJson["FR"] = m.fr -> currSpeed;
        requestJson["BR"] = m.br -> currSpeed;
        requestJson["FL"] = m.fl -> currSpeed;
        requestJson["BL"] = m.bl -> currSpeed;
        serializeJson(requestJson, httpRequestData);

        int httpResponseCode = http.POST(httpRequestData);
        Serial.println(httpRequestData);
    }
    delay(10);
}
