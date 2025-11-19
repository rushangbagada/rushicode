// Define a class UninitializedPtrDemo with a private int* wildPtr (do not initialize in 
// constructor initially). Add a method void initialize(int value) that allocates memory 
// for  wildPtr  and  sets  the  value.  Add  a  method  int  getValue()  that  returns  *wildPtr 
// (without checks initially).
// In  main(),  create  an  instance,  attempt  to  call  getValue()  before  initialize()  (this 
// demonstrates wild pointer—undefined behavior). 
// Modify  the  class  to  initialize  wildPtr  to  nullptr  in  the  constructor,  add  a  check in 
// getValue() for null, and only dereference if not null.
#include<bits/stdc++.h>
using namespace std;

class UninitializedPtrDemo {
    int* wildPtr;
public:
    UninitializedPtrDemo() {
        wildPtr = nullptr;
    }
    void initialize(int value) {
        wildPtr = new int(value);
    }
    int getValue() {
        if (wildPtr == nullptr) {
            cerr << "Wild pointer access detected!" << endl;
            return -1; 
        }
        return *wildPtr;
    }
};

int main() {
    UninitializedPtrDemo demo;
    cout << "Value: " << demo.getValue() << endl; 
    demo.initialize(42);
    cout << "Value: " << demo.getValue() << endl;
    return 0;
}