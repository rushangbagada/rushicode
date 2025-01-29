// write a program to display first N febonacci serise using recursion
#include <stdio.h>
int fib(int n)
{
    if (n == 1 || n == 0)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("The first %d Fibonacci numbers are: ", n);
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}