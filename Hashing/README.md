# Hashing Techniques in C

This folder contains C language implementations of different **hashing techniques** used in data structures to handle collisions in hash tables.

## Contents

**chaining.c**
  Implementation of **Separate Chaining** collision resolution technique using linked lists.

**linear_probing.c**
  Implementation of **Linear Probing**, an open addressing method for resolving collisions.

**quadratic_probing.c**
  Implementation of **Quadratic Probing**, which reduces clustering compared to linear probing.

**double_hashing.c**
  Implementation of **Double Hashing**, which uses a second hash function to resolve collisions.

**rehasing.c**
  Demonstration of **Rehashing**, where the hash table size is increased and elements are reinserted when the load factor exceeds a limit.

## Features

- Written purely in **C language**
- Menu-driven
- Demonstrates collision handling clearly


## TO Compile and Run

Use gcc to compile any file:

gcc filename.c -o filename
./filename
