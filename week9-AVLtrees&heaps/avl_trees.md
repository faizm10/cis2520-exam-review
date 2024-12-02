# Week 10: AVL Trees and Graph
 
## Overview
We will be focusing on AVL Trees and then moving on to Graph

---

## AVL Trees

- The real question is *WHY* do we need AVL trees? The simple answer to this is that we want to avoid the worst case in the binary search tree by balancing the tree!
- The issue with this is that rebalancing the tree may take up O(n) operations. A binary tree is balanced if the height of the tree is **O (log n)**
- So AVL Trees is a way to go when we need to balance a tree with no more than O(log n).
- Height – longest path from the root to some leaf
– An empty tree has height 0 (note: some other definitions make this
as -1)
– A tree with a single node has height 1 (note: some other definitions
make this as 0)
- AVL property: If N is a node in a binary tree T, we say that node N has the **AVL property** if the heights of the left and right subtrees of node N are either equal or if they differ by 1. 
- Balance factor of node N, BF(N) = Height_(Nleft) - Height_(Nright)
- AVL Tree: A binary tree that each of its nodes has AVL property