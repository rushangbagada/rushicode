// Write a function power() to raise a number m to a power n. The function takes a double value for m and integer value for 
// n,  and  returns  the  result  correctly.  Use  a  default  value  of  2  for  n  to  make  the  function  to  calculate  square  when  this 
// argument is omitted. Write a main function that gets the values of m and n from the user to test the function. Use the 
// concept of function overloading.

#include <iostream>
#include <string>
using namespace std;


double power(double m, int n = 2) {
	double result = 1;
	for (int i = 0; i < n; ++i) {
		result *= m;
	}
	return result;
}


int power(int m, int n = 2) {
	int result = 1;
	for (int i = 0; i < n; ++i) {
		result *= m;
	}
	return result;
}

int main() {
	double m;
	int n;
	cout << "Enter the base (m): ";
	cin >> m;
	cout << "Enter the exponent (n, or press Enter for square): ";
	string input;
	getline(cin >> ws, input);
	if (input.empty()) {
		cout << "Result (square): " << power(m) << endl;
	} else {
		n = stoi(input);
		cout << "Result: " << power(m, n) << endl;
	}

	
	int mi = 3;
	cout << "\nDemo: int power(" << mi << ", 4) = " << power(mi, 4) << endl;
	cout << "Demo: int power(" << mi << ") = " << power(mi) << endl;

	return 0;
}