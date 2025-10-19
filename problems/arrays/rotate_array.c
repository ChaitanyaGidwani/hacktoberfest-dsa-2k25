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
    int *temp = (int *)malloc(d * sizeof(int));
    if (temp == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    // 1. Store the first 'd' elements in the temp array
    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }

    // 2. Shift the rest of the array's elements to the left
    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];
    }

    // 3. Copy the elements from the temp array to the end of the original array
    for (int i = 0; i < d; i++) {
        arr[n - d + i] = temp[i];
    }
    
    // Free the dynamically allocated memory
    free(temp);
}

// Main function to drive the program
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2; // Number of positions to rotate

    printf("Original array: \n");
    printArray(arr, n);

    // Rotate the array
    rotateLeft(arr, d, n);

    printf("\nArray after left rotation by %d positions: \n", d);
    printArray(arr, n);

    return 0;
}
