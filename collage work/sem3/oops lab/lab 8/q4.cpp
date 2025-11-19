#include <bits/stdc++.h>
using namespace std;

class Complex
{
    private:
        int real;
        int imag;

    public:
        Complex(int r=0,int i=0)
        {
            this->real=r;
            this->imag=i;
        }

        Complex operator+(const Complex &c)
        {
            return Complex(this->real + c.real, this->imag + c.imag);
        }

        void Display()
        {
            cout << this->real << " + " << this->imag << "i" << endl;
        }
};
int main()
{
    Complex c1(2,3), c2(4,5);
    Complex c3 = c1 + c2;
    c3.Display();

    return 0;
}