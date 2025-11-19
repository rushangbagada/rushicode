// Design a class GradeCalculator with overloaded functions calculateGrade() that return the
// grade of a student based on:
// ● Percentage marks (float)
// ● Marks out of 100 (int)
// ● Marks in 5 subjects (int, int, int, int, int)
// Use simple grading logic:
// A: 90–100, B: 80–89, C: 70–79, D: 60–69, F: <60

#include <bits/stdc++.h>
using namespace std;

class GradeCalculator {
public:
    char calculateGrade(float percentage) {
        if (percentage >= 90) return 'A';
        else if (percentage >= 80) return 'B';
        else if (percentage >= 70) return 'C';
        else if (percentage >= 60) return 'D';
        else return 'F';
    }

    char calculateGrade(int marksOutOf100) {
        return calculateGrade(static_cast<float>(marksOutOf100));
    }

    char calculateGrade(int sub1, int sub2, int sub3, int sub4, int sub5) {
        float percentage = (sub1 + sub2 + sub3 + sub4 + sub5) / 5.0;
        return calculateGrade(percentage);
    }
};
int main() {
    GradeCalculator gc;

    cout << "Grade based on percentage 85.5: " << gc.calculateGrade(85.5f) << endl;
    cout << "Grade based on marks out of 100 (75): " << gc.calculateGrade(75) << endl;
    cout << "Grade based on marks in 5 subjects (80, 90, 70, 60, 50): "
         << gc.calculateGrade(80, 90, 70, 60, 50) << endl;

    return 0;
}