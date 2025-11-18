#include <stdio.h>

int main() {
    int NC, N, h, i, j;
    scanf("%d", &NC);
    
    while (NC--) {
        scanf("%d", &N);
        int count[231] = {0};
        
        for (i = 0; i < N; i++) {
            scanf("%d", &h);
            count[h]++;
        }
        
        int first = 1;
        for (h = 20; h <= 230; h++) {
            for (j = 0; j < count[h]; j++) {
                if (!first) printf(" ");
                printf("%d", h);
                first = 0;
            }
        }
        printf("\n");
    }
    
    return 0;
}