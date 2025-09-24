#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int top;
} Stack;

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

typedef struct {
    int data[MAX];
    int size;
} PriorityQueue;

void initStack(Stack *s) { s->top = 0; }
void pushStack(Stack *s, int x) { s->data[s->top++] = x; }
int popStack(Stack *s) { return s->data[--s->top]; }
int isEmptyStack(Stack *s) { return s->top == 0; }

void initQueue(Queue *q) { q->front = q->rear = 0; }
void pushQueue(Queue *q, int x) { q->data[q->rear++] = x; }
int popQueue(Queue *q) { return q->data[q->front++]; }
int isEmptyQueue(Queue *q) { return q->front == q->rear; }

void initPQ(PriorityQueue *pq) { pq->size = 0; }
void pushPQ(PriorityQueue *pq, int x) {
    int i = pq->size++;
    pq->data[i] = x;
    while (i > 0 && pq->data[(i - 1) / 2] < pq->data[i]) {
        int tmp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = tmp;
        i = (i - 1) / 2;
    }
}
int popPQ(PriorityQueue *pq) {
    int res = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, largest = i;
        if (left < pq->size && pq->data[left] > pq->data[largest]) largest = left;
        if (right < pq->size && pq->data[right] > pq->data[largest]) largest = right;
        if (largest == i) break;
        int tmp = pq->data[i];
        pq->data[i] = pq->data[largest];
        pq->data[largest] = tmp;
        i = largest;
    }
    return res;
}
int isEmptyPQ(PriorityQueue *pq) { return pq->size == 0; }

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Stack s; Queue q; PriorityQueue pq;
        initStack(&s); initQueue(&q); initPQ(&pq);
        int isStack = 1, isQueue = 1, isPQ = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);
            if (op == 1) {
                pushStack(&s, x);
                pushQueue(&q, x);
                pushPQ(&pq, x);
            } else {
                if (isEmptyStack(&s) || popStack(&s) != x) isStack = 0;
                if (isEmptyQueue(&q) || popQueue(&q) != x) isQueue = 0;
                if (isEmptyPQ(&pq) || popPQ(&pq) != x) isPQ = 0;
            }
        }

        if (isStack + isQueue + isPQ == 0) printf("impossible\n");
        else if (isStack + isQueue + isPQ > 1) printf("not sure\n");
        else if (isStack) printf("stack\n");
        else if (isQueue) printf("queue\n");
        else if (isPQ) printf("priority queue\n");
    }
    return 0;
}
