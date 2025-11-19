
// 6. Write a C++ program to store and display the information of students using structure 
// pointers.  

#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};

int main() {
    Student* s = new Student;

    cout << "Enter student name: ";
    cin >> s->name;
    cout << "Enter roll number: ";
    cin >> s->rollNo;
    cout << "Enter marks: ";
    cin >> s->marks;

    cout << "\nStudent Information:\n";
    cout << "Name: " << s->name << endl;
    cout << "Roll No: " << s->rollNo << endl;
    cout << "Marks: " << s->marks << endl;

    delete s;
    return 0;
}
