#include<stdio.h>
#include<string.h>
int main(){
      char s[5];
      fgets(s,7,stdin);
      printf("%d", strlen(s));
      printf("%s",s);
      printf("anything");
      
      
return 0;
}
