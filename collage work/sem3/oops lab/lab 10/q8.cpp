// Create two base classes: 
// ● Teacher → with protected data members: 
// ○ subject (string) 
// ○ experience (int) 
// ● Researcher → with protected data members: 
// ○ researchArea (string) 
// ○ publications (int) 
// Create a derived class Professor that inherits publicly from both Teacher and Researcher.   
                                                 
// The Teacher and Researcher classes should each have a constructor to initialize their data members. 
//  i). The Professor class should have an additional private data member:  
// name (string) 
// ii). The Professor constructor should initialize all data members from both base         classes 
// and its own. 
//  iii). Create a displayProfessor() function that prints: 
//       The professor’s name 
//       Teaching subject and experience 
//           Research area and number of publications 
//  iv) In main(), create an object of Professor, initialize it, and display all details.
// Create two base classes: 
// ● Teacher → with protected data members: 
// ○ subject (string) 
// ○ experience (int) 
// ● Researcher → with protected data members: 
// ○ researchArea (string) 
// ○ publications (int) 
// Create a derived class Professor that inherits publicly from both Teacher and Researcher.   
                                                 
// The Teacher and Researcher classes should each have a constructor to initialize their data members. 
//  i). The Professor class should have an additional private data member:  
// name (string) 
// ii). The Professor constructor should initialize all data members from both base         classes 
// and its own. 
//  iii). Create a displayProfessor() function that prints: 
//       The professor's name 
//       Teaching subject and experience 
//           Research area and number of publications 
//  iv) In main(), create an object of Professor, initialize it, and display all details.

#include <iostream>
#include <string>
using namespace std;

class Teacher {
protected:
    string subject;
    int experience;

public:
    Teacher(string sub, int exp) : subject(sub), experience(exp) {}
};

class Researcher {
protected:
    string researchArea;
    int publications;

public:
    Researcher(string area, int pubs) : researchArea(area), publications(pubs) {}
};

class Professor : public Teacher, public Researcher {
private:
    string name;

public:
    Professor(string n, string sub, int exp, string area, int pubs) 
        : Teacher(sub, exp), Researcher(area, pubs), name(n) {}

    void displayProfessor() {
        cout << "=== Professor Details ===" << endl;
        cout << "Name: " << name << endl;
        cout << "\nTeaching Information:" << endl;
        cout << "Subject: " << subject << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "\nResearch Information:" << endl;
        cout << "Research Area: " << researchArea << endl;
        cout << "Publications: " << publications << endl;
    }
};

int main() {
    string name, subject, researchArea;
    int experience, publications;

    cout << "Enter Professor's name: ";
    getline(cin, name);
    
    cout << "Enter teaching subject: ";
    getline(cin, subject);
    
    cout << "Enter years of experience: ";
    cin >> experience;
    cin.ignore();
    
    cout << "Enter research area: ";
    getline(cin, researchArea);
    
    cout << "Enter number of publications: ";
    cin >> publications;

    Professor prof(name, subject, experience, researchArea, publications);
    
    cout << "\n";
    prof.displayProfessor();

    return 0;
}
