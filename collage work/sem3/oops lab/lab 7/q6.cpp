// Library  Book  ManagementCreate  a  class  LibraryBook  to  manage  books 
// dynamically in a digital library system. 
// Create a class LibraryBook to manage books dynamically in a digital library system. 
// Context: 
// In  a  university’s  e-library,  book  records  are  managed  using  pointers.  Improper 
// memory handling (like dangling, wild, or null pointers) may lead to incorrect access 
// of book details or even crashes. 
// Requirements: 
// ●  Provide  default  and  parameterized  constructors  to  initialize  book  title  (string)  and 
// price (double). 
// ●  Use a wild pointer to demonstrate uninitialized access to a book object, and later fix 
// it by initializing it with nullptr. 
// ●  Demonstrate  a  null pointer  case where a pointer is explicitly set to nullptr before 
// checking for safe access. 
// ●  Use a void pointer to point to both book title and book price, then cast it properly 
// when retrieving values. 
// ●  Show a dangling pointer scenario by deleting a book object but still trying to access 
// it, then fix it by assigning nullptr. 
// ●  Apply new to dynamically allocate memory for a book, and delete to safely release it. 
// ●  Add a const member function display() to show book details safely. 
// Sample Input: 
 
// LibraryBook *b1 = new LibraryBook("C++ Basics", 499.0); 
// b1->display(); 
 
// LibraryBook *b2; // Wild pointer (uninitialized) 
// b2->display();   // unsafe → fix by initializing nullptr 
 
// void* vp; 
// vp = b1; // pointing to object 
// // cast and access details 
 
// delete b1;  // Dangling pointer now 
// b1->display(); // unsafe → fix by setting b1 = nullptr 
 
// Output: 
// Book Title: C++ Basics, Price: 499 
// Error: Wild pointer accessed before initialization! 
// Error: Null pointer detected, cannot display book details. 
// Book details accessed using void pointer → Title: C++ Basics 
// Error: Dangling pointer! Book memory already released.


#include <iostream>
#include <string>

using namespace std;  
class LibraryBook {
private:
    string title;
    double price;

public:
    
    LibraryBook() {
        title = "Unknown";
        price = 0.0;
    }

   
    LibraryBook(const string& t, double p)  {
        title = t;
        price = p;
    }

    
    void display() const {
        cout << "Book Title: " << title
             << ", Price: " << price << endl;
    }
};

int main() {
 
    LibraryBook* b1 = new LibraryBook("C++ Basics", 499.0);
    b1->display();

   
    LibraryBook* b2;      
    cout << "\n-- Wild Pointer Demo --" << endl;
  
    
    cout << "Error: Wild pointer accessed before initialization!" << endl;

    // Fix by initializing to nullptr
    b2 = nullptr;
    if (b2 == nullptr) {
        cout << "Error: Null pointer detected, cannot display book details." << endl;
    }

    // 3️ Void pointer usage
    cout << "\n-- Void Pointer Demo --" << endl;
    void* vp;
    vp = b1;
    static_cast<LibraryBook*>(vp)->display();

    // Simple meaningful example: void* to a primitive type (price)
    double priceVal = 499.0;
    vp = &priceVal;
    cout << "Book details accessed using void pointer → Price: "
         << *static_cast<double*>(vp) << endl;

    // 4️ Dangling pointer scenario
    cout << "\n-- Dangling Pointer Demo --" << endl;
    delete b1;  
    // b1->display();
    cout << "Error: Dangling pointer! Book memory already released." << endl;

    // Fix by assigning nullptr
    b1 = nullptr;
    if (b1 == nullptr) {
        cout << "Pointer reset to nullptr to avoid dangling access." << endl;
    }

    return 0;
}
