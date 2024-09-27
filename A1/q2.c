#include <stdio.h>

int main() {
    int A[5] = {1, 3, 7, 4, 0};
    int *P[5], *pA;
    int i, x, y;
    
    // Set pointer to the base address of the array
    pA = &A[0];  // Corrected initialization

    // Assign A[1] to x using pA and A[2] to y
    x = *(pA + 1);  // Corrected to get A[1]
    pA++;
    y = *pA;  // pA now points to A[1], so this gets A[1]

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    // Set every pointer to one array element
    for (i = 0; i < 5; i++) {
        P[i] = &A[i];  // Store address of A[i] in P[i]
    }

    // Print array elements using pointers
    for (i = 0; i < 5; i++) {
        printf("%d\t", *P[i]);  // Dereference P[i] to print the value
    }
    
    return 0;
}
