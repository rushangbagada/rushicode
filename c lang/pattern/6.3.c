//6.3
#include<stdio.h>
int main(){
  int i,j,a='A';
for(i=1;i<=5;i++){
      for( j=1;j<=i;j++){
        printf("%c ",a);
        a+=1;
      }printf("\n");
}


	return 0;
}


