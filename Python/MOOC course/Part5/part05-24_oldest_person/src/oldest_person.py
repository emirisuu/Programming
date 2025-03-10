# Write your solution here
def oldest_person(people: list):
    index = 0
    for i in range(len(people)):
        if people[i][1] < people[index][1]:
            index = i
    return people[index][0]
    