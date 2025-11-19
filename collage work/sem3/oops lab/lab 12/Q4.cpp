// Q4: Banking System
// Demonstrates: Pointer to Function, Pointer to Data Member, Pointer to Object,
//               this Pointer, Virtual Function, Runtime Polymorphism

#include <bits/stdc++.h>
using namespace std;

class Account {
protected:
    string name;
    long accNo;
    double balance;
    
public:
    Account(string n = "", long acc = 0, double bal = 0.0) 
        : name(n), accNo(acc), balance(bal) {}
    
    // Virtual function for calculating interest
    virtual double calculateInterest() = 0;
    
    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }
    
    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
            cout << "New Balance: $" << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient balance!\n";
        }
    }
    
    // Function to display balance
    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }
    
    // Display account details using this pointer
    void displayDetails() {
        cout << "\n=== Account Details ===\n";
        cout << "Current object address: " << this << endl;
        cout << "Account Holder: " << this->name << endl;
        cout << "Account Number: " << this->accNo << endl;
        cout << "Balance: $" << this->balance << endl;
    }
    
    // Return this pointer
    Account* getThis() {
        return this;
    }
    
    // Get balance (for pointer to data member demo)
    double getBalance() { return balance; }
    void setBalance(double bal) { balance = bal; }
    
    // Get pointer to balance member (needed for pointer to data member demo)
    static double Account::* getBalancePointer() {
        return &Account::balance;
    }
    
    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;  // Annual interest rate in percentage
    
public:
    SavingsAccount(string n = "", long acc = 0, double bal = 0.0, double rate = 4.0)
        : Account(n, acc, bal), interestRate(rate) {}
    
    // Override calculateInterest
    double calculateInterest() override {
        double interest = balance * (interestRate / 100.0);
        cout << "\n--- Savings Account Interest ---\n";
        cout << "Interest Rate: " << interestRate << "%\n";
        cout << "Interest Amount: $" << interest << endl;
        return interest;
    }
    
    void applyInterest() {
        double interest = calculateInterest();
        balance += interest;
        cout << "Interest applied. New balance: $" << balance << endl;
    }
    
    void displayDetails() {
        Account::displayDetails();
        cout << "Account Type: Savings Account\n";
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

class CurrentAccount : public Account {
private:
    double minBalance;
    double penalty;
    
public:
    CurrentAccount(string n = "", long acc = 0, double bal = 0.0, 
                   double minBal = 1000.0, double pen = 50.0)
        : Account(n, acc, bal), minBalance(minBal), penalty(pen) {}
    
    // Override calculateInterest (no interest for current account)
    double calculateInterest() override {
        cout << "\n--- Current Account Interest ---\n";
        cout << "No interest for Current Account\n";
        
        // Check for penalty if below minimum balance
        if (balance < minBalance) {
            cout << "Balance below minimum ($" << minBalance << ")\n";
            cout << "Penalty charged: $" << penalty << endl;
            balance -= penalty;
            return -penalty;
        }
        return 0.0;
    }
    
    void displayDetails() {
        Account::displayDetails();
        cout << "Account Type: Current Account\n";
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Penalty (if below min): $" << penalty << endl;
    }
};

int main() {
    cout << "=== Banking System ===\n\n";
    
    // Pointer to Object - dynamically create account objects
    SavingsAccount* savings = new SavingsAccount("Alice Johnson", 1001, 5000.0, 5.0);
    CurrentAccount* current = new CurrentAccount("Bob Smith", 2001, 800.0, 1000.0, 50.0);
    
    cout << "--- Initial Account Details ---\n";
    savings->displayDetails();
    current->displayDetails();
    
    // Pointer to Function - storing function addresses
    cout << "\n\n=== Pointer to Function Demo ===\n";
    void (Account::*depositFunc)(double) = &Account::deposit;
    void (Account::*withdrawFunc)(double) = &Account::withdraw;
    void (Account::*displayBalFunc)() = &Account::displayBalance;
    
    cout << "Calling deposit through function pointer on Savings Account:\n";
    (savings->*depositFunc)(1000.0);
    
    cout << "\nCalling withdraw through function pointer on Savings Account:\n";
    (savings->*withdrawFunc)(500.0);
    
    cout << "\nCalling displayBalance through function pointer:\n";
    (savings->*displayBalFunc)();
    
    // Pointer to Data Member - accessing and modifying balance
    cout << "\n\n=== Pointer to Data Member Demo ===\n";
    double Account::*balancePtr = Account::getBalancePointer();
    
    cout << "Accessing balance through pointer to data member:\n";
    cout << "Savings Account balance: $" << savings->*balancePtr << endl;
    cout << "Current Account balance: $" << current->*balancePtr << endl;
    
    cout << "\nModifying balance through pointer to data member:\n";
    savings->*balancePtr += 500.0;
    cout << "Added $500 to savings. New balance: $" << savings->*balancePtr << endl;
    
    // this Pointer demonstration
    cout << "\n\n=== this Pointer Demo ===\n";
    Account* thisPtr = savings->getThis();
    cout << "Address returned by getThis(): " << thisPtr << endl;
    cout << "Address of savings object: " << savings << endl;
    cout << "Addresses match: " << (thisPtr == savings ? "Yes" : "No") << endl;
    
    // Runtime Polymorphism - calling through base class pointer
    cout << "\n\n=== Runtime Polymorphism Demo ===\n";
    cout << "Calling calculateInterest() through base class pointer:\n";
    
    Account* accounts[2];
    accounts[0] = savings;
    accounts[1] = current;
    
    for (int i = 0; i < 2; i++) {
        cout << "\nAccount " << i + 1 << ":\n";
        double interest = accounts[i]->calculateInterest();
        accounts[i]->displayBalance();
    }
    
    // Virtual Function - demonstrating polymorphic behavior
    cout << "\n\n=== Virtual Function Demonstration ===\n";
    Account* ptr;
    
    ptr = savings;
    cout << "Base pointer -> Savings Account:\n";
    ptr->calculateInterest();  // Calls SavingsAccount version
    
    ptr = current;
    cout << "\nBase pointer -> Current Account:\n";
    ptr->calculateInterest();  // Calls CurrentAccount version
    
    // Operations menu
    cout << "\n\n=== Banking Operations ===\n";
    int choice;
    do {
        cout << "\n1. Deposit to Savings\n";
        cout << "2. Withdraw from Savings\n";
        cout << "3. Display Savings Balance\n";
        cout << "4. Apply Interest to Savings\n";
        cout << "5. Display Current Account Details\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        double amount;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                (savings->*depositFunc)(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                (savings->*withdrawFunc)(amount);
                break;
            case 3:
                (savings->*displayBalFunc)();
                break;
            case 4:
                savings->applyInterest();
                break;
            case 5:
                current->displayDetails();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    
    // Final account details
    cout << "\n\n=== Final Account Details ===\n";
    savings->displayDetails();
    current->displayDetails();
    
    // Cleanup
    delete savings;
    delete current;
    
    cout << "\n\nThank you for using our Banking System!\n";
    
    return 0;
}
