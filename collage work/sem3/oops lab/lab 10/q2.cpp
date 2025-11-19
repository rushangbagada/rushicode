// Write a menu-driven C++ program that does the following: 
// ● Ask the user to enter a sentence (single or multi-word string). 
// ● Count the frequency of each unique word (case-insensitive) in the sentence. 
// ● Display each word along with its frequency. 
#include <bits/stdc++.h>
using namespace std;

string toLowerCase(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void countWordFrequency() {
    string sentence;
    cout << "Enter a sentence: ";
    cin.ignore();
    getline(cin, sentence);
    
    map<string, int> wordCount;
    stringstream ss(sentence);
    string word;
    
    while (ss >> word) {
        // Remove punctuation from word
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        if (!word.empty()) {
            wordCount[toLowerCase(word)]++;
        }
    }
    
    cout << "\nWord Frequency:\n";
    cout << "----------------\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n=== Word Frequency Counter ===\n";
        cout << "1. Count word frequency\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                countWordFrequency();
                break;
            case 2:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 2);
    
    return 0;
}
