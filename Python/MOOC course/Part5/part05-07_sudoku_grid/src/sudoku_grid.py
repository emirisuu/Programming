# Write your solution here
def sudoku_grid_correct(sudoku: list):
    for index in range(9):
        k = row_correct(sudoku, index)
        if k == False:
            return False
        k = column_correct(sudoku, index)
        if k == False:
            return False

    for index1 in range(0, 9, 3):
        for index2 in range(0, 9, 3):
            k = block_correct(sudoku, index1, index2)
            if k == False:
                return False
    
    return True



def row_correct(sudoku: list, row_no: int):
    filled_numbers = []
    for number in sudoku[row_no]:
        if number in filled_numbers and number != 0:
            return False
        filled_numbers.append(number)
    return True

def column_correct(sudoku: list, column_no: int):
    filled_numbers = []
    for row in sudoku:
        if row[column_no] in filled_numbers and row[column_no] != 0:
            return False
        filled_numbers.append(row[column_no])
    return True

def block_correct(sudoku: list, row_no: int, column_no: int):
    filled_numbers = []
    for row in range(row_no, row_no + 3):
        for column in range(column_no, column_no + 3):
            if sudoku[row][column] in filled_numbers and sudoku[row][column] != 0:
                return False
            filled_numbers.append(sudoku[row][column])
    return True