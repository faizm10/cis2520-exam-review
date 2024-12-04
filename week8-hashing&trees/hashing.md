# Week 6: Hashing and Trees
 
## Overview
We will be focusing on Hashing as there are a lot of content to go over. Trees will be on another note file in the same folder.

---

## Table of Contents

1. [Hash Tables](#hash-tables)
2. [Collision](#collision)
   - [Chaining](#chaining)
   - [Linear Probing](#linear-probing)
   - [Quadratic Probing](#quadratic-probing)
   - [Double Hashing](#double-hashing)
3. [Performance Analysis](#performance-analysis)
4. [Example Questions](#example-questions)

---

## Hash Tables

- **Definition**: A **hash table** is a data structure that stores items by mapping each one to a location in an array using a hash function.
- **Key**: The unique value used to determine where the item is stored in the table.
- **Bucket**: A slot in the array where items are stored.
- **Hash Function**: A formula that turns a key into a bucket index.
- **Hash Code**: A non-negative number produced by the hash function to identify where the key-value pair should go.

## Collision

- A **collision** occurs when an item being inserted into a hash table maps to the same buckets as an existing item in the hashtable
- **Chaining** is a collision resultion technique where each bucket has a list of items

### Collision Resolution Using Linked List:

- Dynamically allocate space
- Easy to Insert/Delete an item
- Need a link for each node in the hash table

![Collision via Linked List](/week8-hashingandtrees/images/image11.png)

---

### Why Use Hash Tables?

   - Assume items have integer keys in the range **1 .. m**
   - Use the value of the key itself to select a slot (**bucket**) in a *direct access table* to *store* the item

![DAT](/week8-hashingandtrees/images/image12.png)

   - To *search* for an item which key, **k**, just look in slot **k** and see if there is an item. If the tag is 0, it's missing
   - Hash tables can quickly find, insert, or delete items in **O(1)** time on average.
   - You can use numbers, text, or other types as keys.

---

### Challenges with Hash Tables

- Keys must be unique and must be integers
- For storage efficiency keys must be *dense* in the range
- if they are *sparse* (lots of gaps between values), a lot of unnecessary space is used to obtain speed

---

### Example

#### Storing Phone Numbers:
- **Hash Function**: `h(x) = x mod 10`
- Example:
  - Phone number `416-229-0004` → Bucket `4`.
  - Steps:
    1. Compute hash: `0004 mod 10 = 4`.
    2. Store `416-229-0004` in bucket `4`.

---

### How a Hash Table Works

1. **Insert**:
   - Use the hash function to calculate the bucket.
   - Place the key-value pair in that bucket.
   - Handle collisions if needed (e.g., chaining or probing).
   - algorithm returns true if the item was inserted otherwise false if all buckets are occupied

2. **Search**:
   - A search algorithm uses the sought item's key to determine the initial bucket.
    -The algorithm probes each bucket until either
        – the matching item is found (returning the item)
        – an empty-since-start bucket is found (returning null), or
        – all buckets are probed without a match (returning null)


3. **Remove**:
   - A remove algorithm uses the sought item's key to determine the initial bucket.
    - The algorithm probes each bucket until either a matching item is found, an empty-since-start bucket is found, or all buckets have been probed.
    - If the item is found, the item is removed, and the bucket is marked empty-after- removal

---

### Example: Hash Table with Collisions

**Keys**: `{203, 105, 303, 212}`  
**Hash Function**: `h(x) = x mod 10`  
**Table Size**: `10`  

1. `203 mod 10 = 3` → Store in bucket `3`.
2. `105 mod 10 = 5` → Store in bucket `5`.
3. `303 mod 10 = 3` → Collision → Add to the linked list in bucket `3`.
4. `212 mod 10 = 2` → Store in bucket `2`.

**Result**:
| Index | Keys        |
|-------|-------------|
| 0     |             |
| 1     |             |
| 2     | 212         |
| 3     | 203 → 303   |
| 4     |             |
| 5     | 105         |
| 6     |             |
| 7     |             |
| 8     |             |
| 9     |             |

---

### Handling Collisions

1. **Chaining**:
   - Use a linked list to store multiple items in the same bucket.

2. **Probing**:
   - Search for the next available bucket:
     - **Linear Probing**: Check the next bucket.
     - **Quadratic Probing**: Use a formula like `(index + i^2)`.
     - **Double Hashing**: Use a second hash function to decide the step size.

3. **Rehashing**:
   - When the table gets too full, increase its size and redistribute all the keys using a new hash function.

### Empty Bucket
- An **empty-since-start** bucket has been empty since the hash table was created
- An **empty-after-removal** bucket had an item removed that caused the bucket to now be empty.

## Collision

### Chaining
- Chaining handles hash table collisions by using a list for each bucket, where each list stores the items that map to that bucket. The get, insert, and remove operations each start by using the item's key to determine the bucket. Each operation then searches that bucket's linked list for the key. The remaining logic is specific to the operation:
    - Get: Return the value corresponding to the key, or null if not found.
    - Insert: If the search finds a node, update that node's value. If not, append a new node with the inserted key and value to the bucket's linked list.
    - Remove: If the search finds a node, remove that node from the bucket's linked list.
- **Advantages**:
  - Dynamically allocates space.
  - Easy to insert/delete an item.
- **Disadvantages**:
  - Requires extra space for pointers.

### Linear Probing
- Handles collisions by placing the colliding item in the next (circularly) available table cell.
- **Algorithm**:
  - Start at the bucket index determined by the hash function.
  - Probe the next cell until an empty bucket is found.
- **Example**:
  - Insert keys `18, 41, 22` with `h(x) = x mod 13`:
    - `18 → Bucket 5`
    - `41 → Bucket 2`
    - `22 → Bucket 9`

#### Code for Linear Probing
```c
int HashInsert(int hashTable[], int N, int key) {
    int i = 0, bucket;
    do {
        bucket = (key % N + i) % N;
        if (hashTable[bucket] == -1) { // Empty bucket
            hashTable[bucket] = key;
            return bucket;
        }
        i++;
    } while (i < N);
    return -1; // Table is full
}
```

### Quadratic Probing
- Resolves collisions by probing using a quadratic function:
  - `h(x) = (h(x) + c1*i + c2*i^2) mod N`
- **Example**:
  - Insert `48` into a hash table with `N = 16`, `c1 = 1`, and `c2 = 1`:
    - Probing sequence: `0 → 2 → 6 → 12`.
    - `48` is placed in bucket `12`.

#### Code for Quadratic Probing
```c
int HashInsertQP(int hashTable[], int N, int key) {
    int i = 0, bucket;
    do {
        bucket = (key % N + i + i*i) % N;
        if (hashTable[bucket] == -1) { // Empty bucket
            hashTable[bucket] = key;
            return bucket;
        }
        i++;
    } while (i < N);
    return -1; // Table is full
}
```

### Double Hashing
- Uses a secondary hash function `h2(k)` to determine the step size for probing:
  - `h(k) = (h1(k) + i*h2(k)) mod N`
- **Example**:
    - Insert `16, 77, 55, 41, 63` into a hash table with:
        - `h1(k) = k mod 11`
        - `h2(k) = 5 - k mod 5`
        - Results:
        - `16 → Bucket 5`
        - `55 → Bucket 10`
        - `63 → Bucket 1`
    - Insert keys 18, 41, 22, 44, 59, 32, 31, 73, in this order
        ![Double Hashing](/week6-hashingandtrees/images/image.png)

#### Code for Double Hashing
```c
int HashInsertDH(int hashTable[], int N, int key, int q) {
    int i = 0, bucket;
    do {
        bucket = (key % N + i * (q - key % q)) % N;
        if (hashTable[bucket] == -1) { // Empty bucket
            hashTable[bucket] = key;
            return bucket;
        }
        i++;
    } while (i < N);
    return -1; // Table is full
}
```

---

## Performance Analysis

- **Load Factor** (`α`): Ratio of the number of items to the size of the hash table (`n/N`).
- **Expected Search Path Length**:
  - Successful Search: `½ (1 + 1 / (1 - α))`
  - Unsuccessful Search: `½ (1 + 1 / (1 - α)^2)`

---

## Example Questions

### Linear Probing
1. Insert `13` into a hash table with `h(x) = x mod 5`:
   - `13 → Bucket 3`.
2. Insert `41` into the same table:
   - `41 → Bucket 1`.
3. Insert `74`:
   - `74 → Bucket 4`.

### Quadratic Probing
1. Insert `48` into a hash table with `N = 16`, `c1 = 1`, `c2 = 1`:
   - Probing sequence: `0 → 2 → 6 → 12`.

### Double Hashing
1. Insert `16, 77, 55, 41, 63` into a hash table with:
   - `h1(k) = k mod 11`
   - `h2(k) = 5 - k mod 5`
   - Results:
     - `16 → Bucket 5`
     - `55 → Bucket 10`
     - `63 → Bucket 1`.

---
## Week 7: (Reading Week)


# Week 8: Hashing, Linear Probing, and Binary Trees

## Overview
This week focuses on exploring fundamental data structures and algorithms, specifically:
- Tree Concepts
- Binary Trees
- Binary Search Trees
- Hash Tables
- Collision Resolution Techniques

## Table of Contents
1. [Tree Concepts](#tree-concepts)
2. [Binary Trees](#binary-trees)
3. [Binary Tree Representations](#binary-tree-representations)
4. [Types of Binary Trees](#types-of-binary-trees)
5. [Binary Tree Traversal Algorithms](#binary-tree-traversal-algorithms)
6. [Binary Search Trees](#binary-search-trees)
7. [Hash Tables](#hash-tables)
8. [Collisions and Collision Resolution](#collisions-and-collision-resolution)
9. [Hash Functions](#hash-functions)
10. [Performance Factors](#performance-factors)

## Tree Concepts

A tree is an abstract model of a hierarchical structure, consisting of nodes connected by edges. Trees have numerous real-world applications, including:
- Organization charts
- File systems
- Decision-making processes

## Binary Trees

In a binary tree, each node has at most two children, referred to as the left child and the right child.

![Complete Binary Tree Example](/week8-hashing&trees/images/completebinarytree_example.png)

### Key Terminologies

- **Leaf**: A node with no children
- **Internal node**: A node with at least one child
- **Parent**: The node directly above a given node
- **Root**: The topmost node in the tree, with no parent
- **Edge**: A connection between two nodes
- **Path**: A sequence of consecutive edges
- **Depth of a node**: The length of the path from the root to that node
- **Height of a tree**: The number of nodes on the longest path from the root to a leaf

### Complete Binary Tree

A complete binary tree is a binary tree where:
- All levels are completely filled, except possibly the last level
- Nodes on the last level are as far left as possible

## Binary Tree Representations

Binary trees can be represented using linked structures, where each node contains:
- Pointers to its left and right children
- The node's data

![Binary Tree Example](/week8-hashing&trees/images/binarytreeexample.png)

## Types of Binary Trees

### 1. Arithmetic Expression Trees
- Used to represent arithmetic expressions
- Internal nodes hold operators
- External nodes (leaves) hold operands

Example:
```
        +
       / \
      *   3
     / \
    2   1
```

### 2. Decision Trees
- Used in decision-making processes
- Internal nodes represent questions
- External nodes represent decisions

## Binary Tree Traversal Algorithms

### 1. Pre-order Traversal
- Visit the root
- Traverse the left subtree
- Traverse the right subtree
- Used to extract prefix notation from an expression tree

![Pre-order Traversal Example](/week8-hashing&trees/images/preorder_example.png)

Example:
```
    1
   / \
  2   3

Pre-order: 1, 2, 3
```

### 2. In-order Traversal
- Traverse the left subtree
- Visit the root
- Traverse the right subtree

![In-order Traversal Example](/week8-hashing&trees/images/inorder_example1.png)

Example:
```
    1
   / \
  2   3

In-order: 2, 1, 3
```

### 3. Post-order Traversal
- Traverse the left subtree
- Traverse the right subtree
- Visit the root
- Used to extract postfix notation from an expression tree

![Post-order Traversal Example](/week8-hashing&trees/images/post_order_example.png)

Example:
```
    1
   / \
  2   3

Post-order: 2, 3, 1
```

### 4. Level-order Traversal
- Visit nodes level by level
- Typically from left to right within each level
- Also known as breadth-first traversal

![Level-order Traversal Example](/week8-hashing&trees/images/level_order_example.png)

## Binary Search Trees (BSTs)

### Key Property
For any node in a BST:
- All nodes in its left subtree have values less than the node's value
- All nodes in its right subtree have values greater than the node's value

### Operations

#### Search (BSTSearch)
- Find a node by comparing its value to the current node's value
- Move left or right accordingly

#### Insertion (BSTInsert)
- Insert a new node by finding its correct position
- Maintain the ordering property

#### Removal (BSTRemove)
Handle special cases for:
- Leaf nodes
- Internal nodes with one child
- Internal nodes with two children

Example BST:
```
       10
      /  \
     5    15
    / \   / \
   3   7 12  20
```

## Hash Tables

A hash table uses a hash function to map keys to indices (buckets) in an array, aiming to achieve near constant-time performance for operations like search, insertion, and deletion.

## Collisions and Collision Resolution

When multiple keys map to the same bucket, a collision occurs. Resolution methods include:

### 1. Chaining
- Uses linked lists at each bucket to store colliding items

### 2. Linear Probing
- Searches for the next available bucket in a linear sequence

### 3. Quadratic Probing
- Uses a quadratic function to probe subsequent buckets
- Aims to reduce clustering

### 4. Double Hashing
- Employs a secondary hash function
- Determines the probe sequence
- Reduces clustering

Example of Linear Probing:
```
Table Size: 5
Keys: 1, 6, 11

Initial Positions:
1 → 1
6 → 1 (collision, moves to index 2)
11 → 1 (collision, moves to index 3)

Resulting Table:
Index: 0  1  2  3  4
       -  1  6  11 -
```

## Hash Functions

The choice of hash function is crucial for hash table performance. An ideal hash function:
- Distributes keys uniformly across the hash table
- Minimizes collisions

## Performance Factors

Key performance considerations:
- Hash function quality
- Collision resolution technique
- Load factor (ratio of items to table size)

**Note**: Higher load factors generally lead to more collisions and slower performance.




## Resources

1. [GeeksForGeeks: Hashing Techniques](https://www.geeksforgeeks.org/hashing-data-structure/)
2. [JavaTpoint: Hashing in Data Structure](https://www.javatpoint.com/hashing-in-data-structure)
3. [MyCodeSchool: Hashing and Collision Resolution](https://www.youtube.com/watch?v=KyUTuwz_b7Q)
4. [Quadratic Probing Explanation](https://www.programiz.com/dsa/hash-table)
