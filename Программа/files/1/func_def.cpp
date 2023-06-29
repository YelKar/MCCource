#include <stdio.h>


long long factorial(int);

int main() {
    printf("%lld\n", factorial(2));
    printf("%lld\n", factorial(5));
    printf("%lld\n", factorial(8));
    printf("%lld\n", factorial(10));
}

long long factorial(int a) {
    if (a <= 1) {
        return 1;
    }
    return a * factorial(a - 1);
}

