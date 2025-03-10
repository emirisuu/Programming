# Write your solution here
def column_correct(sudoku: list, column_no: int):
    filled_numbers = []
    for row in sudoku:
        if row[column_no] in filled_numbers and row[column_no] != 0:
            return False
        filled_numbers.append(row[column_no])
    return True