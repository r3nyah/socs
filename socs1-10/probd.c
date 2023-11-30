#include <stdio.h>

void main() {
    int numberOfTasks;
    scanf("%d", &numberOfTasks);

    int taskDifficulty[numberOfTasks];

    for (int i = 0; i < numberOfTasks; i++) {
        scanf("%d", &taskDifficulty[i]);
    }

    int totalDifficulty = 0;

    for (int i = 0; i < numberOfTasks; i++) {
        totalDifficulty += taskDifficulty[i];
    }

    if (totalDifficulty > 0) {
        printf("not easy\n");
    } else {
        printf("easy\n");
    }
}
