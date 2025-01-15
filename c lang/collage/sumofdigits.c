#include<stdio.h>
int main(){
  int a,b=0,n,c=0;
  scanf("%d",&n);
  while(n>0){
   a=n%10;
   b=b*10+a;
   n=n/10;
  }printf("%d",b);


return 0;
 }