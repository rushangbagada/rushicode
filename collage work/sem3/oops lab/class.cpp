// class template to display the values of two variables


// #include<bits/stdc++.h>
// using namespace std;

// class Display {
// public:
//     template <typename T1, typename T2>
//     void show(T1 a, T2 b) {
//         cout << "First value: " << a << endl;
//         cout << "Second value: " << b << endl;
//     }
// };

// int main(){
//     Display obj;
//     obj.show(5, 10);
//     return 0;
// }



#include <iostream>
using namespace std;


template <class T1, class T2>
class Printer {
    T1 var1;
    T2 var2;
public:

    Printer(T1 a, T2 b) {
        var1 = a;
        var2 = b;
    }

  
    void display() {
        cout << "First Variable: " << var1 << endl;
        cout << "Second Variable: " << var2 << endl;
    }
};


int main() {
    
    Printer<int, double> obj1(10, 25.5);
    Printer<string, char> obj2("Hello", 'A');

    cout << "Object 1 Output:\n";
    obj1.display();

    cout << "\nObject 2 Output:\n";
    obj2.display();

    return 0;
}
