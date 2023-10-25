#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}

void swap_case(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] -= 32;
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    char str[1000];
    scanf("%s", str);

    reverse_string(str);
    swap_case(str);

    printf("Case #%d: %s\n", i, str);
  }

  return 0;
}
