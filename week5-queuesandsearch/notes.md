# Week 5: Queues

## Overview
This week focuses on **Queues** and **Search**, including their implementation.

---

## Table of Contents

1. [Queues](#queues)
2. [Array-Based Implementation](#array-based-implementation)
3. [Linked List Implementation](#linked-list-implementation)
4. [Search: Definition](#search-definition)
5. [Linear Search](#linear-search)
6. [Binary Search](#binary-search)
7. [Interpolation Search](#interpolation-search)
8. [Recursive Algorithm](#recursive-algorithm)
9. [Time Complexity Analysis](#time-complexity-analysis)
10. [Resources](#resources)

---

## Queues

- Let's quickly recap what we learned from Week 4:

### Stacks and Queues 

- **Stacks**: Last In First Out
    - A **stack** is an ADT representing a collection of items in which items are only inserted on or removed from the top. 
    - The stack **push** operation inserts an item on the top of the stack. 
    - The stack **pop** operation removes and returns the item at the top of the stack.  
    - This is a linear data structure in which the elements are accessed using the **LIFO: Last-In First-Out** principle. 
- **Queues**: First In First Out
    - A queue is an ADT in which items are inserted at the end of the queue and removed from the front of the queue.
    - **Enqueue** operation inserts an item at the end of the queue.
    - **Dequeue** operation removes and returns the item at the front of the queue.
    - **FIFO (First-In First-Out) ADT.**

---

- Insertions and removals are performed individually.
- The object designated as the front of the queue is the object that has been in the queue the longest.

![Queue ADT](/week5-queuesandsearch/images/image.png)

---

### Common Queue ADT Operations

| **Operation**        | **Description**                                          | **Example starting with Queue (43, 12, 77) (front is 43)** |
|-----------------------|----------------------------------------------------------|------------------------------------------------------------|
| **Enqueue(queue, x)** | Inserts `x` at the end of the queue                      | `Enqueue(queue, 56)` → Queue: (43, 12, 77, 56)             |
| **Dequeue(queue)**    | Returns and removes the item at the front of the queue   | `Dequeue(queue)` → Returns: 43; Queue: (12, 77)            |
| **Peek(queue)**       | Returns but does not remove the item at the front        | `Peek(queue)` → Returns: 43; Queue: (43, 12, 77)           |
| **IsEmpty(queue)**    | Returns true if the queue has no items                   | `IsEmpty(queue)` → Returns: false; Queue: (43, 12, 77)     |
| **GetLength(queue)**  | Returns the number of items in the queue                 | `GetLength(queue)` → Returns: 3; Queue: (43, 12, 77)       |

---

### Time Complexities
- **O(1)** for `Enqueue()`, `Dequeue()`, `Peek()`, and `IsEmpty()`.
- No loops are required for any of these operations.

---

## Array-Based Implementation
- A queue can be implemented with an array. Three variables are needed in addition to the array:
    - allocationSize: an integer for the array's allocated size.
    - length: an integer for the number of items in the queue.
    - frontIndex: an integer for the queue's front item index.
The queue's content starts at `array[frontIndex]` and continues forward through `length` items. If the array's end is reached before encountering all items, remaining items are stored starting at index 0.
- Q – index between front and rear:
    - **rear**: where elements are added.
    - **front**: where elements are removed.
- Remaining elements in the array are free.

---

![Array Based Implementation](/week5-queuesandsearch/images/image1.png)

---

### Example: Adding an Element to Q
What would the queue look like after adding an element?

![Array Based Implementation](/week5-queuesandsearch/images/image2.png)

---

### Example: Removing an Element from Q
What happens after removing an element from the queue?

![Array Based Implementation](/week5-queuesandsearch/images/image3.png)

---

#### C Code for Array-Based Implementation

```c
#include <stdio.h>
#include <stdlib.h>

// Define the size of the queue
#define SIZE 100

// Structure to represent a queue
struct Queue {
    int items[SIZE];
    int front, rear;
};

// Function to create a queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Check if the queue is full
int isFull(struct Queue* queue) {
    return queue->rear == SIZE - 1;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }

    if (isEmpty(queue)) {
        queue->front = 0; // Initialize front for the first enqueue
    }

    queue->rear++;
    queue->items[queue->rear] = value;
    printf("%d added to the queue\n", value);
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate underflow
    }

    int value = queue->items[queue->front];

    // Check if the queue becomes empty
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // Reset the queue
    } else {
        queue->front++;
    }

    return value;
}

// Function to return the front item of the queue
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate the queue is empty
    }
    return queue->items[queue->front];
}

// Function to get the length of the queue
int getLength(struct Queue* queue) {
    if (isEmpty(queue)) {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

// Driver code
int main() {
    struct Queue* queue = createQueue();

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printf("Front item is: %d\n", peek(queue));
    printf("Removed item: %d\n", dequeue(queue));
    printf("Queue length: %d\n", getLength(queue));

    enqueue(queue, 40);
    printf("Front item is: %d\n", peek(queue));

    return 0;
}
```

---

## Linked List Implementation
- A queue is often implemented using a linked list, with the list's head node representing the queue's front, and the list's tail node representing the queue's end.
- Enqueueing an item is performed by creating a new linked list node, assigning the node's data with the item, and appending the node to the list. Dequeuing is performed by assigning a local variable with the front node's data, removing the front node from the list, and returning the local variable.
- **Head node** of the linked list → **Front** of the queue.
- **Tail node** of the linked list → **Rear** of the queue.
- **Enqueue** → Append to the end of the linked list.
- **Dequeue** → Remove the head node.

---

### Example: Adding a New Last Element
How do we determine where the end is? Traversal or Tail pointer?

![Last Element of Linked List Queue](/week5-queuesandsearch/images/image4.png)

---

### Example: Deleting an Element from an SLL
To delete the first element, we change the head of the linked list:

![Deleting First Element Of Linked List Queue](/week5-queuesandsearch/images/image5.png)

---

#### C Code for Linked List Implementation

```c
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure representing a single node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Structure to implement queue operations using a linked list
typedef struct Queue {
    Node *front, *rear;
} Queue;

// Function to create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return (q->front == NULL && q->rear == NULL);
}

// Function to add an element to the queue
void enqueue(Queue* q, int new_data) {
    Node* new_node = createNode(new_data);

    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    q->rear->next = new_node;
    q->rear = new_node;
}

// Function to remove an element from the queue
void dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    Node* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

// Function to get the front element of the queue
int getFront(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}

// Function to get the rear element of the queue
int getRear(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->rear->data;
}

// Driver code
int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);

    printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    dequeue(q);
    dequeue(q);

    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    dequeue(q);

    printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    return 0;
}
```

## Search: Definition

- A **search** is a function or process used to find letters, words, files, web pages, or other data.
- An **algorithm** is a sequence of steps to accomplish a task.
- **Runtime** refers to the time an algorithm takes to execute.

---

## Linear Search

### Definition
- Linear search starts at the beginning of a list and checks each element sequentially until the search key is found or the list ends.
- Used for unordered lists.

### Example
Find the position of `k=1` in the array `[3, 5, 1, 7]`:
1. Start from the first element.
2. Compare each element with `k`.
3. If a match is found, return the index.
4. If no match is found, return `-1`.

#### Code
```c
int LinearSearch(int numbers[], int numbersSize, int key) { 
    for (int i = 0; i < numbersSize; ++i) {
        if (numbers[i] == key) { 
            return i; 
        } 
    } 
    return -1; // not found 
}
```

### Time Complexity
- **Best Case**: O(1) (when the key is the first element).
- **Worst Case**: O(n) (when the key is the last element or not found).

---

## Binary Search

### Definition
- Used for **sorted arrays** to efficiently find an element.
- The algorithm:
  1. Check the middle element of the array.
  2. If the key matches the middle element, return the index.
  3. If the key is smaller, search the left sub-array.
  4. If the key is larger, search the right sub-array.
  5. Repeat until the element is found or the search space is empty.

### Example
Find the position of `k=23` in `[2, 5, 8, 12, 16, 23, 38, 56, 72, 91]`:
1. Middle = `23` (key matches).
2. Return index.

![Binary Search Example](/week5-queuesandsearch/images/image6.png)


#### Code
```c
int BinarySearch(int numbers[], int numbersSize, int key) {
    int mid = 0, low = 0, high = numbersSize - 1;
    while (high >= low) {
        mid = (high + low) / 2;
        if (numbers[mid] < key) {
            low = mid + 1;
        } else if (numbers[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1; // not found
}
```

### Time Complexity
- **Best Case**: O(1) (when the key is the middle element).
- **Worst Case**: O(log n) (halving the search space each iteration).

---

## Interpolation Search

### Definition
- An **improved version of Binary Search**, designed for uniformly distributed data.
- The algorithm:
  1. "Guess" the position of the searched element based on interpolation.
  2. Compare the element at the guessed position with the target.
  3. Narrow down the search space based on the result.

### Formula
Probe position:
```math
prob = low + ((x - A[low]) * (high - low)) / (A[high] - A[low])
```

### Example
Find `x=3` in `[1, 3, 5, 7, 9, 11]`:
1. Calculate `prob = 0 + ((3-1) * (5-0)) / (11-1) = 1`.
2. Check `A[prob]`.
3. Return position.

#### Code
```c
int InterpolationSearch(int arr[], int arr_size, int x) {
    int pos, lo = 0, hi = arr_size - 1;
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        else if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1; // not found
}
```

### Time Complexity
- **Best Case**: O(1).
- **Worst Case**: O(n) (when elements are not uniformly distributed).

---

## Recursive Algorithm

### Definition
- A recursive algorithm breaks a problem into smaller subproblems and applies the algorithm to solve those subproblems.
- Example: Recursive Binary Search.

#### Code
```c
int RecursiveBinarySearch(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = (high + low) / 2;
        if (arr[mid] == key) 
            return mid;
        if (arr[mid] > key) 
            return RecursiveBinarySearch(arr, low, mid - 1, key);
        return RecursiveBinarySearch(arr, mid + 1, high, key);
    }
    return -1; // not found
}
```

---

## Time Complexity Analysis

### Binary Search
- Key: How many times do we need to call the recursive function?
- Assume array length `n`:
  ```
  (1/2)^x * n = 1 → x = log2(n)
  ```
- **Best Case**: O(1).
- **Worst Case**: O(log n).

---

## Resources

- [GeeksForGeeks: Complexity Analysis of Binary Search](https://www.geeksforgeeks.org/complexity-analysis-of-binary-search/)
- [W3Resource: Interpolation Search](https://www.w3resource.com/c-programming-exercises/searching-and-sorting/c-search-and-sorting-exercise-19.php)
- [JavaTpoint: Interpolation Search](https://www.javatpoint.com/interpolation-search)
- [Recursive Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [JavaTpoint: Linked List Implementation of Queue](https://www.javatpoint.com/linked-list-implementation-of-queue)
- [Scaler: Queue Using Linked List](https://www.scaler.com/topics/c/implementation-of-queue-using-linked-list/)
- [MyCodeSchool: Array Implementation of Queue](https://www.youtube.com/watch?v=okr-XE8yTO8)
- [MyCodeSchool: Linked List Implementation of Queue](https://www.youtube.com/watch?v=A5_XdiK4J8A)
- [Linked List Implementation of Queue in C](https://gist.github.com/mycodeschool/7510222)
- [Alternative Implementation Without Rear Pointer](https://gist.github.com/kroggen/5fc7380d30615b2e70fcf9c7b69997b6)