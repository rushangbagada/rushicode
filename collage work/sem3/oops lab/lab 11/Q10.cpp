#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name;

public:
    Person(string n = "") : name(n) {}
    virtual void display() { cout << "Name: " << name << "\n"; }
};
class Student : virtual public Person
{
public:
    int studentID;
    Student(string n = "", int id = 0) : Person(n), studentID(id) {}
    void display() override { cout << "Name: " << name << " StudentID: " << studentID << "\n"; }
};
class Employee : virtual public Person
{
public:
    int employeeID;
    Employee(string n = "", int id = 0) : Person(n), employeeID(id) {}
    void display() override { cout << "Name: " << name << " EmployeeID: " << employeeID << "\n"; }
};
class Manager : public Student, public Employee
{
public:
    Manager(string n, int sid, int eid) : Person(n), Student(n, sid), Employee(n, eid) {}
    void display() override { cout << "Manager Name: " << name << " SID: " << studentID << " EID: " << employeeID << "\n"; }
};

int main()
{
    Manager m("Sam", 111, 222);
    m.display();
    return 0;
}
