#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2, discount;
    scanf("%lf %lf", &num1, &num2);

    discount = ((num1 - num2) / num1) * 100;
    discount = round(discount * 100) / 100;
    printf("%.2lf%%\n", discount);

    return 0;
}
