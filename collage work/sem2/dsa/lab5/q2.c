//Create a system to manage orders in a restaurant using a circular queue.The system
//should allow customers to place orders,
//kitchen staff to process orders, and waitstaff to deliver orders to tables, all while efficiently managing the queue of orders with a circular structure.

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
    printf("Enter Customer Name: ");
    scanf(" %[^\n]", newOrder.customerName);
    printf("Enter Food Item: ");
    scanf(" %[^\n]", newOrder.foodItem);

    q->rear = (q->rear + 1) % MAX_ORDERS; // Circular increment
    q->orders[q->rear] = newOrder;
    q->count++;

    printf("Order placed successfully!\n");
}

// Function to process an order (dequeue)
void processOrder(CircularQueue *q)
{
    if (isEmpty(q))
    {
        printf("No pending orders!\n");
        return;
    }

    Order processedOrder = q->orders[q->front];
    printf("\nProcessing Order...\n");
    printf("Order ID: %d | Customer: %s | Food: %s\n",
           processedOrder.orderID, processedOrder.customerName, processedOrder.foodItem);

    q->front = (q->front + 1) % MAX_ORDERS; // Circular increment
    q->count--;

    printf("Order Processed!\n");
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
        printf("Order ID: %d | Customer: %s | Food: %s\n",
               q->orders[index].orderID, q->orders[index].customerName, q->orders[index].foodItem);
        index = (index + 1) % MAX_ORDERS; // Circular increment
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
        printf("3. View Pending Orders\n");
        printf("4. Exit\n");
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
            displayOrders(&orderQueue);
            break;
        case 4:
            printf("Exiting system. Have a great day!\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
