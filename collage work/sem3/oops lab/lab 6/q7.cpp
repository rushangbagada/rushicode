// Write a  program to store and manage student marks dynamically using malloc, 
// calloc, realloc, and free. The program should: 
// a.  Input the number of students and allocate memory using malloc. 
// b.  Input and display the marks. 
// c.  Allocate  memory  for  another  set  of  students  using  realloc and input 
// additional marks. 
// d.  Use calloc to initialize a pass/fail array. 
// e.  Display all marks and pass/fail status. 
 
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n1, n2, total_students;
    float *marks;
    int *pass_fail;
    
    cout << "Enter the number of students (initial): ";
    cin >> n1;
    
    marks = (float*)malloc(n1 * sizeof(float));
    if (marks == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    
  
    cout << "\nEnter marks for " << n1 << " students:" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> marks[i];
    }
    
    cout << "\nInitial marks:" << endl;
    for (int i = 0; i < n1; i++) {
        cout << "Student " << (i + 1) << ": " << fixed << setprecision(2) << marks[i] << endl;
    }
    
   
    cout << "\nEnter number of additional students: ";
    cin >> n2;
    
    total_students = n1 + n2;
    marks = (float*)realloc(marks, total_students * sizeof(float));
    if (marks == nullptr) {
        cout << "Memory reallocation failed!" << endl;
        return 1;
    }
    
    cout << "\nEnter marks for " << n2 << " additional students:" << endl;
    for (int i = n1; i < total_students; i++) {
        cout << "Student " << (i + 1) << ": ";
        cin >> marks[i];
    }
    
 
    pass_fail = (int*)calloc(total_students, sizeof(int));
    if (pass_fail == nullptr) {
        cout << "Memory allocation for pass/fail array failed!" << endl;
        free(marks);
        return 1;
    }
    
 
    const float PASS_MARK = 40.0;
    for (int i = 0; i < total_students; i++) {
        pass_fail[i] = (marks[i] >= PASS_MARK) ? 1 : 0;
    }
    

    cout << "\n--- Final Results ---" << endl;
    cout << left << setw(10) << "Student" << setw(10) << "Marks" << "Status" << endl;
    cout << "--------------------------------" << endl;
    
    for (int i = 0; i < total_students; i++) {
        cout << left << setw(10) << (i + 1) 
             << setw(10) << fixed << setprecision(2) << marks[i]
             << (pass_fail[i] ? "PASS" : "FAIL") << endl;
    }

   
    free(marks);
    free(pass_fail);
    cout << "\nMemory freed successfully!" << endl;
    
    return 0;
}

