# Write your solution here
def add_student(students: dict, name: str):
    students[name] = []

def print_student(students: dict, name: str):
    if name not in students:
        print(f"{name}: no such person in the database")
    else:
        print(f"{name}:")
        if len(students[name]) > 0:
            print(f" {len(students[name])} completed courses:")
            sum = 0
            for course in students[name]:
                print(" ", course[0], course[1])
                sum += course[1]
            average_grade = sum / len(students[name])
            print(" average grade", average_grade)
        else:
            print(" no completed courses")

def add_course(students: dict, name: str, course: tuple):
    if len(students[name]) > 0:
        k = 0
        for item in students[name]:
            if item[0] == course[0]:
                k = 1
                break
        if k == 1:
            for item in students[name]:
                if item[0] == course[0] and item[1] < course[1]:
                    students[name].remove(item)
                    students[name].append(course)
        else:
            if course[1] != 0:
                students[name].append(course)
    elif course[1] != 0:
        students[name].append(course)

def summary(students: dict):
    print("students", len(students))
    max = 0
    max_average = 0
    for key, value in students.items():
        sum = 0
        if len(value) > max:
            max = len(value)
            name = key
        for grade in students[key]:
            sum += grade[1]
        average_grade = sum / len(students[key])
        if average_grade > max_average:
            max_average = average_grade
            name1 = key
    most_courses = name, max
    max_average = name1, max_average
    print("most courses completed", most_courses[1], most_courses[0])
    print("best average grade", max_average[1], max_average[0])

if __name__ == "__main__":
    students = {}
    add_student(students, "Peter")
    add_course(students, "Peter", ("Software Development Methods", 5))
    add_course(students, "Peter", ("Software Development Methods", 1))
    print_student(students, "Peter")
