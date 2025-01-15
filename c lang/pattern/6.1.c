//6.1
#include<stdio.h>
int main(){
  int i,j,k,a='A';
for(i=1;i<=4;i++){
	  for(k=0;k<=i;k++){
	  	printf(" ");
	  }
	 
	
      for( j=4;j>=i;j--){
        printf("%c ",a);
        a=a+2;
      }printf("\n");
}
	return 0;
}


