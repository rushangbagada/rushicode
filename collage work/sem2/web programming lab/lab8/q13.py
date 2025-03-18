# 13. Create combinations of letters
data = {'1': ['a', 'b'], '2': ['c', 'd']}
combinations = [x + y for x in data['1'] for y in data['2']]
print(combinations)

