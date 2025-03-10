# Write your solution here
def transpose(matrix: list):
    copy = []
    for number in matrix:
        copy.append(number[:])
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = copy[j][i]