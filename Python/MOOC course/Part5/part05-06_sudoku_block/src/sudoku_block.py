# Write your solution here
def block_correct(sudoku: list, row_no: int, column_no: int):
    filled_numbers = []
    for row in range(row_no, row_no + 3):
        for column in range(column_no, column_no + 3):
            if sudoku[row][column] in filled_numbers and sudoku[row][column] != 0:
                return False
            filled_numbers.append(sudoku[row][column])
    return True