# Write your solution here
import json
def print_persons(filename: str):
    with open(filename) as my_file:
        data = my_file.read()
    persons = json.loads(data)
    for key in persons:
        hobbies = ""
        for i in key["hobbies"]:
            hobbies += i + ", "
        hobbies = hobbies[:len(hobbies) - 2]
        print(f"{key['name']} {key['age']} years ({hobbies})")