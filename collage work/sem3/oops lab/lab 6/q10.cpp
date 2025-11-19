//  Dynamic Array Average Calculator 
// Use calloc() to allocate memory for n floating-point numbers 
// Calculate and print the average 
// Free memory after use 
 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

   
    float* arr = (float*)calloc(n, sizeof(float));
    if (arr == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return 1;
    }

    cout << "Enter " << n << " floating-point numbers:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    float average = sum / n;

    cout << "Average: " << average << endl;
    free(arr);
    return 0;
}
