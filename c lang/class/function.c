// #include<stdio.h>
// //function  declaration
// void printgoodbye();
// void printhello();
// void namaste();
// void bonjour();
// int main(){
//       printhello();//function call
//       printgoodbye();
//       namaste();
//       bonjour();
//     return 0;
// }
// //function defination
// void printhello(){
//     printf("\nhello");
// }
// void printgoodbye(){
//     printf("\ngoodbye");
// }
// void namaste(){
//     printf("\nnamaste");   
// } void bonjour(){
//     printf("\nbonjour");
// }



// #include<stdio.h>
// void calculateprise(float value);

// int main(){
//      float value=100.0;
//      calculateprise(value);
//      printf("\nvalue is: %f",value);

//     return 0;
// }

// void calculateprise(float value){
//     value=value+(0.18*value);
//     printf("final value is:%f" ,value);
// }

// function can only return one value at a time
//changes to partameter in function don't change the values in callinf function 
//beacause a copy of a argument is passed to the function
  
// #include<stdio.h>
// #include<math.h>

// int main(){
//     int n=4;
//     printf("%f",pow(n,2));
//     return 0;
// }


// #include<stdio.h>
// #include<math.h>
// float squarearea(float side);
// float circlearea(float rad);
// float rectanglearea(float a,float b);
// int main(){
//    float a=5.0;
//    float b=10.0;
//    printf("area is :%f", rectanglearea(a,b));
//     return 0;
// }

// float squarearea(float side){

//     return side*side;
// }

// float circlearea(float rad){


// return 3.14*rad*rad;
// }
// float rectanglearea(float a,float b){

// return a*b;
// }


//recursion like loop 
//printf helloword 5 time
// #include<stdio.h>
// void printh(int count);
// int main(){
//     printh(10);
// return 0;
// }
// //recursion function
// void printh(int count){
//    if(count==0){
//        return;
//    }
// printf("hello world\n");
// printh(count-1);

// }



//sum of n natural number
// #include<stdio.h>
// int sum(int n);
// int main(){
//     int a;
//        scanf("%d",&a);
//     printf("sum is : %d",sum(a));
// return 0;
// }
// //recurtion function
// int sum(int n){
//     if(n==1){
//         return 1;
//     }
//     int sumof=sum(n-1);//sum of 1 to n
//     int sum=sumof + n;
//     return sum;
// } 


// factorial


// #include<stdio.h>
// int mul(int n);
// int main(){
//     int a;
//        scanf("%d",&a);
//     printf("fac  is : %d",mul(a));
// return 0;
// }
// //recurtion function
// int mul(int n){
//     if(n==1){
//         return 1;
//     }
//     int sumof=mul(n-1);//mul of 1 to n
//     int mul=sumof * n;
//     return mul;
// }

//convert temp
// #include<stdio.h>
// float converttemp(float celcius);
// int main(){
//     float n;
//     printf("enter celcius:");
//     scanf("%f",&n);
// float far=converttemp(n);
// printf("ferenheat is:%f",far);
// return 0;
// }
// float converttemp(float celcius){
//     float far = celcius*(9.0/5.0)+32; 
//     return far;
// }

