//implementation of hashing with chaining
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct node {
    int data;
    struct node* next;
};

struct node* hashTable[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

void search(int key) {
    int index = hashFunction(key);

    struct node* temp = hashTable[index];
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("%d --> ", i);
        struct node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(13);
    insert(27);

    display();

    search(13);
    search(99);

    return 0;
}
