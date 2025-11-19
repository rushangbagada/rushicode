#include <bits/stdc++.h>
using namespace std;

class Point
{
    private :
        int x, y;

    public :
        Point(int x=0, int y=0)
        {
            this->x=x;
            this->y=y;
        }

        Point operator++()
        {
            Point temp = *this;
            x+=1;
            y+=1;
            Point helper=temp;
            helper.x-=1;
            helper.y-=1;
            return helper;
        }

        Point operator++(int)
        {
            Point temp = *this;
            x+=1;
            y+=1;
            return temp;
        }

        Point operator+(const Point &p)
        {
            Point temp;
            temp.x = this->x + p.x;
            temp.y = this->y + p.y;
            return temp;
        }

        void display()
        {
            cout<< "(" << x << "," << y << ")" << endl;
        }
};
int main()
{
    Point p1(2,3);
    Point p2(4,5);
    Point p3 = p1 + p2;
    p3.display();
    Point p4 = ++p1;
    p4.display();
    Point p5 = p2++;
    p5.display();
    return 0;
}