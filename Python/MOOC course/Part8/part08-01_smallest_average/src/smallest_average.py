# Write your solution here
def smallest_average(person1: dict, person2: dict, person3: dict):
    dictionaries = [person1, person2, person3]
    averages = []
    for dictionary in dictionaries:
        sum = 0
        for key, value in dictionary.items():
            if key == "name":
                continue
            sum += value
        average = sum / 3
        averages.append(average)
    smallest = min(averages)
    index = averages.index(smallest)
    return dictionaries[index]
