// Write a C++ program to create two classes, ClassA and ClassB, each having a private integer member. Write a friend
// function add() that:
// ● Takes objects of both classes as arguments.
// ● Accesses their private data.
// ● Returns the sum of the two numbers.

#include <iostream>
using namespace std;

class ClassB; 

class ClassA {
	int numA;
public:
	ClassA(int a) : numA(a) {}
	friend int add(const ClassA&, const ClassB&);
};

class ClassB {
	int numB;
public:
	ClassB(int b) : numB(b) {}
	friend int add(const ClassA&, const ClassB&);
};

int add(const ClassA& a, const ClassB& b) {
	return a.numA + b.numB;
}

int main() {
	ClassA objA(10);
	ClassB objB(20);
	cout << "Sum: " << add(objA, objB) << endl;
	return 0;
}

