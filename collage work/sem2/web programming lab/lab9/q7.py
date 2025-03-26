# Define a function 
#that accepts roll number and returns whether the student is present or absent.


def check_presence(roll):
    if roll in [1, 2, 3, 4, 5]:
        return "Present"    
    else:
        return "Absent"
    
print(check_presence(3))
print(check_presence(6))    