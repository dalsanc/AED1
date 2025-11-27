#include <stdio.h>

int main() {
    double F1, F2, total;
    scanf("%lf %lf", &F1, &F2);
    total = (1 + F1 / 100) * (1 + F2 / 100) - 1;
    printf("%.6lf\n", total * 100);
    return 0;
}