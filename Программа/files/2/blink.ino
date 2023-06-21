bool val = true;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
    digitalWrite(LED_BUILTIN, val);
    val = !val;
    delay(500);
}
