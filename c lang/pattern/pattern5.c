//hollow diamond

#include<stdio.h>
int main(){
    int n;
     scanf("%d",&n);
for (int i=1;i<=n;i++){
   for(int j=1;j<=n-i;j++){
       printf("  ");
   }
    for(int j=1;j<=1;j++){
        printf("* ");
    }
   if(i==1){
    printf(" ");

   }else{
    for(int j=3;j<=2*i-1;j++){
       printf("  ");
   }
    for(int j=1;j<=1;j++){
        printf("* ");
   }
    
    }
    printf("\n");
    
}
    for (int i=n-1;i>=1;i--){
   for(int j=n-i;j>=1;j--){
       printf("  ");
   }
    for(int j=1;j>=1;j--){
        printf("*");
    }if(i==1){
        printf(" ");

    }else{
        for(int j=2*i-1;j>=3;j--){
       printf("  ");
   }
    for(int j=1;j<=1;j++){
        printf(" *");
    }
    
    }
    
    printf("\n");
    }
return 0;

}
