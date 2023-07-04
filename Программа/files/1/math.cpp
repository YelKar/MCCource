#include "stdio.h"


int main() {
    int a = 10;
    int b = 4;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d // %d = %d\n", a, b, a / b);
    printf("%d / %d = %.1f\n", a, b, a / (double) b);
    printf("%d %% %d = %d\n", a, b, a % b);
}
