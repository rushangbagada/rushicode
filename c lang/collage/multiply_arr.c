#include<stdio.h>
int main(){
      
 int n,i=0,b=1,c=0,e;
  printf("Enter a number: ");
  scanf("%d",&n);
  e=n;
  while(n>0){
      n=n/10;
      i++;
  }
  n=e;
  printf("\nNo of digits is: %d", i);
  while(n>0){
     b=n%10;
    int d=1;
     for(int j=1;j<=i;j++){
         d=d*b;
     }
     c=c+d;
     n=n/10;
  }
  printf("\nArmstrong sum: %d Original number: %d",c,e);
  if(c==e){
    printf("\nthe number is armstrong");
  }else{
    printf("\nthe number is non armstrong");
  }
 
  return 0;

}