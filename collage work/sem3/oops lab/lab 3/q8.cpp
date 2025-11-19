// . Create a class Distance Converter that uses function overloading to convert distances:
// ● From kilometers to meters: convert(float kilometers)
// ● From meters to centimeters: convert(int meters)
// ● From miles to kilometers: convert(double miles, char unit)
// Each overloaded function should return the converted distance.


#include <bits/stdc++.h>
using namespace std;

class DistanceConverter {
public:
    float convert(float kilometers) {
        return kilometers * 1000; 
    }

    int convert(int meters) {
        return meters * 100; 
    }

    
    double convert(double miles, char unit) {
        if (unit == 'k') {
            return miles * 1.609344;
        } else {
            return miles * 1609.34; 
        }
    }
};

int main() {
    DistanceConverter converter;

    float kilometers = 10.5f;
    cout << "Distance in kilometers: " << kilometers << endl;
    cout << "Distance in meters: " << converter.convert(kilometers) << endl;

    int meters = 1500;
    cout << "Distance in meters: " << meters << endl;
    cout << "Distance in centimeters: " << converter.convert(meters) << endl;

    double miles = 2.5;
    char unit = 'k';
    cout << "Distance in miles: " << miles << endl;
    cout << "Distance in kilometers: " << converter.convert(miles, unit) << endl;

    return 0;
}