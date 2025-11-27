#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

int adj[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1];

void dfs(int node, int N) {
    visited[node] = 1;
    for (int i = 1; i <= N; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs(i, N);
        }
    }
}

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    for (int i = 0; i < L; i++) {
        int X, Y;
        scanf("%d %d", &X, &Y);
        adj[X][Y] = adj[Y][X] = 1;
    }
    
    dfs(1, N); 
    
    int completo = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            completo = 0;
            break;
        }
    }
    
    printf("%s\n", completo ? "COMPLETO" : "INCOMPLETO");
    
    return 0;
}