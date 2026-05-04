#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
typedef struct {
    int start;
    int end;
} Interval;

// Comparator function for qsort (sort by start time)
int compareIntervals(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;
    return x->start - y->start;
}

// Function to merge overlapping intervals
Interval *mergeIntervals(Interval intervals[], int n, int *mergedCount) {
    // Sort intervals by start time
    qsort(intervals, n, sizeof(Interval), compareIntervals);
    
    // Create result array
    Interval *merged = (Interval *)malloc(n * sizeof(Interval));
    *mergedCount = 0;
    
    // Start with first interval
    merged[0] = intervals[0];
    *mergedCount = 1;
    
    // Iterate through remaining intervals
    for (int i = 1; i < n; i++) {
        // Get last merged interval
        Interval *lastInterval = &merged[*mergedCount - 1];
        
        // Check if current interval overlaps with last merged interval
        if (intervals[i].start <= lastInterval->end) {
            // Merge by extending end time
            lastInterval->end = (intervals[i].end > lastInterval->end) 
                                ? intervals[i].end 
                                : lastInterval->end;
        } else {
            // No overlap, add current interval to result
            merged[*mergedCount] = intervals[i];
            (*mergedCount)++;
        }
    }
    
    return merged;
}

// Function to print intervals
void printIntervals(Interval intervals[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("[%d,%d]", intervals[i].start, intervals[i].end);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    
    Interval intervals[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }
    
    printf("Original Intervals: ");
    printIntervals(intervals, n);
    
    int mergedCount;
    Interval *merged = mergeIntervals(intervals, n, &mergedCount);
    
    printf("Merged Intervals: ");
    printIntervals(merged, mergedCount);
    
    free(merged);
    return 0;
}
