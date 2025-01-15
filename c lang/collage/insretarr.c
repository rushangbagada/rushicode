#include <stdio.h>

int main() {
    int n, i, pos, element;

    // Step 1: Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int a[n]; // Declare the array with the specified size

    // Step 2: Input the elements of the array
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Step 3: Input the element to insert and the position
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert the element (0 to %d): ", n);
    scanf("%d", &pos);

    // Check if the position is valid
    if(pos < 0 || pos > n) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", n);
        return 1; // Exit the program with an error code
    }

    // Step 4: Shift elements to the right to make space for the new element
    for(i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    // Step 5: Insert the new element
    a[pos] = element;

    // Print the updated array
    printf("Updated array:\n");
    for(i = 0; i <= n; i++) { // Note: n is now the new size of the array
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}