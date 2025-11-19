#include <bits/stdc++.h>
using namespace std;

class Animal
{
public:
    virtual void makeSound() { cout << "Generic animal sound." << "\n"; }
};
class Dog : public Animal
{
public:
    void makeSound() override { cout << "Bark!\n"; }
};

int main()
{
    Dog d;
    // direct
    d.makeSound();
    // scope resolution: call base version
    d.Animal::makeSound();
    // base pointer
    Animal *p = &d;
    p->makeSound();
    // base reference
    Animal &r = d;
    r.makeSound();
    return 0;
}
