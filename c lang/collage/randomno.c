
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i=0,a,num,b;
    srand(time(0));
         b = rand(); // Generate a random number
         num=b%100+1;
           do{
              printf("guess the number:\n");
              scanf("%d",&a);
              if(num>a){
                printf("too low\n");
              }else if(num<a){
                printf("too high\n");
              }
               i++;
 
           }while(num!=a);

         printf("yop guessed the number in %d guesses",i);

    return 0;
}

