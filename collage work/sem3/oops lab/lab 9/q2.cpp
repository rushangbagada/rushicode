#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string Emp_name, Address, Mail_id;
    int Emp_id;
    long long Mobile_no;
public:
    void getDetails() {
        cout << "Enter Employee Name: ";
        getline(cin, Emp_name);
        cout << "Enter Employee ID: ";
        cin >> Emp_id;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, Address);
        cout << "Enter Mail ID: ";
        getline(cin, Mail_id);
        cout << "Enter Mobile No: ";
        cin >> Mobile_no;
        cin.ignore();
    }
    void showDetails() {
        cout << "Employee Name: " << Emp_name << endl;
        cout << "Employee ID: " << Emp_id << endl;
        cout << "Address: " << Address << endl;
        cout << "Mail ID: " << Mail_id << endl;
        cout << "Mobile No: " << Mobile_no << endl;
    }
};

class Programmer : public Employee {
protected:
    double BP;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay for Programmer: ";
        cin >> BP;
        cin.ignore();
    }
    void generatePaySlip() {
        double DA = 0.97 * BP;
        double HRA = 0.10 * BP;
        double PF = 0.12 * BP;
        double staffClub = 0.001 * BP;
        double gross = BP + DA + HRA;
        double net = gross - PF - staffClub;
        cout << "\n--- Programmer Pay Slip ---\n";
        showDetails();
        cout << "Basic Pay: " << BP << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << staffClub << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

class AssistantProfessor : public Employee {
protected:
    double BP;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay for Assistant Professor: ";
        cin >> BP;
        cin.ignore();
    }
    void generatePaySlip() {
        double DA = 0.97 * BP;
        double HRA = 0.10 * BP;
        double PF = 0.12 * BP;
        double staffClub = 0.001 * BP;
        double gross = BP + DA + HRA;
        double net = gross - PF - staffClub;
        cout << "\n--- Assistant Professor Pay Slip ---\n";
        showDetails();
        cout << "Basic Pay: " << BP << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << staffClub << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

class AssociateProfessor : public Employee {
protected:
    double BP;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay for Associate Professor: ";
        cin >> BP;
        cin.ignore();
    }
    void generatePaySlip() {
        double DA = 0.97 * BP;
        double HRA = 0.10 * BP;
        double PF = 0.12 * BP;
        double staffClub = 0.001 * BP;
        double gross = BP + DA + HRA;
        double net = gross - PF - staffClub;
        cout << "\n--- Associate Professor Pay Slip ---\n";
        showDetails();
        cout << "Basic Pay: " << BP << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << staffClub << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

class Professor : public Employee {
protected:
    double BP;
public:
    void getPayDetails() {
        cout << "Enter Basic Pay for Professor: ";
        cin >> BP;
        cin.ignore();
    }
    void generatePaySlip() {
        double DA = 0.97 * BP;
        double HRA = 0.10 * BP;
        double PF = 0.12 * BP;
        double staffClub = 0.001 * BP;
        double gross = BP + DA + HRA;
        double net = gross - PF - staffClub;
        cout << "\n--- Professor Pay Slip ---\n";
        showDetails();
        cout << "Basic Pay: " << BP << endl;
        cout << "DA: " << DA << endl;
        cout << "HRA: " << HRA << endl;
        cout << "PF: " << PF << endl;
        cout << "Staff Club Fund: " << staffClub << endl;
        cout << "Gross Salary: " << gross << endl;
        cout << "Net Salary: " << net << endl;
    }
};

int main() {
    int choice;
    cout << "Select Employee Type:\n1. Programmer\n2. Assistant Professor\n3. Associate Professor\n4. Professor\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        Programmer p;
        p.getDetails();
        p.getPayDetails();
        p.generatePaySlip();
    } else if (choice == 2) {
        AssistantProfessor ap;
        ap.getDetails();
        ap.getPayDetails();
        ap.generatePaySlip();
    } else if (choice == 3) {
        AssociateProfessor asp;
        asp.getDetails();
        asp.getPayDetails();
        asp.generatePaySlip();
    } else if (choice == 4) {
        Professor prof;
        prof.getDetails();
        prof.getPayDetails();
        prof.generatePaySlip();
    } else {
        cout << "Invalid choice!" << endl;
    }
    return 0;
}