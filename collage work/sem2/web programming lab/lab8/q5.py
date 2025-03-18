# 5. Replace the last value of tuples in a list
tuple_list = [(10, 20, 40), (40, 50, 60), (70, 80, 90)]
tuple_list = [t[:-1] + (100,) for t in tuple_list]
print(tuple_list)

