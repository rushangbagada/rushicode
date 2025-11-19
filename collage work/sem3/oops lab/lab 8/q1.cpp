#include <bits/stdc++.h>
using namespace std;

class Number
{
    public:
        int x;

        Number(int v=0)
        {
            this->x=v;
        }

        int operator++()
        {
            return x=x+1;
        }

        int operator++(int)
        {
            x=x+1;
            return x-1;
        }
};

int main()
{
    Number n(5);
    cout<<n++<<endl; 
    cout<<++n<<endl; 
    return 0;
}