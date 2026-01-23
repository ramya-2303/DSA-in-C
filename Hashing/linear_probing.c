//implementation of hashing with linear probing
#include <stdio.h>
#include<stdlib,h>

#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1; 
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hashFunction(key);

    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;  // linear probe
    }
    hashTable[index] = key;
}

void search(int key) {
    int index = hashFunction(key);
    int start = index;

    while (hashTable[index] != key) {
        index = (index + 1) % SIZE;
        if (index == start) {
            printf("Not found\n");
            return;
        }
    }
    printf("Found %d at index %d\n", key, index);
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    init();
  
    insert(43);
    insert(13);
    insert(27);

    display();

    search(13);

    return 0;
}
