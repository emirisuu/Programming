# wwite your solution here
students = {}
student_file = input("Student information:")
exercises_file = input("Exercises completed:")
exam_points = input("Exam points:")
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

for key, value in students.items():
    total_points = value[2] + value[3]
    students[key].append(total_points)
    if total_points >= 0 and total_points < 15:
        grade = 0
    elif total_points >= 15 and total_points < 18:
        grade = 1
    elif total_points >= 18 and total_points < 21:
        grade = 2
    elif total_points >= 21 and total_points < 24:
        grade = 3
    elif total_points >= 24 and total_points < 28:
        grade = 4
    elif total_points >= 28:
        grade = 5
    students[key].append(grade)


print(f"{'name':30}{'exec_nbr':10}{'exec_pts.':10}{'exm_pts.':10}{'tot_pts.':10}{'grade'}")

for key in students:
    print(f"{students[key][0]:30}{students[key][1]:<10}{students[key][2]:<10}{students[key][3]:<10}{students[key][4]:<10}{students[key][5]:<1}")
