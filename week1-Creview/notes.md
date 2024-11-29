# C Review

## Overview
This document covers important concepts in C programming, focusing on topics that are especially useful for learning Data Structures and Algorithms (DSA). It includes storage classes, pointers, and some handy programming tips.

---

## Table of Contents
1. [Storage Classes](#storage-classes)
2. [Pointers](#pointers)
3. [Function Arguments](#function-arguments)
4. [Pointers and Arrays](#pointers-and-arrays)

---

## Storage Classes

### What Are Storage Classes?
Storage classes in C tell us:
- Where a variable can be accessed (its **scope**).
- How long it stays in memory (its **lifetime**).
- Where it is stored (in **RAM** or in the CPU's register).

| **Type**       | **Scope**        | **Lifetime**           | **Stored In**  | **Details**                                                      |
|-----------------|------------------|------------------------|----------------|------------------------------------------------------------------|
| `auto`         | Inside a block   | While the block runs   | RAM            | Default for local variables.                                    |
| `static`       | Inside a block   | Until the program ends | RAM            | Keeps its value even after the function ends.                   |
| `extern`       | Whole program    | Until the program ends | RAM            | Used to share variables between files.                          |
| `register`     | Inside a block   | While the block runs   | CPU Register   | For fast access. Cannot take its address with `&`.              |

### Example: Using `static`
```c
#include <stdio.h>

void counter() {
    static int count = 0;  // Keeps its value across calls
    count++;
    printf("Count: %d\n", count);
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}

// Output:
// Count: 1
// Count: 2
// Count: 3
```

---

## Pointers

### What Are Pointers?
Pointers are variables that store the memory address of another variable. They are really useful in C for managing memory and creating complex data structures like linked lists and trees.

### Pointer Basics
1. **Declaration**: `int *p;` (This makes `p` a pointer to an integer.)
2. **Assigning an Address**: `p = &x;` (The `&` operator gets the memory address of `x`.)
3. **Dereferencing**: `*p` (The `*` operator gets the value stored at the address `p` points to.)

### Example: Pointers in Action
```c
int x = 42;
int *p = &x;

printf("Value of x: %d\n", x);      // 42
printf("Address of x: %p\n", &x);  // Address of x
printf("Value via pointer: %d\n", *p); // 42
```

---

## Function Arguments

### Call by Value
When you pass variables to a function, their **values** are copied. Changes inside the function don’t affect the original variables.

### Call by Reference
By passing a variable's **address** (using pointers), you allow the function to modify the original variable.

#### Example: Call by Reference
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);  // Passing the addresses of x and y
    printf("x: %d, y: %d\n", x, y);  // x: 10, y: 5
    return 0;
}
```

---

## Pointers and Arrays

### Key Points
- The name of an array (e.g., `arr`) is a pointer to its first element.
- You can use pointers to access elements in an array:
  - `arr[i]` is the same as `*(arr + i)`.

### Example: Pointer Arithmetic
```c
int arr[] = {10, 20, 30};
int *p = arr;

printf("%d\n", *(p + 1));  // Prints 20
```

---

## Character Arrays and Strings

### Example
```c
char str[] = "Hello, World!";
char *p = str;

printf("%s\n", p);  // Prints the entire string: Hello, World!
```

### Key Points
- Arrays are passed to functions by reference.
- You can use pointers to navigate through string characters.