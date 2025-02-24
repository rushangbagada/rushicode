#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack definition
typedef struct
{
    int top;
    int items[MAX];
} Stack;


typedef struct
{
    Stack stack1; 
    Stack stack2; 
} Queue;


void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void display(Queue *q);

int main()
{
    Queue q;
    initStack(&q.stack1);
    initStack(&q.stack2);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeued: %d\n", dequeue(&q)); // Should print 10
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 20

    enqueue(&q, 40);
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 30
    printf("Dequeued: %d\n", dequeue(&q)); // Should print 40

    return 0;
}


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


void push(Stack *s, int value)
{
    if (!isFull(s))
    {
        s->items[++s->top] = value;
    }else{
        printf("Stack overflow\n");
    }
}


int pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->items[s->top--];
    }
    return -1; 
}


void enqueue(Queue *q, int value)
{
    printf("Enqueued value: %d \n", value);
    push(&q->stack1, value); 
}




int dequeue(Queue *q)
{
    if (isEmpty(&q->stack2))
    { 
        while (!isEmpty(&q->stack1))
        {
            push(&q->stack2, pop(&q->stack1)); 
        }
    }

    return pop(&q->stack2); 
}

