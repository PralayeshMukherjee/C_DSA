#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node *createNode(int data)
{
    Node *newNode = (Node *)calloc(sizeof(Node), 1);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void addNode(Node **root, int data)
{
    Node *newNode = createNode(data);
    if (*root == NULL)
    {
        *root = newNode;
        return;
    }
    Node *current = *root;
    Node *parent = NULL;
    while (current != NULL)
    {
        parent = current;
        if (current->data > data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (parent->data > data)
    {
        parent->left = newNode;
    }
    else
    {
        parent->right = newNode;
    }
}
void inorder(Node *root)
{
    if (root == NULL)
        return;
    // if (root->left != NULL)
    inorder(root->left);
    printf("%d -> ", root->data);
    // if (root->right != NULL)
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    preorder(root->right);
    printf("%d -> ", root->data);
}
int main()
{
    Node *root = NULL;
    addNode(&root, 50);
    addNode(&root, 30);
    addNode(&root, 60);
    addNode(&root, 20);
    addNode(&root, 40);
    addNode(&root, 55);
    addNode(&root, 70);
    inorder(root);
    printf("NULL\n");
    preorder(root);
    printf("NULL\n");
    postorder(root);
    printf("NULL\n");
}