// Q2: Employee Management System
// Demonstrates: Dynamic memory allocation, this pointer, pointer to objects

#include <bits/stdc++.h>
using namespace std;

class Employee {
private:
    string name;
    int age;
    double salary;
    
public:
    // Constructor
    Employee(string n = "", int a = 0, double s = 0.0) : name(n), age(a), salary(s) {}
    
    // Input employee details
    void inputDetails() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter salary: ";
        cin >> salary;
    }
    
    // Display employee details using this pointer
    void displayDetails() {
        cout << "\n=== Employee Details ===\n";
        cout << "Current object address: " << this << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Salary: $" << this->salary << endl;
    }
    
    // Update salary by percentage using this pointer
    void updateSalary(double percentage) {
        this->salary += this->salary * (percentage / 100.0);
        cout << "\nSalary updated by " << percentage << "%\n";
        cout << "New salary: $" << this->salary << endl;
    }
    
    // Compare two employees using this pointer
    bool earnMoreThan(Employee* other) {
        return this->salary > other->salary;
    }
    
    // Return this pointer
    Employee* getThis() {
        return this;
    }
    
    // Demonstrate this pointer explicitly
    void showThisPointer() {
        cout << "\nDemonstrating 'this' pointer:\n";
        cout << "Address of current object: " << this << endl;
        cout << "Value accessed via this->name: " << this->name << endl;
        cout << "Address of name member: " << &(this->name) << endl;
    }
};

int main() {
    cout << "=== Employee Management System ===\n\n";
    
    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;
    
    // Dynamically create array of Employee pointers
    Employee** employees = new Employee*[numEmployees];
    
    // Input details for each employee
    for (int i = 0; i < numEmployees; i++) {
        cout << "\n--- Employee " << i + 1 << " ---\n";
        employees[i] = new Employee();  // Dynamically allocate each object
        employees[i]->inputDetails();
    }
    
    // Display all employee details
    cout << "\n\n=== All Employee Details ===\n";
    for (int i = 0; i < numEmployees; i++) {
        cout << "\nEmployee " << i + 1 << ":";
        employees[i]->displayDetails();
    }
    
    // Update salary for first employee
    if (numEmployees > 0) {
        cout << "\n\n=== Updating Salary ===\n";
        double percentage;
        cout << "Enter percentage to increase salary for Employee 1: ";
        cin >> percentage;
        employees[0]->updateSalary(percentage);
        employees[0]->displayDetails();
    }
    
    // Demonstrate this pointer
    if (numEmployees > 0) {
        cout << "\n\n=== this Pointer Demonstration ===\n";
        employees[0]->showThisPointer();
        
        // Using getThis() to get the object pointer
        Employee* ptr = employees[0]->getThis();
        cout << "\nPointer returned by getThis(): " << ptr << endl;
        cout << "Original object address: " << employees[0] << endl;
        cout << "Both addresses match: " << (ptr == employees[0] ? "Yes" : "No") << endl;
    }
    
    // Compare employees
    if (numEmployees > 1) {
        cout << "\n\n=== Comparing Employees ===\n";
        if (employees[0]->earnMoreThan(employees[1])) {
            cout << "Employee 1 earns more than Employee 2\n";
        } else {
            cout << "Employee 2 earns more than or equal to Employee 1\n";
        }
    }
    
    // Demonstrate pointer to member function
    cout << "\n\n=== Pointer to Member Function ===\n";
    void (Employee::*displayFunc)() = &Employee::displayDetails;
    if (numEmployees > 0) {
        cout << "Calling displayDetails() through pointer to member function:\n";
        (employees[0]->*displayFunc)();
    }
    
    // Cleanup - delete all dynamically allocated memory
    for (int i = 0; i < numEmployees; i++) {
        delete employees[i];
    }
    delete[] employees;
    
    cout << "\n\nMemory cleaned up successfully!\n";
    
    return 0;
}
