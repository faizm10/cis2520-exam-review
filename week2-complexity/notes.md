# Week 2: Algorithm Complexity and Sorting

## Overview
This week focuses on understanding the performance of algorithms and the efficiency of sorting methods. Key topics include analyzing algorithms, asymptotic notations, and exploring sorting algorithms with their time and space complexities.

---

## Table of Contents
1. [What Are Algorithms?](#what-are-algorithms)
2. [Analyzing Algorithms](#analyzing-algorithms)
3. [Asymptotic Notations](#asymptotic-notations)
4. [Sorting Algorithms](#sorting-algorithms)
5. [Summary of Sorting Complexities](#summary-of-sorting-complexities)

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
  
#### Examples:
- Linear Growth: `O(n)`
- Quadratic Growth: `O(n^2)`

---

### 2. Omega Notation (`Ω`)
Defines the **lower bound** of an algorithm's runtime. It describes the best-case scenario.
- **Formal Definition**: `f(n) ∈ Ω(g(n))` if there exist constants `c > 0` and `n0` such that for all `n ≥ n0`:  
  `f(n) ≥ c * g(n)`

---

### 3. Theta Notation (`Θ`)
Defines a **tight bound**, meaning the algorithm runs between a lower and upper bound.
- **Formal Definition**: `f(n) ∈ Θ(g(n))` if `f(n) ∈ O(g(n))` and `f(n) ∈ Ω(g(n))`.

---

## Sorting Algorithms

### 1. Bubble Sort
Repeatedly swaps adjacent elements that are out of order.  
- **Best Case**: `O(n)`
- **Worst Case**: `O(n^2)`
- **Space Complexity**: `O(1)`

---

### 2. Selection Sort
Finds the smallest element and places it in the correct position.  
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
| **Bubble Sort**    | `O(n)`           | `O(n^2)`          | `O(1)`               |
| **Selection Sort** | `O(n^2)`         | `O(n^2)`          | `O(1)`               |
| **Insertion Sort** | `O(n)`           | `O(n^2)`          | `O(1)`               |
| **Merge Sort**     | `O(n log n)`     | `O(n log n)`      | `O(n)`               |
| **Quick Sort**     | `O(n log n)`     | `O(n^2)`          | `O(n)`               |
