import csv


def write_dict_to_csv(file_name, data):
    with open(file_name, mode='w', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=data[0].keys())
        writer.writeheader()
        writer.writerows(data)

data = [
    {"Name": "rushang", "Age": 17, "Grade": "b"}, {"Name": "rushang", "Age": 21, "Grade": "f"},
  
]
write_dict_to_csv("students_output.csv", data)
