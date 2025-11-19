#include <bits/stdc++.h>
using namespace std;

class vector_2d
{
    private :
        int x;
        int y;

    public:
        vector_2d(int x=0, int y=0)
        {
            this->x=x;
            this->y=y;
        }

        vector_2d operator+(const vector_2d &v)
        {
            vector_2d temp;
            temp.x = this->x + v.x;
            temp.y = this->y + v.y;
            return temp;
        }

        vector_2d operator-(const vector_2d &v)
        {
            vector_2d temp;
            temp.x = this->x - v.x;
            temp.y = this->y - v.y;
            return temp;
        }

        vector_2d operator*(const vector_2d &v)
        {
            vector_2d temp;
            temp.x = this->x * v.x;
            temp.y = this->y * v.y;
            return temp;
        }

        vector_2d operator^(int a)
        {
            return vector_2d(this->x*a, this->y*a);
        }

        bool operator==(const vector_2d &v)
        {
            if(v.x == this->x && v.y == this->y)
            {
                return true;
            }

            return false;
        }   

        friend ostream& operator<<(ostream& out, const vector_2d& v);

};

ostream& operator<<(ostream& out, const vector_2d& v)
{
    out << v.x << " " << v.y << endl;
    return out;
}
int main()
{
    vector_2d v(3, 4);
    vector_2d u(1, 2);
    
    vector_2d w = v + u;
    cout << w;

    vector_2d z = v - u;
    cout << z;  

    vector_2d x = v * u;
    cout << x;

    vector_2d y = v ^ 2;
    cout << y;

    cout << (v == u) << endl;
    return 0;
}