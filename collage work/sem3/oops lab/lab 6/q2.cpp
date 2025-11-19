//  Create a class BankAccount where each object stores balance, and a static data 
// member   stores interestRate. Write a static function to change the interest rate 
// for all accounts..

#include <iostream>
using namespace std;

class BankAccount {
    double balance;
    static double interestRate; 

public:
    BankAccount(double bal) {
        balance = bal;
    }

    double getBalance() const { return balance; }

    static void setInterestRate(double rate) { 
        interestRate = rate;
    }

    static double getInterestRate() { 
        return interestRate;
    }


    void addInterest() {
        balance += balance * interestRate / 100.0;
    }
};


double BankAccount::interestRate = 5.0; 

int main() {
    BankAccount acc1(1000), acc2(2000);

    cout << "Initial interest rate: " << BankAccount::getInterestRate() << "%\n";
    acc1.addInterest();
    acc2.addInterest();
    cout << "Balance after interest:\n";
    cout << "Account 1: " << acc1.getBalance() << endl;
    cout << "Account 2: " << acc2.getBalance() << endl;

    BankAccount::setInterestRate(7.5); \
    cout << "New interest rate: " << BankAccount::getInterestRate() << "%\n";
}