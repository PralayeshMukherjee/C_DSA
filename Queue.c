#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int front;
    int rear;
    int size;
    int *arr;
} Queue;
Queue *init(int size)
{
    Queue *q = (Queue *)calloc(sizeof(Queue), 1);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    q->arr = (int *)calloc(sizeof(int), size);
    return q;
}
bool isEmpty(Queue *q)
{
    return q->front == q->rear;
}
bool isFull(Queue *q)
{
    return q->rear == q->size - 1;
}
void enququ(Queue *q, int data)
{
    if (!isFull(q))
    {
        q->arr[++q->rear] = data;
    }
}
int deququ(Queue *q)
{
    if (!isEmpty(q))
    {
        return q->arr[++q->front];
    }
}
void printArray(Queue *q)
{
    for (int i = 1 + q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
}
int main()
{
    Queue *q = init(100);
    enququ(q, 10);
    enququ(q, 20);
    enququ(q, 30);
    enququ(q, 40);
    enququ(q, 50);
    // enququ(q, 60);
    printArray(q);
    printf("\n%d\n", deququ(q));
    enququ(q, 60);
    printArray(q);
}