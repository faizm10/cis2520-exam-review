# Week 2: Algorithm Complexity and Sorting

## Overview
This week focuses on understanding the performance of algorithms and the efficiency of sorting methods. Key topics include analyzing algorithms, asymptotic notations, and exploring sorting algorithms with their time and space complexities.

---

## Table of Contents
1. [What Are Algorithms?](#what-are-algorithms)
2. [Analyzing Algorithms](#analyzing-algorithms)
3. [Asymptotic Notations](#asymptotic-notations)
4. [Complexity Calculations](#complexity-calculations)
5. [Sorting Algorithms](#sorting-algorithms)
6. [Summary of Sorting Complexities](#summary-of-sorting-complexities)
7. [Resources](#resources)

---

## What Are Algorithms?

### Definition
An **algorithm** is a step-by-step, well-defined computational process that transforms inputs into outputs to solve a specific problem.

### Key Concepts
- **Problem**: The goal to be achieved.
- **Instance**: An example of inputs and outputs.
- **Correct Algorithm**: Produces the correct output for all valid inputs.

#### Example: Sorting Problem
**Input**: A sequence of `n` numbers.  
**Output**: A permutation of the input in ascending order.  
**Example**:  
Input: `[7, 4, 3, 1, 5, 4]` → Output: `[1, 3, 4, 4, 5, 7]`

---

## Analyzing Algorithms

### Why Analyze Algorithms?
To predict:
- **Time Complexity**: How long the algorithm takes.
- **Space Complexity**: How much memory the algorithm uses.

### Key Factors
1. **Input Size**: Examples:
   - Sorting: Number of elements/items.
   - Graphs: Number of vertices and edges.
2. **Operations**:
   - Examples: Comparisons, additions, multiplications.

### Analyzing Algorithm -- Operations
- **Best Case**: Fastest performance.
- **Worst Case**: Slowest performance.
- **Average Case**: Performance averaged over all inputs.

#### Example: Loops and Their Growth
1. **Linear Loop**:
   ```c
   for (i = 1; i <= n; i++) {
       x = x + 1;
   }
   // Total operations: O(n)
   ```
2. **Nested Loop**:
   ```c
   for (i = 1; i <= n; i++) {
       for (j = 1; j <= n; j++) {
           x = x + 1;
       }
   }
   // Total operations: O(n^2)
   ```

---

## Asymptotic Notations

### 1. Big-O Notation (`O`)
Defines the **upper bound** of an algorithm's runtime. It describes the worst-case scenario.
- **Formal Definition**: `f(n) ∈ O(g(n))` if there exist constants `c > 0` and `n0` such that for all `n ≥ n0`:  
  `f(n) ≤ c * g(n)`

- Constant c could depend on
    – the programming language used,
    – the quality of the compiler or interpreter,
    – the CPU speed,
    – the size of the main memory and the access time to it,
    – the knowledge of the programmer,
    – the algorithm itself, which may require simple but also time-consuming machine instructions

### Big-O Examples

#### Example 1: Show that `2n = O(n²)`

To prove `2n = O(n²)`, we do the following steps:

1. By definition, we need to find a constant `c` such that:  
   `f(n) ≤ c * g(n)`

2. Substitute `f(n) = 2n` and `g(n) = n²`:  
   `2n ≤ c * n²`

3. Simplify by dividing both sides by `n` (valid since `n > 0`):  
   `2 ≤ c`

4. Choose constants `c` and `n₀` to satisfy the Big-O definition:  
   `c = 2`, `n₀ = 1`

Thus, for `n ≥ 1`, the inequality holds true. Therefore:  
`2n = O(n²)`


### 2. Omega Notation (`Ω`)
Defines the **lower bound** of an algorithm's runtime. It describes the best-case scenario.
- **Formal Definition**: `f(n) ∈ Ω(g(n))` if there exist constants `c > 0` and `n0` such that for all `n ≥ n0`:  
  `f(n) ≥ c * g(n)`

### Omega Notation Example

#### Example: Show that `2n ≠ Ω(n²)`

To prove `2n ≠ Ω(n²)`, we do the following steps:

1. By definition, we need to find a constant `c` such that:  
   `f(n) ≥ c * g(n)`

2. Substitute `f(n) = 2n` and `g(n) = n²`:  
   `2n ≥ c * n²`

3. Simplify by dividing both sides by `n` (valid since `n > 0`):  
   `2/n ≥ c`

4. As `n` becomes larger, the value of `2/n` gets closer and closer to 0.

5. The only possible value for `c` would be `0`, but `c` must be a positive constant (`c ∈ R⁺`).

6. Therefore, no such constant `c` exists, and we conclude that:  
   `2n ≠ Ω(n²)`

This proves the inequality by contradiction.

### 3. Theta Notation (`Θ`)
Defines a **tight bound**, meaning the algorithm runs between a lower and upper bound.
- **Formal Definition**: `f(n) ∈ Θ(g(n))` if `f(n) ∈ O(g(n))` and `f(n) ∈ Ω(g(n))`.

### Theta Notation Example

#### Example: Show that `2n = Θ(n)`

To prove `2n = Θ(n)`, we do the following steps:

1. By definition, we need to find constants `c₁` and `c₂` such that:  
   `c₁ * g(n) ≤ f(n) ≤ c₂ * g(n)`

2. Substitute `f(n) = 2n` and `g(n) = n`:  
   `c₁ * n ≤ 2n ≤ c₂ * n`

3. Divide all terms by `n` (valid since `n > 0`):  
   `c₁ ≤ 2 ≤ c₂`

4. Choose constants to satisfy the inequality:  
   `c₁ = 1`, `c₂ = 2`, and `n₀ = 1`.

Thus, for `n ≥ 1`, the inequality holds true. Therefore:  
`2n = Θ(n)`

### Brief Overview of Little-o and Little-Omega Notation

#### Little-o Notation (`o`)
- **Definition**: Little-o describes an **upper bound** that is not tight. It means `f(n)` grows strictly slower than `g(n)` as `n` becomes very large.
- **Key Idea**: `f(n)` approaches 0 relative to `g(n)` as `n` increases.
- **Example**: `f(n) = n` is `o(n²)` because `n` grows much slower than `n²`.

#### Little-Omega Notation (`ω`)
- **Definition**: Little-omega describes a **lower bound** that is not tight. It means `f(n)` grows strictly faster than `g(n)` as `n` becomes very large.
- **Key Idea**: `f(n)` grows infinitely larger compared to `g(n)` as `n` increases.
- **Example**: `f(n) = n²` is `ω(n)` because `n²` grows much faster than `n`.

---

## Complexity Calculations

Some sample questions below:

Computer solves problem of complexity **T(n) ∈ 𝜣 (n3)** & size **n = 1000** in 1 minute. What size would be solved in 1 hour?

1. Simplify the equation:
`(𝑐 ∗ (100)^3)/(𝑐 ∗ (𝑥)^3) = 1/60`
2. Solve for **x**:
`(𝑥)^3 = 60 * (100)^3`
3. Calculate **x**
`x = 3914`

#### Conclusion: 
The computer can solve a problem of size **x = 3914** in 1 hour. Note that **x ∈ ℕ** (it must be a natural number).

## Sorting Algorithms

### 1. Bubble Sort
Repeatedly swaps adjacent elements that are out of order.  
- **Best Case**: `O(n)`
- **Worst Case**: `O(n^2)`
- **Space Complexity**: `O(1)`

---

### 2. Selection Sort

Finds the smallest element and places it in the correct position.  

---

### Steps:
- Orders a list of values by repeatedly putting the smallest or largest unplaced value into its final position.
  - Look through the list to find the smallest value.
  - Swap it so that it is at index 0.
  - Look through the list to find the second-smallest value.
  - Swap it so that it is at index 1.
  - Repeat until all values are in their proper places.

---

![Selection Sort Example](/week2-complexity/images/selectionsort.png)

- **Best Case**: `O(n^2)`  
- **Worst Case**: `O(n^2)`  
- **Space Complexity**: `O(1)`

---

### 3. Insertion Sort
Builds a sorted sub-array by repeatedly inserting elements in the correct position.  
- **Best Case**: `O(n)`
- **Worst Case**: `O(n^2)`
- **Space Complexity**: `O(1)`

---

### 4. Merge Sort
Uses the "divide and conquer" strategy to split the array, sort each half, and merge them.  

---

![Merge Sort Example](/week2-complexity/images/mergesort.png)

- **Best Case**: `O(n log n)`
- **Worst Case**: `O(n log n)`
- **Space Complexity**: `O(n)`

---

### 5. Quick Sort
Recursively partitions the array based on a pivot element.  
- **Best Case**: `O(n log n)`
- **Worst Case**: `O(n^2)` (happens when pivot selection is poor)
- **Space Complexity**: `O(n)`

---

## Summary of Sorting Complexities

| **Algorithm**     | **Best Case**     | **Worst Case**    | **Space Complexity** |
|--------------------|-------------------|-------------------|-----------------------|
| **Bubble Sort**    | `Ω(n)`           | `O(n^2)`          | `O(1)`               |
| **Selection Sort** | `Ω(n^2)`         | `O(n^2)`          | `O(1)`               |
| **Insertion Sort** | `Ω(n)`           | `O(n^2)`          | `O(1)`               |
| **Merge Sort**     | `Ω(n log n)`     | `O(n log n)`      | `O(n)`               |
| **Quick Sort**     | `Ω(n log n)`     | `O(n^2)`          | `O(n)`               |

## Resources

### Merge Sort:
- [Time and Space Complexity Analysis of Merge Sort](https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-merge-sort/)

### Time Complexity of Sorting Algorithms:
- [GeeksforGeeks: Time Complexities of All Sorting Algorithms](https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/)
- [Board Infinity: Time Complexity of Sorting Algorithms](https://www.boardinfinity.com/blog/time-complexity-of-sorting-algorithms/)
