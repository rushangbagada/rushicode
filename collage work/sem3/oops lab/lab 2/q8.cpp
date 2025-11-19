// Write a C++ program that performs basic arithmetic operations (addition, subtraction,
// multiplication, division) using user-defined functions.

#include<bits/stdc++.h>
using namespace std;

void Operations(int a, int b) {
    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    if (b != 0) {
        cout << "Division: " << static_cast<double>(a) / b << endl;
    } else {
        cout << "Division: Cannot divide by zero." << endl;
    }
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    Operations(num1, num2);

    return 0;
}