#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int freq[26] = {0};  // for 'a' to 'z'

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (freq[index] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        freq[index]++;
    }

    printf("-1");
    return 0;
}