// 10. Create a class Book with the following: 
// A. Data members: title, author, and price. 
// B.  A static data member totalBooks to keep track of the total number of books added. 
// A static member function showTotalBooks() to display the total number of books. 
// Write a program to demonstrate this by creating at least 4 Book objects, and show the details of each 
// book along with the total number of books created.


#include<bits/stdc++.h>
using namespace std;

class Book {
    string title;
    string author;
    float price;
    static int totalBooks;

public:
    Book(string t, string a, float p) {
        title = t;
        author = a;
        price = p;
        totalBooks++;
    }

    static void showTotalBooks() {
        cout << "Total books created: " << totalBooks << endl;
    }

    void showDetails() {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price << endl;
    }
};

int Book::totalBooks = 0;

int main() {
    Book b1("Book One", "Author A", 29.99);
    Book b2("Book Two", "Author B", 39.99);
    Book b3("Book Three", "Author C", 49.99);
    Book b4("Book Four", "Author D", 59.99);

    b1.showDetails();
    b2.showDetails();
    b3.showDetails();
    b4.showDetails();

    Book::showTotalBooks();

    return 0;
}