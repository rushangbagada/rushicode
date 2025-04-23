class Vehicle:
    def __init__(self, name):
        self.name = name

class TwoWheeler(Vehicle):
    def __init__(self, name, type):
        super().__init__(name)
        self.type = type

class FourWheeler(Vehicle):
    def __init__(self, name, type):
        super().__init__(name)
        self.type = type

class Car(FourWheeler):
    def details(self):
        print(f"Car Name: {self.name}, Type: {self.type}")

class Scooter(TwoWheeler):
    def details(self):
        print(f"Scooter Name: {self.name}, Type: {self.type}")

car = Car("Honda City", "Sedan")
scooter = Scooter("Activa", "Scooter")

print("Vehicle Details:")
car.details()
scooter.details()