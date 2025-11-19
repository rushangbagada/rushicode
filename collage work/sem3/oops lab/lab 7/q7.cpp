// Heterogeneous Container using Void Pointers 
// Create a class HeteroContainer that can store an array of void* pointers to hold  
// different data types. 
// • Implement methods: 
// - void add(void* item) → to insert elements. 
// - template<typename T> T get(int index) → retrieves and typecasts the element. 
// • In main(), store at least: 
// - An int 
// - A float 
// - A string (as string*) 
// • Retrieve and print them using proper typecasting. 
// • Show what happens if the wrong type is requested (undefined behavior) 
// (Concepts: void pointer arrays, type safety issues, runtime errors) 
 
 
#include<bits/stdc++.h>
using namespace std;

class HeteroContainer {
    vector<void*> items;
public:
    void add(void* item) {
        items.push_back(item);
    }
    template<typename T>
    T get(int index) {
        return *(static_cast<T*>(items[index]));
    }
};

int main() {
    HeteroContainer container;

    // Adding different types of data
    int a = 42;
    float b = 3.14f;
    string str = "Hello, World!";
    
    container.add(&a);
    container.add(&b);
    container.add(&str);

    // Retrieving and printing them
    cout << "Integer: " << container.get<int>(0) << endl;
    cout << "Float: " << container.get<float>(1) << endl;
    cout << "String: " << container.get<string>(2) << endl;

    // Demonstrating type safety issue (undefined behavior)
    // Uncommenting the next line will cause undefined behavior
    // cout << "Wrong type retrieval: " << container.get<float>(2) << endl; 

    return 0;
}