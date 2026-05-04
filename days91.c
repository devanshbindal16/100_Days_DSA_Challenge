#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int i = left;       // Starting index of left subarray
    int j = mid + 1;    // Starting index of right subarray
    int k = 0;          // Index for temporary array
    
    // Create temporary array to store merged elements
    int temp[right - left + 1];
    
    // Compare elements from both subarrays and merge
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    // Copy remaining elements from left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    // Copy sorted elements back to original array
    for (int i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Divide and sort function (recursive)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find middle point
        
        // Sort left half
        mergeSort(arr, left, mid);
        
        // Sort right half
        mergeSort(arr, mid + 1, right);
        
        // Merge sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
    
    mergeSort(arr, 0, n - 1);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    return 0;
}
