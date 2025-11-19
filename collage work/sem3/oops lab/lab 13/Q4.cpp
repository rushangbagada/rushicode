// Q4: Product Bill Generator
// Demonstrates: setw, fixed, setprecision, width(), fill(), precision()

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Product {
    string name;
    int quantity;
    double pricePerItem;
    double total;
};

int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    cin.ignore();
    
    Product products[n];
    double grandTotal = 0;
    
    // Input product details
    for(int i = 0; i < n; i++) {
        cout << "\n--- Product " << (i+1) << " ---\n";
        cout << "Enter Product Name: ";
        getline(cin, products[i].name);
        
        cout << "Enter Quantity: ";
        cin >> products[i].quantity;
        
        cout << "Enter Price per Item: ";
        cin >> products[i].pricePerItem;
        cin.ignore();
        
        products[i].total = products[i].quantity * products[i].pricePerItem;
        grandTotal += products[i].total;
    }
    
    // Display Bill
    cout << "\n\n";
    cout.fill('=');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    cout << setw(45) << "INVOICE / BILL" << endl;
    
    cout.fill('=');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    // Table Header
    cout << left << setw(5) << "No."
         << setw(30) << "Product Name"
         << right << setw(15) << "Quantity"
         << setw(15) << "Price/Item"
         << setw(15) << "Total" << endl;
    
    cout.fill('-');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    // Product rows
    for(int i = 0; i < n; i++) {
        cout << left << setw(5) << (i+1)
             << setw(30) << products[i].name;
        
        cout.precision(0);
        cout << right << setw(15) << products[i].quantity;
        
        cout.precision(2);
        cout << fixed << right << setw(15) << products[i].pricePerItem
             << setw(15) << products[i].total << endl;
    }
    
    cout.fill('-');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    // Grand Total
    cout << left << setw(50) << ""
         << right << setw(15) << "Grand Total:"
         << fixed << setprecision(2) << setw(15) << grandTotal << endl;
    
    // Tax calculation
    double tax = grandTotal * 0.18; // 18% GST
    cout << left << setw(50) << ""
         << right << setw(15) << "Tax (18%):"
         << fixed << setprecision(2) << setw(15) << tax << endl;
    
    double finalAmount = grandTotal + tax;
    cout.fill('=');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    cout << left << setw(50) << ""
         << right << setw(15) << "Final Amount:"
         << fixed << setprecision(2) << setw(15) << finalAmount << endl;
    
    cout.fill('=');
    cout.width(80);
    cout << "" << endl;
    cout.fill(' ');
    
    cout << "\nThank you for your purchase!\n";
    
    return 0;
}
