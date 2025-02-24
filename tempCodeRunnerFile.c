#include <stdio.h>
#include <stdlib.h>

#define MAX 100 

struct Queue
{
    int items[MAX];
    int front, rear;
};

// Function to create and initialize a queue
void initializeQueue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return queue->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(struct Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = value;
}

// Function to dequeue an element
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1; 
    }
    int dequeuedValue = queue->items[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return dequeuedValue;
}

// Function to reverse a queue using another queue
void reverseQueue(struct Queue *originalQueue)
{
    struct Queue tempQueue;
    initializeQueue(&tempQueue);

    while (!isEmpty(originalQueue))
    {
        enqueue(&tempQueue, dequeue(originalQueue)); // Transfer all elements
    }

    // Copy back to originalQueue in reverse order
    while (!isEmpty(&tempQueue))
    {
        enqueue(originalQueue, dequeue(&tempQueue));
    }
}

// Function to print the queue
void printQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

// Main function to test the queue reversal
int main()
{
    struct Queue originalQueue;
    initializeQueue(&originalQueue);

    // Enqueue elements into the queue
    enqueue(&originalQueue, 1);
    enqueue(&originalQueue, 2);
    enqueue(&originalQueue, 3);
    enqueue(&originalQueue, 4);
    enqueue(&originalQueue, 5);

    printf("Original Queue: ");
    printQueue(&originalQueue);

    // Reverse the queue
    reverseQueue(&originalQueue);

    printf("Reversed Queue: ");
    printQueue(&originalQueue);

    return 0;
}
