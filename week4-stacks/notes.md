# Week 3: Stacks

## Overview
This week focuses on **Stacks** and their implementation.

---

## Table of Contents
1. [Definition of Stacks](#stacks)
2. [Stack Applications](#queue)
3. [Implementation](#sample-code-program-using-linked-list)

---

## Stacks 

- A **stack** is an ADT representing a collection of items in which items are only inserted on or removed from the top. 
- The stack **push** operation inserts an item on the top of the stack. 
- The stack **pop** operation removes and returns the item at the top of the stack.  
  Example: After the operations `Push 7`, `Push 14`, `Push 9`, and `Push 5`, `Pop` returns 5. A second `Pop` returns 9.
- This is a linear data structure in which the elements are accessed using the **LIFO: Last-In First-Out** principle. 
- A stack is commonly implemented using a linked list or an array.

### Common Stack ADT Operations

| **Operation**       | **Description**                                        | **Example starting with Stack (99, 77)**   |
|---------------------|--------------------------------------------------------|--------------------------------------------|
| **Push(stack, x)**   | Inserts `x` on top of the stack                        | `Push(stack, 44)` → Stack: (44, 99, 77)    |
| **Pop(stack)**       | Removes and returns the stack's top item               | `Pop(stack)` → Returns: 99; Stack: (77)    |
| **Peek(stack)**      | Returns but does not remove the stack's top item       | `Peek(stack)` → Returns: 99; Stack still: (99, 77) |
| **IsEmpty(stack)**   | Returns true if the stack has no items                 | `IsEmpty(stack)` → Returns: false; Stack: (99, 77) |
| **GetLength(stack)** | Returns the number of items in the stack               | `GetLength(stack)` → Returns: 2; Stack: (99, 77) |

---

### Pros vs Cons of Array Implementation
- **Pros**: Easy to implement. No additional pointer for each element is needed (saves memory).
- **Cons**: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.

---

### Pros & Cons of Linked List Implementation
- **Pros**: The linked list implementation of a stack can grow and shrink according to the needs at runtime.
- **Cons**: Requires extra memory due to the involvement of pointers.

---

### isEmpty
- Returns true if the stack is empty; else false.

```c
// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->head == NULL;
}
```

---

### Peek
- Returns the top element of the stack.

```c
// Function to return the top element of the stack
int peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->head->data;
    else {
        printf("\nStack is empty");
        return INT_MIN;
    }
}
```

---

### Push
- Adds an item to the stack. If the stack is full, it is said to be an **overflow** condition.

```c
// Function to push an element onto the stack
void push(Stack* stack, int new_data) {
    Node* new_node = createNode(new_data);

    // Check if memory allocation for the new node failed
    if (!new_node) {
        printf("\nStack Overflow");
        return;
    }

    // Link the new node to the current top node
    new_node->next = stack->head;

    // Update the top to the new node
    stack->head = new_node;
}
```

---

### Pop
- Removes an item from the stack. The items are popped in the reverse order in which they were pushed. If the stack is empty, it is said to be an **underflow** condition.

```c
void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nStack Underflow\n");
        return;
    } else {
        Node* temp = stack->head;
        stack->head = stack->head->next;
        free(temp);
    }
}
```

---

### Time Complexities
- **O(1)** for `push()`, `pop()`, `isEmpty()`, and `peek()`.
- No loops are required for any of these operations.

---

### Sample Code Program Using Linked List
```c
// A structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function creates a stack of given capacity. It initializes size to 0
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

// Driver program to test above functions
int main() {
    struct Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d popped from stack\n", pop(stack));
    printf("Top element is: %d\n", peek(stack));
    return 0;
}
```

---

## Queue - [More Info In Week6](/week5-queuesandsearch) 

- **Queue**: A queue is an ADT in which items are inserted at the end of the queue and removed from the front of the queue.
- **Enqueue** operation inserts an item at the end of the queue.
- **Dequeue** operation removes and returns the item at the front of the queue.
- **FIFO (First-In First-Out) ADT.**

---

## Resources
- [GeeksForGeeks](https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/)
- Zybook Data Structures 5: Stacks and Queues
- [Signed and Unsigned in Type Define (Yale)](https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)IntegerTypes.html#:~:text=Unsigned%20variables%2C%20which%20can%20be,the%20whim%20of%20the%20compiler)
- [University of Waterloo - C Integer Types](https://ece.uwaterloo.ca/~dwharder/icsrts/C/07/)
