//  Write a C++ program to overload a function fun() as follows:
// ● Case 1: void fun(const int i)
//  void fun(int i)
// ● Case 2: void fun(char *a)
//  void fun(const char *a)


#include <iostream>
using namespace std;

// Case 1: const int by value and int by value
// void fun(const int i) {
//     cout << "fun(const int): " << i << endl;
// }

// void fun(int i) {
//     cout << "fun(int): " << i << endl;
// }

// Case 2: char* and const char*
void fun(char *a) {
    cout << "fun(char*): " << a << endl;
}

void fun(const char *a) {
    cout << "fun(const char*): " << a << endl;
}

int main() {
    int x = 10;
    const int y = 20;
    char str1[] = "Hello";
    const char *str2 = "World";

    // fun(x);         // Calls fun(int)
    // fun(y);         // Calls fun(const int&)
    fun(str1);      // Calls fun(char*)
    fun(str2);      // Calls fun(const char*)

    return 0;
}