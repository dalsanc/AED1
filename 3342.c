#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int total_casas = n * n;
    int casas_brancas = (total_casas + 1) / 2;
    int casas_pretas = total_casas / 2;
    printf("%d casas brancas e %d casas pretas\n", casas_brancas, casas_pretas);

    return 0;
}