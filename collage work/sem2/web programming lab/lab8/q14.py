# 14. Create a dictionary from a string
string = 'a9prtovpcr'
dict_from_string = {char: string.count(char) for char in string}
print(dict_from_string)

