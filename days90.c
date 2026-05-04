#include <stdio.h>

// Function to check if we can paint all boards with k painters in given time
int canPaint(int boards[], int n, int k, long long time) {
    int painters = 1;
    long long currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        if (boards[i] > time) {
            return 0; // Single board takes more time than available
        }
        
        if (currentTime + boards[i] <= time) {
            currentTime += boards[i];
        } else {
            // Need a new painter
            painters++;
            currentTime = boards[i];
            
            if (painters > k) {
                return 0; // Need more painters than available
            }
        }
    }
    
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int boards[n];
    long long maxBoard = 0, totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        maxBoard = (boards[i] > maxBoard) ? boards[i] : maxBoard;
        totalSum += boards[i];
    }
    
    // Binary search on the answer
    long long left = maxBoard;
    long long right = totalSum;
    long long answer = totalSum;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canPaint(boards, n, k, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    printf("%lld\n", answer);
    
    return 0;
}
