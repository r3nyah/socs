#include <stdio.h>

int main() {
    int Phy, Mag, Pur;
    scanf("%d %d %d", &Phy, &Mag, &Pur);

    double jojoDamage = (0.2 * Phy) + (0.3 * Mag) + (0.5 * Pur);

    printf("%.2lf\n", jojoDamage);

    return 0;
}
