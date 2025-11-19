// 5. An electricity board charges the following rates to discourage large consumption of 
// energy.  
// For the first 100 units -60P per unit  
// For next 200 units -80P per unit  
// Beyond 300 units -90P per unit  
// All users are charged a minimum of Rs. 50.00. If the total amount is more than Rs. 
// 300.00 then an additional surcharge of 15% is added. Write a program to read the name 
// of the user and number of units consumed and print out the charges with names.  


#include<bits/stdc++.h>
using namespace std;

int main() {
    string name;
    int units;
    float total;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter number of units consumed: ";
    cin >> units;

    if (units <= 100) {
        total = units * 0.60;
    } else if (units <= 300) {
        total = 100 * 0.60 + (units - 100) * 0.80;
    } else {
        total = 100 * 0.60 + 200 * 0.80 + (units - 300) * 0.90;
    }

    if (total < 50) {
        total = 50;
    } else if (total > 300) {
        total += total * 0.15;
    }

    cout << "Electricity charges for " << name << " are: Rs. " << total << endl;

    return 0;
}
