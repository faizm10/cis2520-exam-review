# Week 12: Final Review

## Final Exam Practice Quiz

---

### **Question 1**  
**Which of the following is true about a hash table?**  
- It maps each item to a specific location using a key  
- It can only store sorted items  
- It uses a stack to manage collisions  
- It relies on depth-first search to retrieve items  

**Answer:** It maps each item to a specific location using a key  
**Explanation:** A hash table uses a **key** to calculate an index where the value is stored, enabling fast lookups and updates.

---

### **Question 2**  
**Which collision resolution method uses linked lists at each bucket?**  
- Quadratic Probing  
- Double Hashing  
- Linear Probing  
- Chaining  

**Answer:** Chaining  
**Explanation:** Chaining stores multiple items in the same bucket using linked lists, resolving collisions by linking the items together.

---

### **Question 3**  
**Which of the following statements about linear probing is true?**  
- It always results in evenly distributed keys  
- It requires linked lists to store all collided items  
- It requires the use of a secondary hash function  
- It can lead to primary clustering  

**Answer:** It can lead to primary clustering  
**Explanation:** Linear probing can cause **primary clustering**, where adjacent filled buckets create long chains, making it harder to find empty slots.

---

### **Question 4**  
**The quadratic probing method ensures that items will always find an empty bucket to be inserted into.**  
- True  
- False  

**Answer:** False  
**Explanation:** Quadratic probing can fail to find an empty bucket if the hash table isn't properly configured (e.g., prime size, appropriate load factor).

---

### **Question 5**  
**In double hashing, the secondary hash function must return a value that can be zero.**  
- True  
- False  

**Answer:** False  
**Explanation:** The secondary hash function determines the step size. If it returns 0, the algorithm would get stuck in the same bucket.

---

### **Question 6**  
**A collision in a hash table occurs when two different keys map to the same bucket.**  
- True  
- False  

**Answer:** True  
**Explanation:** Collisions happen when the hash function maps two different keys to the same index in the hash table.

---

### **Question 7**  
**Which traversal method of a tree is most similar to the breadth-first search (BFS) of a graph?**  
- Post-order traversal  
- In-order traversal  
- Level-order traversal  
- Pre-order traversal  

**Answer:** Level-order traversal  
**Explanation:** Level-order traversal visits tree nodes level by level, just like BFS explores a graph layer by layer.

---

### **Question 8**  
**In a depth-first search (DFS) of a graph, which of the following data structures is typically used?**  
- Priority Queue  
- Stack  
- Queue  
- Linked List  

**Answer:** Stack  
**Explanation:** DFS uses a stack (explicit or implicit via recursion) to explore one branch deeply before backtracking.

---

### **Question 9**  
**What type of graph is required for a topological sort to be valid?**  
- Undirected Graph  
- Cyclic Graph  
- Directed Acyclic Graph  
- Weighted Graph  

**Answer:** Directed Acyclic Graph  
**Explanation:** Topological sorting applies only to **DAGs** because cycles would make it impossible to order the vertices linearly.

---

### **Question 10**  
**Which of the following algorithms is used to determine the shortest path from a source vertex to all other vertices, even with negative weights?**  
- Dijkstra's Algorithm  
- Depth-First Search (DFS)  
- Bellman-Ford's Algorithm  
- Topological Sort  

**Answer:** Bellman-Ford's Algorithm  
**Explanation:** Bellman-Ford works with graphs that have negative weights and detects negative weight cycles.

---

### **Question 11**  
**Which of the following statements is true about directed weighted graphs?**  
- Only cyclic graphs can have topological sort  
- All paths have equal weight  
- Weights cannot be greater than the number of nodes  
- Weights can be negative, but must not form negative weight cycles for shortest path calculations  

**Answer:** Weights can be negative, but must not form negative weight cycles for shortest path calculations  
**Explanation:** Algorithms like Bellman-Ford handle negative weights but fail if negative weight cycles exist, as they make shortest path calculations undefined.

---

### **Question 12**  
**In an adjacency matrix representation of a graph, determining if two vertices are adjacent takes O(V) time, where V is the number of vertices.**  
- True  
- False  

**Answer:** False  
**Explanation:** Checking adjacency in an adjacency matrix takes O(1) time, as it's a direct lookup.

---

### **Question 13**  
**The time complexity of the topological sort algorithm is O(|V| + |E|).**  
- True  
- False  

**Answer:** True  
**Explanation:** Topological sort processes each vertex and edge once, giving a complexity of O(|V| + |E|).

---

### **Question 14**  
**The space complexity of a graph representation using an adjacency list is O(V + E).**  
- True  
- False  

**Answer:** True  
**Explanation:** An adjacency list stores all vertices and their edges, requiring O(V + E) space.

---

### **Question 15**  
**A complete binary tree is a tree where all levels, except possibly the last, are completely filled, and all nodes are as far left as possible.**  
- True  
- False  

**Answer:** True  
**Explanation:** This is the definition of a complete binary tree.

---

### **Question 16**  
**In a binary search tree (BST), nodes in the left subtree of a node have values greater than the node's value.**  
- True  
- False  

**Answer:** False  
**Explanation:** In a BST, nodes in the left subtree have values **less than** the node's value.

---

### **Question 17**  
**In a tree, the root node is the only node that does not have a parent.**  
- True  
- False  

**Answer:** True  
**Explanation:** The root node is the topmost node and does not have a parent.

---

### **Question 18**  
**In a complete binary tree, every level must be completely filled with nodes.**  
- True  
- False  

**Answer:** False  
**Explanation:** Only the last level may be partially filled, and the nodes must be as far left as possible.

---

### **Question 19**  
**In a binary search tree (BST), nodes in the left subtree have values less than the root node, and nodes in the right subtree have values greater than the root node.**  
- True  
- False  

**Answer:** True  
**Explanation:** This is the basic property of a binary search tree.

---

### **Question 20**  
**In a binary tree, the number of children a node can have is called the node’s degree.**  
- True  
- False  

**Answer:** True  
**Explanation:** The degree of a node refers to the number of its children. For example, a leaf node has a degree of 0.

---

### **Question 21**  
**Post-order traversal visits the root node before visiting its left and right subtrees.**  
- True  
- False  


**Answer:** False  
**Explanation:** In post-order traversal, the root is visited **after** the left and right subtrees.

---

### **Question 22**  
**Which of the following traversal methods visits the root node last?**  
- Pre-order  
- In-order  
- Post-order  
- Level-order  

**Answer:** Post-order  
**Explanation:** Post-order traversal visits the root node **after** traversing both the left and right subtrees.

---

### **Question 23**  
**Which of the following is a correct property of a Binary Search Tree (BST)?**  
- Inserting values is always done at the root  
- The left subtree contains only nodes with values greater than the root  
- The left and right subtrees are not restricted in value  
- Each node's value must be greater than the values in its left subtree  

**Answer:** Each node's value must be greater than the values in its left subtree  
**Explanation:** A BST property ensures that values in the left subtree are smaller, and values in the right subtree are greater than the node.

---

### **Question 24**  
**What does an AVL tree maintain to ensure balance?**  
- The height difference between left and right subtrees is at most 1  
- Each node has exactly two children  
- The number of nodes in the left subtree is equal to the number in the right subtree  
- Each level of the tree is completely filled  

**Answer:** The height difference between left and right subtrees is at most 1  
**Explanation:** An AVL tree maintains balance by ensuring the height difference (balance factor) of the left and right subtrees of any node is no more than 1.

---

### **Question 25**  
**Which of the following correctly defines a max-heap?**  
- The tree is always completely filled  
- Every child node has a value greater than its parent node  
- Every parent node has a value greater than or equal to its child nodes  
- All nodes have the same value  

**Answer:** Every parent node has a value greater than or equal to its child nodes  
**Explanation:** A max-heap ensures the parent node's value is always greater than or equal to its children's values.

---

### **Question 26**  
**A single rotation can always fix any imbalance in an AVL tree.**  
- True  
- False  

**Answer:** False  
**Explanation:** Some imbalances in an AVL tree require a **double rotation** to restore balance.

---

### **Question 27**  
**The balance factor of a node in an AVL tree must be 0, 1, or -1.**  
- True  
- False  

**Answer:** True  
**Explanation:** The balance factor of a node in an AVL tree is defined as the height difference between the left and right subtrees, which must be -1, 0, or 1.

---

### **Question 28**  
**In an AVL tree, a rotation is needed whenever a new node is inserted.**  
- True  
- False  

**Answer:** False  
**Explanation:** A rotation is only needed if the insertion causes the AVL balance factor to exceed the range -1 to 1.

---

### **Question 29**  
**An adjacency matrix is not symmetric along the major diagonal. This points to the fact that the graph may be**  
- A hyperbolic graph  
- An undirected graph  
- A digraph  
- A sparse graph  
- None of these  

**Answer:** A digraph  
**Explanation:** A directed graph (digraph) does not have symmetric relationships, so its adjacency matrix is not symmetric.

---

### **Question 30**  
**Given a graph G(V, E), and |V|=v, and |E|=e, if G is a tree then:**  
- v = e  
- v + 1 = e  
- v = e - 1  
- v = e + 1  

**Answer:** v = e + 1  
**Explanation:** In a tree, the number of vertices is always **one more than the number of edges**, so v = e + 1.