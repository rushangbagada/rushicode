#include <bits/stdc++.h>
using namespace std;

class Address
{
public:
    string city, state;
    int pincode;
    Address(string c = "", string s = "", int p = 0) : city(c), state(s), pincode(p) {}
};
class Student
{
public:
    string name;
    int roll;
    Address addr;
    Student(string n = "", int r = 0, Address a = Address()) : name(n), roll(r), addr(a) {}
    void display() { cout << "Name: " << name << " Roll: " << roll << " City: " << addr.city << " State: " << addr.state << " Pincode: " << addr.pincode << "\n"; }
};
class GraduateStudent : public Student
{
public:
    string degree;
    GraduateStudent(string n, int r, Address a, string d) : Student(n, r, a), degree(d) {}
    void displayAll()
    {
        display();
        cout << "Degree: " << degree << "\n";
    }
};

int main()
{
    Address ad("Mumbai", "Maharashtra", 400001);
    GraduateStudent gs("Priya", 101, ad, "M.Tech");
    gs.displayAll();
    return 0;
}
/*
Containership vs Inheritance (comments):
- Containership: Student "has-a" Address object as member (reuse). Address exists independently.
- Inheritance: GraduateStudent "is-a" Student; it acquires Student's interface and behaviour.
*/
