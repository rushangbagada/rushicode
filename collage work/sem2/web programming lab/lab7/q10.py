# Python program for simple interest 

p = float(input("Enter the principal amount: "))
r = float(input("Enter the rate of interest: "))
t = float(input("Enter the time period: "))

si = (p * r * t) / 100

print("The simple interest is:", si)