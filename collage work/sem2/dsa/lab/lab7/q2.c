#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Doubly Linked List Structure
typedef struct
{
    Node *head;
    Node *tail;
} LinkedList;

// Function to initialize the list
void initLinkedList(LinkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
}

// Insert at the end
void insertAtEnd(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
    printf("Node inserted at end\n");
}

// Insert at the beginning
void insertAtBegin(Node **head, Node **tail, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Node inserted at beginning\n");
}

// Insert at a specific position
void insertAtPos(Node **head, Node **tail, int data, int pos)
{
    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    { // Insert at beginning
        insertAtBegin(head, tail, data);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    Node *temp = *head;
    int count = 1;
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    else
    {
        *tail = newNode; // If inserted at the last position
    }

    temp->next = newNode;
    printf("Node inserted at position %d\n", pos);
}

// Display the linked list
void display(Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete a node by value
void deleteNode(Node **head, Node **tail, int data)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node *temp = *head;

    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found\n", data);
        return;
    }

    if (temp == *head)
    { // Deleting the head node
        *head = temp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        else
        {
            *tail = NULL; // If list becomes empty
        }
    }
    else if (temp == *tail)
    { // Deleting the tail node
        *tail = temp->prev;
        (*tail)->next = NULL;
    }
    else
    { // Deleting a node in the middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node deleted\n");
}

int main()
{
    LinkedList list;
    initLinkedList(&list);

    int choice, data, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Display\n5. Delete\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBegin(&list.head, &list.tail, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&list.head, &list.tail, data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPos(&list.head, &list.tail, data, pos);
            break;
        case 4:
            display(list.head);
            break;
        case 5:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&list.head, &list.tail, data);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
