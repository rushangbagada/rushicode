def count_lines_in_csv(file):
    with open(file, mode='r') as file:
        lines = file.readlines()
        return len(lines)


line_count = count_lines_in_csv("D:\\padhai\\rushicode\\collage work\\sem2\\web programming lab\\lab11\\q3.csv") 
print(f"Number of lines in the CSV file: {line_count}")