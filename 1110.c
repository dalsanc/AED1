
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *p;
} no;

typedef struct {
    no *i, *f;
} fila;

void ini(fila *q) {
    q->i = q->f = NULL;
}

int vazia(fila *q) {
    return q->i == NULL;
}

void enq(fila *q, int v) {
    no *n = malloc(sizeof(no));
    n->v = v;
    n->p = NULL;
    if (q->f) q->f->p = n;
    q->f = n;
    if (!q->i) q->i = n;
}

int deq(fila *q) {
    no *n = q->i;
    int v = n->v;
    q->i = n->p;
    if (!q->i) q->f = NULL;
    free(n);
    return v;
}

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        fila q;
        ini(&q);
        for (int i = 1; i <= n; i++) enq(&q, i);
        printf("Discarded cards:");
        while (q.i && q.i->p) {
            int x = deq(&q);
            printf(" %d", x);
            if (q.i && q.i->p) printf(",");
            enq(&q, deq(&q));
        }
        printf("\nRemaining card: %d\n", deq(&q));
    }
    return 0;
}
