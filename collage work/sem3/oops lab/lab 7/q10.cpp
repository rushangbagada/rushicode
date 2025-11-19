// Wild Pointer in Dynamic Matrix Allocation 
// Write a class Matrix that manages a 2D matrix with dynamic allocation using  
// double pointers (int**). 
// • Constructor should allocate memory for rows and columns. 
// • If pointers are not initialized properly (wild pointer case), accessing elements leads  
//   to undefined behavior. 
// • Add proper initialization to nullptr and allocate safely with new. 
// • Add methods: 
//   - void set(int r, int c, int val) 
//   - int get(int r, int c) 
// • In main(), demonstrate: 
//   - The effect of using wild pointers (uninitialized int**). 
//   - The corrected version with safe initialization. 
// (Concepts: wild pointer, multi-level pointer allocation, memory safety) 
 
   
#include<bits/stdc++.h>
using namespace std;

class Matrix {
    int** matrix;
    int rows, cols;
public:
    Matrix(int r, int c){
        rows = r;
        cols = c;
        matrix = new int*[rows];
        for(int i = 0; i < rows; i++){
            matrix[i] = new int[cols];
        }
    }
    void set(int r, int c, int val){
        matrix[r][c] = val;
    }
    int get(int r, int c){
        return matrix[r][c];
    }
    ~Matrix(){
        for(int i = 0; i < rows; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix matrix(3, 2);
    matrix.set(0, 0, 1);
    matrix.set(0, 1, 2);
    matrix.set(1, 0, 3);
    matrix.set(1, 1, 4);
    matrix.set(2, 0, 5);
    matrix.set(2, 1, 6);
    matrix.display();
    return 0;
    }