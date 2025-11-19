#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual double calculateArea() = 0;
    void display() { cout << "This is a shape\n"; }
    virtual ~Shape() {}
};
class Circle : public Shape
{
    double r;

public:
    Circle(double rr) : r(rr) {}
    double calculateArea() override { return 3.14 * r * r; }
};
class Rectangle : public Shape
{
    double l, w;

public:
    Rectangle(double ll, double ww) : l(ll), w(ww) {}
    double calculateArea() override { return l * w; }
};

int main()
{
    Shape *s1 = new Circle(3);
    Shape *s2 = new Rectangle(4, 5);
    cout << "Circle Area: " << s1->calculateArea() << "\n";
    s1->display();
    cout << "Rectangle Area: " << s2->calculateArea() << "\n";
    s2->display();
    delete s1;
    delete s2;
    return 0;
}
