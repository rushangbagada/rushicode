#include <bits/stdc++.h>
using namespace std;

class Employee{
protected:
    string name;
    double salary;
public:
    Employee(string n="", double s=0): name(n), salary(s) {}
    virtual void showDetails(){ cout<<"Base Details: Name = "<<name<<", Salary = "<<salary<<"\n"; }
};

class Manager: public Employee{
private:
    string dept;
    double bonus;
public:
    Manager(string n,double s,string d,double b): Employee(n,s), dept(d), bonus(b){}
    void showDetails() override{ cout<<"Derived Details: Department = "<<dept<<", Bonus = "<<bonus<<"\n"; }
    void showBoth(){ Employee::showDetails(); showDetails(); }
};

int main(){
    Manager m("Raj",30000,"HR",5000);
    m.showBoth();
    return 0;
}
