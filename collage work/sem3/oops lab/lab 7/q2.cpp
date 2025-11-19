// Define a class SafeObject with a private pointer to an integer (int* ptr). Implement a 
// constructor that initializes ptr to nullptr. Add methods: 
// ●  void allocate(int value) to dynamically allocate memory and set the value. 
// ●  int getValue() that checks if ptr is null; if null, return 0 and print "Null pointer 
// detected"; else return *ptr. 
// ●  void deallocate() to free the memory and set ptr to nullptr. 
// In main(), create an instance, call getValue() before allocation (should handle 
// null),  allocate  with  value  100,  get  the  value,  then  deallocate  and  call 
// getValue() again

#include <bits/stdc++.h>
using namespace std;
class SafeObject {
    int* ptr;
public:
    SafeObject() {
        ptr = nullptr;
    }
    void allocate(int value) {
        if (ptr != nullptr) {
            cout << "Memory already allocated. Deallocate first." << endl;
            return;
        }
        ptr = new int(value);
    }
    int getValue() {
        if (ptr == nullptr) {
            cout << "Null pointer detected" << endl;
            return 0;
        }
        return *ptr;
    }
    void deallocate() {
        if (ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
    }
    ~SafeObject() {
        deallocate();
    }
};

int main() {
    SafeObject obj;
    cout << "Value: " << obj.getValue() << endl;
    obj.allocate(100);
    cout << "Value: " << obj.getValue() << endl;
    obj.deallocate();
    cout << "Value: " << obj.getValue() << endl;
    return 0;

}