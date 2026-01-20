#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;        //front
    int r;        //rear
    int *arr;
};

void initQueue(struct queue *q, int size) {
    q->size = size;
    q->f = q->r = -1;                                 
    q->arr = (int *)malloc(q->size * sizeof(int));
    if (!q->arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

void destroyQueue(struct queue *q) {
    free(q->arr);                        
    q->arr = NULL;
    q->size = 0;
    q->f = q->r = -1;
}

int isEmpty(struct queue *q) {
    return (q->r == q->f);
}

int isFull(struct queue *q) {
    return (q->r == q->size - 1);
}

void enqueue(struct queue *q, int val) {        
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("%d Enqueued to queue.\n", val);
    }
}

int dequeue(struct queue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        q->f++;
        a = q->arr[q->f];
        printf("%d Dequeued from queue.\n", a);
    }
    return a;
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = q->f + 1; i <= q->r; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    int size;
    printf("Enter size of the queue: ");
    scanf("%d", &size);

    initQueue(&q, size);

    int choice, val;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(&q, val);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                if (isFull(&q))
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 6:
                destroyQueue(&q);
                printf("Queue is destroyed. Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
