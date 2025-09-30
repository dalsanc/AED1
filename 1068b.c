
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct node {
    char c;
    struct node *next;
} node;

void push(node **top, char c) {
    node *n = malloc(sizeof(node));
    n->c = c;
    n->next = *top;
    *top = n;
}

int pop(node **top) {
    if (*top == NULL) return 0;
    node *t = *top;
    *top = t->next;
    free(t);
    return 1;
}

void clear(node **top) {
    while (*top) pop(top);
}

int main() {
    char s[MAX+1];
    while (scanf("%s", s) != EOF) {
        int n = strlen(s);
        node *st = NULL;
        int ok = 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') push(&st, '(');
            else if (s[i] == ')') {
                if (!pop(&st)) { ok = 0; break; }
            }
        }
        if (st) ok = 0;
        clear(&st);
        printf("%s\n", ok ? "correct" : "incorrect");
    }
    return 0;
}
