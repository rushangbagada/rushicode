//find minimum from n inputed numbers from arry
#include<stdio.h>

int main(){
     int n,min;
      printf("you entered value:");
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
     
     min=a[0];
     for(int i=0;i<n;i++){
            if(a[i]<min){
              min=a[i];
            }
     }
     printf(" minimum is:%d",min);

    return 0;
}