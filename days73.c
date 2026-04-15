#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int freq[26] = {0};

    // Step 1: Count frequency
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Step 2: Find first non-repeating
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$'; // If all repeat
}

int main() {
    char s[1000];
    scanf("%s", s);

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}