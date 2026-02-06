# Linked Lists Implementation in C

This folder contains C programs that implement different types of **Linked Lists**.  
Each file demonstrates creation and basic operations on a specific linked list type.

## Files in this Folder

- **singly_linked_list.c**  
  Implementation of a **Singly Linked List** with basic operations such as:
  - Insertion
  - Deletion
  - Traversal

- **doubly_linked_list.c**  
  Implementation of a **Doubly Linked List**, where each node contains:
  - A pointer to the previous node
  - A pointer to the next node

- **singlyCircular_linked_list.c**  
  Implementation of a **Singly Circular Linked List**, where the last node points back to the first node.

- **doublyCircular_linked_list.c**  
  Implementation of a **Doubly Circular Linked List**, where:
  - The last node points to the first node
  - The first node points to the last node

## How to Compile and Run

Use gcc to compile any file:
gcc singly_linked_list.c -o singly
./singly
