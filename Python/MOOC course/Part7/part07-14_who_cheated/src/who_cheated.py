# Write your solution here
import csv
from datetime import datetime, timedelta
def cheaters():
    cheater_list = []
    students = {}

    with open("start_times.csv") as my_file:
        for line in csv.reader(my_file, delimiter=";"):
            parts = line[1].split(":")
            students[line[0]] = datetime(2024, 4, 16, int(parts[0]), int(parts[1]))

    with open("submissions.csv") as my_file:
        for line in csv.reader(my_file, delimiter=";"):
            if line[0] in cheater_list:
                continue
            parts = line[3].split(":")
            time  = datetime(2024, 4, 16, int(parts[0]), int(parts[1]))
            temp = time - students[line[0]]
            if temp > timedelta(hours=3):
                cheater_list.append(line[0])
        
    return cheater_list

#print(cheaters())