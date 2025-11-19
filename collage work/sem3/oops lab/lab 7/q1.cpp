// Define a class GenericStorage with a private void* member variable data. Implement 
// a constructor that takes a void* parameter to initialize data. Add methods: 
// ●  void setData(void* newData) to update the pointer. 
// ●  Template method T getDataAs() to cast and return the data as type T. 
// In  main(),  create  an  instance  of  GenericStorage,  store  an  integer (e.g., 42), 
// retrieve it as int, then store a string (e.g., "Hello"), and retrieve it as string*. 


#include <iostream>
using namespace std;

class GenericStorage {
    void* data;
public:
    GenericStorage(void* newData) {
        data = newData;
    }
    void setData(void* newData) { data = newData; }
    void* getData() { return data; }
};

int main() {
    int x = 42;
    GenericStorage storage(&x);
    cout << *static_cast<int*>(storage.getData()) << endl;

    const char* str = "Hello";
    storage.setData((void*)str);
    cout << static_cast<const char*>(storage.getData()) << endl;

    return 0;
}