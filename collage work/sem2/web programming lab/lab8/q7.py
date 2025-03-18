# 7. Sort a tuple by float element
tuple_data2 = [('item1', '12.20'), ('item2', '15.10'), ('item3', '24.5')]
tuple_data2.sort(key=lambda x: float(x[1]), reverse=True)
print(tuple_data2)

