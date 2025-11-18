#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char v;
    struct no *e;
    struct no *d;
} No;

No *novo(char c) {
    No *p = (No*)malloc(sizeof(No));
    p->v = c;
    p->e = NULL;
    p->d = NULL;
    return p;
}

No *insere(No *r, char c) {
    if (r == NULL) return novo(c);
    if (c < r->v) r->e = insere(r->e, c);
    else if (c > r->v) r->d = insere(r->d, c);
    return r;
}

int busca(No *r, char c) {
    if (r == NULL) return 0;
    if (c == r->v) return 1;
    if (c < r->v) return busca(r->e, c);
    return busca(r->d, c);
}

void infixa(No *r, int *first) {
    if (r == NULL) return;
    infixa(r->e, first);
    if (*first) {
        printf("%c", r->v);
        *first = 0;
    } else {
        printf(" %c", r->v);
    }
    infixa(r->d, first);
}

void prefixa(No *r, int *first) {
    if (r == NULL) return;
    if (*first) {
        printf("%c", r->v);
        *first = 0;
    } else {
        printf(" %c", r->v);
    }
    prefixa(r->e, first);
    prefixa(r->d, first);
}

void posfixa(No *r, int *first) {
    if (r == NULL) return;
    posfixa(r->e, first);
    posfixa(r->d, first);
    if (*first) {
        printf("%c", r->v);
        *first = 0;
    } else {
        printf(" %c", r->v);
    }
}

void libera(No *r) {
    if (r == NULL) return;
    libera(r->e);
    libera(r->d);
    free(r);
}

int main() {
    No *raiz = NULL;
    char cmd[20];
    char c;

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "I") == 0) {
            scanf(" %c", &c);
            raiz = insere(raiz, c);
        } else if (strcmp(cmd, "P") == 0) {
            scanf(" %c", &c);
            if (busca(raiz, c))
                printf("%c existe\n", c);
            else
                printf("%c nao existe\n", c);
        } else if (strcmp(cmd, "INFIXA") == 0) {
            int first = 1;
            infixa(raiz, &first);
            printf("\n");
        } else if (strcmp(cmd, "PREFIXA") == 0) {
            int first = 1;
            prefixa(raiz, &first);
            printf("\n");
        } else if (strcmp(cmd, "POSFIXA") == 0) {
            int first = 1;
            posfixa(raiz, &first);
            printf("\n");
        }
    }

    libera(raiz);
    return 0;
}
