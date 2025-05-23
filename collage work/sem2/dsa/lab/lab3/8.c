#include <stdio.h>
#include "stack.h" // Include the header file

int main()
{
    Stack stack;
    int value;

    // Initialize the stack
    stack_init(&stack);

    // Push elements onto the stack
    stack_push(&stack, 10);
    stack_peek(&stack, &value);
    stack_push(&stack, 20);
    stack_peek(&stack, &value);
    stack_push(&stack, 30);
    stack_peek(&stack, &value);
    printf("Top element: %d\n", value);
    return 0;
}
