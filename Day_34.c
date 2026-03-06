// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main() {

    char postfix[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);

    while (postfix[i] != '\0') {

        if (postfix[i] == ' ' || postfix[i] == '\n') {
            i++;
            continue;
        }

        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        else {
            int b = pop();
            int a = pop();

            switch (postfix[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}