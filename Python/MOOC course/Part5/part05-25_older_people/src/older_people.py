# Write your solution here
def older_people(people: list, year: int):
    new_list = []
    for born in people:
        if born[1] < year:
            new_list.append(born[0])
    return new_list