#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        int key = arr[i];       // Element to be inserted
        int j = i - 1;          // Index of previous element
        
        // Move all elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert key at its correct position
        arr[j + 1] = key;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print array state during sorting (for visualization)
void printStep(int arr[], int n, int step) {
    printf("Step %d: ", step);
    printArray(arr, n);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original Array: ");
    printArray(arr, n);
    
    insertionSort(arr, n);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    return 0;
}
