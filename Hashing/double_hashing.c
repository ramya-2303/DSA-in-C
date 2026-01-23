//implementation of hashing using double hashing
#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {
    int index = h1(key);
    int step = h2(key);

    while (hashTable[index] != -1) {
        index = (index + step) % SIZE;
    }
    hashTable[index] = key;
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
