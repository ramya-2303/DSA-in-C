//implementing queue using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *f = NULL; // front
struct Node *r = NULL; // rear

// Traversal
void displayQueue(struct Node *ptr) {
    if (ptr == NULL) {
        printf("Queue is EMPTY!\n");
        return;
    }
    printf("Queue elements: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Enqueue
void enqueue(int val) {
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    if (n == NULL) {
        printf("Queue is FULL (Memory allocation failed)\n");
        return;
    }
    n->data = val;
    n->next = NULL;
    if (f == NULL) {
        f = r = n;
    } else {
        r->next = n;
        r = n;
    }
    printf("%d Enqueued successfully.\n", val);
}

// Dequeue
int dequeue() {
    int val = -1;
    if (f == NULL) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return val;
    }
    struct Node *ptr = f;
    f = f->next;
    val = ptr->data;
    free(ptr);
    if (f == NULL)
        r = NULL;
    printf("%d Dequeued successfully.\n", val);
    return val;
}

// Peek (front element)
void peek() {
    if (f == NULL) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Front element: %d\n", f->data);
    }
}

// Count elements
int count() {
    int c = 0;
    struct Node *ptr = f;
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    return c;
}

// Clear queue
void clearQueue() {
    while (f != NULL) {
        dequeue();
    }
    printf("Queue cleared successfully!\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Queue (Linked List) Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek Front\n");
        printf("5. Count Elements\n");
        printf("6. Clear Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue(f);
                break;

            case 4:
                peek();
                break;

            case 5:
                printf("Total elements: %d\n", count());
                break;

            case 6:
                clearQueue();
                break;

            case 7:
                clearQueue(); // free before exiting
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
