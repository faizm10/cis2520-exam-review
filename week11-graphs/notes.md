# Week 11: GraphPath

## Overview

This document provides a comprehensive guide to two fundamental shortest path algorithms: **Dijkstra's Algorithm** and **Bellman-Ford's Algorithm**. These algorithms are crucial in solving graph-related problems and finding the most efficient routes in various applications.

---

## Table of Contents
- [Dijkstra's Algorithm](#dijkstras-algorithm)
  - [Characteristics](#characteristics)
  - [Example Procedure](#example-procedure)
  - [Pseudocode](#pseudocode)
  - [Time Complexity](#time-complexity)
- [Bellman-Ford's Algorithm](#bellman-fords-algorithm)
  - [Characteristics](#characteristics-1)
  - [Initialization](#initialization)
  - [Relaxation](#relaxation)
  - [Negative Weight Cycle Check](#negative-weight-cycle-check)
  - [Example Procedure](#example-procedure-1)
  - [Pseudocode](#pseudocode-1)
  - [Time Complexity](#time-complexity-1)
- [Comparative Analysis](#comparative-analysis)

---

## Dijkstra's Algorithm

### Characteristics
- Used to find the shortest path from a starting node to all other nodes in a graph.
- Works on both directed and undirected graphs.
- Requires **positive weights only**.
- Efficient for graphs without negative edge weights.

---

### Example

What’s the shortest path between nodes 1 and 2?

![Dijkstra's Basics](/week11-graphs/images/ds_review.png)

---

### Example Procedure

Consider a graph with the following edges:
- \(0 \xrightarrow{1} 1\)  
- \(0 \xrightarrow{4} 2\)  
- \(1 \xrightarrow{2} 2\)  
- \(1 \xrightarrow{6} 3\)  
- \(2 \xrightarrow{3} 3\)

**Step-by-Step Process:**
1. **Initialization**:  
   - Start at node 0 with distance 0.  
   - Set all other nodes' distances to infinity.  

2. **Node Visitation**:  
   - Visit Node 0: Update neighbors:  
     - Distance to 1: 1  
     - Distance to 2: 4  
   - Visit Node 1: Update neighbors:  
     - Distance to 2: \(\min(4, 1+2) = 3\)  
     - Distance to 3: \(1+6 = 7\)  
   - Visit Node 2: Update neighbors:  
     - Distance to 3: \(\min(7, 3+3) = 6\)  
   - Visit Node 3: Completed.  

---

### Pseudocode
```python
def dijkstra(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    pq = [(0, start)]
    
    while pq:
        current_distance, current_vertex = heapq.heappop(pq)
        
        if current_distance > distances[current_vertex]:
            continue
        
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight
            
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))
    
    return distances
```

---

### Time Complexity
- **Using a List**: \(O(V^2)\)  
- **Using a Binary Heap**: \(O((E + V) \log V)\)  
- **Using a Fibonacci Heap**: \(O(E + V \log V)\)  

---

## Bellman-Ford's Algorithm

### Characteristics
- Handles graphs with **negative edge weights**.  
- Detects **negative weight cycles**.  
- More versatile but slower compared to Dijkstra's algorithm.  

---

### Initialization
1. Set all node distances to infinity (\(\infty\)).  
2. Set the starting node's distance to 0.  
3. Initialize predecessors as null.  

---

### Relaxation
For each edge \((u, v)\) with weight \(w\):  
- Check if \(distance[v] > distance[u] + w\).  
- If true, update \(distance[v]\) and set predecessor of \(v\) to \(u\).  

---

### Negative Weight Cycle Check
1. After \(V-1\) iterations, check all edges again.  
2. If a shorter path is still found, a **negative weight cycle exists**.  

---

### Example Procedure

Consider a graph with the following edges:
- \(0 \xrightarrow{1} 1\)  
- \(0 \xrightarrow{4} 2\)  
- \(1 \xrightarrow{3} 2\)  
- \(1 \xrightarrow{6} 3\)  
- \(2 \xrightarrow{3} 3\)  

**Step-by-Step Process:**
1. **Initialization**:  
   - Start at node 0 with distance 0.  
   - Set all other nodes' distances to infinity.  

2. **Relaxation**:  
   - First Iteration:  
     - Relax \(0 \to 1\): Distance to 1 = 1  
     - Relax \(0 \to 2\): Distance to 2 = 4  
     - Relax \(1 \to 2\): Distance to 2 = 3  
     - Relax \(1 \to 3\): Distance to 3 = 7  
     - Relax \(2 \to 3\): Distance to 3 = 6  

3. **Negative Cycle Check**:  
   - No further updates.  
   - No negative weight cycle detected.  

---

### Pseudocode
```python
def bellman_ford(graph, start):
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0
    
    for _ in range(len(graph) - 1):
        for vertex in graph:
            for neighbor, weight in graph[vertex].items():
                if distances[vertex] + weight < distances[neighbor]:
                    distances[neighbor] = distances[vertex] + weight
    
    for vertex in graph:
        for neighbor, weight in graph[vertex].items():
            if distances[vertex] + weight < distances[neighbor]:
                raise ValueError("Graph contains a negative weight cycle")
    
    return distances
```

---

### Time Complexity
- **Best Case**: \(O(E)\)  
- **Worst Case**: \(O(V \times E)\)  

---

## Comparative Analysis

| **Feature**             | **Dijkstra's Algorithm**      | **Bellman-Ford Algorithm**    |
|--------------------------|-------------------------------|--------------------------------|
| **Weight Handling**      | Positive weights only         | Handles negative weights      |
| **Negative Cycle Detection** | No                        | Yes                            |
| **Time Complexity**      | \(O((E + V) \log V)\)         | \(O(V \times E)\)             |
| **Use Case**             | Faster for positive weights   | Versatile, handles complex cases |

---

## Conclusion

Both algorithms solve the shortest path problem but have different strengths. Use **Dijkstra’s** for faster performance when negative weights are not present, and **Bellman-Ford** when graphs contain negative edge weights.
## Resources

## Additional Resources

1. **Dijkstra's Shortest Path Algorithm - A Detailed and Visual Introduction**  
   [Read on freeCodeCamp](https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/#:~:text=Dijkstra's%20Algorithm%20finds%20the%20shortest,node%20and%20all%20other%20nodes.)

2. **Bellman-Ford's Algorithm**  
   [Read on GeeksforGeeks](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)

3. **Dijkstra's vs Bellman-Ford Algorithm**  
   [Read on Medium](https://medium.com/@brianpatrao1996/dijkstras-vs-bellman-ford-algorithm-383e4771c2cb#:~:text=One%20of%20the%20main%20benefits,is%20the%20number%20of%20vertices.)