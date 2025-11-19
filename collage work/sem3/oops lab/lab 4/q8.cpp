// 8. Write a C++ program solving a Tower of Hanoi Problem using a recursive 
// function. 


#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << target << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, target);
    cout << "Move disk " << n << " from " << source << " to " << target << endl;
    towerOfHanoi(n - 1, auxiliary, target, source);
}

int main() {
    int n = 3; 
    towerOfHanoi(n, 'A', 'C', 'B');  
    return 0;
}