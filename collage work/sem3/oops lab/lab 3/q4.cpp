// Develop a Library class that contains a collection of books (Book objects). Implement methods
// to add a book, remove a book, and display all books.


#include <bits/stdc++.h>

using namespace std;
class Book {
public:
    string title;
    string author;
    int year;
    Book(string t, string a, int y){
        title = t;
        author = a;
        year = y;
    }
    void display() {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};


class Library{
    private:
         vector<Book> books;

    public:
      void addBook(string title,string author ,int year){
        Book b(title, author, year);
        books.push_back(b);
      }
      void removeBook(string title){
        for (auto it = books.begin();it !=books.end();it++){
            if (it->title == title) {
                books.erase(it);
                break;
            }
        }
      }
      void displayBooks() {
          for (int i = 0; i < books.size(); i++) {
              books[i].display();
          }
      }
};


int main (){
    Library lib;
    lib.addBook("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    lib.addBook("1984", "George Orwell", 1949);
    lib.addBook("To Kill a Mockingbird", "Harper Lee", 1960);

    cout << "Books in the library:" << endl;
    lib.displayBooks();

    cout << "\nRemoving '1984' from the library." << endl;
    lib.removeBook("1984");

    cout << "Books in the library after removal:" << endl;
    lib.displayBooks();

    return 0;
}

