#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_STRING 50

/*
25 November 2022
github.com/r3nyah/
*/

typedef struct {
    char location1[MAX_STRING];
    char location2[MAX_STRING];
    int price;
    int rooms;
    int bathrooms;
    int carParks;
    char type[MAX_STRING];
    char furnish[MAX_STRING];
} Property;

void displayCSV(const char *filename, int linesToDisplay);

void searchDataFromFile(const char *filename);

void sortDataFromFile(const char *filename, int sortColumn, int sortOrder);
void sortData(Property data[], int n, int column, int ascending);

void exportData(const char *filename, Property data[], int n);


int main() {
    Property properties[MAX_ROWS];
    int numProperties = 0;
    char filename[MAX_STRING];
    int choice;
    char searchTerm[MAX_STRING];

    do {
        printf("\nMenu:\n");
        printf("1. Display data\n");
        printf("2. Search data\n");
        printf("3. Sort data\n");
        printf("4. Export data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int linesToDisplay;
                printf("Enter the CSV file path: ");
                scanf("%s", filename);
                printf("Enter the number of lines to display: ");
                scanf("%d", &linesToDisplay);
                printf("\n");
                displayCSV(filename, linesToDisplay);
                break;
            }
            case 2:
                printf("Enter the CSV file path: ");
                scanf("%s", filename);
                searchDataFromFile(filename);
                break;
            case 3: {
                int sortColumn, sortOrder;
                printf("Enter the CSV file path for sorting: ");
                scanf("%s", filename);
                
                printf("Choose column to sort by:\n");
                printf("1. Price\n");
                printf("2. Rooms\n");
                printf("3. Bathrooms\n");
                printf("4. Car Parks\n");
                printf("Enter your choice: ");
                scanf("%d", &sortColumn);

                printf("Choose sorting order:\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Enter your choice: ");
                scanf("%d", &sortOrder);

                sortDataFromFile(filename, sortColumn, sortOrder);
                break;
            }
            case 4:
                printf("DATA successfully exported\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}

void displayCSV(const char *filename, int linesToDisplay) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    int linesDisplayed = 0;

    while (fgets(line, sizeof(line), file) && linesDisplayed < linesToDisplay) {
        char *token = strtok(line, "\t");

        Property property;

        int i = 0;
        while (token != NULL) {
            switch (i) {
                case 0:
                    strncpy(property.location1, token, sizeof(property.location1) - 1);
                    property.location1[sizeof(property.location1) - 1] = '\0';
                    break;
                case 1:
                    strncpy(property.location2, token, sizeof(property.location2) - 1);
                    property.location2[sizeof(property.location2) - 1] = '\0';
                    break;
                case 2:
                    property.price = atoi(token);
                    break;
                case 3:
                    property.rooms = atoi(token);
                    break;
                case 4:
                    property.bathrooms = atoi(token);
                    break;
                case 5:
                    property.carParks = atoi(token);
                    break;
                case 6:
                    strncpy(property.type, token, sizeof(property.type) - 1);
                    property.type[sizeof(property.type) - 1] = '\0';
                    break;
                case 7:
                    strncpy(property.furnish, token, sizeof(property.furnish) - 1);
                    property.furnish[sizeof(property.furnish) - 1] = '\0';
                    break;
                default:
                    break;
            }

            token = strtok(NULL, "\t");
            i++;
        }

        printf("%-30s%-15s%-10s%-6s%-6s%-6s%-15s%-15s\n", "Location 1", "Location 2", "Price", "Rooms", "Bath", "CP", "Type", "Furnish");
        printf("%-30s%-15s%-10d%-6d%-6d%-6d%-15s%-15s\n", property.location1, property.location2, property.price, property.rooms, property.bathrooms,
        property.carParks, property.type, property.furnish);


        linesDisplayed++;
    }

    fclose(file);
}

void searchDataFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Property property;
    int choice;
    char searchTerm[MAX_STRING];

    printf("Choose column to search:\n");
    printf("1. Location 1\n");
    printf("2. Location 2\n");
    printf("3. Type\n");
    printf("4. Furnish\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
        fclose(file);
        return;
    }

    printf("Enter the data you want to find: ");
    scanf("%s", searchTerm);

    printf("%-30s%-15s%-10s%-6s%-6s%-6s%-15s%-15s\n", "Location 1", "Location 2", "Price", "Rooms", "Bath", "CP", "Type", "Furnish");
    printf("%-30s%-15s%-10d%-6d%-6d%-6d%-15s%-15s\n", property.location1, property.location2, property.price, property.rooms, property.bathrooms,
    property.carParks, property.type, property.furnish);

    int found = 0;

    while (fscanf(file, "%s%s%d%d%d%d%s%s", property.location1, property.location2, &property.price, &property.rooms, &property.bathrooms, &property.carParks, property.type, property.furnish) != EOF) {
        char *searchField;

        switch (choice) {
            case 1:
                searchField = property.location1;
                break;
            case 2:
                searchField = property.location2;
                break;
            case 3:
                searchField = property.type;
                break;
            case 4:
                searchField = property.furnish;
                break;
            default:
                searchField = NULL;
                break;
        }

        if (searchField != NULL && strstr(searchField, searchTerm)) {
            printf("%-30s%-15s%-10s%-6s%-6s%-6s%-15s%-15s\n", "Location 1", "Location 2", "Price", "Rooms", "Bath", "CP", "Type", "Furnish");
            printf("%-30s%-15s%-10d%-6d%-6d%-6d%-15s%-15s\n", property.location1, property.location2, property.price, property.rooms, property.bathrooms,
            property.carParks, property.type, property.furnish);

            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("Data not found.\n");
    }
}

void sortDataFromFile(const char *filename, int sortColumn, int sortOrder) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Property data[MAX_ROWS];
    int n = 0;

    while (fscanf(file, "%s%s%d%d%d%d%s%s", data[n].location1, data[n].location2, &data[n].price, &data[n].rooms, &data[n].bathrooms, &data[n].carParks, data[n].type, data[n].furnish) != EOF) {
        n++;
        if (n >= MAX_ROWS) {
            printf("Too many rows in the file. Consider increasing MAX_ROWS.\n");
            break;
        }
    }

    fclose(file);

    sortData(data, n, sortColumn, sortOrder);

    printf("\n%-30s%-15s%-10s%-6s%-6s%-6s%-15s%-15s\n", "Location 1", "Location 2", "Price", "Rooms", "Bath", "CP", "Type", "Furnish");
    for (int i = 0; i < (n < 10 ? n : 10); i++) {
        printf("%-30s%-15s%-10d%-6d%-6d%-6d%-15s%-15s\n",
               data[i].location1, data[i].location2,
               data[i].price, data[i].rooms, data[i].bathrooms,
               data[i].carParks, data[i].type, data[i].furnish);
    }

    char exportFilename[MAX_STRING];
    printf("Enter the filename to export the sorted data (including .csv extension): ");
    scanf("%s", exportFilename);
    printf("DATA successfully stored, Feel free to export it now :)\n");
    exportData(exportFilename, data, n);
}

int compareColumns(const void *a, const void *b, int column) {
    switch (column) {
        case 1:
            return (*(Property *)a).price - (*(Property *)b).price;
        case 2:
            return (*(Property *)a).rooms - (*(Property *)b).rooms;
        case 3:
            return (*(Property *)a).bathrooms - (*(Property *)b).bathrooms;
        case 4:
            return (*(Property *)a).carParks - (*(Property *)b).carParks;
        default:
            return 0;
    }
}

int comparePricesAscending(const void *a, const void *b) {
    return compareColumns(a, b, 1);
}

int comparePricesDescending(const void *a, const void *b) {
    return compareColumns(b, a, 1);
}

void sortData(Property data[], int n, int column, int sortOrder) {
    int (*compareFunction)(const void *, const void *);

    if (sortOrder == 1) {
        compareFunction = (column == 1) ? comparePricesAscending : NULL;
    } else {
        compareFunction = (column == 1) ? comparePricesDescending : NULL;
    }

    if (compareFunction != NULL) {
        qsort(data, n, sizeof(Property), compareFunction);
    }
}

void exportData(const char *filename, Property data[], int n) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for export");
        return;
    }

    fprintf(file, "Location 1,Location 2,Price,Rooms,Bathrooms,Car Parks,Type,Furnish\n");

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s,%s,%d,%d,%d,%d,%s,%s\n",
               data[i].location1, data[i].location2,
               data[i].price, data[i].rooms, data[i].bathrooms,
               data[i].carParks, data[i].type, data[i].furnish);
    }
    fclose(file);
}