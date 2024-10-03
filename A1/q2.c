#include <stdio.h>

int main() {
    int A[5] = {1, 3, 7, 4, 0};
    int *P[5], *pA;
    int i, x, y;
    
    // Set pointer pA to the base address of the array A
    pA = &A[0];  

    // Assign the value of A[1] (second element of A) to x using pointer arithmetic
    x = *(pA + 1);  // This accesses A[1], which is 3

    // Assign the value of A[1] again to y 
    y = *(pA + 1);  // This also accesses A[1], which is still 3

    // Print the values of x and y
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    // Loop through the array A and store the address of each element in the array of pointers P
    for (i = 0; i < 5; i++) {
        P[i] = &A[i];  // Store the address of A[i] in P[i]
    }

    // Print each element of array A using the pointer array P
    for (i = 0; i < 5; i++) {
        printf("%d\t", *P[i]);  // Dereference each pointer in P to access and print the corresponding value in A
    }
    
    return 0;
}
