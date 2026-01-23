//implementation of hashing with quadratic probing
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i*i) % SIZE;
        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
    printf("Hash table full\n");
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    initialize();

    insert(23);
    insert(43);
    insert(13);
    insert(27);

    display();

    return 0;
}
