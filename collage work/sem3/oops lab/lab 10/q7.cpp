// a) Explain the 'Diamond Problem' in Multiple Inheritance. 
// b) Give the code showing the 'Diamond Problem'.(Note : This code must give an error on executing.) 
// c) Explain how this 'Diamond Problem' can be solved. 

#include <iostream>
using namespace std;

/* 
a) Diamond Problem Explanation:
   The Diamond Problem occurs in multiple inheritance when a class inherits from two classes
   that both inherit from a common base class. This creates ambiguity about which path to
   follow to access members of the base class.

   Structure:
        A (base)
       / \
      B   C (both inherit from A)
       \ /
        D (inherits from both B and C)
*/

// b) Code showing Diamond Problem (will cause ambiguity):

class A {
public:
    int value;
    void display() {
        cout << "Class A, value = " << value << endl;
    }
};

class B : public A {
public:
    B() { value = 10; }
};

class C : public A {
public:
    C() { value = 20; }
};

class D : public B, public C {
    // D has TWO copies of 'value' and 'display()' - one from B::A and one from C::A
    // This creates ambiguity!
};

// c) Solution using Virtual Inheritance:

class A_Virtual {
public:
    int value;
    void display() {
        cout << "Class A_Virtual, value = " << value << endl;
    }
};

class B_Virtual : virtual public A_Virtual {
public:
    B_Virtual() { value = 10; }
};

class C_Virtual : virtual public A_Virtual {
public:
    C_Virtual() { value = 20; }
};

class D_Virtual : public B_Virtual, public C_Virtual {
    // Now D has only ONE copy of A_Virtual
    // No ambiguity!
};

int main() {
    cout << "=== Demonstrating Diamond Problem ===\n\n";
    
    cout << "Problem: Without virtual inheritance\n";
    D obj1;
    // obj1.value = 5;        // ERROR: ambiguous - which value? B::A::value or C::A::value?
    // obj1.display();        // ERROR: ambiguous - which display()? B::A::display() or C::A::display()?
    
    // We must specify the path:
    obj1.B::value = 100;
    obj1.C::value = 200;
    cout << "B::value = " << obj1.B::value << endl;
    cout << "C::value = " << obj1.C::value << endl;
    cout << "This shows TWO separate copies exist!\n\n";
    
    cout << "Solution: With virtual inheritance\n";
    D_Virtual obj2;
    obj2.value = 300;       // No ambiguity - only ONE copy exists
    cout << "value = " << obj2.value << endl;
    obj2.display();         // No ambiguity - only ONE display() exists
    cout << "Only ONE copy of base class exists!\n";
    
    return 0;
}

