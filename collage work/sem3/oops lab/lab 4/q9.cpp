// 9. Create a class Student with data members name, roll_no, and a static data member count to     
// keep track of the number of student objects created. 
// A. Write a static member function to display the total number of students created. 
// B. Demonstrate the program by creating at least 3 objects. 


#include<bits/stdc++.h> 
using namespace std;

class Student {
    string name;
    int roll_no;
    static int count;

public:
    Student(string n, int r) {
        name = n;
        roll_no = r;
        count++;
    }
    

    static void displayCount() {
        cout << "Total students created: " << count << endl;
    }
};

int Student::count = 0;

int main() {
    Student s1("Alice", 1);
    Student s2("Bob", 2);
    Student s3("Charlie", 3);

    Student::displayCount();

    return 0;
}
