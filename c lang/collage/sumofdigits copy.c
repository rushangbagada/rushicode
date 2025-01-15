#include<stdio.h>
int main(){
  int n,b,c=0;
  scanf("%d",&n);
  while(b>0){
     b=n%10;
     n=n/10;
     c=c+b;

  }
printf("%d",c);

return 0;
 }