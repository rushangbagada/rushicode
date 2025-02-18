#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100


typedef struct
{
    int top;
    char items[MAX];
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}


int isFull(Stack *s)
{
    return s->top == MAX - 1;
}


int isEmpty(Stack *s)
{
    return s->top == -1;
}


void push(Stack *s, char value)
{
    if (!isFull(s))
    {
        s->items[++s->top] = value;
    }
}


char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top--];
    }
    return '\0'; 
}


char peek(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top];
    }
    return '\0'; 
}


int precedence(char operator)
{
    switch (operator)
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


int isOperand(char ch)
{
    return isalnum(ch);
}


void infixToPostfix(const char *infix, char *postfix)
{
    Stack s;
    initStack(&s);
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i]; 
        }
        else if (infix[i] == '(')
        {
            push(&s, infix[i]); 
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(&s) && peek(&s) != '(')
            {
                postfix[j++] = pop(&s); 
            }
            pop(&s);
        }
        else
        { // Operator
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&s); 
            }
            push(&s, infix[i]);
        }
    }

    
    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; 
}
int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix); 

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

