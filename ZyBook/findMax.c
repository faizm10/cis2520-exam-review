#include <stdio.h>
//  gcc findMax.c -o findMax
// ./findMax

int FindMax(int inputArray[], int size) {
    int max = inputArray[0]; // Initialize max with the first element

    for (int i = 1; i < size; ++i) { // Start from the second element
        if (inputArray[i] > max) {
            max = inputArray[i]; // Update max if current element is larger
        }
    }

    return max; // Return the maximum value
}

int main() {
    int inputArray[] = {1, 2, 3, 4, 5};
    int size = sizeof(inputArray) / sizeof(inputArray[0]);
    
    int max = FindMax(inputArray, size);
    printf("The maximum value is: %d\n", max);

    return 0;
}
