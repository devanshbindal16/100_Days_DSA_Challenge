#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }

    // Table full (optional handling)
}

int search(int table[], int m, int key) {
    int h = hash(key, m);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY)
            return 0; // not found

        if (table[idx] == key)
            return 1; // found
    }

    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);   // table size
    scanf("%d", &q);   // number of operations

    int table[m];

    // initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(table, m, key);
        } 
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}