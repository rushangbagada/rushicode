//find maximum from n inputed numbers from arry
#include<stdio.h>

int main(){
     int n,max;
      printf("you entered value:");
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
     
     max=a[0];
     for(int i=0;i<n;i++){
            if(a[i]>max){
              max=a[i];
            }
     }
     printf(" maximum is:%d",max);

    return 0;
}