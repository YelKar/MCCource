#include "ESP8266WiFi.h"

//char* ssid = "Wifi";
//char* pwd = "password";


void setup() {
    Serial.begin(9600);
    Serial.println("Hello");
    WiFi.begin("Wifi", "password");
    Serial.print("\n\n\nConnecting...");
    
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\n\nConnected");
    Serial.print("IP Address:");
    Serial.println(WiFi.localIP());
}


WiFiClient client;
const IPAddress serverIP(192,168,224,89);
uint16_t serverPort = 9999;

void loop() {
    if (client.connect(serverIP, serverPort)) //Try to access the target address
    {
        while (!(client.available() || client.connected()));
        String line = client.readStringUntil('}');
        Serial.println(line);
    }
    else
    {
        Serial.println("Access failed");
        client.stop(); //Close the client
    }
    delay(100);
}
