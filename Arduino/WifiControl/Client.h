#include "WiFi.h"


WiFiUDP Udp;
char packetBuffer[255];

const IPAddress serverIP(192,168,1,6);
uint16_t serverPort = 1111;

IPAddress clientIP(192, 168, 1, 20);
IPAddress Subnet(255, 255, 255, 0);

void setupWifi(char * ssid, char * pwd) {
    // Подключаемся к WiFi
    WiFi.begin(ssid, pwd);
    WiFi.mode(WIFI_STA);
    Serial.print("\n\n\nConnecting...");

    // Ждём подкючения
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    WiFi.config(clientIP, serverIP, Subnet);
    Udp.begin(serverPort);
    Serial.println("\n");
    Serial.println("Connected!");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());
}

String get() {
    int packageSize = 0;
    Udp.beginPacket(serverIP, serverPort);
    Udp.println("GET");
    Udp.endPacket();
    packageSize = Udp.parsePacket();
    Udp.read(packetBuffer, packageSize);

    String msg = packetBuffer;
    msg.trim();

    Serial.print("JSON: ");
    Serial.println(msg);
    return msg;
}
