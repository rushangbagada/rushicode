// Define a class DynamicArray with private members: int* arr and int size. Implement a 
// constructor that takes an int n, uses new to allocate an array of size n, and initializes 
// elements to 0. Add methods: 
// ●  void  setElement(int  index,  int value) to set arr[index] = value (with bounds 
// check). 
// ●  int getElement(int index) to return arr[index] (with bounds check). 
// ●  Destructor to use delete[] to free the array. 
// In main(), create an instance with size 5, set elements (e.g., 1 to 5), print them, 
// then  create  another  instance  and  let it go out of scope to trigger destructor. 
// Handle bad allocations with try-catch for std::

#include<bits/stdc++.h>
using namespace std;

class DynamicArray {
    int* arr;
    int size;
public:
    DynamicArray(int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; ++i) arr[i] = 0;
    }
    void setElement(int i, int v) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        arr[i] = v;
    }
    int getElement(int i) {
        if (i < 0 || i >= size) {
            cout << "Index out of bounds" << endl;
            return -1;
        }
        return arr[i];
    }
    ~DynamicArray() {
        delete[] arr;
    }
};

int main() {
  
        DynamicArray arr(5);
        for (int i = 0; i < 5; ++i) {
            arr.setElement(i, i + 1);
        }
        for (int i = 0; i < 5; ++i) {
            cout << "Element at index " << i << ": " << arr.getElement(i) << endl;
        }
    return 0;
}