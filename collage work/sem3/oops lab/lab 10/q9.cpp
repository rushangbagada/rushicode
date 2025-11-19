// Write a C++ program to demonstrate Hybrid Inheritance using the following structure: 
// a. Create a base class Person with data members name and age. 
// b. Derive a class Student from Person, adding studentID and course. 
// c. Derive another class Exam from Student, adding marks. 
// d. Create another class Sports (independent from Student) with a data member score. 
// e. Finally, derive a class Result from both Exam and Sports to calculate and display the total 
// performance.  (Note: The code should compile and demonstrate Hybrid Inheritance clearly

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived from Person
class Student : virtual public Person {
protected:
    int studentID;
    string course;

public:

    Student(string n = "", int a = 0, int id = 0, string c = "") 
        : Person(n, a), studentID(id), course(c) {}

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived from Student
class Exam : virtual public Student {
protected:
    float marks;

public:
    Exam(string n = "", int a = 0, int id = 0, string c = "", float m = 0.0)
        : Person(n, a), Student(n, a, id, c), marks(m) {}

    void displayExam() {
        displayStudent();
        cout << "Exam Marks: " << marks << endl;
    }

    float getMarks() { return marks; }
};

// Independent class (not derived from Person)
class Sports {
protected:
    float score;

public:
    Sports(float s = 0.0) : score(s) {}

    void displaySports() {
        cout << "Sports Score: " << score << endl;
    }

    float getScore() { return score; }
};

// Hybrid inheritance: Result inherits from both Exam and Sports
class Result : public Exam, public Sports {
private:
    float totalPerformance;

public:
    Result(string n, int a, int id, string c, float m, float s)
        : Person(n, a), Student(n, a, id, c), Exam(n, a, id, c, m), Sports(s) {
        calculateTotal();
    }

    void calculateTotal() {
        totalPerformance = marks + score;
    }

    void displayResult() {
        cout << "\n=== Student Result ===" << endl;
        displayExam();
        displaySports();
        cout << "-------------------" << endl;
        cout << "Total Performance: " << totalPerformance << endl;
        
        if (totalPerformance >= 80)
            cout << "Grade: Excellent" << endl;
        else if (totalPerformance >= 60)
            cout << "Grade: Good" << endl;
        else if (totalPerformance >= 40)
            cout << "Grade: Average" << endl;
        else
            cout << "Grade: Needs Improvement" << endl;
    }
};

int main() {
    string name, course;
    int age, studentID;
    float marks, score;

    cout << "Enter student name: ";
    getline(cin, name);
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Enter student ID: ";
    cin >> studentID;
    cin.ignore();
    
    cout << "Enter course: ";
    getline(cin, course);
    
    cout << "Enter exam marks (out of 100): ";
    cin >> marks;
    
    cout << "Enter sports score (out of 100): ";
    cin >> score;

    Result student(name, age, studentID, course, marks, score);
    student.displayResult();

    return 0;
}
