// write a program to display first N febonacci serise using recursion
#include <stdio.h>

// Function to calculate the nth Fibonacci number using recursion
int fibonacci(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// Function to display the first N Fibonacci numbers
void displayFibonacciSeries(int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", fibonacci(i));
    }
}

int main()
{
    int N;

    // Input: Number of terms in the Fibonacci series
    printf("Enter the number of terms: ");
    scanf("%d", &N);

    // Display the Fibonacci series
    printf("First %d Fibonacci numbers are:\n", N);
    displayFibonacciSeries(N);

    return 0;
}