# Week 11: GraphPath

## Overview

This document provides a comprehensive guide to two fundamental shortest path algorithms: Dijkstra's Algorithm and Bellman-Ford's Algorithm. These algorithms are crucial in solving graph-related problems and finding the most efficient routes in various applications.

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

## Dijkstra's Algorithm

### Characteristics
- Used to find the shortest path from a starting node to all other nodes in a graph
- Works on both directed and undirected graphs
- Requires **positive weights only**
- Efficient for graphs without negative edge weights

### Example, whats the shortest path here? between 1 and 2:
![DijKstra's Basics](reviewCIS2520/cis2520-exam-review/week11-graphs/images/ds_review.png) 

### Example Procedure

Consider a graph with the following edges:
- 0 --1--> 1 
- 0 --4--> 2 
- 1 --2--> 2 
- 1 --6--> 3 
- 2 --3--> 3

**Step-by-Step Process:**
1. **Initialization**: 
   - Start at node 0 with distance 0
   - Set all other nodes' distances to infinity

2. **Node Visitation**:
   - Visit Node 0: Update neighbors
     * Distance to 1: 1
     * Distance to 2: 4
   - Visit Node 1: Update neighbors
     * Distance to 2: min(4, 1+2) = 3
     * Distance to 3: 1+6 = 7
   - Visit Node 2: Update neighbor
     * Distance to 3: min(7, 3+3) = 6
   - Visit Node 3: Completed

### Pseudocode
```python
Algorithm Dijkstra(Graph, source):
    // Initialization
    Create vertex set Q
    For each vertex v in Graph:
        distance[v] ← INFINITY
        previous[v] ← UNDEFINED
        Add v to Q
    
    // Distance to source is zero
    distance[source] ← 0
    
    // Main algorithm
    While Q is not empty:
        // Select vertex u in Q with smallest distance
        u ← vertex in Q with minimum distance[u]
        Remove u from Q
        
        // For each neighbor v of u still in Q
        For each neighbor v of u:
            // Calculate alternative path length
            alt ← distance[u] + length(u, v)
            
            // If alternative path is shorter, update distance
            If alt < distance[v]:
                distance[v] ← alt
                previous[v] ← u
    
    // Return both distances and previous vertices for path reconstruction
    Return distance[], previous[]


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

### Time Complexity
- Using a list: O(V²)
- Using a binary heap: O((E + V) log V)
- Using a Fibonacci heap: O(E + V log V)

## Bellman-Ford's Algorithm

### Characteristics
- Can handle graphs with **negative edge weights**
- Detects negative weight cycles
- More versatile but slower compared to Dijkstra's algorithm

### Initialization
- Set all node distances to infinity
- Set the starting node's distance to 0
- Initialize predecessors as null

### Relaxation
For each edge (u, v) with weight w:
- Check if `distance[v] > distance[u] + w`
- If true, update `distance[v]` and set predecessor of v to u

### Negative Weight Cycle Check
- Perform an additional iteration after V-1 main iterations
- If a shorter path is found, a negative weight cycle exists

### Example Procedure

Consider a graph with these edges:
- 0 --1--> 1
- 0 --4--> 2
- 1 ---3--> 2
- 1 --6--> 3
- 2 --3--> 3

**Step-by-Step Process:**
1. **Initialization**: 
   - Start at node 0 with distance 0
   - Set all other nodes' distances to infinity

2. **Iterations**:
   - First Iteration:
     * Relax 0→1: distance to 1 = 1
     * Relax 0→2: distance to 2 = 4
     * Relax 1→2: distance to 2 = -2
     * Relax 1→3: distance to 3 = 7
     * Relax 2→3: distance to 3 = 1

3. **Cycle Check**:
   - No further updates
   - No negative weight cycle detected

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

### Time Complexity
- Best Case: O(E)
- Worst Case: O(V*E)

## Comparative Analysis

| Feature | Dijkstra's Algorithm | Bellman-Ford Algorithm |
|---------|---------------------|------------------------|
| Weight Handling | Positive weights only | Can handle negative weights |
| Negative Cycle Detection | No | Yes |
| Time Complexity | O((E + V) log V) | O(V*E) |
| Use Case | Faster for positive weight graphs | More versatile, handles complex scenarios |

## Conclusion
Both algorithms solve the shortest path problem but have different strengths. Choose based on your specific graph characteristics and performance requirements.
