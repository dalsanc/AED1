#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 10000
#define MAX_M 30000

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    Node* head[MAX_N + 1];
} Graph;

void initGraph(Graph* g, int n) {
    for (int i = 1; i <= n; i++) {
        g->head[i] = NULL;
    }
}

void addEdge(Graph* g, int a, int b) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = b;
    newNode->next = g->head[a];
    g->head[a] = newNode;
}

bool dfs(Graph* g, int v, int* visited) {
    visited[v] = 1; 
    
    Node* temp = g->head[v];
    while (temp != NULL) {
        if (visited[temp->vertex] == 1) {
            return true; 
        }
        if (visited[temp->vertex] == 0 && dfs(g, temp->vertex, visited)) {
            return true;
        }
        temp = temp->next;
    }
    
    visited[v] = 2; 
    return false;
}


bool hasCycle(Graph* g, int n) {
    int visited[MAX_N + 1] = {0};
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(g, i, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        
        Graph g;
        initGraph(&g, N);
        
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            addEdge(&g, A, B);
        }
        
        if (hasCycle(&g, N)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    
    return 0;
}