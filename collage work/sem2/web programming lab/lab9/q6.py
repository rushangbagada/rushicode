#Python Program to find the sum of series: 1 + 1/2 + 1/3 + ….. + 1/N

def sum_of_series(n):
    sum = 0
    for i in range(1, n+1):
        sum += 1/i
    return sum

print(sum_of_series(5))