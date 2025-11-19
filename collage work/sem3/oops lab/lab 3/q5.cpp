// Create a BankAccount class with attributes accountNumber, accountHolder, and balance.
// Implement methods to deposit and withdraw money. Ensure to display an appropriate message
// if a withdrawal amount exceeds the available balance.


#include <bits/stdc++.h>    
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string number, string holder, double initialBalance) {
        accountNumber = number;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit of $" << amount << " successful. New balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Withdrawal of $" << amount << " failed. Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << endl;
        }
    }
};

int main() {
    BankAccount account("123456789", "rushang", 1000.0);

    account.deposit(500.0);
    account.withdraw(200.0);
    account.withdraw(1500.0);

    return 0;
}
 