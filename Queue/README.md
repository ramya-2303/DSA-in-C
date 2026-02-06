# Queue Implementation in C

This folder contains C programs that demonstrate **Queue data structures** using both **arrays** and **linked lists**.  
It also includes implementations of **Circular Queues**.

## Files in this Folder

- **queue_using_array.c**  
  Implementation of a **Queue using an Array** with basic operations:
  - Enqueue
  - Dequeue
  - Display

- **queue_using_linkedList.c**  
  Implementation of a **Queue using a Linked List**, allowing dynamic memory allocation.

- **circular_queue_using_array.c**  
  Implementation of a **Circular Queue using an Array**, which efficiently utilizes memory by reusing empty spaces.

- **circular_queue_using_linkedList.c**  
  Implementation of a **Circular Queue using a Linked List**, where the last node points back to the first node.

## How to Compile and Run

Use gcc to compile any file:
gcc queue_using_array.c -o queue_array
./queue_array
