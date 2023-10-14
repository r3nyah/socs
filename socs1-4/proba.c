#include <stdio.h>

int main() {
    int number;

    scanf("%d", &number);

    if (number % 2 == 0) {
        printf("EVEN\n", number);
    } else {
        printf("ODD\n", number);
    }

    return 0;
}
