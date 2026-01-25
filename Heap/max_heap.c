//Implementation of max heap
#include<stdio.h>
#include<stdlib.h>

void heapifyUp(int heap[], int index) {        
    int parent = (index - 1) / 2;
    if (index > 0 && heap[parent] < heap[index]) {
        int temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;
        heapifyUp(heap, parent);       
    }
}

void heapifyDown(int heap[], int n, int index) {
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        heapifyDown(heap, n, largest);
    }
}

void insert(int heap[], int *n, int value) {
    heap[*n] = value;
    (*n)++;
    heapifyUp(heap, *n - 1);
}

int deleteRoot(int heap[], int *n) {
    if (*n <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    heapifyDown(heap, *n, 0);
    return root;
}

void buildHeap(int heap[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyDown(heap, n, i);
}

void heapSort(int heap[], int n) {
    buildHeap(heap, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        heapifyDown(heap, i, 0);
    }
}

int main() {
    int heap[100];
    int n = 0;

    insert(heap, &n, 50);
    insert(heap, &n, 30);
    insert(heap, &n, 20);
    insert(heap, &n, 10);
    insert(heap, &n, 60);

    printf("Max Heap: ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    printf("\nDeleted root: %d\n", deleteRoot(&heap[0], &n));

    printf("After deletion: ");
    for (int i = 0; i < n; i++)
        printf("%d ", heap[i]);

    return 0;
}
