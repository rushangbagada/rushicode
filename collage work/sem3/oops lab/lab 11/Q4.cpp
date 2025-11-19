#include <bits/stdc++.h>
using namespace std;

class Student {
protected:
    string name;
    int roll;
public:
    Student(string n="", int r=0): name(n), roll(r) {}
    void displayStudent(){ cout<<"Name: "<<name<<"\nRoll No: "<<roll<<"\n"; }
};

class Test : virtual public Student {
protected:
    int m1, m2;
public:
    Test(int a=0,int b=0){ m1=a; m2=b; }
};

class Sports : virtual public Student {
protected:
    int sportMarks;
public:
    Sports(int s=0){ sportMarks=s; }
};

class Result : public Test, public Sports {
public:
    Result(string n,int r,int a,int b,int s): Student(n,r), Test(a,b), Sports(s) {}
    void display(){
        displayStudent();
        cout<<"Marks in Subject 1: "<<Test::m1<<"\n";
        cout<<"Marks in Subject 2: "<<Test::m2<<"\n";
        cout<<"Sports Marks: "<<Sports::sportMarks<<"\n";
        cout<<"Total: "<<(Test::m1+Test::m2+Sports::sportMarks)<<"\n";
    }
};

int main(){
    Result res("Riya",12,80,85,10);
    res.display();
    return 0;
}
