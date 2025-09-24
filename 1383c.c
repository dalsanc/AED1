#include <stdio.h>
#include <stdlib.h>

int valido(int **m) {
    int i, j, k, l, v[10];
    for (i = 0; i < 9; i++) {
        for (j = 1; j <= 9; j++) v[j] = 0;
        for (j = 0; j < 9; j++) v[m[i][j]]++;
        for (j = 1; j <= 9; j++) if (v[j] != 1) return 0;
    }
    for (j = 0; j < 9; j++) {
        for (i = 1; i <= 9; i++) v[i] = 0;
        for (i = 0; i < 9; i++) v[m[i][j]]++;
        for (i = 1; i <= 9; i++) if (v[i] != 1) return 0;
    }
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (k = 1; k <= 9; k++) v[k] = 0;
            for (k = 0; k < 3; k++) for (l = 0; l < 3; l++) v[m[i+k][j+l]]++;
            for (k = 1; k <= 9; k++) if (v[k] != 1) return 0;
        }
    }
    return 1;
}

int main() {
    int n, inst = 1, i, j;
    scanf("%d", &n);
    while (n--) {
        int **m = (int**) malloc(9 * sizeof(int*));
        for (i = 0; i < 9; i++) m[i] = (int*) malloc(9 * sizeof(int));
        for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) scanf("%d", &m[i][j]);
        printf("Instancia %d\n", inst++);
        if (valido(m)) printf("SIM\n\n"); else printf("NAO\n\n");
        for (i = 0; i < 9; i++) free(m[i]);
        free(m);
    }
    return 0;
}
