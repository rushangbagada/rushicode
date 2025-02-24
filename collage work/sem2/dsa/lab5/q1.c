#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
struct Queue
{
    int items[MAX];
    int front, rear;
};

// Function to create a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
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
        queue->front = queue->rear = -1; // Reset the queue
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
    struct Queue *tempQueue = createQueue();

    while (!isEmpty(originalQueue))
    {
        int frontElement = dequeue(originalQueue);

        // Move elements from tempQueue to maintain reverse order
        int size = tempQueue->rear - tempQueue->front + 1;
        enqueue(tempQueue, frontElement);

        for (int i = 0; i < size; i++)
        {
            enqueue(tempQueue, dequeue(tempQueue));
        }
    }

    // Copy elements back to originalQueue 
    while (!isEmpty(tempQueue))
    {
        enqueue(originalQueue, dequeue(tempQueue));
    }

    free(tempQueue);
}

// Function to print a queue
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

// Main function to test the reversal
int main()
{
    struct Queue *originalQueue = createQueue();

    // Enqueue elements into the queue
    enqueue(originalQueue, 1);
    enqueue(originalQueue, 2);
    enqueue(originalQueue, 3);
    enqueue(originalQueue, 4);
    enqueue(originalQueue, 5);

    printf("Original Queue: ");
    printQueue(originalQueue);

    // Reverse the queue
    reverseQueue(originalQueue);

    printf("Reversed Queue: ");
    printQueue(originalQueue);

    // Free allocated memory
    free(originalQueue);

    return 0;
}
