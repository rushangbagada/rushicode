//  Write a C++ program to display and calculate the sum of n numbers by using dynamic 
// memory allocation function.  

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    int sum = 0;

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The sum is: " << sum << endl;

   
    delete[] arr;

    return 0;
}