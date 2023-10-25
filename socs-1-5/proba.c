#include <stdio.h>

int main() {
  int tests;
  scanf("%d", &tests);

  for (int i = 1; i <= tests; i++) {
    int n;
    scanf("%d", &n);

    int a[n], b[n], r[n];
     
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[j]);
    }
     
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[j]);
    }
     
    printf("Case #%d: ", i);
     
    for (int j = 0; j < n; j++) {
      int need = a[j] - b[j];
      
      printf("%d", need);
       
      if (j < n - 1) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }

  return 0;
}