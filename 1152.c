#include <stdio.h>
#include <stdlib.h>

#define MAX 200000

typedef struct {
    int x, y, z;
} Edge;

Edge edges[MAX];
int parent[MAX];

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->z - ((Edge*)b)->z;
}

int main() {
    int m, n;
    
    while (scanf("%d %d", &m, &n) && (m || n)) {
        int total_cost = 0, mst_cost = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].z);
            total_cost += edges[i].z;
        }
        
        for (int i = 0; i < m; i++) parent[i] = i;
        
        qsort(edges, n, sizeof(Edge), cmp);
        
        int edges_used = 0;
        for (int i = 0; i < n && edges_used < m - 1; i++) {
            if (find(edges[i].x) != find(edges[i].y)) {
                union_sets(edges[i].x, edges[i].y);
                mst_cost += edges[i].z;
                edges_used++;
            }
        }
        
        printf("%d\n", total_cost - mst_cost);
    }
    
    return 0;
}