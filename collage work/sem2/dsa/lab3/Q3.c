// Write a program to implement two stacks using one single array

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct
{
    int arr[MAX];
    int top1; 
    int top2; 
} TwoStacks;


void initStacks(TwoStacks *stacks)
{
    stacks->top1 = -1;  
    stacks->top2 = MAX; 
}


void push1(TwoStacks *stacks, int value)
{
    if (stacks->top1 + 1 == stacks->top2)
    {
        printf("Stack 1 overflow\n");
        return;
    }
    stacks->arr[++stacks->top1] = value;
}


void push2(TwoStacks *stacks, int value)
{
    if (stacks->top2 - 1 == stacks->top1)
    {
        printf("Stack 2 overflow\n");
        return;
    }
    stacks->arr[--stacks->top2] = value;
}


int pop1(TwoStacks *stacks)
{
    if (stacks->top1 == -1)
    {
        printf("Stack 1 underflow\n");
        return -1; 
    }
    return stacks->arr[stacks->top1--];
}


int pop2(TwoStacks *stacks)
{
    if (stacks->top2 == MAX)
    {
        printf("Stack 2 underflow\n");
        return -1;
    }
    return stacks->arr[stacks->top2++];
}
int peek1(TwoStacks *stacks)
{
    if (stacks->top1 == -1)
    {
        printf("Stack 1 is empty\n");
        return -1; 
    }
    return stacks->arr[stacks->top1];
}


int peek2(TwoStacks *stacks)
{
    if (stacks->top2 == MAX)
    {
        printf("Stack 2 is empty\n");
        return -1; 
    }
    return stacks->arr[stacks->top2];
}


int isEmpty1(TwoStacks *stacks)
{
    return stacks->top1 == -1;
}

// Function to check if Stack 2 is empty
int isEmpty2(TwoStacks *stacks)
{
    return stacks->top2 == MAX;
}

// Function to display the contents of both stacks
void displayStacks(TwoStacks *stacks)
{
    printf("Stack 1: ");
    for (int i = 0; i <= stacks->top1; i++)
    {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");

    printf("Stack 2: ");
    for (int i = MAX - 1; i >= stacks->top2; i--)
    {
        printf("%d ", stacks->arr[i]);
    }
    printf("\n");
}

int main()
{
    TwoStacks stacks;
    initStacks(&stacks);

    int choice, value;

    do
    {
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Peek Stack 1\n");
        printf("6. Peek Stack 2\n");
        printf("7. Display Stacks\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push to Stack 1: ");
            scanf("%d", &value);
            push1(&stacks, value);
            break;
        case 2:
            printf("Enter value to push to Stack 2: ");
            scanf("%d", &value);
            push2(&stacks, value);
            break;
        case 3:
            value = pop1(&stacks);
            if (value != -1)
            {
                printf("Popped from Stack 1: %d\n", value);
            }
            break;
        case 4:
            value = pop2(&stacks);
            if (value != -1)
            {
                printf("Popped from Stack 2: %d\n", value);
            }
            break;
        case 5:
            value = peek1(&stacks);
            if (value != -1)
            {
                printf("Top of Stack 1: %d\n", value);
            }
            break;
        case 6:
            value = peek2(&stacks);
            if (value != -1)
            {
                printf("Top of Stack 2: %d\n", value);
            }
            break;
        case 7:
            displayStacks(&stacks);
            break;
        case 8:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 8);

    return 0;
}