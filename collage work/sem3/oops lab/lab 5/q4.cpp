
#include <iostream>
using namespace std;


int area(int side) {
	return side * side;
}

int area(int length, int breadth) {
	return length * breadth;
}


double area(double radius) {
	return 3.14159 * radius * radius;
}

int main() {
	int side = 4;
	int length = 5, breadth = 3;
	double radius = 2.5;

	cout << "Area of square: " << area(side) << endl;
	cout << "Area of rectangle: " << area(length, breadth) << endl;
	cout << "Area of circle: " << area(radius) << endl;

	return 0;
}