# 3. Check if two lists have common members
lst1 = [1, 2, 3]
lst2 = [4, 5, 6]
has_common = any(x in lst2 for x in lst1)
print(has_common)

