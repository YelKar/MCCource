#define btn 2

int val = 0;

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(btn, INPUT_PULLUP);
}
void loop() {
    while (digitalRead(btn));
    delay(50);
    while (!digitalRead(btn));

    digitalWrite(LED_BUILTIN, val = !val);

    Serial.print("Светодиод ");
    Serial.println(val ? "Включен" : "Выключен");

    delay(50);
}