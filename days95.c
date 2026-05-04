#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

// Structure to represent a bucket
typedef struct {
    float *elements;
    int count;
    int capacity;
} Bucket;

// Function to insert element in a bucket (keeps sorted)
void insertInBucket(Bucket *bucket, float val) {
    if (bucket->count == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->elements = (float *)realloc(bucket->elements, bucket->capacity * sizeof(float));
    }
    
    // Find correct position and insert (insertion sort within bucket)
    int i = bucket->count - 1;
    while (i >= 0 && bucket->elements[i] > val) {
        bucket->elements[i + 1] = bucket->elements[i];
        i--;
    }
    bucket->elements[i + 1] = val;
    bucket->count++;
}

// Function to perform Bucket Sort
void bucketSort(float arr[], int n) {
    // Create buckets
    Bucket buckets[MAX_BUCKETS];
    for (int i = 0; i < MAX_BUCKETS; i++) {
        buckets[i].elements = (float *)malloc(10 * sizeof(float));
        buckets[i].count = 0;
        buckets[i].capacity = 10;
    }
    
    // Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(MAX_BUCKETS * arr[i]);
        
        // Handle edge case where arr[i] = 1.0
        if (bucketIndex == MAX_BUCKETS) {
            bucketIndex--;
        }
        
        insertInBucket(&buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate all buckets back into original array
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].elements[j];
        }
        free(buckets[i].elements);
    }
}

// Function to print array
void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }
    
    printf("Original Array: ");
    printArray(arr, n);
    
    bucketSort(arr, n);
    
    printf("Sorted Array: ");
    printArray(arr, n);
    
    return 0;
}
