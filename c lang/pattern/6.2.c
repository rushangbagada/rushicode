//
#include<stdio.h>
int main(){

  int i,k,j,a='Z';
for(i=1;i<=4;i++){
	for(k=1;k<=4-i;k++){
		printf(" ");
	}
      for( j=1;j<=i;j++){
        printf("%c ",a);
        a=a-2;
      }printf("\n");
}

	return 0;
}


