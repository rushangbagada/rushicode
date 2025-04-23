class Cat:
    def info(self):
        print("I am a cat. I like to meow.")

    def make_sound(self):
        print("Meow!")

class Dog:
    def info(self):
        print("I am a dog. I like to bark.")

    def make_sound(self):
        print("Woof!")

# Polymorphism in action
animals = [Cat(), Dog()]

for animal in animals:
    animal.info()
    animal.make_sound()