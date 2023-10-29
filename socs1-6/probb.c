#include <stdio.h>

void print_sum(int pos, int sum, int data[], int array_size);

int main() {
  int T;
  scanf("%d", &T);
  int array_size;

  int i;
  for (i = 1; i <= T; i++) {
    scanf("%d", &array_size);
    int data[array_size];

    int j;
    for (j = 0; j < array_size; j++) {
      scanf("%d", &data[j]);
    }
    printf("Case #%d:\n", i);
    print_sum(0, 0, data, array_size);
  }
  return 0;
}

void print_sum(int pos, int sum, int data[], int array_size) {
  int x = data[pos];
  if (pos * 2 + 1 < array_size) {
    print_sum(pos * 2 + 1, sum + x, data, array_size);
    if (pos * 2 + 2 < array_size) {
      print_sum(pos * 2 + 2, sum + x, data, array_size);
    }
  } else {
    printf("%d\n", sum + x);
  }
}