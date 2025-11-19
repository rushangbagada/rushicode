// Q7: Template-Based Circular Buffer Visualizer
// Demonstrates: Class templates, custom fill, table formatting

#include <iostream>
#include <iomanip>
#include <typeinfo>
using namespace std;

template <typename T>
class CircularBuffer {
private:
    T* buffer;
    int capacity;
    int head;
    int tail;
    int count;
    
public:
    CircularBuffer(int size) : capacity(size), head(0), tail(0), count(0) {
        buffer = new T[capacity];
    }
    
    ~CircularBuffer() {
        delete[] buffer;
    }
    
    bool insert(T element) {
        if(count == capacity) {
            cout << "Buffer full! Overwriting oldest element.\n";
            head = (head + 1) % capacity;
            count--;
        }
        
        buffer[tail] = element;
        tail = (tail + 1) % capacity;
        count++;
        return true;
    }
    
    bool remove(T& element) {
        if(count == 0) {
            cout << "Buffer empty!\n";
            return false;
        }
        
        element = buffer[head];
        head = (head + 1) % capacity;
        count--;
        return true;
    }
    
    void display() {
        cout << "\n";
        cout.fill('=');
        cout.width(70);
        cout << "" << endl;
        cout.fill(' ');
        
        cout << setw(40) << "CIRCULAR BUFFER CONTENTS" << endl;
        
        cout.fill('=');
        cout.width(70);
        cout << "" << endl;
        cout.fill(' ');
        
        cout << left << setw(10) << "Index"
             << setw(15) << "Position"
             << setw(20) << "Value"
             << setw(15) << "Status" << endl;
        
        cout.fill('-');
        cout.width(70);
        cout << "" << endl;
        cout.fill(' ');
        
        int pos = head;
        for(int i = 0; i < count; i++) {
            cout << left << setw(10) << i;
            
            cout << setfill('.') << setw(15) << pos << setfill(' ');
            
            // Format based on type
            cout << left << setw(20);
            if(typeid(T) == typeid(double) || typeid(T) == typeid(float)) {
                cout << fixed << setprecision(2) << buffer[pos];
            } else if(typeid(T) == typeid(char)) {
                cout << buffer[pos];
            } else {
                cout << buffer[pos];
            }
            
            if(pos == head && pos == (tail - 1 + capacity) % capacity) {
                cout << setw(15) << "HEAD & TAIL";
            } else if(pos == head) {
                cout << setw(15) << "HEAD";
            } else if(pos == (tail - 1 + capacity) % capacity) {
                cout << setw(15) << "TAIL";
            } else {
                cout << setw(15) << "DATA";
            }
            
            cout << endl;
            
            // Insert horizontal line after every 5 elements
            if((i + 1) % 5 == 0 && i < count - 1) {
                cout.fill('~');
                cout.width(70);
                cout << "" << endl;
                cout.fill(' ');
            }
            
            pos = (pos + 1) % capacity;
        }
        
        cout.fill('=');
        cout.width(70);
        cout << "" << endl;
        cout.fill(' ');
        
        cout << "\nBuffer Statistics:\n";
        cout << "Capacity: " << capacity << " | ";
        cout << "Count: " << count << " | ";
        cout << "Head: " << head << " | ";
        cout << "Tail: " << tail << endl;
        
        cout.fill('=');
        cout.width(70);
        cout << "" << endl;
        cout.fill(' ');
    }
};

int main() {
    cout << "=== Circular Buffer Demo ===\n\n";
    
    // Test with char type
    cout << "--- Testing with CHAR type ---\n";
    CircularBuffer<char> charBuffer(8);
    
    charBuffer.insert('A');
    charBuffer.insert('B');
    charBuffer.insert('C');
    charBuffer.insert('D');
    charBuffer.insert('E');
    charBuffer.insert('F');
    charBuffer.insert('G');
    
    charBuffer.display();
    
    char removed;
    charBuffer.remove(removed);
    cout << "\nRemoved: " << removed << endl;
    charBuffer.insert('H');
    charBuffer.insert('I');
    
    charBuffer.display();
    
    // Test with double type
    cout << "\n\n--- Testing with DOUBLE type ---\n";
    CircularBuffer<double> doubleBuffer(12);
    
    doubleBuffer.insert(23.45);
    doubleBuffer.insert(67.89);
    doubleBuffer.insert(12.34);
    doubleBuffer.insert(99.99);
    doubleBuffer.insert(45.67);
    doubleBuffer.insert(78.90);
    doubleBuffer.insert(34.56);
    doubleBuffer.insert(89.12);
    doubleBuffer.insert(56.78);
    doubleBuffer.insert(90.12);
    
    doubleBuffer.display();
    
    double dRemoved;
    doubleBuffer.remove(dRemoved);
    doubleBuffer.remove(dRemoved);
    cout << "\nLast removed: " << fixed << setprecision(2) << dRemoved << endl;
    
    doubleBuffer.insert(11.11);
    doubleBuffer.insert(22.22);
    doubleBuffer.insert(33.33);
    
    doubleBuffer.display();
    
    return 0;
}
