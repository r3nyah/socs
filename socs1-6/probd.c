#include <stdio.h>

int fibonacci_call_count = 0;
int fibonacci();

int main() {
  int t, n;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d", &n);
    fibonacci_call_count = 0;
    fibonacci(n);
    printf("Case #%d: %d\n", i, fibonacci_call_count);
  }
  return 0;
}

int fibonacci(int n) {
  fibonacci_call_count++;
  if (n == 0 || n == 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}