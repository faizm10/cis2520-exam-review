#include <stdio.h>
#include <string.h>

// Define a structure for Salesperson
struct Salesperson {
    char name[50];
    int salesTotal;
};

// Function to display the top five salespersons
void DisplayTopFiveSalespersons(struct Salesperson allSalespersons[], int numSalespersons) {
    // Create an array to store the top 5 salespersons
    struct Salesperson topSales[5];

    // Initialize the topSales array with default values
    for (int i = 0; i < 5; ++i) {
        strcpy(topSales[i].name, ""); // Set name to empty string
        topSales[i].salesTotal = -1; // Set sales total to a negative value
    }

    // Function to sort topSales in descending order based on salesTotal
    void SortDescending(struct Salesperson arr[], int length) {
        struct Salesperson temp;
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (arr[i].salesTotal < arr[j].salesTotal) {
                    // Swap the elements
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    // Loop through each salesperson in the list
    for (int i = 0; i < numSalespersons; ++i) {
        // If the current salesperson has more sales than the last one in topSales
        if (allSalespersons[i].salesTotal > topSales[4].salesTotal) {
            // Replace the last element with the current salesperson
            strcpy(topSales[4].name, allSalespersons[i].name);
            topSales[4].salesTotal = allSalespersons[i].salesTotal;

            // Sort the topSales array in descending order by salesTotal
            SortDescending(topSales, 5);
        }
    }

    // Display the top five salespersons
    printf("Top 5 Salespersons:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%s: %d\n", topSales[i].name, topSales[i].salesTotal);
    }
}

int main() {
    // Example usage
    struct Salesperson allSalespersons[] = {
        {"Alice", 300},
        {"Bob", 250},
        {"Charlie", 500},
        {"David", 450},
        {"Eve", 100},
        {"Frank", 550},
        {"Grace", 200}
    };
    
    int numSalespersons = sizeof(allSalespersons) / sizeof(allSalespersons[0]);

    DisplayTopFiveSalespersons(allSalespersons, numSalespersons);

    return 0;
}
