// Write a C++ program to access public members of a class, by using the (.)dot operator.
// These are members marked with a public access modifier.
// Example: Price of Car A1 = 10000
// Price of Bike A2 = 2000
// Number of Car available in showroom = 4
// Number of Bike available in showroom = 3

#include<bits/stdc++.h>
using namespace std;
  

class car{
public:
    int price;
    int number;

    car(int p, int n){
        price = p;
        number = n;
    }
    void display() {
        cout << "Price of Car  = " << price << endl;
        cout << "Number of Car available in showroom = " << number << endl;
    }
};

class bike{
public:
    int price;
    int number;

    bike(int p, int n) {
        price = p;
        number = n;
    }

    void display() {
        cout << "Price of Bike  = " << price << endl;
        cout << "Number of Bike available in showroom = " << number << endl;
    }

};


int main(){
    car A1(10000, 4);
    bike A2(2000, 3);
    A1.display();
    A2.display();
    return 0;
}