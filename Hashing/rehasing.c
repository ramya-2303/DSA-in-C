//Implementation of hashing using rehasing
//Rehasing means creating a new biggger hash table and re-inserting all old elements into it using new hash function or new table size
  // 1. Old table size = 5
  // 12, 22, 32, -1, -1
  // These values are already placed using hash = key % 5.
  // 2. New table size = 10
  // You reinsert each old key using hash = key % 10.
  // 3. You use linear probing to resolve collisions

#include <stdio.h>

#define OLD_SIZE 5
#define NEW_SIZE 10

int oldTable[OLD_SIZE] = {12, 22, 32, -1, -1};
int newTable[NEW_SIZE];

int hash(int key, int size) {
    return key % size;
}

void initialize(int table[], int size) {
    for (int i = 0; i < size; i++)
        table[i] = -1;
}

void rehash() {
    initialize(newTable, NEW_SIZE);

    for (int i = 0; i < OLD_SIZE; i++) {
        if (oldTable[i] != -1) {
            int key = oldTable[i];
            int index = hash(key, NEW_SIZE);

            while (newTable[index] != -1) {
                index = (index + 1) % NEW_SIZE;  // linear probing
            }
            newTable[index] = key;
        }
    }     
}

int main() {
    rehash();

    printf("New table after rehashing:\n");
    for (int i = 0; i < NEW_SIZE; i++)
        printf("%d -> %d\n", i, newTable[i]);

    return 0;
}
