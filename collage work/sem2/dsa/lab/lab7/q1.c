#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Queue structure
typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// Initialize queue
void initQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
}

// Check if queue is empty
int isEmpty(Queue *q)
{
    return q->front == NULL;
}

// Enqueue (insert) an element
void enqueue(Queue *q, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed! Cannot enqueue %d\n", value);
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d enqueued into queue.\n", value);
}

// Dequeue (remove) an element
int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue Underflow! Cannot dequeue.\n");
        return -1;
    }
    Node *temp = q->front;
    int dequeuedValue = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

// Peek at the front element
int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Display queue elements
void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = q->front;
    printf("Queue elements: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main()
{
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);

    printf("Front element: %d\n", peek(&q));

    return 0;
}