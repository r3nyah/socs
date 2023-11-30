#include <stdio.h>
#include <string.h>

struct student {
  char name[11];
  int score;
} students[1001], tempStudent;

int main() {
  int testCaseCount;
  scanf("%d", &testCaseCount);

  for (int testCaseIndex = 1; testCaseIndex <= testCaseCount; testCaseIndex++) {
    int studentCount;
    scanf("%d", &studentCount); getchar();

    for (int studentIndex = 0; studentIndex < studentCount; studentIndex++) {
      scanf("%[^#]#%d", &students[studentIndex].name, &students[studentIndex].score); getchar();
    }

    for (int i = 0; i < studentCount - 1; i++) {
      for (int j = 0; j < studentCount - 1 - i; j++) {
        if (strcmp(students[j].name, students[j + 1].name) > 0) {
          tempStudent = students[j];
          students[j] = students[j + 1];
          students[j + 1] = tempStudent;
        }
      }
    }

    for (int i = 0; i < studentCount - 1; i++) {
      for (int j = 0; j < studentCount - 1 - i; j++) {
        if (students[j].score < students[j + 1].score) {
          tempStudent = students[j];
          students[j] = students[j + 1];
          students[j + 1] = tempStudent;
        }
      }
    }

    char searchName[11];
    scanf("%s", searchName); getchar();

    printf("Case #%d: ", testCaseIndex);

    for (int i = 0; i < studentCount; i++) {
      if (strcmp(students[i].name, searchName) == 0) {
        printf("%d\n", i + 1);
      }
    }
  }
}
