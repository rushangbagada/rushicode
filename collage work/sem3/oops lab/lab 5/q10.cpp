// Write a C++ program to find average of two numbers and consider following cases:
// ● Case 1: Function with no argument and no return value- void avg()
// ● Case 2: Function with no argument but with return value- float avg()
// ● Case 3: Function with argument and but no return value- void avg(float, float)
// ●Case 4: Function with argument and return value- float avg(float, float)


#include <iostream>
using namespace std;


void avg() {
	float a, b;
	cout << "Enter two numbers (void avg()): ";
	cin >> a >> b;
	cout << "Average: " << (a + b) / 2 << endl;
}


float avg_ret() {
	float a, b;
	cout << "Enter two numbers (float avg()): ";
	cin >> a >> b;
	return (a + b) / 2;
}


void avg(float a, float b) {
	cout << "Average (void avg(float, float)): " << (a + b) / 2 << endl;
}


float avg_val(float a, float b) {
	return (a + b) / 2;
}

int main() {
	
	avg();

	float result = avg_ret();
	cout << "Average (float avg()): " << result << endl;


	avg(10, 20);


	float val = avg_val(15, 25);
	cout << "Average (float avg(float, float)): " << val << endl;

	return 0;
}

