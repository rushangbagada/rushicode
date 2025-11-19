// Create a base class Shape with a function displayArea(). 
//  Derive three classes: 
// ● Rectangle → inputs length and breadth 
// ● Triangle → inputs base and height 
// ● Circle → inputs radius 
// Each derived class should override displayArea() to show its own area.
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual void displayArea() {
        cout << "Area calculation not implemented" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) : length(l), breadth(b) {}

    void displayArea() override {
        double area = length * breadth;
        cout << "Rectangle Area: " << area << " square units" << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    void displayArea() override {
        double area = 0.5 * base * height;
        cout << "Triangle Area: " << area << " square units" << endl;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void displayArea() override {
        double area = M_PI * radius * radius;
        cout << "Circle Area: " << area << " square units" << endl;
    }
};

int main() {
    double length, breadth, base, height, radius;

    cout << "Enter length and breadth of rectangle: ";
    cin >> length >> breadth;
    Rectangle rect(length, breadth);
    rect.displayArea();

    cout << "\nEnter base and height of triangle: ";
    cin >> base >> height;
    Triangle tri(base, height);
    tri.displayArea();

    cout << "\nEnter radius of circle: ";
    cin >> radius;
    Circle circ(radius);
    circ.displayArea();

    return 0;
}
