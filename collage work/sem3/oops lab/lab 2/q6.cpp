
// C++ program that finds the largest among three different numbers entered by the user. using functions

#include <bits/stdc++.h>
using namespace std;


int findLargest(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;

    int largest = findLargest(num1, num2, num3);
    cout << "The largest number is: " << largest << endl;

    return 0;
}