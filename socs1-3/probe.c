#include <stdio.h>

int main() {
    int var;
    scanf("%d", &var);

    if (var == 3) {
        int A1, A2, A3;
        scanf("%d %d %d", &A1, &A2, &A3);
        double reamur1 = 0.8 * A1;
        double fahrenheit1 = (A1 * 9.0 / 5.0) + 32.0;
        double kelvin1 = A1 + 273;

        double reamur2 = 0.8 * A2;
        double fahrenheit2 = (A2 * 9.0 / 5.0) + 32.0;
        double kelvin2 = A2 + 273;

        double reamur3 = 0.8 * A3;
        double fahrenheit3 = (A3 * 9.0 / 5.0) + 32.0;
        double kelvin3 = A3 + 273;

        printf("%.2lf %.2lf %.2lf\n", reamur1, fahrenheit1, kelvin1);
        printf("%.2lf %.2lf %.2lf\n", reamur2, fahrenheit2, kelvin2);
        printf("%.2lf %.2lf %.2lf\n", reamur3, fahrenheit3, kelvin3);
    }

    return 0;
}
