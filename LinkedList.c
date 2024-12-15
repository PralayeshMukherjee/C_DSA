#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int n)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->data = n;
    (*newNode).next = NULL;
    return newNode;
}
void addFirst(Node **head, int n)
{
    Node *newNode = createNode(n);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}
void addLast(Node **head, int n)
{
    Node *newNode = createNode(n);
    Node *parent = NULL;
    Node *current = *head;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (current != NULL)
    {
        parent = current;
        current = current->next;
    }
    parent->next = newNode;
}
void addMid(Node **head, int n, int index)
{
    Node *newNode = createNode(n);
    Node *current = *head;
    Node *parent = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    int count = 0;
    while (count != n)
    {
        parent = current;
        current = (*current).next;
        count++;
    }
    parent->next = newNode;
    newNode->next = current;
}
int deleteNode(Node **head, int index)
{
    Node *current = *head;
    Node *parent = NULL;
    // int count = 0;
    while (current->data != index)
    {
        parent = current;
        current = current->next;
        // count++;
    }
    if (parent == NULL)
    {
        *head = current->next;
        current->next = NULL;
        return current->data;
    }
    else if (current->next == NULL)
    {
        parent->next = NULL;
        return current->data;
    }
    else
    {
        parent->next = current->next;
        current->next = NULL;
        return current->data;
    }
}
void printLL(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
int main()
{
    Node *head = NULL;
    int opperation = 1;
    while (opperation != 0)
    {
        printf("Enter 1 for add Node in first\n");
        printf("Enter 2 for add Node in last\n");
        printf("Enter 3 for add Node in mid\n");
        printf("Enter 0 for print Node\n");
        printf("Enter 4 for delete Node\n");
        printf("Enter 5 for print the linked list\n");
        scanf("%d", &opperation);
        int n, index;
        switch (opperation)
        {
        case 1:
            printf("Enter the data you want to insert:- \n");
            scanf("%d", &n);
            addFirst(&head, n);
            break;
        case 2:
            printf("Enter the data you want to insert:- \n");
            // int n;
            scanf("%d", &n);
            addLast(&head, n);
            break;
        case 3:
            printf("Enter the data you want to insert:- \n");
            // int n;
            scanf("%d", &n);
            printf("Enter in which index you want to insert in the Linked List: \n");
            // int index;
            scanf("%d", &index);
            addMid(&head, n, index);
            break;
        case 4:
            printf("Enter data you want to delete in the Linked List: \n");
            // int index;
            scanf("%d", &index);
            int data = deleteNode(&head, index);
            printf("deleteing node value is %d", data);
            break;
        case 5:
            printLL(head);
            break;
        case 0:
            printf("Exit the loop\n");
            break;
        default:
            printf("Invalid input given\n");
            break;
        }
    }
}