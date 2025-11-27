#include <stdio.h>
#include <stdlib.h>


int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return abs(a);
}

int main() {
    int N;
    scanf("%d", &N);
    
    while (N--) {
        int N1, D1, N2, D2, num, den;
        char op;
        
        scanf("%d / %d %c %d / %d", &N1, &D1, &op, &N2, &D2);
        
        switch (op) {
            case '+':
                num = N1 * D2 + N2 * D1;
                den = D1 * D2;
                break;
            case '-':
                num = N1 * D2 - N2 * D1;
                den = D1 * D2;
                break;
            case '*':
                num = N1 * N2;
                den = D1 * D2;
                break;
            case '/':
                num = N1 * D2;
                den = N2 * D1;
                break;
        }
        
        int divisor = mdc(num, den);
        int num_simpl = num / divisor;
        int den_simpl = den / divisor;
        
        printf("%d/%d = %d/%d\n", num, den, num_simpl, den_simpl);
    }
    
    return 0;
}