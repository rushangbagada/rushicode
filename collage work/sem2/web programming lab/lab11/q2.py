import csv

def read_csv(file_name):
    with open(file_name, mode='r') as file:
        reader = csv.reader(file)
        for row in reader:
            print(', '.join(row))


read_csv("D:\\padhai\\rushicode\\collage work\\sem2\\web programming lab\\lab11\\q3.csv")  