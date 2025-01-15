//5.2
#include<stdio.h>
int main(){
int i,j,k,l=0;
for(i=1;i<=5;i++){
	for(k=1;k<=5-i;k++){
          printf(" ");		
	}
	
	  
      for( j=1;j<=i;j++){
        printf("%d ",l);
        l+=2;
      }printf("\n");
}




	return 0;
}


