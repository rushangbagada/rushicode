// Q6: Employee Payroll Slip Generator with Stream Flags
// Demonstrates: showpos, internal, setfill, setw, stream flags

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Employee {
    int empID;
    string name;
    double hourlyWage;
    double hoursWorked;
    double grossPay;
};

int main() {
    int n;
    double threshold = 500.0; // Minimum pay threshold
    
    cout << "Enter number of employees: ";
    cin >> n;
    cin.ignore();
    
    Employee employees[n];
    
    // Input employee details
    for(int i = 0; i < n; i++) {
        cout << "\n--- Employee " << (i+1) << " ---\n";
        
        // Input Employee ID with validation
        while(true) {
            cout << "Enter Employee ID: ";
            cin >> employees[i].empID;
            
            if(cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(10000, '\n'); // Discard invalid input
                cout << "Invalid input! Please enter a numeric Employee ID.\n";
            } else {
                cin.ignore(); // Clear newline
                break;
            }
        }
        
        cout << "Enter Name: ";
        getline(cin, employees[i].name);
        
        // Input Hourly Wage with validation
        while(true) {
            cout << "Enter Hourly Wage: ";
            cin >> employees[i].hourlyWage;
            
            if(cin.fail() || employees[i].hourlyWage < 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter a valid hourly wage.\n";
            } else {
                break;
            }
        }
        
        // Input Hours Worked with validation
        while(true) {
            cout << "Enter Hours Worked: ";
            cin >> employees[i].hoursWorked;
            
            if(cin.fail() || employees[i].hoursWorked < 0) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter valid hours worked.\n";
            } else {
                cin.ignore(); // Clear newline
                break;
            }
        }
        
        employees[i].grossPay = employees[i].hourlyWage * employees[i].hoursWorked;
    }
    
    // Display Payroll Slips
    cout << "\n\n";
    cout << string(90, '=') << endl;
    cout << setw(50) << "PAYROLL SLIP REPORT" << endl;
    cout << string(90, '=') << endl;
    
    // Table Header
    cout << left << setw(30) << "Employee Name"
         << right << setw(15) << "Employee ID"
         << setw(15) << "Hourly Wage"
         << setw(15) << "Hours"
         << setw(15) << "Gross Pay" << endl;
    cout << string(90, '-') << endl;
    
    // Display each employee's payroll
    for(int i = 0; i < n; i++) {
        // Name - left aligned
        cout << left << setw(30) << employees[i].name;
        
        // ID - right aligned, padded with zeros, width 8
        cout << right << setfill('0') << setw(15) << employees[i].empID;
        cout << setfill(' ');
        
        // Hourly wage - with sign
        cout << showpos << fixed << setprecision(2) 
             << setw(15) << employees[i].hourlyWage;
        
        // Hours worked
        cout << noshowpos << fixed << setprecision(2)
             << setw(15) << employees[i].hoursWorked;
        
        // Gross pay - with sign and internal alignment
        cout << showpos << internal << setfill('*') 
             << setw(15) << fixed << setprecision(2) 
             << employees[i].grossPay << noshowpos << setfill(' ');
        
        cout << endl;
        
        // Warning if below threshold
        if(employees[i].grossPay < threshold) {
            cout << "⚠ WARNING: Gross pay for " << employees[i].name 
                 << " is below threshold!" << endl << flush;
        }
    }
    
    cout << string(90, '=') << endl;
    
    // Individual Payroll Slips
    for(int i = 0; i < n; i++) {
        cout << "\n\n";
        cout << string(60, '=') << endl;
        cout << setw(35) << "PAYROLL SLIP" << endl;
        cout << string(60, '=') << endl;
        
        cout << left << setw(20) << "Employee Name:" 
             << setw(40) << employees[i].name << endl;
        
        cout << left << setw(20) << "Employee ID:" 
             << right << setfill('0') << setw(8) << employees[i].empID 
             << setfill(' ') << endl;
        
        cout << string(60, '-') << endl;
        
        cout << left << setw(30) << "Hourly Wage:" 
             << right << showpos << "$ " << fixed << setprecision(2)
             << setw(10) << employees[i].hourlyWage << noshowpos << endl;
        
        cout << left << setw(30) << "Hours Worked:" 
             << right << fixed << setprecision(2)
             << setw(12) << employees[i].hoursWorked << endl;
        
        cout << string(60, '-') << endl;
        
        cout << left << setw(30) << "Gross Pay:" 
             << right << showpos << "$ " << fixed << setprecision(2)
             << setw(10) << employees[i].grossPay << noshowpos << endl;
        
        cout << string(60, '=') << endl;
        
        if(employees[i].grossPay < threshold) {
            cout << "\n⚠ WARNING: Payment below minimum threshold of $" 
                 << fixed << setprecision(2) << threshold << endl << flush;
        }
    }
    
    cout << "\n\nPayroll processing completed!" << endl;
    
    return 0;
}
