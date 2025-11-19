// Write a C++ program finding maximum and minimum numbers in an array using dynamic
// memory allocation.




#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i]; 
        if (arr[i] < min) min = arr[i];
    }

    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;

    free(arr);
    return 0;
}
