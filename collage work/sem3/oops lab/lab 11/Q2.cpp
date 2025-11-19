//  Password Strength Checker
// Create a C++ program that checks the strength of a given password. A password is strong if
// it:
// - Has at least 8 characters.
// - Contains at least one uppercase letter, one lowercase letter, one digit, and one special
// character.



#include <bits/stdc++.h>
using namespace std;


bool isStrongPassword(const string &pw) {
    if (pw.size() < 8) return false;
    bool hasUpper=false, hasLower=false, hasDigit=false, hasSpecial=false;
    for(char c: pw) {
        if (isupper((unsigned char)c)) hasUpper = true;
        else if (islower((unsigned char)c)) hasLower = true;
        else if (isdigit((unsigned char)c)) hasDigit = true;
        else hasSpecial = true;
    }
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    string password;
    cout << "Enter password: ";
    getline(cin, password);
    if(isStrongPassword(password)) cout << "Strong password\n";
    else cout << "Weak password\n";
    return 0;
}