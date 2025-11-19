// Q1: Shape Area Calculation System
// Demonstrates: Pointer to Function, Pointer to Data Member, Pointer to Object,
//               this Pointer, Virtual Function, Runtime Polymorphism

#include <bits/stdc++.h>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n = "Shape") : name(n) {}
    
    // Virtual function for polymorphism
    virtual double area() = 0;
    
    // Function to input data
    virtual void inputData() = 0;
    
    // Function to display result
    void displayResult() {
        cout << "Shape: " << name << endl;
        cout << "Area: " << area() << endl;
    }
    
    // Using this pointer
    void showDetails() {
        cout << "Current object address: " << this << endl;
        cout << "Object name: " << this->name << endl;
    }
    
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    double radius;
    
    Circle() : Shape("Circle"), radius(0) {}
    
    void inputData() override {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }
    
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
public:
    double length, width;
    
    Rectangle() : Shape("Rectangle"), length(0), width(0) {}
    
    void inputData() override {
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;
    }
    
    double area() override {
        return length * width;
    }
};

int main() {
    cout << "=== Shape Area Calculation System ===\n\n";
    
    // Pointer to Object - dynamically creating objects
    Circle* c = new Circle();
    Rectangle* r = new Rectangle();
    
    cout << "--- Circle Input ---\n";
    c->inputData();
    
    cout << "\n--- Rectangle Input ---\n";
    r->inputData();
    
    cout << "\n--- Results ---\n";
    
    // Pointer to Function - storing function address
    void (Shape::*funcPtr)() = &Shape::displayResult;
    (c->*funcPtr)();  // Call through pointer to function
    cout << endl;
    (r->*funcPtr)();
    
    cout << "\n--- Using this Pointer ---\n";
    c->showDetails();
    cout << endl;
    r->showDetails();
    
    // Pointer to Data Member - accessing data members through pointers
    cout << "\n--- Pointer to Data Member ---\n";
    double Circle::*radiusPtr = &Circle::radius;
    double Rectangle::*lengthPtr = &Rectangle::length;
    double Rectangle::*widthPtr = &Rectangle::width;
    
    cout << "Circle radius (via pointer): " << c->*radiusPtr << endl;
    cout << "Rectangle length (via pointer): " << r->*lengthPtr << endl;
    cout << "Rectangle width (via pointer): " << r->*widthPtr << endl;
    
    // Modifying through pointer to data member
    c->*radiusPtr = 10.0;
    r->*lengthPtr = 15.0;
    r->*widthPtr = 20.0;
    
    cout << "\n--- After Modification ---\n";
    cout << "New Circle radius: " << c->*radiusPtr << endl;
    cout << "New Rectangle dimensions: " << r->*lengthPtr << " x " << r->*widthPtr << endl;
    
    // Runtime Polymorphism - calling through base class pointer
    cout << "\n=== Runtime Polymorphism Demo ===\n";
    Shape* shapes[2];
    shapes[0] = c;
    shapes[1] = r;
    
    for (int i = 0; i < 2; i++) {
        cout << "\nShape " << i + 1 << ":\n";
        cout << "Area: " << shapes[i]->area() << endl;  // Calls derived class version
    }
    
    // Cleanup
    delete c;
    delete r;
    
    return 0;
}
