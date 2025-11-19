// Write a C++ program to check if an entered password is valid. 
// ●  Minimum 8 characters. 
// ● At least 1 uppercase letter. 
// ● At least 1 lowercase letter. 
// ● At least 1 digit. 
// ● At least 1 special character (@, #, $, %, &, *). 
// Output should say "Strong Password" or "Weak Password" accordingly

#include <bits/stdc++.h>
using namespace std;

int main() {
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
    string specialChars = "@#$%&*";

    for(char c : password) {
        if(isupper(c)) hasUpper = true;
        else if(islower(c)) hasLower = true;
        else if(isdigit(c)) hasDigit = true;
        else if(specialChars.find(c) != string::npos) hasSpecial = true;
    }

    if(password.length() >= 8 && hasUpper && hasLower && hasDigit && hasSpecial) {
        cout << "Strong Password" << endl;
    } else {
        cout << "Weak Password" << endl;
    }

    return 0;
}