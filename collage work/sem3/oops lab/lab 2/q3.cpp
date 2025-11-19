// Write a program to find the factorial of a number/ using a function
#include <bits/stdc++.h>
using namespace std;

int factorial(double n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    double number;
    cout << "Enter a number: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << number << " is " << factorial(number) << "." << endl;
    }

    return 0;
}