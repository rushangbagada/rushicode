// Write a C++ program : Digital Wallet Transfer       Create a class DigitalWallet with: 
// • walletID (int), ownerName (string), and balance (double). 
// Requirements: 
// • Use default and parameterized constructors. 
// • Write  a  friend  function  sendMoney(DigitalWallet  &sender,  DigitalWallet  &receiver,  double  amount)  that 
// transfers money from one wallet to another and returns the updated sender wallet object. 
// • Use a const member function showBalance() to display wallet details. 
// • Ensure balance cannot go negative (print an error if funds are insufficient). 
//  Sample Input :  
// Wallet1: 201, Alex, 1200   
// Wallet2: 202, Sam, 800   
// Transfer 500 from Alex to Sam  
// Sample Output :  
// After Transfer:   
// Alex: Balance = 700   
// Sam: Balance = 130
#include <bits/stdc++.h>

using namespace std;

class DigitalWallet {
	int walletID;
	string ownerName;
	double balance;
public:

	DigitalWallet()  {
        walletID=0;
         ownerName="";
         balance=0.0;
    }

	
	DigitalWallet(int id, string name, double bal) { 
        walletID = id;
        ownerName = name;
        balance = bal;
    }

	
	friend DigitalWallet& sendMoney(DigitalWallet &sender, DigitalWallet &receiver, double amount);

	void showBalance() const {
		cout << ownerName << ": Balance = " << balance << endl;
	}

	
	string getOwnerName() const { return ownerName; }
};

DigitalWallet& sendMoney(DigitalWallet &sender, DigitalWallet &receiver, double amount) {
	if (amount > sender.balance) {
		cout << "Error: Insufficient funds in " << sender.ownerName << "'s wallet!" << endl;
	} else {
		sender.balance -= amount;
		receiver.balance += amount;
	}
	return sender;
}

int main() {
	
	DigitalWallet wallet1(201, "Alex", 1200);
	DigitalWallet wallet2(202, "Sam", 800);

	
	sendMoney(wallet1, wallet2, 500);

	cout << "After Transfer: " << endl;
	wallet1.showBalance();
	wallet2.showBalance();

	return 0;
}

