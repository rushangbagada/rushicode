// Write a menu-driven C++ program that performs various string manipulation operations using the 
// std::string  class.  The  program  should  display  a  menu  to  the  user  with  options  to  perform  the 
// following operations: 
// Students have to enter their full name.  
// Firstname_Middlename_Surname (First letter should be capital in each word) 
// ● Input and Display a String 
// ● Find the Length of a String 
// ● Convert a String to Uppercase 
// ● Reverse a String 
// ● Search for a Substring 
// ● Replace a Word in a String 
// ● Exit the Program


#include <bits/stdc++.h>
using namespace std;


string capitalizeWords(string str) {
    bool cap = true;
    for (int i = 0; i < str.size(); i++) {
        if (isspace(str[i])) {
            cap = true;  
        } else if (cap && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            cap = false;
        } else {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}

int main() {
    string str;
    int choice;

    cout << "Enter your full name (Firstname Middlename Surname): ";
    getline(cin, str);

    // Capitalize the name properly
    str = capitalizeWords(str);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Input and Display a String\n";
        cout << "2. Find the Length of a String\n";
        cout << "3. Convert a String to Uppercase\n";
        cout << "4. Reverse a String\n";
        cout << "5. Search for a Substring\n";
        cout << "6. Replace a Word in a String\n";
        cout << "7. Exit the Program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
            case 1:
                cout << "String: " << str << endl;
                break;

            case 2:
                cout << "Length of the string: " << str.length() << endl;
                break;

            case 3: {
                string upper_str = str;
                transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);
                cout << "Uppercase String: " << upper_str << endl;
                break;
            }

            case 4: {
                string rev_str = str;
                reverse(rev_str.begin(), rev_str.end());
                cout << "Reversed String: " << rev_str << endl;
                break;
            }

            case 5: {
                string substr;
                cout << "Enter the substring to search: ";
                getline(cin, substr);
                if (str.find(substr) != string::npos) {
                    cout << "Substring found!" << endl;
                } else {
                    cout << "Substring not found!" << endl;
                }
                break;
            }

            case 6: {
                string old_word, new_word;
                cout << "Enter the word to replace: ";
                getline(cin, old_word);
                cout << "Enter the new word: ";
                getline(cin, new_word);

                size_t pos = str.find(old_word);
                if (pos != string::npos) {
                    str.replace(pos, old_word.length(), new_word);
                    cout << "Updated String: " << str << endl;
                } else {
                    cout << "Word not found!" << endl;
                }
                break;
            }

            case 7:
                cout << "Exiting the program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
