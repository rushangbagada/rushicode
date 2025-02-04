#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to check if a string is a valid positive integer
int isValidNumber(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0; // Not a number
        }
    }
    return 1; // Valid number
}

int main()
{
    char input[100];
    int dimensions[10]; // Array to hold dimensions (max 10 dimensions)
    int numDimensions = 0;

    printf("Enter the dimensions of the multi-dimensional array (comma-separated): ");
    scanf("%s", input);

    // Split the input string by commas
    char *token = strtok(input, ",");

    while (token != NULL) {
        if (isValidNumber(token))
        {
            int value = atoi(token);
            if (value > 0)
            {
                dimensions[numDimensions++] = value;
            }
            else
            {
                printf("Error: Dimensions must be positive integers.\n");
                return 1;
            }
        }
        else
        {
            printf("Error: Invalid input '%s'. Dimensions must be integers.\n", token);
            return 1;
        }
        token = strtok(NULL, ",");
    }

    if (numDimensions == 0) {
        printf("Error: No dimensions provided.\n");
        return 1;
    }

    // Display the valid dimensions
    printf("The array declaration is valid with dimensions: ");
    for (int i = 0; i < numDimensions; i++) {
        printf("%d", dimensions[i]);
        if (i < numDimensions - 1)
        {
            printf(" x ");
        }
    }
   

    return 0;
}
