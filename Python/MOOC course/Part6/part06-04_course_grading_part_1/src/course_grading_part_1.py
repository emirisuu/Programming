# write your solution here
students = {}
student_file = input("Student information:")
exercises_file = input("Exercises completed:")
with open(student_file) as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        parts = line.split(";")
        if parts[0] == "id":
            continue
        students[parts[0]] = []
        name = parts[1] + " " + parts[2]
        students[parts[0]].append(name)

with open(exercises_file) as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        parts = line.split(";")
        if parts[0] == "id":
            continue
        sum = 0
        for number in parts[1:]:
            sum += int(number)
        students[parts[0]].append(sum)

for key in students:
    print(f"{students[key][0]} {students[key][1]}")