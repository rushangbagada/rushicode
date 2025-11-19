// Write a program with the base class PLUSData has two protected member variables namely 
// N1  and  N2.  Class  Addition  is  derived  from  the  base  class  AddData  by  using  simple 
// inheritance

#include <bits/stdc++.h>
using namespace std;

class PLUSdata{
    protected:
        int N1;
        int N2;
    public:
        void setData(int a,int b){
            N1=a;
            N2=b;
        }
        void getData(){
            cout<<"The value of N1 is "<<N1<<endl;
            cout<<"The value of N2 is "<<N2<<endl;
        }
};

class addition:public PLUSdata{
    public:
        void Display(){
            int sum=N1+N2;
            cout<<"The sum of N1 and N2 is "<<sum<<endl;
        
        }
};

int main(){
    addition obj;
    int a,b;
    cout<<"Enter the value of N1 and N2"<<endl;
    cin>>a>>b;
    obj.setData(a,b);
    obj.getData();
    obj.Display();
    return 0;
}