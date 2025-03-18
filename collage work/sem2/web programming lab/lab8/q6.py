# 6. Remove empty tuples
tuple_data = [(), (), ('',), ('a', 'b'), ('a', 'b', 'c'), ('d')]
tuple_data = [t for t in tuple_data if t]
print(tuple_data)

