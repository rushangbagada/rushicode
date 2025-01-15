#include<stdio.h>
#include<math.h>
int main(){
    int a,i,j,b;
    printf("enter a decimal no:");
    scanf("%d",&a);
    b=a;
    
      for(i=0;a!=0;i++){
          a=a/2;
         }
      for(j=1;j<=i;j++){
        int c;
       c=b/pow(2,i-j);
       printf("%d",c%2);
      }


    return 0;
}