#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {};
    void display() { cout << "Name: " << name << " Age: " << age << "\n"; }
};
class Employee : virtual public Person
{
protected:
    int empId;

public:
    Employee(string n = "", int a = 0, int id = 0) : Person(n, a), empId(id) {}
};
class Student : virtual public Person
{
protected:
    int stuId;

public:
    Student(string n = "", int a = 0, int id = 0) : Person(n, a), stuId(id) {}
};

class WorkingStudent : public Employee, public Student
{
public:
    WorkingStudent(string n, int a, int emp, int stu) : Person(n, a), Employee(n, a, emp), Student(n, a, stu) {}
    void displayAll()
    {
        display();
        cout << "EmpID: " << empId << " StuID: " << stuId << "\n";
    }
};

int main()
{
    WorkingStudent ws("Alex", 22, 1001, 5001);
    ws.displayAll();
    return 0;
}
