#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50
#define MAX_NOME 51

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        char produtos[MAX_PRODUTOS][MAX_NOME];
        double precos[MAX_PRODUTOS];

        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i], &precos[i]);
        }

        int P;
        scanf("%d", &P);

        double total = 0.0;

        for (int i = 0; i < P; i++) {
            char nome[MAX_NOME];
            int quantidade;
            scanf("%s %d", nome, &quantidade);

            for (int j = 0; j < M; j++) {
                if (strcmp(nome, produtos[j]) == 0) {
                    total += precos[j] * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}
