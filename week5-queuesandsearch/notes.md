# Week 5: Stacks

## Overview
This week focuses on **Queues** and **Search** their implementation.

---

## Table of Contents


---

## Queues

- Let's quickly recap what we have learnt from week 4:

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

- Now let's dive into Queues!:

- Insertions and removals are performed individually
- The object designated as the front of the queue is the object which was in the queue the longest

![Queue ADT](/week5-queuesandsearch/images/image.png)

### Common Queue ADT Operations

| **Operation**        | **Description**                                          | **Example starting with Queue (43, 12, 77) (front is 43)** |
|---------------------------------------------------------------------------------------------------------------------------------------------|
| **Enqueue(queue, x)** | Inserts `x` at the end of the queue                      | `Enqueue(queue, 56)` → Queue: (43, 12, 77, 56)             |
| **Dequeue(queue)**    | Returns and removes the item at the front of the queue   | `Dequeue(queue)` → Returns: 43; Queue: (12, 77)            |
| **Peek(queue)**       | Returns but does not remove the item at the front        | `Peek(queue)` → Returns: 43; Queue: (43, 12, 77)           |
| **IsEmpty(queue)**    | Returns true if the queue has no items                   | `IsEmpty(queue)` → Returns: false; Queue: (43, 12, 77)     |
| **GetLength(queue)**  | Returns the number of items in the queue                 | `GetLength(queue)` → Returns: 3; Queue: (43, 12, 77)       |

### Time Complexities
- **O(1)** for `Enqueue()`, `Dequeue()`, `Peek()`, and `IsEmpty()`.
- No loops are required for any of these operations.

### Array Based Implementation

- Define an array
- Q – index between front and rear
    - rear: add element
    – front: remove element
- Rest of the element in the array are free

![Array Based Implementation](/week5-queuesandsearch/images/image1.png)

- What if we add an element to Q? What would it look like after doing so?

![Array Based Implementation](/week5-queuesandsearch/images/image2.png)

- Alright. What about removing an element to the Q?

![Array Based Implementation](/week5-queuesandsearch/images/image3.png)

#### C Code for Implementation of Array Based 

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

### Linked-List Implementation

- LL’s **head** node – queue’s **front**
- LL’s **tail** node – queue’s **rear**
- **Enqueue** – append to the end of LL
- **Dequeue** – remove the head node
- Recall: how did we do that in the LL? What about the Time complexity?

#### Inserting as a new last element

- How do we know where is the end? -- Traversal or Tail pointer?

![Last Element of Linked List Queue](/week5-queuesandsearch/images/image4.png)

#### Deleted an element from a SLL

- To Delete the first element, we change the head of the linked list:

![Deleting First Element of Linked List Queue](/week5-queuesandsearch/images/image6.png)

#### C Code For Implementation of Single Linked List

```c
// C program to implement the queue data structure using
// linked list
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Node structure representing a single node in the linked
// list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

// Structure to implement queue operations using a linked
// list
typedef struct Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;
} Queue;

// Function to create a queue
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q)
{

    // If the front and rear are null, then the queue is
    // empty, otherwise it's not
    if (q->front == NULL && q->rear == NULL) {
        return 1;
    }
    return 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int new_data)
{

    // Create a new linked list node
    Node* new_node = createNode(new_data);

    // If queue is empty, the new node is both the front
    // and rear
    if (q->rear == NULL) {
        q->front = q->rear = new_node;
        return;
    }

    // Add the new node at the end of the queue and
    // change rear
    q->rear->next = new_node;
    q->rear = new_node;
}

// Function to remove an element from the queue
void dequeue(Queue* q)
{

    // If queue is empty, return
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return;
    }

    // Store previous front and move front one node
    // ahead
    Node* temp = q->front;
    q->front = q->front->next;

    // If front becomes null, then change rear also
    // to null
    if (q->front == NULL)
        q->rear = NULL;

    // Deallocate memory of the old front node
    free(temp);
}

// Function to get the front element of the queue
int getFront(Queue* q)
{

    // Checking if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}

// Function to get the rear element of the queue
int getRear(Queue* q)
{

    // Checking if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->rear->data;
}

// Driver code
int main()
{
    Queue* q = createQueue();

    // Enqueue elements into the queue
    enqueue(q, 10);
    enqueue(q, 20);
    
      printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);


    // Enqueue more elements into the queue
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    // Dequeue an element from the queue
    dequeue(q);

    printf("Queue Front: %d\n", getFront(q));
    printf("Queue Rear: %d\n", getRear(q));

    return 0;
}
```