# Write your solution here
import urllib.request
import json
import math
def retrieve_all():
    my_request = urllib.request.urlopen("https://studies.cs.helsinki.fi/stats-mock/api/courses")
    temp = my_request.read()
    courses = json.loads(temp)
    active_courses = []

    for course in courses:
        if course["enabled"]:
            sum = 0
            for i in course["exercises"]:
                sum += int(i)
            tuple = course["fullName"], course["name"], course["year"], sum
            active_courses.append(tuple)
    
    return active_courses

def retrieve_course(course_name: str):
    url = "https://studies.cs.helsinki.fi/stats-mock/api/courses/****/stats"
    url = url.replace("****", course_name)
    my_request = urllib.request.urlopen(url)
    temp = my_request.read()
    data = json.loads(temp)
    course = {}
    week_no = len(data)
    course["weeks"] = week_no
    max_students = []
    hours_total = []
    exercises_total = []

    for key, value in data.items():
        max_students.append(int(value["students"]))
        hours_total.append(int(value["hour_total"]))
        exercises_total.append(int(value["exercise_total"]))

    course["students"] = max(max_students)
    course["hours"] = sum(hours_total)
    hour_average = course["hours"] / course["students"]
    course["hours_average"] = math.trunc(hour_average)
    course["exercises"] = sum(exercises_total)
    exercise_average = course["exercises"] / course["students"]
    course["exercises_average"] = math.trunc(exercise_average)
    
    return course

#print(retrieve_course("docker2019"))