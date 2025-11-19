#include <bits/stdc++.h>
using namespace std;

class Time
{
    private:
        int hours;  
        int minutes;

    public:
        Time(int h=0, int m=0)
        {
            this->hours=h;
            this->minutes=m;
        }

        friend Time operator+(const Time &t1, const Time &t2);
        
        void display()
        {
            cout << hours << " hours" << " " << minutes << " minutes" << endl;
        }
};

Time operator+(const Time &t1, const Time &t2)
{
    int h = t1.hours + t2.hours;
    int m = t1.minutes + t2.minutes;

    if(m>=60)
    {
        h+=m/60;
        m=m%60;
    }

    return Time(h,m);
}

int main()
{
    Time t1(2, 30), t2(1, 45);
    Time t3 = t1 + t2;
    t3.display();
    
    return 0;
}