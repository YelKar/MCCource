#define led LED_BUILTIN
#define maxVal 80
#define pwmChannel 0
#define pwmFrequency 1000 // 1 KHz
#define resolution 8  // 0-255


int i = 0;

void setup() {
    ledcSetup(pwmChannel, pwmFrequency, resolution);  // Назначаем ШИМ
    ledcAttachPin(led, pwmChannel);  // Привязываем ШИМ к пину
}
void loop() {
    ledcWrite(pwmChannel, abs(i));  // Передаем значение в ШИМ-канал
    delay(10);
    i++;
    if (i > maxVal) {
        i = -maxVal;
    }
}