// Write a C++ program that takes two strings as input. Each string contains only unique   characters 
// (no character repeats within the same string). 
// ● Your task is : 
// A. Concatenate the two strings. 
// B. While concatenating, remove any characters that are common in both strings. 
// C. Print the modified concatenated string. 
// ● Example: 
//  Input:   
//        str1 = "abcd"  
//        str2 = "cdef"  
//  Output : "abef"

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    string result = "";
    for (char c : str2) {
        if (result.find(c) == string::npos) {
            result += c;
        }
    }
    for (char c : str1) {
        if (str2.find(c) == string::npos && result.find(c) == string::npos) {
            result += c;
        }
    }

    cout << "Concatenated string without common characters: " << result << endl;

    return 0;
}