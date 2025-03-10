# Write your solution here
def copy_and_add(sudoku: list, row_no: int, column_no: int, number: int):
    sudoku_copy = []
    for row in sudoku:
        sudoku_copy.append(row[:])
    sudoku_copy[row_no][column_no] = number
    return sudoku_copy

def print_sudoku(sudoku: list):
    for row in range(9):
        if row == 3 or row == 6:
            print()
        for column in range(9):
            if column == 3 or column == 6:
                print(" ", end = "")
                if sudoku[row][column] == 0:
                    print(f"_ ", end = "")
                else:
                    print(f"{sudoku[row][column]} ", end = "")
            elif column == 8:
                if sudoku[row][column] == 0:
                    print(f"_", end = "")
                else:
                    print(f"{sudoku[row][column]}", end = "")
            else:
                if sudoku[row][column] == 0:
                    print(f"_ ", end = "")
                else:
                    print(f"{sudoku[row][column]} ", end = "")
        print()

if __name__ == "__main__":
    s = [
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
  [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
    ]
    res = copy_and_add(s, 1, 1, 5)
    print_sudoku(s)
    print()
    print()
    print_sudoku(res)