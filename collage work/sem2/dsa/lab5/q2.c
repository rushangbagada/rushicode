#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 5 // Max number of orders in the queue

// Order structure
typedef struct
{
    int orderID;
    char customerName[50];
    char foodItem[50];
    int isProcessed; // 0 = Not Processed, 1 = Processed
} Order;

// Circular Queue structure
typedef struct
{
    Order orders[MAX_ORDERS];
    int front, rear, count;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue *q)
{
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if the queue is full
int isFull(CircularQueue *q)
{
    return (q->count == MAX_ORDERS);
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q)
{
    return (q->count == 0);
}

// Function to place an order (enqueue)
void placeOrder(CircularQueue *q)
{
    if (isFull(q))
    {
        printf("Order queue is full! Please wait for pending orders to be processed.\n");
        return;
    }

    Order newOrder;
    printf("Enter Order ID: ");
    scanf("%d", &newOrder.orderID);
    getchar(); // Consume newline character
    printf("Enter Customer Name: ");
    gets(newOrder.customerName);
    printf("Enter Food Item: ");
    gets(newOrder.foodItem);
    newOrder.isProcessed = 0; // New orders are unprocessed

    q->rear = (q->rear + 1) % MAX_ORDERS;
    q->orders[q->rear] = newOrder;
    q->count++;

    printf("Order placed successfully!\n");
}

// Function to process an order
void processOrder(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("No pending orders to process!\n");
        return;
    }

    if (q->orders[q->front].isProcessed)
    {
        printf("The next order is already processed and awaiting delivery.\n");
        return;
    }

    printf("\nProcessing Order...\n");
    printf("Order ID: %d | Customer: %s | Food: %s\n",
           q->orders[q->front].orderID, q->orders[q->front].customerName, q->orders[q->front].foodItem);

    q->orders[q->front].isProcessed = 1; // Mark as processed
    printf("Order Processed! Ready for delivery.\n");
}

// Function to deliver an order
void deliverOrder(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("No orders to deliver!\n");
        return;
    }

    if (!q->orders[q->front].isProcessed)
    {
        printf("The next order has not been processed yet. Process it first!\n");
        return;
    }

    Order deliveredOrder = q->orders[q->front];
    printf("\nDelivering Order...\n");
    printf("Order ID: %d | Customer: %s | Food: %s\n",
           deliveredOrder.orderID, deliveredOrder.customerName, deliveredOrder.foodItem);

    q->front = (q->front + 1) % MAX_ORDERS;
    q->count--;
    printf("Order Delivered Successfully!\n");
}

// Function to display the order queue
void displayOrders(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("No orders in the queue.\n");
        return;
    }

    printf("\nCurrent Orders in Queue:\n");
    int index = q->front;
    for (int i = 0; i < q->count; i++)
    {
        printf("Order ID: %d | Customer: %s | Food: %s | Status: %s\n",
               q->orders[index].orderID, q->orders[index].customerName, q->orders[index].foodItem,
               q->orders[index].isProcessed ? "Processed" : "Pending");
        index = (index + 1) % MAX_ORDERS;
    }
}

// Main function - Restaurant Order System
int main()
{
    CircularQueue orderQueue;
    initializeQueue(&orderQueue);

    int choice;
    while (1)
    {
        printf("\n----- Restaurant Order Management -----\n");
        printf("1. Place Order\n");
        printf("2. Process Order\n");
        printf("3. Deliver Order\n");
        printf("4. View Pending Orders\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            placeOrder(&orderQueue);
            break;
        case 2:
            processOrder(&orderQueue);
            break;
        case 3:
            deliverOrder(&orderQueue);
            break;
        case 4:
            displayOrders(&orderQueue);
            break;
        case 5:
            printf("Exiting system. Have a great day!\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
