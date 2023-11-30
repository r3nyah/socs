#include <stdio.h>

void insertionSort(long int *array, int size) {
    for (int i = 1; i < size; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= 0 && temp < array[j]) {
            array[j + 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

int main() {
    int arraySize, querySize;
    long int originalArray[1000];
    long int queryArray[1000];

    scanf("%d %d", &arraySize, &querySize);

    for (int i = 0; i < arraySize; i++) {
        scanf("%ld", &originalArray[i]);
    }

    for (int i = 0; i < querySize; i++) {
        scanf("%ld", &queryArray[i]);
    }

    for (int i = 0; i < querySize; i++) {
        for (int j = 0; j < arraySize; j++) {
            if (queryArray[i] == originalArray[j]) {
                originalArray[j] = 0;
            }
        }
    }

    insertionSort(originalArray, arraySize);

    long int max = originalArray[arraySize - 1];
    if (max == 0) {
        max = -1;
    }

    printf("Maximum number is %ld\n", max);

    return 0;
}
