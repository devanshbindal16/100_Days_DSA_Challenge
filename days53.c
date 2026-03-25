#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Queue structure
struct Pair {
    struct Node* node;
    int hd;
};

struct Pair queue[MAX];
int front = 0, rear = 0;

// Enqueue
void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

// Dequeue
struct Pair dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front == rear;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* q[MAX];
    int f = 0, r = 0;

    q[r++] = root;
    int i = 1;

    while (f < r && i < n) {
        struct Node* curr = q[f++];

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;

        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }

    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    int columns[2 * MAX][MAX]; // store values
    int colSize[2 * MAX] = {0};

    int offset = MAX; // to handle negative hd

    enqueue(root, 0);

    while (!isEmpty()) {
        struct Pair temp = dequeue();

        struct Node* node = temp.node;
        int hd = temp.hd;

        int index = hd + offset;

        columns[index][colSize[index]++] = node->data;

        if (node->left)
            enqueue(node->left, hd - 1);

        if (node->right)
            enqueue(node->right, hd + 1);
    }

    // Print result
    for (int i = 0; i < 2 * MAX; i++) {
        if (colSize[i] > 0) {
            for (int j = 0; j < colSize[i]; j++) {
                printf("%d ", columns[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}