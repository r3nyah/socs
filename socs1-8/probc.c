#include <stdio.h>
#include <string.h>

#define Max_Student 100
#define Max_Lecture 100
#define Max_Name 30

typedef struct{
  char code[Max_Name];
  char name[Max_Name];
  char gender[Max_Name];
  int numStudents;
}Lecture;

typedef struct {
  char code[Max_Name];
  char name[Max_Name];
  char gender[Max_Name];
  char fatherName[Max_Name];
  char motherName[Max_Name];
  int siblings;
}Student;

Lecture lectures[Max_Lecture];
Student students[Max_Lecture][Max_Student];

int main() {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%s", lectures[i].code);
    scanf("%s", lectures[i].name);
    scanf("%s", lectures[i].gender);
    scanf("%d", &lectures[i].numStudents);

    for (int j = 0; j < lectures[i].numStudents; j++) {
      scanf("%s", students[i][j].code);
      scanf("%s", students[i][j].name);
      scanf("%s", students[i][j].gender);
      scanf("%s", students[i][j].fatherName);
      scanf("%s", students[i][j].motherName);
      scanf("%d", &students[i][j].siblings);
    }
  }

  int K;
  scanf("%d", &K);

  printf("Kode Dosen: %s\n", lectures[K - 1].code);
  printf("Nama Dosen: %s\n", lectures[K - 1].name);
  printf("Gender Dosen: %s\n", lectures[K - 1].gender);
  printf("Jumlah Mahasiswa: %d\n", lectures[K - 1].numStudents);

  for (int i = 0; i < lectures[K - 1].numStudents; i++) {
    printf("Kode Mahasiswa: %s\n", students[K - 1][i].code);
    printf("Nama Mahasiswa: %s\n", students[K - 1][i].name);
    printf("Gender Mahasiswa: %s\n", students[K - 1][i].gender);
    printf("Nama Ayah: %s\n", students[K - 1][i].fatherName);
    printf("Nama Ibu: %s\n", students[K - 1][i].motherName);
    printf("Jumlah Saudara Kandung: %d\n", students[K - 1][i].siblings);
  }

  return 0;
}
