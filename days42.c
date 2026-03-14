/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10
*/

#include <stdio.h>
#define MAX 1000

/* Queue implementation */
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

/* Stack implementation */
typedef struct {
    int arr[MAX];
    int top;
} Stack;

/* Queue functions */
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int x) {
    q->arr[++(q->rear)] = x;
}

int dequeue(Queue *q) {
    return q->arr[(q->front)++];
}

/* Stack functions */
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int x) {
    s->arr[++(s->top)] = x;
}

int pop(Stack *s) {
    return s->arr[(s->top)--];
}

int main() {
    int n, x;
    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    scanf("%d", &n);

    /* Input queue elements */
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    /* Move queue elements to stack */
    while(!isQueueEmpty(&q)) {
        push(&s, dequeue(&q));
    }

    /* Move stack elements back to queue */
    while(!isStackEmpty(&s)) {
        enqueue(&q, pop(&s));
    }

    /* Print reversed queue */
    while(!isQueueEmpty(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}