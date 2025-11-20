#include <stdio.h>
#include <string.h>

int leds_por_digito[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calcular_leds(const char *numero) {
    int total_leds = 0;
    for (int i = 0; numero[i] != '\0'; i++) {
        total_leds += leds_por_digito[numero[i] - '0'];
    }
    return total_leds;
}

int main() {
    int N;
    char numero[101];
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", numero);
        printf("%d leds\n", calcular_leds(numero));
    }
    
    return 0;
}