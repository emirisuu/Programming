# Write your solution here
def row_correct(sudoku: list, row_no: int):
    filled_numbers = []
    for number in sudoku[row_no]:
        if number in filled_numbers and number != 0:
            return False
        filled_numbers.append(number)
    return True