// Develop a C++ program to manage the installation of CCTV cameras for a 
// security  company,  where  the  number  of  cameras  required  for  each  project 
// varies.  Use  dynamic  memory  allocation  to  handle  the  data  efficiently  for 
// storing information about CCTV cameras. 
// a.  Implement the programme in C-style (using malloc()/calloc()/free()). 
// i.  Create a Camera class with the following data members: model, 
// status and installation_area. 
// ii.  Prompt the user for the number of cameras and Camera details. 
// iii.  Dynamically allocate the memory (using an appropriate function 
// or operator) for an array of Camera objects. 
 
 
// iv.  Create a function to display the details. 
// v.  Finally, deallocate the memory 
// b.  Implement  the  previous  programme  using  C++  operators  (new  and 
// delete) 
// c.  Expand  the  previous  C-style  programme  to  add  additional  CCTV 
// cameras using realloc() to efficiently resize the memory. Prompt for an 
// additional number of cameras and it’s details from the user.


#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Camera {
public:
    char model[50];
    char status[20];
    char installation_area[50];
};

void displayCameras(Camera* arr, int n) {
    cout << "\nCamera Details:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Camera " << i + 1 << ": Model: " << arr[i].model
             << ", Status: " << arr[i].status
             << ", Area: " << arr[i].installation_area << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of cameras: ";
    cin >> n;
    Camera* arr = (Camera*)malloc(n * sizeof(Camera)); 

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for camera " << i + 1 << ":\n";
        cout << "Model: "; cin >> arr[i].model;
        cout << "Status: "; cin >> arr[i].status;
        cout << "Installation Area: "; cin >> arr[i].installation_area;
    }

    displayCameras(arr, n);

    free(arr); 
    return 0;
}




// #include <iostream>
// using namespace std;

// class Camera {
// public:
//     string model, status, installation_area;
// };

// void displayCameras(Camera* arr, int n) {
//     cout << "\nCamera Details:\n";
//     for (int i = 0; i < n; ++i) {
//         cout << "Camera " << i + 1 << ": Model: " << arr[i].model
//              << ", Status: " << arr[i].status
//              << ", Area: " << arr[i].installation_area << endl;
//     }
// }

// int main() {
//     int n;
//     cout << "Enter number of cameras: ";
//     cin >> n;
//     Camera* arr = new Camera[n]; 

//     for (int i = 0; i < n; ++i) {
//         cout << "Enter details for camera " << i + 1 << ":\n";
//         cout << "Model: "; cin >> arr[i].model;
//         cout << "Status: "; cin >> arr[i].status;
//         cout << "Installation Area: "; cin >> arr[i].installation_area;
//     }

//     displayCameras(arr, n);

//     delete[] arr; 
//     return 0;
// }