//5.3
#include<stdio.h>
int main(){
int i,j,k,l=0;
for(i=1;i<=5;i++){
	for(k=1;k<=i;k++){
          printf(" ");		
	}
	
	  
      for( j=1;j<2*(5-i+1);j++){
        printf("%d",j);
        
      }printf("\n");
}




	return 0;
}


