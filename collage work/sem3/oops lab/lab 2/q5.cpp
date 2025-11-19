// 5. Write a C++ program to find the Fibonacci series till the limit entered by the user using functions

#include<bits/stdc++.h>
using namespace std;

void fibonacci(int n){
    int a=0,b=1,c;
    for(int i=0;i<n;i++){
        cout<<a<<" ";
        c=a+b;
        a=b;
        b=c;
    }
}

int main(){
    int n;
    cout<<"Enter the limit for Fibonacci series: ";
    cin>>n;

    cout<<"Fibonacci series till "<<n<<" terms: ";
    fibonacci(n);
    cout<<endl;

    return 0;
}