#include <stdio.h>

int main() {
    double num1, num2, percentage;
    scanf("%lf %lf", &num1, &num2);

    percentage = (num2 / num1) * 100;
    printf("%.4lf%%\n", percentage);

    return 0;
}
