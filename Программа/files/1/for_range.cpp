#include "stdio.h"


int main() {
    printf("for with increment:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
    }
    printf("\nfor with some step:\n");
    int step = 13;
    int min = -100;
    int max = 25;
    for (int i = min; i < max; i += step) {
        printf("%d\n", i);
    }
}
