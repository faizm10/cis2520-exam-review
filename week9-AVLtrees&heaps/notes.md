# AVL Trees and Heaps

## Table of Contents
- [AVL Trees](#avl-trees)
  - [Motivation](#motivation-for-avl-trees)
  - [Definition](#definition-of-avl-trees)
  - [Restoring AVL Property](#restoring-avl-property)
- [Heaps](#heaps)
  - [Definition](#heap-definition)
  - [Applications](#heap-applications)
  - [Operations](#heap-operations)
  - [Array Implementation](#heap-implementation-using-arrays)
- [Heapsort Algorithm](#heapsort)

## AVL Trees

### Motivation for AVL Trees

Standard binary search trees can become skewed or unbalanced, leading to:
- Degraded performance
- Linear time complexity O(n) for operations
- Inefficient search, insert, and delete operations

![AVL Tree Examples](/week9-AVLtrees&heaps/images/avltree_examples.png)

### Definition of AVL Trees

AVL trees are self-balancing binary search trees with a crucial property:
- For any node, the height difference between left and right subtrees is at most 1
- This difference is called the **Balance Factor (BF)**
- Valid Balance Factor range: -1, 0, or 1

**Example AVL Tree:**
```
       10
      /  \
     5    15
    / \     \
   3   7    20
```

![AVL Property Loss Example](/week9-AVLtrees&heaps/images/avlexample_whichnodeloseavl_property.png)

### Restoring AVL Property

When insertion or deletion disrupts the AVL property, rotations are used:

1. **Single Rotation**
   Example of a right rotation:
   ```
   Before:     20         After:     10
              /                    /  \
             10                   5    20
            /
           5
   ```

2. **Double Rotation**
   - More complex imbalances require left-right or right-left rotations
   - Ensures tree remains balanced without significantly increasing height

![Insertion Example](/week9-AVLtrees&heaps/images/insertionAVLexample_whathappenswheninsert13.png)

## Heaps

### Heap Definition

Two primary types of heaps:

1. **Max-Heap**
   - Each node's value ≥ its children's values
   - Root contains the maximum value

2. **Min-Heap**
   - Each node's value ≤ its children's values
   - Root contains the minimum value

![Heap Example](/week9-AVLtrees&heaps/images/heap_example1.png)

### Heap Applications

Heaps are crucial in:
- Priority Queues
- Job Scheduling Systems
- Customer Support Prioritization
- Operating System Task Management

### Heap Operations

1. **Insertion**
   - Add new element at the bottom level
   - "Percolate up" to maintain heap property

   ![Heap Insertion](/week9-AVLtrees&heaps/images/heapinsertion_example2.png)

2. **Removal**
   - Remove root element
   - Move last element to root
   - "Percolate down" to restore heap property

   ![Heap Removal](/week9-AVLtrees&heaps/images/heap_removal_example.png)

### Heap Implementation Using Arrays

Heap-to-Array Indexing:
- Root: Index 0
- Left Child: `(2 * i) + 1`
- Right Child: `(2 * i) + 2`
- Parent: `((i - 1) // 2)`

**Example Array Representation:**
```
Array: [25, 18, 20, 13, 10, 8, 15]
Heap:
       25
      /  \
    18    20
   / \   / 
  13  10 8  15
```

## Heapsort

A sorting algorithm utilizing heap data structure:

**Steps:**
1. Construct a max-heap (for descending sort) or min-heap (for ascending sort)
2. Repeatedly extract root element
3. Place extracted element in sorted output
4. Restore heap property after each extraction

**Example Process:**
- Input: `[4, 10, 3, 5, 1]`
- Build Max-heap
- Repeatedly extract maximum
- Final sorted array

### Complexity
- Time Complexity: O(n log n)
- Space Complexity: O(1)

