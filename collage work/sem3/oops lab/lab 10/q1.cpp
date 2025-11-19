// Write a C++ program that takes a full name in the format: 
// Firstname Middlename Surname 
// Convert the entire string so that the first letter of each word is uppercase and the rest lowercase. 
// Display the name in short form as Surname, F.M. (e.g., "Rahul Dev Sharma" → "Sharma, R.D."). 
#include <iostream>
using namespace std;

int main() {
    string fullName;
    cout << "Enter full name (Firstname Middlename Surname): ";
    getline(cin, fullName);
    // Convert to proper case
    bool newWord = true;
    for (size_t i = 0; i < fullName.length(); ++i) {
        if (isspace(fullName[i])) {
            newWord = true;
        } else {
            if (newWord) {
                fullName[i] = toupper(fullName[i]);
                newWord = false;
            } else {
                fullName[i] = tolower(fullName[i]);
            }
        }
    }
    // Display the name in short form
    cout << "Short form: " << fullName.substr(fullName.find_last_of(" ") + 1) << ", ";
    cout << fullName[0] << "." << fullName[fullName.find(" ") + 1] << "." << endl;

    return 0;
}
