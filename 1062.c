#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int sequencia[1000];
        
    while (1) {
            scanf("%d", &sequencia[0]);
            if (sequencia[0] == 0) {
                printf("\n");
                break;
            }
            
        for (int i = 1; i < n; i++) {
                scanf("%d", &sequencia[i]);
            }
            
            int pilha[1000], topo = -1;
            int vagao = 1;
            int possivel = 1;
            
        for (int i = 0; i < n; i++) {
            while (vagao <= sequencia[i]) {
                    pilha[++topo] = vagao++;
                }
                
            if (topo >= 0 && pilha[topo] == sequencia[i]) {
                    topo--;
                } else {
                    possivel = 0;
                    break;
                }
            }
            
            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    return 0;
}