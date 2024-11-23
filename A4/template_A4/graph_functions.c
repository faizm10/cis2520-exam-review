#include "graph.h"

/* function will display the primary user interface
    This is already done for you*/
void prompt(void)
{

    printf("\nMenu:\n");
    printf("1. Display Adjacency List\n");
    printf("2. Perform Breadth-First Search (BFS)\n");
    printf("3. Perform Depth-First Search (DFS)\n");
    printf("4. Find Shortest Path using Dijkstra's Algorithm\n");
    printf("5. Exit\n");
}

/**
 * Reads a graph from a file and constructs the graph structure.
 * @param filename The name of the file containing the adjacency matrix.
 * @return Pointer to the created Graph structure, or NULL if an error occurs.
 */
Graph *readGraph(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    Graph *graph = malloc(sizeof(Graph));
    if (!graph)
    {
        fprintf(stderr, "Error: Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Initialize adjacency list pointers
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        graph->adjList[i] = NULL;
    }

    int numVertices = 0;

    // Read the adjacency matrix
    char line[1024];
    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " ");
        int col = 0;
        while (token)
        {
            graph->adjMatrix[numVertices][col] = atoi(token);
            token = strtok(NULL, " ");
            col++;
        }
        numVertices++;
    }

    graph->numVertices = numVertices;
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }

    fclose(file);

    return graph;
}

/**
 * Creates a new node for the adjacency list.
 * @param vertex The vertex number that this node will represent.
 * @return Pointer to the newly created Node structure.
 */
Node *createNode(int vertex)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

/**
 * Displays the adjacency list of the graph.
 * @param graph Pointer to the Graph structure.
 */
#include "graph.h"

/**
 * Displays the adjacency list of the graph.
 * @param graph Pointer to the Graph structure.
 */
void displayAdjacencyList(Graph *graph)
{
    if (!graph)
    {
        fprintf(stderr, "Error: Graph is NULL.\n");
        return;
    }

    printf("Adjacency List Representation:\n");

    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %d:", i + 1);

        Node *current = graph->adjList[i];
        while (current)
        {
            if (current->next)
            {
                printf(" -> %d (%d)", current->vertex + 1, graph->adjMatrix[i][current->vertex]);
            }
            else
            {
                printf(" -> %d (%d) NULL", current->vertex + 1, graph->adjMatrix[i][current->vertex]);
            }
            current = current->next;
        }

        if (!graph->adjList[i])
        {
            printf(" NULL");
        }

        printf("\n");
    }
}

/**
 * Converts the adjacency matrix of the graph to an adjacency list.
 * @param graph Pointer to the Graph structure.
 */
void createAdjacencyList(Graph *graph)
{
    if (!graph)
    {
        fprintf(stderr, "Error: Graph is NULL.\n");
        return;
    }

    // Clear existing adjacency list
    for (int i = 0; i < graph->numVertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    // Build adjacency list from adjacency matrix
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            // Check if there is an edge with a non-zero weight
            if (graph->adjMatrix[i][j] != 0)
            {
                Node *newNode = createNode(j);

                // Insert into adjacency list in sorted order
                if (!graph->adjList[i] || graph->adjList[i]->vertex > newNode->vertex)
                {
                    newNode->next = graph->adjList[i];
                    graph->adjList[i] = newNode;
                }
                else
                {
                    Node *current = graph->adjList[i];
                    while (current->next && current->next->vertex < newNode->vertex)
                    {
                        current = current->next;
                    }
                    newNode->next = current->next;
                    current->next = newNode;
                }
            }
        }
    }
}

/**
 * Performs Breadth-First Search (BFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which BFS starts (0-based index).
 */
void bfs(Graph *graph, int startVertex)
{
    if (!graph)
    {
        fprintf(stderr, "Error: Graph is NULL.\n");
        return;
    }

    bool discovered[MAX_VERTICES] = {false}; // Tracks discovered vertices
    int queue[MAX_VERTICES];                 // Queue for BFS
    int front = 0, rear = 0;                 // Queue pointers

    queue[rear++] = startVertex; // Enqueue startVertex
    discovered[startVertex] = true;

    printf("BFS Order: ");

    while (front < rear) // While queue is not empty
    {
        int currentVertex = queue[front++]; // Dequeue front element
        printf("%d ", currentVertex + 1);   // Process the current vertex (1-based index)

        // Explore each adjacent vertex of the current vertex
        Node *neighbor = graph->adjList[currentVertex];
        while (neighbor)
        {
            if (!discovered[neighbor->vertex])
            {
                // Enqueue undiscovered neighbor and mark it as discovered
                queue[rear++] = neighbor->vertex;
                discovered[neighbor->vertex] = true;
            }
            neighbor = neighbor->next; // Move to the next neighbor
        }
    }
    printf("\n");
}
/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which DFS starts (0-based index).
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which DFS starts (0-based index).
 */
void dfs(Graph *graph, int startVertex)
{
    if (!graph)
    {
        fprintf(stderr, "Error: Graph is NULL.\n");
        return;
    }

    bool visited[MAX_VERTICES] = {false}; // Tracks visited vertices
    int stack[MAX_VERTICES];              // Stack for DFS
    int top = -1;                         // Stack pointer

    // Initialize the stack with the starting vertex
    stack[++top] = startVertex;

    printf("DFS Order: ");

    while (top >= 0) // While stack is not empty
    {
        int currentVertex = stack[top--]; // Pop from the stack

        if (!visited[currentVertex]) // Process unvisited vertex
        {
            printf("%d ", currentVertex + 1); // Print vertex (1-based index)
            visited[currentVertex] = true;    // Mark as visited

            // Push all unvisited neighbors onto the stack in reverse order
            Node *neighbor = graph->adjList[currentVertex];
            int tempStack[MAX_VERTICES]; // Temporary stack to reverse order
            int tempTop = -1;

            while (neighbor)
            {
                if (!visited[neighbor->vertex])
                {
                    tempStack[++tempTop] = neighbor->vertex;
                }
                neighbor = neighbor->next; // Move to next neighbor
            }

            // Push neighbors from temporary stack back to the main stack
            while (tempTop >= 0)
            {
                stack[++top] = tempStack[tempTop--];
            }
        }
    }
    printf("\n");
}

/**
 * Finds the shortest path from the start vertex to all other vertices using Dijkstra's algorithm.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which to start the algorithm (0-based index).
 */
#include <limits.h>  // For INT_MAX
#include <stdbool.h> // For boolean types

/**
 * Finds the shortest path from the start vertex to all other vertices using Dijkstra's algorithm.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which to start the algorithm (0-based index).
 */
void dijkstra(Graph *graph, int startVertex)
{
    if (!graph)
    {
        fprintf(stderr, "Error: Graph is NULL.\n");
        return;
    }

    int numVertices = graph->numVertices;
    int distance[MAX_VERTICES]; // Shortest distance from startVertex to each vertex
    bool visited[MAX_VERTICES]; // Visited vertices
    int previous[MAX_VERTICES]; // Previous vertex in the shortest path

    // Initialize all distances as infinite and visited as false
    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = INT_MAX; // Set initial distances to "infinity"
        visited[i] = false;    // Mark all vertices as unvisited
        previous[i] = -1;      // No previous vertex for any node initially
    }

    // Distance to the source vertex is 0
    distance[startVertex] = 0;

    // Dijkstra's algorithm
    for (int i = 0; i < numVertices; i++)
    {
        // Find the vertex with the smallest distance that hasn't been visited
        int minDistance = INT_MAX;
        int u = -1; // Index of vertex with the smallest distance
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && distance[v] < minDistance)
            {
                minDistance = distance[v];
                u = v;
            }
        }

        // If no vertex was found, break (remaining vertices are unreachable)
        if (u == -1)
            break;

        // Mark the chosen vertex as visited
        visited[u] = true;

        // Update distances to the neighbors of the current vertex
        Node *neighbor = graph->adjList[u];
        while (neighbor)
        {
            int v = neighbor->vertex;            // Neighbor vertex
            int weight = graph->adjMatrix[u][v]; // Weight of the edge (u, v)

            // Alternative path distance
            int alt = distance[u] + weight;
            if (alt < distance[v])
            {
                distance[v] = alt;
                previous[v] = u; // Update the path
            }

            neighbor = neighbor->next; // Move to the next neighbor
        }
    }

    // Print the results
    printf("Shortest distances from vertex %d:\n", startVertex + 1);
    for (int i = 0; i < numVertices; i++)
    {
        if (distance[i] == INT_MAX)
        {
            printf("Vertex %d: Unreachable\n", i + 1);
        }
        else
        {
            printf("Vertex %d: %d\n", i + 1, distance[i]);
        }
    }
}

/**
 * Frees the memory allocated for the graph, including the adjacency list.
 * @param graph Pointer to the Graph structure to be freed.
 */
void freeGraph(Graph *graph)
{
    if (!graph)
        return;

    // Free adjacency list
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->adjList[i];
        while (current)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    // Free graph structure
    free(graph);
}
