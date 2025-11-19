// Q1: Student Details with iomanip Manipulators
// Demonstrates: setw, setprecision, left, right, fixed, getline(), get()

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks[3];
    float total;
    float average;
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore(); // Clear newline from buffer
    
    Student students[n];
    
    // Input student details
    for(int i = 0; i < n; i++) {
        cout << "\n--- Student " << (i+1) << " ---\n";
        
        cout << "Enter Roll Number: ";
        cin >> students[i].rollNo;
        cin.ignore();
        
        cout << "Enter Name: ";
        getline(cin, students[i].name);
        
        students[i].total = 0;
        for(int j = 0; j < 3; j++) {
            cout << "Enter marks for Subject " << (j+1) << ": ";
            cin >> students[i].marks[j];
            students[i].total += students[i].marks[j];
        }
        cin.ignore();
        
        students[i].average = students[i].total / 3.0;
    }
    
    // Display formatted table
    cout << "\n\n";
    cout << string(90, '=') << endl;
    cout << setw(45) << "STUDENT REPORT CARD" << endl;
    cout << string(90, '=') << endl;
    
    // Table header
    cout << left << setw(10) << "Roll No" 
         << setw(25) << "Name" 
         << right << setw(12) << "Subject 1" 
         << setw(12) << "Subject 2" 
         << setw(12) << "Subject 3" 
         << setw(10) << "Total" 
         << setw(10) << "Average" << endl;
    cout << string(90, '-') << endl;
    
    // Display student data
    for(int i = 0; i < n; i++) {
        cout << left << setw(10) << students[i].rollNo
             << setw(25) << students[i].name;
        
        for(int j = 0; j < 3; j++) {
            cout << right << setw(12) << fixed << setprecision(2) 
                 << students[i].marks[j];
        }
        
        cout << setw(10) << fixed << setprecision(2) << students[i].total
             << setw(10) << fixed << setprecision(2) << students[i].average << endl;
    }
    
    cout << string(90, '=') << endl;
    
    return 0;
}
