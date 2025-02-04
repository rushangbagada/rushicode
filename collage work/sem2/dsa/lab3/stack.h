
#include <stdbool.h> // For boolean type
#include <stdio.h>
// Define the maximum size of the stack
#define STACK_MAX_SIZE 100

// Define the stack structure
typedef struct
{
    int data[STACK_MAX_SIZE]; // Array to hold stack elements
    int top;                  // Index of the top element
} Stack;



// Function to initialize the stack
void stack_init(Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
int stack_is_empty(const Stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int stack_is_full(const Stack *stack)
{
    return stack->top == STACK_MAX_SIZE - 1;
}

// Function to push an element onto the stack
int stack_push(Stack *stack, int value)
{
    if (stack_is_full(stack))
    {
        return false; // Stack is full, push operation fails
    }

    return stack->data[++(stack->top)] = value;
}

// Function to pop an element from the stack
int stack_pop(Stack *stack, int *value)
{
    if (stack_is_empty(stack))
    {
        return false; // Stack is empty, pop operation fails
    }

    return *value = stack->data[(stack->top)--];
}

// Function to get the top element of the stack without removing it
int stack_peek(const Stack *stack, int *value)
{
    if (stack_is_empty(stack))
    {
        return false; // Stack is empty, peek operation fails
    }

    return *value = stack->data[stack->top];
}

