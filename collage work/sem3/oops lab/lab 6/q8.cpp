// Hospital Management System (Patient Records) 
//    Create  a  system  where  the  hospital can store patient records dynamically. Each 
// patient     has: 
// ●  Name 
// ●  Age 
// ●  Disease 
// ●  ID number 
// Allow the user to: 
// ●  Add new patients dynamically 
// ●  Display all patient records 
// ●  Delete a patient by ID 

#include<bits/stdc++.h>
using namespace std;
struct patient{
    string name;
    int age;
    string disease;
    int id;
};

vector<patient> patients;

void addPatient() {
    patient p;
    cout << "Enter patient name: ";
    cin >> p.name;
    cout << "Enter patient age: ";
    cin >> p.age;
    cout << "Enter patient disease: ";
    cin >> p.disease;
    cout << "Enter patient ID: ";
    cin >> p.id;
    patients.push_back(p);
    cout << "Patient added successfully!\n";
}

void displayPatients() {
    if (patients.empty()) {
        cout << "No patient records found.\n";
        return;
    }
    cout << "\n--- Patient Records ---\n";
    for (const auto& p : patients) {
        cout << "Name: " << p.name << ", Age: " << p.age
             << ", Disease: " << p.disease << ", ID: " << p.id << endl;
    }
}

void deletePatient() {
    int id;
    cout << "Enter patient ID to delete: ";
    cin >> id;
    auto it = remove_if(patients.begin(), patients.end(),
                       [id](const patient& p) { return p.id == id; });
    if (it != patients.end()) {
        patients.erase(it, patients.end());
        cout << "Patient deleted successfully!\n";
    } else {
        cout << "Patient with ID " << id << " not found.\n";
    }
}

int main() {
    int choice;
    do {
      
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Delete Patient\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                deletePatient();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
