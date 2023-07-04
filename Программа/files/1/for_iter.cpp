#include "stdio.h"


int main() {
    printf("for string:\n");
    for (char letter : "Hello, world") {
        if (letter != '\0') {
            printf("%c_", letter);
        }
    }
    printf("!\n");

    printf("\nfor string with check zero symbol:\n");
    for (char letter : "Hello, world") {
        printf("%c_", letter);
    }
    printf("!\n\n");
}
