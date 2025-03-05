#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue
{
    int requests[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

int isFull(Queue *q)
{
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

int isEmpty(Queue *q)
{
    return q->front == q->rear;
}

void enqueue(Queue *q, int requestNumber)
{
    if (isFull(q))
    {
        printf("Queue is full! Cannot add request %d.\n", requestNumber);
        return;
    }
    q->requests[q->rear] = requestNumber;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    printf("Request %d added to the queue.\n", requestNumber);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("No requests to process.\n");
        return -1;
    }
    int requestNumber = q->requests[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return requestNumber;
}

void processRequest(Queue *q)
{
    int processedRequest = dequeue(q);
    if (processedRequest != -1)
    {
        printf("Processed request number: %d\n", processedRequest);
    }
}

void displayQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("No requests in the queue.\n");
        return;
    }

    printf("Current requests in the queue: ");
    int count = (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    for (int i = 0; i < count; i++)
    {
        printf("%d ", q->requests[(q->front + i) % MAX_QUEUE_SIZE]);
    }
    printf("\n");
}



int main()
{
    Queue *q = createQueue();
    int choice;

    while (1)
    {
        printf("\nBank Counter Management System\n");
        printf("1. Add Customer Request\n");
        printf("2. Process Customer Request\n");
        printf("3. Display All Requests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n')
                ; 
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int requestNumber;
            printf("Enter request number: ");
            if (scanf("%d", &requestNumber) != 1)
            {
                printf("Invalid input! Please enter a number.\n");
                while (getchar() != '\n')
                    ; // Clear invalid input
                continue;
            }
            enqueue(q, requestNumber);
        }
        break;
        case 2:
            processRequest(q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            printf("Exiting the system.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

