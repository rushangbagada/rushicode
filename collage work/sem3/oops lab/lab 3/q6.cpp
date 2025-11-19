// Create a C++ program that demonstrates function overloading using a class. You are required
// to design a class named Calculator that performs addition operations. The add() function should
// be overloaded to handle the following cases:
// ● Add two integers
// ● Add three integers
// ● Add two floating-point numbers
// ● Add a double and an integer


#include <bits/stdc++.h>
using namespace std;    

class Calculator {
public:
    
    int add(int a, int b) {
        return a + b;
    }

   
    int add(int a, int b, int c) {
        return a + b + c;
    }

    
    float add(float a, float b) {
        return a + b;
    }

   
    double add(double a, int b) {
        return a + b;
    }
};

int main() {
    Calculator calc;

    
    cout << "Sum of 5 and 10: " << calc.add(5, 10) << endl;

    cout << "Sum of 5, 10, and 15: " << calc.add(5, 10, 15) << endl;

    
    cout << "Sum of 5.5 and 10.2: " << calc.add(5.5f, 10.2f) << endl;

    
    cout << "Sum of 5.5 and 10: " << calc.add(5.5, 10) << endl;

    return 0;
}
   