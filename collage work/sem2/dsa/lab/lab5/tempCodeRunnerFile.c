#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define MAX 100

// Structure for Deque (Doubly Ended Queue)
typedef struct
{
    char items[MAX];
    int front, rear;
} Deque;

// Function to initialize the deque
void initializeDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq)
{
    return (dq->front == -1);
}

// Function to check if the deque is full
int isFull(Deque *dq)
{
    return ((dq->rear + 1) % MAX == dq->front);
}

// Function to insert at the rear
void insertRear(Deque *dq, char ch)
{
    if (isFull(dq))
    {
        printf("Deque is full!\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->items[dq->rear] = ch;
}

// Function to delete from the front
char deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return '\0';
    }
    char ch = dq->items[dq->front];

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1; // Reset when last element is removed
    }
    else
    {
        dq->front = (dq->front + 1) % MAX;
    }
    return ch;
}

// Function to delete from the rear
char deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty!\n");
        return '\0';
    }
    char ch = dq->items[dq->rear];

    if (dq->front == dq->rear)
    {
        dq->front = dq->rear = -1; // Reset when last element is removed
    }
    else
    {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
    return ch;
}

// Function to check if a string is a palindrome using a deque
int isPalindrome(char str[])
{
    Deque dq;
    initializeDeque(&dq);

    int len = strlen(str);

    // Insert characters into deque (ignoring case and non-alphabetic characters)
    for (int i = 0; i < len; i++)
    {
            insertRear(&dq, str[i]);
    }

    // Check palindrome by comparing front and rear characters
    while (dq.front < dq.rear)
    {
        if (deleteFront(&dq) != deleteRear(&dq))
        {
            return 0; // Not a palindrome
        }
    }
    return 1; // It's a palindrome
}

// Main function
int main()
{
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove newline character from input

    if (isPalindrome(str))
    {
        printf("The string is a palindrome!\n");
    }
    else
    {
        printf("The string is NOT a palindrome.\n");
    }

    return 0;
}
