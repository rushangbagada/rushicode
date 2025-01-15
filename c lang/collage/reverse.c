#include<stdio.h>
int main(){
  int a,b=0,n,c=0,d;

  scanf("%d",&n);
  d=n;
  while(n>1){
   a=n%10;
   b=b*10+a;
   n=n/10;
  }printf("%d",b);
  if(b==d){
    printf("is a palindrome number");
  }else{
    printf("is not a pelindrrome number");
  }


return 0;
 }