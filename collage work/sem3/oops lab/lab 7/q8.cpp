 
// 8.  Null Pointer Safe Linked List 
// Design a singly linked list using a Node class where next is a pointer. 
// • Ensure that all next pointers are initialized to nullptr in constructors. 
// • Implement: 
//   - void insert(int value) 
//   - void display() 
//   - int search(int value) (return index or -1) 
// • In main(), show that: 
//   - Without null initialization, the list leads to garbage traversal. 
//   - With proper initialization, null pointer safely terminates traversal. 
// (Concepts: null pointer as sentinel, avoiding garbage links, safe dynamic structures)


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    
    }
    ~Node() {
        cout << "Node with value " << data << " deleted." << endl;
    }   

    Node* getNext() const {
        return next;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }   
    int search(int value) {
        Node* current = head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; // Not found
    }
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    // Insert elements
    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Display the list
    cout << "Linked List: ";
    list.display();

    // Search for an element
    int valueToSearch = 20;
    int index = list.search(valueToSearch);
    if (index != -1) {
        cout << "Value " << valueToSearch << " found at index " << index << "." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found." << endl;
    }

    return 0;
}