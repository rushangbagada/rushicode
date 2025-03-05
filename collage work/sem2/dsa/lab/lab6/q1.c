//. Write a program to implement stack using linked list. Perform necessary operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;            
  

int isEmpty()
{
    return top == NULL;
}
void push(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    int data = top->data;
    struct node *temp = top;
    top = top->next;
    free(temp);
    return data;
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    return 0;
}