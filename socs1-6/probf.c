#include <stdio.h>

int jojonanci();

int main() {
  int t, n, x, y;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d %d", &n, &x, &y);
    printf("Case #%d: %d\n", i, jojonanci(n, x, y));
  }
  return 0;
}

int jojonanci(int n, int x, int y) {
  if (n == 0) {
    return x;
  } else if (n == 1) {
    return y;
  } else {
    return jojonanci(n - 1, x, y) - jojonanci(n - 2, x, y);
  }
}