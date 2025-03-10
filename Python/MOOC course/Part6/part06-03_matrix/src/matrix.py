# write your solution here
def matrix_sum():
    suma = 0
    with open("matrix.txt") as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            numbers = line.split(",")
            for number in numbers:
                suma += int(number)
    return suma
 
def matrix_max():
    max_number = 0
    with open("matrix.txt") as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            numbers = line.split(",")
            temp = int(max(numbers))
            if temp > max_number:
                max_number = temp
    return max_number     
 
def row_sums():
    row_sum = []
    with open("matrix.txt") as new_file:
        for line in new_file:
            line = line.replace("\n", "")
            numbers = line.split(",")
            suma = 0
            for number in numbers:
                suma += int(number)
            row_sum.append(suma)
    return row_sum