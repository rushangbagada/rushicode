//find maximum from n inputed numbers from arry
#include<stdio.h>

int main(){
     int n,min,max;
      printf("you entered value:");
     scanf("%d",&n);
     int a[n];
     for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
     
     min=a[0];
     max=a[0];
     for(int i=0;i<n;i++){
            if(a[i]<min){
              min=a[i];
            }else if(a[i]>max){
              max=a[i];
            }



     }
     printf("\n minimum is:%d",min);
     printf("\n maximum is:%d",max);  
    return 0;
}