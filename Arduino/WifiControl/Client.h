#include "WiFi.h"


WiFiClient client;
const IPAddress serverIP(192,168,1,7);
uint16_t serverPort = 9999;

void setupWifi(char * ssid, char * pwd) {
    // Подключаемся к WiFi
    WiFi.begin(ssid, pwd);
    Serial.print("\n\n\nConnecting...");

    // Ждём подкючения
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\n");
    Serial.println("Connected!");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());
}

String get() {
    // While not Connected
    GET:
    String line;
    if (client.connect(serverIP, serverPort))
    {
        while (!(client.available() || client.connected()));
        // Когда получаем информацию, считываем её
        line = client.readStringUntil('/');
    }
    else
    {
        // Если нет соединения, переходим в начало функции
        Serial.println("Access failed");
        client.stop();
        goto GET;
    }
    return line;
}
