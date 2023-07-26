#include <WiFi.h>

WiFiUDP Udp; // Creation of wifi Udp instance

char packetBuffer[255];


IPAddress clientIP(192, 168, 1, 20);
IPAddress serverIP(192, 168, 1, 20);
IPAddress Subnet(255, 255, 255, 0);
unsigned int localPort = 9999;

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
    Udp.begin(localPort);
    Serial.println("\n");
    Serial.println("Connected!");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());
}

String get() {
    int packetSize;
    while ((packetSize = Udp.parsePacket()) < 60);
    Udp.read(packetBuffer, packetSize);
    String msg = packetBuffer;
    msg.trim();

    Serial.print("JSON: ");
    Serial.println(msg);
    return msg;
}