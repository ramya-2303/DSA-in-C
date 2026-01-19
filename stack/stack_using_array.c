//stack using array
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

void initStack(struct stack *sp, int size) {
    sp->size = size;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    if (!sp->arr) {
        printf("Memory allocation failed\n");
        exit(1);                                
    }
}

void destroy(struct stack *sp) {
    if (sp->arr != NULL) {
        free(sp->arr);          
        sp->arr = NULL;
    }
    sp->size = 0;
    sp->top = -1;
    printf("Stack destroyed successfully\n");
}

int isFull(struct stack *sp) {
    return sp->top == sp->size - 1;  
}

int isEmpty(struct stack *sp) {
    return sp->top == -1;
}

void push(struct stack *sp, int val) {
    if (isFull(sp)) {
        printf("Stack Overflow\n");
        return;
    }
    sp->arr[++sp->top] = val;                  
    printf("%d pushed successfully\n", val);
}                                                 

int pop(struct stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack Underflow\n");
        return -1;
    }
    printf("%d popped succesfully");
    return sp->arr[sp->top--];              
  
}

int peek(struct stack *sp, int pos) {
    int index = sp->top - pos + 1;
    if (index < 0 || index > sp->top) {
        printf("Invalid position\n");
        return -1;
    }
    return sp->arr[index];
}

void display(struct stack *sp) {
    if (isEmpty(sp)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = sp->top; i >= 0; i--)
        printf("%d ", sp->arr[i]);
    printf("\n");
}

int main() {
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    int choice, val, pos, size;

    printf("Enter the size of stack: ");
    scanf("%d", &size);
    initStack(sp, size);

    do {
        printf("\nMENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be pushed: ");
                scanf("%d", &val);
                push(sp, val);
                break;
            case 2:
                val = pop(sp);
                if (val != -1)
                    printf("Popped value: %d\n", val);
                break;
            case 3:
                printf("Enter the position from top to peek: ");
                scanf("%d", &pos);
                val = peek(sp, pos);
                if (val != -1)
                    printf("Value at position %d is %d\n", pos, val);
                break;
            case 4:
                display(sp);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    destroy(sp);
    free(sp);
  
    return 0;
}
