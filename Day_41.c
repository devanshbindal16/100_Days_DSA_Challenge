/*
Problem Statement:
Implement a Queue using a linked list supporting enqueue and dequeue operations.

Input Format:
- First line contains integer N
- Next N lines contain queue operations

Output Format:
- Print dequeued elements
- Print -1 if dequeue is attempted on an empty queue
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// Front and Rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;


// ENQUEUE operation
void enqueue(int value)
{
    // Create new node
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->next = NULL;

    // If queue is empty
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}


// DEQUEUE operation
void dequeue()
{
    // If queue is empty
    if (front == NULL)
    {
        printf("-1\n");
        return;
    }

    // Store front node
    struct Node* temp = front;

    printf("%d\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
        rear = NULL;

    free(temp);
}


int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        int choice;

        scanf("%d", &choice);

        // 1 x → enqueue x
        if (choice == 1)
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }

        // 2 → dequeue
        else if (choice == 2)
        {
            dequeue();
        }
    }

    return 0;
}