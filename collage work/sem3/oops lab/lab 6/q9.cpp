//  Book Management Using calloc() in C++
// Create a book management system where each book has: 
// Title 
// Author 
// Price 
// Steps: 
// Allocate memory for n books using calloc() 
// Input book data 
// Display all books 
// Free memory

#include<bits/stdc++.h>
using namespace std;

struct Book {
    char title[100];
    char author[100];
    float price;
};

int main() {
    int n;
    Book *books;
    
    cout << "Enter the number of books: ";
    cin >> n;
    
    
    books = (Book*)calloc(n, sizeof(Book));
    
    if (books == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }
    
    
    cout << "\nEnter book details:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << (i + 1) << ":\n";
        cout << "Enter title: ";
        cin.ignore();
        cin.getline(books[i].title, 100);
        cout << "Enter author: ";
        cin.getline(books[i].author, 100);
        cout << "Enter price: ";
        cin >> books[i].price;
    }
    
    cout << "\n\n--- Book Details ---\n";
    cout << left << setw(20) << "Title" 
         << setw(20) << "Author" 
         << "Price" << endl;
    cout << "---------------------------------------------------\n";
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << books[i].title 
             << setw(20) << books[i].author 
             << "$" << fixed << setprecision(2) << books[i].price << endl;
    }
    

    free(books);
    cout << "\nMemory freed successfully!\n";
    
    return 0;
}

