#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with at least 'mid' distance
int isPossible(int arr[], int n, int k, int mid) {
    int count = 1; // Place first cow in the first stall
    int lastPos = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - lastPos >= mid) {
            count++;
            lastPos = arr[i];
            if (count >= k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. Sort the stall positions
    qsort(arr, n, sizeof(int), compare);

    // 2. Binary search on the distance
    int low = 1;
    int high = arr[n - 1] - arr[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            ans = mid;     // Distance mid is possible, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1; // Distance mid is too large, try smaller
        }
    }

    printf("%d\n", ans);

    return 0;
}