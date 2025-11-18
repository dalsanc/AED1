#include <stdio.h>

int g[1000][1000];
int d[1000];
int n, v0, a;
int c;

void dfs(int u) {
    d[u] = 1;
    for (int i = 0; i < n; i++) {
        if (g[u][i] && !d[i]) {
            c++;
            dfs(i);
            c++;
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        scanf("%d", &v0);
        scanf("%d %d", &n, &a);
        for (int i = 0; i < n; i++) {
            d[i] = 0;
            for (int j = 0; j < n; j++) g[i][j] = 0;
        }
        for (int i = 0; i < a; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            g[x][y] = 1;
            g[y][x] = 1;
        }
        c = 0;
        dfs(v0);
        printf("%d\n", c);
    }
    return 0;
}
