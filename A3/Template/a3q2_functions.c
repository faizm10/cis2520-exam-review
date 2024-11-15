/*
Name: Faiz Mustansar
Student ID: 1261489
Assignment: A3
Date: Nov 15, 2024
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"

/*
 * The downHeap function performs the downheap algorithm.
 * The key at the passed position is swapped with the key of it's child with the smallest value.
 * If the key is smaller, than both of it's children's keys then no swap happens.
 * After swap, the downHeap is called again to the new position of the swapped key and it terminates when it's value is smaller than both children.
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "a3q2_header.h"

void downHeap(int key[20], int pos, int array[20][10]) {
    int largest = pos;
    int leftChild = 2 * pos + 1;
    int rightChild = 2 * pos + 2;

    // Check if left child exists and is greater than root
    if (leftChild < 20 && key[leftChild] > key[largest])
        largest = leftChild;

    // Check if right child exists and is greater than largest
    if (rightChild < 20 && key[rightChild] > key[largest])
        largest = rightChild;

    // If largest is not root
    if (largest != pos) {
        swap(pos, largest, key, array);
        downHeap(key, largest, array); // Recursively heapify the affected subtree
    }
}

bool isParent(int keyPos) {
    return (2 * keyPos + 1 < 20); // Check if it has at least one child
}

void swap(int key1Pos, int key2Pos, int key[20], int array[20][10]) {
    // Swap keys
    int tempKey = key[key1Pos];
    key[key1Pos] = key[key2Pos];
    key[key2Pos] = tempKey;

    // Swap rows in the 2D array
    int tempRow[10];
    for (int i = 0; i < 10; i++) {
        tempRow[i] = array[key1Pos][i];
        array[key1Pos][i] = array[key2Pos][i];
        array[key2Pos][i] = tempRow[i];
    }
}
