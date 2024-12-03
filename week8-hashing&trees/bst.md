# Week 6: Hashing and Trees
 
## Overview
We will be focusing on Trees 

---

## Trees

### What is a tree?

- It is a abstract model of a hierarchical structure which contains nodes and edges with a parent-child relation
- datatype can be any (e.g strings, numbers, etc)
- Some of the real life applications include:
    - Organization Charts
    - File Systems
    - Decision Process
    - etc 

### Binary Tree

- In a linked list, each node has up to one successor. In a binary tree, each node has up to two children, known as a **left** child and a **right** child. *Binary* means two, referring to the two children. Some more definitions related to a binary tree:

    - **Leaf**: A tree node with no children.
    - **Internal node**: A node with at least one child.
    - **Root**: The one tree node with no parent (the "top" node). If the root has no children, and therefore is the tree's only node, the root is a leaf. Otherwise the root is an internal node.
    - **Degree** of a node: number of children that a node has
    - **Parent**: A node with a child is that child's parent.
    - A node's **ancestors** include the node's parent, the parent's parent, etc., up to the tree's root.
    - A node's **descendants** include the node's children, the childrens' children, etc.
    - **Edge**: the line connecting a node to any of its successors.
    - **Path**: A sequence of consecutive edges.
    - **Depth**: the length of the path from the root to anode n.
        - The depth of the root node is zero.
    - **Height** of a tree: total number of nodes on the path from the root node to the deepest node in the tree.
        – A tree with only a root node has a height of 0

- This may seem a lot of definitions coming rihght at ya but don't worry, we will break it down with some visuals along the way!

![Binary Tree Example](/week8-hashing&trees/images/image1.png)

- Let's answer some questions for the image below:
    - Root Node: **Jones**
    - Smith's Left Child: **Kumar**
    - How Many Leaf Nodes? **4 Leaf Nodes**
        - Who?? **Kumar, Lee, Gong and Carvey**
    - How Many Internal Nodes? **4 Internal Nodes (Remeber that any node with a child is an internal node)**
        - Who?? **Jones, Smith, Adams and Gupta**
    - The tree has an internal node, Gupta, with only one child rather than two. Is the tree still a binary tree? **YES!!! In a binary tree, each node has up to two children. So the tree is still a binary tree.**
    - Gupta's ancestors are _____. **Adams and Jones**
        - How? **Ancestors are determined by starting at a node's parent and then continuously going up to the next parent until reaching the root. Doing so for Gupta visits only two nodes: Adams and Jones.**
    - The descendants of Adams are _____. **Gong, Gupta and Carvey**
        - How? **Descendants are determined by starting at a node's children and then continuing down to the leaves. Doing so for Adams visits three nodes: Gong, Gupta, and Carvey.**

![Binary Tree Example](/week8-hashing&trees/images/image3.png)

### Special types of Binary Trees

- Certain binary tree structures can affect the speed of operations on the tree. The following describe special types of binary trees:
    - A binary tree is **full** if every node contains 0 or 2 children.
    - A binary tree is **complete** if all levels, except possibly the last level, contain all possible nodes and all nodes in the last level are as far left as possible.
    - A binary tree is **perfect** if all internal nodes have 2 children and all leaf nodes are at the same level.

![Types of Binary Tree](/week8-hashing&trees/images/image2.png)

### Subtree

- A binary tree subtree is any node X in the tree and all of X's descendants. Node X is the subtree's root, and the subtree itself is a valid binary tree.

![SubTree](/week8-hashing&trees/images/image4.png)

### Binary Tree Representation

- **Linked Representation**:
  - Each node contains:
    - A left pointer.
    - A data value.
    - A right pointer.
  - `ROOT` points to the tree's root node. If `ROOT = NULL`, the tree is empty.

```c
struct node {
    struct node *left;
    int data;
    struct node *right;
};
```
---

### Binary Tree Traversal Techniques

#### **Traversal**: Visiting each node in the tree exactly once in a systematic order.

1. **Pre-order Traversal (Depth-First)**:
   - Visit root.
   - Traverse left subtree.
   - Traverse right subtree.
   - Example order: `A, B, C`.

![Pre-Order](/week8-hashing&trees/images/image5.png)

2. **In-order Traversal (Symmetric)**:
   - Traverse left subtree.
   - Visit root.
   - Traverse right subtree.
   - Example order: `B, A, C`.

![In-Order](/week8-hashing&trees/images/image5.png)

3. **Post-order Traversal**:
   - Traverse left subtree.
   - Traverse right subtree.
   - Visit root.
   - Example order: `B, C, A`.

![Post-Order](/week8-hashing&trees/images/image5.png)

4. **Level-order Traversal (Breadth-First)**:
   - Visit nodes level by level, left to right.
   - Example order: `A, B, C`.

![Pre-Order](/week8-hashing&trees/images/image5.png)

---



## Binary Search Tree (BST)

### **Definition of Binary Search Tree**
- A BST search algorithm has a currentNode pointer that starts at the tree's root. The search key is compared against currentNode's key. If a match occurs, currentNode is returned. Otherwise currentNode is reassigned with:
    - the left child if the search key is **<** currentNode's key,
    - the right child if the search key is **>** currentNode's key.
- The algorithm continues until either a match is found or currentNode is null.

![Binary Search Tree](/week8-hashing&trees/images/image6.png)

---

### Binary Search Tree Operations

#### **1. Search**
- **Algorithm**:
  - Start at the root.
  - Compare the target key `k` with the current node's key.
    - If `k == current node`, return the node.
    - If `k < current node`, move to the left child.
    - If `k > current node`, move to the right child.
  - If a leaf is reached without finding `k`, return `NO_SUCH_KEY`.

```pseudo
BSTSearch(tree, key)
    cur = tree⇢root
    while (cur is not null) do
        if (key == cur⇢key) then
            return cur // Found
        else if (key < cur⇢key) then
            cur = cur⇢left
        else
            cur = cur⇢right
    end while
    return null // Not found
```
- **Example**: Searching for `4` in the tree:
  - Visit nodes in the order `6 → 4`.

![Binary Search Tree -- Search Example](/week8-hashing&trees/images/image7.png)

---

#### **2. Insertion**
- **Algorithm**:
  - Search for the location to insert the key `k`.
  - Insert the new node as a leaf.
  - Special Case: If the tree is empty, the new node becomes the root.
```pseudo
BSTInsert(tree, node)
    if (tree⇢root is null) then
        tree⇢root = node
    else
        currentNode = tree⇢root
        while (currentNode is not null) do
            if (node⇢key < currentNode⇢key) then
                if (currentNode⇢left is null) then
                    currentNode⇢left = node
                    currentNode = null
                else
                    currentNode = currentNode⇢left
                end if
            else
                if (currentNode⇢right is null) then
                    currentNode⇢right = node
                    currentNode = null
                else
                    currentNode = currentNode⇢right
                end if
            end if
        end while
    end if
```
- **Example**: Inserting `5`:
  - Traversal: `6 → 4`.
  - Insert `5` as the right child of `4`.

![Binary Search Tree -- Insertion Example](/week8-hashing&trees/images/image8.png)

---

#### **3. Removal**
- **Algorithm**:
  - Search for the node `X` with the matching key.
  - Handle the following cases:
    1. **Leaf Node**:
       - If `X` is a leaf, set its parent’s pointer to `null`.
       - If `X` is the root, the tree becomes empty.
    2. **Internal Node with One Child**:
       - Replace `X` with its child.
       - If `X` is the root, the root pointer is updated to `X`'s child.
    3. **Internal Node with Two Children**:
       - Locate `X`'s successor (leftmost child of `X`'s right subtree).
       - Copy the successor's value to `X`.
       - Recursively remove the successor.

- **Example**:
  - Remove `25`:
    - Successor is found in the right subtree.
    - Update node and recursively remove the successor.

![Binary Search Tree -- Removal](/week8-hashing&trees/images/image9.png)
![Binary Search Tree -- Removal](/week8-hashing&trees/images/image10.png)

---

### Summary of Operations
| **Operation**    | **Time Complexity** |
|-------------------|---------------------|
| Search            | O(h)               |
| Insertion         | O(h)               |
| Removal           | O(h)               |

**Note**: `h` is the height of the tree. For balanced trees, `h = O(log n)`.

---

### References
- "Binary Search Tree" Notes by Yan Yan
- Data Structures resources and diagrams from provided materials.


### References
- "Data Structures Using C" (2nd Edition) by Reema Thareja.
- [GeeksforGeeks](https://www.geeksforgeeks.org/dfs-traversal-of-a-tree-using-recursion/)
- [Level-Order Traversal](https://www.geeksforgeeks.org/level-order-tree-traversal/)
