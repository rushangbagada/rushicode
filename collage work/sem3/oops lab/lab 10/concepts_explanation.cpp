// ============================================================================
// COMPLETE GUIDE TO OOP CONCEPTS FOR LAB ASSIGNMENT 10
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// 1. VIRTUAL FUNCTIONS - Foundation of Polymorphism
// ============================================================================

/*
WHAT ARE VIRTUAL FUNCTIONS?
- A virtual function is a member function declared in base class with 'virtual' keyword
- It can be overridden in derived classes
- Enables RUNTIME POLYMORPHISM (late binding/dynamic binding)
- Allows calling derived class function through base class pointer/reference

WHY USE VIRTUAL FUNCTIONS?
- Without virtual: Compiler decides which function to call at compile time (static binding)
- With virtual: Decision is made at runtime based on actual object type (dynamic binding)
*/

class Animal {
public:
    // Non-virtual function
    void eat() {
        cout << "Animal is eating" << endl;
    }
    
    // Virtual function - can be overridden
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
    
    // Pure virtual function - MUST be overridden (makes class abstract)
    virtual void move() = 0;
};

class Dog : public Animal {
public:
    void sound() override {  // 'override' keyword is optional but recommended
        cout << "Dog barks: Woof!" << endl;
    }
    
    void move() override {
        cout << "Dog runs on four legs" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows: Meow!" << endl;
    }
    
    void move() override {
        cout << "Cat walks silently" << endl;
    }
};

void demonstrateVirtualFunctions() {
    cout << "\n=== VIRTUAL FUNCTIONS DEMO ===\n" << endl;
    
    // Creating objects
    Dog dog;
    Cat cat;
    
    // Using base class pointers (THIS IS THE KEY!)
    Animal* ptr1 = &dog;
    Animal* ptr2 = &cat;
    
    cout << "Calling through base class pointer:" << endl;
    ptr1->sound();  // Calls Dog::sound() - RUNTIME decision
    ptr2->sound();  // Calls Cat::sound() - RUNTIME decision
    
    ptr1->move();
    ptr2->move();
}

// ============================================================================
// 2. INHERITANCE - The Foundation
// ============================================================================

/*
TYPES OF INHERITANCE:

1. SINGLE INHERITANCE
   Base -> Derived

2. MULTILEVEL INHERITANCE
   A -> B -> C

3. MULTIPLE INHERITANCE
   A    B
    \  /
     C

4. HIERARCHICAL INHERITANCE
      A
     / \
    B   C

5. HYBRID INHERITANCE
   Combination of above types
*/

// Example: Single Inheritance
class Vehicle {
protected:
    string brand;
    int year;
public:
    Vehicle(string b, int y) : brand(b), year(y) {}
    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
public:
    Car(string b, int y, int d) : Vehicle(b, y), doors(d) {}
    void showCar() {
        display();
        cout << "Doors: " << doors << endl;
    }
};

// Example: Multiple Inheritance
class Engine {
protected:
    string engineType;
public:
    Engine(string type) : engineType(type) {}
    void showEngine() {
        cout << "Engine: " << engineType << endl;
    }
};

class Transmission {
protected:
    string transType;
public:
    Transmission(string type) : transType(type) {}
    void showTrans() {
        cout << "Transmission: " << transType << endl;
    }
};

class Automobile : public Engine, public Transmission {
private:
    string model;
public:
    Automobile(string e, string t, string m) 
        : Engine(e), Transmission(t), model(m) {}
    
    void showDetails() {
        cout << "Model: " << model << endl;
        showEngine();
        showTrans();
    }
};

// ============================================================================
// 3. DIAMOND PROBLEM & VIRTUAL INHERITANCE
// ============================================================================

/*
DIAMOND PROBLEM:
When a class inherits from two classes that both inherit from same base class

    Device
     / \
    A   B
     \ /
      C

Problem: C has TWO copies of Device - which one to use? AMBIGUITY!

Solution: VIRTUAL INHERITANCE
*/

class Device {
protected:
    int id;
public:
    Device(int i = 0) : id(i) {
        cout << "Device constructor: " << id << endl;
    }
};

// Without virtual inheritance - PROBLEM
class PhoneFeature : public Device {
public:
    PhoneFeature(int i) : Device(i) {}
};

class CameraFeature : public Device {
public:
    CameraFeature(int i) : Device(i) {}
};

// This will have TWO Device objects!
class SmartphoneProblem : public PhoneFeature, public CameraFeature {
public:
    SmartphoneProblem() : PhoneFeature(1), CameraFeature(2) {}
    // id is ambiguous! Which one? PhoneFeature::id or CameraFeature::id?
};

// WITH virtual inheritance - SOLUTION
class PhoneFeatureVirtual : virtual public Device {
public:
    PhoneFeatureVirtual(int i) : Device(i) {}
};

class CameraFeatureVirtual : virtual public Device {
public:
    CameraFeatureVirtual(int i) : Device(i) {}
};

// Now only ONE Device object exists!
class SmartphoneSolution : public PhoneFeatureVirtual, public CameraFeatureVirtual {
public:
    SmartphoneSolution() : Device(100), PhoneFeatureVirtual(0), CameraFeatureVirtual(0) {}
    // Only one id - no ambiguity!
    void showId() {
        cout << "Device ID: " << id << endl;
    }
};

// ============================================================================
// 4. ACCESS SPECIFIERS IN INHERITANCE
// ============================================================================

/*
ACCESS SPECIFIERS:
1. PUBLIC: Accessible everywhere
2. PROTECTED: Accessible in class and derived classes
3. PRIVATE: Accessible only in the class

INHERITANCE MODES:
1. public: Public remains public, Protected remains protected
2. protected: Public becomes protected, Protected remains protected
3. private: Both public and protected become private
*/

class Base {
public:
    int pubVar;
protected:
    int protVar;
private:
    int privVar;  // Never accessible in derived class
};

class DerivedPublic : public Base {
    // pubVar is public
    // protVar is protected
    // privVar is not accessible
};

class DerivedProtected : protected Base {
    // pubVar is protected
    // protVar is protected
    // privVar is not accessible
};

class DerivedPrivate : private Base {
    // pubVar is private
    // protVar is private
    // privVar is not accessible
};

// ============================================================================
// 5. CONSTRUCTORS IN INHERITANCE
// ============================================================================

/*
IMPORTANT RULES:
1. Base class constructor is called FIRST, then derived class constructor
2. Must explicitly call base class constructor if it has parameters
3. Use initialization list to pass parameters to base class
*/

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person constructor called for " << name << endl;
    }
    
    ~Person() {
        cout << "Person destructor called for " << name << endl;
    }
};

class Student : public Person {
private:
    int rollNo;
public:
    // MUST call Person constructor in initialization list
    Student(string n, int a, int r) : Person(n, a), rollNo(r) {
        cout << "Student constructor called" << endl;
    }
    
    ~Student() {
        cout << "Student destructor called" << endl;
    }
    
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", Roll: " << rollNo << endl;
    }
};

// ============================================================================
// 6. ABSTRACT CLASSES & PURE VIRTUAL FUNCTIONS
// ============================================================================

/*
ABSTRACT CLASS:
- Contains at least one pure virtual function
- Cannot create objects of abstract class
- Used as interface/blueprint for derived classes

PURE VIRTUAL FUNCTION:
- Declared with = 0
- Has no implementation in base class
- MUST be overridden in derived class
*/

class Shape {  // Abstract class
public:
    virtual double area() = 0;  // Pure virtual function
    virtual double perimeter() = 0;  // Pure virtual function
    
    // Can have normal functions too
    void display() {
        cout << "This is a shape" << endl;
    }
    
    virtual ~Shape() {}  // Virtual destructor (important!)
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    
    double area() override {
        return length * width;
    }
    
    double perimeter() override {
        return 2 * (length + width);
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() override {
        return 3.14159 * radius * radius;
    }
    
    double perimeter() override {
        return 2 * 3.14159 * radius;
    }
};

// ============================================================================
// 7. POLYMORPHISM
// ============================================================================

/*
POLYMORPHISM = "Many forms"

Two types:
1. COMPILE-TIME (Static) Polymorphism
   - Function overloading
   - Operator overloading

2. RUNTIME (Dynamic) Polymorphism
   - Virtual functions
   - Function overriding
*/

void demonstratePolymorphism() {
    cout << "\n=== POLYMORPHISM DEMO ===\n" << endl;
    
    // Creating different shapes
    Rectangle rect(5, 3);
    Circle circ(4);
    
    // Array of base class pointers - THIS IS POLYMORPHISM!
    Shape* shapes[2];
    shapes[0] = &rect;
    shapes[1] = &circ;
    
    // Same code, different behavior based on actual object
    for (int i = 0; i < 2; i++) {
        cout << "Shape " << i + 1 << ":" << endl;
        cout << "Area: " << shapes[i]->area() << endl;
        cout << "Perimeter: " << shapes[i]->perimeter() << endl;
        cout << endl;
    }
}

// ============================================================================
// 8. VIRTUAL DESTRUCTOR
// ============================================================================

/*
WHY VIRTUAL DESTRUCTOR?
- When deleting derived class object through base class pointer
- Without virtual destructor: Only base destructor called - MEMORY LEAK!
- With virtual destructor: Both destructors called properly
*/

class BaseClass {
public:
    BaseClass() {
        cout << "Base constructor" << endl;
    }
    
    virtual ~BaseClass() {  // VIRTUAL destructor
        cout << "Base destructor" << endl;
    }
};

class DerivedClass : public BaseClass {
private:
    int* data;
public:
    DerivedClass() {
        data = new int[100];
        cout << "Derived constructor" << endl;
    }
    
    ~DerivedClass() {
        delete[] data;
        cout << "Derived destructor - memory freed" << endl;
    }
};

void demonstrateVirtualDestructor() {
    cout << "\n=== VIRTUAL DESTRUCTOR DEMO ===\n" << endl;
    
    BaseClass* ptr = new DerivedClass();
    delete ptr;  // Both destructors called because base destructor is virtual
}

// ============================================================================
// 9. FUNCTION OVERRIDING vs OVERLOADING
// ============================================================================

/*
OVERLOADING (Compile-time):
- Same function name, different parameters
- In same class

OVERRIDING (Runtime):
- Same function signature
- In base and derived class
- Base function must be virtual
*/

class Example {
public:
    // Function overloading
    void print(int x) {
        cout << "Integer: " << x << endl;
    }
    
    void print(double x) {
        cout << "Double: " << x << endl;
    }
    
    void print(string x) {
        cout << "String: " << x << endl;
    }
};

// ============================================================================
// 10. PRACTICAL TIPS FOR LAB ASSIGNMENT
// ============================================================================

/*
KEY POINTS TO REMEMBER:

1. USE VIRTUAL FUNCTIONS when:
   - You want runtime polymorphism
   - You're using base class pointers/references
   - You want different behavior for different derived classes

2. USE PURE VIRTUAL (= 0) when:
   - You want to create an interface
   - Derived classes MUST implement the function
   - You don't want to create base class objects

3. USE VIRTUAL INHERITANCE when:
   - You have diamond inheritance pattern
   - You want only ONE copy of base class

4. ALWAYS use virtual destructor in base class if:
   - You're using inheritance
   - You might delete derived objects through base pointer

5. ACCESS SPECIFIERS:
   - Use 'protected' for members you want derived classes to access
   - Use 'private' for implementation details
   - Use 'public' for interface

6. CONSTRUCTOR ORDER:
   - Base constructor called first
   - Then derived constructor
   - Destructors in reverse order

7. OVERRIDE KEYWORD:
   - Not mandatory but highly recommended
   - Catches errors at compile time
   - Makes code more readable
*/

// ============================================================================
// MAIN FUNCTION - DEMONSTRATIONS
// ============================================================================

int main() {
    cout << "=====================================================" << endl;
    cout << "  OOP CONCEPTS FOR LAB ASSIGNMENT 10 - TUTORIAL  " << endl;
    cout << "=====================================================" << endl;
    
    // Demo 1: Virtual Functions
    demonstrateVirtualFunctions();
    
    // Demo 2: Single Inheritance
    cout << "\n=== SINGLE INHERITANCE DEMO ===" << endl;
    Car myCar("Toyota", 2024, 4);
    myCar.showCar();
    
    // Demo 3: Multiple Inheritance
    cout << "\n=== MULTIPLE INHERITANCE DEMO ===" << endl;
    Automobile auto1("V8", "Automatic", "Mustang");
    auto1.showDetails();
    
    // Demo 4: Diamond Problem Solution
    cout << "\n=== VIRTUAL INHERITANCE DEMO ===" << endl;
    SmartphoneSolution phone;
    phone.showId();
    
    // Demo 5: Constructor Order
    cout << "\n=== CONSTRUCTOR/DESTRUCTOR ORDER ===" << endl;
    {
        Student s1("John", 20, 101);
        s1.display();
    }  // Destructors called when going out of scope
    
    // Demo 6: Polymorphism
    demonstratePolymorphism();
    
    // Demo 7: Virtual Destructor
    demonstrateVirtualDestructor();
    
    // Demo 8: Function Overloading
    cout << "\n=== FUNCTION OVERLOADING DEMO ===" << endl;
    Example ex;
    ex.print(10);
    ex.print(3.14);
    ex.print("Hello");
    
    cout << "\n=====================================================" << endl;
    cout << "         END OF TUTORIAL - GOOD LUCK!              " << endl;
    cout << "=====================================================" << endl;
    
    return 0;
}

/*
SUMMARY OF KEY CONCEPTS:

1. VIRTUAL FUNCTIONS = Runtime polymorphism, dynamic binding
2. PURE VIRTUAL = Abstract class, interface, must override
3. VIRTUAL INHERITANCE = Solves diamond problem
4. POLYMORPHISM = Same interface, different implementations
5. ABSTRACT CLASS = Cannot instantiate, blueprint for derived
6. OVERRIDE = Keyword to ensure function is actually overriding
7. VIRTUAL DESTRUCTOR = Proper cleanup in inheritance hierarchy
8. PROTECTED = Accessible in derived classes
9. INITIALIZATION LIST = Call base constructor, initialize members
10. MULTIPLE INHERITANCE = Inherit from multiple classes

COMMON MISTAKES TO AVOID:
❌ Forgetting 'virtual' keyword for polymorphism
❌ Not using virtual destructor in base class
❌ Forgetting to call base class constructor
❌ Not using 'override' keyword
❌ Making functions virtual that don't need to be
❌ Not using virtual inheritance in diamond pattern
❌ Trying to instantiate abstract class
❌ Not implementing pure virtual functions in derived class

BEST PRACTICES:
✅ Always use virtual destructor in base class with virtual functions
✅ Use 'override' keyword when overriding functions
✅ Use pure virtual for interface/abstract classes
✅ Use virtual inheritance for diamond problem
✅ Keep base class interface clean and minimal
✅ Document which functions are meant to be overridden
✅ Use smart pointers instead of raw pointers when possible
✅ Follow single responsibility principle

*/
