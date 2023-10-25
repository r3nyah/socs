#include <stdio.h>
#include <string.h>

int isPalindrome(char *word);

int main() {
    int T;
    scanf("%d", &T);

    for (int case_num = 1; case_num <= T; case_num++) {
        char word[500];
        scanf("%s", word);

        printf("Case #%d: ", case_num);

        if (isPalindrome(word)) {
            printf("Yay, it's a palindrome\n");
        } else {
            printf("Nah, it's not a palindrome\n");
        }
    }

    return 0;
}

int isPalindrome(char *word) {
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++) {
        if (word[i] != word[len - i - 1]) {
            return 0; // Not a palindrome
        }
    }
    return 1; // Palindrome
}