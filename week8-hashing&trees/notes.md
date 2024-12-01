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

