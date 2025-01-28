#include <stdio.h>
#define MAX 5

void push(int stack[], int *top, int value)
{
    if (*top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    (*top)++;
    stack[*top] = value;
}

void pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    (*top)--;
}

void peek(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[*top]);
}

void display(int stack[], int top)
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void isempty(int top)
{
    if (top == -1)
    {
        printf("stack is empty\n");
    }else{
        printf("stack is not empty\n");
    }
}

void isfull(int top)
{
    if (top == MAX -1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("stack is not full\n");
    }
}
int main()
{
    int stack[MAX];
    int top = -1;
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
            peek(stack, &top);
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