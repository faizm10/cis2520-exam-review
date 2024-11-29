# Week 3: Linked List

## Overview
This week focuses on **Linked Lists** and their implementation. We will also explore both **Singly Linked Lists (SLL)** and **Doubly Linked Lists (DLL)**.

---

## Table of Contents
1. [List Abstract Data Type (ADT)](#list-abstract-data-type-adt)
2. [Singly-Linked List (SLL)](#singly-linked-list)
3. [Doubly-Linked List (DLL)](#doubly-linked-list)
4. [List Implementations](#list-implementations)

---

## List Abstract Data Type (ADT)

A **list** is a common ADT used to hold ordered data, with operations such as:
- Append a data item
- Remove a data item
- Check if a data item exists
- Print the list

### Examples of Lists:
- A list of student records
- A list of webpages
- A list of songs
- etc.

### Common List ADT Operations:

| **Operation**            | **Description**                                      | **Example starting with List (99, 77)**    |
|--------------------------|------------------------------------------------------|---------------------------------------------|
| **Append(list, X)**       | Inserts `X` at the end of the list                   | `Append(list, 44)` → List: (99, 77, 44)     |
| **Prepend(list, X)**      | Inserts `X` at the start of the list                 | `Prepend(list, 44)` → List: (44, 99, 77)    |
| **InsertAfter(list, W, X)**| Inserts `X` after `W` in the list                    | `InsertAfter(list, 99, 44)` → List: (99, 44, 77) |
| **Remove(list, X)**       | Removes `X` from the list                            | `Remove(list, 77)` → List: (99)             |
| **Contains(list, X)**     | Returns true if `X` is in the list, false otherwise  | `Contains(list, 99)` → true; `Contains(list, 22)` → false |
| **Print(list)**           | Prints the list's items in order                     | `Print(list)` → Outputs: 99, 77             |
| **Sort(list)**            | Sorts the list's items in ascending order           | `Sort(list)` → List: (77, 99)               |
| **IsEmpty(list)**         | Returns true if the list has no items                | `IsEmpty(list)` → false                     |
| **GetLength(list)**       | Returns the number of items in the list              | `GetLength(list)` → 2                       |

#### Operations:
- Insertions like append, prepend, and insert-after require allocating a new node:
  1. Allocate space for the node.
  2. Assign data with an initial value.
  3. Assign the `next` pointer with `NULL`.

- Operations at the `k`th entry of the list include:
  - Accessing the object.
  - Erasing an object.
  - Inserting a new object.
  - Replacing the object.

---

## List Implementations

### Array Implementation
- An **array** is a container object that holds a fixed number of values of a single type.
- The length of an array is established when the array is created.

---

![Array Implementation](/week3-linkedlist/images/array.png)

---

### Linked Lists

A **linked list** is a data structure that can change during execution. Successive elements are connected by pointers, and the last element points to `NULL`.

- The list structure typically has pointers to the **first node (head)** and **last node (tail)**.
- A node’s **successor** is the next node in the sequence (the last node has no successor).
- A node’s **predecessor** is the previous node in the sequence (the first node has no predecessor).
- A list’s **length** is the number of elements in it, and a list may be **empty** (contain no elements).
- A **singly-linked list (SLL)** is a type of **positional list**:
  - Elements contain pointers to the next (and/or previous) elements.
  - It is commonly used to implement a **list ADT**.

---

#### Implementation in C

```c
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
    int data;
    struct Node *next;
};

// Linked list with 3 nodes
int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Allocate 3 nodes in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Assign data to nodes
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    
    return 0;
}
```

**Traversal**

```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
// Prints contents of linked list starting from the given node
void printList(struct Node *n){
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
}
int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
    second->data = 2; // assign data to second node
    second->next = third;
    third->data = 3; // assign data to second node
    third->next = NULL;
    printList(head);
    return 0;
}
```
![Linked List Implementation](/week3-linkedlist/images/linkedlist.png)

---

## Single-Linked Lists (SLL)

- A **singly-linked list** is a data structure for implementing a list ADT
– Each node has data and a pointer to the next node.
– The list structure typically has pointers to the list's first node and last node.
– SLL first node is called the **head**, and the last node the **tail**.
– A list where elements contain pointers to the next and/or previous elements in the list

### Inserting a node into a SLL

- There are many ways you might want to insert a new node into a list:
    – As the new first element
    – As the new last element
    – Before a given node (specified by a reference)
    – After a given node
    – Before a given value
    – After a given value
- All are possible, but differ in difficulty
- Insertion is probably the easiest method to implement
- Assume we have the following linked list created:
![Linked List Created](/week3-linkedlist/images/linkedlistexample.png)
- And we want to insert `zero` before the first element:
![Adding 0](/week3-linkedlist/images/linkedlistexample1.png)

- Here's what we have before we dive into adding 0 to before the first element in the linked list:

![PreviewLinkedList](/week3-linkedlist/images/PreviewLinkedList.png)

- We would create a function add_begin to do it: 

```c
Struct node* add_begin (struct node* head, int d){
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = d;
    ptr -> next = NULL;
    ptr -> next = head;
    head = ptr;
    return head;
}
// call the function, assuming the linked list already created
int add_data = 0;
head = add_begin(head, add_data);

```

## References

- **Video: "Creating the Node of a Single Linked List"** by Neso Academy  
  [Watch on YouTube](https://www.youtube.com/watch?v=DneLxrPmmsw)

- **C struct and malloc**  
  [Learn more at University of Toronto](https://www.cs.toronto.edu/~heap/270F02/node31.html)

- **Data Structures and Applications**  
  [Read more on GeeksforGeeks](https://www.geeksforgeeks.org/what-is-data-structure-types-classifications-and-applications/)
