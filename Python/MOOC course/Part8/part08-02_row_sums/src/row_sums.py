# Write your solution here
def row_sums(my_matrix: list):
    for item in my_matrix:
        sum = 0
        for matrix in item:
            sum += matrix
        item.append(sum)