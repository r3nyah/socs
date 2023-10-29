#include <stdio.h>

int compute(int n, int *num_divisible_by_3);

int main() {
  int T;
  scanf("%d", &T);

  for (int i = 1; i <= T; i++) {
    int N;
    scanf("%d", &N);

    int num_divisible_by_3 = 0;
    int result = compute(N, &num_divisible_by_3);

    printf("Case #%d: %d %d\n", i, result, num_divisible_by_3);
  }

  return 0;
}

int compute(int n, int *num_divisible_by_3) {
  if (n == 0)
    return 1;
  if (n == 1)
    return 2;

  if (n % 3 == 0) {
    (*num_divisible_by_3)++;
  }

  if (n % 5 == 0) {
    return 2 * n;
  }

  return compute(n - 1, num_divisible_by_3) + n + compute(n - 2, num_divisible_by_3) + (n - 2);
}