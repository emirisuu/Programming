from functools import reduce

class CourseAttempt:
    def __init__(self, course_name: str, grade: int, credits: int):
        self.course_name = course_name
        self.grade = grade
        self.credits = credits

    def __str__(self):
        return f"{self.course_name} ({self.credits} cr) grade {self.grade}"

def sum_helper(item, next_item):
        return item + next_item.credits

def sum_of_all_credits(courses: list):
    return reduce(sum_helper, courses, 0)

def sum_of_passed_credits(courses: list):
    list = filter(lambda item: item.grade >= 1, courses)
    return reduce(sum_helper, list, 0)

def average(courses: list):
    grades_list = list(filter(lambda item: item.grade >= 1, courses))
    grades = reduce(lambda item, next_item: item + next_item.grade, grades_list, 0)
    return grades / len(grades_list)


if __name__ == "__main__":
    s1 = CourseAttempt("Introduction to Programming", 5, 5)
    s2 = CourseAttempt("Advanced Course in Programming", 0, 4)
    s3 = CourseAttempt("Data Structures and Algorithms", 3, 10)
    ag = average([s1, s2, s3])
    print(ag)