//armstrong number 

#include <bits/stdc++.h>
using namespace std;

int digitCount(int n) {
    int count = 0;
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;   
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

bool isArmstrong(int n) {
    int original = n;
    int sum = 0;
    int digits = digitCount(n);

    while (n > 0) {
        int digit = n % 10;
        sum += power(digit, digits);
        n /= 10;
    }

    return sum == original;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isArmstrong(number)) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}