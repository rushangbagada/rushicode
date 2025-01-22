// 1. Write a C program to create three signed integer arrays SubArray1, SubArray2, and
// MainArray of sizes 10, 10, and 20 respectively. With the appropriate error message
// handling, perform the following operations on the array with the help of the menu.
// After each operation, print the array elements.
// a. Insert the elements in a user-given array and print the memory address of all
// elements, the size of the array, and the number of elements in the array:
// - at the end
// - at the beginning
// - at the user-given position
// b. Modify the elements in a user-given array:
// - at the end
// - at the beginning
// - at the user-given position
// c. Delete the element from the array:
// - from the end
// - from the beginning and
// - from the user-given position
// d. Reverse the elements of the user-given array:
// - use a temporary array to hold the result
// - do not create another array to hold the result
// e. Copy the sequence of the user-given subarray to Main Array.
// f. Merge two arrays of the same size sorted in descending order.
// g. Display the sum of all array elements:
// • without recursion
// • using recursion
// h. Search the array for the user-given value from the user-given array.
// i. From the MainArray, separate sub-arrays for odd and even numbers and display
// them. (Assume 10 odd and 10 even numbers are provided in MainArray).
// j. From the MainArray, separate sub-arrays for positive and negative numbers and
// display them. (Assume 10 positive and 10 negative numbers are provided in
// MainArray).

#include <stdio.h>

int take_input(int subarray1,int size)
{
    if(size > 10)
    {
        printf("size should be less than 10");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("enter element of subarry1: ");
        scanf("%d", &subarray1[i]);
    }
    
}

int main()
{
    int subarray1[10], subarray2[10], mainarray[20];
    int size;
    printf("enter size of subarry1: ");
    scanf("%d", &size);
    int size1 = take_input(subarray1,size);
    return 0;
}