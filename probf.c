#include <stdio.h>

void main() {
    int numberOfTestCases;
    scanf("%d", &numberOfTestCases);
    int testCaseNumber = 1;

    while (numberOfTestCases--) {
        int numberOfElements, targetValue;
        scanf("%d %d", &numberOfElements, &targetValue);
        int frequencies[numberOfElements];

        int i, j;
        for (i = 0; i < numberOfElements; i++) {
            scanf("%d", &frequencies[i]);
        }

        int temp;
        int swapCount = 0;
        for (i = 0; i < (numberOfElements - 1); i++) {
            for (j = 0; j < (numberOfElements - 1 - i); j++) {
                if (frequencies[j] > frequencies[j + 1]) {
                    temp = frequencies[j];
                    frequencies[j] = frequencies[j + 1];
                    frequencies[j + 1] = temp;
                    swapCount = swapCount + targetValue;
                }
            }
        }
        printf("Case #%d: %d\n", testCaseNumber, swapCount);
        testCaseNumber++;
    }
}
