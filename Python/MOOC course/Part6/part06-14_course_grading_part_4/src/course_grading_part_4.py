# wwite your solution here
students = {}
course = []
student_file = input("Student information:")
exercises_file = input("Exercises completed:")
exam_points = input("Exam points:")
course_info = input("Course information:")

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
        students[parts[0]].append(sum * 10 // 40)

with open(exam_points) as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        parts = line.split(";")
        if parts[0] == "id":
            continue
        sum = 0
        for number in parts[1:]:
            sum += int(number)
        students[parts[0]].append(sum)

with open(course_info) as new_file:
    for line in new_file:
        line = line.replace("\n", "")
        parts = line.split(": ")
        course.append(parts[1])

for key, value in students.items():
    total_points = value[2] + value[3]
    students[key].append(total_points)
    if total_points < 15:
        grade = 0
    elif total_points < 18:
        grade = 1
    elif total_points < 21:
        grade = 2
    elif total_points < 24:
        grade = 3
    elif total_points < 28:
        grade = 4
    else:
        grade = 5
    students[key].append(grade)

with open("results.txt", "w") as new_file:
    line = f"{course[0]}, {course[1]} credits"
    length = len(line)
    new_file.write(line + "\n")
    line = f"{'=' * length}"
    new_file.write(line + "\n")
    line = f"{'name':30}{'exec_nbr':10}{'exec_pts.':10}{'exm_pts.':10}{'tot_pts.':10}{'grade'}"
    new_file.write(line + "\n")
    for key in students:
        line = f"{students[key][0]:30}{students[key][1]:<10}{students[key][2]:<10}{students[key][3]:<10}{students[key][4]:<10}{students[key][5]:<1}"
        new_file.write(line + "\n")

with open("results.csv", "w") as new_file:
    for key, value in students.items():
        line = f"{key};{value[0]};{value[-1]}"
        new_file.write(line + "\n")
