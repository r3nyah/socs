#include <stdio.h>

// Init Method for line[34] and line [43]
char invert_caps(char letter);
void reverseString(char *str, int length);

// Run Main here
int main() {
    char str[100]; //String max length is 100
    int length;

    printf("---Assignment-AOL-Case Study 1---\n");
    printf("Input\t: ");
    scanf("%s", str); // Read or Get data for line[9]

    // do repeatation for calculate string length
    length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // do invert capitalization here
    for (int i = 0; i < length; i++) {
        str[i] = invert_caps(str[i]); // Call method down below[34] and put it on str array with i length
    }

    // Call method down below[43]
    reverseString(str, length);

    printf("Onput\t: %s\n", str);

    return 0;
}

// fill method(will be called by [23])
char invert_caps(char letter) {
    if (letter >= 'A' && letter <= 'Z') {
        letter = letter + ('a' - 'A'); // Convert uppercase to lowercase
    } else if (letter >= 'a' && letter <= 'z') {
        letter = letter - ('a' - 'A'); // Convert lowercase to uppercase
    }
    return letter;
}

// fill method(will be called by [27])
void reverseString(char *str, int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        // Swap characters at start and end
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
}
