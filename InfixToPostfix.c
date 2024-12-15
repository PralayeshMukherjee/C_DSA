#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct Stack
{
    int top;
    char arr[MAX];
} Stack;

void push(Stack *stack, char c)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = c;
}

char pop(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->arr[stack->top--];
}

char peek(Stack *stack)
{
    if (stack->top == -1)
    {
        return '\0';
    }
    return stack->arr[stack->top];
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixToPostfix(char *infix, char *postfix)
{
    Stack stack;
    stack.top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char token = infix[i];

        if (isalnum(token))
        {
            postfix[j++] = token; // Add operand to postfix
        }
        else if (token == '(')
        {
            push(&stack, token);
        }
        else if (token == ')')
        {
            while (peek(&stack) != '(' && stack.top != -1)
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '('
        }
        else if (isOperator(token))
        {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(token))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, token);
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (stack.top != -1)
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
