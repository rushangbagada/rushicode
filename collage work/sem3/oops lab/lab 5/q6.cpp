// Write a C++ program to create a class named Box that has:
// ●One private data member: length (integer).
// ● A constructor to initialize the length.
// (a) Declare a friend function named displayLength(Box) that:
// ● Can access the private member length of the Box class.
// ● Displays the length of the box.
// (b) Define an inline function named square(int) that:
// ● Returns the square of the number passed to it.
// ● Demonstrate its use in the main() function.


#include <bits/stdc++.h>

using namespace std;

class Box {
private:
    int length;

public:
    Box(int l) {
        length = l;
    }

    friend void displayLength(Box b);
};

void displayLength(Box b) {
    cout << "Length of the box: " << b.length << endl;
}

inline int square(int x) {
    return x * x;
}

int main() {
    Box box1(10);
    displayLength(box1);

    int num = 5;
    cout << "Square of " << num << ": " << square(num) << endl;

    return 0;
}