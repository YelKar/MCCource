#define led 5
#define maxVal 80
int i = 0;
void setup() {
    pinMode(led, OUTPUT);  // Назначаем пин на вывод
}
void loop() {
    analogWrite(led, abs(i));  // Передаем ШИМ-сигнал на пин
    delay(10);
    i++;
    if (i > maxVal) {
        i = -maxVal;
    }
}