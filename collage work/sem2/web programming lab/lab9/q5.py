#5. Python Program to find the power of a number using recursion.  
def power(base, exp):
    if exp == 0:
        return 1
    else:
        return base * power(base, exp-1)
print(power(120, 5))