class Course:
    def __init__(self, name = str, grade = None, credits = None):
        self.__name = name
        self.__grade = grade
        self.__credits = credits

    def add_course(self, grade: int, credits: int):
        if self.__grade is None:
            self.__grade = grade
        elif self.__grade < grade:
            self.__grade = grade
        if self.__credits is None:
            self.__credits = credits
    
    def course(self):
        return self.__name
    
    def grade(self):
        return self.__grade
    
    def credits(self):
        return self.__credits
    
class CourseRecords:
    def __init__(self):
        self.__courses = {}

    def add_course(self, name: str, grade: int, credits: int):
        if name not in self.__courses:
            self.__courses[name] = Course(name)
        self.__courses[name].add_course(grade, credits)

    def get_entry(self, name: str):
        if name not in self.__courses:
            return None
        return self.__courses[name]
    
    def get_all_entries(self):
        return self.__courses
    
class CourseRecourdsApplication:
    def __init__(self):
        self.__CourseRecords = CourseRecords()

    def help(self):
        print("1 add course")
        print("2 get course data")
        print("3 statistics")
        print("0 exit")

    def add_course(self):
        name = input("course:")
        grade = int(input("grade:"))
        credits = int(input("credits:"))
        self.__CourseRecords.add_course(name, grade, credits)

    def get_data(self):
        name = input("course:")
        temp = self.__CourseRecords.get_entry(name)
        if temp == None:
            print("no entry for this course")
            return
        print(f"{temp.course()} ({temp.credits()} cr) grade {temp.grade()}")

    def statistics(self):
        courses = self.__CourseRecords.get_all_entries()
        total_courses = len(courses)
        total_credits = 0
        grades = []
        for name in courses:
            total_credits += courses[name].credits()
            grades.append(courses[name].grade())
        total_grades = sum(grades)
        grade_mean = total_grades / total_courses
        print(f"{total_courses} completed courses, a total of {total_credits} credits")
        print(f"mean {grade_mean:.1f}")
        print("grade distribution")
        for number in range(5, 0, -1):
            counter = grades.count(number)
            print(f"{number}: {'x' * counter}")    

    def execute(self):
        self.help()
        while True:
            command = int(input("command:"))
            if command == 0:
                break
            elif command == 1:
                self.add_course()
            elif command == 2:
                self.get_data()
            elif command == 3:
                self.statistics()

application = CourseRecourdsApplication()
application.execute()