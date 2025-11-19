// Username Generator 
// Write a C++ program that takes a person’s full name as input (e.g., Sameer Joshi) and 
// generates a username in the following format: 
// - Convert all characters to lowercase. 
// - The username should be: first three letters of the first name + last three letters of the 
// last name. 
// Eg: Input : Sameer Joshi 
//       Output : Samshi


#include<bits/stdc++.h>
using namespace std;


int main(){
    string fullName;
    cout << "Enter full name: ";
    getline(cin, fullName);

    // Convert to lowercase
    transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);

    // Split into first and last name
    string firstName = fullName.substr(0, fullName.find(" "));
    string lastName = fullName.substr(fullName.find(" ") + 1);

    // Generate username
    string username = firstName.substr(0, 3) + lastName.substr(lastName.length() - 3);
    cout << "Generated Username: " << username << endl;

    return 0;
}