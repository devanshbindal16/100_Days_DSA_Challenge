#include<stdio.h>

int intgerSquareRoot(int n){
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long square = (long long)mid * mid;

        if (square == n) {
            return mid; // Found exact square root
        } else if (square < n) {
            ans = mid; // Update answer and search in the right half
            low = mid + 1;
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return ans; // Return the integer square root
    
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = intgerSquareRoot(n);
    printf("The integer square root of %d is %d\n", n, result);

    return 0;
}