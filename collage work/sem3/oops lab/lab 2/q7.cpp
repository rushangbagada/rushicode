// 7. Write a
// program in C++ to display n terms of natural numbers and their sum. Sample Output:
// Input a number of terms: 7
// The natural numbers upto 7th terms are: 1 2 3 4 5 6 7
// The sum of the natural numbers is: 28

#include<bits/stdc++.h>
using namespace std;

void displaySum(int n) {
    int sum = 0;
    cout << "The natural numbers up to " << n << " terms are: ";
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
        sum += i;
    }
    cout << endl;
    cout << "The sum of the natural numbers is: " << sum << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    displaySum(n);

    return 0;
}