#include <stdio.h>
#include <string.h>

int main() {
    char name[102];

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Congrats \"%s\" for joining the CS department at BINUS.\n", name);

    return 0;
}
