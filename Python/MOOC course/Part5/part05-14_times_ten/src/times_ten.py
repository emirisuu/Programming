# Write your solution here
def times_ten(start_index: int, end_index: int):
    dictionary = {}
    for number in range(start_index, end_index + 1):
        dictionary[number] = number * 10
    return dictionary