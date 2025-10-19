#include <stdio.h>
#include <stdlib.h> // For malloc and free

/**
 * @brief Prints the elements of an integer array.
 * @param arr The array to be printed.
 * @param size The number of elements in the array.
 */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * @brief Rotates an array to the left by 'd' positions.
 * This function uses a temporary array to store the rotated elements
 * and then copies them back to the original array.
 * @param arr The array to rotate.
 * @param d The number of positions to rotate left.
 * @param n The size of the array.
 */
void rotateLeft(int arr[], int d, int n) {
    // Handle cases where d is larger than n
    d = d % n;
    
    // If d is 0, no rotation is needed
    if (d == 0) {
        return;
    }

    // Create a temporary array to store the first 'd' elements
    int *temp = (
