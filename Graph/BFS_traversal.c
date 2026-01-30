//Implementing Breadth First Search traversal technique using C language
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int f, r, size;
    int *arr;
};

int isEmpty(struct queue *q) { 
  return q->f == q->r; 
}
int isFull(struct queue *q) {
  return q->r == q->size - 1; 
}

void enqueue(struct queue *q, int val) {
    if (!isFull(q))
        q->arr[++q->r] = val;
}

int dequeue(struct queue *q) {
    if (!isEmpty(q))
        return q->arr[++q->f];
    return -1;
}

int main() {
    int visited[7] = {0};
    int A[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    struct queue q;
    q.size = 20;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int i = 0;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(&q, i);

    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++) {
            if (A[node][j] && !visited[j]) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }
    return 0;
}
