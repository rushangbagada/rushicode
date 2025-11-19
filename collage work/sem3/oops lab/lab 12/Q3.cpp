// Q3: Vehicle Service Cost Calculator
// Demonstrates: Virtual functions, Runtime polymorphism

#include <bits/stdc++.h>
using namespace std;

class Vehicle {
protected:
    string name;
    double baseCost;
    int engineCC;
    
public:
    Vehicle(string n = "Vehicle", double base = 0, int cc = 0) 
        : name(n), baseCost(base), engineCC(cc) {}
    
    // Virtual function for calculating service cost
    virtual double serviceCost() {
        return baseCost;
    }
    
    // Normal function
    void displayType() {
        cout << "Vehicle Type: " << name << endl;
    }
    
    void inputDetails() {
        cout << "Enter base service cost: $";
        cin >> baseCost;
        cout << "Enter engine CC: ";
        cin >> engineCC;
    }
    
    virtual void displayDetails() {
        cout << "\n=== " << name << " Details ===\n";
        cout << "Base Cost: $" << baseCost << endl;
        cout << "Engine CC: " << engineCC << endl;
        cout << "Total Service Cost: $" << serviceCost() << endl;
    }
    
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car() : Vehicle("Car", 0, 0) {}
    
    // Override serviceCost: cost = baseCost + (engineCC * 0.5)
    double serviceCost() override {
        return baseCost + (engineCC * 0.5);
    }
    
    void displayDetails() override {
        cout << "\n=== Car Service Details ===\n";
        displayType();
        cout << "Base Cost: $" << baseCost << endl;
        cout << "Engine CC: " << engineCC << endl;
        cout << "Additional Cost (CC * 0.5): $" << (engineCC * 0.5) << endl;
        cout << "Total Service Cost: $" << serviceCost() << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike() : Vehicle("Bike", 0, 0) {}
    
    // Override serviceCost: cost = baseCost + (engineCC * 0.2)
    double serviceCost() override {
        return baseCost + (engineCC * 0.2);
    }
    
    void displayDetails() override {
        cout << "\n=== Bike Service Details ===\n";
        displayType();
        cout << "Base Cost: $" << baseCost << endl;
        cout << "Engine CC: " << engineCC << endl;
        cout << "Additional Cost (CC * 0.2): $" << (engineCC * 0.2) << endl;
        cout << "Total Service Cost: $" << serviceCost() << endl;
    }
};

int main() {
    cout << "=== Vehicle Service Cost Calculator ===\n\n";
    
    // Create objects
    Car car;
    Bike bike;
    
    // Input details
    cout << "--- Enter Car Details ---\n";
    car.inputDetails();
    
    cout << "\n--- Enter Bike Details ---\n";
    bike.inputDetails();
    
    // Display using object's own method
    car.displayDetails();
    bike.displayDetails();
    
    // Runtime Polymorphism - using base class pointers
    cout << "\n\n=== Runtime Polymorphism Demo ===\n";
    cout << "Calling through base class pointer:\n";
    
    Vehicle* vehicles[2];
    vehicles[0] = &car;
    vehicles[1] = &bike;
    
    for (int i = 0; i < 2; i++) {
        cout << "\nVehicle " << i + 1 << ":\n";
        vehicles[i]->displayType();
        cout << "Service Cost: $" << vehicles[i]->serviceCost() << endl;
    }
    
    // Demonstrate virtual function behavior
    cout << "\n\n=== Virtual Function Demonstration ===\n";
    Vehicle* vptr;
    
    vptr = &car;
    cout << "Base pointer pointing to Car:\n";
    cout << "Service Cost: $" << vptr->serviceCost() << " (Car's version called)\n";
    
    vptr = &bike;
    cout << "\nBase pointer pointing to Bike:\n";
    cout << "Service Cost: $" << vptr->serviceCost() << " (Bike's version called)\n";
    
    // Compare costs
    cout << "\n\n=== Cost Comparison ===\n";
    if (car.serviceCost() > bike.serviceCost()) {
        cout << "Car service is more expensive by $" 
             << (car.serviceCost() - bike.serviceCost()) << endl;
    } else {
        cout << "Bike service is more expensive by $" 
             << (bike.serviceCost() - car.serviceCost()) << endl;
    }
    
    return 0;
}
