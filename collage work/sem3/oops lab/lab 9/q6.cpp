// Write a C++ program that takes a string as an input and check whether the string is palindrome or 
// not ? 
// ● A  palindrome  is  a  word,  phrase,  number,  or  sequence  of  characters  that  reads  the  same 
// backward as forward. 
// ● Example: madam , level. 
// a) First convert the string in lowercase. 
// b) Print “Palindrome” if true, otherwise print “Not a palindrome”.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);

    string reversed_str = lower_str;
    reverse(reversed_str.begin(), reversed_str.end());

    if (lower_str == reversed_str) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}