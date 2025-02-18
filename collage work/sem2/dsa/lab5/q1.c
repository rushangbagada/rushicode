// Reversing a Queue using another Queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 


struct Queue
{
    int items[MAX];
    int front, rear;
};


struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}


int isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}


int isFull(struct Queue *queue)
{
    return queue->rear == MAX - 1;
}


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


int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return -1; 
    }
    int dequeuedValue = queue->items[queue->front];
    if (queue->front >= queue->rear)
    {
        
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return dequeuedValue;
}


void reverseQueue(struct Queue *originalQueue)
{
    int tempQueue[MAX];
    int tempIndex = 0;

    
    while (!isEmpty(originalQueue))
    {
        tempQueue[tempIndex++] = dequeue(originalQueue);
    }

    
    for (int i = tempIndex - 1; i >= 0; i--)
    {
        enqueue(originalQueue, tempQueue[i]);
    }
}

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