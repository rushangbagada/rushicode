// Write a C++ program to calculate the area of a circle using an area function where radius is a
// private and area function is a public member of a class circle.


#include<bits/stdc++.h>
using namespace std;


class circle{
private:
    float radius;
public:
    circle(float r){
        radius = r;
    }
    float area(){
        return 3.14*radius*radius;
    }
};


int main(){
    circle c(5.0);
    cout << "Area of the circle with radius " << 5.0 << " is " << c.area() << endl;
    return 0;
}