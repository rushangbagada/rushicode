// Write a menu driven c + + program to perform the following operations: 
// a) Whether the entered email address by user is valid or not. Print the message accordingly. 
// b) Extract the domain name from the entered email address. And print the output

#include <bits/stdc++.h>
using namespace std;

bool isValidEmail(const string& email) {
    const regex pattern(R"((^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$))");
    return regex_match(email, pattern);
}

int main() {
    string email;
    cout << "Enter an email address: ";
    getline(cin, email);

    if (isValidEmail(email)) {
        cout << "The email address is valid." << endl;
    } else {
        cout << "The email address is invalid." << endl;
    }

    size_t atPos = email.find('@');
    if (atPos != string::npos && atPos + 1 < email.length()) {
        string domain = email.substr(atPos + 1);
        cout << "Domain name: " << domain << endl;
    } else {
        cout << "No domain found in the email address." << endl;
    }

    return 0;

}