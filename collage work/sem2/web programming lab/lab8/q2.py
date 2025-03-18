# 2. Count strings with same first and last character
string_list = ['abbba', 'xybdmz', 'cvnhf', 'aba', '1221']
count = sum(1 for s in string_list if len(s) >= 2 and s[0] == s[-1])
print(count)

