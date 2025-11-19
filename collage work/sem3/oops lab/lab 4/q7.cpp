// 7. Write a C++ program to create three different integer pointers using malloc function and 
// new operator. Then use delete operator and free() function to delete the memory 
// allocated to the above pointers.  
// For example:  
// int* ptr1 = (int*) malloc (sizeof(int));  
// int* ptr2 = new int;  
// int* ptr3 = NULL;  


#include<bits/stdc++.h>
using namespace std;

int main() {
 
    int* ptr1 = (int*) malloc (sizeof(int));
    int* ptr2 = new int;
    int* ptr3 = NULL;

   
    *ptr1 = 10;
    *ptr2 = 20;

  
    cout << "Value of ptr1: " << *ptr1 << endl;
    cout << "Value of ptr2: " << *ptr2 << endl;

    free(ptr1);
    delete ptr2;

    return 0;
}