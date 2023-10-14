#include <stdio.h>

void main() {
    int testCase;
    scanf("%d", &testCase);

    for (int i = 1; i <= testCase; i++) {
        int numA;
        int numB;
        scanf("%d %d", &numA, &numB);

        printf("Case #%d: ", i);
        if (numA > numB) {
            printf("Go-Jo\n");
        } else {
            printf("Bi-Pay\n");
        }
    }

}