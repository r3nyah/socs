#include <stdio.h>

int fibonacci();

int main() {
  int f0, f1, k;
  scanf("%d %d", &f0, &f1);
  scanf("%d", &k);

  printf("%d\n", fibonacci(k, f0, f1)); 

  return 0;
}

int fibonacci(int n, int f0, int f1) {
  if (n == 0) {
    return f0;
  } else if (n == 1) {
    return f1;
  } else {
    return fibonacci(n - 1, f0, f1) + fibonacci(n - 2, f0, f1);
  }
}
