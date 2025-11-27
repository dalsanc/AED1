#include <stdio.h>
#include <string.h>

#define MAX_N 100
#define MAX_NAME 21

int main() {
    int N, K;
    char alunos[MAX_N][MAX_NAME];
    
    scanf("%d %d", &N, &K);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", alunos[i]);
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (strcmp(alunos[j], alunos[j + 1]) > 0) {
                char temp[MAX_NAME];
                strcpy(temp, alunos[j]);
                strcpy(alunos[j], alunos[j + 1]);
                strcpy(alunos[j + 1], temp);
            }
        }
    }
    
    printf("%s\n", alunos[K - 1]);
    
    return 0;
}