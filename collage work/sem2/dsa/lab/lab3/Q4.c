//write a program to reverse a string with stack
#include <stdio.h>
#include <string.h> 

int main()  
{
    char str[20];
    char stack[20];
    int top = -1;

    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        stack[++top] = str[i];
    }

    for (int i = 0; i < len; i++)
    {
        str[i] = stack[top--];
    }   

    printf("Reversed string: %s\n", str);
    return 0;
}