#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int L;
        scanf("%d", &L);
        int train[L];
        for (int i = 0; i < L; i++) {
            scanf("%d", &train[i]);
        }

        int swaps = 0;
        for (int i = 0; i < L - 1; i++) {
            for (int j = 0; j < L - 1 - i; j++) {
                if (train[j] > train[j + 1]) {
                    int temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    swaps++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", swaps);
    }
    return 0;
}