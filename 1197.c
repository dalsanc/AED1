#include <stdio.h>

int main() {
    int v, t;
    while (scanf("%d %d", &v, &t) == 2) {
        int s = 2 * v * t;
        printf("%d\n", s);
    }
    return 0;
}
