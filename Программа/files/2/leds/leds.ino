int leds[] = {10, 11, 12};  // Указываем выводы для светодиодов

int val = 0;

void setup() {
    for (int led : leds) {
        pinMode(led, OUTPUT);  // Устанавливаем пины на выход
    }
}
void loop() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(leds[i], val == i);
    }
    val = ++val % 3;
    delay(500);
}