#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    // Base case
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal (for checking)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Example usage
int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);

    // Insert new value
    insertIntoBST(root, 5);

    // Print inorder (should be sorted)
    inorder(root);

    return 0;
}