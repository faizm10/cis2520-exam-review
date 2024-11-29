# Week 6: Hashing and Trees
 
## Overview
We will be focusing on Binary Search Tree 

## Binary Search Tree (BST)

### **Definition of Binary Search Tree**
- A BST search algorithm has a currentNode pointer that starts at the tree's root. The search key is compared against currentNode's key. If a match occurs, currentNode is returned. Otherwise currentNode is reassigned with:
    - the left child if the search key is **<** currentNode's key,
    - the right child if the search key is **>** currentNode's key.
- The algorithm continues until either a match is found or currentNode is null.

![Binary Search Tree](/week6-hashingandtrees/images/image6.png)

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

![Binary Search Tree -- Search Example](/week6-hashingandtrees/images/image7.png)

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

![Binary Search Tree -- Insertion Example](/week6-hashingandtrees/images/image8.png)

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

![Binary Search Tree -- Removal](/week6-hashingandtrees/images/image9.png)
![Binary Search Tree -- Removal](/week6-hashingandtrees/images/image10.png)

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