# Trees and Graphs Data Structures

## Table of Contents
- [Binary Trees](#binary-trees)
  - [Complete Binary Trees](#complete-binary-trees)
  - [Binary Search Trees (BSTs)](#binary-search-trees-bsts)
  - [Balanced BSTs (AVL Trees)](#balanced-bsts-avl-trees)
- [Heaps](#heaps)
- [Graphs](#graph-data-structures)
  - [Types of Graphs](#types-of-graphs)
  - [Graph Representations](#graph-representations)
  - [Graph Traversal Algorithms](#graph-traversal-algorithms)
- [Comparative Analysis](#comparative-analysis)

## Binary Trees

A binary tree is a data structure where each node has at most two children, referred to as the left and right children.

![Binary Tree vs Complete Binary Tree](/week10-trees&graphs/images/binarytreevscompletebinarytree.png)

### Complete Binary Trees
A binary tree where all levels are completely filled, except possibly the last level, which is filled from left to right.

### Binary Search Trees (BSTs)
An ordered binary tree with the following properties:
- Left subtree contains only nodes with values less than the node's value
- Right subtree contains only nodes with values greater than the node's value

**Example Structure:**
```
       10
      /  \
     5    15
    / \   / \
   3   7 12  20
```

**Characteristics:**
- Efficient searching, insertion, and deletion
- Worst-case time complexity of O(n) if tree becomes skewed

![BST vs Balanced BST](/week10-trees&graphs/images/BSTvsBalancedBST.png)

### Balanced BSTs (AVL Trees)
A type of BST that uses rotations to maintain balance:
- Prevents tree from becoming skewed
- Guarantees O(log(n)) time complexity for operations
- Useful in databases and in-memory data structures

**Example Balanced Tree:**
```
       10
      /  \
     5    15
    / \     \
   3   7    20
```

## Heaps

A specialized tree-based data structure with two primary types:
- **Max-heap**: Parent node is greater than or equal to children
- **Min-heap**: Parent node is less than or equal to children

**Characteristics:**
- Always a complete binary tree
- Root node contains min/max value
- O(1) retrieval of min/max element

**Example Max-heap:**
```
       20
      /  \
     18   15
    / \   / \
   13 10  8  5
```

### Comparative Analysis of BSTs and Heaps

| Feature | Binary Search Trees | Heaps |
|---------|---------------------|-------|
| Structure | Not necessarily complete | Always complete binary tree |
| Ordering | Left child < parent < right child | Root contains min/max value |
| Min/Max Retrieval | O(log(N)) | O(1) |
| Primary Use Cases | Searching, insertion, deletion | Priority queues, heapsort |

## Graph Data Structures

![Trees vs Graphs](/week10-trees&graphs/images/treesvsbinarytree.png)

Graphs are data structures consisting of nodes (vertices) connected by edges, representing relationships between objects.

### Types of Graphs

1. **Directed Graphs (Digraphs)**
   - Edges have a direction
   - Represent one-way relationships
   - Example: Website linking structure
   ```
   A → B → C
   ```

2. **Undirected Graphs**
   - Edges have no direction
   - Represent mutual relationships
   - Example: Social network connections
   ```
   A — B — C
   ```

3. **Weighted Graphs**
   - Edges have associated weights/costs
   - Represent distances or expenses
   - Example: Road or flight networks
   ```
   A —(3)— B —(2)— C
   ```

### Graph Representations

1. **Adjacency Lists**
   - Space-efficient for sparse graphs
   - Each node maintains a list of adjacent nodes
   ```
   A: [B, C]
   B: [A, D]
   C: [A]
   D: [B]
   ```

2. **Adjacency Matrices**
   - Constant-time edge checking
   - Can be space-inefficient for sparse graphs
   ```
       A B C D
   A [ 0 1 1 0 ]
   B [ 1 0 0 1 ]
   C [ 1 0 0 0 ]
   D [ 0 1 0 0 ]
   ```

### Graph Traversal Algorithms

1. **Breadth-First Search (BFS)**
   - Explores graph level by level
   - Uses a queue
   - Best for:
     * Shortest path in unweighted graphs
     * Checking graph connectivity
     * Finding connected components

2. **Depth-First Search (DFS)**
   - Explores as deeply as possible before backtracking
   - Uses a stack
   - Best for:
     * Topological sorting
     * Cycle detection
     * Solving maze problems
     * Finding strongly connected components

### Graph Terminology

- **Adjacent Nodes**: Connected by an edge
- **Node Degree**: Number of connected edges
- **Path**: Sequence of edges connecting nodes
- **Path Length**: Number of edges (or sum of weights in weighted graphs)
- **Cycle**: Path starting and ending at the same node
