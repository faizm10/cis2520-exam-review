#include "graph.h"

/*
 * A basic menu-based structure
 */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the graph from the file

    Graph *graph = readGraph(argv[1]);
    if (!graph)
    {
        fprintf(stderr, "Error: Could not read the graph from the file.\n");
        return 1;
    }
    // Create the adjacency list for the graph
    createAdjacencyList(graph); // This must be called to populate the adjacency list

    int choice;
    int startVertex;

    do
    {
        // Display the menu
        prompt();

        // Get user input
        printf("Enter a Choice: ");
        if (scanf("%d", &choice) != 1)
        {
            fprintf(stderr, "Invalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ; // Clear the input buffer
            continue;
        }

        // Handle menu options
        switch (choice)
        {
        case 1: // Display Adjacency List
            displayAdjacencyList(graph);
            break;

        case 2: // Perform Breadth-First Search (BFS)
            bfs(graph, 0);
            break;

        case 3: // Perform Depth-First Search (DFS)
            dfs(graph, 0);
            break;

        case 4: // Find Shortest Path using Dijkstra's Algorithm

            dijkstra(graph, 0);
            break;

        case 5: // Exit
            printf("Exiting the program.\n");
            freeGraph(graph);
            return 0;

        default: // Invalid option
            fprintf(stderr, "Invalid choice. Please select a valid option.\n");
            break;
        }
    } while (true);

    // Free the graph memory before exiting
    freeGraph(graph);
    return 0;
}
