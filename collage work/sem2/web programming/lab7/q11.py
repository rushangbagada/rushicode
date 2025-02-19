# Python program to check Perfect Number (Example: 6, divisors of 6 are 3,2,1 and sum 
#of  divisors is the number itself)  

num = int(input("Enter a number: "))

sum = 0

for i in range(1, num):
    if num % i == 0:
        sum += i

if sum == num:
    print(num, "is a perfect number.")
else:
    print(num, "is not a perfect number.")