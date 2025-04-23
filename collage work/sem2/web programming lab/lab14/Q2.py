class Student:
    def __init__(self, name):
        self.name = name

class Marks(Student):
    def __init__(self, name, marks):
        super().__init__(name)
        self.marks = marks

class Percentage(Marks):
    def calculate_percentage(self):
        total = sum(self.marks.values())
        percentage = (total / 500) * 100
        return percentage

# Input marks for 5 subjects
marks = {
    "Maths": int(input("Enter marks for Maths: ")),
    "Chemistry": int(input("Enter marks for Chemistry: ")),
    "Physics": int(input("Enter marks for Physics: ")),
    "Web Programming": int(input("Enter marks for Web Programming: ")),
    "Data Structures": int(input("Enter marks for Data Structures: "))
}

student = Percentage("John Doe", marks)
print(f"\nPercentage of {student.name}: {student.calculate_percentage()}%")