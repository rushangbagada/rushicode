# a. Single inheritance
class Parent:
    def display(self):
        print("This is the parent class.")

class Child(Parent):
    def show(self):
        print("This is the child class.")

# Creating objects
print("Single Inheritance:")
parent = Parent()
child = Child()
parent.display()
child.show()
child.display()

# b. Multiple inheritance
class Father:
    def display(self):
        print("This is the father class.")

class Mother:
    def show(self):
        print("This is the mother class.")

class Child(Father, Mother):
    def introduce(self):
        print("This is the child class.")

print("\nMultiple Inheritance:")
child = Child()
child.display()
child.show()
child.introduce()

# c. Multilevel inheritance
class Grandparent:
    def greet(self):
        print("This is the grandparent class.")

class Parent(Grandparent):
    def display(self):
        print("This is the parent class.")

class Child(Parent):
    def show(self):
        print("This is the child class.")

print("\nMultilevel Inheritance:")
child = Child()
child.greet()
child.display()
child.show()

# d. Hierarchical inheritance
class Parent:
    def display(self):
        print("This is the parent class.")

class Child1(Parent):
    def show(self):
        print("This is the first child class.")

class Child2(Parent):
    def show(self):
        print("This is the second child class.")

print("\nHierarchical Inheritance:")
child1 = Child1()
child2 = Child2()
child1.display()
child1.show()
child2.display()
child2.show()