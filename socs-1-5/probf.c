#include <stdio.h>
#include <string.h>
#include <ctype.h>

char to_capital(char c) {
  if (isalpha(c) && islower(c)) {
    return toupper(c);
  } else {
    return c;
  }
}

char to_number(char c) {
  switch (c) {
    case 'I':
      return '1';
    case 'R':
      return '2';
    case 'E':
      return '3';
    case 'A':
      return '4';
    case 'S':
      return '5';
    case 'G':
      return '6';
    case 'T':
      return '7';
    case 'B':
      return '8';
    case 'P':
      return '9';
    case 'O':
      return '0';
    default:
      return c;
  }
}

int main() {
  char sentence[10000];
  fgets(sentence, sizeof(sentence), stdin);

  for (int i = 0; i < strlen(sentence); i++) {
    if (isalpha(sentence[i])) {
      sentence[i] = to_capital(sentence[i]);
      sentence[i] = to_number(sentence[i]);
    }
  }

  printf("%s", sentence);

  return 0;
}
