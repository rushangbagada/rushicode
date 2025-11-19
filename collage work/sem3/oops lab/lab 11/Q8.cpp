#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    void displayType() { cout << "This is a shape\n"; }
};
class Circle : public Shape
{
    double r;

public:
    Circle(double rr) : r(rr) {}
    double area() override { return 3.14 * r * r; }
};
class Rectangle : public Shape
{
    double l, w;

public:
    Rectangle(double ll, double ww) : l(ll), w(ww) {}
    double area() override { return l * w; }
    void displayType() { cout << "Rectangle Type\n"; }
};
class Triangle : public Shape
{
    double b, h;

public:
    Triangle(double bb, double hh) : b(bb), h(hh) {}
    double area() override { return 0.5 * b * h; }
};

int main()
{
    Shape *s1 = new Circle(3);
    Shape *s2 = new Rectangle(4, 5);
    cout << "Circle area: " << s1->area() << "\n";
    s1->displayType();
    cout << "Rectangle area: " << s2->area() << "\n";
    s2->displayType();

    // call overridden using scope resolution
    Rectangle *rptr = dynamic_cast<Rectangle *>(s2);
    if (rptr)
    {
        rptr->Rectangle::displayType();
    }

    // base pointer call
    Shape *base = s2;
    base->displayType();

    delete s1;
    delete s2;
    return 0;
}
