// Write a program using function overloading to perform some arithmetic operations on different types of arguments

#include <bits/stdc++.h>
using namespace std;

// Addition
int add(int a, int b) {
	return a + b;
}
double add(double a, double b) {
	return a + b;
}
float add(float a, float b) {
	return a + b;
}


int multiply(int a, int b) {
	return a * b;
}
double multiply(double a, double b) {
	return a * b;
}
float multiply(float a, float b) {
	return a * b;
}

int main() {
	int a = 5, b = 3;
	double x = 2.5, y = 4.1;
	float p = 1.2f, q = 3.4f;

	cout << "Addition (int): " << add(a, b) << endl;
	cout << "Addition (double): " << add(x, y) << endl;
	cout << "Addition (float): " << add(p, q) << endl;

	cout << "Multiplication (int): " << multiply(a, b) << endl;
	cout << "Multiplication (double): " << multiply(x, y) << endl;
	cout << "Multiplication (float): " << multiply(p, q) << endl;

	return 0;
}

