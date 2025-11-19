// Q2: Function Template for Statistical Analysis
// Demonstrates: Function templates, array operations, iomanip

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

template <typename T>
void analyze(T arr[], int n) {
    // Calculate Mean
    T sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double mean = static_cast<double>(sum) / n;
    
    // Calculate Median
    T temp[n];
    for(int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    sort(temp, temp + n);
    
    double median;
    if(n % 2 == 0) {
        median = (temp[n/2 - 1] + temp[n/2]) / 2.0;
    } else {
        median = temp[n/2];
    }
    
    // Calculate Standard Deviation
    double variance = 0;
    for(int i = 0; i < n; i++) {
        variance += pow(arr[i] - mean, 2);
    }
    variance /= n;
    double stdDev = sqrt(variance);
    
    // Display results
    cout << fixed << setprecision(2);
    cout << "\n--- Statistical Analysis ---\n";
    cout << left << setw(25) << "Mean: " << right << setw(10) << mean << endl;
    cout << left << setw(25) << "Median: " << right << setw(10) << median << endl;
    cout << left << setw(25) << "Standard Deviation: " << right << setw(10) << stdDev << endl;
    cout << string(35, '-') << endl;
}

int main() {
    int choice;
    cout << "Select data type:\n";
    cout << "1. Integer\n";
    cout << "2. Float\n";
    cout << "3. Double\n";
    cout << "Enter choice: ";
    cin >> choice;
    
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    switch(choice) {
        case 1: {
            int arr[n];
            cout << "Enter " << n << " integer values:\n";
            for(int i = 0; i < n; i++) {
                cout << "Element " << (i+1) << ": ";
                cin >> arr[i];
            }
            analyze(arr, n);
            break;
        }
        case 2: {
            float arr[n];
            cout << "Enter " << n << " float values:\n";
            for(int i = 0; i < n; i++) {
                cout << "Element " << (i+1) << ": ";
                cin >> arr[i];
            }
            analyze(arr, n);
            break;
        }
        case 3: {
            double arr[n];
            cout << "Enter " << n << " double values:\n";
            for(int i = 0; i < n; i++) {
                cout << "Element " << (i+1) << ": ";
                cin >> arr[i];
            }
            analyze(arr, n);
            break;
        }
        default:
            cout << "Invalid choice!\n";
    }
    
    // Confirmation prompt using iostream functions
    char confirm;
    cout << "\nWant to analyze another dataset? (y/n): ";
    cin.get(); // Clear buffer
    confirm = cin.get();
    
    if(confirm == 'y' || confirm == 'Y') {
        cout << "Rerun the program!\n";
    } else {
        cout << "Thank you!\n";
    }
    
    return 0;
}
