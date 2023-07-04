#include "stdio.h"


int main() {
    printf("while:\n");

    int a = 10;
    while (a > 0) {
        printf("%d\n", --a);
    }
}