// Q3: Mini Bank Statement Generator
// Demonstrates: fixed, setprecision, setw, currency formatting

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string name, accountNumber;
    double balance;
    
    cout << "=== Bank Statement Generator ===\n\n";
    
    cout << "Enter Customer Name: ";
    getline(cin, name);
    
    cout << "Enter Account Number: ";
    getline(cin, accountNumber);
    
    cout << "Enter Balance Amount: ";
    cin >> balance;
    
    // Display Mini Statement
    cout << "\n\n";
    cout << string(60, '=') << endl;
    cout << setw(40) << right << "MINI BANK STATEMENT" << endl;
    cout << string(60, '=') << endl;
    
    cout << left << setw(25) << "Customer Name:" 
         << left << name << endl;
    
    cout << left << setw(25) << "Account Number:" 
         << left << accountNumber << endl;
    
    cout << string(60, '-') << endl;
    
    cout << left << setw(25) << "Current Balance:" 
         << "Rs. " << fixed << setprecision(2) 
         << balance << endl;
    
    cout << string(60, '=') << endl;
    
    // Additional transaction display
    cout << "\n" << left << setw(35) << "Transaction Type" 
         << right << setw(25) << "Amount (Rs.)" << endl;
    cout << string(60, '-') << endl;
    
    cout << left << setw(35) << "Opening Balance" 
         << right << "Rs. " << fixed << setprecision(2) 
         << setw(20) << balance << endl;
    
    cout << left << setw(35) << "Interest Credited" 
         << right << "Rs. " << fixed << setprecision(2) 
         << setw(20) << (balance * 0.04) << endl;
    
    double closingBalance = balance + (balance * 0.04);
    cout << string(60, '-') << endl;
    cout << left << setw(35) << "Closing Balance" 
         << right << "Rs. " << fixed << setprecision(2) 
         << setw(20) << closingBalance << endl;
    
    cout << string(60, '=') << endl;
    cout << "\nThank you for banking with us!\n";
    
    return 0;
}
