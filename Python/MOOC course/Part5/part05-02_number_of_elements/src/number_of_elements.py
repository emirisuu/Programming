# Write your solution here
def count_matching_elements(my_matrix: list, element: int):
    counter = 0
    for row in my_matrix:
        for item in row:
            if item == element:
                counter += 1
    return counter