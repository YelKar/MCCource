#include "WiFi.h"


WiFiClient client;
const IPAddress serverIP(192,168,1,7);
uint16_t serverPort = 9999;

void setupWifi(char * ssid, char * pwd) {
    WiFi.begin(ssid, pwd);
    Serial.print("\n\n\nConnecting...");

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
    GET:
    String line;
    if (client.connect(serverIP, serverPort)) //Try to access the target address
    {
        while (!(client.available() || client.connected()));
        line = client.readStringUntil('/');
    }
    else
    {
        Serial.println("Access failed");
        client.stop(); //Close the client
        goto GET;
    }
    return line;
}
