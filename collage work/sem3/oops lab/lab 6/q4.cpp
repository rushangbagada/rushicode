// Create a programme using a pointer to navigate and manipulate the data in an 
// array of integers. 
// a.  Declare an array with 10 integers. 
// b.  Declare a pointer and point it to the first element of an array. 
// c.  Access and print the value of the fifth element in the array without using 
// array indexing ([]). (Pointer Arithmetic) 
// d.  Declare another pointer to an integer and point it to the integer pointer 
// created in the previous steps, and print the value of the element it points 
// to. (Pointer to Pointer) 
// e.  Update the value of the third element using the first pointer created in 
// step b, and print the value of the third element using the second pointer 
// created in step d.


#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; 

    int* p = arr; 
    cout << "Fifth element: " << *(p + 4) << endl;

    int** pp = &p; 
    cout << "Value pointed by pointer to pointer: " << **pp << endl;

    
    *(p + 2) = 999;
    cout << "Updated third element (using pointer to pointer): " << *(*pp + 2) << endl;

    return 0;
}