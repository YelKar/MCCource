#define btn 2

int last = -1;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(btn, INPUT_PULLUP);
}
void loop() {
    int val = !digitalRead(btn);  // Если btn возвращает 1, на светодиод выводим 0
    digitalWrite(LED_BUILTIN, val);
    if (val != last) {
        Serial.print("Светодиод ");
        Serial.println(val ? "Включен" : "Выключен");
        last = val;
    }
}
