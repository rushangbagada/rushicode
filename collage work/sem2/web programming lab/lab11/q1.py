import random
import string

def generate_random_char():
    return random.choice(string.ascii_letters)


def generate_random_string(length):
    return ''.join(random.choices(string.ascii_letters, k=length))


with open("random_strings.txt", "w") as file:
    for _ in range(10):  
        random_char = generate_random_char()
        random_string = generate_random_string(8)  
        file.write(f"Random Character: {random_char}, Random String: {random_string}\n")

