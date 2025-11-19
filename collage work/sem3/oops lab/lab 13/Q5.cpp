// Q5: Template-Based Statistics Analyzer
// Demonstrates: Class templates, function templates, manipulators

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Class template for Statistics
template <typename T>
class Statistics {
private:
    T* arr;
    int size;
    
public:
    Statistics(T a[], int n) : size(n) {
        arr = new T[size];
        for(int i = 0; i < size; i++) {
            arr[i] = a[i];
        }
    }
    
    ~Statistics() {
        delete[] arr;
    }
    
    T sum() {
        T total = 0;
        for(int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }
    
    double average() {
        return static_cast<double>(sum()) / size;
    }
    
    T maximum() {
        T max = arr[0];
        for(int i = 1; i < size; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
    
    void display() {
        cout << fixed << setprecision(2);
        cout << left << setw(20) << "Sum = " << sum() << endl;
        cout << left << setw(20) << "Average = " << average() << endl;
        cout << left << setw(20) << "Maximum = " << maximum() << endl;
    }
};

// Function template to compare two values
template <typename T>
T compareValues(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Integer array (student scores)
    int intArr[] = {78, 65, 92, 55};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "Integer Data (Student Scores):\n";
    cout << string(40, '-') << endl;
    Statistics<int> intStats(intArr, intSize);
    intStats.display();
    cout << endl;
    
    // Double array (product prices)
    double doubleArr[] = {199.99, 49.50, 274.26, 499.75};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    
    cout << "Double Data (Product Prices):\n";
    cout << string(40, '-') << endl;
    Statistics<double> doubleStats(doubleArr, doubleSize);
    doubleStats.display();
    cout << endl;
    
    // Comparing values
    int val1 = 25, val2 = 42;
    cout << "Comparing " << val1 << " and " << val2 
         << " → Greater value: " << compareValues(val1, val2) << endl;
    
    double dval1 = 45.67, dval2 = 32.89;
    cout << fixed << setprecision(2);
    cout << "Comparing " << dval1 << " and " << dval2 
         << " → Greater value: " << compareValues(dval1, dval2) << endl;
    
    return 0;
}
