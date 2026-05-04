#include <stdio.h>
#include <stdlib.h>

// Function to merge and count inversions
long long mergeAndCount(int arr[], int left, int mid, int right) {
    int i = left;           // Starting index of left subarray
    int j = mid + 1;        // Starting index of right subarray
    int k = 0;              // Index for temporary array
    long long invCount = 0; // Count of inversions
    
    // Create temporary array to store merged elements
    int temp[right - left + 1];
    
    // Compare elements from both subarrays and merge
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If element from right subarray is smaller,
            // it forms inversions with all remaining elements in left subarray
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
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
    
    return invCount;
}

// Function to count inversions using merge sort
long long mergeSortAndCount(int arr[], int left, int right) {
    long long invCount = 0;
    
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Count inversions in left half
        invCount += mergeSortAndCount(arr, left, mid);
        
        // Count inversions in right half
        invCount += mergeSortAndCount(arr, mid + 1, right);
        
        // Count split inversions (between left and right halves)
        invCount += mergeAndCount(arr, left, mid, right);
    }
    
    return invCount;
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
    int arrCopy[n];  // To preserve original array for display
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arrCopy[i] = arr[i];
    }
    
    printf("Original Array: ");
    printArray(arrCopy, n);
    
    long long inversionCount = mergeSortAndCount(arr, 0, n - 1);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    printf("Number of Inversions: %lld\n", inversionCount);
    
    return 0;
}
