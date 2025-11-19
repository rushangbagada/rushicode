// Create a class BankAccount with static member interestRate. Create an array of 
 
// objects for multiple customers. Write a function that accepts an object as an 
// argument and calculate interest.

#include <iostream>
using namespace std;

class BankAccount {
    double balance;
    static double interestRate; 

public:
    BankAccount(double bal = 0) : balance(bal) {}

    double getBalance() const { return balance; }

    static void setInterestRate(double rate) { interestRate = rate; }
    static double getInterestRate() { return interestRate; }

    friend double calculateInterest(const BankAccount& acc); 
};

double BankAccount::interestRate = 5.0; // default interest rate

double calculateInterest(const BankAccount& acc) {
    return acc.balance * BankAccount::interestRate / 100.0;
}

int main() {
    const int n = 3;
    BankAccount customers[n] = { BankAccount(1000), BankAccount(1500), BankAccount(2000) };

    BankAccount::setInterestRate(6.5); 

    for (int i = 0; i < n; ++i) {
        cout << "Customer " << i + 1 << " balance: " << customers[i].getBalance();
        cout << ", Interest: " << calculateInterest(customers[i]) << endl;
    }
    return 0;
}