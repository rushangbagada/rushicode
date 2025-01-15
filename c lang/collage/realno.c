#include<stdio.h>
int main(){
  int n,c=0,b;
  printf("enter a number:");
  scanf("%d",&n);
  for(int i=1;i<n;i++){
    b=n%i;
    if(b==0){
        c=c+i;
    }

}
if(c==n){
    printf("%d :is a perfect number",n);
}else{
    printf("%d :is not a perfect number",n);
}
  

return 0;
 }

    
