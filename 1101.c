#include <stdio.h>

int main() {
    int M, N;
    
    while (1) {
        scanf("%d %d", &M, &N);
        
        if (M <= 0 || N <= 0) {
            break;
        }
        
        int start = (M < N) ? M : N;
        int end = (M > N) ? M : N;
        int sum = 0;
        
        for (int i = start; i <= end; i++) {
            printf("%d", i);
            sum += i;
            if (i < end) {
                printf(" ");
            }
        }
        
        printf(" Sum=%d\n", sum);
    }
    
    return 0;
}