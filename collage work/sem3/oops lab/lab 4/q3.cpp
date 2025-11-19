// Write a C++ program to read a matrix of size m*n from the keyboard and display the same 
// on the screen using functions.  


#include <bits/stdc++.h>
using namespace std;

void readMatrix(int matrix[][10], int m, int n) {
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[][10], int m, int n) {
    cout << "Matrix elements are:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[10][10], m, n;

    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    readMatrix(matrix, m, n);
    displayMatrix(matrix, m, n);

    return 0;
}
