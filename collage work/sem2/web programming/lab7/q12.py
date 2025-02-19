#Python program to calculate grade of a student. Take in the marks of 5 subjects 
#and  display the grade.

marks1 = float(input("Enter marks of sub1: "))
marks2 = float(input("Enter marks of sub2: "))
marks3 = float(input("Enter marks of sub3: "))
marks4 = float(input("Enter marks of sub4: "))
marks5 = float(input("Enter marks of sub5: "))

marks = (marks1 + marks2 + marks3 + marks4 + marks5) / 5

if marks >= 90 and marks <= 100:
    print("Grade: A")
elif marks >= 80 and marks < 90:
    print("Grade: B")
elif marks >= 70 and marks < 80:
    print("Grade: C")
elif marks >= 60 and marks < 70:
    print("Grade: D")
else:
    print("faliled")