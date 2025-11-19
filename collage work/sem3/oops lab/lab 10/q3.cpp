// Write a C++ program that performs the following: 
// ● Accept a single string input from the user. 
// ● Remove all duplicate characters from the string while preserving the order of first occurrences. 
// ● Display the modified string.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string output;
    for (char c : input) {
        if (output.find(c) == string::npos) {
            output += c;
        }
    }

    cout << "Modified string: " << output << endl;
    return 0;
}
