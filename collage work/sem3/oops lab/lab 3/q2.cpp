// Write a C++ program to create an object of a class and access class attributes
// Example: Student's Roll No.: 101
// Student's Name: First_Name Last_Name
// Student's Percentage: 90.45

#include<bits/stdc++.h>
using namespace std;

class student{
public:
    int rollno;
    string name;
    float percentage;
    student(int r, string n, float p){
        rollno = r;
        name = n;
        percentage = p;
    }

    void display() {
        cout << "Student's Roll No.: " << rollno << endl;
        cout << "Student's Name: " << name << endl;
        cout << "Student's Percentage: " << percentage << endl;
    }
};

int main(){
    student s1(76,"rushang", 90.45);
    s1.display();

}