// Write a C++ program to swap the values of two numbers by using 
// • Call by value 
// • Call by address 
// • Call by reference variable 


#include<bits/stdc++.h>
using namespace std;

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    // Call by value
    swapByValue(x, y);
    cout << "After swap by value: x = " << x << ", y = " << y << endl;

    // Call by address
    swapByAddress(&x, &y);
    cout << "After swap by address: x = " << x << ", y = " << y << endl;

    // Call by reference
    swapByReference(x, y);
    cout << "After swap by reference: x = " << x << ", y = " << y << endl;

    return 0;
}