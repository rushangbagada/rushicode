// Write a program to implement stack using an array in descending order of index to
//perform the array push operation and accordingly all the remaining operations.
//
#include <stdio.h>
#define MAX 5

void push(int stack[], int *top, int value)
{
    if (*top == -1)
    {
        printf("Stack overflow\n");
        return;
    }
    stack[*top] = value;
    (*top)--; // Move the top down
}

void pop(int stack[], int *top)
{
    if (*top == MAX - 1)
    {
        printf("Stack underflow\n");
        return;
    }
    (*top)++; // Move the top up
}

void peek(int stack[], int top)
{
    if (top == MAX - 1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top + 1]);
}

void display(int stack[], int top)
{
    if (top == MAX - 1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = top + 1; i < MAX; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void isempty(int top)
{
    if (top == MAX - 1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}

void isfull(int top)
{
    if (top == -1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Stack is not full\n");
    }
}

int main()
{
    int stack[MAX];
    int top = MAX - 1; // Initialize top to the last index
    int choice;
    int value;

    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. isempty\n");
        printf("5. isfull\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(stack, &top, value);
            break;
        case 2:
            pop(stack, &top);
            break;
        case 3:
            peek(stack, top);
            break;
        case 4:
            isempty(top);
            break;
        case 5:
            isfull(top);
            break;
        case 6:
            display(stack, top);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 7);

    return 0;
}