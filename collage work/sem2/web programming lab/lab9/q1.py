# Python Program to count the number of vowels in a string.


def count_vowels(string):
    vowels = 'aeiouAEIOU'
    count = 0
    for char in string:
        if char in vowels:
            count += 1
    return count    

print(count_vowels('Hello World'))
print(count_vowels('Python Programming'))