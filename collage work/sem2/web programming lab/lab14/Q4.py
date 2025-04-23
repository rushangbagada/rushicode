class Vehicle:
    def details(self, name, color, price):
        print(f"Details: {name} {color} {price}")

    def max_speed(self):
        print("Vehicle max speed is 150")

    def change_gear(self):
        print("Vehicle changes 6 gears")

class Car(Vehicle):
    def max_speed(self):
        print("Car max speed is 240")

    def change_gear(self):
        print("Car changes 7 gears")

class Truck(Vehicle):
    pass

# Polymorphism in action
car = Car()
truck = Truck()

print("Car:")
car.details("Car", "Red", 20000)
car.max_speed()
car.change_gear()

print("\nTruck:")
truck.details("Truck", "White", 75000)
truck.max_speed()
truck.change_gear()