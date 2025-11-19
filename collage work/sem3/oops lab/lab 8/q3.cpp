#include <bits/stdc++.h>
using namespace std;

class Distance
{
    int feet, inches;

    public:
    Distance(int f=0, int i=0)
    {
        feet=f;
        inches=i;
    }

    void getdist()
    {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showdist()
    {
        cout << feet << " " << inches << " " << endl;
    }

    friend Distance operator+(const Distance &c,const Distance &d);
};

Distance operator+(const Distance &c,const Distance &d)
{
    int f = c.feet + d.feet;
    int i = c.inches + d.inches;

    if(i>=12)
    {
        f+=i/12;
        i=i%12;
    }

    return Distance(f,i);
}
int main()
{
    Distance D1, D2, D3;
    D1.getdist();
    D2.getdist();
    D3=D1+D2;
    D3.showdist();
    D1.showdist();
    D2.showdist();

    return 0;
}