#include <stdio.h>
#include <stdlib.h>

struct circularQueue {
    int size;
    int f;       //front 
    int r;       //rear
    int* arr;
};

int isEmpty(struct circularQueue *q) {
    return q->r == q->f;                  
}

int isFull(struct circularQueue *q) {
    return (q->r + 1) % q->size == q->f;    
}
//Enqueue → insertion of an element, always at the rear.
//Dequeue → deletion of an element, always from the front and not always  
void enqueue(struct circularQueue *q, int val) {
    if (isFull(q)) {
        printf("Queue is FULL! Cannot enqueue %d\n", val);
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
    } else {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        printf("Dequeued element: %d\n", a);
    }
    return a;
}

void display(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    int i = (q->f + 1) % q->size;        
    while (i != (q->r + 1) % q->size) {   
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

void display(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue elements: ");
    int start = (q->f + 1) % q->size;         
    int end   = (q->r + 1) % q->size;         

    for (int i = start; i != end; i = (i + 1) % q->size) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
void peek(struct circularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is EMPTY!\n");
    } else {
        int frontIndex = (q->f + 1) % q->size;
        printf("Front element is: %d\n", q->arr[frontIndex]);
    }
}

int count(struct circularQueue *q) {
    return (q->r - q->f + q->size) % q->size;
}

void clear(struct circularQueue *q) {
    q->f = q->r = 0;
    printf("Queue has been cleared!\n");
}

int main() {
    struct circularQueue q;
    printf("Enter the size of the circular queue: ");
    scanf("%d", &q.size);
    q.size++;  // one space is wasted to distinguish full vs empty
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int choice, val;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Empty\n");
        printf("4. Check if Full\n");
        printf("5. Display\n");
        printf("6. Peek Front\n");
        printf("7. Count Elements\n");
        printf("8. Clear Queue\n");
        printf("9. Exit\n");
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
                if (isEmpty(&q))
                    printf("Queue is EMPTY\n");
                else
                    printf("Queue is NOT empty\n");
                break;

            case 4:
                if (isFull(&q))
                    printf("Queue is FULL\n");
                else
                    printf("Queue is NOT full\n");
                break;

            case 5:
                display(&q);
                break;

            case 6:
                peek(&q);
                break;

            case 7:
                printf("Total elements: %d\n", count(&q));
                break;

            case 8:
                clear(&q);
                break;

            case 9:
                printf("Exiting...\n");
                free(q.arr);
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
