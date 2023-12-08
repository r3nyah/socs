#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1010
#define MAX_DATA_ENTRIES 100

struct VideoData {
    char length[MAX_STRING_LENGTH];
    char title[MAX_STRING_LENGTH];
    long long int views;
};


int readDataFromFile(const char *filename, struct VideoData data[], int *numEntries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%[^#]#%[^%#]#%lld\n", data[count].length, data[count].title, &data[count].views) == 3) {
        count++;
        if (count >= MAX_DATA_ENTRIES) {
            printf("Exceeded maximum number of data entries.\n");
            break;
        }
    }

    fclose(file);
    *numEntries = count;
    return 1;
}

void sortData(struct VideoData data[], int numEntries) {
    int i, j;
    struct VideoData temp;

    for (i = 0; i < numEntries - 1; i++) {
        for (j = 0; j < numEntries - 1 - i; j++) {
            if (strcmp(data[j].length, data[j + 1].length) > 0) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < numEntries - 1; i++) {
        for (j = 0; j < numEntries - 1 - i; j++) {
            if (data[j].views < data[j + 1].views) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void displaySortedData(const struct VideoData data[], int numEntries) {
    int i;
    for (i = 0; i < numEntries; i++) {
        printf("%s by %s - %lld\n", data[i].length, data[i].title, data[i].views);
    }
}

int main() {
    struct VideoData videoData[MAX_DATA_ENTRIES];
    int numEntries = 0;

    if (readDataFromFile("testdata.in", videoData, &numEntries)) {
        sortData(videoData, numEntries);

        displaySortedData(videoData, numEntries);
    }

    return 0;
}
