# Write your solution here
import csv
from datetime import datetime, timedelta
def final_points():
    students = {}
    times = {}

    with open("start_times.csv") as my_file:
        for line in csv.reader(my_file, delimiter=";"):
            parts = line[1].split(":")
            times[line[0]] = datetime(2024, 4, 16, int(parts[0]), int(parts[1]))
            students[line[0]] = {}

    with open("submissions.csv") as my_file:
        for line in csv.reader(my_file, delimiter=";"):
            parts = line[3].split(":")
            time  = datetime(2024, 4, 16, int(parts[0]), int(parts[1]))
            temp = time - times[line[0]] 
            if temp > timedelta(hours=3):
                continue
            if line[1] not in students[line[0]]:
                students[line[0]][line[1]] = int(line[2]) 
            elif students[line[0]][line[1]] < int(line[2]):
                students[line[0]][line[1]] = int(line[2])
    final_students = {}
    for key, value in students.items():
        sum = 0
        for points in value:
            sum += int(value[points])
        final_students[key] = sum

    return final_students

#print(final_points())