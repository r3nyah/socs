#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Entries {
    char name[41];
    int number;
};

void bubbleSort(struct Entries *arr, int size) {
    struct Entries temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");

    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    int numEntries;
    fscanf(file, "%d", &numEntries);

    struct Entries entries[1000];

    for (int i = 0; i < numEntries; i++) {
        fscanf(file, "%d#%[^\n]", &entries[i].number, entries[i].name);
    }

    fclose(file);

    bubbleSort(entries, numEntries);

    for (int i = 0; i < numEntries; i++) {
        printf("%d %s\n", entries[i].number, entries[i].name);
    }

    return 0;
}
