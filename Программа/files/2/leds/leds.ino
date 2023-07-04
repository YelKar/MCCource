int leds[] = {10, 11, 12};  // Указываем выводы для светодиодов

int val = 0;

void setup() {
  Serial.begin(9600);
    for (int led : leds) {
        pinMode(led, OUTPUT);  // Устанавливаем пины на выход
    }
}
void loop() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(leds[i], val == i);
        Serial.print("LED-");
        Serial.print(leds[i]);
        Serial.print(":\t");
        Serial.print(val == i ? "on" : "off");
        Serial.print("\t");
    }
    Serial.println();
    val = ++val % 3;
    delay(500);
}