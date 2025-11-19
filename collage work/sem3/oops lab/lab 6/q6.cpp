// Write a program for a College Library System using a Book class with data 
// members: bookID, title, author, and copies. a. Define both a default constructor and a parameterised constructor. b. Add a const member function display() to show book details. c. Write a friend function that takes two Book objects, compares their number 
// of copies, and returns the book with more copies. d. In main(), create at least two books, use the friend function, and display the 
// details of the book with more copies


#include<bits/stdc++.h>

using namespace std;
class book {
    int bookID;
    string title;
    string author;
    int copies;
    public:
        friend book compareBooks(const book &b1, const book &b2);
        book(){
            bookID = 0;
            title = "";
            author = "";
            copies = 0;
        }
        book(int id,string t,string s,int c){
             bookID = id;
            title = t;
            author = s;
            copies = c;
        }
         void display(){
            cout << "Book ID: " << bookID << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Copies: " << copies << endl;
         }
};

book compareBooks(const book &b1, const book &b2) {
    return (b1.copies > b2.copies) ? b1 : b2;
}

int main() {
    book book1(1, "C++ Programming", "John Doe", 5);
    book book2(2, "Data Structures", "Jane Smith", 3);

    book moreCopies = compareBooks(book1, book2);
    moreCopies.display();

    return 0;
}