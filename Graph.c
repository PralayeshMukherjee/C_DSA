#include <stdio.h>
#include <stdlib.h>

int **init(int n)
{
    int **arr = (int **)calloc(sizeof(int *), n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)calloc(sizeof(int), n);
    }
    return arr;
}
void printArray(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int *bfs(int **arr, int start, int n)
{
    int k = 0, temp;
    int queue[100];
    int rear = -1, front = -1;
    int *visitedArray;
    int *result;
    visitedArray = (int *)calloc(sizeof(int), n);
    result = (int *)calloc(sizeof(int), n);
    queue[++rear] = start;
    visitedArray[start] = 1;

    while (front != rear)
    {
        temp = queue[++front];
        result[k++] = temp;
        for (int j = 0; j < n; j++)
        {
            if (arr[temp][j] != 0)
            {
                if (visitedArray[j] == 0)
                {
                    visitedArray[j] = 1;
                    queue[++rear] = j;
                }
            }
        }
    }
    return result;
}
int *dfs(int **arr, int start, int n)
{
    int stack[100];
    int top = -1;
    int temp, k = 0;
    int *visitedArray;
    int *result;
    visitedArray = (int *)calloc(sizeof(int), n);
    result = (int *)calloc(sizeof(int), n);
    visitedArray[start] = 1;
    stack[++top] = start;
    while (top != -1)
    {
        temp = stack[top--];
        result[k++] = temp;
        for (int i = 0; i < n; i++)
        {
            if (arr[temp][i] == 1)
            {
                if (visitedArray[i] == 0)
                {
                    visitedArray[i] = 1;
                    stack[++top] = i;
                }
            }
        }
    }
    return result;
}
int main()
{
    printf("Enter the number of nodes you want to insert\n");
    int n;
    scanf("%d", &n);
    int **arr;
    arr = init(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i != j)
            {
                printf("is their any node between %d and %d\n", i, j);
                printf("Enter 1 for yes\nEnter 0 for no\n");
                int isEdge;
                scanf("%d", &isEdge);
                arr[i][j] = isEdge;
                arr[j][i] = isEdge;
            }
        }
    }
    printArray(arr, n);
    printf("\nEnter the starting node:-\n");
    int start;
    scanf("%d", &start);
    int *bfsTraversal = bfs(arr, start, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", bfsTraversal[i]);
    }
    printf("\n");
    int *dfsTraversal = dfs(arr, start, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dfsTraversal[i]);
    }
}

// 7 1 0 1 0 0 1 0 0 0 1 0 0 0 1 1 1 0 1 1 0 0 0 0