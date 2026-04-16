#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Simple hashmap using arrays (for teaching purpose)
int findMaxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Hashmap (sum -> index)
    int hash[2 * MAX + 1];
    
    // Initialize hashmap with -2 (means not visited)
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -2;
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // If sum is 0 → from index 0 to i
        if (sum == 0) {
            maxLen = i + 1;
        }

        // Shift index to handle negative sums
        int index = sum + MAX;

        if (hash[index] != -2) {
            int prevIndex = hash[index];
            if (i - prevIndex > maxLen) {
                maxLen = i - prevIndex;
            }
        } else {
            hash[index] = i; // store first occurrence
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", findMaxLen(arr, n));

    return 0;
}