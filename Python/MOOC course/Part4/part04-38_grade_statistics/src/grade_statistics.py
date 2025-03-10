# Write your solution here

def main():
    exam_points = []
    exercise_points = []
    grades = []
    points = []
    user_input(exam_points, exercise_points)
    calculations(grades, exam_points, exercise_points, points)
    points_average = sum(points) / len(points)
    pass_percentage = (len(grades) - grades.count(0)) / len(grades) * 100
    printout(points_average, pass_percentage, grades)

def user_input(exam_points, exercise_points):
    while True:
        string = input("Exam points and exercises completed:")
        if string != "":
            temp = string.split()
            temp[0] = int(temp[0])
            temp[1] = int(temp[1])
            exam_points.append(temp[0])
            exercise_points.append(temp[1] // 10)
        else:
            break

def calculations(grades, exam_points, exercise_points, points):
    for i in range(len(exam_points)):
        points.append(exam_points[i] + exercise_points[i])
        if exam_points[i] < 10:
            grade = 0
        else:
            temp = exam_points[i] + exercise_points[i]
            if temp >= 0 and temp < 15:
                grade = 0
            elif temp >= 15 and temp < 18:
                grade = 1
            elif temp >= 18 and temp < 21:
                grade = 2
            elif temp >= 21 and temp < 24:
                grade = 3
            elif temp >= 24 and temp < 28:
                grade = 4
            elif temp >= 28 and temp < 31:
                grade = 5
        grades.append(grade)
        
    
    

def printout(points_average, pass_percentage, grades):
    star = "*"
    print("Statistics:")
    print(f"Points average: {points_average:.1f}")
    print(f"Pass percentage: {pass_percentage:.1f}")
    print("Grade distribution:")
    for i in range(5, -1, -1):
        print(f"  {i}: {star * grades.count(i)}")

main()