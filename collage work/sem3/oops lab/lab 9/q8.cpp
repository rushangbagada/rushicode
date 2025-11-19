// Write a C++ program that asks the user to enter a sentence. Your program should: 
// a) Count the total number of vowels (a, e, i, o, u) in the sentence. 
// b) Count the total number of words in the sentence. 
// c) Count the total number of uppercase letters and lowercase letters in the sentence. 
// d) Replace all spaces with - (hyphen) and display the modified sentence

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);
    int vowel_count = 0;
    int word_count = 1; 
    int uppercase_count = 0;
    int lowercase_count = 0;
    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowel_count++;
        } else if (c == ' ') {
            word_count++;
        } else if (c >= 'A' && c <= 'Z') {
            uppercase_count++;
        } else if (c >= 'a' && c <= 'z') {
            lowercase_count++;
        }
    }
    cout << "Total vowels: " << vowel_count << endl;
    cout << "Total words: " << word_count << endl;
    cout << "Total uppercase letters: " << uppercase_count << endl;
    cout << "Total lowercase letters: " << lowercase_count << endl;

    // Replace spaces with hyphens
    replace(str.begin(), str.end(), ' ', '-');
    cout << "Modified sentence: " << str << endl;

    return 0;
}