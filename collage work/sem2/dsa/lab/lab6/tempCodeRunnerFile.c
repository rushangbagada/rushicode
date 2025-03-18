// Write a program to input an n digit number. Now break this number into its individual
// digits and then store every single digit in a separate node thereby forming a linked list.For
//  Example,
// you entered 235, then there will be 3 nodes in the list containing nodes with value 2, 3, 5.


#include <stdio.h>
#include <stdlib.h> 

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    int n;
    printf("Enter a number: "); 
    scanf("%d", &n);
    int rem;
    while (n > 0)
    {
        rem = n % 10;
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = rem;
        new_node->next = head;
        head = new_node;
        n /= 10;
    }
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);  
        temp = temp->next;
    }    
    return 0;
}


  

