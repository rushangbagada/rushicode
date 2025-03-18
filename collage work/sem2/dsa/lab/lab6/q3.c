//// Q2:Write a program to reverse the element of ABOVE singly linked list.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Function to reverse the linked list
struct node *reverse(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next; // Store next node
        curr->next = prev; // Reverse current node's pointer
        prev = curr;       // Move prev and curr one step forward
        curr = next;
    }
    return prev; // New head of the reversed list
}

// Function to print the linked list
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int rem;

    // Creating linked list from digits of the number
    while (n > 0)
    {
        rem = n % 10;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rem;
        new_node->next = head;
        head = new_node;
        n /= 10;
    }

    printf("Original Linked List: ");
    printList(head);

    // Reverse the linked list
    head = reverse(head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
