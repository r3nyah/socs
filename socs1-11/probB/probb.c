#include <stdio.h>
#include <string.h>

struct Entry {
    char name[41];
    char description[41];
} entries[101];

char searchKey[41];
int numberOfEntries, numberOfQueries, resultIndex;

int binarySearch(char key[]) {
    int mid = 0;
    int left = 0;
    int right = numberOfEntries - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(entries[mid].name, key) > 0) {
            right = mid - 1;
        } else if (strcmp(entries[mid].name, key) < 0) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}


int main() {
    FILE *fileReader = fopen("testdata.in", "r");

    if (fileReader == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fscanf(fileReader, "%d\n", &numberOfEntries);
    int i;
    for (i = 0; i < numberOfEntries; i++) {
        fscanf(fileReader, "%s %[^\n]\n", &entries[i].name, &entries[i].description);
    }

    fscanf(fileReader, "%d", &numberOfQueries);
    int j;
    for (j = 0; j < numberOfQueries; j++) {
        fscanf(fileReader, "%s", searchKey);

        resultIndex = binarySearch(searchKey);
        printf("Case #%d: ", j + 1);
        if (resultIndex != -1) {
            printf("%s\n", entries[resultIndex].description);
        } else {
            printf("N/A\n");
        }
    }
    fclose(fileReader);
    return 0;
}