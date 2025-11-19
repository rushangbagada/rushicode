// write C++ programs that illustrate how the following forms of inheritance are supported: 


#include<bits/stdc++.h>
using namespace std;

// a)Single inheritance
class A {
    public:
        int a;
};

class B : public A {
    public:
        int b;
};

// b)Multiple inheritance
class C {
    public:
        int c;
};

class D : public A, public C {
    public:
        int d;
};

// c)Multilevel inheritance
class E : public B {
    public:
        int e;
};

// d)Hierarchical inheritance
class F : public A {
    public:
        int f;
};

class G : public A {
    public:
        int g;
};


int main() {
    // Single inheritance
    B objB;
    objB.a = 10;
    objB.b = 20;
    cout << "a: " << objB.a << ", b: " << objB.b << endl;

    // Multiple inheritance
    D objD;
    objD.a = 10;
    objD.c = 30;
    objD.d = 40;
    cout << "a: " << objD.a << ", c: " << objD.c << ", d: " << objD.d << endl;

    // Multilevel inheritance
    E objE;
    objE.a = 10;
    objE.b = 20;
    objE.e = 50;
    cout << "a: " << objE.a << ", b: " << objE.b << ", e: " << objE.e << endl;

    // Hierarchical inheritance
    F objF;
    G objG;
    objF.a = 10;
    objF.f = 60;
    objG.a = 10;
    objG.g = 70;
    cout << "a: " << objF.a << ", f: " << objF.f << endl;
    cout << "a: " << objG.a << ", g: " << objG.g << endl;

    return 0;
}