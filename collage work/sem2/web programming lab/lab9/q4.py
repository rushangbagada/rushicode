 #Python Program to find the factorial of a number with and without using recursion. 
 
 
def factorial_rec(n):
     if n == 0:
         return 1
     else:
         return n * factorial_rec(n-1)
     
def factorial(n):
    fact = 1
    for i in range(1, n+1):
        fact *= i
    return fact

print(factorial_rec(5))
print(factorial(5))
     