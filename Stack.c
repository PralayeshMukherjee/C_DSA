#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int top;
    int size;
    int *arr;
} Stack;

Stack *init(int size)
{
    Stack *S = (Stack *)calloc(sizeof(Stack), 1);
    S->top = -1;
    S->size = size;
    S->arr = (int *)calloc(sizeof(int), size);
    return S;
}
void push(Stack *S, int element)
{
    S->arr[++S->top] = element;
}
int pop(Stack *S)
{
    return S->arr[S->top--];
}
int peek(Stack *S)
{
    return S->arr[S->top];
}
bool isEmpty(Stack *S)
{
    return S->top == -1;
}
bool isFull(Stack *S)
{
    return S->top == S->size - 1;
}
void printStack(Stack *S)
{
    while (S->top != -1)
    {
        printf("%d ", S->arr[S->top--]);
    }
    printf("\n");
}
int main()
{
    Stack *S;
    int size;
    printf("Enter the size of the stack\n");
    scanf("%d", &size);
    S = init(size);
    int operation = 1;
    while (operation != 0)
    {
        printf("Enter the operation: \n");
        printf("Enter 1 for push\n");
        printf("Enter 2 for pop\n");
        printf("Enter 3 for peek\n");
        printf("Enter 0 for exit\n");
        scanf("%d", &operation);

        switch (operation)
        {
        case 1:
            if (isFull(S) == false)
            {
                int n;
                printf("Enter the element in the stack:\n");
                scanf("%d", &n);
                push(S, n);
            }
            else
            {
                printf("Stack is full\n");
            }
            break;
        case 2:
            if (isEmpty(S) == false)
            {
                printf("Pop out element is %d\n", pop(S));
            }
            else
            {
                printf("The stack is Empty\n");
            }
            break;
        case 3:
            printf("The peek element of the Stack is %d\n", peek(S));
            break;
        default:
            printf("invalid element given\n");
        }
    }
    printStack(S);
}