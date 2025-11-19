// Create a base class called Person with protected data members name (string) and age (int). Create a derived 
// class  Student  that  inherits  publicly  from  Person.  The  Student  class  should  have  additional  private  data 
// members: studentID (int) and major (string). 
// ● The Person class should have a constructor to initialize name and age, and a displayPerson() method 
// to print these details. 
// ● The Student class should have a constructor that initializes all four data members  
// ● The Student class should have a displayStudent() method that first calls displayPerson() from the 
// base class and then prints the studentID and major. 
// ● Write a main() function to create an object of the Student class, initialize it, and call its display 
// method to show the complete details.
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
private:
    int studentID;
    string major;

public:
    Student(string n, int a, int id, string m) : Person(n, a), studentID(id), major(m) {}

    void displayStudent() const {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Major: " << major << endl;
    }
};

int main() {
    Student student("John Doe", 20, 12345, "Computer Science");
    student.displayStudent();
    return 0;
}
