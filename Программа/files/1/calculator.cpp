#include "stdio.h"


int main() {
    int a;
    char operation;
    int b;
    while (true) {
        printf("Введите пример в формате \"<число> <операция> <число>\": ");
        scanf("%d %c %d", &a, &operation, &b);
        switch (operation)
        {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '*':
            printf("%lld\n", (long long) a * (long long) b);
            break;
        case '/':
            if (b == 0) {
                printf("!!! Делитель должен быть не равен нулю !!!\n");
                break;
            }
            printf("%d\n", a / b);
            break;
        default:
            printf("Неверный оператор\n ");
        }
    }
}
