//stack using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;            

void initStack() {
    top = NULL;
}

void destroyStack() {                
    struct Node *temp;
    while (top != NULL) {              
        temp = top;
        top = top->next;
        free(temp);
    }                                            
    printf("Stack destroyed successfully.\n");                  
}

void linkedListTraversal(struct Node *ptr) {
    if (ptr == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top) {
    return top == NULL;
}

int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));     
    if (p == NULL)
        return 1;
    free(p);
    return 0;
}

struct Node* push(struct Node *top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow! Cannot push %d\n", x);
    } else {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        printf("%d pushed to stack.\n", x);
    }
    return top;
}

int pop(struct Node **tp) {
    if (isEmpty(*tp)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    } else {
        struct Node *n = *tp;
        *tp = (*tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos) {
    struct Node *ptr = top;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr != NULL)
        return ptr->data;
    else
        return -1;
}

int stackTop() {
    if (top != NULL)
        return top->data;
    else
        return -1;
}

int main() {
    int choice, val, pos;

    initStack(); 

    while (1) {
        printf("\n------ Stack Menu ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (by position)\n");
        printf("4. Display Stack\n");
        printf("5. Stack Top\n");
        printf("6. Is Empty\n");
        printf("7. Is Full\n");
        printf("8. Destroy Stack\n");
        printf("9. Exit\n");
        printf("------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                top = push(top, val);
                break;
            case 2:
                val = pop(&top);
                if (val != -1)
                    printf("Popped element: %d\n", val);
                break;
            case 3:
                printf("Enter position to peek: ");
                scanf("%d", &pos);
                val = peek(pos);
                if (val != -1)
                    printf("Element at position %d: %d\n", pos, val);
                else
                    printf("Invalid position.\n");
                break;
            case 4:
                linkedListTraversal(top);
                break;
            case 5:
                val = stackTop();
                if (val != -1)
                    printf("Top element: %d\n", val);
                else
                    printf("Stack is empty.\n");
                break;
            case 6:
                if (isEmpty(top))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;
            case 7:
                if (isFull(top))
                    printf("Stack is full (memory not available).\n");
                else
                    printf("Stack is not full.\n");
                break;
            case 8:
                destroyStack();
                break;
            case 9:
                destroyStack(); 
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
