#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // int arr[5] = {5, 4, 3, 2, 1};  // Worst Case Array
    int arr[5] = {1, 2, 3, 4, 5};  // Best Case Array
    int n = 5;
    
    // Variables to track operations
    int totalComparisons = 0; 
    int totalSwaps = 0;
    int totalLoopOperations = 0;

    printf("Initial array:\n");
    printArray(arr, n);  // Print the initial array

    for (int i = 0; i < n; i++)
    {
        printf("\nPass %d:\n", i + 1);  // Track the passes of Bubble Sort
        int swapped = 0;  // Track if a swap occurred

        for (int j = 0; j < n - 1 - i; j++)  // Inner loop
        {
            totalLoopOperations++;  // Increment for each inner loop iteration
            
            printf("Comparing %d and %d\n", arr[j], arr[j + 1]);
            totalComparisons++;  // Counting the comparison

            if (arr[j] > arr[j + 1])
            {
                printf("Swapping %d and %d\n", arr[j], arr[j + 1]);
                
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                totalSwaps++;  // Counting the swap
                swapped = 1;   // Set swap flag
            }
        }

        printArray(arr, n);  // Print the array after each pass

        // If no swaps happened, the array is sorted
        if (swapped == 0)
        {
            printf("Array is sorted!\n");
            break;
        }
    }

    // Final output of array
    printf("\nFinal sorted array:\n");
    printArray(arr, n);  // Print the final sorted array

    // Print time complexity and number of operations
    printf("\nTotal Comparisons: %d\n", totalComparisons);
    printf("Total Swaps: %d\n", totalSwaps);
    printf("Total Inner Loop Operations: %d\n", totalLoopOperations);
    printf("Total Operations (Comparisons + Swaps + Loop): %d\n", totalComparisons + totalSwaps + totalLoopOperations);

    return 0;
}
